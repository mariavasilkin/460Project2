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

 private:
	LexicalAnalyzer * lex;
	token_type token;

	void write_project_enter (string _function_name);
        void write_project_rule (int rule);
        void write_project_exit (string _function_name);

        void program();
        void more_defines();
        void define();
        void stmt_list();
        void stmt();
        void literal();
        void quoted_lit();
        void more_tokens();
        void param_list();
        void else_part();
        void stmt_pair();
        void stmt_pair_body();
        void action();
        void any_other_token();
	
	bool is_action (string _token_name);
	bool is_any_other (string _token_name);
	
	int errors;

	ofstream project_file;
};
	
#endif
