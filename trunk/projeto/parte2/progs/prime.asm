;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 2.8.0 #5117 (Mar 23 2008) (UNIX)
; This file was generated Sat Jun  4 20:41:44 2011
;--------------------------------------------------------
	.module prime
	.optsdcc -mhc08
	
	.area HOME (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT (CODE)
	.area GSFINAL (CODE)
	.area CSEG (CODE)
	.area XINIT
	.area CONST   (CODE)
	.area DSEG
	.area OSEG    (OVR)
	.area BSEG
	.area XSEG
	.area XISEG
	.area	CODEIVT (ABS)
	.org	0xfffe
	.dw	__sdcc_gs_init_startup

	.area GSINIT0
__sdcc_gs_init_startup:
	ldhx	#0x3801
	txs
	jsr	__sdcc_external_startup
	beq	__sdcc_init_data
	jmp	__sdcc_program_startup
__sdcc_init_data:
; _hc08_genXINIT() start
        ldhx #0
00001$:
        cphx #l_XINIT
        beq  00002$
        lda  s_XINIT,x
        sta  s_XISEG,x
        aix  #1
        bra  00001$
00002$:
; _hc08_genXINIT() end
	.area GSFINAL
	jmp	__sdcc_program_startup

	.area CSEG
__sdcc_program_startup:
	jsr	_main
	jmp	0x0000
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _prime
;--------------------------------------------------------
;  ram data
;--------------------------------------------------------
	.area DSEG
_prime_sloc0_1_0:
	.ds 2
;--------------------------------------------------------
; overlayable items in  ram 
;--------------------------------------------------------
	.area OSEG    (OVR)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG
;--------------------------------------------------------
; extended address mode data
;--------------------------------------------------------
	.area XSEG
_prime_n_1_1:
	.ds 2
_main_b_1_1:
	.ds 2
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME (CODE)
	.area GSINIT (CODE)
	.area GSFINAL (CODE)
	.area GSINIT (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME (CODE)
	.area HOME (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'prime'
;------------------------------------------------------------
;sloc0                     Allocated with name '_prime_sloc0_1_0'
;n                         Allocated with name '_prime_n_1_1'
;i                         Allocated to registers 
;------------------------------------------------------------
;prime.c:1: int prime(int n) {
;	-----------------------------------------
;	 function prime
;	-----------------------------------------
_prime:
	sta	(_prime_n_1_1 + 1)
	stx	_prime_n_1_1
;prime.c:3: while ( (i < n) && (n % i) ) {
	clr	*_prime_sloc0_1_0
	mov	#0x02,*(_prime_sloc0_1_0 + 1)
00102$:
	lda	*(_prime_sloc0_1_0 + 1)
	sub	(_prime_n_1_1 + 1)
	lda	*_prime_sloc0_1_0
	sbc	_prime_n_1_1
	bge	00104$
00111$:
	lda	*_prime_sloc0_1_0
	sta	__modsint_PARM_2
	lda	*(_prime_sloc0_1_0 + 1)
	sta	(__modsint_PARM_2 + 1)
	ldx	_prime_n_1_1
	lda	(_prime_n_1_1 + 1)
	jsr	__modsint
	tsta
	bne	00112$
	tstx
00112$:
	beq	00104$
00113$:
;prime.c:4: i++;
	ldhx	*_prime_sloc0_1_0
	aix	#1
	sthx	*_prime_sloc0_1_0
	bra	00102$
00104$:
;prime.c:6: return i;
	ldx	*_prime_sloc0_1_0
	lda	*(_prime_sloc0_1_0 + 1)
00105$:
	rts
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;a                         Allocated to registers 
;b                         Allocated with name '_main_b_1_1'
;c                         Allocated to registers 
;------------------------------------------------------------
;prime.c:9: int main (void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;prime.c:14: b = prime(a);
	ldx	#0x02
	lda	#0xCF
	jsr	_prime
	sta	(_main_b_1_1 + 1)
	stx	_main_b_1_1
;prime.c:16: if (a == b) {
	lda	(_main_b_1_1 + 1)
	cmp	#0xCF
	bne	00107$
	lda	_main_b_1_1
	cmp	#0x02
	beq	00109$
00107$:
	clra
	bra	00108$
00109$:
	lda	#0x01
00108$:
;prime.c:24: return 0;
	clrx
	clra
00104$:
	rts
	.area CSEG (CODE)
	.area CONST   (CODE)
	.area XINIT
	.area CABS    (ABS,CODE)
