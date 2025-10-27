# ARM-Assembly

Die ARM Assembly Language (die nichts mit AMD zu tun hat) ist eine [[TI - VL 23#Einteilung von Instruction Sets|RISC]]-Assembly für ARM-Prozessoren. 
Die meisten Smartphones laufen auf ARM.

- ARM-Befehle arbeiten nur auf Registern
- nutzen Load/Store-Befehle für Speicherzugriff
- es gibt 31 allgemein verfügbare 64-bit-Register X0 - X30

> **Hello World in ARM**
> ```ARM
> .text
> .global _start
> _start:
> 	mov r0, #1
> 	ldr r1, =message
> 	ldr r2, =len
> 	mov r7, #4
> 	swi 0
> 	mov r7, #1
> 	swi 0
> 	
> .data
> message:
> 	.asciz "hello world\n"
> 	len = .-message
> ```