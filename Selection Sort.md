Selection Sort ist ein [[Algorithmen#Funktionsweise#Vergleichsbasiertheit|vergleichsbasierter]] Sortieralgorithmus mit [[Größenordnungen|Laufzeit]] $\mathcal{O}(n^2)$.

### Funktionsweise
Die Grundidee besteht darin, in jedem Schritt das kleinste verbleibende Element nach vorne zu sortieren. Dieses Element schreibt man dann entweder in ein separates Array ([[Algorithmen#Speicherplatz|out-of-place]]), oder man tauscht es mit dem aktuellen Element (in-place). 
Wenn man links in der Liste anfängt und immer das kleinste Element selektiert, nennt man das ganze auch **Min Sort**. Das Gegenteilige Äquivalent heißt **Max Sort**.