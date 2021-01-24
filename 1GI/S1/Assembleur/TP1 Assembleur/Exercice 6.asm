TITLE Constantes Textuelles Symboliques
; This program defines symbolic constants
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
chaine1 BYTE "ceci est une chaine"
chaine2 BYTE "voila une deuxieme"
chaine3 BYTE "encore une"
chainen BYTE "enfin la derniere chaine"



.code
main PROC

exit
main ENDP
END main