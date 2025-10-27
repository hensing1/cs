# Nichtlineare Filterung

Bitte Rauschen loswerden.

Wir kennen:
- Lokale lineare Filterung (z.B. Gauss)
- Lokale nichtlineare Filterung (Medianfilter)
- [[CV 2 - Filtering#Bilaterales Filter|Bilaterales Filter]]
- Dekonvolution mit Wiener-Filter (letzte VL)

> [!info] *Flash-Noflash-Imaging:*
> Je länger die Aufnahmezeit, desto mehr Sensorrauschen bekommt das Bild.
> Wir möchten aber trotzdem die natürlichen Lichtverhältnisse erfassen (ohne Blitz).
> - Nimm verrauschtes Langzeitbelichtungsbild, glätte mit bilateralem Filter
> - Nimm unverrauschtes Blitzlichtbild, nimm Details durch Filterung mit ($\mathrm{Id}-$Bilaterales Filter)
> - Addiere zusammen


## Total Variation (TV)
Idee: ein unverrauschtes Bild hat geringere Gradienten als ein verrauschtes Bild (sparse gradients).

