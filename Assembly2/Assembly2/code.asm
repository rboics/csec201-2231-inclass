.386
.model flat, stdcall
.stack 4096

includelib libcmt.lib
includelib legacy_stdio_definitions.lib

ExitProcess PROTO, dwExitCode:DWORD

extern printf:NEAR
extern scanf:NEAR

.data

greater BYTE "The first value was greater", 0
smaller BYTE "The first value was smaller", 0
equal BYTE "The two values are equal", 0

.code
main PROC c
	mov eax, 10
	mov ebx, 9
	cmp eax, ebx 
	;conditional jump - go to some label based on the values in efl
	; j<something> <label>
	; jz, je, jne, jg, jl, jge, jle
	jg printgreater
	jl printsmaller
	je printequal

printgreater:
	push offset greater
	call printf
	add esp,4
	jmp AfterIf ;Non-conditional jump
printsmaller:
	push offset smaller
	call printf
	add esp,4
	jmp AfterIf ;Non-conditional jump
printequal:
	push offset equal
	call printf
	add esp,4
AfterIf:



    INVOKE ExitProcess, 0
main endp
end