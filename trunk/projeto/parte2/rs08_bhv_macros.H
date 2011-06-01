#ifndef _RS08_BHV_MACROS_H
#define _RS08_BHV_MACROS_H

typedef ac_memport<rs08_parms::ac_word, rs08_parms::ac_Hword> ac_memory;

#define ac_behavior(instr) AC_BEHAVIOR_##instr ()

#define AC_BEHAVIOR_instruction() rs08_parms::rs08_isa::_behavior_instruction(unsigned int op)

#define AC_BEHAVIOR_begin() rs08_parms::rs08_isa::_behavior_begin()
#define AC_BEHAVIOR_end() rs08_parms::rs08_isa::_behavior_end()

#define AC_BEHAVIOR_Type_IMM() rs08_parms::rs08_isa::_behavior_rs08_Type_IMM(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_Type_IMD() rs08_parms::rs08_isa::_behavior_rs08_Type_IMD(unsigned int op, unsigned int byte2, unsigned int addr3)
#define AC_BEHAVIOR_Type_IMM_DIR() rs08_parms::rs08_isa::_behavior_rs08_Type_IMM_DIR(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_Type_DIR() rs08_parms::rs08_isa::_behavior_rs08_Type_DIR(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_Type_DD() rs08_parms::rs08_isa::_behavior_rs08_Type_DD(unsigned int op, unsigned int byte2, unsigned int byte3)
#define AC_BEHAVIOR_Type_REL() rs08_parms::rs08_isa::_behavior_rs08_Type_REL(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_Type_INH() rs08_parms::rs08_isa::_behavior_rs08_Type_INH(unsigned int op)
#define AC_BEHAVIOR_Type_EXT() rs08_parms::rs08_isa::_behavior_rs08_Type_EXT(unsigned int op, unsigned int addr)

#define AC_BEHAVIOR_adci() rs08_parms::rs08_isa::behavior_adci(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_andi() rs08_parms::rs08_isa::behavior_andi(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_cmpi() rs08_parms::rs08_isa::behavior_cmpi(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_eori() rs08_parms::rs08_isa::behavior_eori(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_ldai() rs08_parms::rs08_isa::behavior_ldai(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_orai() rs08_parms::rs08_isa::behavior_orai(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_subi() rs08_parms::rs08_isa::behavior_subi(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_movi() rs08_parms::rs08_isa::behavior_movi(unsigned int op, unsigned int byte2, unsigned int addr3)
#define AC_BEHAVIOR_addi() rs08_parms::rs08_isa::behavior_addi(unsigned int op, unsigned int byte2)
#define AC_BEHAVIOR_add() rs08_parms::rs08_isa::behavior_add(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_adc() rs08_parms::rs08_isa::behavior_adc(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_sub() rs08_parms::rs08_isa::behavior_sub(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_inc() rs08_parms::rs08_isa::behavior_inc(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_dec() rs08_parms::rs08_isa::behavior_dec(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_cmp() rs08_parms::rs08_isa::behavior_cmp(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_clr() rs08_parms::rs08_isa::behavior_clr(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_and() rs08_parms::rs08_isa::behavior_and(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_ora() rs08_parms::rs08_isa::behavior_ora(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_eor() rs08_parms::rs08_isa::behavior_eor(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_lda() rs08_parms::rs08_isa::behavior_lda(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_sta() rs08_parms::rs08_isa::behavior_sta(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_mov() rs08_parms::rs08_isa::behavior_mov(unsigned int op, unsigned int byte2, unsigned int byte3)
#define AC_BEHAVIOR_beq() rs08_parms::rs08_isa::behavior_beq(unsigned int op, unsigned int addr2)
#define AC_BEHAVIOR_lsra() rs08_parms::rs08_isa::behavior_lsra(unsigned int op)
#define AC_BEHAVIOR_lsla() rs08_parms::rs08_isa::behavior_lsla(unsigned int op)
#define AC_BEHAVIOR_rola() rs08_parms::rs08_isa::behavior_rola(unsigned int op)
#define AC_BEHAVIOR_rora() rs08_parms::rs08_isa::behavior_rora(unsigned int op)
#define AC_BEHAVIOR_jmp() rs08_parms::rs08_isa::behavior_jmp(unsigned int op, unsigned int addr)


#endif //_RS08_BHV_MACROS_H

