/***********************************************************************************
Author: Maria Vasilkin, Dylan Marcus, John Salman
Assignment: CS460 Project 2
Date: 11/25/18
File: SyntacticalAnalyzer.cpp
Description: Definition of SyntacticalAnalyzer methods, private functions, and variables.
***********************************************************************************/

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

	bool is_action (string _token_name);
	bool is_any_other (string _token_name);
	
	int errors;

	ofstream project_file;
};
	
#endif
