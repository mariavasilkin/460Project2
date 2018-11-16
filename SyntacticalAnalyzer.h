#ifndef SYN_H
#define SYN_H

#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"

using namespace std;

class SyntacticalAnalyzer 
{
 public:
	SyntacticalAnalyzer (char * filename);
	~SyntacticalAnalyzer ();

	void write_project_enter (string _function_name);
	void write_project_rule (int rule);
	void write_project_exit (string _function_name);

	void report_error();
	
	int program();
	int more_defines();
	int define();
	int stmt_list();
	int stmt();
	int literal();
	int quoted_lit();
	int more_tokens();
	int param_list();
	int else_part();
	int stmt_pair();
	int stmt_pair_body();
	int action();
	int any_other_token();
 private:
	LexicalAnalyzer * lex;
	token_type token;

	string action_tokens [] = {"IF_T", "COND_T", "LISTOP_T", "CONS_T", "AND_T", "OR_T", "NOT_T",
				   "NUMBERP_T", "LISTP_T", "ZEROP_T", "NULLP_T", "STRINGP_T", "PLUS_T",
				   "MINUS_T", "DIV_T", "MULT_T", "MODULO_T", "ROUND_T", "EQUALTO_T",
				   "GT_T", "LT_T", "GTE_T", "LTE_T", "IDENT_T", "DISPLAY_T", "NEWLINE_T"}

	int errors;

	ofstream project_file;
};
	
#endif
