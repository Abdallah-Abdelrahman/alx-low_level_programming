; Declare external function
        extern	printf		; the C function, to be called

        SECTION .data		; Data section, initialized variables

fmt:    db 	"%s", 10, 0	; The printf format, "\n",'0'
str:	db"Hello, Holberton",0	; C string needs 0
len:	equ	$-str		; length has value, not an address


        SECTION .text           ; Code section.

        global main		; the standard gcc entry point
main:				; the program label for the entry point
        push    rbp		; set up stack frame

	mov	rdi, fmt	; first argument to printf, format
	mov	rsi, str	; second argument, string
	mov	rdx, len        ; third argument, int
        call    printf		; Call C function

	pop	rbp		; restore stack

	mov	rax,0		; normal, no error, return value
	ret			; return
