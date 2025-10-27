[[11features_WS2425_slides.pdf]]

# Features

![[ISS - VL 8#Harris Corner Detector]]

Was ist der Laplacian (Laplacian of Gaussian, LoG)?
-> die Magnitude der zweiten Ableitung von einer Gaussian (sieht aus wie ein Sombrero)
-> Laplacian auf ein Bild angewandt ist ein richtungsunabhängiger Kantendetektor: Kanten sind Nulldurchläufe in der zweiten Ableitung, haben also eine positive Response auf der einen Seite (wo die Bildintensität gering ist) und eine negative Response auf der anderen Seite

Blob Detection:
- Eine Kante erzeugt ein "Ripple" im Bild vom Laplace-Operator
- Ein Blob erzeugt die Superposition zweier Ripples, sofern die Skalierung des Laplace-Filters mit der Größe des Blobs übereinstimmt

Die *charakteristische Skalierung* eines Blobs ist diejenige Skalierung, die die höchste Laplace-Antwort bewirkt.

-> **Interest points** sind charakteristisch sowohl in Skalierung als auch Position.
Es kann hilfreich sein, kontrastarme Interest Points zu verwerfen.
Subpixel-Genauigkeit kann man erreichen, indem man quadratische Funktion auf die Filterantwort anpasst und deren Maximum berechnet.

Den Laplace-Operator kann man als Differenz zwischen zwei Gaussians approximieren (Difference of Gaussians, DoG). Diese Eigenschaft haben wir schon bei der [[CV 3 - Pyramids#Laplace-Pyramide|Laplace-Pyramide]] gesehen.

![[Photo I - VL 8#SIFT]]

