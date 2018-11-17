#include "../SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::stmt_pair_body() {
  string function_name = "Stmt_Pair_Body";
  string error_message = "";
  write_function_enter(function_name);
  if (token == ELSE_T) {
    // apply rule 23
    // <stmt_pair_body> -> ELSE_T <stmt> RPAREN_T
    write_project_rule(23);

    token = lex->GetToken();
    stmt();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      error_message = "RPAREN_T expected";
      lex->ReportError(error_message);
    }
  }

  else if (token == NUMLIT_T || token == STRLIT_T || token == SQUOTE_T || token == IDENT_T || token == LPAREN_T) { // doing it in this order to avoid this conditional
    // apply rule 22
    // <stmt_pair_body> -> <stmt> <stmt> RPAREN_T <stmt_pair>
    write_project_rule(22);

    stmt();
    stmt();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      error_message = "RPAREN_T expected";
      lex->ReportError(error_message);
    }
    stmt_pair();
  }

  else {
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }
}
