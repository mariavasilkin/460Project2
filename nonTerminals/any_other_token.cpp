#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::any_other_token() {
  int errors = 0;
  string function_name = "Any_Other_Token";
  write_function_enter(function_name);
  
  if (token == LPAREN_T) {
    // apply rule 50
    // <any_other_token> -> LPAREN_T <more_tokens> RPAREN_T
    write_project_rule(50);
    
    token = lex->GetToken();
    errors += lex->GetToken();
    if (token == RPAREN_T) {
      token = lex->GetToken();
    } else {
      errors++;
    }
  }

  else if (token == IDENT_T) {
    // apply rule 51
    // <any_other_token> -> IDENT_T
    write_project_rule(51);
    
    token = lex->GetToken();
  }

  else if (token == NUMLIT_T) {
    // apply rule 52
    // <any_other_token> -> NUMLIT_T
    write_project_rule(52);
    
    token = lex->GetToken();
  }

  else if (token == STRLIT_T) {
    // apply rule 53
    // <any_other_token> -> STRLIT_T
    write_project_rule(53);
    
    token = lex->GetToken();
  }

  else if (token == CONS_T) {
    // apply rule 54
    // <any_other_token> -> CONS_T
    write_project_rule(54);
    
    token = lex->GetToken();
  }

  else if (token == IF_T) {
    // apply rule 55
    // <any_other_token> -> IF_T
    write_project_rule(55);
    
    token = lex->GetToken();
  }

  else if (token == DISPLAY_T) {
    // apply rule 56
    // <any_other_token> -> DISPLAY_T
    write_project_rule(56);
    
    token = lex->GetToken();
  }

  else if (token == NEWLINE_T) {
    // apply rule 57
    // <any_other_token> -> NEWLINE_T
    write_project_rule(57);
    
    token = lex->GetToken();
  }

  else if (token == LISTOP_T) {
    // apply rule 58
    // <any_other_token> -> LISTOP_T
    write_project_rule(58);
    
    token = lex->GetToken();
  }

  else if (token == AND_T) {
    // apply rule 59
    // <any_other_token> -> AND_T
    write_project_rule(59);
    
    token = lex->GetToken();
  }

  else if (token == OR_T) {
    // apply rule 60
    // <any_other_token> -> OR_T
    write_project_rule(60);
    
    token = lex->GetToken();
  }

  else if (token == NOT_T) {
    // apply rule 61
    // <any_other_token> -> NOT_T
    write_project_rule(61);
    
    token = lex->GetToken();
  }

  else if (token == DEFINE_T) {
    // apply rule 62
    // <any_other_token> -> DEFINE_T
    write_project_rule(62);
    
    token = lex->GetTOken();
  }

  else if (token == NUMBERP_T) {
    // apply rule 63
    // <any_other_token> -> NUMBERP_T
    write_project_rule(63);
    
    token = lex->GetToken();
  }

  else if (token == LISTP_T) {
    // apply rule 64
    // <any_other_token> -> LISTP_T
    write_project_rule(64);
    
    token = lex->GetToken();
  }

  else if (token == ZEROP_T) {
    // apply rule 65
    // <any_other_token> -> ZEROP_T
    write_project_rule(65);
    
    token = lex->GetToken();
  }

  else if (token == NULLP_T) {
    // apply rule 66
    // <any_other_token> -> NULLP_T
    write_project_rule(66);
    
    token = lex->GetToken();
  }

  else if (token == STRINGP_T) {
    // apply rule 67
    // <any_other_token> -> STRINGP_T
    write_project_rule(67);
    
    token = lex->GetToken();
  }

  else if (token == PLUS_T) {
    // apply rule 68
    // <any_other_token> -> PLUS_T
    write_project_rule(68);
    
    token = lex->GetToken();
  }

  else if (token == MINUS_T) {
    // apply rule 69
    // <any_other_token> -> MINUS_T
    write_project_rule(69);
    
    token = lex->GetToken();
  }

  else if (token == DIV_T) {
    // apply rule 70
    // <any_other_token> -> DIV_T
    write_project_rule(70);
    
    token = lex->GetToken();
  }

  else if (token == MULT_T) {
    // apply rule 71
    // <any_other_token> -> MULT_T
    write_project_rule(71);
    
    token = lex->GetToken();
  }

  else if (token == MODULO_T) {
    // apply rule 72
    // <any_other_token> -> MODULO_T
    write_project_rule(72);
    
    token = lex->GetToken();
  }

  else if (token == ROUND_T) {
    // apply rule 73
    // <any_other_token> -> ROUND_T
    write_project_rule(73);
    
    token = lex->GetToken();
  }

  else if (token == EQUALTO_T) {
    // apply rule 74
    // <any_other_token> -> EQUALTO_T
    write_project_rule(74);
    
    token = lex->GetToken();
  }

  else if (token == GT_T) {
    // apply rule 75
    // <any_other_token> -> GT_T
    write_project_rule(75);
    
    token = lex->GetToken();
  }

  else if (token == LT_T) {
    // apply rule 76
    // <any_other_token> -> LT_T
    write_project_rule(76);
    
    token = lex->GetToken();
  }

  else if (token == GTE_T) {
    // apply rule 77
    // <any_other_token> -> GTE_T
    write_project_rule(77);
    
    token = lex->GetToken();
  }

  else if (token == LTE_T) {
    // apply rule 78
    // <any_other_token> -> LTE_T
    write_project_rule(78);
    
    token = lex->GetToken();
  }

  else if (token == SQUOTE_T) {
    // apply rule 79
    // <any_other_token> -> SQUOTE_T <any_other_token>
    write_project_rule(79);
    
    token = lex->GetToken();
    errors += any_other_token();
  }

  else if (token == COND_T) {
    // apply rule 80
    // <any_other_token> -> COND_T
    write_project_rule(80);
    
    token = lex->GetToken();
  }

  else if (token == ELSE_T) {
    // apply rule 81
    // <any_other_token> -> COND_T
    write_project_rule(81);
    
    token = lex->GetToken();
  }

  else {
    report_error();
  }
  write_project_exit(function_name);
  
  return errors;
}




