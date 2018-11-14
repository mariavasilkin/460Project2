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

	program();
	more_defines();
	define();
	stmt_list();
	stmt();
	literal();
	quoted_lit();
	more_tokens();
	param_list();
	else_part();
	stmt_pair();
	stmt_pair_body();
	action();
	any_other_token();
 private:
	LexicalAnalyzer * lex;
	token_type token;
};
	
#endif
