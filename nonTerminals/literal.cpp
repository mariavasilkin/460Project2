#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::literal() {
  int errors = 0;
  string function_name = "Literal";
  write_project_enter(function_name);
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
    errors += quoted_lit();
  }

  else {
    report_error();
  }

  write_project_exit(function_name);
  return errors;
}
