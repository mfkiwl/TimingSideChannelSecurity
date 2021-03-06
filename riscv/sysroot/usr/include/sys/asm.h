/* copyright (c) 1997, 1998, 2002, 2003, 2004, 2005
   Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Ralf Baechle <ralf@gnu.org>.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, write to the Free
   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
   02111-1307 USA.  */

#ifndef _SYS_ASM_H
#define _SYS_ASM_H

/* 
 * Macros to handle different pointer/register sizes for 32/64-bit code
 */
#ifdef __riscv64
# define PTR .dword
# define PTRLOG 3
# define SZREG	8
# define REG_S sd
# define REG_L ld
#else
# define PTR .word
# define PTRLOG 2
# define SZREG	4
# define REG_S sw
# define REG_L lw
#endif

#ifdef __riscv_flen
/* For ABI uniformity, reserve 8 bytes for floats, even if double-precision
   floating-point is not supported in hardware.  */
# define SZFREG 8
# if __riscv_flen == 32
#  define FREG_L flw
#  define FREG_S fsw
# elif __riscv_flen == 64
#  define FREG_L fld
#  define FREG_S fsd
# else
#  error unsupported FLEN
# endif
#endif

/*
 * LEAF - declare leaf routine
 */
#define	LEAF(symbol)				\
		.globl	symbol;			\
		.align	2;			\
		.type	symbol,@function;	\
symbol:						\
		cfi_startproc;

/*
 * NESTED - declare nested routine entry point
 */
#define	NESTED(symbol, framesize, rpc) LEAF(symbol)

/*
 * END - mark end of function
 */
#undef END
#define END(function)				\
		cfi_endproc;			\
		.size	function,.-function

/*
 * Stack alignment
 */
#define ALMASK	~15

#endif /* sys/asm.h */
