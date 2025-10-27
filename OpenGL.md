> [!abstract] OpenGL
> OpenGL ist eine Spezifikation einer API zur Entwicklung von 2D- und 3D-Computergrafikanwendungen.
> Es ist also ein *Standard*, keine *Library*.
> Die eigentliche Library wird von den Treiberentwicklern (nVidia, AMD, Intel etc.) als **libgl** ausgeliefert.

Jede Implementierung unterstützt das *Core Profile* und optional einige *Extensions*. Für Legacy-Schnittstellen gibt es das *Compat Profile*.

# Kontext

- speichert den *state* (Variablen) sowie die *surface* (Informationen über das Ausgabemedium)
- Für Erstellung von Kontext und Fenster gibt es verschiedene Bibliotheken:
	- glfw
	- freeglut
	- SDL

Erstellen eines Kontexts:
```cpp
glfwInit();
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, argv[0] /*Fenstertitel*/, nullptr, nullptr);

if (window == nullptr) {
	std::cerr << "Failed to Create OpenGL Context" << std::endl;
	std::terminate();
}

// create context and load OpenGL functions
glfwMakeContextCurrent(window);
glfwSetFramebufferSizeCallback(window, resize_callback);  // resize_callback wird bei Ändern der Fenstergröße aufgerufen

gladLoadGL(); // lade extensions (geht mit glad, glew oder gl3w)
```

# Event/Rendering Loop

```cpp
while (glfwWindowShouldClose(window) == false) {
	glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	// render something...
	
	glfwSwapBuffers(window);
	glfwPollEvents();
}

glfwTerminate();
```

Um screen tearing zu vermeiden, halten wir zwei Bild-Buffer in der Grafikkarte:
- Front Buffer, der zum Monitor geschickt wird
- Back Buffer, in das gerendert wird

Die beiden werden mit `glfwSwapBuffers()` vertauscht.

Events können Tastatur- oder Mausinteraktionen sein, oder das Ändern der Fenstergröße.

# Rendering Pipeline


> - *Application*
> 	- $\to$ produziert Vertex Data
> - *Vertex Program* (Vertex Shader)
> 	- erhält die Daten und berechnet ihre tatsächliche Position
> 	- $\to$ produziert Vertices
> - *Geometry Program*
> 	- setzt die Vertices zu Objekten (z.B. Punkte, Liniensegmente, Dreiecke) zusammen
> 	- $\to$ produziert Primitives
> - *Clipping und Rasterization*
> 	- lassen sich nur mit globalen Variablen steuern
> 	- sind in der Regel in Hardware implementiert
> 	- Clipping: verwirft Vertices und Fragments, die nicht sichtbar sind
> 	- Rasterisierung: interpoliert die Vertex-Attribute
> 	- $\to$ produziert Fragments
> 		- Fragments $\approx$ Pixel, nur dass fragments eine 3. Koordinate haben (Tiefe) und Pixel aus mehreren Fragments zusammengesetzt sein können (wichtig für Antialiasing)
> - *Fragment Program* (Fragment Shader)
> 	- bestimmt Färbung abhängig von simulierten Beleuchtungsmodellen (shading)
> 	- $\to$ produziert gefärbte Fragments
> - *Framebuffer Operations*
> 	- OpenGL macht den Rest
> 	- Fragments werden zu Pixeln zusammengesetzt (wird anhand Tiefe und (Semi-)Transparenz des Fragments bestimmt)
> 	- Pixel können durch Maskierung verworfen und evtl. in anderes Farbformat konvertiert werden
> 	- $\to$ produziert Pixel

^94ddb2

Ein Durchlaufen dieser Pipeline heißt **Render pass**.

Starten der Pipeline (im Event Loop): z.B. `glDrawArrays()`
## Shader

Shader werden in der *GL Shading Language* (GLSL) geschrieben.

Spezifizierung der shader version: `#version 330 core` (korrespondiert zur OpenGL-Version)

Spezifierung der Inputvariablen:
```glsl
layout (location = 0) in vec3 position;
layout (location = 1) in vec4 color;
```
Alles weitere passiert in der `main()`-Methode des Shaders (s.u.).

*Kompilieren und Laden:*
- `glCreateShader(type)` gibt ID zurück
	- `type`: z.B. `GL_VERTEX_SHADER`, `GL_FRAGMENT_SHADER`
- `void glShaderSource(shader, 1, &shaderSource, NULL)` weist den source code (`char* shaderSource`) dem Shader mit der ID `shader` zu
- `void glCompileShader(shader);` zum Kompilieren

Danach müssen die Shader an ein *Shader Program* gebunden werden:

```cpp
unsigned int shaderProgram;
shaderProgram = glCreateProgram();
glAttachShader(shaderProgram, vertexShader);
glAttachShader(shaderProgram, fragmentShader);
glLinkProgram(shaderProgram);
if (!checkProgram(shaderProgram)) {
	std::terminate();
}
glDeleteShader(fragmentShader);
glDeleteShader(vertexShader);
```
Im Event loop wird das shader program dann mit `glUseProgram(shaderProgram)` aktiviert. Danach verwenden alle Operationen, die Geometrie zeichnen, dieses Programm.
### Vertex Shader

Dateiendung: `.vert`

Die Aufgabe des Shaders ist es, der globalen Variable `gl_Position` (und ggf. [weiteren](https://www.khronos.org/opengl/wiki/Vertex_Shader#Outputs)) einen Wert in [[Homogene Koordinaten|homogenen Koordinaten]] (4D-Punkt) zuzuweisen.

```glsl
#version 330 core
layout (location = 0) in vec3 position;

void main()
{
	gl_Position = vec4(position.x, position.y, position.z, 1.0);
}
```

Der Vertex Shader interpoliert die Daten zwischen den Vertices. Das ist mindestens die Position, kann aber auch zusätzlich die Farbe sein, damit funktioniert das genauso:
```glsl
#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 interpColor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    interpColor = color;
}
```

Wenn jetzt der Fragment Shader eine `in`-Variable mit dem Namen `interpColor` hat, wird er den interpolierten Farbwert entgegennehmen und kann ihn z.B. 1-zu-1 übernehmen, oder noch anderweitig verarbeiten.
### Fragment Shader

Dateiendung: `.frag`

Dafür zuständig, einem Fragment eine Farbe zuzuweisen, z.B. 
```glsl
#version 330 core
out vec4 frag_color;

void main()
{
	frag_color = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
```

# Geometriedaten
## Vertex Buffers

Der Zweck von Vertex Buffern ist es, Vertexdaten an die GPU zu schicken.

Der Vertex Buffer bekommt eine ID, um ein OpenGL-Objekt damit zu verknüpfen:

```cpp
unsigned int VBO;
glGenBuffers(1, &VBO);
glBindBuffer(GL_ARRAY_BUFFER, VBO); // setze diesen Buffer als das aktuelle Objekt
```

Nun können wir dem Buffer mit `glBufferData` unsere Vertices übergeben, z.B. als Array:
```cpp
float vertices[] = {
	// X, Y, Z,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	0.0f, 0.5f, 0.0f
};

glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
```

Nun müssen wir die Vertices mit der entsprechenden Variablen im Vertex Shader verknüpfen. Das geht mit:
```
void glVertexAttribPointer(
	GLuint index,
	GLint size,
	GLenum type,
	GLboolean normalized,
	GLsizei stride,
	const GLvoid * pointer);
```

^d6ad93

- `index`: ist die `location` vom Shader-Attribut
- `size`: Dimension des Attributs (obiges Beispiel: 3)
- `type`: Datentyp (obiges Beispiel: `GL_FLOAT`)
- `normalized`: ob die Verteces normalisiert werden sollen
- `stride`: wieviele Bytes von einem Vertex zum nächsten (obiges Beispiel: `3 * sizeof(float)`)
- `pointer`: wo sich die Daten befinden - `(void*)0` bedeutet, dass die Daten im akuell gebundenen *vertex buffer* (z.B. VBO) liegen

Mit `glEnableVertexAttribArray(0)` wird das Shader-Attribut mit Index 0 aktiviert.

### Vertex Array Objects

Die obigen Aufrufe `glVertexAttribPointer`, `glEnableVertexAttribArray` müssen einmal pro Event Loop aufgerufen werden. Wenn man aber:
- ein *vertex array object* (VAO) erstellt
- dieses bindet
- dann sein VBO erstellt und die Attribute setzt
- und dann pro Event Loop nur das VAO bindet
dann erspart man sich das.

```cpp
unsigned int VAO;
glGenVertexArrays(1, &VAO);
glBindVertexArray(VAO);

// glBindBufffer, glVertexAttribPointer glEnableVertexAttribArray
```
## Index Buffers
Auch genannt Element Buffer ($\to$ IBO, EBO).

Ein Index Buffer enthält die Indices, aus denen die Vertices aus dem Vertex Buffer genommen werden, um z.B. Dreiecke zusammenzusetzen.

Es wird genauso erstellt wie der Vertex Buffer und muss auch an das VAO gebunden werden.

Hat man das VAO von seinem Index Buffer gebunden, kann man im Event Loop mit `glDrawElements` seine Objekte malen.

# Farben

sRGB-Rendering aktivieren:
```cpp
glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
glEnable(GL_FRAMEBUFFER_SRGB);
```

Wir können Farbdaten in unseren Vertex Buffer packen:
```cpp
const std::vector<float> VERTICES = {
	-0.6f, -0.5f, 0.0f, 1.f, 0.f, 0.f,
	0.6f, -0.5f, 0.0f, 0.f, 1.f, 0.f,
	0.0f, 0.5f, 0.0f, 0.f, 0.f, 1.f,
};
```

und dann mit [[OpenGL#^d6ad93|glVertexAttribPointer]] an unseren shader übergeben:
```cpp
size_t stride = 6 * sizeof(float);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
					  stride, (void*) (0 * sizeof(float)));
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,
					  stride, (void*) (3 * sizeof(float)));
glEnableVertexAttribArray(0);
glEnableVertexAttribArray(1);
```

Damit landen die Farbwerte auch im Vertex Shader und werden dadurch auch interpoliert.