#ifndef __MICROJS2_LL_H__
#define __MICROJS2_LL_H__

#include <stdint.h>

/* Last symbol num:164  Num rules:110 */

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
#define T_RETURN                49
#define T_FUNCTION              50

#define NONTERM_BASE            51
#define N_PROGRAM               51
#define N_STAT                  52
#define N_SEMI_STAT             53
#define N_SEMI_LIST             54
#define N_COMPOUND_STAT         55
#define N_FUNCTION_DEF          56
#define N_VAR_LIST              57
#define N_VAR                   58
#define N_VAR_LIST1             59
#define N_VAR_INIT_OPT          60
#define N_EXP                   61
#define N_ASSIGN_OR_CALL1       62
#define N_FUNCTION_CALL         63
#define N_ATTR_ASSIGN           64
#define N_ATTR_ASSIGN2          65
#define N_METHOD_CALL           66
#define N_ARG_LIST_OPT          67
#define N_ARG_LIST              68
#define N_ARG_LIST1             69
#define N_EXP_LST_OPT           70
#define N_EXP_LST               71
#define N_EXP_LST1              72
#define N_AND_EXP               73
#define N_OR_EXP                74
#define N_RELATIONAL_EXP        75
#define N_AND_EXP1              76
#define N_SHIFT_EXP             77
#define N_RELATIONAL_EXP1       78
#define N_ADDITIVE_EXP          79
#define N_SHIFT_EXP1            80
#define N_DIV_EXP               81
#define N_ADDITIVE_EXP1         82
#define N_MULT_EXP              83
#define N_DIV_EXP1              84
#define N_UNARY_EXP             85
#define N_MULT_EXP1             86
#define N_PRIMARY_EXP           87
#define N_ID_EVAL               88
#define N_ID_EVAL1              89
#define N_ATTR_EVAL             90
#define N_ATTR_EVAL1            91
#define N_STAT_LIST             92
#define N_CONDITION             93
#define N_ELSE_OPT              94
#define N_CATCH_OPT             95
#define N_RETVAL_OPT            96
#define N_ARG_LST_OPT           97
#define N_ARG_LST               98
#define N_ARG_OPT               99

#define ACTION_BASE             100
#define A_OP_VAR_DECL          100
#define A_OP_PUSH_TMP          101
#define A_OP_POP_TMP           102
#define A_OP_VAR_INIT          103
#define A_OP_VAR_ASSIGN        104
#define A_OP_RET_DISCARD       105
#define A_OP_ARRAY_XLAT        106
#define A_OP_OBJECT_GET        107
#define A_OP_ATTR_ASSIGN       108
#define A_OP_ARRAY_ASSIGN      109
#define A_OP_METHOD_LOOKUP     110
#define A_OP_CALL              111
#define A_OP_FUNCTION_LOOKUP   112
#define A_OP_ARG               113
#define A_OP_OR                114
#define A_OP_LOGIC_OR          115
#define A_OP_XOR               116
#define A_OP_AND               117
#define A_OP_LOGIC_AND         118
#define A_OP_LT                119
#define A_OP_GT                120
#define A_OP_EQU               121
#define A_OP_NEQ               122
#define A_OP_GTE               123
#define A_OP_LTE               124
#define A_OP_SHL               125
#define A_OP_ASR               126
#define A_OP_ADD               127
#define A_OP_SUB               128
#define A_OP_DIV               129
#define A_OP_MOD               130
#define A_OP_MUL               131
#define A_OP_INV               132
#define A_OP_MINUS             133
#define A_OP_NOT               134
#define A_OP_PUSH_INT          135
#define A_OP_PUSH_STRING       136
#define A_OP_PUSH_TRUE         137
#define A_OP_PUSH_FALSE        138
#define A_OP_VAR_EVAL          139
#define A_OP_CALL_RET          140
#define A_OP_ATTR_EVAL         141
#define A_OP_ARRAY_EVAL        142
#define A_OP_BLK_OPEN          143
#define A_OP_BLK_CLOSE         144
#define A_OP_FOR_INIT          145
#define A_OP_FOR_COND          146
#define A_OP_FOR_AFTER         147
#define A_OP_FOR_END           148
#define A_OP_WHILE_BEGIN       149
#define A_OP_WHILE_COND        150
#define A_OP_WHILE_END         151
#define A_OP_IF_COND           152
#define A_OP_PATCH_REF         153
#define A_OP_TRY_BEGIN         154
#define A_OP_THROW             155
#define A_OP_IF_ELSE           156
#define A_OP_TRY_END           157
#define A_OP_CATCH             158
#define A_OP_RETURN            159
#define A_OP_RETVAL            160
#define A_OP_FUN_DEF           161
#define A_OP_FUN_END           162
#define A_OP_ARG_DECL          163

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

extern int (* const microjs_ll_op[])(void *);

#ifdef __cplusplus
extern "C" {
#endif

int microjs_ll_push(uint8_t * sp, unsigned int sym, unsigned int tok);
int microjs_ll_start(uint8_t * sp);

#ifdef __cplusplus
}
#endif

#endif /* __MICROJS2_LL_H__ */


