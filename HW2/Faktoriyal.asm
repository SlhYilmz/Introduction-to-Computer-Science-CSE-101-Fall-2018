 Faktöriyel bulur.
;FACTORIAL

DRIVER:
load r1,0x60
load rd,DATA

START:

	load r0,0 ; load 0
	load rb,1 ; incremental +1
	load rE,0xFF ;decremental -1
	load r7,[r1] ;
	load r3,[r1]
	jmpEQ r7=r0,LOOP_END1
START_LOOP: ;
	load ra,1 ;counter
	load r0,0 ;control value.
	load r6,0 ; counter cross action.
	addi r7,rE,r7 ; -1 value
	jmpEQ r7=r0,LOOP_END2
	move r0,r7
LOOP_TOPLA: ; cross action
		addi r6,r3,r6
		addi ra,ra,rb
		jmpLE ra<=r0,LOOP_TOPLA
		move r3,r6 ; saved result before next cross action
	jmp START_LOOP ; continue loop until value of 0.
LOOP_END2:
	move r1,r3 ; move result from r3 to r1.
	
load r0,24;
jmpEQ r1=r0,PRINTING ; if result 24 do printing process.
			;  else stop execution.

LOOP_HALT:	
	; stop execution.
	halt
PRINTING:
	load r0,0 ;compare value
LOOP_PRINT:
	load rf,[rd]
	addi rd,rd,rb
	jmpEQ rf=r0,LOOP_HALT ; if value 0 do stop execution.
	jmp LOOP_PRINT

LOOP_END1: ; if data is 0 . result should be 1.
	load r1,1;
	jmp LOOP_HALT

DATA:
db "Factorial is 24",0


org 0x60
db 4
