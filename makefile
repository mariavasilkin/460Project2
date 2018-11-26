P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -c LexicalAnalyzer.cpp

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h action.o define.o literal.o more_tokens.o program.o stmt.o stmt_pair.o any_other_token.o else_part.o more_defines.o param_list.o quoted_lit.o stmt_list.o stmt_pair.o 
	g++ -g -c SyntacticalAnalyzer.cpp action.o define.o literal.o more_tokens.o program.o stmt.o stmt_pair.o any_other_token.o else_part.o more_defines.o param_list.o quoted_lit.o stmt_list.o stmt_pair.o  

action.o : action.cpp SyntacticalAnalyzer.h
	g++ -g -c action.cpp

define.o: define.cpp SyntacticalAnalyzer.h
	g++ -g -c define.cpp

literal.o: literal.cpp SyntacticalAnalyzer.h
	g++ -g -c literal.cpp

more_tokens.o: more_tokens.cpp SyntacticalAnalyzer.h
	g++ -g -c more_tokens.cpp

program.o: program.cpp SyntacticalAnalyzer.h
	g++ -g -c program.cpp

stmt.o: stmt.cpp SyntacticalAnalyzer.h
	g++ -g -c stmt.cpp

stmt_pair_body.o: stmt_pair_body.cpp SyntacticalAnalyzer.h
	g++ -g -c stmt_pair_body.cpp

any_other_token.o: any_other_token.cpp SyntacticalAnalyzer.h
	g++ -g -c any_other_token.cpp

else_part.o: else_part.cpp SyntacticalAnalyzer.h
	g++ -g -c else_part.cpp

more_defines.o: more_defines.cpp SyntacticalAnalyzer.h
	g++ -g -c more_defines.cpp

param_list.o: param_list.cpp SyntacticalAnalyzer.h
	g++ -g -c param_list.cpp

quoted_lit.o: quoted_lit.cpp SyntacticalAnalyzer.h
	g++ -g -c quoted_lit.cpp

stmt_list.o: stmt_list.cpp SyntacticalAnalyzer.h
	g++ -g -c stmt_list.cpp

stmt_pair.o: stmt_pair.cpp SyntacticalAnalyzer.h
	g++ -g -c stmt_pair.cpp

clean :
	rm *.o P2.out *.gch

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp action.cpp define.cpp literal.cpp more_tokens.cpp program.cpp stmt.cpp stmt_pair_body.cpp any_other_token.cpp else_part.cpp more_defines.cpp param_list.cpp quoted_lit.cpp stmt_list.cpp stmt_pair.cpp  makefile README.txt
	rm -rf TeamWP2
	mkdir TeamWP2
	cp Project2.cpp TeamWP2
	cp LexicalAnalyzer.h TeamWP2
	cp LexicalAnalyzer.cpp TeamWP2
	cp SyntacticalAnalyzer.h TeamWP2
	cp SyntacticalAnalyzer.cpp TeamWP2
	cp action.cpp TeamWP2
	cp define.cpp TeamWP2
	cp literal.cpp TeamWP2
	cp more_tokens.cpp TeamWP2
	cp program.cpp TeamWP2
	cp stmt.cpp TeamWP2
	cp stmt_pair_body.cpp TeamWP2
	cp any_other_token.cpp TeamWP2
	cp else_part.cpp TeamWP2
	cp more_defines.cpp TeamWP2
	cp param_list.cpp TeamWP2
	cp quoted_lit.cpp TeamWP2
	cp stmt_list.cpp TeamWP2
	cp stmt_pair.cpp TeamWP2
	cp makefile TeamWP2
	cp README.txt TeamWP2
	tar cfvz TeamWP2.tgz TeamWP2
	cp TeamWP2.tgz ~tiawatts/cs460drop
