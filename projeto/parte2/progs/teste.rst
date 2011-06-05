ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 1.



                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.8.0 #5117 (Mar 23 2008) (UNIX)
                              4 ; This file was generated Sat Jun  4 20:42:21 2011
                              5 ;--------------------------------------------------------
                              6 	.module teste
                              7 	.optsdcc -mhc08
                              8 	
                              9 	.area HOME (CODE)
                             10 	.area GSINIT0 (CODE)
                             11 	.area GSINIT (CODE)
                             12 	.area GSFINAL (CODE)
                             13 	.area CSEG (CODE)
                             14 	.area XINIT
                             15 	.area CONST   (CODE)
                             16 	.area DSEG
                             17 	.area OSEG    (OVR)
                             18 	.area BSEG
                             19 	.area XSEG
                             20 	.area XISEG
                             21 	.area	CODEIVT (ABS)
   FFFE                      22 	.org	0xfffe
   FFFE 80 00                23 	.dw	__sdcc_gs_init_startup
                             24 
                             25 	.area GSINIT0
   8000                      26 __sdcc_gs_init_startup:
   8000 45 80 00             27 	ldhx	#0x8000
   8003 94                   28 	txs
   8004 CD 80 2A             29 	jsr	__sdcc_external_startup
   8007 27 03                30 	beq	__sdcc_init_data
   8009 CC 80 21             31 	jmp	__sdcc_program_startup
   800C                      32 __sdcc_init_data:
                             33 ; _hc08_genXINIT() start
   800C 45 00 00             34         ldhx #0
   800F                      35 00001$:
   800F 65 00 00             36         cphx #l_XINIT
   8012 27 0A                37         beq  00002$
   8014 D6 80 2C             38         lda  s_XINIT,x
   8017 D7 00 20             39         sta  s_XISEG,x
   801A AF 01                40         aix  #1
   801C 20 F1                41         bra  00001$
   801E                      42 00002$:
                             43 ; _hc08_genXINIT() end
                             44 	.area GSFINAL
   801E CC 80 21             45 	jmp	__sdcc_program_startup
                             46 
                             47 	.area CSEG
   8021                      48 __sdcc_program_startup:
   8021 CD 80 27             49 	jsr	_main
   8024 CC 00 00             50 	jmp	0x0000
                             51 ;--------------------------------------------------------
                             52 ; Public variables in this module
                             53 ;--------------------------------------------------------
                             54 	.globl _main
                             55 ;--------------------------------------------------------
                             56 ;  ram data
ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 2.



                             57 ;--------------------------------------------------------
                             58 	.area DSEG
                             59 ;--------------------------------------------------------
                             60 ; overlayable items in  ram 
                             61 ;--------------------------------------------------------
                             62 	.area OSEG    (OVR)
                             63 ;--------------------------------------------------------
                             64 ; absolute external ram data
                             65 ;--------------------------------------------------------
                             66 	.area XABS    (ABS)
                             67 ;--------------------------------------------------------
                             68 ; external initialized ram data
                             69 ;--------------------------------------------------------
                             70 	.area XISEG
                             71 ;--------------------------------------------------------
                             72 ; extended address mode data
                             73 ;--------------------------------------------------------
                             74 	.area XSEG
                             75 ;--------------------------------------------------------
                             76 ; global & static initialisations
                             77 ;--------------------------------------------------------
                             78 	.area HOME (CODE)
                             79 	.area GSINIT (CODE)
                             80 	.area GSFINAL (CODE)
                             81 	.area GSINIT (CODE)
                             82 ;--------------------------------------------------------
                             83 ; Home
                             84 ;--------------------------------------------------------
                             85 	.area HOME (CODE)
                             86 	.area HOME (CODE)
                             87 ;--------------------------------------------------------
                             88 ; code
                             89 ;--------------------------------------------------------
                             90 	.area CSEG (CODE)
                             91 ;------------------------------------------------------------
                             92 ;Allocation info for local variables in function 'main'
                             93 ;------------------------------------------------------------
                             94 ;a                         Allocated to registers 
                             95 ;b                         Allocated to registers 
                             96 ;------------------------------------------------------------
                             97 ;teste.c:4: int main(){
                             98 ;	-----------------------------------------
                             99 ;	 function main
                            100 ;	-----------------------------------------
   8027                     101 _main:
                            102 ;teste.c:12: return 0;
   8027 5F                  103 	clrx
   8028 4F                  104 	clra
   8029                     105 00101$:
   8029 81                  106 	rts
                            107 	.area CSEG (CODE)
                            108 	.area CONST   (CODE)
                            109 	.area XINIT
                            110 	.area CABS    (ABS,CODE)
