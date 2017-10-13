#ifndef __MICROJS2_LL_H__
#define __MICROJS2_LL_H__

#include <stdint.h>

/* Last symbol num:198  Num rules:141 */

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
#define T_VAR_ID                44
#define T_CONST_ID              45
#define T_FUNC_ID               46
#define T_INT                   47
#define T_CHAR                  48
#define T_STRING                49
#define T_ERR                   50
#define T_CONST                 51
#define T_ADD_EQ                52
#define T_SUB_EQ                53
#define T_DIV_EQ                54
#define T_MOD_EQ                55
#define T_MUL_EQ                56
#define T_AND_EQ                57
#define T_OR_EQ                 58
#define T_XOR_EQ                59
#define T_SHL_EQ                60
#define T_ASR_EQ                61
#define T_NOT                   62
#define T_BREAK                 63
#define T_CONTINUE              64
#define T_DO                    65
#define T_RETURN                66
#define T_FUNCTION              67

#define NONTERM_BASE            68
#define N_PROGRAM               68
#define N_STAT                  69
#define N_SEMI_STAT             70
#define N_SEMI_LIST             71
#define N_COMPOUND_STAT         72
#define N_VAR_LIST              73
#define N_VAR                   74
#define N_VAR_LIST1             75
#define N_VAR_INIT_OPT          76
#define N_EXP                   77
#define N_VAR_ASSIGN            78
#define N_ADDITIVE_EXP          79
#define N_DIV_EXP               80
#define N_MULT_EXP              81
#define N_AND_EXP               82
#define N_SHIFT_EXP             83
#define N_ATTR_ASSIGN1          84
#define N_ATTR_ASSIGN           85
#define N_ATTR_ASSIGN2          86
#define N_METHOD_CALL           87
#define N_CONST_LIST            88
#define N_CONST                 89
#define N_CONST_LIST1           90
#define N_CONST_EXP             91
#define N_ARG_LIST_OPT          92
#define N_FUNCTION_CALL         93
#define N_ARG_LIST              94
#define N_ARG_LIST1             95
#define N_EXP_LST_OPT           96
#define N_EXP_LST               97
#define N_EXP_LST1              98
#define N_OR_EXP                99
#define N_RELATIONAL_EXP       100
#define N_AND_EXP1             101
#define N_RELATIONAL_EXP1      102
#define N_SHIFT_EXP1           103
#define N_ADDITIVE_EXP1        104
#define N_DIV_EXP1             105
#define N_UNARY_EXP            106
#define N_MULT_EXP1            107
#define N_PRIMARY_EXP          108
#define N_ID_EVAL1             109
#define N_ATTR_EVAL            110
#define N_ATTR_EVAL1           111
#define N_STAT_LIST            112
#define N_LOOP_COMP_STAT       113
#define N_LOOP_STAT_LIST       114
#define N_CONDITION            115
#define N_ELSE_OPT             116
#define N_CATCH_OPT            117
#define N_FUNC_COMP_STAT       118
#define N_FUNC_STAT_LIST       119
#define N_RETVAL_OPT           120
#define N_FUNCTION_DEF         121
#define N_ARG_LST_OPT          122
#define N_ARG_LST              123
#define N_ARG_OPT              124

#define ACTION_BASE             125
#define A_OP_VAR_DECL          125
#define A_OP_POP_REF           126
#define A_OP_VAR_INIT          127
#define A_OP_VAR_ASSIGN        128
#define A_OP_VAR_EVAL          129
#define A_OP_ADD               130
#define A_OP_SUB               131
#define A_OP_DIV               132
#define A_OP_MOD               133
#define A_OP_MUL               134
#define A_OP_AND               135
#define A_OP_OR                136
#define A_OP_XOR               137
#define A_OP_SHL               138
#define A_OP_ASR               139
#define A_OP_ARRAY_XLAT        140
#define A_OP_OBJECT_GET        141
#define A_OP_PUSH_TMP          142
#define A_OP_ATTR_ASSIGN       143
#define A_OP_ARRAY_ASSIGN      144
#define A_OP_RET_DISCARD       145
#define A_OP_CONST_DECL        146
#define A_OP_CONST_INIT        147
#define A_OP_PUSH_INT          148
#define A_OP_PUSH_STRING       149
#define A_OP_PUSH_TRUE         150
#define A_OP_PUSH_FALSE        151
#define A_OP_PUSH_REF          152
#define A_OP_CONST_EVAL        153
#define A_OP_METHOD_LOOKUP     154
#define A_OP_CALL              155
#define A_OP_FUNCTION_LOOKUP   156
#define A_OP_ARG               157
#define A_OP_LOGIC_OR          158
#define A_OP_LOGIC_AND         159
#define A_OP_LT                160
#define A_OP_GT                161
#define A_OP_EQU               162
#define A_OP_NEQ               163
#define A_OP_GTE               164
#define A_OP_LTE               165
#define A_OP_INV               166
#define A_OP_MINUS             167
#define A_OP_NOT               168
#define A_OP_RET_VAL           169
#define A_OP_ATTR_EVAL         170
#define A_OP_ARRAY_EVAL        171
#define A_OP_BLK_OPEN          172
#define A_OP_BLK_CLOSE         173
#define A_OP_LOOP_BREAK        174
#define A_OP_LOOP_CONTINUE     175
#define A_OP_FOR_INIT          176
#define A_OP_FOR_COND          177
#define A_OP_FOR_AFTER         178
#define A_OP_FOR_END           179
#define A_OP_WHILE_BEGIN       180
#define A_OP_WHILE_COND        181
#define A_OP_WHILE_END         182
#define A_OP_DO_WHILE_BEGIN    183
#define A_OP_DO_WHILE_COND     184
#define A_OP_DO_WHILE_END      185
#define A_OP_IF_COND           186
#define A_OP_PATCH_REF         187
#define A_OP_TRY_BEGIN         188
#define A_OP_THROW             189
#define A_OP_IF_ELSE           190
#define A_OP_TRY_END           191
#define A_OP_CATCH             192
#define A_OP_RETURN            193
#define A_OP_RETVAL            194
#define A_OP_FUN_DEF           195
#define A_OP_FUN_END           196
#define A_OP_ARG_DECL          197

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

extern const char * const microjs_ll_sym[];

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


