/******************************************************
 * AC_ISA Initialization File                         *
 * This file is automatically generated by ArchC      *
 * WITHOUT WARRANTY OF ANY KIND, either express       *
 * or implied.                                        *
 * For more information on ArchC, please visit:       *
 * http://www.archc.org                               *
 *                                                    *
 * The ArchC Team                                     *
 * Computer Systems Laboratory (LSC)                  *
 * IC-UNICAMP                                         *
 * http://www.lsc.ic.unicamp.br                       *
 ******************************************************/
 

#include "rs08_isa.H"

//!Fields table declaration.
ac_dec_field rs08_parms::rs08_isa::fields[rs08_parms::AC_DEC_FIELD_NUMBER] = {
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[1])},
  {"byte2", 8, 15, 2, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[3])},
  {"byte2", 8, 15, 2, 0, 0, &(rs08_parms::rs08_isa::fields[4])},
  {"addr3", 8, 23, 3, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[6])},
  {"byte2", 8, 15, 2, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[8])},
  {"addr2", 8, 15, 4, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[10])},
  {"byte2", 8, 15, 2, 0, 0, &(rs08_parms::rs08_isa::fields[11])},
  {"byte3", 8, 23, 5, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[13])},
  {"addr2", 8, 15, 4, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, NULL},
  {"op", 8, 7, 1, 0, 0, &(rs08_parms::rs08_isa::fields[16])},
  {"addr", 16, 23, 6, 0, 0, NULL}
};

ac_dec_format rs08_parms::rs08_isa::formats[rs08_parms::AC_DEC_FORMAT_NUMBER] = {
  {"Type_IMM", 16, &(rs08_parms::rs08_isa::fields[0]), &(rs08_parms::rs08_isa::formats[1])},
  {"Type_IMD", 24, &(rs08_parms::rs08_isa::fields[2]), &(rs08_parms::rs08_isa::formats[2])},
  {"Type_IMM_DIR", 16, &(rs08_parms::rs08_isa::fields[5]), &(rs08_parms::rs08_isa::formats[3])},
  {"Type_DIR", 16, &(rs08_parms::rs08_isa::fields[7]), &(rs08_parms::rs08_isa::formats[4])},
  {"Type_DD", 24, &(rs08_parms::rs08_isa::fields[9]), &(rs08_parms::rs08_isa::formats[5])},
  {"Type_REL", 16, &(rs08_parms::rs08_isa::fields[12]), &(rs08_parms::rs08_isa::formats[6])},
  {"Type_INH", 8, &(rs08_parms::rs08_isa::fields[14]), &(rs08_parms::rs08_isa::formats[7])},
  {"Type_EXT", 24, &(rs08_parms::rs08_isa::fields[15]), NULL}
};

ac_dec_list rs08_parms::rs08_isa::dec_list[rs08_parms::AC_DEC_LIST_NUMBER] = {
  {"op", 169, NULL},
  {"op", 164, NULL},
  {"op", 161, NULL},
  {"op", 168, NULL},
  {"op", 166, NULL},
  {"op", 170, NULL},
  {"op", 160, NULL},
  {"op", 62, NULL},
  {"op", 171, NULL},
  {"op", 187, NULL},
  {"op", 185, NULL},
  {"op", 176, NULL},
  {"op", 60, NULL},
  {"op", 58, NULL},
  {"op", 177, NULL},
  {"op", 63, NULL},
  {"op", 180, NULL},
  {"op", 186, NULL},
  {"op", 184, NULL},
  {"op", 182, NULL},
  {"op", 183, NULL},
  {"op", 78, NULL},
  {"op", 55, NULL},
  {"op", 68, NULL},
  {"op", 72, NULL},
  {"op", 73, NULL},
  {"op", 70, NULL},
  {"op", 188, NULL}
};

ac_dec_instr rs08_parms::rs08_isa::instructions[rs08_parms::AC_DEC_INSTR_NUMBER] = {
  {"adci", 2, "adc", "adc #%imm", "Type_IMM", 1, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[0]), 0, &(rs08_parms::rs08_isa::instructions[1])},
  {"andi", 2, "and", "and #%imm", "Type_IMM", 2, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[1]), 0, &(rs08_parms::rs08_isa::instructions[2])},
  {"cmpi", 2, "cmp", "cmp #%imm", "Type_IMM", 3, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[2]), 0, &(rs08_parms::rs08_isa::instructions[3])},
  {"eori", 2, "eor", "eor #%imm", "Type_IMM", 4, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[3]), 0, &(rs08_parms::rs08_isa::instructions[4])},
  {"ldai", 2, "lda", "lda #%imm", "Type_IMM", 5, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[4]), 0, &(rs08_parms::rs08_isa::instructions[5])},
  {"orai", 2, "ora", "ora #%imm", "Type_IMM", 6, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[5]), 0, &(rs08_parms::rs08_isa::instructions[6])},
  {"subi", 2, "sub", "sub #%imm", "Type_IMM", 7, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[6]), 0, &(rs08_parms::rs08_isa::instructions[7])},
  {"movi", 3, "mov", "mov *#%imm, *%addr", "Type_IMD", 8, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[7]), 0, &(rs08_parms::rs08_isa::instructions[8])},
  {"addi", 2, "add", "add *#%imm", "Type_IMM_DIR", 9, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[8]), 0, &(rs08_parms::rs08_isa::instructions[9])},
  {"add", 2, "add", "add *%addr", "Type_DIR", 10, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[9]), 0, &(rs08_parms::rs08_isa::instructions[10])},
  {"adc", 2, "adc", "adc *%addr", "Type_DIR", 11, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[10]), 0, &(rs08_parms::rs08_isa::instructions[11])},
  {"sub", 2, "sub", "sub *%addr", "Type_DIR", 12, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[11]), 0, &(rs08_parms::rs08_isa::instructions[12])},
  {"inc", 2, "inc", "inc *%addr", "Type_DIR", 13, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[12]), 0, &(rs08_parms::rs08_isa::instructions[13])},
  {"dec", 2, "dec", "dec *%addr", "Type_DIR", 14, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[13]), 0, &(rs08_parms::rs08_isa::instructions[14])},
  {"cmp", 2, "cmp", "cmp *%addr", "Type_DIR", 15, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[14]), 0, &(rs08_parms::rs08_isa::instructions[15])},
  {"clr", 2, "clr", "clr *%addr", "Type_DIR", 16, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[15]), 0, &(rs08_parms::rs08_isa::instructions[16])},
  {"and", 2, "and", "and *%addr", "Type_DIR", 17, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[16]), 0, &(rs08_parms::rs08_isa::instructions[17])},
  {"ora", 2, "ora", "ora *%addr", "Type_DIR", 18, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[17]), 0, &(rs08_parms::rs08_isa::instructions[18])},
  {"eor", 2, "eor", "eor *%addr", "Type_DIR", 19, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[18]), 0, &(rs08_parms::rs08_isa::instructions[19])},
  {"lda", 2, "lda", "lda *%addr", "Type_DIR", 20, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[19]), 0, &(rs08_parms::rs08_isa::instructions[20])},
  {"sta", 2, "sta", "sta *%addr", "Type_DIR", 21, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[20]), 0, &(rs08_parms::rs08_isa::instructions[21])},
  {"mov", 3, "mov", "mov *%addr, *%addr", "Type_DD", 22, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[21]), 0, &(rs08_parms::rs08_isa::instructions[22])},
  {"beq", 2, "beq", "beq %addr$", "Type_REL", 23, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[22]), 0, &(rs08_parms::rs08_isa::instructions[23])},
  {"lsra", 1, "lsra", "lsra", "Type_INH", 24, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[23]), 0, &(rs08_parms::rs08_isa::instructions[24])},
  {"lsla", 1, "lsla", "lsla", "Type_INH", 25, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[24]), 0, &(rs08_parms::rs08_isa::instructions[25])},
  {"rola", 1, "rola", "rola", "Type_INH", 26, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[25]), 0, &(rs08_parms::rs08_isa::instructions[26])},
  {"rora", 1, "rora", "rora", "Type_INH", 27, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[26]), 0, &(rs08_parms::rs08_isa::instructions[27])},
  {"jmp", 3, "jmp", "jmp %addr", "Type_EXT", 28, 1, 1, 1, &(rs08_parms::rs08_isa::dec_list[27]), 0, NULL}
};

const ac_instr_info
rs08_parms::rs08_isa::instr_table[rs08_parms::AC_DEC_INSTR_NUMBER + 1] = {
  ac_instr_info(0, "_ac_invalid_", "_ac_invalid_", 1),
  ac_instr_info(1, "adci", "adc", 2),
  ac_instr_info(2, "andi", "and", 2),
  ac_instr_info(3, "cmpi", "cmp", 2),
  ac_instr_info(4, "eori", "eor", 2),
  ac_instr_info(5, "ldai", "lda", 2),
  ac_instr_info(6, "orai", "ora", 2),
  ac_instr_info(7, "subi", "sub", 2),
  ac_instr_info(8, "movi", "mov", 3),
  ac_instr_info(9, "addi", "add", 2),
  ac_instr_info(10, "add", "add", 2),
  ac_instr_info(11, "adc", "adc", 2),
  ac_instr_info(12, "sub", "sub", 2),
  ac_instr_info(13, "inc", "inc", 2),
  ac_instr_info(14, "dec", "dec", 2),
  ac_instr_info(15, "cmp", "cmp", 2),
  ac_instr_info(16, "clr", "clr", 2),
  ac_instr_info(17, "and", "and", 2),
  ac_instr_info(18, "ora", "ora", 2),
  ac_instr_info(19, "eor", "eor", 2),
  ac_instr_info(20, "lda", "lda", 2),
  ac_instr_info(21, "sta", "sta", 2),
  ac_instr_info(22, "mov", "mov", 3),
  ac_instr_info(23, "beq", "beq", 2),
  ac_instr_info(24, "lsra", "lsra", 1),
  ac_instr_info(25, "lsla", "lsla", 1),
  ac_instr_info(26, "rola", "rola", 1),
  ac_instr_info(27, "rora", "rora", 1),
  ac_instr_info(28, "jmp", "jmp", 3)
};
