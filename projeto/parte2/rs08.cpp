/******************************************************
 * Processor Module Implementation File.              *
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
 

#include  "rs08.H"

void rs08::behavior() {

  unsigned ins_id;
  cache_item_t* ins_cache;
  if (has_delayed_load) {
    APP_MEM->load(delayed_load_program);
    has_delayed_load = false;
  }

  for (;;) {

  if( bhv_pc >= dec_cache_size){
    cerr << "ArchC: Address out of bounds (pc=0x" << hex << bhv_pc << ")." << endl;
    stop();
    return;
  }
  else {
    if( start_up ){
      decode_pc = ac_start_addr;
      start_up=0;
      init_dec_cache();
    }
    else{ 
      decode_pc = bhv_pc;
    }
 
      ins_cache = (DEC_CACHE+decode_pc);
      if ( !ins_cache->valid ){
        quant = 0;
        ins_cache->instr_p = new ac_instr<rs08_parms::AC_DEC_FIELD_NUMBER>((ISA.decoder)->Decode(reinterpret_cast<unsigned char*>(buffer), quant));
        ins_cache->valid = 1;
      }
      instr_vec = ins_cache->instr_p;
      ins_id = instr_vec->get(IDENT);

      if( ins_id == 0 ) {
        cerr << "ArchC Error: Unidentified instruction. " << endl;
        cerr << "PC = " << hex << decode_pc << dec << endl;
        stop();
        return;
      }

    ac_pc = decode_pc;

    ISA.cur_instr_id = ins_id;
    if (!ac_annul_sig) ISA._behavior_instruction(instr_vec->get(1));
    switch (ins_id) {
    case 1: // Instruction adci
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_adci(instr_vec->get(1), instr_vec->get(2));
      break;
    case 2: // Instruction andi
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_andi(instr_vec->get(1), instr_vec->get(2));
      break;
    case 3: // Instruction cmpi
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_cmpi(instr_vec->get(1), instr_vec->get(2));
      break;
    case 4: // Instruction eori
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_eori(instr_vec->get(1), instr_vec->get(2));
      break;
    case 5: // Instruction ldai
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_ldai(instr_vec->get(1), instr_vec->get(2));
      break;
    case 6: // Instruction orai
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_orai(instr_vec->get(1), instr_vec->get(2));
      break;
    case 7: // Instruction subi
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_subi(instr_vec->get(1), instr_vec->get(2));
      break;
    case 8: // Instruction movi
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMD(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3));
      if (!ac_annul_sig) ISA.behavior_movi(instr_vec->get(1), instr_vec->get(2), instr_vec->get(3));
      break;
    case 9: // Instruction addi
      if (!ac_annul_sig) ISA._behavior_rs08_Type_IMM_DIR(instr_vec->get(1), instr_vec->get(2));
      if (!ac_annul_sig) ISA.behavior_addi(instr_vec->get(1), instr_vec->get(2));
      break;
    case 10: // Instruction add
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_add(instr_vec->get(1), instr_vec->get(4));
      break;
    case 11: // Instruction adc
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_adc(instr_vec->get(1), instr_vec->get(4));
      break;
    case 12: // Instruction sub
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_sub(instr_vec->get(1), instr_vec->get(4));
      break;
    case 13: // Instruction inc
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_inc(instr_vec->get(1), instr_vec->get(4));
      break;
    case 14: // Instruction dec
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_dec(instr_vec->get(1), instr_vec->get(4));
      break;
    case 15: // Instruction cmp
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_cmp(instr_vec->get(1), instr_vec->get(4));
      break;
    case 16: // Instruction clr
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_clr(instr_vec->get(1), instr_vec->get(4));
      break;
    case 17: // Instruction and
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_and(instr_vec->get(1), instr_vec->get(4));
      break;
    case 18: // Instruction ora
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_ora(instr_vec->get(1), instr_vec->get(4));
      break;
    case 19: // Instruction eor
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_eor(instr_vec->get(1), instr_vec->get(4));
      break;
    case 20: // Instruction lda
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_lda(instr_vec->get(1), instr_vec->get(4));
      break;
    case 21: // Instruction sta
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DIR(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_sta(instr_vec->get(1), instr_vec->get(4));
      break;
    case 22: // Instruction mov
      if (!ac_annul_sig) ISA._behavior_rs08_Type_DD(instr_vec->get(1), instr_vec->get(2), instr_vec->get(5));
      if (!ac_annul_sig) ISA.behavior_mov(instr_vec->get(1), instr_vec->get(2), instr_vec->get(5));
      break;
    case 23: // Instruction beq
      if (!ac_annul_sig) ISA._behavior_rs08_Type_REL(instr_vec->get(1), instr_vec->get(4));
      if (!ac_annul_sig) ISA.behavior_beq(instr_vec->get(1), instr_vec->get(4));
      break;
    case 24: // Instruction lsra
      if (!ac_annul_sig) ISA._behavior_rs08_Type_INH(instr_vec->get(1));
      if (!ac_annul_sig) ISA.behavior_lsra(instr_vec->get(1));
      break;
    case 25: // Instruction lsla
      if (!ac_annul_sig) ISA._behavior_rs08_Type_INH(instr_vec->get(1));
      if (!ac_annul_sig) ISA.behavior_lsla(instr_vec->get(1));
      break;
    case 26: // Instruction rola
      if (!ac_annul_sig) ISA._behavior_rs08_Type_INH(instr_vec->get(1));
      if (!ac_annul_sig) ISA.behavior_rola(instr_vec->get(1));
      break;
    case 27: // Instruction rora
      if (!ac_annul_sig) ISA._behavior_rs08_Type_INH(instr_vec->get(1));
      if (!ac_annul_sig) ISA.behavior_rora(instr_vec->get(1));
      break;
    case 28: // Instruction jmp
      if (!ac_annul_sig) ISA._behavior_rs08_Type_EXT(instr_vec->get(1), instr_vec->get(6));
      if (!ac_annul_sig) ISA.behavior_jmp(instr_vec->get(1), instr_vec->get(6));
      break;
    } // switch (ins_id)
    if ((!ac_wait_sig) && (!ac_annul_sig)) ac_instr_counter+=1;
    ac_annul_sig = 0;
  }
//!Updating Regs for behavioral simulation.
  if(!ac_wait_sig){
    bhv_pc = ac_pc;
  }
  if (ac_stop_flag) {
    return;
  }
  else {
    if (instr_in_batch < instr_batch_size) {
      instr_in_batch++;
    }
    else {
      instr_in_batch = 0;
      wait(1, SC_NS);
    }
  }

} // for (;;)
} // behavior()

 
#include <ac_sighandlers.H>

void rs08::init() {
  set_args(ac_argc, ac_argv);
#ifdef AC_VERIFY
  set_queue(av[0]);
#endif

  ISA._behavior_begin();
  cerr << "ArchC: -------------------- Starting Simulation --------------------" << endl;
  InitStat();

  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  signal(SIGSEGV, sigsegv_handler);
  signal(SIGUSR1, sigusr1_handler);
#ifdef USE_GDB
  signal(SIGUSR2, sigusr2_handler);
#endif
#ifndef AC_COMPSIM
  set_running();
#else
  ac_pc = 0;
  void Execute(int argc, char *argv[]);
  Execute(argc, argv);
#endif
}

void rs08::init(int ac, char *av[]) {
  extern char* appfilename;
  ac_init_opt( ac, av);
  ac_init_app( ac, av);
  APP_MEM->load(appfilename);
  set_args(ac_argc, ac_argv);
#ifdef AC_VERIFY
  set_queue(av[0]);
#endif

  ISA._behavior_begin();
  cerr << "ArchC: -------------------- Starting Simulation --------------------" << endl;
  InitStat();

  signal(SIGINT, sigint_handler);
  signal(SIGTERM, sigint_handler);
  signal(SIGSEGV, sigsegv_handler);
  signal(SIGUSR1, sigusr1_handler);
#ifdef USE_GDB
  signal(SIGUSR2, sigusr2_handler);
#endif
#ifndef AC_COMPSIM
  set_running();
#else
  ac_pc = 0;
  void Execute(int argc, char *argv[]);
  Execute(argc, argv);
#endif
}

//Stop simulation (may receive exit status)
void rs08::stop(int status) {
  cerr << "ArchC: -------------------- Simulation Finished --------------------" << endl;
  ISA._behavior_end();
  ac_stop_flag = 1;
  ac_exit_status = status;
#ifndef AC_COMPSIM
  set_stopped();
#endif
}

void rs08::load(char* program) {
  APP_MEM->load(program);
}

void rs08::delayed_load(char* program) {
  has_delayed_load = true;
  delayed_load_program = new char[strlen(program)];
  strcpy(delayed_load_program, program);
}

// Returns ac_pc value
unsigned rs08::get_ac_pc() {
  return ac_pc;
}

// Assigns value to ac_pc
void rs08::set_ac_pc(unsigned int value) {
  ac_pc = value;
}

// Wrapper function to PrintStat().
void rs08::PrintStat() {
  ac_arch<rs08_parms::ac_word, rs08_parms::ac_Hword>::PrintStat();
}
