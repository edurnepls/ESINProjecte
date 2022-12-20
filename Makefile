OPCIONS = -g -O0 -std=c++03 -Wall -lesin -Wno-deprecated

program.exe: program.o racional.o token.o
		g++ -o program.exe program.o racional.o token.o
		rm *.o 

program.o: program.cpp racional.hpp racional.cpp token.hpp token.cpp
		g++ -c program.cpp $(OPCIONS)

token.o: token.cpp token.hpp token.rep
		g++ -c token.cpp $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
		g++ -c racional.cpp $(OPCIONS)

clean:
		rm *.o 
		rm *.exe
		rm *.gch
