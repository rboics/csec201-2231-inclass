.386					;Specifies the architecture
.model flat, stdcall	;Specifies the calling structure/layout
.stack 4096				;Stack size is 4k bytes

includelib libcmt.lib
includelib legacy_stdio_definitions.lib


ExitProcess PROTO, dwExitCode:DWORD	; Going to use an function called ExitProcess that's prebuilt

extern printf:NEAR


.data ;variables will go here
	;nameofvar type initialvalue
	;type-->how much space each instance of that variable takes up
	
	msg BYTE "The value of eax is: %d", 0

.code ;code will go here

main PROC c ;main will go here

	mov eax, 9	;move 9 into the eax register

	;printf(msg, eax) --> pass variables by pushing them onto the stack (in reverse order)
	push eax			;push contents of eax onto the stack
	push offset msg		;push address of msg onto the stack
	call printf

	INVOKE ExitProcess, 9	;terminate the program

main endp	;Used to indicate the end point of main
end 

