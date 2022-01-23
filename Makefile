GCC=g++
CCFLAGS = -c -g -W -Wall -ansi -pedantic -std=c++0x
DSTATE=
DDEBUG=

OBJETS = Lexer.o Symbole.o Automate.o Etat.o Expression.o main.o
EXEC = main


ifdef state
    DSTATE=-DSTATE
endif

ifdef debug
    DDEBUG=-DMAP
endif


all: $(EXEC)

$(EXEC) : $(OBJETS)
	$(GCC) -o $(EXEC) $(OBJETS)

%.o : %.cpp
	$(GCC) $(CCFLAGS) $(PRINT_MAP) $<

Lexer.o : Lexer.h
Symbole.o : Symbole.h
Automate.o : Automate.h
Etat.o : Etat.h
Expression.o : Expression.h

run: $(EXEC)
	./$(EXEC)

memory_check : $(EXEC)
	valgrind --leak-check=yes ./$(EXEC)

rebuild: cleanall all

clean:
	rm -rf *.o
	echo "Binary files deleted."

cleanall: clean
	rm -rf $(EXEC)
	echo "Executable deleted."