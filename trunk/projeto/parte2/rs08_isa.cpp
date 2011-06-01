#include "rs08_isa.H"
#include "rs08_isa_init.cpp"
#include "rs08_bhv_macros.H"
#include <systemc.h>

//global var declarations
sc_uint<16> pc;
sc_int<8> rel;
int start_address;

//Initialize special registers for simulation
void ac_behavior ( begin ) {
    CCR = 0x00;
    start_address = ac_start_addr;
}

void ac_behavior ( end ) {
}

//!Generic instruction behavior method.
void ac_behavior ( instruction ) {
    int a;
    char *name;
    sc_uint<16> sp;
    sc_uint<2> ccr;
    sc_uint<8> reg_A;
  
    sp.range(7,0) = SPC.SPCL;
    sp.range(13,8) = SPC.SPCL;
    ccr[0] = CCR.C;
    ccr[1] = CCR.Z;
    reg_A = A;
    pc = ac_pc;
    PC.PCH = pc.range(13,8);
    PC.PCL = pc.range(7,0);
}
 
//! Instruction Format behavior methods.
void ac_behavior( Type_IMM ) {}
void ac_behavior( Type_IMD ) {}
void ac_behavior( Type_IMM_DIR ) {}
void ac_behavior( Type_DIR ) {}
void ac_behavior( Type_DD ) {}
void ac_behavior( Type_INH ) {}
void ac_behavior( Type_EXT ) {}
void ac_behavior( Type_REL ) {
     rel = addr2;
}
  
/* Immediate addressing mode instructions */
void ac_behavior ( adci ) {

  sc_uint<9> sum;   /* 1 bit a mais para verificar carry*/
  sc_uint<8> reg_A; /* Acumulador */
  sc_uint<8> imm;   /*Imediato */
  sc_uint<2> ccr;   /* ccr[0]= Carry,ccr[1]= Zero */
  
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  imm = byte2;
  reg_A = A;
  
  ccr = ccr & 0x01;
  
  sum = reg_A + imm + ccr[0];
  
  A = sum.range(7,0);
  /*carry*/
  if ( sum[8] ) {
    ccr[0] = 1;
  }
  /*zero*/
  if ( !A ) {
    ccr[1] = 1;
  }
  //  CCR = ccr;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

/* Immediate addressing mode instructions */
void ac_behavior ( addi ) {

  sc_uint<9> sum;   /* 1 bit a mais para verificar carry*/
  sc_uint<8> reg_A; /* Acumulador */
  sc_uint<8> imm;   /*Imediato */
  sc_uint<2> ccr;   /* ccr[0]= Carry,ccr[1]= Zero */
  
  //  ccr = CCR;

  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  imm = byte2;
  reg_A = A;
  
  ccr = ccr & 0x00;  /* zerando flags*/
  
  sum = reg_A + imm ;/* Soma sem carry*/
  
  A = sum.range(7,0);
  /*carry*/
  if ( sum[8] ) {
    ccr[0] = 1;
  }
  /*zero*/
  if ( !A ) {
    ccr[1] = 1;
  }
  CCR.Z = ccr[1];
  CCR.C = ccr[1];

}

/*TO DO*/
void ac_behavior ( andi ) {}
void ac_behavior ( cmpi ) {}
void ac_behavior ( eori ) {}
void ac_behavior ( ldai ) {}
void ac_behavior ( orai ) {}
void ac_behavior ( subi ) {}
void ac_behavior ( movi ) {}
void ac_behavior ( inc ) {}
void ac_behavior ( cmp ) {}
void ac_behavior ( clr ) {}
void ac_behavior ( and ) {}
void ac_behavior ( ora ) {}
void ac_behavior ( eor ) {}
void ac_behavior ( lda ) {}
void ac_behavior ( sta ) {}
void ac_behavior ( mov ) {}
void ac_behavior ( beq ) {}
void ac_behavior ( lsra ) {}
void ac_behavior ( lsla ) {}
void ac_behavior ( rola ) {}
void ac_behavior ( rora ) {}
void ac_behavior ( jmp ) {}
void ac_behavior ( add ) {}
void ac_behavior ( sub ) {}
void ac_behavior ( adc ) {}
void ac_behavior ( dec ) {}