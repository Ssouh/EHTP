TITLE Calcul Nombre Elements
; This program calculates the number of elements of an array
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
myArray WORD 30 DUP(?)
ArraySize = ($-myArray)/4 ; ceci est le nombre d'�lements


.code
main PROC

exit
main ENDP
END main