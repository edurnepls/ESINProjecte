OPCIONS = -g -O0 -std=c++03 -Wall -lesin -Wno-deprecated -fpermissive

program.exe: program.o racional.o
		g++ -o program.exe program.o racional.o 
		rm *.o 

program.o: program.cpp racional.hpp racional.cpp
		g++ -c program.cpp $(OPCIONS)

racional.o: racional.cpp racional.hpp racional.rep
		g++ -c racional.cpp $(OPCIONS)

clean:
		rm *.o 
		rm *.exe
		rm *.gch