TITLE Calcul Nombre Octets 
; This program calculates the number of bytes of an array
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
myArray WORD 20 DUP(?)
ArraySize=($-myArray) ; ceci est le nombre d'octets


.code
main PROC

exit
main ENDP
END main