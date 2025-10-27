[[algo_I_02_1.pdf|Folien]]
# Methoden zum Entwurf von Algorithmen
## Divide-and-Conquer
![[Algorithmen#Methoden zum Entwurf von Algorithmen#Divide-and-Conquer#Allgemeiner Ansatz]]

### Beispiele
#### Binäre Suche
![[Binary Search#Funktionsweise]]
![[Binary Search#Laufzeit]]

#### Merge Sort
![[Mergesort#Funktionsweise]]

In den Folien steht nun, wie man die Laufzeit via vollständiger Induktion durch eine Rekursionsgleichung bestimmen kann.

>[!attention] Vorsicht bei Beweisen mit O-Notation
>Man sollte nie innerhalb von Induktionsbeweisen mit O-Notation einfach die Konstanten rauslassen, die die Laufzeit nach oben beschränken. Sonst kann es nämlich sein, dass sich die Konstanten in Abhängigkeit von n verändern müssen, damit die Gleichung für beliebige n's gilt - dadurch kann der Beweis falsch werden (steht alles nochmal in den Folien).

#### Strassen-Algorithmus
![[Strassen-Algorithmus#Funktionsweise]]

### Rekursionsgleichungen und Rekursionsbäume

![[Rekursionsgleichungen]]

