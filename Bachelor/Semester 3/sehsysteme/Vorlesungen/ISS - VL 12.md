Datum: 16.01.
[[ISS12_WS2324_3D-PCLs_240126_240126.pdf|Folien]]

[[ISS_WS2324_Aufgabenblatt12.pdf|Aufgabenblatt]], [[Blatt 12|Lösungen]]
# Klassifikation von 3D-Punkten

Situation: man hat irgendein Gerät, welches um sich herum punktweise Abstandsmessungen macht und damit eine 3D-Punktwolke erstellt (z.B. Time-of-Flight-Kamera, siehe Robotik).

Wir möchten erst mal eine Nearest Neighbor Klassifikation machen. Das ist nicht ganz einfach, weil wir Millionen von Punkten haben

## Histogrammbasierte Deskriptoren

*Normal Orientation Histrogram*
- Man nimmt die Normalenvektoren aller Punkte (was an sich schon nicht einfach ist)
- Innerhalb eines Radius um den Vektor (Support-Radius $\delta$) nimmt man all diese Vektoren und packt sie jenach Orientierung in ein Histogramm
- Verschiedene Oberflächen ergeben verschiedene Histogramme

*Spin Image*
- Nudelsieb

