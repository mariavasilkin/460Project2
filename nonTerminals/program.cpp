#include "../SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::program() {
    string function_name = "Program";
    string error_message = "";
    write_project_enter(function_name);

    if (token == LPAREN_T) {
      // apply rule 1
      // <program> -> LPAREN_T <define> LPAREN_T <more_defines> EOF_T
      write_project_rule(1);

      token = lex->GetToken();
      define();
      if (token == LPAREN_T) {
	token = lex->GetToken();
      } else {
          error_message = "LPAREN_T expected";
          lex->ReportError(error_message);
      }
      more_defines();
      if (token == EOF_T) {
      } else {
          error_message = "EOF_T expected";
          lex->ReportError(error_message);
      }
    } else {
        error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
        lex->ReportError(error_message);
    }

    write_project_enter(function_name);
}
