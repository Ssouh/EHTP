TITLE Soustraction De 3 Elements
; This program calculates the result of soustraction of 3 elements
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
N1 WORD 0AB96h
N2 WORD 13B7h
N3 WORD 0F321h

.code
main PROC
; on calcule N3 - (N2-N1)
mov ax,N2
sub ax,N1 ; AX = N2 - N1
sub N3,ax ; N3 = N3 - (N2-N1)

;si on veut stocker le resulat dans ax
mov ax,N3

exit
main ENDP
END main