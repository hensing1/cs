[[16stereo_WS2425_slides.pdf]]

# Stereo Vision
Wir möchten gerne Informationen über *Tiefe* haben.

Wir haben zwei Kameras, und wir kennen die Kalibrierung und den Abstand (calibrated binocular stereo pair).

Aus dem [[CV 15 - Calibration|letzten Kapitel]] wissen wir schon, dass wir Korrespondenzen finden können, indem wir entlang von Epipolarlinien suchen.
Die Korrespondenzen können wir triangulieren, um die Tiefeninformation zu erhalten.

Einfachster Fall: Epipolarlinie ist horizontal (Korrespondenzen haben dieselbe $y$-Koordinate)
Mit Baseline $B$, Tiefe $Z$, Brennweite $f$ und x-Koordinaten $x,x'$: $$\frac{Z}{B} = \frac{Z-f}{B+x'-x}$$woraus folgt: Disparität ($x-x'$) ist invers proportional zur Tiefe: $$x-x'= \frac{Bf}{Z}.$$

Kameras genau auszurichten ist schwierig, daher: beide Bildebenen auf eine gemeinsame Ebene warpen, mit Homographien $H,H'$. Dabei soll die Verzerrung möglichst gering bleiben.
Das funktioniert im unkalibrierten Fall mit der Fundamentalmatrix $F$, oder im kalibrierten Fall mit den Kameramatrizen $K,K'$ und der essential matrix $E$.
Wir projizieren so, dass die Epipolarlinien *parallel* und *horizontal* sind. 

## Bessere Matchings

Mehr constraints:
- nur ein Match pro Punkt
- Gefundene Matches sollten in beiden Bildern in derselben Reihenfolge sein
	- nicht unbedingt erfüllt
- Scanline: diesdas entlang einer Linie
- Rauschreduzierung mit [[CV 7 - Markov Random Fields|Markov Random Fields]] (Abstandswerte diskretisieren)

## Alternatives Dings

- Nur eine Kamera
- projiziere strukturierte Muster (z.B. farbige Linien) auf das Objekt

## Plane Sweep

- Zwei oder mehr Kameras
- Wir schmeißen eine Ebene in den Raum (als Hypothese), und projizieren alle Kamerabilder auf diese Ebene
- ist ein Bereich scharf (alle Bilder wurden in diesem Bereich auf dieselben Bildpunkte gemappt), stimmt die Hypothese (Ebene hat dieselbe Tiefe wie der Bereich)
- Man muss vorher Grenzen für die möglichen Tiefenwerte bestimmen

-> für jeden Pixel: nimm die Tiefe, die die geringste Varianz produziert

## Space Carving

Ziel: Voxel-Repräsentierung unseres Objekts

- Initialisiere Volumen, welches das Objekt enthält
- Wähle ein Voxel an der Oberfläche
- Projiziere auf die Input-Bilder
- Falls auf einem der Bilder kein Objekt an dieser Stelle zu sehen (bzw. keine Konsistenz mit dem Foto): entferne Voxel
- Wiederhole bis Konvergenz

> *Def. Fotokonsistenz*
> Eine Szene ist fotokonsistent, wenn sie die aufgenommenen Bilder mit denselben Kamerapositionen exakt reproduziert.

Man kann mit den Input-Bildern keine fotokonsistente Szene von der echten Szene unterscheiden.
Der Schnitt aller fotokonsistenten Szenen ist die *Photo Hull:* 
![[Photo_Hull.png|400]]

Binärbilder: ein Voxel ist fotokonsistent, wenn es in allen Bildern innerhalb der Silhouette liegt

