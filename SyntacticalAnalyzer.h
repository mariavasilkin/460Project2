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
};
	
#endif
