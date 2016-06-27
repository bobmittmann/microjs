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
 * @file microjs_dbg.c
 * @brief Microjs debug functions
 * @author Robinson Mittmann <bobmittmann@gmail.com>
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define __MICROJS_I__
#include "microjs-i.h"

#if MICROJS_VERBOSE_ENABLED

static const char * const err_tab[] = {
	[OK] = "Ok", 
	[ERR_GENERAL] = "general fault",
	[ERR_UNEXPECED_EOF] = "unexpected end of file",
	[ERR_UNEXPECTED_CHAR] = "unexpected char",
	[ERR_UNEXPECTED_SYMBOL] = "unexpected symbol",
	[ERR_UNCLOSED_STRING] = "unclosed string",
	[ERR_UNCLOSED_COMMENT] = "unclosed comment",
	[ERR_INVALID_LITERAL] = "invalid literal",
	[ERR_INVALID_ID] = "invalid identifier",
	[ERR_STRINGS_UNSUPORTED] = "strings NOT suported",
	[ERR_STRING_TOO_LONG] = "string too long",
	[ERR_STRING_NOT_FOUND] = "string not found",
	[ERR_STRBUF_OVERFLOW] = "string buffer overflow",
	[ERR_SYNTAX_ERROR] = "syntax error",
	[ERR_DATA_OVERFLOW] = "target data overflow",
	[ERR_STACK_OVERFLOW] = "target stack overflow",
	[ERR_STACK_UNDERFLOW] = "target stack underflow",
	[ERR_VAR_UNKNOWN] = "unknown variable",
	[ERR_EXTERN_UNKNOWN] = "unknown external",
	[ERR_ARG_MISSING] = "argument missing",
	[ERR_TOO_MANY_ARGS] = "too many arguments",
	[ERR_SYM_PUSH_FAIL] = "symbol stack overflow",
	[ERR_SYM_POP_FAIL] = "symbol stack sequence fail",
	[ERR_OBJ_NEW_FAIL] = "symbol alloc fail",
	[ERR_SDT_STACK_OVERFLOW] = "compiler stack overflow",
	[ERR_GENERAL] = "general failure",
	[ERR_CODE_MEM_OVERFLOW] = "code memory overflow",
	[ERR_RET_COUNT_MISMATCH] = "function returns no value",
	[ERR_INVALID_INSTRUCTION] = "invalid VM instruction",
	[ERR_EXTERN_NOT_FUNCTION] = "extern is not a function",
	[ERR_EXTERN_NOT_ARRAY] = "not an array",
	[ERR_EXTERN_NOT_OBJECT] = "not an object",
	[ERR_EXTERN_NOT_INTEGER] = "not an integer type",
	[ERR_EXTERN_NOT_MEMBER] = "not a class member",
	[ERR_EXTERN_READONLY] = "attribute is read-only",
	[ERR_NOT_IMPLEMENTED] = "construct not implemented",
	[ERR_ATTR_NOT_ARRAY] = "attribute is not an array",
	[ERR_NULL_POINTER] = "null pointer",
	[ERR_NOT_FUNCTION] = "symbol is not a function",
	[ERR_NOT_VARIABLE] = "symbol is not a variable",
	[ERR_FUNCTION_UNKNOWN] = "unknown function",
	[ERR_OBJ_DEFINED] = "symbol already defined",
};

const char * microjs_strerr(int err)
{
	return err_tab[-err];
}

static void js_dump_line(FILE * f, int ln, char * lp)
{
	char * cp;
	int c;

	if (lp == NULL)
		return;

	fprintf(f, "%4d: ", ln);
	for (cp = lp; (c = *cp) != '\0'; ++cp) {
		if ((c == '\r') || (c == '\n'))
			break;
		fprintf(f, "%c", c);
	}
	fprintf(f, "\n");
}


void lexer_print_err(FILE * f, struct lexer * lex, int err)
{
	char * txt = (char *)lex->txt;
	unsigned int len = lex->len;
	char * lp[5];
	int ln;
	int c;
	int i;

	fprintf(f, "error %d: %s:\n", err, err_tab[err]);

	lp[4] = NULL;
	lp[3] = NULL;
	lp[2] = NULL;
	lp[1] = NULL;
	lp[0] = txt;
	ln = 1;
	for (i = 0; ((c = txt[i]) != '\0') && (i < len); ++i) {
		if (txt[i - 1] == '\n') {
			lp[4] = lp[3];
			lp[3] = lp[2];
			lp[2] = lp[1];
			lp[1] = lp[0];
			lp[0] = &txt[i];
			ln++;
		}
		if (i == lex->off) {
			js_dump_line(f, ln - 4, lp[4]);
			js_dump_line(f, ln - 3, lp[3]);
			js_dump_line(f, ln - 2, lp[2]);
			js_dump_line(f, ln - 1, lp[1]);
			js_dump_line(f, ln - 0, lp[0]);
			break;
		}
	}
}

#endif /* MICROJS_VERBOSE_ENABLED */


#if MICROJS_DEBUG_ENABLED

int dump_js(char * script, unsigned int len)
{
	int i;

	printf("\n");

	for (i = 0; i < len; ++i)
		printf("%c", script[i]);

	printf("\n");

	return 0;
}

void dump_src(const char * txt, unsigned int len)
{
	bool crlf = false;
	int ln;
	int c;
	int i;

	ln = 0;
	crlf = true;
	for (i = 0; ((c = txt[i]) != '\0') && (i < len); ++i) {
		if (crlf) {
			printf("%4d: ", ++ln);
			crlf = false;
		}
		if (c == '\r')
			continue;
		if (c == '\n')
			crlf = true;

		printf("%c", c);
	}

	printf("\n");
	fflush(stdout);
}

#define STRING_LEN_MAX 64

const char token_nm[][4] = {
	[T_EOF] = "EOF",
	[T_DOT] = ".",
	[T_COMMA] = ",",
	[T_SEMICOLON] = ";",
	[T_COLON] = ":",
	[T_LBRACKET] = "[",
	[T_RBRACKET] = "]",
	[T_LPAREN] = "(",
	[T_RPAREN] = ")",
	[T_LBRACE] = "{",
	[T_RBRACE] = "}",
	[T_ASR] = ">>",
	[T_SHL] = "<<",
	[T_LTE] = "<=",
	[T_LESSTHEN] = "<",
	[T_GTE] = ">=",
	[T_GREATTHEN] = ">",
	[T_EQU] = "==",
	[T_NEQ] = "!=",
	[T_PLUS] = "+",
	[T_MINUS] = "-",
	[T_STAR] = "*",
	[T_SLASH] = "/",
	[T_PERCENT] = "%",
	[T_BAR] = "|",
	[T_LOGICOR] = "||",
	[T_AMPERSAND] = "&",
	[T_LOGICAND] = "&&",
	[T_CARET] = "^",
	[T_EXCLAM] = "!",
	[T_TILDE] = "~",
	[T_QUEST] = "?",
	[T_EQUALS] = "=",
};

char * tok2str(struct token tok)
{
	static char buf[STRING_LEN_MAX + 3];
	unsigned int typ = tok.typ;

	if (typ == T_ERR) {
		sprintf(buf, "ERR: %s", err_tab[tok.qlf]);
	} else if (typ == T_ID) {
		unsigned int n = tok.qlf;
		memcpy(buf, tok.s, n);
		buf[n] = '\0';
	} else if (typ == T_INT) {
		sprintf(buf, "%d", tok.u32);
	} else
		sprintf(buf, "%s", token_nm[typ]);

	return buf;
}

int ll_stack_dump(FILE * f, uint8_t * sp, uint8_t * sl)
{
	while (sp < sl) {
		fprintf(f, "\t%s\n", microjs_ll_sym[*sp++]);
	};
	return 0;
}

void show_hex32(FILE * f, uint32_t  addr, const void * buf, int count)
{
	uint32_t base;
	uint8_t * p;
	uint32_t val;
	int i;
	int j;
	int n;
	int c;

	/* 32bits addr alignement */
	addr &= ~(sizeof(uint32_t) - 1);
	/* 16 bytes base alignment */
	base = addr & ~(16 - 1);

	if (base < addr) {
		j = (addr - base);
		n = count + j;
	} else {
		j = 0;
		n = count;
	}

	fprintf(f, "%08x: ", base);

	p = (uint8_t *)buf; 
	for (i = 0; i < n; i += sizeof(uint32_t)) {
		if (i < j) {
			fprintf(f, "________ ");
		} else {
			val = p[0] + (p[1] << 8) + (p[2] << 16) + (p[3] << 24);
			fprintf(f, "%08x ", val);
			p += sizeof(uint32_t);
		}
	}

	for (; i < 16; i += 4) {
		fprintf(f, "         ");
	}

	fprintf(f, ": ");

	p = (uint8_t *)buf; 
	for (i = 0; i < n; i++) {
		if (i == 8)
			fprintf(f, " ");

		if (i < j) {
			fprintf(f, ".");
		} else {
			c = *p++;
			fprintf(f, "%c", ((c < ' ') || (c > 126)) ? '.' : c);
		}
	}
	fprintf(f, "\n");
}

void show_hex8(FILE * f, uint32_t  addr, const void * buf, unsigned int count)
{
	uint32_t base;
	uint8_t * p;
	uint32_t val;
	int i;
	int j;
	int n;
	int c;

	/* 32bits addr alignement */
	addr &= ~(sizeof(uint32_t) - 1);
	/* 16 bytes base alignment */
	base = addr & ~(16 - 1);

	if (base < addr) {
		j = (addr - base);
		n = count + j;
	} else {
		j = 0;
		n = count;
	}

	fprintf(f, "%08x: ", base);

	p = (uint8_t *)buf; 
	for (i = 0; i < n; ++i) {
		if (i < j) {
			fprintf(f, "__");
		} else {
			val = p[0];
			fprintf(f, "%02x ", val);
			p++;
		}
	}

	for (; i < 16; ++i) {
		fprintf(f, "   ");
	}

	fprintf(f, ": ");

	p = (uint8_t *)buf; 
	for (i = 0; i < n; i++) {
		if (i == 8)
			fprintf(f, " ");

		if (i < j) {
			fprintf(f, ".");
		} else {
			c = *p++;
			fprintf(f, "%c", ((c < ' ') || (c > 126)) ? '.' : c);
		}
	}
	fprintf(f, "\n");
}

void xxd8(FILE * f, uint32_t addr, const void * ptr, unsigned int count)
{
	uint8_t * buf = (uint8_t *)ptr;
	unsigned int base;
	unsigned int n;

	n = count;
	addr &= ~(sizeof(uint32_t) - 1);
	base = addr & ~(16 - 1);
	if (base < addr) {
		n = (base + 16) - addr;
	} else {
		n = 16;
	}

	do {
		if (count < n)
			n = count;

		show_hex8(f, addr, buf, n);
		addr += n;
		buf += n;
		count -= n;
		n = 16;
	} while (count > 0);

}

void xxd32(FILE * f, uint32_t addr, const void * ptr, unsigned int count)
{
	uint8_t buf[16];
	unsigned int base;
	unsigned int n;

	n = (count + (sizeof(uint32_t) - 1)) & ~(sizeof(uint32_t) - 1);

	addr &= ~(sizeof(uint32_t) - 1);
	base = addr & ~(16 - 1);
	if (base < addr) {
		n = (base + 16) - addr;
	} else {
		n = 16;
	}

	do {
		if (count < n)
			n = count;

		memcpy(buf, (void *)ptr, n);

		show_hex32(f, addr, buf, n);
		addr += n;
		ptr += n;
		count -= n;
		n = 16;
	} while (count > 0);

}

#else

int ll_stack_dump(FILE * f, uint8_t * sp, uint8_t * sl)
{
	while (sp < sl) {
		fprintf(f, "\t%3d\n", *sp++);
	};
	return 0;
}

#endif /* MICROJS_DEBUG_ENABLED */

