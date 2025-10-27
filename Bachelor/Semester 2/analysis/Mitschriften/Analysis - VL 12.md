Datum: 17.05.
[Annotiertes Skript](https://ecampus.uni-bonn.de/goto_ecampus_file_3046506_download.html)
[Notizen aus der Vorlesung](https://ecampus.uni-bonn.de/goto_ecampus_file_3046507_download.html)

*Kapitel 3: Stetigkeit*
# Umkehrfunktionen
![[Funktionen#^2568b3]]
![[Funktionen#^109abb]]

![[Funktionen#Monotonie]]

> Sei $f : \left[a,b\right]\to \mathbb{R}$ eine *stetige, streng monoton wachsende* Funktion.
> Dann ist $f$ bijektiv und es existiert die Umkehrfunktion $f^{-1}: \left[f(a),f(b)\right]\to \left[a,b\right]$. Zudem ist $f^{-1}$ ebenfalls stetig und streng monoton wachsend.

Dieser Satz gilt für streng monoton fallende Funktionen analog.

# Logarithmusfunktion
Bei uns in der Vorlesung meint $\log(x)$ die Umkehrfunktion von $\exp(x)$, also $\ln(x)$.

Mithilfe des natürlichen Logarithmus können wir jetzt endlich rellwertige Exponenten definieren:

> [!abstract] **Potenz**
> Seien $a,x \in \mathbb{R}$ und $a>0$. Wir definieren: $$a^{x}:=\exp(x \cdot \ln(a)).$$

Wir machen hier also den Ansatz, dass wir erst den Logarithmus definieren und dann die ganzen Potenzgesetze daraus herleiten. 
Die Potenzgesetze vorausgesetzt, kann man sich aber auch die o.g. Definition herleiten:
$$\exp(x \cdot \ln(a))=e^{x \cdot \ln(a)}=(e^{\ln (a)})^{x}=\exp(\ln(a))^{x}=a^{x}$$

Wir definieren den Logarithmus für beliebige Basen $a$ wie folgt:
> $$\log_{a}x:=\frac{\ln x}{\ln a}.$$

