Datum: 31.01.

| Semantik            | Syntax (Kalkül) |
| ------------------- | --------------- |
| $W \models \varphi$ | $W \vdash \varphi$                |

$$(W\rightarrow \varphi) \text{ ist Tautologie} \iff \square \in \text{Res}^{*}(K(W)\cup K(\lnot \varphi))$$

Algorithmus zur Bestimmung, ob Formel $\varphi$ erfüllbar ist oder nicht:
```
Ist_erfüllbar(phi):
	R = K(phi)
	while (R != Res(R)):
		R = Res(R)
	if ({} in R):
		return "phi nicht erfüllbar"
	else:
		return "phi erfüllbar"
```

Terminiert garantiert, ist aber NP-vollständig

# Prädikatenlogik
Mehr Syntax, um Sachverhalte auszudrücken:
"Wenn x ein Mensch ist, der älter ist als 130, dann ist die Wahrscheinlichkeit, dass er tot ist, 100%":
$$\forall x((\text{mensch}(x) \land >(\text{alter}(x),130)) \rightarrow \space =(\text{WsTot}(x),1))$$
> [!abstract] Definition
> Eine **Signatur** ist eine Menge von irgendwas
