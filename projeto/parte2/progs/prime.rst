ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 1.



                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 2.8.0 #5117 (Mar 23 2008) (UNIX)
                              4 ; This file was generated Sat Jun  4 20:41:44 2011
                              5 ;--------------------------------------------------------
                              6 	.module prime
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
   FFFE 38 00                23 	.dw	__sdcc_gs_init_startup
                             24 
                             25 	.area GSINIT0
   3800                      26 __sdcc_gs_init_startup:
   3800 45 38 01             27 	ldhx	#0x3801
   3803 94                   28 	txs
   3804 CD 38 87             29 	jsr	__sdcc_external_startup
   3807 27 03                30 	beq	__sdcc_init_data
   3809 CC 38 21             31 	jmp	__sdcc_program_startup
   380C                      32 __sdcc_init_data:
                             33 ; _hc08_genXINIT() start
   380C 45 00 00             34         ldhx #0
   380F                      35 00001$:
   380F 65 00 00             36         cphx #l_XINIT
   3812 27 0A                37         beq  00002$
   3814 D6 39 8A             38         lda  s_XINIT,x
   3817 D7 40 0A             39         sta  s_XISEG,x
   381A AF 01                40         aix  #1
   381C 20 F1                41         bra  00001$
   381E                      42 00002$:
                             43 ; _hc08_genXINIT() end
                             44 	.area GSFINAL
   381E CC 38 21             45 	jmp	__sdcc_program_startup
                             46 
                             47 	.area CSEG
   3821                      48 __sdcc_program_startup:
   3821 CD 38 64             49 	jsr	_main
   3824 CC 00 00             50 	jmp	0x0000
                             51 ;--------------------------------------------------------
                             52 ; Public variables in this module
                             53 ;--------------------------------------------------------
                             54 	.globl _main
                             55 	.globl _prime
                             56 ;--------------------------------------------------------
ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 2.



                             57 ;  ram data
                             58 ;--------------------------------------------------------
                             59 	.area DSEG
   0020                      60 _prime_sloc0_1_0:
   0020                      61 	.ds 2
                             62 ;--------------------------------------------------------
                             63 ; overlayable items in  ram 
                             64 ;--------------------------------------------------------
                             65 	.area OSEG    (OVR)
                             66 ;--------------------------------------------------------
                             67 ; absolute external ram data
                             68 ;--------------------------------------------------------
                             69 	.area XABS    (ABS)
                             70 ;--------------------------------------------------------
                             71 ; external initialized ram data
                             72 ;--------------------------------------------------------
                             73 	.area XISEG
                             74 ;--------------------------------------------------------
                             75 ; extended address mode data
                             76 ;--------------------------------------------------------
                             77 	.area XSEG
   3FFD                      78 _prime_n_1_1:
   3FFD                      79 	.ds 2
   3FFF                      80 _main_b_1_1:
   3FFF                      81 	.ds 2
                             82 ;--------------------------------------------------------
                             83 ; global & static initialisations
                             84 ;--------------------------------------------------------
                             85 	.area HOME (CODE)
                             86 	.area GSINIT (CODE)
                             87 	.area GSFINAL (CODE)
                             88 	.area GSINIT (CODE)
                             89 ;--------------------------------------------------------
                             90 ; Home
                             91 ;--------------------------------------------------------
                             92 	.area HOME (CODE)
                             93 	.area HOME (CODE)
                             94 ;--------------------------------------------------------
                             95 ; code
                             96 ;--------------------------------------------------------
                             97 	.area CSEG (CODE)
                             98 ;------------------------------------------------------------
                             99 ;Allocation info for local variables in function 'prime'
                            100 ;------------------------------------------------------------
                            101 ;sloc0                     Allocated with name '_prime_sloc0_1_0'
                            102 ;n                         Allocated with name '_prime_n_1_1'
                            103 ;i                         Allocated to registers 
                            104 ;------------------------------------------------------------
                            105 ;prime.c:1: int prime(int n) {
                            106 ;	-----------------------------------------
                            107 ;	 function prime
                            108 ;	-----------------------------------------
   3827                     109 _prime:
   3827 C7 3F FE            110 	sta	(_prime_n_1_1 + 1)
   382A CF 3F FD            111 	stx	_prime_n_1_1
                            112 ;prime.c:3: while ( (i < n) && (n % i) ) {
ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 3.



   382D 3F 20               113 	clr	*_prime_sloc0_1_0
   382F 6E 02 21            114 	mov	#0x02,*(_prime_sloc0_1_0 + 1)
   3832                     115 00102$:
   3832 B6 21               116 	lda	*(_prime_sloc0_1_0 + 1)
   3834 C0 3F FE            117 	sub	(_prime_n_1_1 + 1)
   3837 B6 20               118 	lda	*_prime_sloc0_1_0
   3839 C2 3F FD            119 	sbc	_prime_n_1_1
   383C 90 21               120 	bge	00104$
   383E                     121 00111$:
   383E B6 20               122 	lda	*_prime_sloc0_1_0
   3840 C7 40 01            123 	sta	__modsint_PARM_2
   3843 B6 21               124 	lda	*(_prime_sloc0_1_0 + 1)
   3845 C7 40 02            125 	sta	(__modsint_PARM_2 + 1)
   3848 CE 3F FD            126 	ldx	_prime_n_1_1
   384B C6 3F FE            127 	lda	(_prime_n_1_1 + 1)
   384E CD 38 89            128 	jsr	__modsint
   3851 4D                  129 	tsta
   3852 26 01               130 	bne	00112$
   3854 5D                  131 	tstx
   3855                     132 00112$:
   3855 27 08               133 	beq	00104$
   3857                     134 00113$:
                            135 ;prime.c:4: i++;
   3857 55 20               136 	ldhx	*_prime_sloc0_1_0
   3859 AF 01               137 	aix	#1
   385B 35 20               138 	sthx	*_prime_sloc0_1_0
   385D 20 D3               139 	bra	00102$
   385F                     140 00104$:
                            141 ;prime.c:6: return i;
   385F BE 20               142 	ldx	*_prime_sloc0_1_0
   3861 B6 21               143 	lda	*(_prime_sloc0_1_0 + 1)
   3863                     144 00105$:
   3863 81                  145 	rts
                            146 ;------------------------------------------------------------
                            147 ;Allocation info for local variables in function 'main'
                            148 ;------------------------------------------------------------
                            149 ;a                         Allocated to registers 
                            150 ;b                         Allocated with name '_main_b_1_1'
                            151 ;c                         Allocated to registers 
                            152 ;------------------------------------------------------------
                            153 ;prime.c:9: int main (void) {
                            154 ;	-----------------------------------------
                            155 ;	 function main
                            156 ;	-----------------------------------------
   3864                     157 _main:
                            158 ;prime.c:14: b = prime(a);
   3864 AE 02               159 	ldx	#0x02
   3866 A6 CF               160 	lda	#0xCF
   3868 CD 38 27            161 	jsr	_prime
   386B C7 40 00            162 	sta	(_main_b_1_1 + 1)
   386E CF 3F FF            163 	stx	_main_b_1_1
                            164 ;prime.c:16: if (a == b) {
   3871 C6 40 00            165 	lda	(_main_b_1_1 + 1)
   3874 A1 CF               166 	cmp	#0xCF
   3876 26 07               167 	bne	00107$
   3878 C6 3F FF            168 	lda	_main_b_1_1
ASxxxx Assembler V01.70 + NoICE + SDCC mods + Flat24 Feb-1999  (Motorola 68HC08), page 4.



   387B A1 02               169 	cmp	#0x02
   387D 27 03               170 	beq	00109$
   387F                     171 00107$:
   387F 4F                  172 	clra
   3880 20 02               173 	bra	00108$
   3882                     174 00109$:
   3882 A6 01               175 	lda	#0x01
   3884                     176 00108$:
                            177 ;prime.c:24: return 0;
   3884 5F                  178 	clrx
   3885 4F                  179 	clra
   3886                     180 00104$:
   3886 81                  181 	rts
                            182 	.area CSEG (CODE)
                            183 	.area CONST   (CODE)
                            184 	.area XINIT
                            185 	.area CABS    (ABS,CODE)
