TITLE Definitions
; This program gives known variable types with examples
.386
.model flat,stdcall
include \masm32\include\masm32rt.inc
.data
N1 BYTE 'I'
N2 WORD 13B7h
N3 DWORD 1AB9C332h
N4 SBYTE -18 
N5 DB 200
N6 DB -19
TAB BYTE 23,19,5,8,33
quad1 QWORD 115999999999999h

.code
main PROC

exit
main ENDP
END main