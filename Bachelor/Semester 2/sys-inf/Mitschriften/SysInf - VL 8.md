Datum: 06.06.
[[SysInf_Kap_2_230505_1035.pdf|Folien Kapitel 2]] (ab Seite 77)
[[SysInf_Kap_3_230526_1204.pdf|Folien Kapitel 3]] (bis Seite 9)

# Der Rest von Kapitel 2
## Der Rest der Analyse

![[Der Kompilierprozess#Semantische Analyse]]

## Synthese
In der Synthese wird der in der Analysephase erzeugte Zwischencode in die Maschinensprache der Zielmaschine übersetzt. Der zentrale Teil der Syntese ist also die **Code-Erzeugung**.

![[Der Kompilierprozess#Registerzuteilung]]

*Kapitel 3*
# Prozesse und Prozessverwaltung
## Parallele und nebenläufige Prozesse

Wir unterscheiden zwischen:
- *Parallelen* (tasächlich gleichzeitig auf mehreren Prozessen laufenden) und *verzahnten* (abwechselnd auf demselben Prozessor laufenden) Prozessen
	- Beide werden als *nebenläufige* Prozesse bezeichnet
- Threads als "leichte Prozesse", welche besonders einfach umgeschaltet werden können
- *Process* als ausführbare Einheit (vom Scheduler verwaltet) und *Task* (behandelt als grundlegende (nicht teilbare??) Arbeitseinheit)
- *Multiprocessing* (mehrere Prozessoren), *Multitasking* (ein Prozessor) und *Multiprogramming* (Multitasking mit automatischer Speicherverwaltung)

ja, ich weiß auch nicht.