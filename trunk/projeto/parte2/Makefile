#acsim mips1.ac -abi
#make -f Makefile.archc
#mips1.x --load=<nome do programa que você quer executar> <parâmetros para o pro#grama>

all:
	/home/Tiago/Desktop/archc-2.0/src/acsim/acsim rs08.ac -abi
	make -f Makefile.archc

add:
	./rs08.x --load=teste.c
local:
	acsim rs08.ac 
	make -f Makefile.archc
	./rs08.x --load=teste.c

teste:
	sdcc --code-loc 0x4000 --stack-loc 0x4000 --data-loc 0x0080 --xram-loc 0x8000 -mhc08 teste.c
	asm=$1".asm"
	rel=$1".rel"
	sed -e "s/bra\t\./jmp\t0x0000/" $1".asm" > $1".tmp"
	mv -f $1".tmp" $1".asm"
	sed "s/$rel/-t\n$rel/g" $1".lnk" > $1".tmp"
	mv -f $1".tmp" $1".lnk"
	as-hc08 -losfjga $1".asm" 
	link-hc08 -f $1".lnk"