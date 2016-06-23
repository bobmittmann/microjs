/* LL(1) Embeddedd Nonrecursive Predictive Parser */

#include "microjs2_ll.h"

/* Token-Rule pair (predict set) */
struct tr_pair {
	uint8_t t;
	uint8_t r;
};

/* Predict sets */
static const struct tr_pair predict_vec[] = {
	/*  51 (program) */
	{  0,  0}, { 23,  3}, { 36,  1}, { 37,  1}, { 38,  2}, { 40,  1}, 
	{ 41,  2}, { 42,  1}, { 43,  2}, { 49,  2}, { 50,  4}, 
	/*  52 (stat) */
	{ 36, 89}, { 37, 91}, { 40, 92}, { 42, 90}, 
	/*  53 (semi_stat) */
	{ 38, 94}, { 41, 95}, { 43, 97}, { 49, 96}, 
	/*  54 (semi_list) */
	{  0,  5}, {  3,  6}, 
	/*  55 (compound_stat) */
	{ 23, 85}, 
	/*  56 (function_def) */
	{ 50,104}, 
	/*  57 (var_list) */
	{ 43,  7}, 
	/*  58 (var) */
	{ 43, 10}, 
	/*  59 (var_list1) */
	{  0,  8}, {  2,  9}, {  3,  8}, 
	/*  60 (var_init_opt) */
	{  0, 11}, {  2, 11}, {  3, 11}, { 16, 12}, 
	/*  61 (exp) */
	{  6, 33}, { 13, 33}, { 21, 33}, { 35, 33}, { 39, 33}, { 43, 33}, 
	{ 44, 33}, { 45, 33}, { 46, 33}, { 48, 33}, 
	/*  62 (assign_or_call1) */
	{  1, 16}, { 16, 13}, { 19, 15}, { 21, 14}, 
	/*  63 (function_call) */
	{ 21, 22}, 
	/*  64 (attr_assign) */
	{ 43, 17}, 
	/*  65 (attr_assign2) */
	{ 16, 18}, { 19, 19}, { 21, 20}, 
	/*  66 (method_call) */
	{ 21, 21}, 
	/*  67 (arg_list_opt) */
	{  6, 24}, { 13, 24}, { 21, 24}, { 22, 23}, { 35, 24}, { 39, 24}, 
	{ 43, 24}, { 44, 24}, { 45, 24}, { 46, 24}, { 48, 24}, 
	/*  68 (arg_list) */
	{  6, 25}, { 13, 25}, { 21, 25}, { 35, 25}, { 39, 25}, { 43, 25}, 
	{ 44, 25}, { 45, 25}, { 46, 25}, { 48, 25}, 
	/*  69 (arg_list1) */
	{  2, 27}, { 22, 26}, 
	/*  70 (exp_lst_opt) */
	{  3, 28}, { 22, 28}, { 43, 29}, 
	/*  71 (exp_lst) */
	{ 43, 30}, 
	/*  72 (exp_lst1) */
	{  2, 32}, {  3, 31}, { 22, 31}, 
	/*  73 (and_exp) */
	{  6, 38}, { 13, 38}, { 21, 38}, { 35, 38}, { 39, 38}, { 43, 38}, 
	{ 44, 38}, { 45, 38}, { 46, 38}, { 48, 38}, 
	/*  74 (or_exp) */
	{  0, 34}, {  2, 34}, {  3, 34}, { 11, 35}, { 12, 37}, { 20, 34}, 
	{ 22, 34}, { 31, 36}, 
	/*  75 (relational_exp) */
	{  6, 42}, { 13, 42}, { 21, 42}, { 35, 42}, { 39, 42}, { 43, 42}, 
	{ 44, 42}, { 45, 42}, { 46, 42}, { 48, 42}, 
	/*  76 (and_exp1) */
	{  0, 39}, {  2, 39}, {  3, 39}, { 10, 40}, { 11, 39}, { 12, 39}, 
	{ 20, 39}, { 22, 39}, { 31, 39}, { 32, 41}, 
	/*  77 (shift_exp) */
	{  6, 50}, { 13, 50}, { 21, 50}, { 35, 50}, { 39, 50}, { 43, 50}, 
	{ 44, 50}, { 45, 50}, { 46, 50}, { 48, 50}, 
	/*  78 (relational_exp1) */
	{  0, 43}, {  2, 43}, {  3, 43}, { 10, 43}, { 11, 43}, { 12, 43}, 
	{ 17, 44}, { 18, 45}, { 20, 43}, { 22, 43}, { 25, 48}, { 26, 49}, 
	{ 27, 46}, { 28, 47}, { 31, 43}, { 32, 43}, 
	/*  79 (additive_exp) */
	{  6, 54}, { 13, 54}, { 21, 54}, { 35, 54}, { 39, 54}, { 43, 54}, 
	{ 44, 54}, { 45, 54}, { 46, 54}, { 48, 54}, 
	/*  80 (shift_exp1) */
	{  0, 51}, {  2, 51}, {  3, 51}, { 10, 51}, { 11, 51}, { 12, 51}, 
	{ 17, 51}, { 18, 51}, { 20, 51}, { 22, 51}, { 25, 51}, { 26, 51}, 
	{ 27, 51}, { 28, 51}, { 29, 53}, { 30, 52}, { 31, 51}, { 32, 51}, 
	/*  81 (div_exp) */
	{  6, 58}, { 13, 58}, { 21, 58}, { 35, 58}, { 39, 58}, { 43, 58}, 
	{ 44, 58}, { 45, 58}, { 46, 58}, { 48, 58}, 
	/*  82 (additive_exp1) */
	{  0, 55}, {  2, 55}, {  3, 55}, {  5, 56}, {  6, 57}, { 10, 55}, 
	{ 11, 55}, { 12, 55}, { 17, 55}, { 18, 55}, { 20, 55}, { 22, 55}, 
	{ 25, 55}, { 26, 55}, { 27, 55}, { 28, 55}, { 29, 55}, { 30, 55}, 
	{ 31, 55}, { 32, 55}, 
	/*  83 (mult_exp) */
	{  6, 62}, { 13, 62}, { 21, 62}, { 35, 62}, { 39, 62}, { 43, 62}, 
	{ 44, 62}, { 45, 62}, { 46, 62}, { 48, 62}, 
	/*  84 (div_exp1) */
	{  0, 59}, {  2, 59}, {  3, 59}, {  5, 59}, {  6, 59}, {  8, 60}, 
	{  9, 61}, { 10, 59}, { 11, 59}, { 12, 59}, { 17, 59}, { 18, 59}, 
	{ 20, 59}, { 22, 59}, { 25, 59}, { 26, 59}, { 27, 59}, { 28, 59}, 
	{ 29, 59}, { 30, 59}, { 31, 59}, { 32, 59}, 
	/*  85 (unary_exp) */
	{  6, 67}, { 13, 66}, { 21, 65}, { 35, 65}, { 39, 65}, { 43, 65}, 
	{ 44, 65}, { 45, 65}, { 46, 65}, { 48, 68}, 
	/*  86 (mult_exp1) */
	{  0, 63}, {  2, 63}, {  3, 63}, {  5, 63}, {  6, 63}, {  7, 64}, 
	{  8, 63}, {  9, 63}, { 10, 63}, { 11, 63}, { 12, 63}, { 17, 63}, 
	{ 18, 63}, { 20, 63}, { 22, 63}, { 25, 63}, { 26, 63}, { 27, 63}, 
	{ 28, 63}, { 29, 63}, { 30, 63}, { 31, 63}, { 32, 63}, 
	/*  87 (primary_exp) */
	{ 21, 69}, { 35, 74}, { 39, 73}, { 43, 75}, { 44, 70}, { 45, 71}, 
	{ 46, 72}, 
	/*  88 (id_eval) */
	{ 43, 76}, 
	/*  89 (id_eval1) */
	{  0, 77}, {  1, 80}, {  2, 77}, {  3, 77}, {  5, 77}, {  6, 77}, 
	{  7, 77}, {  8, 77}, {  9, 77}, { 10, 77}, { 11, 77}, { 12, 77}, 
	{ 17, 77}, { 18, 77}, { 19, 79}, { 20, 77}, { 21, 78}, { 22, 77}, 
	{ 25, 77}, { 26, 77}, { 27, 77}, { 28, 77}, { 29, 77}, { 30, 77}, 
	{ 31, 77}, { 32, 77}, 
	/*  90 (attr_eval) */
	{ 43, 81}, 
	/*  91 (attr_eval1) */
	{  0, 82}, {  2, 82}, {  3, 82}, {  5, 82}, {  6, 82}, {  7, 82}, 
	{  8, 82}, {  9, 82}, { 10, 82}, { 11, 82}, { 12, 82}, { 17, 82}, 
	{ 18, 82}, { 19, 84}, { 20, 82}, { 21, 83}, { 22, 82}, { 25, 82}, 
	{ 26, 82}, { 27, 82}, { 28, 82}, { 29, 82}, { 30, 82}, { 31, 82}, 
	{ 32, 82}, 
	/*  92 (stat_list) */
	{ 24, 86}, { 36, 87}, { 37, 87}, { 38, 88}, { 40, 87}, { 41, 88}, 
	{ 42, 87}, { 43, 88}, { 49, 88}, 
	/*  93 (condition) */
	{ 21, 93}, 
	/*  94 (else_opt) */
	{  0, 98}, { 23, 98}, { 24, 98}, { 34, 99}, { 36, 98}, { 37, 98}, 
	{ 38, 98}, { 40, 98}, { 41, 98}, { 42, 98}, { 43, 98}, { 49, 98}, 
	{ 50, 98}, 
	/*  95 (catch_opt) */
	{  0,100}, { 23,100}, { 24,100}, { 33,101}, { 36,100}, { 37,100}, 
	{ 38,100}, { 40,100}, { 41,100}, { 42,100}, { 43,100}, { 49,100}, 
	{ 50,100}, 
	/*  96 (retval_opt) */
	{  0,102}, {  3,102}, {  6,103}, { 13,103}, { 21,103}, { 35,103}, 
	{ 39,103}, { 43,103}, { 44,103}, { 45,103}, { 46,103}, { 48,103}, 
	/*  97 (arg_lst_opt) */
	{ 22,105}, { 43,106}, 
	/*  98 (arg_lst) */
	{ 43,107}, 
	/*  99 (arg_opt) */
	{  2,109}, { 22,108}, 
};
/* 764 bytes; */

static const struct {
	uint16_t off;
	uint8_t cnt;
} predict_idx[] = {
	{   0, 11},
	{  11,  4},
	{  15,  4},
	{  19,  2},
	{  21,  1},
	{  22,  1},
	{  23,  1},
	{  24,  1},
	{  25,  3},
	{  28,  4},
	{  32, 10},
	{  42,  4},
	{  46,  1},
	{  47,  1},
	{  48,  3},
	{  51,  1},
	{  52, 11},
	{  63, 10},
	{  73,  2},
	{  75,  3},
	{  78,  1},
	{  79,  3},
	{  82, 10},
	{  92,  8},
	{ 100, 10},
	{ 110, 10},
	{ 120, 10},
	{ 130, 16},
	{ 146, 10},
	{ 156, 18},
	{ 174, 10},
	{ 184, 20},
	{ 204, 10},
	{ 214, 22},
	{ 236, 10},
	{ 246, 23},
	{ 269,  7},
	{ 276,  1},
	{ 277, 26},
	{ 303,  1},
	{ 304, 25},
	{ 329,  9},
	{ 338,  1},
	{ 339, 13},
	{ 352, 13},
	{ 365, 12},
	{ 377,  2},
	{ 379,  1},
	{ 380,  2},
};
/* 196 bytes */

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
	/*  4:program(2) -> */
	N_FUNCTION_DEF, N_PROGRAM, 
	/*  5:semi_list(1) -> */
	T_EOF, 
	/*  6:semi_list(2) -> */
	T_SEMICOLON, N_PROGRAM, 
	/*  7:var_list(2) -> */
	N_VAR, N_VAR_LIST1, 
	/*  8:var_list1(0) -> */
	
	/*  9:var_list1(2) -> */
	T_COMMA, N_VAR_LIST, 
	/* 10:var(4) -> */
	T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, N_VAR_INIT_OPT, 
	/* 11:var_init_opt(1) -> */
	A_OP_POP_TMP, 
	/* 12:var_init_opt(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_INIT, 
	/* 13:assign_or_call1(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_ASSIGN, 
	/* 14:assign_or_call1(2) -> */
	N_FUNCTION_CALL, A_OP_RET_DISCARD, 
	/* 15:assign_or_call1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_ASSIGN, 
	/* 16:assign_or_call1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_ASSIGN, 
	/* 17:attr_assign(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_ASSIGN2, 
	/* 18:attr_assign2(3) -> */
	T_EQUALS, N_EXP, A_OP_ATTR_ASSIGN, 
	/* 19:attr_assign2(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, T_EQUALS, N_EXP, A_OP_ARRAY_ASSIGN, 
	/* 20:attr_assign2(2) -> */
	N_METHOD_CALL, A_OP_RET_DISCARD, 
	/* 21:method_call(5) -> */
	A_OP_METHOD_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 22:function_call(5) -> */
	A_OP_FUNCTION_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 23:arg_list_opt(0) -> */
	
	/* 24:arg_list_opt(1) -> */
	N_ARG_LIST, 
	/* 25:arg_list(3) -> */
	N_EXP, A_OP_ARG, N_ARG_LIST1, 
	/* 26:arg_list1(0) -> */
	
	/* 27:arg_list1(2) -> */
	T_COMMA, N_ARG_LIST, 
	/* 28:exp_lst_opt(0) -> */
	
	/* 29:exp_lst_opt(1) -> */
	N_EXP_LST, 
	/* 30:exp_lst(4) -> */
	T_ID, A_OP_PUSH_TMP, N_ASSIGN_OR_CALL1, N_EXP_LST1, 
	/* 31:exp_lst1(0) -> */
	
	/* 32:exp_lst1(2) -> */
	T_COMMA, N_EXP_LST, 
	/* 33:exp(2) -> */
	N_AND_EXP, N_OR_EXP, 
	/* 34:or_exp(0) -> */
	
	/* 35:or_exp(3) -> */
	T_BAR, N_EXP, A_OP_OR, 
	/* 36:or_exp(3) -> */
	T_LOGICOR, N_EXP, A_OP_LOGIC_OR, 
	/* 37:or_exp(3) -> */
	T_CARET, N_EXP, A_OP_XOR, 
	/* 38:and_exp(2) -> */
	N_RELATIONAL_EXP, N_AND_EXP1, 
	/* 39:and_exp1(0) -> */
	
	/* 40:and_exp1(3) -> */
	T_AMPERSAND, N_AND_EXP, A_OP_AND, 
	/* 41:and_exp1(3) -> */
	T_LOGICAND, N_AND_EXP, A_OP_LOGIC_AND, 
	/* 42:relational_exp(2) -> */
	N_SHIFT_EXP, N_RELATIONAL_EXP1, 
	/* 43:relational_exp1(0) -> */
	
	/* 44:relational_exp1(3) -> */
	T_LESSTHEN, N_RELATIONAL_EXP, A_OP_LT, 
	/* 45:relational_exp1(3) -> */
	T_GREATTHEN, N_RELATIONAL_EXP, A_OP_GT, 
	/* 46:relational_exp1(3) -> */
	T_EQU, N_RELATIONAL_EXP, A_OP_EQU, 
	/* 47:relational_exp1(3) -> */
	T_NEQ, N_RELATIONAL_EXP, A_OP_NEQ, 
	/* 48:relational_exp1(3) -> */
	T_GTE, N_RELATIONAL_EXP, A_OP_GTE, 
	/* 49:relational_exp1(3) -> */
	T_LTE, N_RELATIONAL_EXP, A_OP_LTE, 
	/* 50:shift_exp(2) -> */
	N_ADDITIVE_EXP, N_SHIFT_EXP1, 
	/* 51:shift_exp1(0) -> */
	
	/* 52:shift_exp1(3) -> */
	T_SHL, N_SHIFT_EXP, A_OP_SHL, 
	/* 53:shift_exp1(3) -> */
	T_ASR, N_SHIFT_EXP, A_OP_ASR, 
	/* 54:additive_exp(2) -> */
	N_DIV_EXP, N_ADDITIVE_EXP1, 
	/* 55:additive_exp1(0) -> */
	
	/* 56:additive_exp1(3) -> */
	T_PLUS, N_ADDITIVE_EXP, A_OP_ADD, 
	/* 57:additive_exp1(3) -> */
	T_MINUS, N_ADDITIVE_EXP, A_OP_SUB, 
	/* 58:div_exp(2) -> */
	N_MULT_EXP, N_DIV_EXP1, 
	/* 59:div_exp1(0) -> */
	
	/* 60:div_exp1(3) -> */
	T_SLASH, N_DIV_EXP, A_OP_DIV, 
	/* 61:div_exp1(3) -> */
	T_PERCENT, N_DIV_EXP, A_OP_MOD, 
	/* 62:mult_exp(2) -> */
	N_UNARY_EXP, N_MULT_EXP1, 
	/* 63:mult_exp1(0) -> */
	
	/* 64:mult_exp1(3) -> */
	T_STAR, N_MULT_EXP, A_OP_MUL, 
	/* 65:unary_exp(1) -> */
	N_PRIMARY_EXP, 
	/* 66:unary_exp(3) -> */
	T_TILDE, N_UNARY_EXP, A_OP_INV, 
	/* 67:unary_exp(3) -> */
	T_MINUS, N_UNARY_EXP, A_OP_MINUS, 
	/* 68:unary_exp(3) -> */
	T_NOT, N_UNARY_EXP, A_OP_NOT, 
	/* 69:primary_exp(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 70:primary_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 71:primary_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 72:primary_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 73:primary_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 74:primary_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 75:primary_exp(1) -> */
	N_ID_EVAL, 
	/* 76:id_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ID_EVAL1, 
	/* 77:id_eval1(1) -> */
	A_OP_VAR_EVAL, 
	/* 78:id_eval1(2) -> */
	N_FUNCTION_CALL, A_OP_CALL_RET, 
	/* 79:id_eval1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_EVAL, 
	/* 80:id_eval1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_EVAL, 
	/* 81:attr_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_EVAL1, 
	/* 82:attr_eval1(1) -> */
	A_OP_ATTR_EVAL, 
	/* 83:attr_eval1(2) -> */
	N_METHOD_CALL, A_OP_CALL_RET, 
	/* 84:attr_eval1(4) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_EVAL, 
	/* 85:compound_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 86:stat_list(0) -> */
	
	/* 87:stat_list(2) -> */
	N_STAT, N_STAT_LIST, 
	/* 88:stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_STAT_LIST, 
	/* 89:stat(13) -> */
	T_FOR, T_LPAREN, N_EXP_LST_OPT, T_SEMICOLON, A_OP_FOR_INIT, N_EXP, A_OP_FOR_COND, T_SEMICOLON, N_EXP_LST_OPT, A_OP_FOR_AFTER, T_RPAREN, N_COMPOUND_STAT, A_OP_FOR_END, 
	/* 90:stat(6) -> */
	T_WHILE, A_OP_WHILE_BEGIN, N_CONDITION, A_OP_WHILE_COND, N_COMPOUND_STAT, A_OP_WHILE_END, 
	/* 91:stat(6) -> */
	T_IF, N_CONDITION, A_OP_IF_COND, N_COMPOUND_STAT, N_ELSE_OPT, A_OP_PATCH_REF, 
	/* 92:stat(4) -> */
	T_TRY, A_OP_TRY_BEGIN, N_COMPOUND_STAT, N_CATCH_OPT, 
	/* 93:condition(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 94:semi_stat(3) -> */
	T_THROW, N_EXP, A_OP_THROW, 
	/* 95:semi_stat(2) -> */
	T_VAR, N_VAR_LIST, 
	/* 96:semi_stat(2) -> */
	T_RETURN, N_RETVAL_OPT, 
	/* 97:semi_stat(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ASSIGN_OR_CALL1, 
	/* 98:else_opt(0) -> */
	
	/* 99:else_opt(3) -> */
	T_ELSE, A_OP_IF_ELSE, N_COMPOUND_STAT, 
	/* 100:catch_opt(1) -> */
	A_OP_TRY_END, 
	/* 101:catch_opt(14) -> */
	T_CATCH, A_OP_CATCH, A_OP_BLK_OPEN, T_LPAREN, T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, A_OP_VAR_INIT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, A_OP_PATCH_REF, 
	/* 102:retval_opt(0) -> */
	
	/* 103:retval_opt(2) -> */
	N_EXP, A_OP_RETVAL, 
	/* 104:function_def(12) -> */
	T_FUNCTION, T_ID, A_OP_FUN_DEF, A_OP_BLK_OPEN, T_LPAREN, N_ARG_LST_OPT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, A_OP_PATCH_REF, 
	/* 105:arg_lst_opt(0) -> */
	
	/* 106:arg_lst_opt(1) -> */
	N_ARG_LST, 
	/* 107:arg_lst(3) -> */
	T_ID, A_OP_ARG_DECL, N_ARG_OPT, 
	/* 108:arg_opt(0) -> */
	
	/* 109:arg_opt(2) -> */
	T_COMMA, N_ARG_LST, 
};
/* 282 bytes */

static const struct {
	uint16_t off;
	uint8_t cnt;
} rule_idx[] = {
	{   0,  1},
	{   1,  2},
	{   3,  2},
	{   5,  2},
	{   7,  2},
	{   9,  1},
	{  10,  2},
	{  12,  2},
	{  14,  0},
	{  14,  2},
	{  16,  4},
	{  20,  1},
	{  21,  3},
	{  24,  3},
	{  27,  2},
	{  29,  6},
	{  35,  3},
	{  38,  3},
	{  41,  3},
	{  44,  6},
	{  50,  2},
	{  52,  5},
	{  57,  5},
	{  62,  0},
	{  62,  1},
	{  63,  3},
	{  66,  0},
	{  66,  2},
	{  68,  0},
	{  68,  1},
	{  69,  4},
	{  73,  0},
	{  73,  2},
	{  75,  2},
	{  77,  0},
	{  77,  3},
	{  80,  3},
	{  83,  3},
	{  86,  2},
	{  88,  0},
	{  88,  3},
	{  91,  3},
	{  94,  2},
	{  96,  0},
	{  96,  3},
	{  99,  3},
	{ 102,  3},
	{ 105,  3},
	{ 108,  3},
	{ 111,  3},
	{ 114,  2},
	{ 116,  0},
	{ 116,  3},
	{ 119,  3},
	{ 122,  2},
	{ 124,  0},
	{ 124,  3},
	{ 127,  3},
	{ 130,  2},
	{ 132,  0},
	{ 132,  3},
	{ 135,  3},
	{ 138,  2},
	{ 140,  0},
	{ 140,  3},
	{ 143,  1},
	{ 144,  3},
	{ 147,  3},
	{ 150,  3},
	{ 153,  3},
	{ 156,  2},
	{ 158,  2},
	{ 160,  2},
	{ 162,  2},
	{ 164,  2},
	{ 166,  1},
	{ 167,  3},
	{ 170,  1},
	{ 171,  2},
	{ 173,  6},
	{ 179,  3},
	{ 182,  3},
	{ 185,  1},
	{ 186,  2},
	{ 188,  4},
	{ 192,  5},
	{ 197,  0},
	{ 197,  2},
	{ 199,  3},
	{ 202, 13},
	{ 215,  6},
	{ 221,  6},
	{ 227,  4},
	{ 231,  3},
	{ 234,  3},
	{ 237,  2},
	{ 239,  2},
	{ 241,  3},
	{ 244,  0},
	{ 244,  3},
	{ 247,  1},
	{ 248, 14},
	{ 262,  0},
	{ 262,  2},
	{ 264, 12},
	{ 276,  0},
	{ 276,  1},
	{ 277,  3},
	{ 280,  0},
	{ 280,  2},
};
/* 440 bytes */

/* Total: 1682 bytes */


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
extern int op_ret_discard(void * arg);
extern int op_array_xlat(void * arg);
extern int op_object_get(void * arg);
extern int op_attr_assign(void * arg);
extern int op_array_assign(void * arg);
extern int op_method_lookup(void * arg);
extern int op_call(void * arg);
extern int op_function_lookup(void * arg);
extern int op_arg(void * arg);
extern int op_or(void * arg);
extern int op_logic_or(void * arg);
extern int op_xor(void * arg);
extern int op_and(void * arg);
extern int op_logic_and(void * arg);
extern int op_lt(void * arg);
extern int op_gt(void * arg);
extern int op_equ(void * arg);
extern int op_neq(void * arg);
extern int op_gte(void * arg);
extern int op_lte(void * arg);
extern int op_shl(void * arg);
extern int op_asr(void * arg);
extern int op_add(void * arg);
extern int op_sub(void * arg);
extern int op_div(void * arg);
extern int op_mod(void * arg);
extern int op_mul(void * arg);
extern int op_inv(void * arg);
extern int op_minus(void * arg);
extern int op_not(void * arg);
extern int op_push_int(void * arg);
extern int op_push_string(void * arg);
extern int op_push_true(void * arg);
extern int op_push_false(void * arg);
extern int op_var_eval(void * arg);
extern int op_call_ret(void * arg);
extern int op_attr_eval(void * arg);
extern int op_array_eval(void * arg);
extern int op_blk_open(void * arg);
extern int op_blk_close(void * arg);
extern int op_for_init(void * arg);
extern int op_for_cond(void * arg);
extern int op_for_after(void * arg);
extern int op_for_end(void * arg);
extern int op_while_begin(void * arg);
extern int op_while_cond(void * arg);
extern int op_while_end(void * arg);
extern int op_if_cond(void * arg);
extern int op_patch_ref(void * arg);
extern int op_try_begin(void * arg);
extern int op_throw(void * arg);
extern int op_if_else(void * arg);
extern int op_try_end(void * arg);
extern int op_catch(void * arg);
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
 	[ACTION(A_OP_RET_DISCARD)] = op_ret_discard,
 	[ACTION(A_OP_ARRAY_XLAT)] = op_array_xlat,
 	[ACTION(A_OP_OBJECT_GET)] = op_object_get,
 	[ACTION(A_OP_ATTR_ASSIGN)] = op_attr_assign,
 	[ACTION(A_OP_ARRAY_ASSIGN)] = op_array_assign,
 	[ACTION(A_OP_METHOD_LOOKUP)] = op_method_lookup,
 	[ACTION(A_OP_CALL)] = op_call,
 	[ACTION(A_OP_FUNCTION_LOOKUP)] = op_function_lookup,
 	[ACTION(A_OP_ARG)] = op_arg,
 	[ACTION(A_OP_OR)] = op_or,
 	[ACTION(A_OP_LOGIC_OR)] = op_logic_or,
 	[ACTION(A_OP_XOR)] = op_xor,
 	[ACTION(A_OP_AND)] = op_and,
 	[ACTION(A_OP_LOGIC_AND)] = op_logic_and,
 	[ACTION(A_OP_LT)] = op_lt,
 	[ACTION(A_OP_GT)] = op_gt,
 	[ACTION(A_OP_EQU)] = op_equ,
 	[ACTION(A_OP_NEQ)] = op_neq,
 	[ACTION(A_OP_GTE)] = op_gte,
 	[ACTION(A_OP_LTE)] = op_lte,
 	[ACTION(A_OP_SHL)] = op_shl,
 	[ACTION(A_OP_ASR)] = op_asr,
 	[ACTION(A_OP_ADD)] = op_add,
 	[ACTION(A_OP_SUB)] = op_sub,
 	[ACTION(A_OP_DIV)] = op_div,
 	[ACTION(A_OP_MOD)] = op_mod,
 	[ACTION(A_OP_MUL)] = op_mul,
 	[ACTION(A_OP_INV)] = op_inv,
 	[ACTION(A_OP_MINUS)] = op_minus,
 	[ACTION(A_OP_NOT)] = op_not,
 	[ACTION(A_OP_PUSH_INT)] = op_push_int,
 	[ACTION(A_OP_PUSH_STRING)] = op_push_string,
 	[ACTION(A_OP_PUSH_TRUE)] = op_push_true,
 	[ACTION(A_OP_PUSH_FALSE)] = op_push_false,
 	[ACTION(A_OP_VAR_EVAL)] = op_var_eval,
 	[ACTION(A_OP_CALL_RET)] = op_call_ret,
 	[ACTION(A_OP_ATTR_EVAL)] = op_attr_eval,
 	[ACTION(A_OP_ARRAY_EVAL)] = op_array_eval,
 	[ACTION(A_OP_BLK_OPEN)] = op_blk_open,
 	[ACTION(A_OP_BLK_CLOSE)] = op_blk_close,
 	[ACTION(A_OP_FOR_INIT)] = op_for_init,
 	[ACTION(A_OP_FOR_COND)] = op_for_cond,
 	[ACTION(A_OP_FOR_AFTER)] = op_for_after,
 	[ACTION(A_OP_FOR_END)] = op_for_end,
 	[ACTION(A_OP_WHILE_BEGIN)] = op_while_begin,
 	[ACTION(A_OP_WHILE_COND)] = op_while_cond,
 	[ACTION(A_OP_WHILE_END)] = op_while_end,
 	[ACTION(A_OP_IF_COND)] = op_if_cond,
 	[ACTION(A_OP_PATCH_REF)] = op_patch_ref,
 	[ACTION(A_OP_TRY_BEGIN)] = op_try_begin,
 	[ACTION(A_OP_THROW)] = op_throw,
 	[ACTION(A_OP_IF_ELSE)] = op_if_else,
 	[ACTION(A_OP_TRY_END)] = op_try_end,
 	[ACTION(A_OP_CATCH)] = op_catch,
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
 	"NOT",
 	"RETURN",
 	"FUNCTION",
 	"program",
 	"stat",
 	"semi_stat",
 	"semi_list",
 	"compound_stat",
 	"function_def",
 	"var_list",
 	"var",
 	"var_list1",
 	"var_init_opt",
 	"exp",
 	"assign_or_call1",
 	"function_call",
 	"attr_assign",
 	"attr_assign2",
 	"method_call",
 	"arg_list_opt",
 	"arg_list",
 	"arg_list1",
 	"exp_lst_opt",
 	"exp_lst",
 	"exp_lst1",
 	"and_exp",
 	"or_exp",
 	"relational_exp",
 	"and_exp1",
 	"shift_exp",
 	"relational_exp1",
 	"additive_exp",
 	"shift_exp1",
 	"div_exp",
 	"additive_exp1",
 	"mult_exp",
 	"div_exp1",
 	"unary_exp",
 	"mult_exp1",
 	"primary_exp",
 	"id_eval",
 	"id_eval1",
 	"attr_eval",
 	"attr_eval1",
 	"stat_list",
 	"condition",
 	"else_opt",
 	"catch_opt",
 	"retval_opt",
 	"arg_lst_opt",
 	"arg_lst",
 	"arg_opt",
 	"op_var_decl",
 	"op_push_tmp",
 	"op_pop_tmp",
 	"op_var_init",
 	"op_var_assign",
 	"op_ret_discard",
 	"op_array_xlat",
 	"op_object_get",
 	"op_attr_assign",
 	"op_array_assign",
 	"op_method_lookup",
 	"op_call",
 	"op_function_lookup",
 	"op_arg",
 	"op_or",
 	"op_logic_or",
 	"op_xor",
 	"op_and",
 	"op_logic_and",
 	"op_lt",
 	"op_gt",
 	"op_equ",
 	"op_neq",
 	"op_gte",
 	"op_lte",
 	"op_shl",
 	"op_asr",
 	"op_add",
 	"op_sub",
 	"op_div",
 	"op_mod",
 	"op_mul",
 	"op_inv",
 	"op_minus",
 	"op_not",
 	"op_push_int",
 	"op_push_string",
 	"op_push_true",
 	"op_push_false",
 	"op_var_eval",
 	"op_call_ret",
 	"op_attr_eval",
 	"op_array_eval",
 	"op_blk_open",
 	"op_blk_close",
 	"op_for_init",
 	"op_for_cond",
 	"op_for_after",
 	"op_for_end",
 	"op_while_begin",
 	"op_while_cond",
 	"op_while_end",
 	"op_if_cond",
 	"op_patch_ref",
 	"op_try_begin",
 	"op_throw",
 	"op_if_else",
 	"op_try_end",
 	"op_catch",
 	"op_retval",
 	"op_fun_def",
 	"op_arg_decl",
 };

