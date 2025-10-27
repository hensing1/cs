Datum: 05.05.
[[Folien-2023-5-05.pdf|Folien]]
[[Skript AlgoII.pdf|Skript]] - Seiten 45 bis 51
[Video](https://uni-bonn.sciebo.de/s/YVfBpu1J5oiqZGj#/files_mediaviewer/Vorlesung-05.mp4)

*Kapitel 4: Komplexitätstheorie*
# Die Klassen P und NP
## Die Klasse P
![[Komplexitätstheorie#Die Klasse P#Beschreibung]]

![[Komplexitätstheorie#Die Klasse P#Probleme der Klasse P]]

## Reduktion auf Entscheidungsprobleme
In dieser Vorlesung werden in erster Linie Entscheidungsprobleme in die Klassen P und NP eingeteilt. Da man jedoch anhand von [[Beweistechniken#^c978bf|Turing-Reduktionen]] auch Optimierungsprobleme (mit lediglich polynomiellem Zeitverlust) auch auf Entscheidungsprobleme zurückführen kann, ist dies keine wirkliche Einschränkung: ist ein Entscheidungsproblem in der Klasse P, dann ist auch das zugehörige Optimierungsproblem in der Klasse P.

Wir zeigen dies am Beispiel des [[Cliquenproblem|Cliquenproblems]]. Wir können bspw. die Optimierungsvariante auf die Wertvariante wie folgt reduzieren, indem wir mit `A(G)` einen polynomiellen Algorithmus für die Wertvariante voraussetzen:
```
A_opt(G) {
	k* = A(G);
	V' := V = {v_1,...,v_N};
	for (i = 0; i <= N; i++) {
		G' := Induzierter Teilgraph von G mit Knotenmenge V' \ {v_i};
		if (A(G')==k*)
			V' := V' \ {v_i};
	}
	return V';
}
```

