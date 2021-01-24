TITLE Constantes Entiers Symboliques
; This program defines symbolic constants
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
Lundi BYTE 1
Mardi BYTE 2
Mercredi BYTE 3
Jeudi BYTE 4
Vendredi BYTE 5
Samedi BYTE 6
Dimanche BYTE 7

Semaine DWORD Lundi,Mardi,Mercredi,Jeudi,Vendredi,Samedi,Dimanche

.code
main PROC

exit
main ENDP
END main