#include "../SyntacticalAnalyzer.h"

int SyntacticalAnalyzer::program() {
    int errors = 0;

    //checking rule 1
    if (t == LPAREN_T)
        t = lex->GetToken();
    else 
        errors++;
    errors += define();
    if (t == LPAREN_T)
        t = lex->GetToken();
    else
        errors++; 
    errors += more_defines();
    if (t == EOF_T)
    else
        errors++;
    return errors;
}
