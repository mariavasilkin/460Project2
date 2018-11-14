#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::more_defines() {
    int errors = 0;
    //checking rule 2
    if (t == DEFINE_T){
        errors += define();
        if (t == LPAREN_T)
            t = lex->GetToken();
        else
            errors++;
        errors+= more_defines();
    }

    //checking rule 3
    else if (t == IDENT_T){
        t = lex->GetToken();
        errors += stmt_list();
        if (t == RPAREN_T)
            t = lex->GetToken();
        else
            errors++;
    }

    else //not rule 2 or 3
        errors++;
        
    return errors;
}
