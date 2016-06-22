
/***********  LL(1) Parser  ************/

#include <stdio.h>

#include "microjs_par.h"


int lookahead;

void SyntaxError(int code) 
{
	printf("Error:%d\n",code);
	exit(1); 
}

void match(int t) 
{
	 if(lookahead == t) lookahead = getToken();
	 else SyntaxError(-1);
}

void program() 
{
	switch (lookahead) {
	case EOF: 
		match(EOF); 
		break;

	case FOR: case IF: case TRY: case WHILE: 
		stat(); 
		program(); 
		break;

	case THROW: case VAR: case ID: 
		semi_stat(); 
		semi_list(); 
		break;

	case LBRACE: 
		compound_stat(); 
		program(); 
		break;

	default:
		Error(0);
	}
} /* end of program*/

void stat() 
{
	switch (lookahead) {
	case FOR: 
		match(FOR); 
		match(LPAREN); 
		exp_lst_opt(); 
		match(SEMICOLON); 
		exp(); 
		match(SEMICOLON); 
		exp_lst_opt(); 
		match(RPAREN); 
		compound_stat(); 
		break;

	case WHILE: 
		match(WHILE); 
		condition(); 
		compound_stat(); 
		break;

	case IF: 
		match(IF); 
		condition(); 
		compound_stat(); 
		else_opt(); 
		break;

	case TRY: 
		match(TRY); 
		compound_stat(); 
		catch_opt(); 
		break;

	default:
		Error(1);
	}
} /* end of stat*/

void semi_stat() 
{
	switch (lookahead) {
	case THROW: 
		match(THROW); 
		exp(); 
		break;

	case VAR: 
		match(VAR); 
		var_list(); 
		break;

	case ID: 
		match(ID); 
		assign_or_call1(); 
		break;

	default:
		Error(2);
	}
} /* end of semi_stat*/

void semi_list() 
{
	switch (lookahead) {
	case EOF: 
		match(EOF); 
		break;

	case SEMICOLON: 
		match(SEMICOLON); 
		program(); 
		break;

	default:
		Error(3);
	}
} /* end of semi_list*/

void compound_stat() 
{
	switch (lookahead) {
	case LBRACE: 
		match(LBRACE); 
		stat_list(); 
		match(RBRACE); 
		break;

	default:
		Error(4);
	}
} /* end of compound_stat*/

void var_list() 
{
	switch (lookahead) {
	case ID: 
		var(); 
		var_list1(); 
		break;

	default:
		Error(5);
	}
} /* end of var_list*/

void var() 
{
	switch (lookahead) {
	case ID: 
		match(ID); 
		var_init_opt(); 
		break;

	default:
		Error(6);
	}
} /* end of var*/

void var_list1() 
{
	switch (lookahead) {
	case EOF: case SEMICOLON: 
		break;

	case COMMA: 
		match(COMMA); 
		var_list(); 
		break;

	default:
		Error(7);
	}
} /* end of var_list1*/

void var_init_opt() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: 
		break;

	case EQUALS: 
		match(EQUALS); 
		exp(); 
		break;

	default:
		Error(8);
	}
} /* end of var_init_opt*/

void exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		and_exp(); 
		or_exp(); 
		break;

	default:
		Error(9);
	}
} /* end of exp*/

void assign_or_call1() 
{
	switch (lookahead) {
	case EQUALS: 
		match(EQUALS); 
		exp(); 
		break;

	case LPAREN: 
		function_call(); 
		break;

	case LBRACKET: 
		match(LBRACKET); 
		exp(); 
		match(RBRACKET); 
		match(DOT); 
		attr_assign(); 
		break;

	case DOT: 
		match(DOT); 
		attr_assign(); 
		break;

	default:
		Error(10);
	}
} /* end of assign_or_call1*/

void function_call() 
{
	switch (lookahead) {
	case LPAREN: 
		match(LPAREN); 
		arg_list_opt(); 
		match(RPAREN); 
		break;

	default:
		Error(11);
	}
} /* end of function_call*/

void attr_assign() 
{
	switch (lookahead) {
	case ID: 
		match(ID); 
		attr_assign2(); 
		break;

	default:
		Error(12);
	}
} /* end of attr_assign*/

void attr_assign2() 
{
	switch (lookahead) {
	case EQUALS: 
		match(EQUALS); 
		exp(); 
		break;

	case LBRACKET: 
		match(LBRACKET); 
		exp(); 
		match(RBRACKET); 
		match(EQUALS); 
		exp(); 
		break;

	case LPAREN: 
		method_call(); 
		break;

	default:
		Error(13);
	}
} /* end of attr_assign2*/

void method_call() 
{
	switch (lookahead) {
	case LPAREN: 
		match(LPAREN); 
		arg_list_opt(); 
		match(RPAREN); 
		break;

	default:
		Error(14);
	}
} /* end of method_call*/

void arg_list_opt() 
{
	switch (lookahead) {
	case RPAREN: 
		break;

	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		arg_list(); 
		break;

	default:
		Error(15);
	}
} /* end of arg_list_opt*/

void arg_list() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		exp(); 
		arg_list1(); 
		break;

	default:
		Error(16);
	}
} /* end of arg_list*/

void arg_list1() 
{
	switch (lookahead) {
	case RPAREN: 
		break;

	case COMMA: 
		match(COMMA); 
		arg_list(); 
		break;

	default:
		Error(17);
	}
} /* end of arg_list1*/

void exp_lst_opt() 
{
	switch (lookahead) {
	case SEMICOLON: case RPAREN: 
		break;

	case ID: 
		exp_lst(); 
		break;

	default:
		Error(18);
	}
} /* end of exp_lst_opt*/

void exp_lst() 
{
	switch (lookahead) {
	case ID: 
		match(ID); 
		assign_or_call1(); 
		exp_lst1(); 
		break;

	default:
		Error(19);
	}
} /* end of exp_lst*/

void exp_lst1() 
{
	switch (lookahead) {
	case SEMICOLON: case RPAREN: 
		break;

	case COMMA: 
		match(COMMA); 
		exp_lst(); 
		break;

	default:
		Error(20);
	}
} /* end of exp_lst1*/

void and_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		relational_exp(); 
		and_exp1(); 
		break;

	default:
		Error(21);
	}
} /* end of and_exp*/

void or_exp() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case RBRACKET: case RPAREN: 
		break;

	case BAR: 
		match(BAR); 
		exp(); 
		break;

	case LOGICOR: 
		match(LOGICOR); 
		exp(); 
		break;

	case CARET: 
		match(CARET); 
		exp(); 
		break;

	default:
		Error(22);
	}
} /* end of or_exp*/

void relational_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		shift_exp(); 
		relational_exp1(); 
		break;

	default:
		Error(23);
	}
} /* end of relational_exp*/

void and_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case BAR: case CARET: case RBRACKET: case RPAREN: case LOGICOR: 
		break;

	case AMPERSAND: 
		match(AMPERSAND); 
		and_exp(); 
		break;

	case LOGICAND: 
		match(LOGICAND); 
		and_exp(); 
		break;

	default:
		Error(24);
	}
} /* end of and_exp1*/

void shift_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		additive_exp(); 
		shift_exp1(); 
		break;

	default:
		Error(25);
	}
} /* end of shift_exp*/

void relational_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case AMPERSAND: case BAR: case CARET: case RBRACKET: case RPAREN: case LOGICOR: case LOGICAND: 
		break;

	case LESSTHEN: 
		match(LESSTHEN); 
		relational_exp(); 
		break;

	case GREATTHEN: 
		match(GREATTHEN); 
		relational_exp(); 
		break;

	case EQU: 
		match(EQU); 
		relational_exp(); 
		break;

	case NEQ: 
		match(NEQ); 
		relational_exp(); 
		break;

	case GTE: 
		match(GTE); 
		relational_exp(); 
		break;

	case LTE: 
		match(LTE); 
		relational_exp(); 
		break;

	default:
		Error(26);
	}
} /* end of relational_exp1*/

void additive_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		div_exp(); 
		additive_exp1(); 
		break;

	default:
		Error(27);
	}
} /* end of additive_exp*/

void shift_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case LOGICOR: case LOGICAND: 
		break;

	case SHL: 
		match(SHL); 
		shift_exp(); 
		break;

	case ASR: 
		match(ASR); 
		shift_exp(); 
		break;

	default:
		Error(28);
	}
} /* end of shift_exp1*/

void div_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		mult_exp(); 
		div_exp1(); 
		break;

	default:
		Error(29);
	}
} /* end of div_exp*/

void additive_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case ASR: case SHL: case LOGICOR: case LOGICAND: 
		break;

	case PLUS: 
		match(PLUS); 
		additive_exp(); 
		break;

	case MINUS: 
		match(MINUS); 
		additive_exp(); 
		break;

	default:
		Error(30);
	}
} /* end of additive_exp1*/

void mult_exp() 
{
	switch (lookahead) {
	case MINUS: case TILDE: case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: case NOT: 
		unary_exp(); 
		mult_exp1(); 
		break;

	default:
		Error(31);
	}
} /* end of mult_exp*/

void div_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case PLUS: case MINUS: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case ASR: case SHL: case LOGICOR: case LOGICAND: 
		break;

	case SLASH: 
		match(SLASH); 
		div_exp(); 
		break;

	case PERCENT: 
		match(PERCENT); 
		div_exp(); 
		break;

	default:
		Error(32);
	}
} /* end of div_exp1*/

void unary_exp() 
{
	switch (lookahead) {
	case LPAREN: case FALSE: case TRUE: case ID: case INT: case CHAR: case STRING: 
		primary_exp(); 
		break;

	case TILDE: 
		match(TILDE); 
		unary_exp(); 
		break;

	case MINUS: 
		match(MINUS); 
		unary_exp(); 
		break;

	case NOT: 
		match(NOT); 
		unary_exp(); 
		break;

	default:
		Error(33);
	}
} /* end of unary_exp*/

void mult_exp1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case PLUS: case MINUS: case SLASH: case PERCENT: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case ASR: case SHL: case LOGICOR: case LOGICAND: 
		break;

	case STAR: 
		match(STAR); 
		mult_exp(); 
		break;

	default:
		Error(34);
	}
} /* end of mult_exp1*/

void primary_exp() 
{
	switch (lookahead) {
	case LPAREN: 
		match(LPAREN); 
		exp(); 
		match(RPAREN); 
		break;

	case INT: 
		match(INT); 
		break;

	case CHAR: 
		match(CHAR); 
		break;

	case STRING: 
		match(STRING); 
		break;

	case TRUE: 
		match(TRUE); 
		break;

	case FALSE: 
		match(FALSE); 
		break;

	case ID: 
		id_eval(); 
		break;

	default:
		Error(35);
	}
} /* end of primary_exp*/

void id_eval() 
{
	switch (lookahead) {
	case ID: 
		match(ID); 
		id_eval1(); 
		break;

	default:
		Error(36);
	}
} /* end of id_eval*/

void id_eval1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case PLUS: case MINUS: case STAR: case SLASH: case PERCENT: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case ASR: case SHL: case LOGICOR: case LOGICAND: 
		break;

	case LPAREN: 
		function_call(); 
		break;

	case LBRACKET: 
		match(LBRACKET); 
		exp(); 
		match(RBRACKET); 
		match(DOT); 
		attr_eval(); 
		break;

	case DOT: 
		match(DOT); 
		attr_eval(); 
		break;

	default:
		Error(37);
	}
} /* end of id_eval1*/

void attr_eval() 
{
	switch (lookahead) {
	case ID: 
		match(ID); 
		attr_eval1(); 
		break;

	default:
		Error(38);
	}
} /* end of attr_eval*/

void attr_eval1() 
{
	switch (lookahead) {
	case EOF: case COMMA: case SEMICOLON: case PLUS: case MINUS: case STAR: case SLASH: case PERCENT: case AMPERSAND: case BAR: case CARET: case LESSTHEN: case GREATTHEN: case RBRACKET: case RPAREN: case GTE: case LTE: case EQU: case NEQ: case ASR: case SHL: case LOGICOR: case LOGICAND: 
		break;

	case LPAREN: 
		method_call(); 
		break;

	case LBRACKET: 
		match(LBRACKET); 
		exp(); 
		match(RBRACKET); 
		break;

	default:
		Error(39);
	}
} /* end of attr_eval1*/

void stat_list() 
{
	switch (lookahead) {
	case RBRACE: 
		break;

	case FOR: case IF: case TRY: case WHILE: 
		stat(); 
		stat_list(); 
		break;

	case THROW: case VAR: case ID: 
		semi_stat(); 
		match(SEMICOLON); 
		stat_list(); 
		break;

	default:
		Error(40);
	}
} /* end of stat_list*/

void condition() 
{
	switch (lookahead) {
	case LPAREN: 
		match(LPAREN); 
		exp(); 
		match(RPAREN); 
		break;

	default:
		Error(41);
	}
} /* end of condition*/

void else_opt() 
{
	switch (lookahead) {
	case EOF: case LBRACE: case RBRACE: case FOR: case IF: case THROW: case TRY: case VAR: case WHILE: case ID: 
		break;

	case ELSE: 
		match(ELSE); 
		compound_stat(); 
		break;

	default:
		Error(42);
	}
} /* end of else_opt*/

void catch_opt() 
{
	switch (lookahead) {
	case EOF: case LBRACE: case RBRACE: case FOR: case IF: case THROW: case TRY: case VAR: case WHILE: case ID: 
		break;

	case CATCH: 
		match(CATCH); 
		match(LPAREN); 
		match(ID); 
		match(RPAREN); 
		match(LBRACE); 
		stat_list(); 
		match(RBRACE); 
		break;

	default:
		Error(43);
	}
} /* end of catch_opt*/

