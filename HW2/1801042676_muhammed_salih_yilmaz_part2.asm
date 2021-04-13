	load    R1, String	;loads the string
	load    R2, -1		;decreases step
	load    R0, 0		;finish string

Loop:	load    RF, [R1]		;get character and print it on screen
	addi    R1, R1, R2	;decreases address
	jmpEQ   RF=R0, fin	;if RF is equal to finish string, then go to fin
	jmp     Loop		;restarts the loop

fin:	halt

		db	0		;Stops the string
		db	"Test", 10
String:	db	10		;Makes one line of empty space


;By writing the string to the last place, we make it start from the bottom.
;This allows program to rewrite it backwards.
