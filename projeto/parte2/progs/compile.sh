#HSC08
#./sdcc --code-loc 0x4000 --stack-loc 0x4000 --data-loc 0x0080 --xram-loc 0x8000 -mhc08 $1".c"
#RS08
#./sdcc --code-loc 0x3800 --stack-loc 0x3800 --data-loc 0x0020 --xram-loc 0x3FFD -mhc08 $1".c"
./sdcc --code-loc 0x3800 --stack-loc 0x3800 --data-loc 0x0020 --xram-loc 0x3FFD -mhc08 $1".c"
asm=$1".asm"
rel=$1".rel"
sed -e "s/bra\t\./jmp\t0x0000/" $1".asm" > $1".tmp"
mv -f $1".tmp" $1".asm"
sed "s/$rel/-t\n$rel/g" $1".lnk" > $1".tmp"
mv -f $1".tmp" $1".lnk"
./as-hc08 -losfjga $1".asm" 
./link-hc08 -f $1".lnk"
	
