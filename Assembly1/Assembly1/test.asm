.386					;Specifies the architecture
.model flat, stdcall	;Specifies the calling structure/layout
.stack 4096				;Stack size is 4k bytes

includelib libcmt.lib
includelib legacy_stdio_definitions.lib


ExitProcess PROTO, dwExitCode:DWORD	; Going to use an function called ExitProcess that's prebuilt

extern printf:NEAR
extern scanf:NEAR


.data ;variables will go here
	;nameofvar type initialvalue
	;type-->how much space each instance of that variable takes up
	
	prompt BYTE "Enter a value: ", 0
	format BYTE "%d", 0
	val DWORD 0		
	msg BYTE "Your input was: %d", 0

.code ;code will go here

main PROC c     ;main will go here

	mov eax, 9	;move 9 into the eax register

	;Code to call printf to get the prompt
	push eax
	push ebx
	push ecx
	push edx

	;printf(prompt)
	push offset prompt
	call printf
	add esp, 4

	pop edx
	pop ecx
	pop ebx
	pop eax

	;Code to call scanf
	push eax
	push ebx
	push ecx
	push edx

	; scanf("%d", &val);
	push offset val
	push offset format
	call scanf
	add esp, 8

	pop edx
	pop ecx
	pop ebx
	pop eax

	;Saving registers so that printf doesn't erase data
	push eax
	push ebx
	push ecx
	push edx

	;printf(msg, val) --> pass variables by pushing them 
	;onto the stack (in reverse order)
	push val			;push contents of eax onto the stack
	push offset msg		;push address of msg onto the stack
	call printf

	;Effectively clears the arguments from the stack
	;Changing where the top of the stack is
	add esp,8

	pop edx
	pop ecx
	pop ebx
	pop eax

	INVOKE ExitProcess, 9	;terminate the program

main endp	;Used to indicate the end point of main
end

