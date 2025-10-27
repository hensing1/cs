Datum: 22.04.
[[cgintro-03-GeometrieRepräsentieren.pdf|Dreiecksfolien]] (ab S. 17)
[[cgintro-04-Raytracing.pdf|Raytracingfolien]] (bis S. 8)

# Darstellung von Dreiecken

In einer geschlossenen Oberfläche, die wir aus Dreiecken zusammensetzen, ist das Verhältnis Vertices ($n_V$) zu Dreiecken ($n_{T}$) zu Kanten ($n_{E}$) etwa 1:2.3. 

Eine Datenstruktur für Dreiecksnetze muss diese Daten einigermaßen effizient abspeichern und gleichzeitig schnell Anfragen bearbeiten können wie:
- Welche Verteces gehören zu einem gebenenen Dreieck?
- Welche Dreiecke grenzen an einen gegebenen Vertex?
- Welche Nachbarn hat ein gegebenes Dreieck?
- etc.

*Edge collapse:* "ziehe" einen Vertex entlang einer Kante auf einen anderen. Resultat: ein Vertex verschwindet, all seine Kanten zeigen nun zu einem benachbartem Vertex.

## Datenstrukturen

### Array von Punkttripeln
- Pro Dreieck die drei Vertices speichern
- $\Rightarrow$ verschwenderisch, da sich Dreiecke Punkte teilen (in einem typischen Dreiecksnetz wird jeder Vertex ca. 6-mal gespeichert)
	- im $\mathbb{R}^{3}$ 36 Bytes pro Dreieck
- Nachbarsuche nur durch Koordinatenvergleich möglich
- Durch Rundungsfehler können Risse entstehen

### Indizierte Dreiecke
- Speichere jeden Vertex nur einmal
- Pro Dreieck die Vertex-Indizes speichern
- Speicherplatz: ca. 18 Bytes
- Nachbarschaftsabfrage: umständlich, da man alle Dreiecke und deren Punkte abfragen muss -> $\mathcal{O}(n_V)$
- Topologie und Geometrie sind getrennt voneinander gespeichert

### Halbkanten-Datenstruktur
[[Algo I - VL 16#Halbkanten-Datenstruktur|Halbkanten-Datenstruktur (Algo I)]]

Zusätzlich Speichern wir *Flächen*. Eine Fläche speichert genau eine angrenzende Halbkante.

Die Halbkante speichert bei uns noch zusätzlich:
- den Index der *zugehörigen Fläche*
- den Index der vorhergehenden Halbkante

*Vorteile*
- $\mathcal{O}(1)$ Nachbarschaftsanfragen
- $\mathcal{O}(1)$ Zeit für lokale Änderungen (edge collapse, Vertex einfügen, etc.)

*Nachteile*
- Speicherintensiv
- nicht 1-zu-1 mit OpenGL zu rendern

## Daten auf Dreiecksnetzen
Oft möchte man zusätzliche Daten, die über die reine Geometrie hinausgehen, mit seinen Dreiecksnetzen speichern (Flächenfarbe, Knicke an Kanten, Normalen, etc.)

*Vertexdaten:*
- Oberflächennormalen (wenn Netz eine glatte Oberfläche darstellen soll)
- Texturkoordinaten (wie ist ein Bild auf dem Dreieck anzubringen?)
- i.A. alles, was sich stetig verändern kann

Speichert man die Oberflächennormalen an den Vertices, kann man an Punkten dazwischen *interpolieren*. Damit erhält man eine gleichmäßige Veränderung der Normalen wie bei einer glatten Oberfläche (z.B. Kugel), auch wenn das Objekt nur als Dreiecksnetz gegeben ist.

Möchte man Knicke in seinem Objekt haben (z.B. Würfel), kann man pro Dreieck für jeden Vertex eine Normale speichern (damit kann man mehrere Normalen pro Vertex haben).

## Special Datenstrukturen
### Dreiecksstreifen

- Speichere Vertices mit ihren Koordinaten
- Speicheren Dreiecke als Streifen: 
	- Liste an Vertex-Indices
	- *Jeder* Index definiert ein neues Dreieck zusammen mit den beiden vorhergeganenen

$\to$ `0,1,2,3,4` erzeugt die Dreiecke `(012), (123), (234)`

Mehrere Streifen können durch degenerierte Dreiecke zusammengenäht werden: 
`[1,2,3,4]` und `[6,7,8,9]` werden zu `[1,2,3,4,4,6,6,7,8,9]` - die Dreiecke an den Übergängen haben Fläche Null, werden also nicht gezeichnet.

### Dreiecksfächer

Genau wie Dreiecksstreifen, nur dass immer das erste Vertex wiederverwendet wird.

$\to$ `0,1,2,3,4` erzeugt `(012), (023), (034)`

# Topologie vs. Geometrie

*Topologie:* wie sind Dreiecke (unabhängig von der Vertexposition) verbunden?
*Geometrie:* wo liegen die Dreiecke im 3D-Raum?

- *Topologische Gültigkeit:*
	- jede Kante hat genau zwei Dreiecke (außer ggf. am Rand)
	- jeder Vertex muss eine umlaufende Schleife von Dreiecken haben
	- $\to$ das Objekt eine *Mannigfaltigkeit* sein
	- ![[Mannigfaltigkeit.png]]
	- Objekte müssen eine eindeutige Vorder- und Rückseite haben (Möbiusband nicht erlaubt)
		- Bei Halbkanten-Datenstruktur: zwei benachbarte Halbkanten müssen immer entgegengesetzt verlaufen (alle Dreiecke müssen gegen den Uhrzeigersinn verlaufen)
- *Geometrische Gültigkeit:*
	- Objekte sollten sich nicht selbst schneiden
	- schwer zu garantieren

---

# Raytracing

*Renderinggleichung für Oberflächen:*

$$L_{o}(\vec x, \vec \omega_{o}) = L_{e}(\vec x, \vec \omega_{o}) + \int_{\Omega}f(\vec \omega_{i}, \vec \omega_{o})L_{i}(\vec x, \vec \omega_{i}) \langle \vec \omega_{i}, \vec n \rangle \,d\vec \omega_{i}$$ ^b35b91

![[Renderinggleichung.png|500]]

Wieviel Licht gibt der Punkt $x$ in die Richtung $\vec \omega_o$ ab?
- Lichtemmision $L_e$
- Indirekte Lichtabgabe (Reflexion) - Integral über alle einfallenden Richtungen, die den Punkt $x$ treffen (alle Richtungen aus der oberen Hemisphäre über dem Punkt):
	- $f$ ist Streufunktion (wieviel Licht die Oberfläche reflektiert)
	- $L_i$ ist die einfallende Radianz (wieviel Licht die Oberfläche trifft)
	- $\langle \vec \omega_{i}, \vec n \rangle$ ist der Lambertsche Cosinus-Term