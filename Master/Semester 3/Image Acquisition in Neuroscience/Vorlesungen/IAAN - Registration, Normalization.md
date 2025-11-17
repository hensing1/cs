[[iaan-04-Registration-Normalization.pdf]]

- Wir möchten Gehirnscans *alignen* - dieselbe Voxelposition soll derselben anatomischen Region entsprechen

Warum?
- Dieselbe Person über längeren Zeitraum betrachten (intra-modal, Vergleich derselben Modalität (z.B. MRI))
- Verschiedene Scans (MRI, fMRI, ...) derselben Person alignen (inter-modal)
- Mehrere Personen vergleichen (intra-modal)

Ansatz: man hat ein *Referenzbild* (bleibt unverändert) und ein *Floating Image*. Der Prozess wird auch **Normalisierung** genannt.

Zwei Arten der Registrierung:
- Linear (affin): erlaubt Rotation, Translation, Skalierung, Scherung
- Nichtlinear: erlaubt lokale Deformationen

Typisches Ähnlichkeitsmaß: Bildintensität jedes Voxels

Man kann eine *regressionsbasierte* Registrierung machen (zwei Bilder direkt alignen), z.B. mit Neuronalen Netzwerken
Man kann auch Registrierung anhand von (manuell markierten) anatomischen *Referenzpunkten* machen. Dann wird der *Target Registration Error* minimiert (durchschnittlicher bzw. maximale Distanz zwischen $m$ Referenzpunkten $r_{i}$ und beweglichen Punkten $p_{i}$): $$\begin{align}
\text{TRE}_{\text{mean}}&=\frac{1}{m} \sum_{i=1}^{m}\|r_{i}-T(p_{i}\| \\
\text{TRE}_{\text{max}} &= \max \{ \|r_{i}-T_{i}(p_{i}) \mid i=1,\dots,m \}
\end{align}$$

