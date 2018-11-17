// Will Lucic in group 4
#include "Syn.h"

int Syn::modifier ()
{
	int errors = 0; 
	if (ct == "wicked" || ct == "sordid" || ct == "naughty" || ct == "malodorous")
	{
		ct = lex->NextTerminal ();
		errors += adjectivr();
	}
	else if (ct == "conspiculously" || ct == "categorically" || ct == "positively" || ct == "incontrovertibly")
	{
		ct = lex->NextTerminal ();
		errors += adverb();
		errors += adjective();
	}
	else
	{
		lex->ReportError ("'a' expected; '" + ct + "' found.");
		errors++;
	}
	return errors;
} 
