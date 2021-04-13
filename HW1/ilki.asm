load r0, 10
load r1, -1
load r2, 12
jmpLE r2<=r0, goster
jmp hata

 	
goster:  	load R0, 0
		jmpEQ r2=r0, bitir		
		addi r2, r1, r2
		jmp goster


		bitir: load rf, text
			text: db "Bitti"

hata: load rf, 12h
	load rf, 17d