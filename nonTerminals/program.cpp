#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::program() {
    int errors = 0;
    string function_name = "Program";
    write_project_enter(function_name);
        
    if (token == LPAREN_T) {
      // apply rule 1
      // <program> -> LPAREN_T <define> LPAREN_T <more_defines> EOF_T
      write_project_rule(1);
      
      token = lex->GetToken();
      errors += define();
      if (token == LPAREN_T) {
	token = lex->GetToken();
      } else {
	report_error();
	errors++;
      }
      errors += more_defines();
      if (token == EOF_T) {
      } else {
	report_error();
	errors++;
      }
    } else { 
      report_error();
      errors++;
    }
    
    write_project_enter(function_name);
    return errors;
}
