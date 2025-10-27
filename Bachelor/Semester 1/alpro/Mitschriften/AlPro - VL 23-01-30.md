Datum: 30.01.
[[05_Objektorientierte_Programmierung_mit_C++_09.pdf|Folien]]

**Faustregel für Abstrakte Klasse vs. Template**
Falls die "Ist-Ein"-Regel Sinn ergibt, nimmt man eine abstrakte Klasse.

![[SOLID-Prinzipien#SOLID-Prinzipien]]

# Mehr UML
![[UML#Associations]]

![[UML#Dependency]]

![[UML#Aggregation]]
Neben der Inheritance ist die Aggregation die einzige Objektbeziehung, die in C++ syntaktisch erzwungen wird.
Eine Aggregation, die keine Composition ist, wird (meistens) durch Referenzen oder Shared Pointer modelliert.

![[UML#Composition]]
Eine Composition wird (meistens) durch ein direktes Memberobjekt (also keine Referenzen oder Shared Pointer) modelliert.