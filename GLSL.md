> GLSL = *OpenGL Shading Language*

## Vertex Shader

`out vec4 color` wird interpoliert
`flat out vec4 color` wird nicht interpoliert

-> `flat in vec4 color` in fragment shader

## Swizzling

Mit einem Vektor:
```glsl
vec2 myVector = vec2(-1, 1);
```
kann man einen neuen Vektor aus dessen Komponenten erstellen:

```glsl
vec2 myVector2 = myVector.yx   // vec2(1, -1)
vec3 myVector3 = myVector.xxy  // vec3(-1, -1, 1)
vec4 myVector4 = myVector.yyyy // vec4(1, 1, 1, 1)
```

Für Adressierung sind möglich:
- `xyzw`
- `rgba`
- `stpq`