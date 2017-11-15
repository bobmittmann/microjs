/* LL(1) Embeddedd Nonrecursive Predictive Parser */

#include "microjs3_ll.h"

/* Token-Rule pair (predict set) */
struct tr_pair {
	uint8_t t;
	uint8_t r;
};

/* Predict sets */
static const struct tr_pair predict_vec[] = {
	/*  76 (program) */
	{  0,  0}, { 23,  3}, { 36,  1}, { 37,  1}, { 38,  2}, { 40,  1}, 
	{ 41,  2}, { 42,  1}, { 44,  2}, { 46,  2}, { 51,  2}, { 64,  2}, 
	{ 65,  2}, { 66,  1}, 
	/*  77 (stat) */
	{ 36, 24}, { 37, 27}, { 40, 28}, { 42, 25}, { 66, 26}, 
	/*  78 (semi_stat) */
	{ 38, 16}, { 41, 17}, { 44, 19}, { 46, 20}, { 51, 18}, { 64, 21}, 
	{ 65, 22}, 
	/*  79 (semi_list) */
	{  0,  4}, {  3,  5}, 
	/*  80 (compound_stat) */
	{ 23,  6}, 
	/*  81 (stat_list) */
	{ 24,  7}, { 36,  8}, { 37,  8}, { 38,  9}, { 40,  8}, { 41,  9}, 
	{ 42,  8}, { 44,  9}, { 46,  9}, { 51,  9}, { 64,  9}, { 65,  9}, 
	{ 66,  8}, 
	/*  82 (loop_comp_stat) */
	{ 23, 10}, 
	/*  83 (loop_stat_list) */
	{ 24, 11}, { 36, 12}, { 37, 12}, { 38, 13}, { 40, 12}, { 41, 13}, 
	{ 42, 12}, { 44, 13}, { 46, 13}, { 51, 13}, { 62, 14}, { 63, 15}, 
	{ 64, 13}, { 65, 13}, { 66, 12}, 
	/*  84 (exp) */
	{  6, 84}, { 13, 84}, { 21, 84}, { 35, 84}, { 39, 84}, { 43, 84}, 
	{ 44, 84}, { 45, 84}, { 46, 84}, { 47, 84}, { 48, 84}, { 49, 84}, 
	{ 68, 85}, { 69, 86}, { 70, 84}, 
	/*  85 (var_list) */
	{ 43, 33}, 
	/*  86 (const_list) */
	{ 43, 59}, 
	/*  87 (var_assign) */
	{ 16, 42}, { 52, 43}, { 53, 44}, { 54, 45}, { 55, 46}, { 56, 47}, 
	{ 57, 48}, { 58, 49}, { 59, 50}, { 60, 51}, { 61, 52}, 
	/*  88 (function_call) */
	{ 21, 73}, 
	/*  89 (fpvar_assign) */
	{ 16,155}, { 52,156}, { 53,157}, { 54,158}, { 56,159}, 
	/*  90 (condition) */
	{ 21, 23}, 
	/*  91 (exp_lst_opt) */
	{  3, 79}, { 22, 79}, { 44, 80}, 
	/*  92 (else_opt) */
	{  0, 29}, { 23, 29}, { 24, 29}, { 34, 30}, { 36, 29}, { 37, 29}, 
	{ 38, 29}, { 40, 29}, { 41, 29}, { 42, 29}, { 44, 29}, { 46, 29}, 
	{ 51, 29}, { 62, 29}, { 63, 29}, { 64, 29}, { 65, 29}, { 66, 29}, 
	{ 71, 29}, 
	/*  93 (catch_opt) */
	{  0, 31}, { 23, 31}, { 24, 31}, { 33, 32}, { 36, 31}, { 37, 31}, 
	{ 38, 31}, { 40, 31}, { 41, 31}, { 42, 31}, { 44, 31}, { 46, 31}, 
	{ 51, 31}, { 62, 31}, { 63, 31}, { 64, 31}, { 65, 31}, { 66, 31}, 
	{ 71, 31}, 
	/*  94 (var) */
	{ 43, 36}, 
	/*  95 (var_list1) */
	{  0, 34}, {  2, 35}, {  3, 34}, 
	/*  96 (var_init_opt) */
	{  0, 37}, {  2, 37}, {  3, 37}, { 16, 38}, 
	/*  97 (var_init_assign) */
	{  6, 39}, { 13, 39}, { 21, 39}, { 35, 39}, { 39, 39}, { 43, 39}, 
	{ 44, 39}, { 45, 39}, { 46, 39}, { 47, 39}, { 48, 39}, { 49, 39}, 
	{ 64, 40}, { 67, 41}, { 68, 39}, { 69, 39}, { 70, 39}, 
	/*  98 (additive_exp) */
	{  6,111}, { 13,111}, { 21,111}, { 35,111}, { 39,111}, { 43,111}, 
	{ 44,111}, { 45,111}, { 46,111}, { 47,111}, { 48,111}, { 49,111}, 
	{ 70,111}, 
	/*  99 (div_exp) */
	{  6,115}, { 13,115}, { 21,115}, { 35,115}, { 39,115}, { 43,115}, 
	{ 44,115}, { 45,115}, { 46,115}, { 47,115}, { 48,115}, { 49,115}, 
	{ 70,115}, 
	/* 100 (mult_exp) */
	{  6,119}, { 13,119}, { 21,119}, { 35,119}, { 39,119}, { 43,119}, 
	{ 44,119}, { 45,119}, { 46,119}, { 47,119}, { 48,119}, { 49,119}, 
	{ 70,119}, 
	/* 101 (and_exp) */
	{  6, 95}, { 13, 95}, { 21, 95}, { 35, 95}, { 39, 95}, { 43, 95}, 
	{ 44, 95}, { 45, 95}, { 46, 95}, { 47, 95}, { 48, 95}, { 49, 95}, 
	{ 70, 95}, 
	/* 102 (shift_exp) */
	{  6,107}, { 13,107}, { 21,107}, { 35,107}, { 39,107}, { 43,107}, 
	{ 44,107}, { 45,107}, { 46,107}, { 47,107}, { 48,107}, { 49,107}, 
	{ 70,107}, 
	/* 103 (attr_assign1) */
	{  1, 54}, { 19, 53}, 
	/* 104 (attr_assign) */
	{ 43, 55}, 
	/* 105 (attr_assign2) */
	{ 16, 56}, { 19, 57}, { 21, 58}, 
	/* 106 (method_call) */
	{ 21, 72}, 
	/* 107 (const) */
	{ 43, 62}, 
	/* 108 (const_list1) */
	{  0, 60}, {  2, 61}, {  3, 60}, 
	/* 109 (const_init) */
	{ 35, 63}, { 39, 63}, { 45, 63}, { 47, 63}, { 48, 63}, { 49, 63}, 
	{ 67, 64}, 
	/* 110 (const_exp) */
	{ 35, 69}, { 39, 68}, { 45, 70}, { 47, 65}, { 48, 66}, { 49, 67}, 
	/* 111 (fpconst_exp) */
	{ 67, 71}, 
	/* 112 (arg_list_opt) */
	{  6, 75}, { 13, 75}, { 21, 75}, { 22, 74}, { 35, 75}, { 39, 75}, 
	{ 43, 75}, { 44, 75}, { 45, 75}, { 46, 75}, { 47, 75}, { 48, 75}, 
	{ 49, 75}, { 68, 75}, { 69, 75}, { 70, 75}, 
	/* 113 (arg_list) */
	{  6, 76}, { 13, 76}, { 21, 76}, { 35, 76}, { 39, 76}, { 43, 76}, 
	{ 44, 76}, { 45, 76}, { 46, 76}, { 47, 76}, { 48, 76}, { 49, 76}, 
	{ 68, 76}, { 69, 76}, { 70, 76}, 
	/* 114 (arg_list1) */
	{  2, 78}, { 22, 77}, 
	/* 115 (exp_lst) */
	{ 44, 81}, 
	/* 116 (exp_lst1) */
	{  2, 83}, {  3, 82}, { 22, 82}, 
	/* 117 (cond_exp) */
	{  6, 87}, { 13, 87}, { 21, 87}, { 35, 87}, { 39, 87}, { 43, 87}, 
	{ 44, 87}, { 45, 87}, { 46, 87}, { 47, 87}, { 48, 87}, { 49, 87}, 
	{ 70, 87}, 
	/* 118 (fpexp) */
	{  6,173}, { 21,173}, { 64,173}, { 67,173}, { 74,174}, { 75,173}, 
	/* 119 (fprelational_exp) */
	{  6,166}, { 21,166}, { 64,166}, { 67,166}, { 75,166}, 
	/* 120 (or_exp) */
	{  6, 90}, { 13, 90}, { 21, 90}, { 35, 90}, { 39, 90}, { 43, 90}, 
	{ 44, 90}, { 45, 90}, { 46, 90}, { 47, 90}, { 48, 90}, { 49, 90}, 
	{ 70, 90}, 
	/* 121 (cond_exp1) */
	{  0, 88}, {  2, 88}, {  3, 88}, {  4, 88}, { 15, 89}, { 20, 88}, 
	{ 22, 88}, { 24, 88}, 
	/* 122 (or_exp1) */
	{  0, 91}, {  2, 91}, {  3, 91}, {  4, 91}, { 11, 92}, { 12, 94}, 
	{ 15, 91}, { 20, 91}, { 22, 91}, { 24, 91}, { 31, 93}, 
	/* 123 (relational_exp) */
	{  6, 99}, { 13, 99}, { 21, 99}, { 35, 99}, { 39, 99}, { 43, 99}, 
	{ 44, 99}, { 45, 99}, { 46, 99}, { 47, 99}, { 48, 99}, { 49, 99}, 
	{ 70, 99}, 
	/* 124 (and_exp1) */
	{  0, 96}, {  2, 96}, {  3, 96}, {  4, 96}, { 10, 97}, { 11, 96}, 
	{ 12, 96}, { 15, 96}, { 20, 96}, { 22, 96}, { 24, 96}, { 31, 96}, 
	{ 32, 98}, 
	/* 125 (relational_exp1) */
	{  0,100}, {  2,100}, {  3,100}, {  4,100}, { 10,100}, { 11,100}, 
	{ 12,100}, { 15,100}, { 17,101}, { 18,102}, { 20,100}, { 22,100}, 
	{ 24,100}, { 25,105}, { 26,106}, { 27,103}, { 28,104}, { 31,100}, 
	{ 32,100}, 
	/* 126 (shift_exp1) */
	{  0,108}, {  2,108}, {  3,108}, {  4,108}, { 10,108}, { 11,108}, 
	{ 12,108}, { 15,108}, { 17,108}, { 18,108}, { 20,108}, { 22,108}, 
	{ 24,108}, { 25,108}, { 26,108}, { 27,108}, { 28,108}, { 29,110}, 
	{ 30,109}, { 31,108}, { 32,108}, 
	/* 127 (additive_exp1) */
	{  0,112}, {  2,112}, {  3,112}, {  4,112}, {  5,113}, {  6,114}, 
	{ 10,112}, { 11,112}, { 12,112}, { 15,112}, { 17,112}, { 18,112}, 
	{ 20,112}, { 22,112}, { 24,112}, { 25,112}, { 26,112}, { 27,112}, 
	{ 28,112}, { 29,112}, { 30,112}, { 31,112}, { 32,112}, 
	/* 128 (div_exp1) */
	{  0,116}, {  2,116}, {  3,116}, {  4,116}, {  5,116}, {  6,116}, 
	{  8,117}, {  9,118}, { 10,116}, { 11,116}, { 12,116}, { 15,116}, 
	{ 17,116}, { 18,116}, { 20,116}, { 22,116}, { 24,116}, { 25,116}, 
	{ 26,116}, { 27,116}, { 28,116}, { 29,116}, { 30,116}, { 31,116}, 
	{ 32,116}, 
	/* 129 (unary_exp) */
	{  6,124}, { 13,123}, { 21,122}, { 35,122}, { 39,122}, { 43,122}, 
	{ 44,122}, { 45,122}, { 46,122}, { 47,122}, { 48,122}, { 49,122}, 
	{ 70,125}, 
	/* 130 (mult_exp1) */
	{  0,120}, {  2,120}, {  3,120}, {  4,120}, {  5,120}, {  6,120}, 
	{  7,121}, {  8,120}, {  9,120}, { 10,120}, { 11,120}, { 12,120}, 
	{ 15,120}, { 17,120}, { 18,120}, { 20,120}, { 22,120}, { 24,120}, 
	{ 25,120}, { 26,120}, { 27,120}, { 28,120}, { 29,120}, { 30,120}, 
	{ 31,120}, { 32,120}, 
	/* 131 (primary_exp) */
	{ 21,126}, { 35,131}, { 39,130}, { 43,135}, { 44,132}, { 45,133}, 
	{ 46,134}, { 47,127}, { 48,128}, { 49,129}, 
	/* 132 (id_eval1) */
	{  1,137}, { 19,136}, 
	/* 133 (attr_eval) */
	{ 43,138}, 
	/* 134 (attr_eval1) */
	{  0,139}, {  2,139}, {  3,139}, {  4,139}, {  5,139}, {  6,139}, 
	{  7,139}, {  8,139}, {  9,139}, { 10,139}, { 11,139}, { 12,139}, 
	{ 15,139}, { 17,139}, { 18,139}, { 19,141}, { 20,139}, { 21,140}, 
	{ 22,139}, { 24,139}, { 25,139}, { 26,139}, { 27,139}, { 28,139}, 
	{ 29,139}, { 30,139}, { 31,139}, { 32,139}, 
	/* 135 (func_comp_stat) */
	{ 23,142}, 
	/* 136 (func_stat_list) */
	{ 24,143}, { 36,144}, { 37,144}, { 38,145}, { 40,144}, { 41,145}, 
	{ 42,144}, { 44,145}, { 46,145}, { 51,145}, { 64,145}, { 65,145}, 
	{ 66,144}, { 71,146}, 
	/* 137 (retval_opt) */
	{  6,148}, { 13,148}, { 21,148}, { 24,147}, { 35,148}, { 39,148}, 
	{ 43,148}, { 44,148}, { 45,148}, { 46,148}, { 47,148}, { 48,148}, 
	{ 49,148}, { 68,148}, { 69,148}, { 70,148}, 
	/* 138 (function_def) */
	{ 72,149}, 
	/* 139 (arg_lst_opt) */
	{ 22,150}, { 43,151}, 
	/* 140 (arg_lst) */
	{ 43,152}, 
	/* 141 (arg_opt) */
	{  2,154}, { 22,153}, 
	/* 142 (fpadditive_exp) */
	{  6,175}, { 21,175}, { 64,175}, { 67,175}, { 75,175}, 
	/* 143 (fpdiv_exp) */
	{  6,179}, { 21,179}, { 64,179}, { 67,179}, { 75,179}, 
	/* 144 (fpmult_exp) */
	{  6,182}, { 21,182}, { 64,182}, { 67,182}, { 75,182}, 
	/* 145 (fpattr_assign1) */
	{  1,161}, { 19,160}, 
	/* 146 (fpattr_assign) */
	{ 43,162}, 
	/* 147 (fpattr_assign2) */
	{ 16,163}, { 19,164}, { 73,165}, 
	/* 148 (fprelational_exp1) */
	{ 17,167}, { 18,168}, { 25,171}, { 26,172}, { 27,169}, { 28,170}, 
	/* 149 (fpadditive_exp1) */
	{  0,176}, {  2,176}, {  3,176}, {  4,176}, {  5,177}, {  6,178}, 
	{ 17,176}, { 18,176}, { 20,176}, { 22,176}, { 24,176}, { 25,176}, 
	{ 26,176}, { 27,176}, { 28,176}, 
	/* 150 (fpdiv_exp1) */
	{  0,180}, {  2,180}, {  3,180}, {  4,180}, {  5,180}, {  6,180}, 
	{  8,181}, { 17,180}, { 18,180}, { 20,180}, { 22,180}, { 24,180}, 
	{ 25,180}, { 26,180}, { 27,180}, { 28,180}, 
	/* 151 (fpunary_exp) */
	{  6,186}, { 21,185}, { 64,185}, { 67,185}, { 75,185}, 
	/* 152 (fpmult_exp1) */
	{  0,183}, {  2,183}, {  3,183}, {  4,183}, {  5,183}, {  6,183}, 
	{  7,184}, {  8,183}, { 17,183}, { 18,183}, { 20,183}, { 22,183}, 
	{ 24,183}, { 25,183}, { 26,183}, { 27,183}, { 28,183}, 
	/* 153 (fpprimary_exp) */
	{ 21,187}, { 64,189}, { 67,190}, { 75,188}, 
};
/* 1314 bytes; */

static const struct {
	uint16_t off;
	uint8_t cnt;
} predict_idx[] = {
	{   0, 14},
	{  14,  5},
	{  19,  7},
	{  26,  2},
	{  28,  1},
	{  29, 13},
	{  42,  1},
	{  43, 15},
	{  58, 15},
	{  73,  1},
	{  74,  1},
	{  75, 11},
	{  86,  1},
	{  87,  5},
	{  92,  1},
	{  93,  3},
	{  96, 19},
	{ 115, 19},
	{ 134,  1},
	{ 135,  3},
	{ 138,  4},
	{ 142, 17},
	{ 159, 13},
	{ 172, 13},
	{ 185, 13},
	{ 198, 13},
	{ 211, 13},
	{ 224,  2},
	{ 226,  1},
	{ 227,  3},
	{ 230,  1},
	{ 231,  1},
	{ 232,  3},
	{ 235,  7},
	{ 242,  6},
	{ 248,  1},
	{ 249, 16},
	{ 265, 15},
	{ 280,  2},
	{ 282,  1},
	{ 283,  3},
	{ 286, 13},
	{ 299,  6},
	{ 305,  5},
	{ 310, 13},
	{ 323,  8},
	{ 331, 11},
	{ 342, 13},
	{ 355, 13},
	{ 368, 19},
	{ 387, 21},
	{ 408, 23},
	{ 431, 25},
	{ 456, 13},
	{ 469, 26},
	{ 495, 10},
	{ 505,  2},
	{ 507,  1},
	{ 508, 28},
	{ 536,  1},
	{ 537, 14},
	{ 551, 16},
	{ 567,  1},
	{ 568,  2},
	{ 570,  1},
	{ 571,  2},
	{ 573,  5},
	{ 578,  5},
	{ 583,  5},
	{ 588,  2},
	{ 590,  1},
	{ 591,  3},
	{ 594,  6},
	{ 600, 15},
	{ 615, 16},
	{ 631,  5},
	{ 636, 17},
	{ 653,  4},
};
/* 312 bytes */

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
	/*  6:compound_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/*  7:stat_list(0) -> */
	
	/*  8:stat_list(2) -> */
	N_STAT, N_STAT_LIST, 
	/*  9:stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_STAT_LIST, 
	/* 10:loop_comp_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_LOOP_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 11:loop_stat_list(0) -> */
	
	/* 12:loop_stat_list(2) -> */
	N_STAT, N_LOOP_STAT_LIST, 
	/* 13:loop_stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_LOOP_STAT_LIST, 
	/* 14:loop_stat_list(3) -> */
	T_BREAK, T_SEMICOLON, A_OP_LOOP_BREAK, 
	/* 15:loop_stat_list(3) -> */
	T_CONTINUE, T_SEMICOLON, A_OP_LOOP_CONTINUE, 
	/* 16:semi_stat(3) -> */
	T_THROW, N_EXP, A_OP_THROW, 
	/* 17:semi_stat(2) -> */
	T_VAR, N_VAR_LIST, 
	/* 18:semi_stat(2) -> */
	T_CONST, N_CONST_LIST, 
	/* 19:semi_stat(3) -> */
	T_VAR_ID, A_OP_PUSH_REF, N_VAR_ASSIGN, 
	/* 20:semi_stat(4) -> */
	T_FUNC_ID, A_OP_PUSH_REF, N_FUNCTION_CALL, A_OP_RET_DISCARD, 
	/* 21:semi_stat(3) -> */
	T_FPVAR_ID, A_OP_PUSH_REF, N_FPVAR_ASSIGN, 
	/* 22:semi_stat(4) -> */
	T_FPFUNC_ID, A_OP_PUSH_REF, N_FUNCTION_CALL, A_OP_RET_DISCARD, 
	/* 23:condition(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 24:stat(15) -> */
	T_FOR, A_OP_BLK_OPEN, T_LPAREN, N_EXP_LST_OPT, T_SEMICOLON, A_OP_FOR_INIT, N_EXP, A_OP_FOR_COND, T_SEMICOLON, N_EXP_LST_OPT, A_OP_FOR_AFTER, T_RPAREN, N_LOOP_COMP_STAT, A_OP_FOR_END, A_OP_BLK_CLOSE, 
	/* 25:stat(6) -> */
	T_WHILE, A_OP_WHILE_BEGIN, N_CONDITION, A_OP_WHILE_COND, N_LOOP_COMP_STAT, A_OP_WHILE_END, 
	/* 26:stat(8) -> */
	T_DO, A_OP_DO_WHILE_BEGIN, N_LOOP_COMP_STAT, T_WHILE, N_CONDITION, A_OP_DO_WHILE_COND, A_OP_DO_WHILE_END, T_SEMICOLON, 
	/* 27:stat(6) -> */
	T_IF, N_CONDITION, A_OP_IF_COND, N_COMPOUND_STAT, N_ELSE_OPT, A_OP_PATCH_REF, 
	/* 28:stat(4) -> */
	T_TRY, A_OP_TRY_BEGIN, N_COMPOUND_STAT, N_CATCH_OPT, 
	/* 29:else_opt(0) -> */
	
	/* 30:else_opt(3) -> */
	T_ELSE, A_OP_IF_ELSE, N_COMPOUND_STAT, 
	/* 31:catch_opt(1) -> */
	A_OP_TRY_END, 
	/* 32:catch_opt(14) -> */
	T_CATCH, A_OP_CATCH, A_OP_BLK_OPEN, T_LPAREN, T_ID, A_OP_VAR_DECL, A_OP_PUSH_TMP, A_OP_VAR_INIT, T_RPAREN, T_LBRACE, N_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, A_OP_PATCH_REF, 
	/* 33:var_list(2) -> */
	N_VAR, N_VAR_LIST1, 
	/* 34:var_list1(0) -> */
	
	/* 35:var_list1(2) -> */
	T_COMMA, N_VAR_LIST, 
	/* 36:var(3) -> */
	T_ID, A_OP_VAR_DECL, N_VAR_INIT_OPT, 
	/* 37:var_init_opt(1) -> */
	A_OP_POP_REF, 
	/* 38:var_init_opt(2) -> */
	T_EQUALS, N_VAR_INIT_ASSIGN, 
	/* 39:var_init_assign(2) -> */
	N_EXP, A_OP_VAR_INIT, 
	/* 40:var_init_assign(1) -> */
	T_FPVAR_ID, 
	/* 41:var_init_assign(1) -> */
	T_FPCONST_ID, 
	/* 42:var_assign(3) -> */
	T_EQUALS, N_EXP, A_OP_VAR_ASSIGN, 
	/* 43:var_assign(5) -> */
	T_ADD_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_ADD, A_OP_VAR_ASSIGN, 
	/* 44:var_assign(5) -> */
	T_SUB_EQ, A_OP_VAR_EVAL, N_ADDITIVE_EXP, A_OP_SUB, A_OP_VAR_ASSIGN, 
	/* 45:var_assign(5) -> */
	T_DIV_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_DIV, A_OP_VAR_ASSIGN, 
	/* 46:var_assign(5) -> */
	T_MOD_EQ, A_OP_VAR_EVAL, N_DIV_EXP, A_OP_MOD, A_OP_VAR_ASSIGN, 
	/* 47:var_assign(5) -> */
	T_MUL_EQ, A_OP_VAR_EVAL, N_MULT_EXP, A_OP_MUL, A_OP_VAR_ASSIGN, 
	/* 48:var_assign(5) -> */
	T_AND_EQ, A_OP_VAR_EVAL, N_AND_EXP, A_OP_AND, A_OP_VAR_ASSIGN, 
	/* 49:var_assign(5) -> */
	T_OR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_OR, A_OP_VAR_ASSIGN, 
	/* 50:var_assign(5) -> */
	T_XOR_EQ, A_OP_VAR_EVAL, N_EXP, A_OP_XOR, A_OP_VAR_ASSIGN, 
	/* 51:var_assign(5) -> */
	T_SHL_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_SHL, A_OP_VAR_ASSIGN, 
	/* 52:var_assign(5) -> */
	T_ASR_EQ, A_OP_VAR_EVAL, N_SHIFT_EXP, A_OP_ASR, A_OP_VAR_ASSIGN, 
	/* 53:attr_assign1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_ASSIGN, 
	/* 54:attr_assign1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_ASSIGN, 
	/* 55:attr_assign(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_ASSIGN2, 
	/* 56:attr_assign2(3) -> */
	T_EQUALS, N_EXP, A_OP_ATTR_ASSIGN, 
	/* 57:attr_assign2(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, T_EQUALS, N_EXP, A_OP_ARRAY_ASSIGN, 
	/* 58:attr_assign2(2) -> */
	N_METHOD_CALL, A_OP_RET_DISCARD, 
	/* 59:const_list(2) -> */
	N_CONST, N_CONST_LIST1, 
	/* 60:const_list1(0) -> */
	
	/* 61:const_list1(2) -> */
	T_COMMA, N_CONST_LIST, 
	/* 62:const(4) -> */
	T_ID, A_OP_CONST_DECL, T_EQUALS, N_CONST_INIT, 
	/* 63:const_init(2) -> */
	N_CONST_EXP, A_OP_CONST_INIT, 
	/* 64:const_init(2) -> */
	N_FPCONST_EXP, A_OP_CONST_INIT, 
	/* 65:const_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 66:const_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 67:const_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 68:const_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 69:const_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 70:const_exp(3) -> */
	T_CONST_ID, A_OP_PUSH_REF, A_OP_CONST_EVAL, 
	/* 71:fpconst_exp(2) -> */
	T_FPCONST_ID, A_OP_FPCONST_INIT, 
	/* 72:method_call(5) -> */
	A_OP_METHOD_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 73:function_call(5) -> */
	A_OP_FUNCTION_LOOKUP, T_LPAREN, N_ARG_LIST_OPT, T_RPAREN, A_OP_CALL, 
	/* 74:arg_list_opt(0) -> */
	
	/* 75:arg_list_opt(1) -> */
	N_ARG_LIST, 
	/* 76:arg_list(3) -> */
	N_EXP, A_OP_ARG, N_ARG_LIST1, 
	/* 77:arg_list1(0) -> */
	
	/* 78:arg_list1(2) -> */
	T_COMMA, N_ARG_LIST, 
	/* 79:exp_lst_opt(0) -> */
	
	/* 80:exp_lst_opt(1) -> */
	N_EXP_LST, 
	/* 81:exp_lst(4) -> */
	T_VAR_ID, A_OP_PUSH_REF, N_VAR_ASSIGN, N_EXP_LST1, 
	/* 82:exp_lst1(0) -> */
	
	/* 83:exp_lst1(2) -> */
	T_COMMA, N_EXP_LST, 
	/* 84:exp(1) -> */
	N_COND_EXP, 
	/* 85:exp(2) -> */
	T_FPINT, N_FPEXP, 
	/* 86:exp(2) -> */
	T_FPCMP, N_FPRELATIONAL_EXP, 
	/* 87:cond_exp(2) -> */
	N_OR_EXP, N_COND_EXP1, 
	/* 88:cond_exp1(0) -> */
	
	/* 89:cond_exp1(4) -> */
	T_QUEST, N_EXP, T_COLON, N_COND_EXP, 
	/* 90:or_exp(2) -> */
	N_AND_EXP, N_OR_EXP1, 
	/* 91:or_exp1(0) -> */
	
	/* 92:or_exp1(3) -> */
	T_BAR, N_OR_EXP, A_OP_OR, 
	/* 93:or_exp1(3) -> */
	T_LOGICOR, N_OR_EXP, A_OP_LOGIC_OR, 
	/* 94:or_exp1(3) -> */
	T_CARET, N_OR_EXP, A_OP_XOR, 
	/* 95:and_exp(2) -> */
	N_RELATIONAL_EXP, N_AND_EXP1, 
	/* 96:and_exp1(0) -> */
	
	/* 97:and_exp1(3) -> */
	T_AMPERSAND, N_AND_EXP, A_OP_AND, 
	/* 98:and_exp1(3) -> */
	T_LOGICAND, N_AND_EXP, A_OP_LOGIC_AND, 
	/* 99:relational_exp(2) -> */
	N_SHIFT_EXP, N_RELATIONAL_EXP1, 
	/* 100:relational_exp1(0) -> */
	
	/* 101:relational_exp1(3) -> */
	T_LESSTHEN, N_RELATIONAL_EXP, A_OP_LT, 
	/* 102:relational_exp1(3) -> */
	T_GREATTHEN, N_RELATIONAL_EXP, A_OP_GT, 
	/* 103:relational_exp1(3) -> */
	T_EQU, N_RELATIONAL_EXP, A_OP_EQU, 
	/* 104:relational_exp1(3) -> */
	T_NEQ, N_RELATIONAL_EXP, A_OP_NEQ, 
	/* 105:relational_exp1(3) -> */
	T_GTE, N_RELATIONAL_EXP, A_OP_GTE, 
	/* 106:relational_exp1(3) -> */
	T_LTE, N_RELATIONAL_EXP, A_OP_LTE, 
	/* 107:shift_exp(2) -> */
	N_ADDITIVE_EXP, N_SHIFT_EXP1, 
	/* 108:shift_exp1(0) -> */
	
	/* 109:shift_exp1(3) -> */
	T_SHL, N_SHIFT_EXP, A_OP_SHL, 
	/* 110:shift_exp1(3) -> */
	T_ASR, N_SHIFT_EXP, A_OP_ASR, 
	/* 111:additive_exp(2) -> */
	N_DIV_EXP, N_ADDITIVE_EXP1, 
	/* 112:additive_exp1(0) -> */
	
	/* 113:additive_exp1(3) -> */
	T_PLUS, N_ADDITIVE_EXP, A_OP_ADD, 
	/* 114:additive_exp1(3) -> */
	T_MINUS, N_ADDITIVE_EXP, A_OP_SUB, 
	/* 115:div_exp(2) -> */
	N_MULT_EXP, N_DIV_EXP1, 
	/* 116:div_exp1(0) -> */
	
	/* 117:div_exp1(3) -> */
	T_SLASH, N_DIV_EXP, A_OP_DIV, 
	/* 118:div_exp1(3) -> */
	T_PERCENT, N_DIV_EXP, A_OP_MOD, 
	/* 119:mult_exp(2) -> */
	N_UNARY_EXP, N_MULT_EXP1, 
	/* 120:mult_exp1(0) -> */
	
	/* 121:mult_exp1(3) -> */
	T_STAR, N_MULT_EXP, A_OP_MUL, 
	/* 122:unary_exp(1) -> */
	N_PRIMARY_EXP, 
	/* 123:unary_exp(3) -> */
	T_TILDE, N_UNARY_EXP, A_OP_INV, 
	/* 124:unary_exp(3) -> */
	T_MINUS, N_UNARY_EXP, A_OP_MINUS, 
	/* 125:unary_exp(3) -> */
	T_NOT, N_UNARY_EXP, A_OP_NOT, 
	/* 126:primary_exp(3) -> */
	T_LPAREN, N_EXP, T_RPAREN, 
	/* 127:primary_exp(2) -> */
	T_INT, A_OP_PUSH_INT, 
	/* 128:primary_exp(2) -> */
	T_CHAR, A_OP_PUSH_INT, 
	/* 129:primary_exp(2) -> */
	T_STRING, A_OP_PUSH_STRING, 
	/* 130:primary_exp(2) -> */
	T_TRUE, A_OP_PUSH_TRUE, 
	/* 131:primary_exp(2) -> */
	T_FALSE, A_OP_PUSH_FALSE, 
	/* 132:primary_exp(3) -> */
	T_VAR_ID, A_OP_PUSH_REF, A_OP_VAR_EVAL, 
	/* 133:primary_exp(3) -> */
	T_CONST_ID, A_OP_PUSH_REF, A_OP_CONST_EVAL, 
	/* 134:primary_exp(4) -> */
	T_FUNC_ID, A_OP_PUSH_REF, N_FUNCTION_CALL, A_OP_RET_VAL, 
	/* 135:primary_exp(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ID_EVAL1, 
	/* 136:id_eval1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_ATTR_EVAL, 
	/* 137:id_eval1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_ATTR_EVAL, 
	/* 138:attr_eval(3) -> */
	T_ID, A_OP_PUSH_TMP, N_ATTR_EVAL1, 
	/* 139:attr_eval1(1) -> */
	A_OP_ATTR_EVAL, 
	/* 140:attr_eval1(2) -> */
	N_METHOD_CALL, A_OP_RET_VAL, 
	/* 141:attr_eval1(4) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_EVAL, 
	/* 142:func_comp_stat(5) -> */
	T_LBRACE, A_OP_BLK_OPEN, N_FUNC_STAT_LIST, T_RBRACE, A_OP_BLK_CLOSE, 
	/* 143:func_stat_list(0) -> */
	
	/* 144:func_stat_list(2) -> */
	N_STAT, N_FUNC_STAT_LIST, 
	/* 145:func_stat_list(3) -> */
	N_SEMI_STAT, T_SEMICOLON, N_FUNC_STAT_LIST, 
	/* 146:func_stat_list(2) -> */
	T_RETURN, N_RETVAL_OPT, 
	/* 147:retval_opt(1) -> */
	A_OP_RETURN, 
	/* 148:retval_opt(2) -> */
	N_EXP, A_OP_RETVAL, 
	/* 149:function_def(12) -> */
	T_FUNCTION, T_ID, A_OP_FUN_DEF, A_OP_BLK_OPEN, T_LPAREN, N_ARG_LST_OPT, T_RPAREN, T_LBRACE, N_FUNC_STAT_LIST, T_RBRACE, A_OP_FUN_END, A_OP_PATCH_REF, 
	/* 150:arg_lst_opt(0) -> */
	
	/* 151:arg_lst_opt(1) -> */
	N_ARG_LST, 
	/* 152:arg_lst(3) -> */
	T_ID, A_OP_ARG_DECL, N_ARG_OPT, 
	/* 153:arg_opt(0) -> */
	
	/* 154:arg_opt(2) -> */
	T_COMMA, N_ARG_LST, 
	/* 155:fpvar_assign(3) -> */
	T_EQUALS, N_FPEXP, A_OP_VAR_ASSIGN, 
	/* 156:fpvar_assign(5) -> */
	T_ADD_EQ, A_OP_VAR_EVAL, N_FPADDITIVE_EXP, A_OP_FPADD, A_OP_VAR_ASSIGN, 
	/* 157:fpvar_assign(5) -> */
	T_SUB_EQ, A_OP_VAR_EVAL, N_FPADDITIVE_EXP, A_OP_FPSUB, A_OP_VAR_ASSIGN, 
	/* 158:fpvar_assign(5) -> */
	T_DIV_EQ, A_OP_VAR_EVAL, N_FPDIV_EXP, A_OP_FPDIV, A_OP_VAR_ASSIGN, 
	/* 159:fpvar_assign(5) -> */
	T_MUL_EQ, A_OP_VAR_EVAL, N_FPMULT_EXP, A_OP_FPMUL, A_OP_VAR_ASSIGN, 
	/* 160:fpattr_assign1(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, A_OP_ARRAY_XLAT, T_DOT, N_FPATTR_ASSIGN, 
	/* 161:fpattr_assign1(3) -> */
	T_DOT, A_OP_OBJECT_GET, N_FPATTR_ASSIGN, 
	/* 162:fpattr_assign(3) -> */
	T_ID, A_OP_PUSH_TMP, N_FPATTR_ASSIGN2, 
	/* 163:fpattr_assign2(3) -> */
	T_EQUALS, N_FPEXP, A_OP_ATTR_ASSIGN, 
	/* 164:fpattr_assign2(6) -> */
	T_LBRACKET, N_EXP, T_RBRACKET, T_EQUALS, N_FPEXP, A_OP_ARRAY_ASSIGN, 
	/* 165:fpattr_assign2(2) -> */
	T_FPMETHOD_CALL, A_OP_RET_DISCARD, 
	/* 166:fprelational_exp(2) -> */
	N_FPADDITIVE_EXP, N_FPRELATIONAL_EXP1, 
	/* 167:fprelational_exp1(3) -> */
	T_LESSTHEN, N_FPADDITIVE_EXP, A_OP_FPLT, 
	/* 168:fprelational_exp1(3) -> */
	T_GREATTHEN, N_FPADDITIVE_EXP, A_OP_FPGT, 
	/* 169:fprelational_exp1(3) -> */
	T_EQU, N_FPADDITIVE_EXP, A_OP_FPEQU, 
	/* 170:fprelational_exp1(3) -> */
	T_NEQ, N_FPADDITIVE_EXP, A_OP_FPNEQ, 
	/* 171:fprelational_exp1(3) -> */
	T_GTE, N_FPADDITIVE_EXP, A_OP_FPGTE, 
	/* 172:fprelational_exp1(3) -> */
	T_LTE, N_FPADDITIVE_EXP, A_OP_FPLTE, 
	/* 173:fpexp(1) -> */
	N_FPADDITIVE_EXP, 
	/* 174:fpexp(2) -> */
	T_INTFP, N_EXP, 
	/* 175:fpadditive_exp(2) -> */
	N_FPDIV_EXP, N_FPADDITIVE_EXP1, 
	/* 176:fpadditive_exp1(0) -> */
	
	/* 177:fpadditive_exp1(3) -> */
	T_PLUS, N_FPADDITIVE_EXP, A_OP_FPADD, 
	/* 178:fpadditive_exp1(3) -> */
	T_MINUS, N_FPADDITIVE_EXP, A_OP_FPSUB, 
	/* 179:fpdiv_exp(2) -> */
	N_FPMULT_EXP, N_FPDIV_EXP1, 
	/* 180:fpdiv_exp1(0) -> */
	
	/* 181:fpdiv_exp1(3) -> */
	T_SLASH, N_FPDIV_EXP, A_OP_FPDIV, 
	/* 182:fpmult_exp(2) -> */
	N_FPUNARY_EXP, N_FPMULT_EXP1, 
	/* 183:fpmult_exp1(0) -> */
	
	/* 184:fpmult_exp1(3) -> */
	T_STAR, N_FPMULT_EXP, A_OP_FPMUL, 
	/* 185:fpunary_exp(1) -> */
	N_FPPRIMARY_EXP, 
	/* 186:fpunary_exp(3) -> */
	T_MINUS, N_FPUNARY_EXP, A_OP_FPMINUS, 
	/* 187:fpprimary_exp(3) -> */
	T_LPAREN, N_FPEXP, T_RPAREN, 
	/* 188:fpprimary_exp(2) -> */
	T_FPLIT, A_OP_PUSH_FP, 
	/* 189:fpprimary_exp(3) -> */
	T_FPVAR_ID, A_OP_PUSH_REF, A_OP_VAR_EVAL, 
	/* 190:fpprimary_exp(3) -> */
	T_FPCONST_ID, A_OP_PUSH_REF, A_OP_CONST_EVAL, 
};
/* 526 bytes */

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
	{  10,  5},
	{  15,  0},
	{  15,  2},
	{  17,  3},
	{  20,  5},
	{  25,  0},
	{  25,  2},
	{  27,  3},
	{  30,  3},
	{  33,  3},
	{  36,  3},
	{  39,  2},
	{  41,  2},
	{  43,  3},
	{  46,  4},
	{  50,  3},
	{  53,  4},
	{  57,  3},
	{  60, 15},
	{  75,  6},
	{  81,  8},
	{  89,  6},
	{  95,  4},
	{  99,  0},
	{  99,  3},
	{ 102,  1},
	{ 103, 14},
	{ 117,  2},
	{ 119,  0},
	{ 119,  2},
	{ 121,  3},
	{ 124,  1},
	{ 125,  2},
	{ 127,  2},
	{ 129,  1},
	{ 130,  1},
	{ 131,  3},
	{ 134,  5},
	{ 139,  5},
	{ 144,  5},
	{ 149,  5},
	{ 154,  5},
	{ 159,  5},
	{ 164,  5},
	{ 169,  5},
	{ 174,  5},
	{ 179,  5},
	{ 184,  6},
	{ 190,  3},
	{ 193,  3},
	{ 196,  3},
	{ 199,  6},
	{ 205,  2},
	{ 207,  2},
	{ 209,  0},
	{ 209,  2},
	{ 211,  4},
	{ 215,  2},
	{ 217,  2},
	{ 219,  2},
	{ 221,  2},
	{ 223,  2},
	{ 225,  2},
	{ 227,  2},
	{ 229,  3},
	{ 232,  2},
	{ 234,  5},
	{ 239,  5},
	{ 244,  0},
	{ 244,  1},
	{ 245,  3},
	{ 248,  0},
	{ 248,  2},
	{ 250,  0},
	{ 250,  1},
	{ 251,  4},
	{ 255,  0},
	{ 255,  2},
	{ 257,  1},
	{ 258,  2},
	{ 260,  2},
	{ 262,  2},
	{ 264,  0},
	{ 264,  4},
	{ 268,  2},
	{ 270,  0},
	{ 270,  3},
	{ 273,  3},
	{ 276,  3},
	{ 279,  2},
	{ 281,  0},
	{ 281,  3},
	{ 284,  3},
	{ 287,  2},
	{ 289,  0},
	{ 289,  3},
	{ 292,  3},
	{ 295,  3},
	{ 298,  3},
	{ 301,  3},
	{ 304,  3},
	{ 307,  2},
	{ 309,  0},
	{ 309,  3},
	{ 312,  3},
	{ 315,  2},
	{ 317,  0},
	{ 317,  3},
	{ 320,  3},
	{ 323,  2},
	{ 325,  0},
	{ 325,  3},
	{ 328,  3},
	{ 331,  2},
	{ 333,  0},
	{ 333,  3},
	{ 336,  1},
	{ 337,  3},
	{ 340,  3},
	{ 343,  3},
	{ 346,  3},
	{ 349,  2},
	{ 351,  2},
	{ 353,  2},
	{ 355,  2},
	{ 357,  2},
	{ 359,  3},
	{ 362,  3},
	{ 365,  4},
	{ 369,  3},
	{ 372,  6},
	{ 378,  3},
	{ 381,  3},
	{ 384,  1},
	{ 385,  2},
	{ 387,  4},
	{ 391,  5},
	{ 396,  0},
	{ 396,  2},
	{ 398,  3},
	{ 401,  2},
	{ 403,  1},
	{ 404,  2},
	{ 406, 12},
	{ 418,  0},
	{ 418,  1},
	{ 419,  3},
	{ 422,  0},
	{ 422,  2},
	{ 424,  3},
	{ 427,  5},
	{ 432,  5},
	{ 437,  5},
	{ 442,  5},
	{ 447,  6},
	{ 453,  3},
	{ 456,  3},
	{ 459,  3},
	{ 462,  6},
	{ 468,  2},
	{ 470,  2},
	{ 472,  3},
	{ 475,  3},
	{ 478,  3},
	{ 481,  3},
	{ 484,  3},
	{ 487,  3},
	{ 490,  1},
	{ 491,  2},
	{ 493,  2},
	{ 495,  0},
	{ 495,  3},
	{ 498,  3},
	{ 501,  2},
	{ 503,  0},
	{ 503,  3},
	{ 506,  2},
	{ 508,  0},
	{ 508,  3},
	{ 511,  1},
	{ 512,  3},
	{ 515,  3},
	{ 518,  2},
	{ 520,  3},
	{ 523,  3},
};
/* 764 bytes */

/* Total: 2916 bytes */


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
extern int op_blk_open(void * arg);
extern int op_blk_close(void * arg);
extern int op_loop_break(void * arg);
extern int op_loop_continue(void * arg);
extern int op_throw(void * arg);
extern int op_push_ref(void * arg);
extern int op_ret_discard(void * arg);
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
extern int op_if_else(void * arg);
extern int op_try_end(void * arg);
extern int op_catch(void * arg);
extern int op_var_decl(void * arg);
extern int op_push_tmp(void * arg);
extern int op_var_init(void * arg);
extern int op_pop_ref(void * arg);
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
extern int op_attr_assign(void * arg);
extern int op_array_assign(void * arg);
extern int op_const_decl(void * arg);
extern int op_const_init(void * arg);
extern int op_push_int(void * arg);
extern int op_push_string(void * arg);
extern int op_push_true(void * arg);
extern int op_push_false(void * arg);
extern int op_const_eval(void * arg);
extern int op_fpconst_init(void * arg);
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
extern int op_return(void * arg);
extern int op_retval(void * arg);
extern int op_fun_def(void * arg);
extern int op_fun_end(void * arg);
extern int op_arg_decl(void * arg);
extern int op_fpadd(void * arg);
extern int op_fpsub(void * arg);
extern int op_fpdiv(void * arg);
extern int op_fpmul(void * arg);
extern int op_fplt(void * arg);
extern int op_fpgt(void * arg);
extern int op_fpequ(void * arg);
extern int op_fpneq(void * arg);
extern int op_fpgte(void * arg);
extern int op_fplte(void * arg);
extern int op_fpminus(void * arg);
extern int op_push_fp(void * arg);


/* Syntax action callback lookup table */
int (* const microjs_ll_op[])(void *) = {
	[ACTION(A_OP_BLK_OPEN)] = op_blk_open,
 	[ACTION(A_OP_BLK_CLOSE)] = op_blk_close,
 	[ACTION(A_OP_LOOP_BREAK)] = op_loop_break,
 	[ACTION(A_OP_LOOP_CONTINUE)] = op_loop_continue,
 	[ACTION(A_OP_THROW)] = op_throw,
 	[ACTION(A_OP_PUSH_REF)] = op_push_ref,
 	[ACTION(A_OP_RET_DISCARD)] = op_ret_discard,
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
 	[ACTION(A_OP_IF_ELSE)] = op_if_else,
 	[ACTION(A_OP_TRY_END)] = op_try_end,
 	[ACTION(A_OP_CATCH)] = op_catch,
 	[ACTION(A_OP_VAR_DECL)] = op_var_decl,
 	[ACTION(A_OP_PUSH_TMP)] = op_push_tmp,
 	[ACTION(A_OP_VAR_INIT)] = op_var_init,
 	[ACTION(A_OP_POP_REF)] = op_pop_ref,
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
 	[ACTION(A_OP_ATTR_ASSIGN)] = op_attr_assign,
 	[ACTION(A_OP_ARRAY_ASSIGN)] = op_array_assign,
 	[ACTION(A_OP_CONST_DECL)] = op_const_decl,
 	[ACTION(A_OP_CONST_INIT)] = op_const_init,
 	[ACTION(A_OP_PUSH_INT)] = op_push_int,
 	[ACTION(A_OP_PUSH_STRING)] = op_push_string,
 	[ACTION(A_OP_PUSH_TRUE)] = op_push_true,
 	[ACTION(A_OP_PUSH_FALSE)] = op_push_false,
 	[ACTION(A_OP_CONST_EVAL)] = op_const_eval,
 	[ACTION(A_OP_FPCONST_INIT)] = op_fpconst_init,
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
 	[ACTION(A_OP_RETURN)] = op_return,
 	[ACTION(A_OP_RETVAL)] = op_retval,
 	[ACTION(A_OP_FUN_DEF)] = op_fun_def,
 	[ACTION(A_OP_FUN_END)] = op_fun_end,
 	[ACTION(A_OP_ARG_DECL)] = op_arg_decl,
 	[ACTION(A_OP_FPADD)] = op_fpadd,
 	[ACTION(A_OP_FPSUB)] = op_fpsub,
 	[ACTION(A_OP_FPDIV)] = op_fpdiv,
 	[ACTION(A_OP_FPMUL)] = op_fpmul,
 	[ACTION(A_OP_FPLT)] = op_fplt,
 	[ACTION(A_OP_FPGT)] = op_fpgt,
 	[ACTION(A_OP_FPEQU)] = op_fpequ,
 	[ACTION(A_OP_FPNEQ)] = op_fpneq,
 	[ACTION(A_OP_FPGTE)] = op_fpgte,
 	[ACTION(A_OP_FPLTE)] = op_fplte,
 	[ACTION(A_OP_FPMINUS)] = op_fpminus,
 	[ACTION(A_OP_PUSH_FP)] = op_push_fp,
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
 	"BREAK",
 	"CONTINUE",
 	"FPVAR_ID",
 	"FPFUNC_ID",
 	"DO",
 	"FPCONST_ID",
 	"FPINT",
 	"FPCMP",
 	"NOT",
 	"RETURN",
 	"FUNCTION",
 	"fpmethod_call",
 	"INTFP",
 	"FPLIT",
 	"program",
 	"stat",
 	"semi_stat",
 	"semi_list",
 	"compound_stat",
 	"stat_list",
 	"loop_comp_stat",
 	"loop_stat_list",
 	"exp",
 	"var_list",
 	"const_list",
 	"var_assign",
 	"function_call",
 	"fpvar_assign",
 	"condition",
 	"exp_lst_opt",
 	"else_opt",
 	"catch_opt",
 	"var",
 	"var_list1",
 	"var_init_opt",
 	"var_init_assign",
 	"additive_exp",
 	"div_exp",
 	"mult_exp",
 	"and_exp",
 	"shift_exp",
 	"attr_assign1",
 	"attr_assign",
 	"attr_assign2",
 	"method_call",
 	"const",
 	"const_list1",
 	"const_init",
 	"const_exp",
 	"fpconst_exp",
 	"arg_list_opt",
 	"arg_list",
 	"arg_list1",
 	"exp_lst",
 	"exp_lst1",
 	"cond_exp",
 	"fpexp",
 	"fprelational_exp",
 	"or_exp",
 	"cond_exp1",
 	"or_exp1",
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
 	"func_comp_stat",
 	"func_stat_list",
 	"retval_opt",
 	"function_def",
 	"arg_lst_opt",
 	"arg_lst",
 	"arg_opt",
 	"fpadditive_exp",
 	"fpdiv_exp",
 	"fpmult_exp",
 	"fpattr_assign1",
 	"fpattr_assign",
 	"fpattr_assign2",
 	"fprelational_exp1",
 	"fpadditive_exp1",
 	"fpdiv_exp1",
 	"fpunary_exp",
 	"fpmult_exp1",
 	"fpprimary_exp",
 	"op_blk_open",
 	"op_blk_close",
 	"op_loop_break",
 	"op_loop_continue",
 	"op_throw",
 	"op_push_ref",
 	"op_ret_discard",
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
 	"op_if_else",
 	"op_try_end",
 	"op_catch",
 	"op_var_decl",
 	"op_push_tmp",
 	"op_var_init",
 	"op_pop_ref",
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
 	"op_attr_assign",
 	"op_array_assign",
 	"op_const_decl",
 	"op_const_init",
 	"op_push_int",
 	"op_push_string",
 	"op_push_true",
 	"op_push_false",
 	"op_const_eval",
 	"op_fpconst_init",
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
 	"op_return",
 	"op_retval",
 	"op_fun_def",
 	"op_fun_end",
 	"op_arg_decl",
 	"op_fpadd",
 	"op_fpsub",
 	"op_fpdiv",
 	"op_fpmul",
 	"op_fplt",
 	"op_fpgt",
 	"op_fpequ",
 	"op_fpneq",
 	"op_fpgte",
 	"op_fplte",
 	"op_fpminus",
 	"op_push_fp",
 };

