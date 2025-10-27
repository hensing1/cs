Datum: 24.10.
[[Kapitel_1.0_Maschinenprogrammierung_WS2324_v1031_Teil1.pdf|Folien - Teil 1]] von S. 39 bis Ende
[[Kapitel_1.0_Maschinenprogrammierung_WS2324_v1023_Teil2.pdf|Folien - Teil 2]] bis S. 13

# Mehr Assembler

![[x86-64#Assembler-Syntax Intel vs. AT&T]]

![[x86-64#Adressierungsarten]]

## Jetzt Assembly wirklich richtig

### Summe
C:
```C
summe = a + b + c + d;
```

Assembly:
```asm
mov rax, [a]
add rax, [b]
add rax, [c]
add rax, [d]
```
### If-Else
C:
```C
if (a == 4711) {
	...
}
else {
	...
}
```
Assembly:
```nasm
	cmp rax, 4711
	jne else
if:            ; dekoratives Label
	...
	jmp endif
else:
	...
endif:
	...
```

### Schleife
```C
for (int i = 101; i > 0; i--) {
	...
}
```

```x86
	mov rcx, 101
schleife:
	...
	loop schleife
```

`loop` dekrementiert erst `rcx` und springt wenn ungleich 0. Das heißt, wenn `rcx` direkt bei Loopbeginn auf 0 steht, wird die Schleife $2^{64}$-mal ausgeführt.
Flags werden *nicht* gesetzt.

Alternativ:
```asm
	mov rcx, 0
schleife:
	...
	inc rcx
	cmp rcx, 100
	jne schleife
```
## Calling Conventions

![[x86-64#Funktionsaufruf]]

### cdecl
cdecl ist die Standard-Calling Convention für (32-Bit) x86 C-Compiler. 

Funktionsparameter werden in umgekehrter Reihenfolge auf den Stack gepusht. Danach kommt die Rücksprungadresse.
D.h.:
- `esp` & `ebp`: alter `ebp`
- `ebp + 4`: Rücksprungadresse
- `ebp + 8`: erster Parameter
- `ebp + 12`: zweiter Parameter
- ...

Ist der return-Wert ein Int oder Pointer, kommt er in `eax`.

Die Register `eax`, `ecx` und `edx` sind caller-saved, können also von der aufgerufenen Funktion überschrieben werden.
Die restlichen Register müssen von der Funktion wiederhergestellt werden.

![[x86-64#System V AMD64 ABI]]