#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

SyntacticalAnalyzer::SyntacticalAnalyzer (char * filename)
{
	lex = new LexicalAnalyzer (filename);
	//token_type token;
	// we can skip a lot of error checking on files as watts already made them
	string name = filename;
	string project_name = name.substr (0, name.length()-3) + ".p2";
	project_file.open (project_name.c_str());
	program ();
}

SyntacticalAnalyzer::~SyntacticalAnalyzer ()
{
	delete lex;
}

void SyntacticalAnalyzer::write_project_enter (string _function_name) {
  project_file << "Entering " << _function_name << " function; current token is: " << lex->GetTokenName(token) << ", lexeme: " <<  lex->GetLexeme() << endl;
  return;
}

void SyntacticalAnalyzer::write_project_rule (int rule) {
    project_file << "Using Rule " << rule << endl;
    return;
}

void SyntacticalAnalyzer::write_project_exit (string _function_name) {
  project_file << "Exiting " << _function_name << " function; current token is: " << lex->GetTokenName(token) << endl;
  return;
}

bool SyntacticalAnalyzer::is_action (string _token_name) {
  string action_tokens [] = {"IF_T", "COND_T", "LISTOP_T", "CONS_T", "AND_T", "OR_T", "NOT_T",
                                   "NUMBERP_T", "LISTP_T", "ZEROP_T", "NULLP_T", "STRINGP_T", "PLUS_T",
                                   "MINUS_T", "DIV_T", "MULT_T", "MODULO_T", "ROUND_T", "EQUALTO_T",
                                   "GT_T", "LT_T", "GTE_T", "LTE_T", "IDENT_T", "DISPLAY_T", "NEWLINE_T"};
  for (int i = 0; i < 26; i++) {
    if (action_tokens[i] == _token_name) {
      return true;
    }
  }
  return false;
}

bool SyntacticalAnalyzer::is_any_other (string _token_name) {
  string any_other_tokens [] = {"LPAREN_T", "IDENT_T", "NUMLIT_T", "STRLIT_T", "CONS_T", "IF_T",
                                      "DISPLAY_T", "NEWLINE_T", "LISTOP_T", "AND_T", "OR_T","NOT_T",
                                      "DEFINE_T", "NUMBERP_T", "LISTP_T", "ZEROP_T", "NULLP_T", "STRINGP_T",
                                      "PLUS_T", "MINUS_T", "DIV_T", "MULT_T", "MODULO_T", "ROUND_T",
                                      "EQUALTO_T", "GT_T", "LT_T", "GTE_T", "LTE_T", "QUOTE_T", "COND_T", "ELSE_T"};
  for (int i = 0; i < 32; i++) {
    if (any_other_tokens[i] == _token_name) {
      return true;
    }
  }
  return false;
}


