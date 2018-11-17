#include "SyntacticalAnalyzer.h"

void SyntacticalAnalyzer::action() {
  string function_name = "Action";
  string error_message = "";
  write_project_enter (function_name);

  if (token == IF_T) {
    // apply rule 24
    //<action> -> IF_T <stmt> <stmt> <else_part>
    write_project_rule(24);

    token = lex->GetToken();
    stmt();
    stmt();
    else_part();
  }

  else if (token == COND_T) {
    // apply rule 25
    // <action> -> COND_T LPAREN_T <stmt_pair_body>
    write_project_rule(25);

    token = lex->GetToken();
    if (token == LPAREN_T) {
      token = lex->GetToken();
    } else {
        error_message = "LPAREN_T expected";
        lex->ReportError(error_message);
    }
    stmt_pair_body();
  }

  else if (token == LISTOP_T) {
    // apply rule 26
    // <action> -> LISTOP_T <stmt>
    write_project_rule(26);

    token = lex->GetToken();
    stmt();
  }

  else if (token == CONS_T) {
    // apply rule 27
    // <action> -> CONS_T <stmt> <stmt>
    write_project_rule(27);

    token = lex->GetToken();
    stmt();
    stmt();
  }

  else if (token == AND_T) {
    // apply rule 28
    // <action> -> AND_T <stmt_list>
    write_project_rule(28);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == OR_T) {
    // apply rule 29
    // <action> -> OR_T <stmt_list>
    write_project_rule(29);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == NOT_T) {
    // apply rule 30
    // <action> -> NOT_T <stmt>
    write_project_rule(30);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NUMBERP_T) {
    // apply rule 31
    // <action> -> NUMBERP_T <stmt>
    write_project_rule(31);

    token = lex->GetToken();
    stmt();
  }

  else if (token == LISTP_T) {
    // apply rule 32
    // <action> -> LISTP_T <stmt>
    write_project_rule(32);

    token = lex->GetToken();
    stmt();
  }

  else if (token == ZEROP_T) {
    // apply rule 33
    // <action> -> LISTP_T <stmt>
    write_project_rule(33);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NULLP_T) {
    // apply rule 34
    // <action> -> NULLP_T <stmt>
    write_project_rule(34);

    token = lex->GetToken();
    stmt();
  }

  else if (token == STRINGP_T) {
    // apply rule 35
    // <action> -> STRINGP_T <stmt>
    write_project_rule(35);

    token = lex->GetToken();
    stmt();
  }

  else if (token == PLUS_T) {
    // apply rule 36
    // <action> -> PLUS_T <stmt_list>
    write_project_rule(36);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == MINUS_T) {
    // apply rule 37
    // <action> -> MINUS_T <stmt> <stmt_list>
    write_project_rule(37);

    token = lex->GetToken();
    stmt();
    stmt_list();
  }

  else if (token == DIV_T) {
    // apply rule 38
    // <action> -> DIV_T <stmt> <stmt_list>
    write_project_rule(38);

    token = lex->GetToken();
    stmt();
    stmt_list();
  }

  else if (token == MULT_T) {
    // apply rule 39
    // <action> -> MULT_T <stmt_list>
    write_project_rule(39);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == MODULO_T) {
    // apply rule 40
    // <action> -> MODULO_T <stmt> <stmt>
    write_project_rule(40);

    token = lex->GetToken();
    stmt();
    stmt();
  }

  else if (token == ROUND_T) {
    // apply rule 41
    // <action> -> ROUND_T <stmt>
    write_project_rule(41);

    token = lex->GetToken();
    stmt();
  }

  else if (token == EQUALTO_T) {
    // apply rule 42
    // <action> -> EQUALTO_T <stmt_list>
    write_project_rule(42);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == GT_T) {
    // apply rule 43
    // <action> -> GT_T <stmt_list>
    write_project_rule(43);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == LT_T) {
    // apply rule 44
    // <action> -> LT_T <stmt_list>
    write_project_rule(44);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == GTE_T) {
    // apply rule 45
    // <action> -> GTE_T <stmt_list>
    write_project_rule(45);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == LTE_T) {
    // apply rule 46
    // <action> -> LTE_T <stmt_list>
    write_project_rule(46);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == IDENT_T) {
    // apply rule 47
    // <action> -> IDENT_T <stmt_list>
    write_project_rule(47);

    token = lex->GetToken();
    stmt_list();
  }

  else if (token == DISPLAY_T) {
    // apply rule 48
    // <action> -> DISPLAY_T <stmt>
    write_project_rule(48);

    token = lex->GetToken();
    stmt();
  }

  else if (token == NEWLINE_T) {
    // apply rule 49
    // <action> -> NEWLINE_T
    write_project_rule(49);

    token = lex->GetToken();
  }

  else {
    // no match to any rules
    error_message = "'" + lex->GetLexeme() + "'" + " unexpected";
    lex->ReportError(error_message);
  }
}
