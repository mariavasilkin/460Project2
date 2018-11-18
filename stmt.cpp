#include "SyntacticalAnalyzer.h"

using namespace std;

void SyntacticalAnalyzer::stmt() {
  string function_name = "Stmt";
  string error_message = "";
  write_project_enter(function_name);
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
      error_message = "RPAREN_T expected";
      lex->ReportError(error_message);
  }
  write_project_exit(function_name);
}
