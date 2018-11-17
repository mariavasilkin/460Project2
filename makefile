P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -c LexicalAnalyzer.cpp

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h nonTerminals/action.cpp nonTerminals/define.cpp nonTerminals/literal.cpp nonTerminals/more_tokens.cpp nonTerminals/program.cpp nonTerminals/stmt.cpp nonTerminals/stmt_pair_body.cpp nonTerminals/any_other_token.cpp nonTerminals/else_part.cpp nonTerminals/more_defines.cpp nonTerminals/param_list.cpp nonTerminals/quoted_lit.cpp nonTerminals/stmt_list.cpp nonTerminals/stmt_pair.cpp LexicalAnalyzer.h
	g++ -g -c SyntacticalAnalyzer.cpp

clean : 
	rm *.o P2.out *.gch

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp nonTerminals/action.cpp nonTerminals/define.cpp nonTerminals/literal.cpp nonTerminals/more_tokens.cpp nonTerminals/program.cpp nonTerminals/stmt.cpp nonTerminals/stmt_pair_body.cpp nonTerminals/any_other_token.cpp nonTerminals/else_part.cpp nonTerminals/more_defines.cpp nonTerminals/param_list.cpp nonTerminals/quoted_lit.cpp nonTerminals/stmt_list.cpp nonTerminals/stmt_pair.cpp  makefile README.txt
	rm -rf WP2
	mkdir WP2
	cp Project2.cpp WP2
	cp LexicalAnalyzer.h WP2
	cp LexicalAnalyzer.cpp WP2
	cp SyntacticalAnalyzer.h WP2
	cp SyntacticalAnalyzer.cpp WP2
	cp nonTerminals WP2
	cp makefile WP2
	cp README.txt WP2
	tar cfvz WP2.tgz WP2
	cp WP2.tgz ~tiawatts/cs460drop
