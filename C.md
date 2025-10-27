
## Datentypen
- Es gibt kein `bool`
	- stattdessen: `int`, mit `0` als `false` und allem anderen als `true`
- Es gibt wohl `bool`
	- `#include <stdbool.h>`
	- `true` und `false` sind trotzdem bloß Makros für `1` und `0`
- Größe von `int` nicht fix
	- 4 Byte für gcc/i386, 2 Byte für viele embedded devices
	- Kann mit `sizeof(int)` festgestellt werden
- Es gibt kein `string`
	- Strings werden mit `char*` umgesetzt:
		- `"hi"` steht für ein char-Array mit `'h', 'i', '\0'`

## Pointer
- Gewöhnliche Variable: `char c = 'a';  // c hat den Wert 'a'`
	- `&c` ist die Speicherzelle dieser Variable
- Pointer: `char* pc;`
	- `pc = &c;  // pc ist nun ein Pointer auf c`
- Pointer dereferenzieren:
	- `*pc = 'x'  // c hat nun den Wert 'x'`
- Pointerarithmetik:
	- `pc += 3;  // pc zeigt nun auf die Speicheradresse 3 Adressen hinter c`
	- falls `sizeof(*pc)` gleich 2 ist, zeigt `pc + 3` auf 6 Speicheradressen hinter `pc`(!)

- Arrays:
	- `int a[4];` macht (in einer Funktion) auf dem Stack Platz für 4 Ints hintereinander.
		- Allocation auf dem Heap: `int* a = malloc(4 * sizeof(int));`
			- Der Unterschied ist, dass mit `malloc` der Speicher nicht mehr automatisch freigegeben wird, wenn der Scope verlassen wird. Man muss den Speicher mit `free(a);` wieder freigeben. Passiert das nicht, hat man einen Memory Leak.
	- `a[2]` ist gleichbedeutend mit `*(a + 2)` (*nicht* gleichbedeutend mit `*(a + 2 * sizeof(int))`)

## Kompilieren

*Nur eine Quelldatei:*
```bash
$ clang quelldatei.c -o ausführbare_datei
```

*Mehrere Quelldateien:*
Jede Quelldatei kompilieren (nur Objektdatei erzeugen):
```bash
$ clang -c quelldatei1.c -o objektdatei1.o
$ clang -c quelldatei2.c -o objektdatei2.o
$ clang -c quelldatei3.c -o objektdatei3.o
```

Linken:
```bash
$ clang objektdatei1.o objektdatei2.o objektdatei3.o -o ausführbare_datei
```