/* LL(1) Embeddedd Nonrecursive Predictive Parser */

#include "microjs2_ll.h"

/* Token-Rule pair (predict set) */
struct tr_pair {
	uint8_t t;
	uint8_t r;
};

/* Predict sets */
static const struct tr_pair predict_vec[] = {
	/*  68 (program) */
	{  0,  0}, { 23,  3}, { 36,  1}, { 37,  1}, { 38,  2}, { 40,  1}, 
	{ 41,  2}, { 42,  1}, { 44,  2}, { 46,  2}, { 51,  2}, { 65,  1}, 
	/*  69 (stat) */
	{ 36,113}, { 37,116}, { 40,117}, { 42,114}, { 65,115}, 
	/*  70 (semi_stat) */
	{ 38,119}, { 41,120}, { 44,122}, { 46,123}, { 51,121}, 
	/*  71 (semi_list) */
	{  0,  4}, {  3,  5}, 
	/*  72 (compound_stat) */
	{ 23,103}, 
	/*  73 (var_list) */
	{ 43,  6}, 
	/*  74 (var) */
	{ 43,  9}, 
	/*  75 (var_list1) */
	{  0,  7}, {  2,  8}, {  3,  7}, 
	/*  76 (var_init_opt) */
	{  0, 10}, {  2, 10}, {  3, 10}, { 16, 11}, 
	/*  77 (exp) */
	{  6, 51}, { 13, 51}, { 21, 51}, { 35, 51}, { 39, 51}, { 43, 51}, 
	{ 44, 51}, { 45, 51}, { 46, 51}, { 47, 51}, { 48, 51}, { 49, 51}, 
	{ 62, 51}, 
	/*  78 (var_assign) */
	{ 16, 12}, { 52, 13}, { 53, 14}, { 54, 15}, { 55, 16}, { 56, 17}, 
	{ 57, 18}, { 58, 19}, { 59, 20}, { 60, 21}, { 61, 22}, 
	/*  79 (additive_exp) */
	{  6, 72}, { 13, 72}, { 21, 72}, { 35, 72}, { 39, 72}, { 43, 72}, 
	{ 44, 72}, { 45, 72}, { 46, 72}, { 47, 72}, { 48, 72}, { 49, 72}, 
	{ 62, 72}, 
	/*  80 (div_exp) */
	{  6, 76}, { 13, 76}, { 21, 76}, { 35, 76}, { 39, 76}, { 43, 76}, 
	{ 44, 76}, { 45, 76}, { 46, 76}, { 47, 76}, { 48, 76}, { 49, 76}, 
	{ 62, 76}, 
	/*  81 (mult_exp) */
	{  6, 80}, { 13, 80}, { 21, 80}, { 35, 80}, { 39, 80}, { 43, 80}, 
	{ 44, 80}, { 45, 80}, { 46, 80}, { 47, 80}, { 48, 80}, { 49, 80}, 
	{ 62, 80}, 
	/*  82 (and_exp) */
	{  6, 56}, { 13, 56}, { 21, 56}, { 35, 56}, { 39, 56}, { 43, 56}, 
	{ 44, 56}, { 45, 56}, { 46, 56}, { 47, 56}, { 48, 56}, { 49, 56}, 
	{ 62, 56}, 
	/*  83 (shift_exp) */
	{  6, 68}, { 13, 68}, { 21, 68}, { 35, 68}, { 39, 68}, { 43, 68}, 
	{ 44, 68}, { 45, 68}, { 46, 68}, { 47, 68}, { 48, 68}, { 49, 68}, 
	{ 62, 68}, 
	/*  84 (attr_assign1) */
	{  1, 24}, { 19, 23}, 
	/*  85 (attr_assign) */
	{ 43, 25}, 
	/*  86 (attr_assign2) */
	{ 16, 26}, { 19, 27}, { 21, 28}, 
	/*  87 (method_call) */
	{ 21, 39}, 
	/*  88 (const_list) */
	{ 43, 29}, 
	/*  89 (const) */
	{ 43, 32}, 
	/*  90 (const_list1) */
	{  0, 30}, {  2, 31}, {  3, 30}, 
	/*  91 (const_exp) */
	{ 35, 37}, { 39, 36}, { 45, 38}, { 47, 33}, { 48, 34}, { 49, 35}, 
	/*  92 (arg_list_opt) */
	{  6, 42}, { 13, 42}, { 21, 42}, { 22, 41}, { 35, 42}, { 39, 42}, 
	{ 43, 42}, { 44, 42}, { 45, 42}, { 46, 42}, { 47, 42}, { 48, 42}, 
	{ 49, 42}, { 62, 42}, 
	/*  93 (function_call) */
	{ 21, 40}, 
	/*  94 (arg_list) */
	{  6, 43}, { 13, 43}, { 21, 43}, { 35, 43}, { 39, 43}, { 43, 43}, 
	{ 44, 43}, { 45, 43}, { 46, 43}, { 47, 43}, { 48, 43}, { 49, 43}, 
	{ 62, 43}, 
	/*  95 (arg_list1) */
	{  2, 45}, { 22, 44}, 
	/*  96 (exp_lst_opt) */
	{  3, 46}, { 22, 46}, { 44, 47}, 
	/*  97 (exp_lst) */
	{ 44, 48}, 
	/*  98 (exp_lst1) */
	{  2, 50}, {  3, 49}, { 22, 49}, 
	/*  99 (or_exp) */
	{  0, 52}, {  2, 52}, {  3, 52}, { 11, 53}, { 12, 55}, { 20, 52}, 
	{ 22, 52}, { 24, 52}, { 31, 54}, 
	/* 100 (relational_exp) */
	{  6, 60}, { 13, 60}, { 21, 60}, { 35, 60}, { 39, 60}, { 43, 60}, 
	{ 44, 60}, { 45, 60}, { 46, 60}, { 47, 60}, { 48, 60}, { 49, 60}, 
	{ 62, 60}, 
	/* 101 (and_exp1) */
	{  0, 57}, {  2, 57}, {  3, 57}, { 10, 58}, { 11, 57}, { 12, 57}, 
	{ 20, 57}, { 22, 57}, { 24, 57}, { 31, 57}, { 32, 59}, 
	/* 102 (relational_exp1) */
	{  0, 61}, {  2, 61}, {  3, 61}, { 10, 61}, { 11, 61}, { 12, 61}, 
	{ 17, 62}, { 18, 63}, { 20, 61}, { 22, 61}, { 24, 61}, { 25, 66}, 
	{ 26, 67}, { 27, 64}, { 28, 65}, { 31, 61}, { 32, 61}, 
	/* 103 (shift_exp1) */
	{  0, 69}, {  2, 69}, {  3, 69}, { 10, 69}, { 11, 69}, { 12, 69}, 
	{ 17, 69}, { 18, 69}, { 20, 69}, { 22, 69}, { 24, 69}, { 25, 69}, 
	{ 26, 69}, { 27, 69}, { 28, 69}, { 29, 71}, { 30, 70}, { 31, 69}, 
	{ 32, 69}, 
	/* 104 (additive_exp1) */
	{  0, 73}, {  2, 73}, {  3, 73}, {  5, 74}, {  6, 75}, { 10, 73}, 
	{ 11, 73}, { 12, 73}, { 17, 73}, { 18, 73}, { 20, 73}, { 22, 73}, 
	{ 24, 73}, { 25, 73}, { 26, 73}, { 27, 73}, { 28, 73}, { 29, 73}, 
	{ 30, 73}, { 31, 73}, { 32, 73}, 
	/* 105 (div_exp1) */
	{  0, 77}, {  2, 77}, {  3, 77}, {  5, 77}, {  6, 77}, {  8, 78}, 
	{  9, 79}, { 10, 77}, { 11, 77}, { 12, 77}, { 17, 77}, { 18, 77}, 
	{ 20, 77}, { 22, 77}, { 24, 77}, { 25, 77}, { 26, 77}, { 27, 77}, 
	{ 28, 77}, { 29, 77}, { 30, 77}, { 31, 77}, { 32, 77}, 
	/* 106 (unary_exp) */
	{  6, 85}, { 13, 84}, { 21, 83}, { 35, 83}, { 39, 83}, { 43, 83}, 
	{ 44, 83}, { 45, 83}, { 46, 83}, { 47, 83}, { 48, 83}, { 49, 83}, 
	{ 62, 86}, 
	/* 107 (mult_exp1) */
	{  0, 81}, {  2, 81}, {  3, 81}, {  5, 81}, {  6, 81}, {  7, 82}, 
	{  8, 81}, {  9, 81}, { 10, 81}, { 11, 81}, { 12, 81}, { 17, 81}, 
	{ 18, 81}, { 20, 81}, { 22, 81}, { 24, 81}, { 25, 81}, { 26, 81}, 
	{ 27, 81}, { 28, 81}, { 29, 81}, { 30, 81}, { 31, 81}, { 32, 81}, 
	/* 108 (primary_exp) */
	{ 21, 87}, { 35, 92}, { 39, 91}, { 43, 96}, { 44, 93}, { 45, 94}, 
	{ 46, 95}, { 47, 88}, { 48, 89}, { 49, 90}, 
	/* 109 (id_eval1) */
	{  1, 98}, { 19, 97}, 
	/* 110 (attr_eval) */
	{ 43, 99}, 
	/* 111 (attr_eval1) */
	{  0,100}, {  2,100}, {  3,100}, {  5,100}, {  6,100}, {  7,100}, 
	{  8,100}, {  9,100}, { 10,100}, { 11,100}, { 12,100}, { 17,100}, 
	{ 18,100}, { 19,102}, { 20,100}, { 21,101}, { 22,100}, { 24,100}, 
	{ 25,100}, { 26,100}, { 27,100}, { 28,100}, { 29,100}, { 30,100}, 
	{ 31,100}, { 32,100}, 
	/* 112 (stat_list) */
	{ 24,104}, { 36,105}, { 37,105}, { 38,106}, { 40,105}, { 41,106}, 
	{ 42,105}, { 44,106}, { 46,106}, { 51,106}, { 65,105}, 
	/* 113 (loop_comp_stat) */
	{ 23,107}, 
	/* 114 (loop_stat_list) */
	{ 24,108}, { 36,109}, { 37,109}, { 38,110}, { 40,109}, { 41,110}, 
	{ 42,109}, { 44,110}, { 46,110}, { 51,110}, { 63,111}, { 64,112}, 
	{ 65,109}, 
	/* 115 (condition) */
	{ 21,118}, 
	/* 116 (else_opt) */
	{  0,124}, { 23,124}, { 24,124}, { 34,125}, { 36,124}, { 37,124}, 
	{ 38,124}, { 40,124}, { 41,124}, { 42,124}, { 44,124}, { 46,124}, 
	{ 51,124}, { 63,124}, { 64,124}, { 65,124}, { 66,124}, 
	/* 117 (catch_opt) */
	{  0,126}, { 23,126}, { 24,126}, { 33,127}, { 36,126}, { 37,126}, 
	{ 38,126}, { 40,126}, { 41,126}, { 42,126}, { 44,126}, { 46,126}, 
	{ 51,126}, { 63,126}, { 64,126}, { 65,126}, { 66,126}, 
	/* 118 (func_comp_stat) */
	{ 23,128}, 
	/* 119 (func_stat_list) */
	{ 24,129}, { 36,130}, { 37,130}, { 38,131}, { 40,130}, { 41,131}, 
	{ 42,130}, { 44,131}, { 46,131}, { 51,131}, { 65,130}, { 66,132}, 
	/* 120 (retval_opt) */
	{  6,134}, { 13,134}, { 21,134}, { 24,133}, { 35,134}, { 39,134}, 
	{ 43,134}, { 44,134}, { 45,134}, { 46,134}, { 47,134}, { 48,134}, 
	{ 49,134}, { 62,134}, 
	/* 121 (function_def) */
	{ 67,135}, 
	/* 122 (arg_lst_opt) */
	{ 22,136}, { 43,137}, 
	/* 123 (arg_lst) */
	{ 43,138}, 
	/* 124 (arg_opt) */
	{  2,140}, { 22,139}, 
};
/* 920 bytes; */

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
	{  34, 13},
	{  47, 11},
	{  58, 13},
	{  71, 13},
	{  84, 13},
	{  97, 13},
	{ 110, 13},
	{ 123,  2},
	{ 125,  1},
	{ 126,  3},
	{ 129,  1},
	{ 130,  1},
	{ 131,  1},
	{ 132,  3},
	{ 135,  6},
	{ 141, 14},
	{ 155,  1},
	{ 156, 13},
	{ 169,  2},
	{ 171,  3},
	{ 174,  1},
	{ 175,  3},
	{ 178,  9},
	{ 187, 13},
	{ 200, 11},
	{ 211, 17},
	{ 228, 19},
	{ 247, 21},
	{ 268, 23},
	{ 291, 13},
	{ 304, 24},
	{ 328, 10},
	{ 338,  2},
	{ 340,  1},
	{ 341, 26},
	{ 367, 11},
	{ 378,  1},
	{ 379, 13},
	{ 392,  1},
	{ 393, 17},
	{ 410, 17},
	{ 427,  1},
	{ 428, 12},
	{ 440, 14},
	{ 454,  1},
	{ 455,  2},
	{ 457,  1},
	{ 458,  2},
};
/* 228 bytes */

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
	/*  9:var(3) -> */
	T_ID, A_OP_VAR_DECL, N_VAR_INIT_OPT, 
	/* 10:var_init_opt(1) -> */
	A_OP_POP_REF, 
	/* 11:var_init_opt(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_INIT, 
	/* 12:var_assign(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_ASSIGN, 
	/* 13:var_assign(5) -> */
	T_ADD_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_ADD, A_OP_VAR_ASSIGN, 
	/* 14:var_assign(5) -> */
	T_SUB_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_SUB, A_OP_VAR_ASSIGN, 
	/* 15:var_assign(5) -> */
	T_DIV_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_DIV, A_OP_VAR_ASSIGN, 
	/* 16:var_assign(5) -> */
	T_MOD_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_MOD, A_OP_VAR_ASSIGN, 
	/* 17:var_assign(5) -> */
	T_MUL_EQ, A_OP_VAR_EVAL, N_MULT_EXP, A_OP_MUL, A_OP_VAR_ASSIGN, 
	/* 18:var_assign(5) -> */
	T_AND_EQ, A_OP_VAR_EVAL, N_AND_EXP, A_OP_AND, A_OP_VAR_ASSIGN, 
	/* 19:var_assign(5) -> */
	T_OR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_OR, A_OP_VAR_ASSIGN, 
	/* 20:var_assign(5) -> */
	T_XOR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_XOR, A_OP_VAR_ASSIGN, 
	/* 21:var_assign(5) -> */
	T_SHL_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_SHL, A_OP_VAR_ASSIGN, 
	/* 22:var_assign(5) -> */
	T_ASR_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_ASR, A_OP_VAR_ASSIGN, 
	/* 23:attr_assign1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_ASSIGN, 
	/* 24:attr_assign1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_ASSIGN, 
	/* 25:attr_assign(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_ASSIGN2, 
	/* 26:attr_assign2(3) -> */
	T_EQUALS, N_EXP, A_OP_ATTR_ASSIGN, 
	/* 27:attr_assign2(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, T_EQUALS, N_EXP, A_OP_ARRAY_ASSIGN, 
	/* 28:attr_assign2(2) -> */
	N_METHOD_CALL, A_OP_RET_DISCARD, 
	/* 29:const_list(2) -> */
	N_CONST, N_CONST_LIST1, 
	/* 30:const_list1(0) -> */
	
	/* 31:const_list1(2) -> */
	T_COMMA, N_CONST_LIST, 
	/* 32:const(5) -> */
	T_ID, A_OP_CONST_DECL, T_EQUALS, N_CONST_EXP, A_OP_CONST_INIT, 
	/* 33:const_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 34:const_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 35:const_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 36:const_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 37:const_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 38:const_exp(3) -> */
	T_CONST_ID, A_OP_PUSH_REF, A_OP_CONST_EVAL, 
	/* 39:method_call(5) -> */
	A_OP_METHOD_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 40:function_call(5) -> */
	A_OP_FUNCTION_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 41:arg_list_opt(0) -> */
	
	/* 42:arg_list_opt(1) -> */
	N_ARG_LIST, 
	/* 43:arg_list(3) -> */
	N_EXP, A_OP_ARG, N_ARG_LIST1, 
	/* 44:arg_list1(0) -> */
	
	/* 45:arg_list1(2) -> */
	T_COMMA, N_ARG_LIST, 
	/* 46:exp_lst_opt(0) -> */
	
	/* 47:exp_lst_opt(1) -> */
	N_EXP_LST, 
	/* 48:exp_lst(4) -> */
	T_VAR_ID, A_OP_PUSH_REF, N_VAR_ASSIGN, N_EXP_LST1, 
	/* 49:exp_lst1(0) -> */
	
	/* 50:exp_lst1(2) -> */
	T_COMMA, N_EXP_LST, 
	/* 51:exp(2) -> */
	N_AND_EXP, N_OR_EXP, 
	/* 52:or_exp(0) -> */
	
	/* 53:or_exp(3) -> */
	T_BAR, N_EXP, A_OP_OR, 
	/* 54:or_exp(3) -> */
	T_LOGICOR, N_EXP, A_OP_LOGIC_OR, 
	/* 55:or_exp(3) -> */
	T_CARET, N_EXP, A_OP_XOR, 
	/* 56:and_exp(2) -> */
	N_RELATIONAL_EXP, N_AND_EXP1, 
	/* 57:and_exp1(0) -> */
	
	/* 58:and_exp1(3) -> */
	T_AMPERSAND, N_AND_EXP, A_OP_AND, 
	/* 59:and_exp1(3) -> */
	T_LOGICAND, N_AND_EXP, A_OP_LOGIC_AND, 
	/* 60:relational_exp(2) -> */
	N_SHIFT_EXP, N_RELATIONAL_EXP1, 
	/* 61:relational_exp1(0) -> */
	
	/* 62:relational_exp1(3) -> */
	T_LESSTHEN, N_RELATIONAL_EXP, A_OP_LT, 
	/* 63:relational_exp1(3) -> */
	T_GREATTHEN, N_RELATIONAL_EXP, A_OP_GT, 
	/* 64:relational_exp1(3) -> */
	T_EQU, N_RELATIONAL_EXP, A_OP_EQU, 
	/* 65:relational_exp1(3) -> */
	T_NEQ, N_RELATIONAL_EXP, A_OP_NEQ, 
	/* 66:relational_exp1(3) -> */
	T_GTE, N_RELATIONAL_EXP, A_OP_GTE, 
	/* 67:relational_exp1(3) -> */
	T_LTE, N_RELATIONAL_EXP, A_OP_LTE, 
	/* 68:shift_exp(2) -> */
	N_ADDITIVE_EXP, N_SHIFT_EXP1, 
	/* 69:shift_exp1(0) -> */
	
	/* 70:shift_exp1(3) -> */
	T_SHL, N_SHIFT_EXP, A_OP_SHL, 
	/* 71:shift_exp1(3) -> */
	T_ASR, N_SHIFT_EXP, A_OP_ASR, 
	/* 72:additive_exp(2) -> */
	N_DIV_EXP, N_ADDITIVE_EXP1, 
	/* 73:additive_exp1(0) -> */
	
	/* 74:additive_exp1(3) -> */
	T_PLUS, N_ADDITIVE_EXP, A_OP_ADD, 
	/* 75:additive_exp1(3) -> */
	T_MINUS, N_ADDITIVE_EXP, A_OP_SUB, 
	/* 76:div_exp(2) -> */
	N_MULT_EXP, N_DIV_EXP1, 
	/* 77:div_exp1(0) -> */
	
	/* 78:div_exp1(3) -> */
	T_SLASH, N_DIV_EXP, A_OP_DIV, 
	/* 79:div_exp1(3) -> */
	T_PERCENT, N_DIV_EXP, A_OP_MOD, 
	/* 80:mult_exp(2) -> */
	N_UNARY_EXP, N_MULT_EXP1, 
	/* 81:mult_exp1(0) -> */
	
	/* 82:mult_exp1(3) -> */
	T_STAR, N_MULT_EXP, A_OP_MUL, 
	/* 83:unary_exp(1) -> */
	N_PRIMARY_EXP, 
	/* 84:unary_exp(3) -> */
	T_TILDE, N_UNARY_EXP, A_OP_INV, 
	/* 85:unary_exp(3) -> */
	T_MINUS, N_UNARY_EXP, A_OP_MINUS, 
	/* 86:unary_exp(3) -> */
	T_NOT, N_UNARY_EXP, A_OP_NOT, 
	/* 87:primary_exp(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 88:primary_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 89:primary_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 90:primary_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 91:primary_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 92:primary_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 93:primary_exp(3) -> */
	T_VAR_ID, A_OP_PUSH_REF, A_OP_VAR_EVAL, 
	/* 94:primary_exp(3) -> */
	T_CONST_ID, A_OP_PUSH_REF, A_OP_CONST_EVAL, 
	/* 95:primary_exp(4) -> */
	T_FUNC_ID, A_OP_PUSH_REF, N_FUNCTION_CALL, A_OP_RET_VAL, 
	/* 96:primary_exp(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ID_EVAL1, 
	/* 97:id_eval1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_EVAL, 
	/* 98:id_eval1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_EVAL, 
	/* 99:attr_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_EVAL1, 
	/* 100:attr_eval1(1) -> */
	A_OP_ATTR_EVAL, 
	/* 101:attr_eval1(2) -> */
	N_METHOD_CALL, A_OP_RET_VAL, 
	/* 102:attr_eval1(4) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_EVAL, 
	/* 103:compound_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 104:stat_list(0) -> */
	
	/* 105:stat_list(2) -> */
	N_STAT, N_STAT_LIST, 
	/* 106:stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_STAT_LIST, 
	/* 107:loop_comp_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_LOOP_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 108:loop_stat_list(0) -> */
	
	/* 109:loop_stat_list(2) -> */
	N_STAT, N_LOOP_STAT_LIST, 
	/* 110:loop_stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_LOOP_STAT_LIST, 
	/* 111:loop_stat_list(3) -> */
	T_BREAK, T_SEMICOLON, A_OP_LOOP_BREAK, 
	/* 112:loop_stat_list(3) -> */
	T_CONTINUE, T_SEMICOLON, A_OP_LOOP_CONTINUE, 
	/* 113:stat(15) -> */
	T_FOR, A_OP_BLK_OPEN, T_LPAREN, N_EXP_LST_OPT, T_SEMICOLON, A_OP_FOR_INIT, N_EXP, A_OP_FOR_COND, T_SEMICOLON, N_EXP_LST_OPT, A_OP_FOR_AFTER, T_RPAREN, N_LOOP_COMP_STAT, A_OP_FOR_END, A_OP_BLK_CLOSE, 
	/* 114:stat(6) -> */
	T_WHILE, A_OP_WHILE_BEGIN, N_CONDITION, A_OP_WHILE_COND, N_LOOP_COMP_STAT, A_OP_WHILE_END, 
	/* 115:stat(8) -> */
	T_DO, A_OP_DO_WHILE_BEGIN, N_LOOP_COMP_STAT, T_WHILE, N_CONDITION, A_OP_DO_WHILE_COND, A_OP_DO_WHILE_END, T_SEMICOLON, 
	/* 116:stat(6) -> */
	T_IF, N_CONDITION, A_OP_IF_COND, N_COMPOUND_STAT, N_ELSE_OPT, A_OP_PATCH_REF, 
	/* 117:stat(4) -> */
	T_TRY, A_OP_TRY_BEGIN, N_COMPOUND_STAT, N_CATCH_OPT, 
	/* 118:condition(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 119:semi_stat(3) -> */
	T_THROW, N_EXP, A_OP_THROW, 
	/* 120:semi_stat(2) -> */
	T_VAR, N_VAR_LIST, 
	/* 121:semi_stat(2) -> */
	T_CONST, N_CONST_LIST, 
	/* 122:semi_stat(3) -> */
	T_VAR_ID, A_OP_PUSH_REF, N_VAR_ASSIGN, 
	/* 123:semi_stat(4) -> */
	T_FUNC_ID, A_OP_PUSH_REF, N_FUNCTION_CALL, A_OP_RET_DISCARD, 
	/* 124:else_opt(0) -> */
	
	/* 125:else_opt(3) -> */
	T_ELSE, A_OP_IF_ELSE, N_COMPOUND_STAT, 
	/* 126:catch_opt(1) -> */
	A_OP_TRY_END, 
	/* 127:catch_opt(14) -> */
	T_CATCH, A_OP_CATCH, A_OP_BLK_OPEN, T_LPAREN, T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, A_OP_VAR_INIT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, A_OP_PATCH_REF, 
	/* 128:func_comp_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_FUNC_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 129:func_stat_list(0) -> */
	
	/* 130:func_stat_list(2) -> */
	N_STAT, N_FUNC_STAT_LIST, 
	/* 131:func_stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_FUNC_STAT_LIST, 
	/* 132:func_stat_list(2) -> */
	T_RETURN, N_RETVAL_OPT, 
	/* 133:retval_opt(1) -> */
	A_OP_RETURN, 
	/* 134:retval_opt(2) -> */
	N_EXP, A_OP_RETVAL, 
	/* 135:function_def(12) -> */
	T_FUNCTION, T_ID, A_OP_FUN_DEF, A_OP_BLK_OPEN, T_LPAREN, N_ARG_LST_OPT, T_RPAREN, T_LBRACE, N_FUNC_STAT_LIST, T_RBRACE, A_OP_FUN_END, A_OP_PATCH_REF, 
	/* 136:arg_lst_opt(0) -> */
	
	/* 137:arg_lst_opt(1) -> */
	N_ARG_LST, 
	/* 138:arg_lst(3) -> */
	T_ID, A_OP_ARG_DECL, N_ARG_OPT, 
	/* 139:arg_opt(0) -> */
	
	/* 140:arg_opt(2) -> */
	T_COMMA, N_ARG_LST, 
};
/* 398 bytes */

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
	{  14,  3},
	{  17,  1},
	{  18,  3},
	{  21,  3},
	{  24,  5},
	{  29,  5},
	{  34,  5},
	{  39,  5},
	{  44,  5},
	{  49,  5},
	{  54,  5},
	{  59,  5},
	{  64,  5},
	{  69,  5},
	{  74,  6},
	{  80,  3},
	{  83,  3},
	{  86,  3},
	{  89,  6},
	{  95,  2},
	{  97,  2},
	{  99,  0},
	{  99,  2},
	{ 101,  5},
	{ 106,  2},
	{ 108,  2},
	{ 110,  2},
	{ 112,  2},
	{ 114,  2},
	{ 116,  3},
	{ 119,  5},
	{ 124,  5},
	{ 129,  0},
	{ 129,  1},
	{ 130,  3},
	{ 133,  0},
	{ 133,  2},
	{ 135,  0},
	{ 135,  1},
	{ 136,  4},
	{ 140,  0},
	{ 140,  2},
	{ 142,  2},
	{ 144,  0},
	{ 144,  3},
	{ 147,  3},
	{ 150,  3},
	{ 153,  2},
	{ 155,  0},
	{ 155,  3},
	{ 158,  3},
	{ 161,  2},
	{ 163,  0},
	{ 163,  3},
	{ 166,  3},
	{ 169,  3},
	{ 172,  3},
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
	{ 202,  3},
	{ 205,  2},
	{ 207,  0},
	{ 207,  3},
	{ 210,  1},
	{ 211,  3},
	{ 214,  3},
	{ 217,  3},
	{ 220,  3},
	{ 223,  2},
	{ 225,  2},
	{ 227,  2},
	{ 229,  2},
	{ 231,  2},
	{ 233,  3},
	{ 236,  3},
	{ 239,  4},
	{ 243,  3},
	{ 246,  6},
	{ 252,  3},
	{ 255,  3},
	{ 258,  1},
	{ 259,  2},
	{ 261,  4},
	{ 265,  5},
	{ 270,  0},
	{ 270,  2},
	{ 272,  3},
	{ 275,  5},
	{ 280,  0},
	{ 280,  2},
	{ 282,  3},
	{ 285,  3},
	{ 288,  3},
	{ 291, 15},
	{ 306,  6},
	{ 312,  8},
	{ 320,  6},
	{ 326,  4},
	{ 330,  3},
	{ 333,  3},
	{ 336,  2},
	{ 338,  2},
	{ 340,  3},
	{ 343,  4},
	{ 347,  0},
	{ 347,  3},
	{ 350,  1},
	{ 351, 14},
	{ 365,  5},
	{ 370,  0},
	{ 370,  2},
	{ 372,  3},
	{ 375,  2},
	{ 377,  1},
	{ 378,  2},
	{ 380, 12},
	{ 392,  0},
	{ 392,  1},
	{ 393,  3},
	{ 396,  0},
	{ 396,  2},
};
/* 564 bytes */

/* Total: 2110 bytes */


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
extern int op_pop_ref(void * arg);
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
extern int op_array_xlat(void * arg);
extern int op_object_get(void * arg);
extern int op_push_tmp(void * arg);
extern int op_attr_assign(void * arg);
extern int op_array_assign(void * arg);
extern int op_ret_discard(void * arg);
extern int op_const_decl(void * arg);
extern int op_const_init(void * arg);
extern int op_push_int(void * arg);
extern int op_push_string(void * arg);
extern int op_push_true(void * arg);
extern int op_push_false(void * arg);
extern int op_push_ref(void * arg);
extern int op_const_eval(void * arg);
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
extern int op_ret_val(void * arg);
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
extern int op_fun_end(void * arg);
extern int op_arg_decl(void * arg);


/* Syntax action callback lookup table */
int (* const microjs_ll_op[])(void *) = {
	[ACTION(A_OP_VAR_DECL)] = op_var_decl,
 	[ACTION(A_OP_POP_REF)] = op_pop_ref,
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
 	[ACTION(A_OP_ARRAY_XLAT)] = op_array_xlat,
 	[ACTION(A_OP_OBJECT_GET)] = op_object_get,
 	[ACTION(A_OP_PUSH_TMP)] = op_push_tmp,
 	[ACTION(A_OP_ATTR_ASSIGN)] = op_attr_assign,
 	[ACTION(A_OP_ARRAY_ASSIGN)] = op_array_assign,
 	[ACTION(A_OP_RET_DISCARD)] = op_ret_discard,
 	[ACTION(A_OP_CONST_DECL)] = op_const_decl,
 	[ACTION(A_OP_CONST_INIT)] = op_const_init,
 	[ACTION(A_OP_PUSH_INT)] = op_push_int,
 	[ACTION(A_OP_PUSH_STRING)] = op_push_string,
 	[ACTION(A_OP_PUSH_TRUE)] = op_push_true,
 	[ACTION(A_OP_PUSH_FALSE)] = op_push_false,
 	[ACTION(A_OP_PUSH_REF)] = op_push_ref,
 	[ACTION(A_OP_CONST_EVAL)] = op_const_eval,
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
 	[ACTION(A_OP_RET_VAL)] = op_ret_val,
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
 	[ACTION(A_OP_FUN_END)] = op_fun_end,
 	[ACTION(A_OP_ARG_DECL)] = op_arg_decl,
 };

const char * const microjs_ll_sym[] = {
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
 	"VAR_ID",
 	"CONST_ID",
 	"FUNC_ID",
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
 	"var_assign",
 	"additive_exp",
 	"div_exp",
 	"mult_exp",
 	"and_exp",
 	"shift_exp",
 	"attr_assign1",
 	"attr_assign",
 	"attr_assign2",
 	"method_call",
 	"const_list",
 	"const",
 	"const_list1",
 	"const_exp",
 	"arg_list_opt",
 	"function_call",
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
 	"id_eval1",
 	"attr_eval",
 	"attr_eval1",
 	"stat_list",
 	"loop_comp_stat",
 	"loop_stat_list",
 	"condition",
 	"else_opt",
 	"catch_opt",
 	"func_comp_stat",
 	"func_stat_list",
 	"retval_opt",
 	"function_def",
 	"arg_lst_opt",
 	"arg_lst",
 	"arg_opt",
 	"op_var_decl",
 	"op_pop_ref",
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
 	"op_array_xlat",
 	"op_object_get",
 	"op_push_tmp",
 	"op_attr_assign",
 	"op_array_assign",
 	"op_ret_discard",
 	"op_const_decl",
 	"op_const_init",
 	"op_push_int",
 	"op_push_string",
 	"op_push_true",
 	"op_push_false",
 	"op_push_ref",
 	"op_const_eval",
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
 	"op_ret_val",
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
 	"op_fun_end",
 	"op_arg_decl",
 };

