#include "../SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::more_defines() {
    string function_name = "More_Defines";
    string error_message = "";
    write_project_enter(function_name);

    if (token == DEFINE_T) {
      // apply rule 2
      // <more_defines> -> <define> LPAREN_T <more_defines>
      write_project_rule(2);

      define();
      if (token == LPAREN_T) {
	token = lex->GetToken();
      } else {
          error_message = "LPAREN_T expected";
          lex->ReportError(error_message);
      }
      more_defines();
    }

    else if (token == IDENT_T) {
      // apply rule 3
      // <more_defines> -> IDENT_T <stmt_list> RPAREN_T
      write_project_rule(3);

      token = lex->GetToken();
      stmt_list();
      if (token == RPAREN_T) {
	token = lex->GetToken();
      } else {
        error_message = "RPAREN_T expected";
        lex->ReportError(error_message);
      }
    }

    else {
        error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
        lex->ReportError(error_message);
    }

    write_project_exit(function_name);
}
