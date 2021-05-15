CC := g++

# Compile flags
CFLAGS := -std=c++17 -Wall -no-pie

# Additional libs
CLIBS := -lgpiod -lpthread

all: main io_test

main:
	clear
	@echo "Compiling main.cpp ... "
	$(CC) $(CLIBS) -o main.out main.cpp

io_test:
	clear
	@echo "Compiling io_test.cpp ... "
	$(CC) $(CLIBS) -o io_test.out io_test.cpp


clean:
	rm -rf main.out