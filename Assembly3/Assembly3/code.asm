.model flat, stdcall
.stack 4096

includelib libcmt.lib
includelib legacy_stdio_definitions.lib

ExitProcess PROTO, dwExitCode:DWORD

extern printf:NEAR
extern scanf:NEAR

.data

prompt BYTE "Enter the numerical grade: ", 0
format BYTE "%d", 0
numgrade DWORD 0
messagea BYTE "Letter grade: A", 0ah, 0
messageb BYTE "Letter grade: B", 0ah, 0
messagec BYTE "Letter grade: C", 0ah, 0
messaged BYTE "Letter grade: D", 0ah, 0
elsemsg BYTE "Letter grade: F", 0ah, 0


.code
main PROC c

push offset prompt
call printf
add esp,4

push offset numgrade
push offset format
call scanf
add esp,8

mov eax,numgrade ; move numgrade into eax so we can easily compare it

; As are >= 90
cmp eax, 90
jl Bbranch

;Section that prints the A message
Abranch:

	push offset messagea
	call printf
	add esp,4
	jmp endofif

Bbranch:
	
	cmp eax, 80
	jl Cbranch

	push offset messageb
	call printf
	add esp,4
	jmp endofif

Cbranch:
	
	cmp eax, 70
	jl Dbranch

	push offset messagec
	call printf
	add esp,4
	jmp endofif

Dbranch:
	
	cmp eax, 60
	jl elsebranch

	push offset messaged
	call printf
	add esp,4
	jmp endofif


;Section that prints the else message
elsebranch:

	push offset elsemsg
	call printf
	add esp,4

endofif:

	INVOKE ExitProcess,0
main endp
end