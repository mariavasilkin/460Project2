#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::define() {
    int errors = 0;
    string function_name = "Define";
    write_project_enter(function_name);

    //checking rule 4
    if (token == DEFINE_T) {
      // applying rule 4
      //<define> -> DEFINE_T LPAREN_T IDENT_T <param_list> RPAREN_T <stmt> <stmt_list> RPAREN_T
      write_project_rule(4);
      
      token = lex->GetToken();
      if (token == LPAREN_T) {
	token = lex->GetToken();
      } else {
	
	errors++;
      }
      if (token == IDENT_T) {
	  token = lex->GetToken();
      } else {
	errors++;
      }
      errors += param_list();
      if (token == RPAREN_T) {
	token = lex->GetToken();
      } else {
	errors++;
      }
      errors += stmt();
      errors += stmt_list();
      if (token == RPAREN_T) {
	  token = lex->GetToken();
      } else {
	errors++;
      }
    } else {   
      errors++;
    }
    write_project_rule(function_name);
    return errors;
}
