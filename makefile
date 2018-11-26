P2.out : Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o
	g++ -g -o P2.out Project2.o SetLimits.o LexicalAnalyzer.o SyntacticalAnalyzer.o

Project2.o : Project2.cpp SetLimits.h SyntacticalAnalyzer.h
	g++ -g -c Project2.cpp

SetLimits.o : SetLimits.cpp SetLimits.h
	g++ -g -c SetLimits.cpp

LexicalAnalyzer.o : LexicalAnalyzer.cpp LexicalAnalyzer.h
	g++ -g -c LexicalAnalyzer.cpp

SyntacticalAnalyzer.o : SyntacticalAnalyzer.cpp SyntacticalAnalyzer.h LexicalAnalyzer.h  
	g++ -g -c SyntacticalAnalyzer.cpp

clean :
	rm *.o P2.out *.gch *.p2 *.lst *.dbg *.p1

submit : Project2.cpp LexicalAnalyzer.h LexicalAnalyzer.cpp SyntacticalAnalyzer.h SyntacticalAnalyzer.cpp makefile README.txt
	rm -rf TeamWP2
	mkdir TeamWP2
	cp Project2.cpp TeamWP2
	cp LexicalAnalyzer.h TeamWP2
	cp LexicalAnalyzer.cpp TeamWP2
	cp SyntacticalAnalyzer.h TeamWP2
	cp SyntacticalAnalyzer.cpp TeamWP2
	cp makefile TeamWP2
	cp README.txt TeamWP2
	tar cfvz TeamWP2.tgz TeamWP2
	cp TeamWP2.tgz ~tiawatts/cs460drop
