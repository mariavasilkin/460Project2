#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::else_part() {
  int errors = 0;
  string function_name = "Else_Part";

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

    errors += stmt();
  } 

  else {
    report_error();
    errors++;
  }

  write_project_exit(function_name);
  return errors;
}
