[[FOCVE_12_Motion_Tasks_and_Outlook.pdf]]

## Motion Adaptation
- Körper soll sich bei Bewegungen dynamisch dem Terrain anpassen

Ansatz:
- Timing der Bewegung mit periodischer Funktion modellieren
- Das als Input für KNN verwenden, das Bewegung anpassen soll
## Motion Retargeting
- Übertragung von Bewegungen von einem Skelett zu einem anderen, mit anderen Eigenschaften (z.B. andere Körpergröße, Körperbau, etc.)
- Soll im Kontext der Umgebung weiterhin Sinn machen (z.B. Füße auf dem Boden bleiben, wenn Charakter schrumpft)

Ansatz:
- Bewegung kopieren und schrittweise anpassen
- Semantik: Relative Distanzen von Gelenken beibehalten
- Geometrie: Mesh soll sich nicht selbst überlappen
- Mit erlernter Gewichtungsfunktion Semantik und Geometrie gewichten
- kein KNN nötig
## Motion Completion
- Vollständige Bewegung vorhersagen, wenn nur unvollständige Messungen vorhanden sind

Ansatz:
- Reinforcement Learning 
## Motion Creation
- Komplett neue Bewegung erzeugen, z.B. auf Text-Prompt

Ansatz:
- Encoder-Decoder Architektur (Encoder für Text, Decoder für Bewegung)
- Diffusionsmodell