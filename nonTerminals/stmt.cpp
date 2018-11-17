#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::stmt() {
  int errors = 0;
  string function_name = "Stmt";

  write_project_enter(function_name);
  if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T) {
    // apply rule 7
    // <stmt> -> <literal>
    write_project_rule(7);
    errors += literal();
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
    errors += action();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      report_error();
    }
  }

  else {
    report_error();
    errors++;
  }

  write_project_exit(function_name);
  return errors;
}
