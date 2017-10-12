/* LL(1) Embeddedd Nonrecursive Predictive Parser */

#include "microjs2_ll.h"

/* Token-Rule pair (predict set) */
struct tr_pair {
	uint8_t t;
	uint8_t r;
};

/* Predict sets */
static const struct tr_pair predict_vec[] = {
	/*  65 (program) */
	{  0,  0}, { 23,  3}, { 36,  1}, { 37,  1}, { 38,  2}, { 40,  1}, 
	{ 41,  2}, { 42,  1}, { 43,  2}, { 48,  2}, { 62,  1}, { 63,  2}, 
	/*  66 (stat) */
	{ 36,109}, { 37,112}, { 40,113}, { 42,110}, { 62,111}, 
	/*  67 (semi_stat) */
	{ 38,115}, { 41,116}, { 43,119}, { 48,117}, { 63,118}, 
	/*  68 (semi_list) */
	{  0,  4}, {  3,  5}, 
	/*  69 (compound_stat) */
	{ 23, 99}, 
	/*  70 (var_list) */
	{ 43,  6}, 
	/*  71 (var) */
	{ 43,  9}, 
	/*  72 (var_list1) */
	{  0,  7}, {  2,  8}, {  3,  7}, 
	/*  73 (var_init_opt) */
	{  0, 10}, {  2, 10}, {  3, 10}, { 16, 11}, 
	/*  74 (exp) */
	{  6, 47}, { 13, 47}, { 21, 47}, { 35, 47}, { 39, 47}, { 43, 47}, 
	{ 44, 47}, { 45, 47}, { 46, 47}, { 59, 47}, 
	/*  75 (assign_or_call1) */
	{  1, 25}, { 16, 12}, { 19, 24}, { 21, 23}, { 49, 13}, { 50, 14}, 
	{ 51, 15}, { 52, 16}, { 53, 17}, { 54, 18}, { 55, 19}, { 56, 20}, 
	{ 57, 21}, { 58, 22}, 
	/*  76 (additive_exp) */
	{  6, 68}, { 13, 68}, { 21, 68}, { 35, 68}, { 39, 68}, { 43, 68}, 
	{ 44, 68}, { 45, 68}, { 46, 68}, { 59, 68}, 
	/*  77 (div_exp) */
	{  6, 72}, { 13, 72}, { 21, 72}, { 35, 72}, { 39, 72}, { 43, 72}, 
	{ 44, 72}, { 45, 72}, { 46, 72}, { 59, 72}, 
	/*  78 (mult_exp) */
	{  6, 76}, { 13, 76}, { 21, 76}, { 35, 76}, { 39, 76}, { 43, 76}, 
	{ 44, 76}, { 45, 76}, { 46, 76}, { 59, 76}, 
	/*  79 (and_exp) */
	{  6, 52}, { 13, 52}, { 21, 52}, { 35, 52}, { 39, 52}, { 43, 52}, 
	{ 44, 52}, { 45, 52}, { 46, 52}, { 59, 52}, 
	/*  80 (shift_exp) */
	{  6, 64}, { 13, 64}, { 21, 64}, { 35, 64}, { 39, 64}, { 43, 64}, 
	{ 44, 64}, { 45, 64}, { 46, 64}, { 59, 64}, 
	/*  81 (function_call) */
	{ 21, 36}, 
	/*  82 (attr_assign) */
	{ 43, 26}, 
	/*  83 (attr_assign2) */
	{ 16, 27}, { 19, 28}, { 21, 29}, 
	/*  84 (method_call) */
	{ 21, 35}, 
	/*  85 (const_list) */
	{ 43, 30}, 
	/*  86 (const) */
	{ 43, 33}, 
	/*  87 (const_list1) */
	{  0, 31}, {  2, 32}, {  3, 31}, 
	/*  88 (const_exp) */
	{  6, 34}, { 13, 34}, { 21, 34}, { 35, 34}, { 39, 34}, { 43, 34}, 
	{ 44, 34}, { 45, 34}, { 46, 34}, { 59, 34}, 
	/*  89 (arg_list_opt) */
	{  6, 38}, { 13, 38}, { 21, 38}, { 22, 37}, { 35, 38}, { 39, 38}, 
	{ 43, 38}, { 44, 38}, { 45, 38}, { 46, 38}, { 59, 38}, 
	/*  90 (arg_list) */
	{  6, 39}, { 13, 39}, { 21, 39}, { 35, 39}, { 39, 39}, { 43, 39}, 
	{ 44, 39}, { 45, 39}, { 46, 39}, { 59, 39}, 
	/*  91 (arg_list1) */
	{  2, 41}, { 22, 40}, 
	/*  92 (exp_lst_opt) */
	{  3, 42}, { 22, 42}, { 43, 43}, 
	/*  93 (exp_lst) */
	{ 43, 44}, 
	/*  94 (exp_lst1) */
	{  2, 46}, {  3, 45}, { 22, 45}, 
	/*  95 (or_exp) */
	{  0, 48}, {  2, 48}, {  3, 48}, { 11, 49}, { 12, 51}, { 20, 48}, 
	{ 22, 48}, { 31, 50}, 
	/*  96 (relational_exp) */
	{  6, 56}, { 13, 56}, { 21, 56}, { 35, 56}, { 39, 56}, { 43, 56}, 
	{ 44, 56}, { 45, 56}, { 46, 56}, { 59, 56}, 
	/*  97 (and_exp1) */
	{  0, 53}, {  2, 53}, {  3, 53}, { 10, 54}, { 11, 53}, { 12, 53}, 
	{ 20, 53}, { 22, 53}, { 31, 53}, { 32, 55}, 
	/*  98 (relational_exp1) */
	{  0, 57}, {  2, 57}, {  3, 57}, { 10, 57}, { 11, 57}, { 12, 57}, 
	{ 17, 58}, { 18, 59}, { 20, 57}, { 22, 57}, { 25, 62}, { 26, 63}, 
	{ 27, 60}, { 28, 61}, { 31, 57}, { 32, 57}, 
	/*  99 (shift_exp1) */
	{  0, 65}, {  2, 65}, {  3, 65}, { 10, 65}, { 11, 65}, { 12, 65}, 
	{ 17, 65}, { 18, 65}, { 20, 65}, { 22, 65}, { 25, 65}, { 26, 65}, 
	{ 27, 65}, { 28, 65}, { 29, 67}, { 30, 66}, { 31, 65}, { 32, 65}, 
	/* 100 (additive_exp1) */
	{  0, 69}, {  2, 69}, {  3, 69}, {  5, 70}, {  6, 71}, { 10, 69}, 
	{ 11, 69}, { 12, 69}, { 17, 69}, { 18, 69}, { 20, 69}, { 22, 69}, 
	{ 25, 69}, { 26, 69}, { 27, 69}, { 28, 69}, { 29, 69}, { 30, 69}, 
	{ 31, 69}, { 32, 69}, 
	/* 101 (div_exp1) */
	{  0, 73}, {  2, 73}, {  3, 73}, {  5, 73}, {  6, 73}, {  8, 74}, 
	{  9, 75}, { 10, 73}, { 11, 73}, { 12, 73}, { 17, 73}, { 18, 73}, 
	{ 20, 73}, { 22, 73}, { 25, 73}, { 26, 73}, { 27, 73}, { 28, 73}, 
	{ 29, 73}, { 30, 73}, { 31, 73}, { 32, 73}, 
	/* 102 (unary_exp) */
	{  6, 81}, { 13, 80}, { 21, 79}, { 35, 79}, { 39, 79}, { 43, 79}, 
	{ 44, 79}, { 45, 79}, { 46, 79}, { 59, 82}, 
	/* 103 (mult_exp1) */
	{  0, 77}, {  2, 77}, {  3, 77}, {  5, 77}, {  6, 77}, {  7, 78}, 
	{  8, 77}, {  9, 77}, { 10, 77}, { 11, 77}, { 12, 77}, { 17, 77}, 
	{ 18, 77}, { 20, 77}, { 22, 77}, { 25, 77}, { 26, 77}, { 27, 77}, 
	{ 28, 77}, { 29, 77}, { 30, 77}, { 31, 77}, { 32, 77}, 
	/* 104 (primary_exp) */
	{ 21, 83}, { 35, 88}, { 39, 87}, { 43, 89}, { 44, 84}, { 45, 85}, 
	{ 46, 86}, 
	/* 105 (id_eval) */
	{ 43, 90}, 
	/* 106 (id_eval1) */
	{  0, 91}, {  1, 94}, {  2, 91}, {  3, 91}, {  5, 91}, {  6, 91}, 
	{  7, 91}, {  8, 91}, {  9, 91}, { 10, 91}, { 11, 91}, { 12, 91}, 
	{ 17, 91}, { 18, 91}, { 19, 93}, { 20, 91}, { 21, 92}, { 22, 91}, 
	{ 25, 91}, { 26, 91}, { 27, 91}, { 28, 91}, { 29, 91}, { 30, 91}, 
	{ 31, 91}, { 32, 91}, 
	/* 107 (attr_eval) */
	{ 43, 95}, 
	/* 108 (attr_eval1) */
	{  0, 96}, {  2, 96}, {  3, 96}, {  5, 96}, {  6, 96}, {  7, 96}, 
	{  8, 96}, {  9, 96}, { 10, 96}, { 11, 96}, { 12, 96}, { 17, 96}, 
	{ 18, 96}, { 19, 98}, { 20, 96}, { 21, 97}, { 22, 96}, { 25, 96}, 
	{ 26, 96}, { 27, 96}, { 28, 96}, { 29, 96}, { 30, 96}, { 31, 96}, 
	{ 32, 96}, 
	/* 109 (stat_list) */
	{ 24,100}, { 36,101}, { 37,101}, { 38,102}, { 40,101}, { 41,102}, 
	{ 42,101}, { 43,102}, { 48,102}, { 62,101}, { 63,102}, 
	/* 110 (loop_comp_stat) */
	{ 23,103}, 
	/* 111 (loop_stat_list) */
	{ 24,104}, { 36,105}, { 37,105}, { 38,106}, { 40,105}, { 41,106}, 
	{ 42,105}, { 43,106}, { 48,106}, { 60,107}, { 61,108}, { 62,105}, 
	{ 63,106}, 
	/* 112 (condition) */
	{ 21,114}, 
	/* 113 (else_opt) */
	{  0,120}, { 23,120}, { 24,120}, { 34,121}, { 36,120}, { 37,120}, 
	{ 38,120}, { 40,120}, { 41,120}, { 42,120}, { 43,120}, { 48,120}, 
	{ 60,120}, { 61,120}, { 62,120}, { 63,120}, 
	/* 114 (catch_opt) */
	{  0,122}, { 23,122}, { 24,122}, { 33,123}, { 36,122}, { 37,122}, 
	{ 38,122}, { 40,122}, { 41,122}, { 42,122}, { 43,122}, { 48,122}, 
	{ 60,122}, { 61,122}, { 62,122}, { 63,122}, 
	/* 115 (retval_opt) */
	{  0,124}, {  3,124}, {  6,125}, { 13,125}, { 21,125}, { 35,125}, 
	{ 39,125}, { 43,125}, { 44,125}, { 45,125}, { 46,125}, { 59,125}, 
	/* 116 (function_def) */
	{ 64,126}, 
	/* 117 (arg_lst_opt) */
	{ 22,127}, { 43,128}, 
	/* 118 (arg_lst) */
	{ 43,129}, 
	/* 119 (arg_opt) */
	{  2,131}, { 22,130}, 
};
/* 864 bytes; */

static const struct {
	uint16_t off;
	uint8_t cnt;
} predict_idx[] = {
	{   0, 12},
	{  12,  5},
	{  17,  5},
	{  22,  2},
	{  24,  1},
	{  25,  1},
	{  26,  1},
	{  27,  3},
	{  30,  4},
	{  34, 10},
	{  44, 14},
	{  58, 10},
	{  68, 10},
	{  78, 10},
	{  88, 10},
	{  98, 10},
	{ 108,  1},
	{ 109,  1},
	{ 110,  3},
	{ 113,  1},
	{ 114,  1},
	{ 115,  1},
	{ 116,  3},
	{ 119, 10},
	{ 129, 11},
	{ 140, 10},
	{ 150,  2},
	{ 152,  3},
	{ 155,  1},
	{ 156,  3},
	{ 159,  8},
	{ 167, 10},
	{ 177, 10},
	{ 187, 16},
	{ 203, 18},
	{ 221, 20},
	{ 241, 22},
	{ 263, 10},
	{ 273, 23},
	{ 296,  7},
	{ 303,  1},
	{ 304, 26},
	{ 330,  1},
	{ 331, 25},
	{ 356, 11},
	{ 367,  1},
	{ 368, 13},
	{ 381,  1},
	{ 382, 16},
	{ 398, 16},
	{ 414, 12},
	{ 426,  1},
	{ 427,  2},
	{ 429,  1},
	{ 430,  2},
};
/* 220 bytes */

/* Rules vectors table */
static const uint8_t rule_vec[] = {
	/*  0:program(1) -> */
	T_EOF, 
	/*  1:program(2) -> */
	N_STAT, N_PROGRAM, 
	/*  2:program(2) -> */
	N_SEMI_STAT, N_SEMI_LIST, 
	/*  3:program(2) -> */
	N_COMPOUND_STAT, N_PROGRAM, 
	/*  4:semi_list(1) -> */
	T_EOF, 
	/*  5:semi_list(2) -> */
	T_SEMICOLON, N_PROGRAM, 
	/*  6:var_list(2) -> */
	N_VAR, N_VAR_LIST1, 
	/*  7:var_list1(0) -> */
	
	/*  8:var_list1(2) -> */
	T_COMMA, N_VAR_LIST, 
	/*  9:var(4) -> */
	T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, N_VAR_INIT_OPT, 
	/* 10:var_init_opt(1) -> */
	A_OP_POP_TMP, 
	/* 11:var_init_opt(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_INIT, 
	/* 12:assign_or_call1(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_ASSIGN, 
	/* 13:assign_or_call1(5) -> */
	T_ADD_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_ADD, A_OP_VAR_ASSIGN, 
	/* 14:assign_or_call1(5) -> */
	T_SUB_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_SUB, A_OP_VAR_ASSIGN, 
	/* 15:assign_or_call1(5) -> */
	T_DIV_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_DIV, A_OP_VAR_ASSIGN, 
	/* 16:assign_or_call1(5) -> */
	T_MOD_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_MOD, A_OP_VAR_ASSIGN, 
	/* 17:assign_or_call1(5) -> */
	T_MUL_EQ, A_OP_VAR_EVAL, N_MULT_EXP, A_OP_MUL, A_OP_VAR_ASSIGN, 
	/* 18:assign_or_call1(5) -> */
	T_AND_EQ, A_OP_VAR_EVAL, N_AND_EXP, A_OP_AND, A_OP_VAR_ASSIGN, 
	/* 19:assign_or_call1(5) -> */
	T_OR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_OR, A_OP_VAR_ASSIGN, 
	/* 20:assign_or_call1(5) -> */
	T_XOR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_XOR, A_OP_VAR_ASSIGN, 
	/* 21:assign_or_call1(5) -> */
	T_SHL_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_SHL, A_OP_VAR_ASSIGN, 
	/* 22:assign_or_call1(5) -> */
	T_ASR_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_ASR, A_OP_VAR_ASSIGN, 
	/* 23:assign_or_call1(2) -> */
	N_FUNCTION_CALL, A_OP_RET_DISCARD, 
	/* 24:assign_or_call1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_ASSIGN, 
	/* 25:assign_or_call1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_ASSIGN, 
	/* 26:attr_assign(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_ASSIGN2, 
	/* 27:attr_assign2(3) -> */
	T_EQUALS, N_EXP, A_OP_ATTR_ASSIGN, 
	/* 28:attr_assign2(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, T_EQUALS, N_EXP, A_OP_ARRAY_ASSIGN, 
	/* 29:attr_assign2(2) -> */
	N_METHOD_CALL, A_OP_RET_DISCARD, 
	/* 30:const_list(2) -> */
	N_CONST, N_CONST_LIST1, 
	/* 31:const_list1(0) -> */
	
	/* 32:const_list1(2) -> */
	T_COMMA, N_CONST_LIST, 
	/* 33:const(6) -> */
	T_ID, A_OP_CONST_DECL, A_OP_PUSH_TMP, T_EQUALS, N_CONST_EXP, A_OP_CONST_INIT, 
	/* 34:const_exp(1) -> */
	N_EXP, 
	/* 35:method_call(5) -> */
	A_OP_METHOD_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 36:function_call(5) -> */
	A_OP_FUNCTION_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 37:arg_list_opt(0) -> */
	
	/* 38:arg_list_opt(1) -> */
	N_ARG_LIST, 
	/* 39:arg_list(3) -> */
	N_EXP, A_OP_ARG, N_ARG_LIST1, 
	/* 40:arg_list1(0) -> */
	
	/* 41:arg_list1(2) -> */
	T_COMMA, N_ARG_LIST, 
	/* 42:exp_lst_opt(0) -> */
	
	/* 43:exp_lst_opt(1) -> */
	N_EXP_LST, 
	/* 44:exp_lst(4) -> */
	T_ID, A_OP_PUSH_TMP, N_ASSIGN_OR_CALL1, N_EXP_LST1, 
	/* 45:exp_lst1(0) -> */
	
	/* 46:exp_lst1(2) -> */
	T_COMMA, N_EXP_LST, 
	/* 47:exp(2) -> */
	N_AND_EXP, N_OR_EXP, 
	/* 48:or_exp(0) -> */
	
	/* 49:or_exp(3) -> */
	T_BAR, N_EXP, A_OP_OR, 
	/* 50:or_exp(3) -> */
	T_LOGICOR, N_EXP, A_OP_LOGIC_OR, 
	/* 51:or_exp(3) -> */
	T_CARET, N_EXP, A_OP_XOR, 
	/* 52:and_exp(2) -> */
	N_RELATIONAL_EXP, N_AND_EXP1, 
	/* 53:and_exp1(0) -> */
	
	/* 54:and_exp1(3) -> */
	T_AMPERSAND, N_AND_EXP, A_OP_AND, 
	/* 55:and_exp1(3) -> */
	T_LOGICAND, N_AND_EXP, A_OP_LOGIC_AND, 
	/* 56:relational_exp(2) -> */
	N_SHIFT_EXP, N_RELATIONAL_EXP1, 
	/* 57:relational_exp1(0) -> */
	
	/* 58:relational_exp1(3) -> */
	T_LESSTHEN, N_RELATIONAL_EXP, A_OP_LT, 
	/* 59:relational_exp1(3) -> */
	T_GREATTHEN, N_RELATIONAL_EXP, A_OP_GT, 
	/* 60:relational_exp1(3) -> */
	T_EQU, N_RELATIONAL_EXP, A_OP_EQU, 
	/* 61:relational_exp1(3) -> */
	T_NEQ, N_RELATIONAL_EXP, A_OP_NEQ, 
	/* 62:relational_exp1(3) -> */
	T_GTE, N_RELATIONAL_EXP, A_OP_GTE, 
	/* 63:relational_exp1(3) -> */
	T_LTE, N_RELATIONAL_EXP, A_OP_LTE, 
	/* 64:shift_exp(2) -> */
	N_ADDITIVE_EXP, N_SHIFT_EXP1, 
	/* 65:shift_exp1(0) -> */
	
	/* 66:shift_exp1(3) -> */
	T_SHL, N_SHIFT_EXP, A_OP_SHL, 
	/* 67:shift_exp1(3) -> */
	T_ASR, N_SHIFT_EXP, A_OP_ASR, 
	/* 68:additive_exp(2) -> */
	N_DIV_EXP, N_ADDITIVE_EXP1, 
	/* 69:additive_exp1(0) -> */
	
	/* 70:additive_exp1(3) -> */
	T_PLUS, N_ADDITIVE_EXP, A_OP_ADD, 
	/* 71:additive_exp1(3) -> */
	T_MINUS, N_ADDITIVE_EXP, A_OP_SUB, 
	/* 72:div_exp(2) -> */
	N_MULT_EXP, N_DIV_EXP1, 
	/* 73:div_exp1(0) -> */
	
	/* 74:div_exp1(3) -> */
	T_SLASH, N_DIV_EXP, A_OP_DIV, 
	/* 75:div_exp1(3) -> */
	T_PERCENT, N_DIV_EXP, A_OP_MOD, 
	/* 76:mult_exp(2) -> */
	N_UNARY_EXP, N_MULT_EXP1, 
	/* 77:mult_exp1(0) -> */
	
	/* 78:mult_exp1(3) -> */
	T_STAR, N_MULT_EXP, A_OP_MUL, 
	/* 79:unary_exp(1) -> */
	N_PRIMARY_EXP, 
	/* 80:unary_exp(3) -> */
	T_TILDE, N_UNARY_EXP, A_OP_INV, 
	/* 81:unary_exp(3) -> */
	T_MINUS, N_UNARY_EXP, A_OP_MINUS, 
	/* 82:unary_exp(3) -> */
	T_NOT, N_UNARY_EXP, A_OP_NOT, 
	/* 83:primary_exp(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 84:primary_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 85:primary_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 86:primary_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 87:primary_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 88:primary_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 89:primary_exp(1) -> */
	N_ID_EVAL, 
	/* 90:id_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ID_EVAL1, 
	/* 91:id_eval1(1) -> */
	A_OP_VAR_EVAL, 
	/* 92:id_eval1(2) -> */
	N_FUNCTION_CALL, A_OP_CALL_RET, 
	/* 93:id_eval1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_EVAL, 
	/* 94:id_eval1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_EVAL, 
	/* 95:attr_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_EVAL1, 
	/* 96:attr_eval1(1) -> */
	A_OP_ATTR_EVAL, 
	/* 97:attr_eval1(2) -> */
	N_METHOD_CALL, A_OP_CALL_RET, 
	/* 98:attr_eval1(4) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_EVAL, 
	/* 99:compound_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 100:stat_list(0) -> */
	
	/* 101:stat_list(2) -> */
	N_STAT, N_STAT_LIST, 
	/* 102:stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_STAT_LIST, 
	/* 103:loop_comp_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_LOOP_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 104:loop_stat_list(0) -> */
	
	/* 105:loop_stat_list(2) -> */
	N_STAT, N_LOOP_STAT_LIST, 
	/* 106:loop_stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_LOOP_STAT_LIST, 
	/* 107:loop_stat_list(3) -> */
	T_BREAK, T_SEMICOLON, A_OP_LOOP_BREAK, 
	/* 108:loop_stat_list(3) -> */
	T_CONTINUE, T_SEMICOLON, A_OP_LOOP_CONTINUE, 
	/* 109:stat(15) -> */
	T_FOR, A_OP_BLK_OPEN, T_LPAREN, N_EXP_LST_OPT, T_SEMICOLON, A_OP_FOR_INIT, N_EXP, A_OP_FOR_COND, T_SEMICOLON, N_EXP_LST_OPT, A_OP_FOR_AFTER, T_RPAREN, N_LOOP_COMP_STAT, A_OP_FOR_END, A_OP_BLK_CLOSE, 
	/* 110:stat(6) -> */
	T_WHILE, A_OP_WHILE_BEGIN, N_CONDITION, A_OP_WHILE_COND, N_LOOP_COMP_STAT, A_OP_WHILE_END, 
	/* 111:stat(8) -> */
	T_DO, A_OP_DO_WHILE_BEGIN, N_LOOP_COMP_STAT, T_WHILE, N_CONDITION, A_OP_DO_WHILE_COND, A_OP_DO_WHILE_END, T_SEMICOLON, 
	/* 112:stat(6) -> */
	T_IF, N_CONDITION, A_OP_IF_COND, N_COMPOUND_STAT, N_ELSE_OPT, A_OP_PATCH_REF, 
	/* 113:stat(4) -> */
	T_TRY, A_OP_TRY_BEGIN, N_COMPOUND_STAT, N_CATCH_OPT, 
	/* 114:condition(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 115:semi_stat(3) -> */
	T_THROW, N_EXP, A_OP_THROW, 
	/* 116:semi_stat(2) -> */
	T_VAR, N_VAR_LIST, 
	/* 117:semi_stat(2) -> */
	T_CONST, N_CONST_LIST, 
	/* 118:semi_stat(2) -> */
	T_RETURN, N_RETVAL_OPT, 
	/* 119:semi_stat(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ASSIGN_OR_CALL1, 
	/* 120:else_opt(0) -> */
	
	/* 121:else_opt(3) -> */
	T_ELSE, A_OP_IF_ELSE, N_COMPOUND_STAT, 
	/* 122:catch_opt(1) -> */
	A_OP_TRY_END, 
	/* 123:catch_opt(14) -> */
	T_CATCH, A_OP_CATCH, A_OP_BLK_OPEN, T_LPAREN, T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, A_OP_VAR_INIT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, A_OP_PATCH_REF, 
	/* 124:retval_opt(1) -> */
	A_OP_RETURN, 
	/* 125:retval_opt(2) -> */
	N_EXP, A_OP_RETVAL, 
	/* 126:function_def(12) -> */
	T_FUNCTION, T_ID, A_OP_FUN_DEF, A_OP_BLK_OPEN, T_LPAREN, N_ARG_LST_OPT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_RETURN, A_OP_PATCH_REF, 
	/* 127:arg_lst_opt(0) -> */
	
	/* 128:arg_lst_opt(1) -> */
	N_ARG_LST, 
	/* 129:arg_lst(3) -> */
	T_ID, A_OP_ARG_DECL, N_ARG_OPT, 
	/* 130:arg_opt(0) -> */
	
	/* 131:arg_opt(2) -> */
	T_COMMA, N_ARG_LST, 
};
/* 370 bytes */

static const struct {
	uint16_t off;
	uint8_t cnt;
} rule_idx[] = {
	{   0,  1},
	{   1,  2},
	{   3,  2},
	{   5,  2},
	{   7,  1},
	{   8,  2},
	{  10,  2},
	{  12,  0},
	{  12,  2},
	{  14,  4},
	{  18,  1},
	{  19,  3},
	{  22,  3},
	{  25,  5},
	{  30,  5},
	{  35,  5},
	{  40,  5},
	{  45,  5},
	{  50,  5},
	{  55,  5},
	{  60,  5},
	{  65,  5},
	{  70,  5},
	{  75,  2},
	{  77,  6},
	{  83,  3},
	{  86,  3},
	{  89,  3},
	{  92,  6},
	{  98,  2},
	{ 100,  2},
	{ 102,  0},
	{ 102,  2},
	{ 104,  6},
	{ 110,  1},
	{ 111,  5},
	{ 116,  5},
	{ 121,  0},
	{ 121,  1},
	{ 122,  3},
	{ 125,  0},
	{ 125,  2},
	{ 127,  0},
	{ 127,  1},
	{ 128,  4},
	{ 132,  0},
	{ 132,  2},
	{ 134,  2},
	{ 136,  0},
	{ 136,  3},
	{ 139,  3},
	{ 142,  3},
	{ 145,  2},
	{ 147,  0},
	{ 147,  3},
	{ 150,  3},
	{ 153,  2},
	{ 155,  0},
	{ 155,  3},
	{ 158,  3},
	{ 161,  3},
	{ 164,  3},
	{ 167,  3},
	{ 170,  3},
	{ 173,  2},
	{ 175,  0},
	{ 175,  3},
	{ 178,  3},
	{ 181,  2},
	{ 183,  0},
	{ 183,  3},
	{ 186,  3},
	{ 189,  2},
	{ 191,  0},
	{ 191,  3},
	{ 194,  3},
	{ 197,  2},
	{ 199,  0},
	{ 199,  3},
	{ 202,  1},
	{ 203,  3},
	{ 206,  3},
	{ 209,  3},
	{ 212,  3},
	{ 215,  2},
	{ 217,  2},
	{ 219,  2},
	{ 221,  2},
	{ 223,  2},
	{ 225,  1},
	{ 226,  3},
	{ 229,  1},
	{ 230,  2},
	{ 232,  6},
	{ 238,  3},
	{ 241,  3},
	{ 244,  1},
	{ 245,  2},
	{ 247,  4},
	{ 251,  5},
	{ 256,  0},
	{ 256,  2},
	{ 258,  3},
	{ 261,  5},
	{ 266,  0},
	{ 266,  2},
	{ 268,  3},
	{ 271,  3},
	{ 274,  3},
	{ 277, 15},
	{ 292,  6},
	{ 298,  8},
	{ 306,  6},
	{ 312,  4},
	{ 316,  3},
	{ 319,  3},
	{ 322,  2},
	{ 324,  2},
	{ 326,  2},
	{ 328,  3},
	{ 331,  0},
	{ 331,  3},
	{ 334,  1},
	{ 335, 14},
	{ 349,  1},
	{ 350,  2},
	{ 352, 12},
	{ 364,  0},
	{ 364,  1},
	{ 365,  3},
	{ 368,  0},
	{ 368,  2},
};
/* 528 bytes */

/* Total: 1982 bytes */


int microjs_ll_push(uint8_t * sp, unsigned int sym, unsigned int tok)
{
	const struct tr_pair * vec;
	uint8_t * p;
	int imax;
	int imin;
	int n;
	int i;

	/* Get the index for the symbol at the stack's head */
	i = sym - NONTERM_BASE;
	if (i < 0) /* Shuld be nonterminal */
		return -1;
	vec = &predict_vec[predict_idx[i].off];
	imax = predict_idx[i].cnt;
	imin = 1;

	/* Is the production list empty ? !!! 
	if (imax < 0)
		return -1;
	*/

	/* Binary search for the matching rule */
	while (imin < imax) {
		int imid = (imin + imax) / 2;
		if (vec[imid - 1].t < tok) 
			imin = imid + 1;
		else
			imax = imid;
	}

	if (vec[imin - 1].t != tok) {
		/* No matching rule, return error. */
		return -1;
	}

	i = vec[imin - 1].r;
	n = rule_idx[i].cnt;
	p = (uint8_t *)&rule_vec[rule_idx[i].off];
	sp -= n;

	/* Push the production into the stack */
	for (i = 0; i < n; ++i)
		sp[i] = p[i];

	/* Return the lenght of the production */
	return n;
}

int microjs_ll_start(uint8_t * sp)
{
	sp[-1] = T_EOF;
	sp[-2] = N_PROGRAM;

	return 2;
}


/* Syntax action callbacks */
extern int op_var_decl(void * arg);
extern int op_push_tmp(void * arg);
extern int op_pop_tmp(void * arg);
extern int op_var_init(void * arg);
extern int op_var_assign(void * arg);
extern int op_var_eval(void * arg);
extern int op_add(void * arg);
extern int op_sub(void * arg);
extern int op_div(void * arg);
extern int op_mod(void * arg);
extern int op_mul(void * arg);
extern int op_and(void * arg);
extern int op_or(void * arg);
extern int op_xor(void * arg);
extern int op_shl(void * arg);
extern int op_asr(void * arg);
extern int op_ret_discard(void * arg);
extern int op_array_xlat(void * arg);
extern int op_object_get(void * arg);
extern int op_attr_assign(void * arg);
extern int op_array_assign(void * arg);
extern int op_const_decl(void * arg);
extern int op_const_init(void * arg);
extern int op_method_lookup(void * arg);
extern int op_call(void * arg);
extern int op_function_lookup(void * arg);
extern int op_arg(void * arg);
extern int op_logic_or(void * arg);
extern int op_logic_and(void * arg);
extern int op_lt(void * arg);
extern int op_gt(void * arg);
extern int op_equ(void * arg);
extern int op_neq(void * arg);
extern int op_gte(void * arg);
extern int op_lte(void * arg);
extern int op_inv(void * arg);
extern int op_minus(void * arg);
extern int op_not(void * arg);
extern int op_push_int(void * arg);
extern int op_push_string(void * arg);
extern int op_push_true(void * arg);
extern int op_push_false(void * arg);
extern int op_call_ret(void * arg);
extern int op_attr_eval(void * arg);
extern int op_array_eval(void * arg);
extern int op_blk_open(void * arg);
extern int op_blk_close(void * arg);
extern int op_loop_break(void * arg);
extern int op_loop_continue(void * arg);
extern int op_for_init(void * arg);
extern int op_for_cond(void * arg);
extern int op_for_after(void * arg);
extern int op_for_end(void * arg);
extern int op_while_begin(void * arg);
extern int op_while_cond(void * arg);
extern int op_while_end(void * arg);
extern int op_do_while_begin(void * arg);
extern int op_do_while_cond(void * arg);
extern int op_do_while_end(void * arg);
extern int op_if_cond(void * arg);
extern int op_patch_ref(void * arg);
extern int op_try_begin(void * arg);
extern int op_throw(void * arg);
extern int op_if_else(void * arg);
extern int op_try_end(void * arg);
extern int op_catch(void * arg);
extern int op_return(void * arg);
extern int op_retval(void * arg);
extern int op_fun_def(void * arg);
extern int op_arg_decl(void * arg);


/* Syntax action callback lookup table */
int (* const microjs_ll_op[])(void *) = {
	[ACTION(A_OP_VAR_DECL)] = op_var_decl,
 	[ACTION(A_OP_PUSH_TMP)] = op_push_tmp,
 	[ACTION(A_OP_POP_TMP)] = op_pop_tmp,
 	[ACTION(A_OP_VAR_INIT)] = op_var_init,
 	[ACTION(A_OP_VAR_ASSIGN)] = op_var_assign,
 	[ACTION(A_OP_VAR_EVAL)] = op_var_eval,
 	[ACTION(A_OP_ADD)] = op_add,
 	[ACTION(A_OP_SUB)] = op_sub,
 	[ACTION(A_OP_DIV)] = op_div,
 	[ACTION(A_OP_MOD)] = op_mod,
 	[ACTION(A_OP_MUL)] = op_mul,
 	[ACTION(A_OP_AND)] = op_and,
 	[ACTION(A_OP_OR)] = op_or,
 	[ACTION(A_OP_XOR)] = op_xor,
 	[ACTION(A_OP_SHL)] = op_shl,
 	[ACTION(A_OP_ASR)] = op_asr,
 	[ACTION(A_OP_RET_DISCARD)] = op_ret_discard,
 	[ACTION(A_OP_ARRAY_XLAT)] = op_array_xlat,
 	[ACTION(A_OP_OBJECT_GET)] = op_object_get,
 	[ACTION(A_OP_ATTR_ASSIGN)] = op_attr_assign,
 	[ACTION(A_OP_ARRAY_ASSIGN)] = op_array_assign,
 	[ACTION(A_OP_CONST_DECL)] = op_const_decl,
 	[ACTION(A_OP_CONST_INIT)] = op_const_init,
 	[ACTION(A_OP_METHOD_LOOKUP)] = op_method_lookup,
 	[ACTION(A_OP_CALL)] = op_call,
 	[ACTION(A_OP_FUNCTION_LOOKUP)] = op_function_lookup,
 	[ACTION(A_OP_ARG)] = op_arg,
 	[ACTION(A_OP_LOGIC_OR)] = op_logic_or,
 	[ACTION(A_OP_LOGIC_AND)] = op_logic_and,
 	[ACTION(A_OP_LT)] = op_lt,
 	[ACTION(A_OP_GT)] = op_gt,
 	[ACTION(A_OP_EQU)] = op_equ,
 	[ACTION(A_OP_NEQ)] = op_neq,
 	[ACTION(A_OP_GTE)] = op_gte,
 	[ACTION(A_OP_LTE)] = op_lte,
 	[ACTION(A_OP_INV)] = op_inv,
 	[ACTION(A_OP_MINUS)] = op_minus,
 	[ACTION(A_OP_NOT)] = op_not,
 	[ACTION(A_OP_PUSH_INT)] = op_push_int,
 	[ACTION(A_OP_PUSH_STRING)] = op_push_string,
 	[ACTION(A_OP_PUSH_TRUE)] = op_push_true,
 	[ACTION(A_OP_PUSH_FALSE)] = op_push_false,
 	[ACTION(A_OP_CALL_RET)] = op_call_ret,
 	[ACTION(A_OP_ATTR_EVAL)] = op_attr_eval,
 	[ACTION(A_OP_ARRAY_EVAL)] = op_array_eval,
 	[ACTION(A_OP_BLK_OPEN)] = op_blk_open,
 	[ACTION(A_OP_BLK_CLOSE)] = op_blk_close,
 	[ACTION(A_OP_LOOP_BREAK)] = op_loop_break,
 	[ACTION(A_OP_LOOP_CONTINUE)] = op_loop_continue,
 	[ACTION(A_OP_FOR_INIT)] = op_for_init,
 	[ACTION(A_OP_FOR_COND)] = op_for_cond,
 	[ACTION(A_OP_FOR_AFTER)] = op_for_after,
 	[ACTION(A_OP_FOR_END)] = op_for_end,
 	[ACTION(A_OP_WHILE_BEGIN)] = op_while_begin,
 	[ACTION(A_OP_WHILE_COND)] = op_while_cond,
 	[ACTION(A_OP_WHILE_END)] = op_while_end,
 	[ACTION(A_OP_DO_WHILE_BEGIN)] = op_do_while_begin,
 	[ACTION(A_OP_DO_WHILE_COND)] = op_do_while_cond,
 	[ACTION(A_OP_DO_WHILE_END)] = op_do_while_end,
 	[ACTION(A_OP_IF_COND)] = op_if_cond,
 	[ACTION(A_OP_PATCH_REF)] = op_patch_ref,
 	[ACTION(A_OP_TRY_BEGIN)] = op_try_begin,
 	[ACTION(A_OP_THROW)] = op_throw,
 	[ACTION(A_OP_IF_ELSE)] = op_if_else,
 	[ACTION(A_OP_TRY_END)] = op_try_end,
 	[ACTION(A_OP_CATCH)] = op_catch,
 	[ACTION(A_OP_RETURN)] = op_return,
 	[ACTION(A_OP_RETVAL)] = op_retval,
 	[ACTION(A_OP_FUN_DEF)] = op_fun_def,
 	[ACTION(A_OP_ARG_DECL)] = op_arg_decl,
 };

const const char * const microjs_ll_sym[] = {
	"EOF",
 	"DOT",
 	"COMMA",
 	"SEMICOLON",
 	"COLON",
 	"PLUS",
 	"MINUS",
 	"STAR",
 	"SLASH",
 	"PERCENT",
 	"AMPERSAND",
 	"BAR",
 	"CARET",
 	"TILDE",
 	"EXCLAM",
 	"QUEST",
 	"EQUALS",
 	"LESSTHEN",
 	"GREATTHEN",
 	"LBRACKET",
 	"RBRACKET",
 	"LPAREN",
 	"RPAREN",
 	"LBRACE",
 	"RBRACE",
 	"GTE",
 	"LTE",
 	"EQU",
 	"NEQ",
 	"ASR",
 	"SHL",
 	"LOGICOR",
 	"LOGICAND",
 	"CATCH",
 	"ELSE",
 	"FALSE",
 	"FOR",
 	"IF",
 	"THROW",
 	"TRUE",
 	"TRY",
 	"VAR",
 	"WHILE",
 	"ID",
 	"INT",
 	"CHAR",
 	"STRING",
 	"ERR",
 	"CONST",
 	"ADD_EQ",
 	"SUB_EQ",
 	"DIV_EQ",
 	"MOD_EQ",
 	"MUL_EQ",
 	"AND_EQ",
 	"OR_EQ",
 	"XOR_EQ",
 	"SHL_EQ",
 	"ASR_EQ",
 	"NOT",
 	"BREAK",
 	"CONTINUE",
 	"DO",
 	"RETURN",
 	"FUNCTION",
 	"program",
 	"stat",
 	"semi_stat",
 	"semi_list",
 	"compound_stat",
 	"var_list",
 	"var",
 	"var_list1",
 	"var_init_opt",
 	"exp",
 	"assign_or_call1",
 	"additive_exp",
 	"div_exp",
 	"mult_exp",
 	"and_exp",
 	"shift_exp",
 	"function_call",
 	"attr_assign",
 	"attr_assign2",
 	"method_call",
 	"const_list",
 	"const",
 	"const_list1",
 	"const_exp",
 	"arg_list_opt",
 	"arg_list",
 	"arg_list1",
 	"exp_lst_opt",
 	"exp_lst",
 	"exp_lst1",
 	"or_exp",
 	"relational_exp",
 	"and_exp1",
 	"relational_exp1",
 	"shift_exp1",
 	"additive_exp1",
 	"div_exp1",
 	"unary_exp",
 	"mult_exp1",
 	"primary_exp",
 	"id_eval",
 	"id_eval1",
 	"attr_eval",
 	"attr_eval1",
 	"stat_list",
 	"loop_comp_stat",
 	"loop_stat_list",
 	"condition",
 	"else_opt",
 	"catch_opt",
 	"retval_opt",
 	"function_def",
 	"arg_lst_opt",
 	"arg_lst",
 	"arg_opt",
 	"op_var_decl",
 	"op_push_tmp",
 	"op_pop_tmp",
 	"op_var_init",
 	"op_var_assign",
 	"op_var_eval",
 	"op_add",
 	"op_sub",
 	"op_div",
 	"op_mod",
 	"op_mul",
 	"op_and",
 	"op_or",
 	"op_xor",
 	"op_shl",
 	"op_asr",
 	"op_ret_discard",
 	"op_array_xlat",
 	"op_object_get",
 	"op_attr_assign",
 	"op_array_assign",
 	"op_const_decl",
 	"op_const_init",
 	"op_method_lookup",
 	"op_call",
 	"op_function_lookup",
 	"op_arg",
 	"op_logic_or",
 	"op_logic_and",
 	"op_lt",
 	"op_gt",
 	"op_equ",
 	"op_neq",
 	"op_gte",
 	"op_lte",
 	"op_inv",
 	"op_minus",
 	"op_not",
 	"op_push_int",
 	"op_push_string",
 	"op_push_true",
 	"op_push_false",
 	"op_call_ret",
 	"op_attr_eval",
 	"op_array_eval",
 	"op_blk_open",
 	"op_blk_close",
 	"op_loop_break",
 	"op_loop_continue",
 	"op_for_init",
 	"op_for_cond",
 	"op_for_after",
 	"op_for_end",
 	"op_while_begin",
 	"op_while_cond",
 	"op_while_end",
 	"op_do_while_begin",
 	"op_do_while_cond",
 	"op_do_while_end",
 	"op_if_cond",
 	"op_patch_ref",
 	"op_try_begin",
 	"op_throw",
 	"op_if_else",
 	"op_try_end",
 	"op_catch",
 	"op_return",
 	"op_retval",
 	"op_fun_def",
 	"op_arg_decl",
 };

