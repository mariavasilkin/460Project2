#include "SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::param_list() {
  string function_name = "Param_List";
  write_project_enter(function_name);

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
    string message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(message);
  }

  write_project_exit(function_name);
}
