#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::define() {
    int errors = 0;

    //checking rule 4
    if (t == DEFINE_T)
        t = lex->GetToken();
    else   
        errors++;
    if (t == LPAREN_T)
        t = lex->GetToken();
    else
        errors++;
    if (t == IDENT_T)
        t = lex->GetToken();
    else
        errors++;
    errors += param_list();
    if (t == RPAREN_T)
        t = lex->GetToken();
    else
        errors++;
    errors += stmt();
    errors += stmt_list();
    if (t == RPAREN_T)
        t = lex->GetToken();
    else
        errors++;
    return errors;
}
