GCC=g++
CCFLAGS = -c -g -W -ansi -pedantic -std=c++0x
DSTATE=
DDEBUG=
OBJETS = Lexer.o Symbole.o Automate.o Etat.o Expression.o main.o
EXEC = main

ifdef states
    DSTATE = -DSTATES
endif

ifdef debug
    DDEBUG = -DMAP
endif

DFLAGS = $(DDEBUG) $(DSTATE)

$(EXEC) : $(OBJETS)
	$(GCC) -o $(EXEC) $(OBJETS)

%.o : %.cpp
	$(GCC) $(CCFLAGS) $(DFLAGS) $<

Lexer.o : Lexer.h
Symbole.o : Symbole.h
Automate.o : Automate.h
Etat.o : Etat.h
Expression.o : Expression.h

run: $(EXEC)
	@echo $(DFLAGS)
	./$(EXEC)
	@echo "Run completed."

memory_check : $(EXEC)
	@valgrind --leak-check=yes ./$(EXEC)

rebuild: cleanall all

clean:
	@rm -rf *.o
	@echo "Binary files deleted."

cleanall: clean
	@rm -rf $(EXEC)
	@echo "Executable deleted."