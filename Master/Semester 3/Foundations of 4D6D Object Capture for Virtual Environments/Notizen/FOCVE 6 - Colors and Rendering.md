[[FOCVE_06_Colors_and_Rendering.pdf]]

Sei:
- $\Omega$ die Halbkugel, von der aus ein Oberflächenpunkt $x$ zu sehen ist
- $L_{e}(x, v)$ das Licht, das von diesem Punkt in Richtung $v$ emitiert wird
- $L_{i}(x, l)$ das Licht, das aus Richtung $l$ auf den Punkt trifft
- $n$ der Normalenvektor vom Punkt

dann ist die beobachtbare Leuchtkraft vom diesem Punkt in Richtung $v$: $$L_{o}(x,v)=L_{e}(x, v)+\int_{\Omega}f_{\text{BRDF}}(x, l, v)L_{i}(x, l) \langle n \mid l \rangle \,dl$$
