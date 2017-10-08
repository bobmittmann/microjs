/* 
 * Copyright(C) 2014 Robinson Mittmann. All Rights Reserved.
 * 
 * This file is part of the MicroJs
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You can receive a copy of the GNU Lesser General Public License from 
 * http://www.gnu.org/
 */

/** 
 * @file microjs_dasm.c
 * @brief MicroJS Virtual Machine
 * @author Robinson Mittmann <bobmittmann@gmail.com>
 */



#define __MICROJS_I__
#include "microjs-i.h"

#include <sys/dcclog.h>

/* --------------------------------------------------------------------------
   Virtual machine
   -------------------------------------------------------------------------- */

#define SIGNEXT4BIT(_X) ({ struct { int32_t x: 4; } s; \
						  s.x = (_X); (int32_t)s.x; })

#define SIGNEXT12BIT(_X) ({ struct { int32_t x: 12; } s; \
						  s.x = (_X); (int32_t)s.x; })

#define SIZEOF_WORD ((int)sizeof(int32_t))

int microjs_dasm(FILE * f, struct microjs_vm * vm, uint8_t code[], 
				 unsigned int len)
{
	/* PC: program counter */
	uint8_t * pc = code + vm->pc;
	uint8_t * end = pc + len;

	if (f  == NULL)
		return ERR_NULL_POINTER;

	if (vm  == NULL)
		return ERR_NULL_POINTER;

	if (code == NULL)
		return ERR_NULL_POINTER;

	while (pc < end) {
		unsigned int opc;
		unsigned int opt;
		int32_t r0;
		int32_t r1;

		/* fetch */
		fprintf(f, "%04x\t", (int)(pc - code));
		opc = *pc++;
		opt = opc & 0xf;
		opc >>= 4;

		switch (opc) {

		/* get the absolute call address */
		case (OPC_CALL >> 4):
			r0 = (*pc++ << 4) + opt;
			fprintf(f, "CALL 0x%04x (offs=%d)\n", (int)(pc - code) + r0, r0);
			break;

			/* get the relative address */
		case (OPC_JMP >> 4):
			r0 = SIGNEXT12BIT((*pc++ << 4) + opt);
			fprintf(f, "JMP 0x%04x (offs=%d)\n", (int)(pc - code) + r0, r0);
			break;

		case (OPC_JEQ >> 4): /* coniditional JMP */
			r0 = SIGNEXT12BIT((*pc++ << 4) + opt);
			fprintf(f, "JEQ 0x%04x (off=%d)\n", (int)(pc - code) + r0, r0);
			break;

		case (OPC_ISP >> 4):
			r0 = SIGNEXT12BIT((*pc++ << 4) + opt);
			fprintf(f, "ISP %d\n", r0 * SIZEOF_WORD);
			break;

		case (OPC_PUSHX >> 4):
			/* get the exception absolute jump address */
			r0 = (*pc++ << 4) + opt;
			fprintf(f, "PUSHX\n");
			break;

		case (OPC_LD >> 4):
			r1 = (*pc++ << 4) + opt;
			fprintf(f, "LD [0x%04x]\n", r1 * SIZEOF_WORD);
			break;

		case (OPC_ST >> 4):
			r1 = (*pc++ << 4) + opt;
			fprintf(f, "ST [0x%04x]\n", r1 * SIZEOF_WORD);
			break;

		case (OPC_SLD >> 4): /* Stack load */
			r1 = (*pc++ << 4) + opt;
			fprintf(f, "SLD SP[%04x]\n", r1 * SIZEOF_WORD);
			break;

		case (OPC_SST >> 4): /* Stack store */
			r1 = (*pc++ << 4) + opt;
			fprintf(f, "SST SP[%04x]\n", r1 * SIZEOF_WORD);
			break;

		case (OPC_I4 >> 4): 
			r0 = SIGNEXT4BIT(opt);
			fprintf(f, "I4 %d\n", r0);
			break;

		case (INTOP >> 4):
			switch (opt) {
			case OPC_LT - INTOP:
				fprintf(f, "LT\n");
				break;

			case OPC_GT - INTOP:
				fprintf(f, "GT\n");
				break;

			case OPC_EQ - INTOP:
				fprintf(f, "EQ\n");
				break;

			case OPC_NE - INTOP:
				fprintf(f, "NE\n");
				break;

			case OPC_LE - INTOP:
				fprintf(f, "LE\n");
				break;

			case OPC_GE - INTOP:
				fprintf(f, "GE\n");
				break;

			case OPC_ASR - INTOP:
				fprintf(f, "ASR\n");
				break;

			case OPC_SHL - INTOP:
				fprintf(f, "SHL\n");
				break;

			case OPC_ADD - INTOP:
				fprintf(f, "ADD\n");
				break;

			case OPC_SUB - INTOP:
				fprintf(f, "SUB\n");
				break;

			case OPC_MUL - INTOP:
				fprintf(f, "MUL\n");
				break;

			case OPC_DIV - INTOP:
				fprintf(f, "DIV\n");
				break;

			case OPC_MOD - INTOP:
				fprintf(f, "MOD\n");
				break;

			case OPC_OR - INTOP:
				fprintf(f, "OR\n");
				break;

			case OPC_AND - INTOP:
				fprintf(f, "AND\n");
				break;

			case OPC_XOR - INTOP:
				fprintf(f, "XOR\n");
				break;
			}
			break;

		case (MISCOP >> 4):
			switch (opt) {

			case OPC_INV:
				fprintf(f, "INV\n");
				break;

			case OPC_NEG:
				fprintf(f, "NEG\n");
				break;

			case OPC_NOT:
				fprintf(f, "NOT\n");
				break;

			case OPC_INC:
				fprintf(f, "INC\n");
				break;
				
			case OPC_DEC:
				fprintf(f, "DEC\n");
				break;

			case OPC_POP:
				fprintf(f, "POP\n");
				break;

			case OPC_I32:
				r0 = (int32_t)(pc[0] | pc[1] << 8 | 
							   pc[2] << 16 | pc[3] << 24);
				pc += 4;
				fprintf(f, "I32 %d\n", r0);
				break;

			case OPC_I16:
				r0 = (int16_t)(pc[0] | pc[1] << 8);
				pc += 2;
				fprintf(f, "I16 %d;\n", r0);
				break;

			case OPC_I8:
				r0 = (int8_t)*pc++;
				fprintf(f, "I8 %d\n", r0);
				break;

			case OPC_EXT:
				r0 = *pc++;
				r1 = *pc++;
				fprintf(f, "EXT %d, %d\n", r0, r1);
				break;


			case OPC_XPT: 
				fprintf(f, "XPT\n");
				break;

			case OPC_UNLK:
				fprintf(f, "UNLK\n");
				break;

			case OPC_RET:
				fprintf(f, "RET\n");
				break;

			case OPC_ABT:
				fprintf(f, "ABT\n");
				break;

			default:
				fprintf(f, "Invalid instruction, MISC(%d)", opt);
				break;
			}
			break;

		default:
			fprintf(f, "Invalid instruction, %d", opc);
			break;
		}
	} 

	return 0;
}

