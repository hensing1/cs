# SOLID-Prinzipien
Die SOLID-Prinzipien sind fünf miteinander verträgliche Entwurfsprinzipien für die Konzeption langläufiger Projekte.

Ziel ist es unter anderem, Abwärtskompatibilität zu gewährleisten - Schnittstellen sollen sich also langfristig nicht verändern. Weiterhin ist es wünschenswert, dass man Objektinteraktionen für möglichst allgemeine Typen definiert.

> **SOLID-Prinzipien**
> - **Single-Responsibility:** Klassen sollen für genau eine Aufgabe verantwortlich sein.
> - **Open-Closed:** Klassen sollen erweiterbar, aber nicht veränderbar sein.
> - **Liskov-Substitution** soll erfüllt sein ([[SOLID-Prinzipien#Liskovsches Substitutionsprinzip|s.u.]])
> - **Interface-Segregation:** Klassen sollen nicht von Schnittstellen abhängen, die sie nicht verwenden
> - **Dependency-Inversion:** Klassen und Implementierungsdetails sollen von Abstrakten Klassen / Interfaces abhängig sein

## Liskovsches Substitutionsprinzip
> **Faustregel**
> Ein Objekt $X$ vom Typ $S$ ist ein Subtyp von einem Typ $T$, falls folgende Aussage sinnvoll ist:
> > $X$ ist auch ein $T$.

> **Liskovsches Substitutionsprinzip (vereinfacht)**
> Falls der Typ $S$ ein Subtyp vom Typ $T$ ist, dann können Objekte vom Typ $T$ immer durch Objekte vom Typ $S$ ersetzt werden, ohne die gewünschten Eigenschaften eines beliebigen Programms zu verändern.

> **Liskovsches Substitutionsprinzip (Umformulierung)**
> Falls der Typ $S$ ein Subtyp vom Typ $T$ ist, dann fordert $S$ höchstens so viel wie $T$ und bietet mindestens so viel an wie $T$.

## Dependency-Inversion
Klassen werden, je nach ihrem Abstraktheitsgrad, in Ebenen eingeteilt.

> **DIP #1**
> Klassen höherer Ebenen sollten nicht von Klassen auf niedrigeren Ebenen abhängen, sondern beide sollten von Abstraktionen abhängen.

> **DIP #2**
> Details sollten von Abstraktionen abhängen, und nicht andersherum.