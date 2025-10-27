Datum: 10.06.

# Physikbasierte Simulation und Animation

*Heute:* Partikelsimulation.

> *Partikel*
> - Ein Partikel ist ein Massepunkt
> - Attribute:
> 	- Masse $m$ (kg)
> 	- Position $\vec x$ (m)

Daraus abgeleitet:
- Geschwindigkeit $\vec v$ (m/s)
-  Beschleunigung $\vec a = \frac{\Delta \vec v}{\Delta \vec t}$ (m/s^2)
- Impuls $\vec p = m \vec v$ (kg m/s)
- Kraft $\vec F = \frac{d \vec p}{dt} = m \vec a$ (1 N = 1 kg m/s^2)
- Arbeit $W = \int_{p_{1}}^{p_{2}}\vec F \, d\vec x = \int_{t_{1}}^{t_{2}}\vec F\vec v\,dt$ (1 J = 1 Nm = 1 kg m^2/s^2)
	- $\Delta W = \vec F \Delta\vec x$


Simulation: jeder Schritt macht einen Fehler in $\mathcal{O}(h^2)$ mit Schrittweite $h$

