#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::quoted_lit() {
  string function_name = "Quoted_Lit";
  write_project_enter(function_name);

  bool any_other = is_any_other(lex->GetTokenName(token));
  if (any_other) {
    // apply rule 13
    // <quoted_lit> -> <any_other_token>
    write_project_rule(13);

    any_other_token();
  } else {
    string error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_rule(function_name);
  return;
}
