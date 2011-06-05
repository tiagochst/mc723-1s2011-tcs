#include "rs08_isa.H"
#include "rs08_isa_init.cpp"
#include "rs08_bhv_macros.H"
#include <systemc.h>



/* Auxiliary contents */
typedef struct {
    char name[10];
    int amount;    
} ac_statistic;

struct statistc_instruction {
    ac_statistic vector[310];
    int size;
} statistc_instr;

struct statistc_addressing_mode {
    ac_statistic vector[12];
    int size;
} statistc_addr_mode;

int cmpstr(const void *a, const void *b ) {
   return strcmp( (char *)a, (char *)b );
}

int compare(const void *a, const void *b ) {
   return ( ((ac_statistic *)a)->amount - ((ac_statistic *)b)->amount);
}

/* Execute a search in ac_statistic vectors */
int search_vector ( ac_statistic *v, char *w, int *s ) {
    ac_statistic *a;

    a = (ac_statistic *)bsearch(w, v, *s, sizeof(ac_statistic), cmpstr);
    if (a) {
       a->amount++;
    } else {
       strcpy(v[*s].name,w);
       v[*s].amount++;
       (*s)++;
       qsort(v, *s, sizeof(ac_statistic), cmpstr);
    }
}
/* end-Auxiliary contents */

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
    int a, aux, sv, st;

    fprintf(stderr, "\nInternal RAM\n-------------------");

    for (a = 0x0020; a <= 0x0040; a++) {
       if (!(a % 4)) {
          fprintf (stderr,"\n");
       }
       fprintf(stderr, "[%04X] = [%02X]\t", a, RAM.read(a));
    }
    
    fprintf(stderr, "\nExternal RAM\n-------------------");
    
    for (a = 0x3800; a <= 0x38080; a++) {
       if (!(a % 4)) {
          fprintf (stderr,"\n");
       }
       fprintf(stderr, "[%04X] = [%02X]\t", a, RAM.read(a));
    }

    st = statistc_instr.size;
    qsort(statistc_instr.vector, st, sizeof(ac_statistic), compare);
    sv = (st > 10)?10:st;

    fprintf(stderr, "\nStatistics for Instructions\n-----------------------------\n");

    for (a = 0; a < sv; a++) {
       aux = st-a-1;
       fprintf(stderr, " Instr = %15s\tExec = %5d\n", statistc_instr.vector[aux].name, statistc_instr.vector[aux].amount);
    }

    st = statistc_addr_mode.size;
    qsort(statistc_addr_mode.vector, st, sizeof(ac_statistic), compare);
    sv = (st > 5)?5:st;

    fprintf(stderr, "\nStatistics for Addressing Modes\n-----------------------------\n");

    for (a = 0; a < sv; a++) {
        aux = st-a-1;
       fprintf(stderr, " Addr-Mode = %11s\tExec = %5d\n", statistc_addr_mode.vector[aux].name, statistc_addr_mode.vector[aux].amount);
    }

    fprintf(stderr, "\n ac_heap = %4x\n", ac_heap_ptr);
    fprintf(stderr, "\n----------------over simulation-----------------\n");
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
  sc_uint<8> imm;   /* Imediato */
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
  
  imm = byte2;
  reg_A = A;
  
  ccr = 0;  /* zerando flags*/
  
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
  CCR.C = ccr[0];

}

void ac_behavior ( cmpi ) {
  sc_uint<8> ccr;
  sc_uint<8> imm;
  sc_uint<8> reg_A;
  sc_uint<9> sub;

  ccr = 0;
  reg_A = A;
  imm = byte2;
  sub = reg_A - byte2;

  /*zero*/
  if ( !sub ) {
    ccr[1] = 1;
  }
  /*carry*/
  if ( ((!reg_A[7])&imm[7])|(imm[7]&sub[7])|(sub[7]&(!reg_A[7])) ) {
    ccr[0] = 1;
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}


void ac_behavior ( ldai ) {
  sc_uint<8> ccr;
  sc_uint<8> reg_A;
  

  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  
  reg_A = byte2;
  
  /*zero*/
  if ( !reg_A ) {
    ccr[1] = 1;
  }
  
  A = reg_A;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  
}

void ac_behavior ( orai ) { /* Tiago P2 */
  sc_uint<8> ccr;
  sc_uint<8> reg_A;


  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  reg_A = A | byte2;

  /*zero*/
  if ( !reg_A ) {
    ccr[1] = 1;
  }

  A = reg_A;
  //    CCR = ccr;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

void ac_behavior ( movi ) {
  sc_uint<8> ccr;
  sc_uint<8> imm;
  
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  
  imm = byte2;
  
  RAM.write(addr3, imm);
  
  /*zero*/
  if ( !imm ) {
    ccr[1] = 1;
  }
  
  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  
}


/* Tiago P2 */
void ac_behavior ( inc ) {
  sc_uint<9> sum;
  sc_uint<8> ccr;
  sc_uint<8> byte;

  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  ccr = ccr & 0x01;
  byte = RAM.read(addr2);
  sum = byte + 1;
  
  /*zero*/
  if ( !sum ) {
    ccr[1] = 1;    
  }
  
  // CCR = ccr;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

  RAM.write( addr2, sum.range(7,0) );
    
}

void ac_behavior ( cmp ) {
  sc_uint<8> ccr;
  sc_uint<8> byte;
  sc_uint<8> reg_A;
  sc_uint<9> sub;

  ccr = 0;
  byte = RAM.read(addr2);
  reg_A = A;
  sub = reg_A - byte;
  
  /*zero*/
  if ( !sub ) {
    ccr[1] = 1;
  }
  
  /*carry*/
  if ( ((!reg_A[7])&byte[7])|(byte[7]&sub[7])|(sub[7]&(!reg_A[7])) ) {
    ccr[0] = 1;
  }
  
  CCR.Z = ccr[1];
  CCR.C = ccr[0];
} 


void ac_behavior ( ora ) {  /* Tiago P2 */
  sc_uint<8> reg_A;
  sc_uint<8> ccr;

  reg_A = A | RAM.read(addr2);
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  ccr = ccr & 0x01;
  
  /*zero*/
  if ( !reg_A ) {
    ccr[1] = 1;
  }
  
  A = reg_A;

  //CCR = ccr;

  CCR.Z = ccr[1];
  CCR.C = ccr[0];
}



void ac_behavior ( lda ) {
  sc_uint<8> reg_A;
  sc_uint<8> ccr;

  reg_A = RAM.read(addr2);
    
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  
  /*zero*/
  if ( !reg_A ) {
    ccr[1] = 1;
  }
    
  A = reg_A;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}


void ac_behavior ( sta ) {
    sc_uint<8> reg_A;
    sc_uint<8> ccr;

    ccr[0] = CCR.C;
    ccr[1] = CCR.Z;
    ccr = ccr & 0x01;
 
    reg_A = A;
    RAM.write(addr2, reg_A);

    /*zero*/
    if ( !reg_A ) {
      ccr[1] = 1;
    }

    CCR.Z = ccr[1];
    CCR.C = ccr[0];
    
} 


void ac_behavior ( mov ) {
  sc_uint<8> ccr;
  sc_uint<8> imm;

  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  
  imm = RAM.read(byte2);
  
  RAM.write(byte3, imm);
  
  /*zero*/
  if ( !imm ) {
    ccr[1] = 1;
  }
  
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

void ac_behavior ( dec ) { /* Tiago P2*/
  sc_uint<9> sum;
  sc_uint<8> ccr;
  sc_uint<8> byte;
  
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;

  byte = RAM.read(addr2);
  sum = byte - 1;
  
  /*zero*/
  if ( !sum ) {
    ccr[1] = 1;    
  }
  
  //CCR = ccr;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  RAM.write( addr2, sum.range(7,0) );
  
} 

/* Douglas P2*/
void ac_behavior ( andi ) {

  sc_uint<8> ccr;
  sc_uint<8> reg_A;


  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;
  reg_A = A & byte2;

  /*zero*/
  if ( !reg_A ) {
    ccr[1] = 1;
  }

  A = reg_A;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

/* Douglas P2 */
void ac_behavior ( clr ) {

  A  = A & 0x0;
  RAM.write(addr2, 0);
  CCR.C = CCR.C & 0x0;
  CCR.Z = CCR.Z & 0x0;

}

/* Douglas P2 */
void ac_behavior ( and ) {

  sc_uint<8> ccr;
  sc_uint<8> reg_A;
  sc_uint<8> byte;


  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  ccr = ccr & 0x01;

  byte = RAM.read(addr2);
  reg_A = A & byte;

  /* Zero */
  if ( !reg_A ) {
    ccr[1] = 1;
  }

  A = reg_A;
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

/* Douglas P2*/
void ac_behavior ( add ) {

  sc_uint<9> sum;   /* 1 bit a mais para verificar carry*/
  sc_uint<8> reg_A;
  sc_uint<8> byte;
  sc_uint<2> ccr;   /* ccr[0]= Carry,ccr[1]= Zero */
  
  byte = RAM.read(addr2);
  reg_A = A;
  
  ccr = 0;  /* zerando flags*/
  
  sum = reg_A + byte ;
  
  A = sum.range(7,0);
  /* Carry */
  if ( sum[8] ) {
    ccr[0] = 1;
  }
  /* Zero */
  if ( !A ) {
    ccr[1] = 1;
  }
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

/* Douglas P2*/
void ac_behavior ( adc ) {

  sc_uint<9> sum;   /* 1 bit a mais para verificar carry*/
  sc_uint<8> reg_A;
  sc_uint<8> byte;
  sc_uint<2> ccr;   /* ccr[0]= Carry,ccr[1]= Zero */
  
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  byte = RAM.read(addr2);
  reg_A = A;
  
  ccr = ccr & 0x01;
  
  sum = reg_A + byte + ccr[0];
  
  A = sum.range(7,0);
  /* Carry */
  if ( sum[8] ) {
    ccr[0] = 1;
  }
  /* Zero */
  if ( !A ) {
    ccr[1] = 1;
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

void ac_behavior ( jmp ) {
  ac_pc = addr;
  pc = ac_pc;
  PC.PCH = pc.range(13,8);
  PC.PCL = pc.range(7,0);
}

void ac_behavior ( eori ) {
	
  sc_uint<8> reg_A; 
  sc_uint<8> imm;   
  sc_uint<2> ccr;   
  
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;

  imm = byte2;
  reg_A = A;
  
  reg_A = reg_A ^ imm;
  
  A = reg_A;
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;
  }
  
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

} 
 
void ac_behavior ( eor ) {

  sc_uint<8> reg_A;
  sc_uint<8> ccr;
  sc_uint<2> byte;

  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  reg_A = A;
  
  byte = RAM.read(addr2);
  reg_A = reg_A ^ byte;
  
  A = reg_A;
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;    
  }
  
  CCR.Z = ccr[1];
  CCR.C = ccr[0];

}

void ac_behavior ( lsra ) {

  sc_uint<8> reg_A;
  sc_uint<2> ccr;

  reg_A = A;

  ccr[0] = reg_A[0];

  reg_A >>= 1;
  reg_A[7] = 0;

  A = reg_A;
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;    
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];
	
}

void ac_behavior ( lsla ) {

  sc_uint<8> reg_A;
  sc_uint<2> ccr;

  reg_A = A;

  ccr[0] = reg_A[7];

  reg_A <<= 1;
  reg_A[0] = 0;

  A = reg_A;
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;    
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  
}

void ac_behavior ( rola ) {
  
  sc_uint<9> reg_A;
  sc_uint<2> ccr;
	
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  
  reg_A = A;
  reg_A <<= 1;
  
  reg_A[0] = ccr[0];
  ccr[0] = reg_A[8]; 
  
  A = reg_A.range(7,0);
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;    
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  
}

void ac_behavior ( rora ) {
  
  sc_uint<9> reg_A;
  sc_uint<2> ccr;
	
  ccr[0] = CCR.C;
  ccr[1] = CCR.Z;
  
  reg_A.range(8,1) = A;
  reg_A >>= 1;
  
  reg_A[8] = ccr[0];
  ccr[0] = reg_A[0];
	
  A = reg_A.range(8,1);
  
  if ( !A && !ccr[1] ) {
    ccr[1] = 1;    
  }

  CCR.Z = ccr[1];
  CCR.C = ccr[0];
  
}

/*TO DO*/
void ac_behavior ( beq ) {
  sc_uint<2> ccr;
  ccr = CCR.Z;
  ccr = CCR.C;
  ccr = ccr & 0x02;

  if (ccr) {
    ac_pc += rel;
    pc = ac_pc;
    PC.PCH = pc.range(13,8);
    PC.PCL = pc.range(7,0);
  }
}
void ac_behavior ( subi ) {}
void ac_behavior ( sub ) {} 
