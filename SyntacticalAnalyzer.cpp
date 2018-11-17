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
	project_file.open (projec_name.c_str());
	// program ();
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
  for (int i = 0; i < 26; i++) {
    if (action_tokens[i] == _token_name) {
      return true;
    }
  }
  return false;
}

bool SyntacticalAnalyzer::is_any_other (string _token_name) {
  for (int i = 0; i < ; i++) {
    if (any_other_tokens[i] == _token_name) {
      return true;
    }
  }
  return false;
}

void SyntacticalAnalyzer::report_error() {
  string message = "'" + lex->GetLexeme() + "'" + " unexpected";
  lex->ReportError(message);
  return;
}
