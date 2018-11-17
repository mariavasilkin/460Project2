#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::more_defines() {
    int errors = 0;
    string function_name = "More_Defines";

    write_project_enter(function_name);

    if (token == DEFINE_T) {
      // apply rule 2
      // <more_defines> -> <define> LPAREN_T <more_defines>
      write_project_rule(2);
      
      errors += define();
      if (token == LPAREN_T) {
	token = lex->GetToken();
      } else {

	errors++;
      }
      errors+= more_defines();
    }

    else if (token == IDENT_T) {
      // apply rule 3
      // <more_defines> -> IDENT_T <stmt_list> RPAREN_T
      write_project_rule(3);
      
      token = lex->GetToken();
      errors += stmt_list();
      if (token == RPAREN_T) {
	token = lex->GetToken();
      } else {
	report_error();
	errors++;
      }
    }

    else {
      report_error();
      errors++;
    }

    write_project_exit(function_name);
    return errors;
}
