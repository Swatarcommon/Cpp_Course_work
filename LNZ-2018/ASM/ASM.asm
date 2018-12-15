.586
.model flat, stdcall
includelib userlib.lib
includelib kernel32.lib
includelib libucrt.lib

ExitProcess PROTO : DWORD
sqroot PROTO : DWORD
copystr PROTO : DWORD, : DWORD
strcon PROTO : DWORD, : DWORD
sqr PROTO : SDWORD
outstr PROTO : DWORD
outint PROTO : SDWORD 
.stack 4096
.const
	overflow db 'ERROR: VARIABLE OVERFLOW', 0 
	null_division db 'ERROR: DIVISION BY ZERO', 0
	_Lit1 SDWORD 2
	_Lit2 SDWORD 5
	_Lit3 SDWORD 3
	_Lit4 BYTE "AGA", 0
	_Lit5 BYTE "PRiVET", 0
	_Lit6 BYTE " ", 0
	_Lit7 BYTE "SANYA, KADA VIEBISH MILFU! :)", 0
	_Lit8 SDWORD 144
.data
	func_z SDWORD 0
	main_x SDWORD 0
	main_y SDWORD 0
	main_z SDWORD 0
	main_sa BYTE 255 DUP(0)
	main_sb BYTE 255 DUP(0)
.code

func_proc PROC, func_x : SDWORD, func_y : SDWORD
	push _Lit1
	push func_x
	push func_y
	pop eax
	pop ebx
	add eax, ebx
	jo EXIT_OVERFLOW
	push eax
	pop eax
	pop ebx
	imul eax, ebx
	jo EXIT_OVERFLOW
	push eax
	pop func_z
	push func_z

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
	pop eax
	ret 8

func_proc ENDP

main PROC
	push _Lit2
	pop main_x
	push main_x
	call outint

	push _Lit3
	pop main_y
	push main_y
	call outint

	push offset _Lit4
	push offset main_sa
	call copystr

	push offset main_sa
	call outstr

	push offset _Lit5
	push offset main_sb
	call copystr

	push offset main_sb
	call outstr

	push offset main_sb
	push offset _Lit6
	call strcon
	jo EXIT_OVERFLOW
	push eax
	push offset _Lit7
	call strcon
	jo EXIT_OVERFLOW
	push eax
	push offset main_sb
	call copystr

	push offset main_sb
	call outstr

	push _Lit8
	call sqroot
	push eax
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