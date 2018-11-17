#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt_list() {
  string function_name = "Stmt_List";
  write_project_enter(function_name);

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
    write_project_rule(5);

  }

  else {
    string error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }
  
  write_project_exit(function_name);
  return;
}
