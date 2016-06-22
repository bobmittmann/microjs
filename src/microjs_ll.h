#ifndef __MICROJS_LL_H__
#define __MICROJS_LL_H__

#include <stdint.h>

/* Last symbol num:153  Num rules:100 */

#define T_EOF                    0
#define T_DOT                    1
#define T_COMMA                  2
#define T_SEMICOLON              3
#define T_COLON                  4
#define T_PLUS                   5
#define T_MINUS                  6
#define T_STAR                   7
#define T_SLASH                  8
#define T_PERCENT                9
#define T_AMPERSAND             10
#define T_BAR                   11
#define T_CARET                 12
#define T_TILDE                 13
#define T_EXCLAM                14
#define T_QUEST                 15
#define T_EQUALS                16
#define T_LESSTHEN              17
#define T_GREATTHEN             18
#define T_LBRACKET              19
#define T_RBRACKET              20
#define T_LPAREN                21
#define T_RPAREN                22
#define T_LBRACE                23
#define T_RBRACE                24
#define T_GTE                   25
#define T_LTE                   26
#define T_EQU                   27
#define T_NEQ                   28
#define T_ASR                   29
#define T_SHL                   30
#define T_LOGICOR               31
#define T_LOGICAND              32
#define T_CATCH                 33
#define T_ELSE                  34
#define T_FALSE                 35
#define T_FOR                   36
#define T_IF                    37
#define T_THROW                 38
#define T_TRUE                  39
#define T_TRY                   40
#define T_VAR                   41
#define T_WHILE                 42
#define T_ID                    43
#define T_INT                   44
#define T_CHAR                  45
#define T_STRING                46
#define T_ERR                   47
#define T_NOT                   48

#define NONTERM_BASE            49
#define N_PROGRAM               49
#define N_STAT                  50
#define N_SEMI_STAT             51
#define N_SEMI_LIST             52
#define N_COMPOUND_STAT         53
#define N_VAR_LIST              54
#define N_VAR                   55
#define N_VAR_LIST1             56
#define N_VAR_INIT_OPT          57
#define N_EXP                   58
#define N_ASSIGN_OR_CALL1       59
#define N_FUNCTION_CALL         60
#define N_ATTR_ASSIGN           61
#define N_ATTR_ASSIGN2          62
#define N_METHOD_CALL           63
#define N_ARG_LIST_OPT          64
#define N_ARG_LIST              65
#define N_ARG_LIST1             66
#define N_EXP_LST_OPT           67
#define N_EXP_LST               68
#define N_EXP_LST1              69
#define N_AND_EXP               70
#define N_OR_EXP                71
#define N_RELATIONAL_EXP        72
#define N_AND_EXP1              73
#define N_SHIFT_EXP             74
#define N_RELATIONAL_EXP1       75
#define N_ADDITIVE_EXP          76
#define N_SHIFT_EXP1            77
#define N_DIV_EXP               78
#define N_ADDITIVE_EXP1         79
#define N_MULT_EXP              80
#define N_DIV_EXP1              81
#define N_UNARY_EXP             82
#define N_MULT_EXP1             83
#define N_PRIMARY_EXP           84
#define N_ID_EVAL               85
#define N_ID_EVAL1              86
#define N_ATTR_EVAL             87
#define N_ATTR_EVAL1            88
#define N_STAT_LIST             89
#define N_CONDITION             90
#define N_ELSE_OPT              91
#define N_CATCH_OPT             92

#define ACTION_BASE             93
#define A_OP_VAR_DECL           93
#define A_OP_PUSH_TMP           94
#define A_OP_POP_TMP            95
#define A_OP_VAR_INIT           96
#define A_OP_VAR_ASSIGN         97
#define A_OP_RET_DISCARD        98
#define A_OP_ARRAY_XLAT         99
#define A_OP_OBJECT_GET        100
#define A_OP_ATTR_ASSIGN       101
#define A_OP_ARRAY_ASSIGN      102
#define A_OP_METHOD_LOOKUP     103
#define A_OP_CALL              104
#define A_OP_FUNCTION_LOOKUP   105
#define A_OP_ARG               106
#define A_OP_OR                107
#define A_OP_LOGIC_OR          108
#define A_OP_XOR               109
#define A_OP_AND               110
#define A_OP_LOGIC_AND         111
#define A_OP_LT                112
#define A_OP_GT                113
#define A_OP_EQU               114
#define A_OP_NEQ               115
#define A_OP_GTE               116
#define A_OP_LTE               117
#define A_OP_SHL               118
#define A_OP_ASR               119
#define A_OP_ADD               120
#define A_OP_SUB               121
#define A_OP_DIV               122
#define A_OP_MOD               123
#define A_OP_MUL               124
#define A_OP_INV               125
#define A_OP_MINUS             126
#define A_OP_NOT               127
#define A_OP_PUSH_INT          128
#define A_OP_PUSH_STRING       129
#define A_OP_PUSH_TRUE         130
#define A_OP_PUSH_FALSE        131
#define A_OP_VAR_EVAL          132
#define A_OP_CALL_RET          133
#define A_OP_ATTR_EVAL         134
#define A_OP_ARRAY_EVAL        135
#define A_OP_BLK_OPEN          136
#define A_OP_BLK_CLOSE         137
#define A_OP_FOR_INIT          138
#define A_OP_FOR_COND          139
#define A_OP_FOR_AFTER         140
#define A_OP_FOR_END           141
#define A_OP_WHILE_BEGIN       142
#define A_OP_WHILE_COND        143
#define A_OP_WHILE_END         144
#define A_OP_IF_COND           145
#define A_OP_IF_END            146
#define A_OP_TRY_BEGIN         147
#define A_OP_THROW             148
#define A_OP_IF_ELSE           149
#define A_OP_TRY_END           150
#define A_OP_CATCH             151
#define A_OP_CATCH_END         152

#define IS_A_TERMINAL(_X) ((_X) < NONTERM_BASE)
#ifdef ACTION_BASE
#define IS_A_NONTERMINAL(_X) ((_X) >= NONTERM_BASE && (_X) < ACTION_BASE)
#define IS_AN_ACTION(_X) ((_X) >= ACTION_BASE)
#define ACTION(_X) ((_X) - ACTION_BASE)
#else
#define IS_A_NONTERMINAL(_X) ((_X) >= NONTERM_BASE)
#define IS_AN_ACTION(_X) (0)
#define ACTION(_X) (0)
#endif

extern const const char * const microjs_ll_sym[];

#ifdef __cplusplus
extern "C" {
#endif

int microjs_ll_push(uint8_t * sp, unsigned int sym, unsigned int tok);
int microjs_ll_start(uint8_t * sp);

#ifdef __cplusplus
}
#endif

#endif /* __MICROJS_LL_H__ */


