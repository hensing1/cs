# Mathematische Logik
Die *mathematische Logik* ist ein Teilgebiet der Informatik und Mathematik, das sich damit beschäftigt, wie man formal Schlüsse zieht und Beweise führt.

Anwendungsbereiche sind:
- Repräsentation von Wissen für künstliche Intelligenz
- Grundlage von Datenbanksprachen wie SQL
- Verifikation vn Hardware und Software

Die einfachste Form einer mathematischen Logik ist die [[Aussagenlogik]], welche sich mit der Verknüpfung von atomaren Aussagen befasst. Sie ist relativ ausdrucksschwach, jedoch bildet sie die Grundlage für kompliziertere Logiken.

Eine Erweiterung der Aussagenlogik ist die [[Prädikatenlogik]], welche zusätzlich zu den Verknüpfungen der Aussagenlogik die Quantoren $\exists$ und $\forall$ erlaubt. Die Prädikatenlogik ist deutlich ausdrucksstärker als die Aussagenlogik.

## Kalkül
> [!abstract] Definition
> Ein **Kalkül** ist eine Menge von *syntaktischen Umformungsregeln*, mit denen aus gegebenen Formeln neue Formeln erzeugt werden können.
> Das Ziel beim Entwuf eines Kalküls ist es, die Umformungsregeln so zu wählen, dass sie ein algorithmisches Verfahren ergeben, mit dem getestet werden kann, ob eine gegebene Formel *erfüllbar* ist.

### Korrektheit und Vollständigkeit
> Ein Kalkül heißt **korrekt**, wenn darin nur wahre Aussagen ableitbar sind.
> 
> Ein Kalkül heißt **vollständig**, wenn darin *alle* wahren Aussagen ableitbar sind.

Zum Beispiel ist der Resolutionskalkül aus der Aussagenlogik sowohl korrekt als auch vollständig: mit ihm kann man für jede erfüllbare Formel ableiten, dass sie erfüllbar ist, was wiederum für keine unerfüllbare Formel der Fall ist.