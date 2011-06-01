/**
 * @file      mips1_syscall.cpp
 * @author    Sandro Rigo
 *            Marcus Bartholomeu
 *
 *            The ArchC Team
 *            http://www.archc.org/
 *
 *            Computer Systems Laboratory (LSC)
 *            IC-UNICAMP
 *            http://www.lsc.ic.unicamp.br/
 *
 * @version   1.0
 * @date      Mon, 19 Jun 2006 15:50:52 -0300
 * 
 * @brief     The ArchC MIPS-I functional model.
 * 
 * @attention Copyright (C) 2002-2006 --- The ArchC Team
 * 
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "rs08_syscall.H"

// 'using namespace' statement to allow access to all
// mips1-specific datatypes
using namespace rs08_parms;

void rs08_syscall::get_buffer(int argn, unsigned char* buf, unsigned int size)
{
}

void rs08_syscall::set_buffer(int argn, unsigned char* buf, unsigned int size)
{
}

void rs08_syscall::set_buffer_noinvert(int argn, unsigned char* buf, unsigned int size)
{

}

int rs08_syscall::get_int(int argn)
{
  return  A; 
}

void rs08_syscall::set_int(int argn, int val)
{
  A= val;
}

void rs08_syscall::return_from_syscall()
{
  //npc = ac_pc + 4;
}

void rs08_syscall::set_prog_args(int argc, char **argv)
{
}
