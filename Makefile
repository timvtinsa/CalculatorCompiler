GCC=g++
CCFLAGS = -c -g -W -ansi -pedantic -std=c++0x
OBJETS = Lexer.o Symbole.o Automate.o Etat.o Expression.o main.o
EXEC = main
MAKEFLAGS += --no-print-directory
CALCULATOR = ./src/calculator
DFLAGS =

ifeq ($(states),true)
	DFLAGS += -DSTATES
endif

ifeq ($(debug),true)
    DFLAGS += -DMAP
endif

$(EXEC) : $(OBJETS)
	$(GCC) -o $(EXEC) $(OBJETS)

%.o : $(CALCULATOR)/%.cpp
	$(GCC) $(CCFLAGS) $(DFLAGS) $<

Lexer.o : $(CALCULATOR)/Lexer.h
Symbole.o : $(CALCULATOR)/Symbole.h
Automate.o : $(CALCULATOR)/Automate.h
Etat.o : $(CALCULATOR)/Etat.h
Expression.o : $(CALCULATOR)/Expression.h

run: $(EXEC)
	./$(EXEC)
	@echo "Run completed."

memory_check : $(EXEC)
	@valgrind --leak-check=yes ./$(EXEC)

clean:
	@rm -rf *.o
	@echo "Binary files deleted."

cleanall: clean
	@rm -rf $(EXEC)
	@echo "Executable deleted."

gtest:
	cmake ./Google_tests/CMakeLists.txt
	cd ./Google_tests && make
	cd ./Google_tests && ./Google_Tests_run

cleantest:
	cmake --build ./Google_tests --target clean
	@echo "CMake build cleaned."