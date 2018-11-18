#include "SyntacticalAnalyzer.h"

using namespace std;

void SyntacticalAnalyzer::stmt_pair() {
  string function_name = "Stmt_Pair";
  write_project_enter(function_name);

  if (token == LPAREN_T) {
    // apply rule 20
    // <stmt_pair> -> LPAREN_T <stmt_pair_body>
    write_project_rule(20);

    token = lex->GetToken();
    stmt_pair_body();
  }

  else if (token == RPAREN_T) {
    // apply rule 21
    // <stmt_pair> -> {}
    write_project_rule(21);

  }

  else {
    string error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }

  write_project_exit(function_name);
}
