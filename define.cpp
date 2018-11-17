#include "SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::define() {
    string function_name = "Define";
    string error_message = "";
    write_project_enter(function_name);

    //checking rule 4
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
      }
      if (token == IDENT_T) {
	  token = lex->GetToken();
      } else {
          error_message = "IDENT_T expected";
          lex->ReportError(error_message);
      }
      param_list();
      if (token == RPAREN_T) {
	token = lex->GetToken();
      } else {
          error_message = "RPAREN_T expected";
          lex->ReportError(error_message);
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
    write_project_rule(function_name);
}
