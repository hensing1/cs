Folien: [[02_Imperative_Programmierung_mit_C++_01.pdf|Imperative Programmierung mit C++ - 01]]
# Unser Computermodell
![[AlPro - Einleitung#Abstraktes Computermodell zum Zweck dieser Vorlesung]]

Dieses Computermodell beschreibt eine **x86-64**-Architektur, auf der ein **GNU/Linux**-Betriebssystem läuft. In dieser Vorlesung werden lediglich [[Glossar#Nutzerprozess|Nutzerprozesse]] behandelt, ("Prozess" im Rahmen dieser Vorlesung bedeutet ab sofort "Nutzerprozess").

Der virtuelle Adressraum reicht von `0x0000 0000 0000` bis `0x7FFF FFFF FFFF`. An jeder Adresse liegt genau ein Byte. Dieser Adressraum (sowie die CPU-Register) enthält alle Programmbefehle und Programmdaten.

# Grundlegende Datentypen
- `int`
	- besteht aus 4 Bytes, darstellbare Zahlen reichen von $-2^{31}$ bis $2^{31}-1$
- `unsigned int`
	- $0$ bis $2^{32}-1$
- `double`
	- 8 Byte-[[Kodierung von Binärzahlen#IEEE 754|Gleitkommazahl]]
- `char`
	- 1 Byte, interpretiert als Zeichen
- `wchar`
	- "wide char"
	- 1, 2 oder 4 Byte, interpretiert als Zeichen
- `bool`
	- Umsetzung eines `bool`s im Speicher hängt tatsächlich vom Compiler ab, ist nicht im C++-Standard definiert

Es gibt noch weitere, die sind aber für diese Vorlesung nicht wichtig.

Um die Anzahl der verwendeten Bytes pro Datentyp zu bestimmen, gibt es den Operator `sizeof(type)`.

# Variablen
Eine Variable benennt einen Wert im Speicher, damit man ihn später wiederfindet.

Zu einer Variable gehören:
- Name
	- muss mit einem Buchstaben beginnen, darf ansonsten Buchstaben und Zahlen enthalten
- Typ
	- z.B. `int`
- Wert
	- z.B. `42`
- Adresse
	- z.B. `0x7FFF FFFF FF50`

## Expressions

> [!definition]
> **Expression**
> Ein Stück Programmcode, das den Wert eines definierten Typs berechnet.

Beispiele:
- `42`
- `'F'`
- `alter` (falls `alter` ein Variablenname ist)
- `3+4`
- `factorial(4)`

# Literale, Konstanten und Operatoren
## Literale

> [!definition]
> **Literal**
> Die textuelle Darstellung eines festen Werts (eines gegebenen Datentyps) im Programmcode.

Beispiele:
- `1234`
- `3.14159265`
- `'F'`
- `"Hallo Welt"`

## Konstanten
- Tanten von Kon
- `const double pi = 4`

## Operatoren
`+ - * / % ...`
Mit Operatoren kann man Expressions verknüpfen. Dabei entsteht eine neue Expression. Je nach Datentyp stehen verschiedene Operatoren zur Verfügung.

### Implizites Typecaseing
Beispiele:
- `int + double = double`
- `int / int = int`
- `int / double = double`

### Operatorpräzedenz und Assoziativität
Bei einer Expression mit mehreren Operatoren legt die Operatorpräzedenz fest, welcher Operator zuerst ausgewertet wird. 
Sind die Operatoren dieselben, wird das Verhalten durch die Assoziativität festgelegt.

Detaillierte Info für C++ [hier](https://en.cppreference.com/w/c/language/operator_precedence).

Im Zweifel (und für Lesbarkeit): Klammern setzen.

### Logische Operatoren
`==` und `!=`, `&&` und `||`
Funktionieren in C++ genauso wie in anderen C-like sprachen auch, im Falle von AND und OR wird die zweite Expression nicht ausgewertet, wenn durch die erste bereits das Ergebnis bestimmt wird.

Negation von `a`: `!a`

### Bitweise Operatoren
Bitshift: `<<` und `>>`
Bitweises UND: `a & b`
Bitweises ODER: `a | b`
Bitweises XOR: `a ^ b`
`~a`: Umkehrung von jedem Bit in `a`

Bei bitweisen Operatoren werden beide Expressions ausgewertet, bevor die Operation ausgeführt wird. 

### Operatoren-Abkürzungen
Die ganzen Operatoren gibt's dann noch in Kombination mit `=`, also `+=`, `-=`, `%=`, `|=`, bla bla bla.

# Noch mehr Statements
## Compound Statements
> Folge von Statements, die durch einen `{}`-Block zusammengefasst wurden.

```cpp
// Dies ist ein Compound Statement:  
{  
	int x = 3;  
	drucke_zahl(3);  
}
```

## Scope
> Bereich, in dem eine Variable bekannt ist.

Wird eine Variable innerhalb eines Compound Statements deklariert, ist sie nur innerhalb dieses Compound Statements bekannt.

```cpp
{  
	int x; // Hier wird x deklariert  
	{  
		x = 3; // Hier ist x bekannt  
	}  
}  
x = 4; // Hier ist x unbekannt
```

Wird innerhalb eines Compound Statements eine Variable aufgerufen, wird "von innen nach außen" nach dieser Variable gesucht:

```cpp
int x = 4;
{
	int x = 5;
	{
	  x = 9; // ändert x = 5 zu x = 9
	}
}
drucke_zahl(x); // druckt 4
```

## Fun Fact
Es gibt kein `else if`-Statement. Es gibt sowas:
```
if (EXPRESSION)  
	STATEMENT  
else  
	STATEMENT
```
..und `if (EXPRESSION) { }` ist selbst wiederum ein Statement. Und deshalb:
```
if (EXPRESSION) {  
	...  
} else if (EXPRESSION) {  
	...  
} else if (EXPRESSION) {  
	...  
}
```

