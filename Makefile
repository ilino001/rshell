COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic

all:
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell

main:
	$(COMPILE) $(FLAGS) ./src/main.cpp

clean:
	rm -rf ./bin
	rm a.out
 
