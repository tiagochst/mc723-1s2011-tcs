#acsim mips1.ac -abi
#make -f Makefile.archc
#mips1.x --load=<nome do programa que você quer executar> <parâmetros para o pro#grama>

all:
	acsim rs08.ac 
	make -f Makefile.archc

prime:
	./rs08.x --load=prime.elf
local:
	acsim rs08.ac 
	make -f Makefile.archc
	./rs08.x --load=teste.c

teste:
	./sdcc --code-loc 0x4000 --stack-loc 0x4000 --data-loc 0x0080 --xram-loc 0x8000 -mhc08 teste.c
	asm="teste.asm"
	rel="teste.rel"
	sed -e "s/bra\t\./jmp\t0x0000/" "teste.asm" > "teste.tmp"
	mv -f "teste.tmp" "teste.asm"
	sed "s/teste.rel/-t\nteste.rel/g" "teste.lnk" > "teste.tmp"
	mv -f "teste.tmp" "teste.lnk"
	./as-hc08 -losfjga "teste.asm" 
	./link-hc08 -f "teste.lnk"
