; Verilen  stringi tersten ekrana basar

DRIVER:

	load r1,0xB0 ; Start adress data
	load r2,0xD0 ; store data start adress
	
START:
	move r8,r1
	load r0,0
	load r9,1
	load r3,1 ; counter for fýnd size
LOOP_FIND_SIZE:
	load r4,[r8]
	addi r8,r8,r9
	addi r3,r3,r9
	jmpeq r4=r0,START1
	jmp LOOP_FIND_SIZE
START1:
	move r9,r2 
	load r8,0 ; counter
	load r7,1
	load r6,-1
	addi r4,r3,r1 ; READER FÝRST ADRESS
	addi r4,r4,r6 ; decrase READER ADRESS
	move r0,r3

LOOP_STORE:

	load r5,[r4] ; Read data from adress
	addi r4,r4,r6 ; decrease reader adres for next loop
	addi r8,r8,r7 ; counter +1
	store r5,[r2]
	addi r2,r2,r7
	jmple r8<=r0,LOOP_STORE ; size>counter go LOOP_STORE
	
CONTINUE_LOOP:
load r8,0 ;COUNTER RESET

load rf,10 ;clear screen
load rf,10 ;clear screen
load rf,10 ;clear screen
load rf,10 ;clear screen

LOOP_PRINT: 
	load ra,[r9]
	move rf,ra
	addi r9,r9,r7
	addi r8,r8,r7
	jmpLE r8<=r0,LOOP_PRINT
	 

halt	

org 0xB0
db "ERAWTFOS PTA",0
