#ifndef INC_PARSER_H
#define INC_PARSER_H

#ifdef USE_LEX
	extern char *yytext;
	int yylex();
	#define getToken  yylex
	#define lexeme  yytext
#else
	int getToken();
	extern char *lexeme;
#endif


extern int lookahead;

#define EOF  256
#define DOT  257
#define COMMA  258
#define SEMICOLON  259
#define COLON  260
#define PLUS  261
#define MINUS  262
#define STAR  263
#define SLASH  264
#define PERCENT  265
#define AMPERSAND  266
#define BAR  267
#define CARET  268
#define TILDE  269
#define EXCLAM  270
#define QUEST  271
#define EQUALS  272
#define LESSTHEN  273
#define GREATTHEN  274
#define LBRACKET  275
#define RBRACKET  276
#define LPAREN  277
#define RPAREN  278
#define LBRACE  279
#define RBRACE  280
#define GTE  281
#define LTE  282
#define EQU  283
#define NEQ  284
#define ASR  285
#define SHL  286
#define LOGICOR  287
#define LOGICAND  288
#define CATCH  289
#define ELSE  290
#define FALSE  291
#define FOR  292
#define IF  293
#define THROW  294
#define TRUE  295
#define TRY  296
#define VAR  297
#define WHILE  298
#define ID  299
#define INT  300
#define CHAR  301
#define STRING  302
#define ERR  303
#define NOT  304

void program();
void stat();
void semi_stat();
void semi_list();
void compound_stat();
void var_list();
void var();
void var_list1();
void var_init_opt();
void exp();
void assign_or_call1();
void function_call();
void attr_assign();
void attr_assign2();
void method_call();
void arg_list_opt();
void arg_list();
void arg_list1();
void exp_lst_opt();
void exp_lst();
void exp_lst1();
void and_exp();
void or_exp();
void relational_exp();
void and_exp1();
void shift_exp();
void relational_exp1();
void additive_exp();
void shift_exp1();
void div_exp();
void additive_exp1();
void mult_exp();
void div_exp1();
void unary_exp();
void mult_exp1();
void primary_exp();
void id_eval();
void id_eval1();
void attr_eval();
void attr_eval1();
void stat_list();
void condition();
void else_opt();
void catch_opt();

#endif
