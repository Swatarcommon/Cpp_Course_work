.586
.model flat, stdcall
includelib userlib.lib
includelib kernel32.lib
includelib libucrt.lib

ExitProcess PROTO : DWORD
squadro PROTO : DWORD
copystr PROTO : DWORD, : DWORD
strcon PROTO : DWORD, : DWORD
quadro PROTO : SDWORD
outstr PROTO : DWORD
outint PROTO : SDWORD 
.stack 4096
.const
	overflow db 'ERROR: VARIABLE OVERFLOW', 0 
	null_division db 'ERROR: DIVISION BY ZERO', 0
.data
	main_b SDWORD 0
.code

main PROC
	push main_b
	call outint


	jmp EXIT
	EXIT_DIV_ON_NULL:
	push offset null_division
	call outstr
	push - 1
	call ExitProcess

	EXIT_OVERFLOW:
	push offset overflow
	call outstr
	push - 2
	call ExitProcess

	EXIT:
	push 0
	call ExitProcess

main ENDP
end main