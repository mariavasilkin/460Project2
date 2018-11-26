/***********************************************************************************
Author: Maria Vasilkin, Dylan Marcus, John Salman
Assignment: CS460 Project 2
Date: 11/25/18
File: SyntacticalAnalyzer.cpp
Description: Implementation of SyntacticalAnalyzer class methods and private functions.

***********************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "SyntacticalAnalyzer.h"

using namespace std;

SyntacticalAnalyzer::SyntacticalAnalyzer (char * filename)
{
	lex = new LexicalAnalyzer (filename);
	token = lex->GetToken();
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
                                      "EQUALTO_T", "GT_T", "LT_T", "GTE_T", "LTE_T", "SQUOTE_T", "COND_T", "ELSE_T"};
  for (int i = 0; i < 32; i++) {
    if (any_other_tokens[i] == _token_name) {
      return true;
    }
  }
  return false;
}

/*******************
ACTION; RULES 24-49
*******************/

void SyntacticalAnalyzer::action() {
  string function_name = "Action";
  string error_message = "";
  write_project_enter (function_name);

  while (!(is_action(lex->GetTokenName(token))) && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == IF_T) {
    // apply rule 24
    //<action> -> IF_T <stmt> <stmt> <else_part>
    write_project_rule(24);

    token = lex->GetToken();
    stmt();
    stmt();
    else_part();
  }

  else if (token == COND_T) {
    // apply rule 25
    // <action> -> COND_T LPAREN_T <stmt_pair_body>
    write_project_rule(25);

    token = lex->GetToken();
    if (token == LPAREN_T) {
      token = lex->GetToken();
    } else {
        error_message = "LPAREN_T expected";
        lex->ReportError(error_message);
        token = lex->GetToken();
    }
    stmt_pair_body();
  }

  else if (token == LISTOP_T) {
    // apply rule 26
    // <action> -> LISTOP_T <stmt>
    write_project_rule(26);

    token = lex->GetToken();
    stmt();
  }

  else if (token == CONS_T) {
    // apply rule 27
    // <action> -> CONS_T <stmt> <stmt>
    write_project_rule(27);

    token = lex->GetToken();
    stmt();
    stmt();
  }

  else if (token == AND_T) {
    // apply rule 28
    // <action> -> AND_T <stmt_list>
    write_project_rule(28);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == OR_T) {
    // apply rule 29
    // <action> -> OR_T <stmt_list>
    write_project_rule(29);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == NOT_T) {
    // apply rule 30
    // <action> -> NOT_T <stmt>
    write_project_rule(30);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NUMBERP_T) {
    // apply rule 31
    // <action> -> NUMBERP_T <stmt>
    write_project_rule(31);

    token = lex->GetToken();
    stmt();
  }

  else if (token == LISTP_T) {
    // apply rule 32
    // <action> -> LISTP_T <stmt>
    write_project_rule(32);

    token = lex->GetToken();
    stmt();
  }

  else if (token == ZEROP_T) {
    // apply rule 33
    // <action> -> LISTP_T <stmt>
    write_project_rule(33);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NULLP_T) {
    // apply rule 34
    // <action> -> NULLP_T <stmt>
    write_project_rule(34);

    token = lex->GetToken();
    stmt();
  }

  else if (token == STRINGP_T) {
    // apply rule 35
    // <action> -> STRINGP_T <stmt>
    write_project_rule(35);

    token = lex->GetToken();
    stmt();
  }

  else if (token == PLUS_T) {
    // apply rule 36
    // <action> -> PLUS_T <stmt_list>
    write_project_rule(36);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == MINUS_T) {
    // apply rule 37
    // <action> -> MINUS_T <stmt> <stmt_list>
    write_project_rule(37);

    token = lex->GetToken();
    stmt();
    stmt_list();
  }

  else if (token == DIV_T) {
    // apply rule 38
    // <action> -> DIV_T <stmt> <stmt_list>
    write_project_rule(38);

    token = lex->GetToken();
    stmt();
    stmt_list();
  }

  else if (token == MULT_T) {
    // apply rule 39
    // <action> -> MULT_T <stmt_list>
    write_project_rule(39);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == MODULO_T) {
    // apply rule 40
    // <action> -> MODULO_T <stmt> <stmt>
    write_project_rule(40);

    token = lex->GetToken();
    stmt();
    stmt();
  }

  else if (token == ROUND_T) {
    // apply rule 41
    // <action> -> ROUND_T <stmt>
    write_project_rule(41);

    token = lex->GetToken();
    stmt();
  }

  else if (token == EQUALTO_T) {
    // apply rule 42
    // <action> -> EQUALTO_T <stmt_list>
    write_project_rule(42);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == GT_T) {
    // apply rule 43
    // <action> -> GT_T <stmt_list>
    write_project_rule(43);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == LT_T) {
    // apply rule 44
    // <action> -> LT_T <stmt_list>
    write_project_rule(44);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == GTE_T) {
    // apply rule 45
    // <action> -> GTE_T <stmt_list>
    write_project_rule(45);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == LTE_T) {
    // apply rule 46
    // <action> -> LTE_T <stmt_list>
    write_project_rule(46);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == IDENT_T) {
    // apply rule 47
    // <action> -> IDENT_T <stmt_list>
    write_project_rule(47);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == DISPLAY_T) {
    // apply rule 48
    // <action> -> DISPLAY_T <stmt>
    write_project_rule(48);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NEWLINE_T) {
    // apply rule 49
    // <action> -> NEWLINE_T
    write_project_rule(49);

    token = lex->GetToken();
  }

  else {
    // no match to any rules
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}

/***********************
ANY_OTHER; RULES: 50-81
***********************/
void SyntacticalAnalyzer::any_other_token() {
  string function_name = "Any_Other_Token";
  string error_message = "";
  write_project_enter(function_name);

  while (!(is_any_other(lex->GetTokenName(token))) && token != EOF_T){
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == LPAREN_T) {
    // apply rule 50
    // <any_other_token> -> LPAREN_T <more_tokens> RPAREN_T
    write_project_rule(50);

    token = lex->GetToken();
    more_tokens();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
        error_message = "RPAREN_T expected";
        lex->ReportError(error_message);
    }
  }

  else if (token == IDENT_T) {
    // apply rule 51
    // <any_other_token> -> IDENT_T
    write_project_rule(51);

    token = lex->GetToken();
  }

  else if (token == NUMLIT_T) {
    // apply rule 52
    // <any_other_token> -> NUMLIT_T
    write_project_rule(52);

    token = lex->GetToken();
  }

  else if (token == STRLIT_T) {
    // apply rule 53
    // <any_other_token> -> STRLIT_T
    write_project_rule(53);

    token = lex->GetToken();
  }

  else if (token == CONS_T) {
    // apply rule 54
    // <any_other_token> -> CONS_T
    write_project_rule(54);

    token = lex->GetToken();
  }

  else if (token == IF_T) {
    // apply rule 55
    // <any_other_token> -> IF_T
    write_project_rule(55);

    token = lex->GetToken();
  }

  else if (token == DISPLAY_T) {
    // apply rule 56
    // <any_other_token> -> DISPLAY_T
    write_project_rule(56);

    token = lex->GetToken();
  }

  else if (token == NEWLINE_T) {
    // apply rule 57
    // <any_other_token> -> NEWLINE_T
    write_project_rule(57);

    token = lex->GetToken();
  }

  else if (token == LISTOP_T) {
    // apply rule 58
    // <any_other_token> -> LISTOP_T
    write_project_rule(58);

    token = lex->GetToken();
  }

  else if (token == AND_T) {
    // apply rule 59
    // <any_other_token> -> AND_T
    write_project_rule(59);

    token = lex->GetToken();
  }

  else if (token == OR_T) {
    // apply rule 60
    // <any_other_token> -> OR_T
    write_project_rule(60);

    token = lex->GetToken();
  }

  else if (token == NOT_T) {
    // apply rule 61
    // <any_other_token> -> NOT_T
    write_project_rule(61);

    token = lex->GetToken();
  }

  else if (token == DEFINE_T) {
    // apply rule 62
    // <any_other_token> -> DEFINE_T
    write_project_rule(62);

    token = lex->GetToken();
  }

  else if (token == NUMBERP_T) {
    // apply rule 63
    // <any_other_token> -> NUMBERP_T
    write_project_rule(63);

    token = lex->GetToken();
  }

  else if (token == LISTP_T) {
    // apply rule 64
    // <any_other_token> -> LISTP_T
    write_project_rule(64);

    token = lex->GetToken();
  }

  else if (token == ZEROP_T) {
    // apply rule 65
    // <any_other_token> -> ZEROP_T
    write_project_rule(65);

    token = lex->GetToken();
  }

  else if (token == NULLP_T) {
    // apply rule 66
    // <any_other_token> -> NULLP_T
    write_project_rule(66);

    token = lex->GetToken();
  }

  else if (token == STRINGP_T) {
    // apply rule 67
    // <any_other_token> -> STRINGP_T
    write_project_rule(67);

    token = lex->GetToken();
  }

  else if (token == PLUS_T) {
    // apply rule 68
    // <any_other_token> -> PLUS_T
    write_project_rule(68);

    token = lex->GetToken();
  }

  else if (token == MINUS_T) {
    // apply rule 69
    // <any_other_token> -> MINUS_T
    write_project_rule(69);

    token = lex->GetToken();
  }

  else if (token == DIV_T) {
    // apply rule 70
    // <any_other_token> -> DIV_T
    write_project_rule(70);

    token = lex->GetToken();
  }

  else if (token == MULT_T) {
    // apply rule 71
    // <any_other_token> -> MULT_T
    write_project_rule(71);

    token = lex->GetToken();
  }

  else if (token == MODULO_T) {
    // apply rule 72
    // <any_other_token> -> MODULO_T
    write_project_rule(72);

    token = lex->GetToken();
  }

  else if (token == ROUND_T) {
    // apply rule 73
    // <any_other_token> -> ROUND_T
    write_project_rule(73);

    token = lex->GetToken();
  }

  else if (token == EQUALTO_T) {
    // apply rule 74
    // <any_other_token> -> EQUALTO_T
    write_project_rule(74);

    token = lex->GetToken();
  }

  else if (token == GT_T) {
    // apply rule 75
    // <any_other_token> -> GT_T
    write_project_rule(75);

    token = lex->GetToken();
  }

  else if (token == LT_T) {
    // apply rule 76
    // <any_other_token> -> LT_T
    write_project_rule(76);

    token = lex->GetToken();
  }

  else if (token == GTE_T) {
    // apply rule 77
    // <any_other_token> -> GTE_T
    write_project_rule(77);

    token = lex->GetToken();
  }

  else if (token == LTE_T) {
    // apply rule 78
    // <any_other_token> -> LTE_T
    write_project_rule(78);

    token = lex->GetToken();
  }

  else if (token == SQUOTE_T) {
    // apply rule 79
    // <any_other_token> -> SQUOTE_T <any_other_token>
    write_project_rule(79);

    token = lex->GetToken();
    any_other_token();
  }

  else if (token == COND_T) {
    // apply rule 80
    // <any_other_token> -> COND_T
    write_project_rule(80);

    token = lex->GetToken();
  }

  else if (token == ELSE_T) {
    // apply rule 81
    // <any_other_token> -> COND_T
    write_project_rule(81);

    token = lex->GetToken();
  }

  else {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
      lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}

/****************
DEFINE; RULES: 4
****************/
void SyntacticalAnalyzer::define() {
    string function_name = "Define";
    string error_message = "";
    write_project_enter(function_name);

    while (token != DEFINE_T && token != EOF_T) {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
      lex->ReportError(error_message);
      token = lex->GetToken();
    }

    if (token == DEFINE_T) {
      // applying rule 4
      //<define> -> DEFINE_T LPAREN_T IDENT_T <param_list> RPAREN_T <stmt> <stmt_list> RPAREN_T
      write_project_rule(4);

      token = lex->GetToken();
      if (token == LPAREN_T) {
          token = lex->GetToken();
      } else {
          error_message = "LPAREN_T expected";
          lex->ReportError(error_message);
          token = lex->GetToken();
      }
      if (token == IDENT_T) {
          token = lex->GetToken();
      } else {
          error_message = "IDENT_T expected";
          lex->ReportError(error_message);
          token = lex->GetToken();
      }
      param_list();
      if (token == RPAREN_T) {
          token = lex->GetToken();
      } else {
          error_message = "RPAREN_T expected";
          lex->ReportError(error_message);
          token = lex->GetToken();
      }
      stmt();
      stmt_list();
      if (token == RPAREN_T) {
          token = lex->GetToken();
      } else {
          error_message = "RPAREN_T expected";
          lex->ReportError(error_message);
      }
    } else {
        error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
        lex->ReportError(error_message);
    }
    write_project_exit(function_name);
}

void SyntacticalAnalyzer::else_part() {
  string function_name = "Else_Part";
  string error_message = "";
  write_project_enter(function_name);

  while (token != RPAREN_T && token != NUMLIT_T && token != STRLIT_T && token != SQUOTE_T && token != IDENT_T && token != LPAREN_T && token != EOF_T){
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }
  
  if (token == RPAREN_T) {
    // apply rule 19
    // <else_part> -> {}
    write_project_rule(19);
  }

  else if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T || token == IDENT_T || token == LPAREN_T) {
    // apply rule 18
    // <else_part> -> <stmt>
    write_project_rule(18);

    stmt();
  }

  else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}

void SyntacticalAnalyzer::literal() {
  string function_name = "Literal";
  string error_message = "";
  write_project_enter(function_name);
  
  while (token != NUMLIT_T && token != STRLIT_T && token != SQUOTE_T && token != EOF_T){
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == NUMLIT_T) {
    // apply rule 10
    // <literal> -> NUMLIT_T
    write_project_rule(10);

    token = lex->GetToken();
  }

  else if (token == STRLIT_T) {
    // apply rule 11
    // <literal> -> STRLIT_T
    write_project_rule(11);

    token = lex->GetToken();
  }

  else if (token == SQUOTE_T) {
    // apply rule 12
    // <literal> -> SQUOTE_T <quoted_lit>
    write_project_rule(12);

    token = lex->GetToken();
    quoted_lit();
  }

  else {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
      lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}

void SyntacticalAnalyzer::more_defines() {
    string function_name = "More_Defines";
    string error_message = "";
    write_project_enter(function_name);

    while (token != DEFINE_T && token != IDENT_T && token != EOF_T) {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
      lex->ReportError(error_message);
      token = lex->GetToken();
    }

    if (token == DEFINE_T) {
      // apply rule 2
      // <more_defines> -> <define> LPAREN_T <more_defines>
      write_project_rule(2);

      define();
      if (token == LPAREN_T) {
          token = lex->GetToken();
      } else {
          error_message = "LPAREN_T expected";
          lex->ReportError(error_message);
      }
      more_defines();
    }

    else if (token == IDENT_T) {
      // apply rule 3
      // <more_defines> -> IDENT_T <stmt_list> RPAREN_T
      write_project_rule(3);

      token = lex->GetToken();
      stmt_list();
      if (token == RPAREN_T) {
        token = lex->GetToken();
      } else {
        error_message = "RPAREN_T expected";
        lex->ReportError(error_message);
      }
    }

    else {
        error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
        lex->ReportError(error_message);
    }

    write_project_exit(function_name);
}

void SyntacticalAnalyzer::more_tokens() {
  string function_name = "More_Tokens";
  string error_message = "";
  write_project_enter(function_name);

  bool any_other = false;
  while (!(any_other = is_any_other(lex->GetTokenName(token))) && token != RPAREN_T && token != EOF_T){
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";      
    lex->ReportError(error_message);
    token = lex->GetToken();
  }
  
  if (token == RPAREN_T) {
    // apply rule 15
    // <more_tokens> -> {}
    write_project_rule(15);
  } else if (any_other) {
    // apply rule 14
    // <more_tokens> -> <any_other_token> <more_tokens>
    write_project_rule(14);

    any_other_token();
    more_tokens();
  } else {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
      lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}

void SyntacticalAnalyzer::param_list() {
  string function_name = "Param_List";
  string error_message = "";
  write_project_enter(function_name);

  while (token != IDENT_T && token != RPAREN_T && token != EOF_T){
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";      
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == IDENT_T) {
    // apply rule 16
    // <param_list> -> IDENT_T <param_list>
    write_project_rule(16);

    token = lex->GetToken();
    param_list();
  } else if (token == RPAREN_T) {
    // apply rule 17
    // <param_list> -> {}
    write_project_rule(17);

  } else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}

void SyntacticalAnalyzer::program() {
    string function_name = "Program";
    string error_message = "";
    write_project_enter(function_name);

    while (token != LPAREN_T && token != EOF_T) {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";      
      lex->ReportError(error_message);
      token = lex->GetToken();
    }
    if (token == LPAREN_T) {
      // apply rule 1
      // <program> -> LPAREN_T <define> LPAREN_T <more_defines> EOF_T
      write_project_rule(1);

      token = lex->GetToken();
      define();
      if (token == LPAREN_T) {
        token = lex->GetToken();
      } else {
          error_message = "LPAREN_T expected";
          lex->ReportError(error_message);
	  token = lex->GetToken();
      }
      more_defines();
      if (token == EOF_T) {
      } else {
          error_message = "EOF_T expected";
          lex->ReportError(error_message);
      }
    } else {
        error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
        lex->ReportError(error_message);
    }

    write_project_exit(function_name);
}

void SyntacticalAnalyzer::stmt() {
  string function_name = "Stmt";
  string error_message = "";
  write_project_enter(function_name);

  while (token != NUMLIT_T && token != STRLIT_T && token != SQUOTE_T && token != IDENT_T && token != LPAREN_T && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";      
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T) {
    // apply rule 7
    // <stmt> -> <literal>
    write_project_rule(7);
    literal();
  }

  else if (token == IDENT_T) {
    // apply rule 8
    // <stmt> -> IDENT_T
    write_project_rule(8);

    token = lex->GetToken();
  }

  else if (token == LPAREN_T) {
    // apply rule 9
    // <stmt> -> LPAREN_T <action> RPAREN_T
    write_project_rule(9);

    token = lex->GetToken();
    action();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
        error_message = "RPAREN_T expected";
        lex->ReportError(error_message);
    }
  }

  else {
      error_message = "'" + lex->GetLexeme() + "'" + " unexpected";      
      lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}

void SyntacticalAnalyzer::stmt_list() {
  string function_name = "Stmt_List";
  string error_message = "";
  write_project_enter(function_name);

  while (token != RPAREN_T && token != NUMLIT_T && token != STRLIT_T && token != SQUOTE_T && token != IDENT_T && token != LPAREN_T && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T || token == IDENT_T || token == LPAREN_T) {
    // apply rule 5
    // <stmt_list> -> <stmt> <stmt_list>
    write_project_rule(5);

    stmt();
    stmt_list();
  }

  else if (token == RPAREN_T) {
    // apply rule 6
    // <stmt_list> -> {}
    write_project_rule(6);

  }

  else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}

void SyntacticalAnalyzer::stmt_pair() {
  string function_name = "Stmt_Pair";
  string error_message = "";
  write_project_enter(function_name);

  while (token != LPAREN_T && token != RPAREN_T && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == LPAREN_T) {
    // apply rule 20
    // <stmt_pair> -> LPAREN_T <stmt_pair_body>
    write_project_rule(20);

    token = lex->GetToken();
    stmt_pair_body();
  }

  else if (token == RPAREN_T) {
    // apply rule 21
    // <stmt_pair> -> {}
    write_project_rule(21);

  }

  else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}

void SyntacticalAnalyzer::stmt_pair_body() {
  string function_name = "Stmt_Pair_Body";
  string error_message = "";
  write_project_enter(function_name);

  while (token != ELSE_T && token != RPAREN_T && token != NUMLIT_T && token != STRLIT_T && token != SQUOTE_T && token != IDENT_T && token != LPAREN_T && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (token == ELSE_T) {
    // apply rule 23
    // <stmt_pair_body> -> ELSE_T <stmt> RPAREN_T
    write_project_rule(23);

    token = lex->GetToken();
    stmt();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      error_message = "RPAREN_T expected";
      lex->ReportError(error_message);
    }
  }

  else if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T || token == IDENT_T || token == LPAREN_T) { // doing it in this order to avoid this conditional
    // apply rule 22
    // <stmt_pair_body> -> <stmt> <stmt> RPAREN_T <stmt_pair>
    write_project_rule(22);

    stmt();
    stmt();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      error_message = "RPAREN_T expected";
      lex->ReportError(error_message);
    }
    stmt_pair();
  }

  else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}

void SyntacticalAnalyzer::quoted_lit() {
  string function_name = "Quoted_Lit";
  string error_message = "";
  write_project_enter(function_name);
  
  bool any_other = false;
  while (!(any_other = is_any_other(lex->GetTokenName(token))) && token != EOF_T) {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
    token = lex->GetToken();
  }

  if (any_other) {
    // apply rule 13
    // <quoted_lit> -> <any_other_token>
    write_project_rule(13);

    any_other_token();
  } else {
    string error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}
