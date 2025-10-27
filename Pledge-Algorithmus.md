# Problem
Ich befinde mich in einem Labyrinth und möchte den Ausgang finden (ich kann nicht das gesamte Labyrinth überblicken)

# Lösungsweg
## Rechte-Hand-Algorithmus
(oder linke Hand)
### Idee
- Man läuft so lange, bis man eine Wand findet
- Man orientiert sich so, dass die Wand zu seiner rechten ist
- Man folgt der Wand so lange, bis man draußen ist
### Problem
Falls man eine Innere Wand erwischt hat, kommt man nicht raus

## Angepasster Rechte-Hand-Algorithmus
### Idee
Man folgt dem Rechte-Hand-Algorithmus, verlässt die Wand jedoch, sobald man sich in der ursprünglichen Ausrichtung (Rotation) befindet
### Problem
Es kann trotzdem sein, dass man in einer Sackgasse hängen bleibt

## Pledge-Algorithmus
- Man merkt sich, wie oft man sich insgesamt linksrum oder rechtsrum gedreht hat
- Man verlässt die Wand erst dann, wenn man sich genauso oft linksrum wie rechtsrum gedreht hat

-> Der Pledge-Algorithmus ist für das o.g. Problem [[Algorithmen#Korrektheit|korrekt]].