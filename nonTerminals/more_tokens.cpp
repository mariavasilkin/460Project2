#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::more_tokens() {
  int errors = 0;
  string function_name = "More_Tokens";
  
  write_project_enter(function_name);
  if (token == RPAREN_T) {
    // apply rule 15
    // <more_tokens> -> {}
    write_project_rule(15);
  } else if (token != RPAREN_T) { // doing this to prevent uneccessary calls to is_action() 
    bool action = is_action(lex->GetTokenName(token));
    if (action) {
      // apply rule 14
      // <more_tokens> -> <any_other_token> <more_tokens>
      write_project_rule(14);
      
      errors += any_other_token();
      errors += more_tokens();
    }
  } else {
    report_error();
  }
  
  write_project_exit(function_name);
  return errors;
}
