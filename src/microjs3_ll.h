#ifndef __MICROJS3_LL_H__
#define __MICROJS3_LL_H__

#include <stdint.h>

/* Last symbol num:240  Num rules:191 */

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
#define T_BREAK                 62
#define T_CONTINUE              63
#define T_FPVAR_ID              64
#define T_FPFUNC_ID             65
#define T_DO                    66
#define T_FPCONST_ID            67
#define T_FPINT                 68
#define T_FPCMP                 69
#define T_NOT                   70
#define T_RETURN                71
#define T_FUNCTION              72
#define T_FPMETHOD_CALL         73
#define T_INTFP                 74
#define T_FPLIT                 75

#define NONTERM_BASE            76
#define N_PROGRAM               76
#define N_STAT                  77
#define N_SEMI_STAT             78
#define N_SEMI_LIST             79
#define N_COMPOUND_STAT         80
#define N_STAT_LIST             81
#define N_LOOP_COMP_STAT        82
#define N_LOOP_STAT_LIST        83
#define N_EXP                   84
#define N_VAR_LIST              85
#define N_CONST_LIST            86
#define N_VAR_ASSIGN            87
#define N_FUNCTION_CALL         88
#define N_FPVAR_ASSIGN          89
#define N_CONDITION             90
#define N_EXP_LST_OPT           91
#define N_ELSE_OPT              92
#define N_CATCH_OPT             93
#define N_VAR                   94
#define N_VAR_LIST1             95
#define N_VAR_INIT_OPT          96
#define N_VAR_INIT_ASSIGN       97
#define N_ADDITIVE_EXP          98
#define N_DIV_EXP               99
#define N_MULT_EXP             100
#define N_AND_EXP              101
#define N_SHIFT_EXP            102
#define N_ATTR_ASSIGN1         103
#define N_ATTR_ASSIGN          104
#define N_ATTR_ASSIGN2         105
#define N_METHOD_CALL          106
#define N_CONST                107
#define N_CONST_LIST1          108
#define N_CONST_INIT           109
#define N_CONST_EXP            110
#define N_FPCONST_EXP          111
#define N_ARG_LIST_OPT         112
#define N_ARG_LIST             113
#define N_ARG_LIST1            114
#define N_EXP_LST              115
#define N_EXP_LST1             116
#define N_COND_EXP             117
#define N_FPEXP                118
#define N_FPRELATIONAL_EXP     119
#define N_OR_EXP               120
#define N_COND_EXP1            121
#define N_OR_EXP1              122
#define N_RELATIONAL_EXP       123
#define N_AND_EXP1             124
#define N_RELATIONAL_EXP1      125
#define N_SHIFT_EXP1           126
#define N_ADDITIVE_EXP1        127
#define N_DIV_EXP1             128
#define N_UNARY_EXP            129
#define N_MULT_EXP1            130
#define N_PRIMARY_EXP          131
#define N_ID_EVAL1             132
#define N_ATTR_EVAL            133
#define N_ATTR_EVAL1           134
#define N_FUNC_COMP_STAT       135
#define N_FUNC_STAT_LIST       136
#define N_RETVAL_OPT           137
#define N_FUNCTION_DEF         138
#define N_ARG_LST_OPT          139
#define N_ARG_LST              140
#define N_ARG_OPT              141
#define N_FPADDITIVE_EXP       142
#define N_FPDIV_EXP            143
#define N_FPMULT_EXP           144
#define N_FPATTR_ASSIGN1       145
#define N_FPATTR_ASSIGN        146
#define N_FPATTR_ASSIGN2       147
#define N_FPRELATIONAL_EXP1    148
#define N_FPADDITIVE_EXP1      149
#define N_FPDIV_EXP1           150
#define N_FPUNARY_EXP          151
#define N_FPMULT_EXP1          152
#define N_FPPRIMARY_EXP        153

#define ACTION_BASE             154
#define A_OP_BLK_OPEN          154
#define A_OP_BLK_CLOSE         155
#define A_OP_LOOP_BREAK        156
#define A_OP_LOOP_CONTINUE     157
#define A_OP_THROW             158
#define A_OP_PUSH_REF          159
#define A_OP_RET_DISCARD       160
#define A_OP_FOR_INIT          161
#define A_OP_FOR_COND          162
#define A_OP_FOR_AFTER         163
#define A_OP_FOR_END           164
#define A_OP_WHILE_BEGIN       165
#define A_OP_WHILE_COND        166
#define A_OP_WHILE_END         167
#define A_OP_DO_WHILE_BEGIN    168
#define A_OP_DO_WHILE_COND     169
#define A_OP_DO_WHILE_END      170
#define A_OP_IF_COND           171
#define A_OP_PATCH_REF         172
#define A_OP_TRY_BEGIN         173
#define A_OP_IF_ELSE           174
#define A_OP_TRY_END           175
#define A_OP_CATCH             176
#define A_OP_VAR_DECL          177
#define A_OP_PUSH_TMP          178
#define A_OP_VAR_INIT          179
#define A_OP_POP_REF           180
#define A_OP_VAR_ASSIGN        181
#define A_OP_VAR_EVAL          182
#define A_OP_ADD               183
#define A_OP_SUB               184
#define A_OP_DIV               185
#define A_OP_MOD               186
#define A_OP_MUL               187
#define A_OP_AND               188
#define A_OP_OR                189
#define A_OP_XOR               190
#define A_OP_SHL               191
#define A_OP_ASR               192
#define A_OP_ARRAY_XLAT        193
#define A_OP_OBJECT_GET        194
#define A_OP_ATTR_ASSIGN       195
#define A_OP_ARRAY_ASSIGN      196
#define A_OP_CONST_DECL        197
#define A_OP_CONST_INIT        198
#define A_OP_PUSH_INT          199
#define A_OP_PUSH_STRING       200
#define A_OP_PUSH_TRUE         201
#define A_OP_PUSH_FALSE        202
#define A_OP_CONST_EVAL        203
#define A_OP_FPCONST_INIT      204
#define A_OP_METHOD_LOOKUP     205
#define A_OP_CALL              206
#define A_OP_FUNCTION_LOOKUP   207
#define A_OP_ARG               208
#define A_OP_LOGIC_OR          209
#define A_OP_LOGIC_AND         210
#define A_OP_LT                211
#define A_OP_GT                212
#define A_OP_EQU               213
#define A_OP_NEQ               214
#define A_OP_GTE               215
#define A_OP_LTE               216
#define A_OP_INV               217
#define A_OP_MINUS             218
#define A_OP_NOT               219
#define A_OP_RET_VAL           220
#define A_OP_ATTR_EVAL         221
#define A_OP_ARRAY_EVAL        222
#define A_OP_RETURN            223
#define A_OP_RETVAL            224
#define A_OP_FUN_DEF           225
#define A_OP_FUN_END           226
#define A_OP_ARG_DECL          227
#define A_OP_FPADD             228
#define A_OP_FPSUB             229
#define A_OP_FPDIV             230
#define A_OP_FPMUL             231
#define A_OP_FPLT              232
#define A_OP_FPGT              233
#define A_OP_FPEQU             234
#define A_OP_FPNEQ             235
#define A_OP_FPGTE             236
#define A_OP_FPLTE             237
#define A_OP_FPMINUS           238
#define A_OP_PUSH_FP           239

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

#endif /* __MICROJS3_LL_H__ */


