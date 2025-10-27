Datum: 06.05.
[[AI09_SS24_Planning_240506_240503.pdf|Folien]]

# Handlungsplanung

## Planung im Situationskalkül

Im [[GdKI - VL 8#Situationskalkül|Situationskalkül]] kann man über logische Inferenz eine Handlungsplanung erstellen:

- Initialer Zustand $s_0$
- Operatoren
- Zielbedingungen

Ein initialer Zustand könnte beschrieben werden mit `At(home, s0) ∧ ￢Have(milk, s0)`.

Ein Operator (Nachfolgezustandsaxiom) könnte so aussehen:
`∀a, s Have(milk, do(a, s)) ⇔ {a=buy(milk) ∧ Poss(buy(milk), s) ∨ Have(milk, s) ∧ a ≠ drop(milk)}`

Eine Zielbedingung kann formuliert werden mit `∃s At(home, s) ∧ Have(milk, s)`

a

## Strips-Formalismus
*ST*anford *R*esearch *I*nstitute *P*roblem *S*olver (STRIPS)

- Der Weltzustand besteht aus Aussagen über Grundatome
	- Konstanten sind die einzigen Funktionssymbole
	- alles, was nicht in der Wissensbasis ist, ist falsch (Closed World Assumption)
- Zielbedingungen sind auch nur Aussagen über Grundatome

Eine *Aktion* besteht aus:
- Aktionsname
	- Funktionsname mit Parametern
- Vorbedingungen
	- Konjunktion positiver Literale
- Effekte
	- Konjunktion positiver und negativer Literale
	- Positive Literale werden in die KB aufgenommen, negative werden gelöscht

