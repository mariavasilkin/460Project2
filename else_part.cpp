#include "SyntacticalAnalyzer.h"

using namespace std;

void SyntacticalAnalyzer::else_part() {
  string function_name = "Else_Part";
  string error_message = "";
  write_project_enter(function_name);
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
