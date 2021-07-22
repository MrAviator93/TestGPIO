CC := g++

# Compile flags
CFLAGS := -std=c++17 -Wall -no-pie

# Additional libs
CLIBS := -lgpiod -lpthread

all: main io_test

main:
	clear
	@echo "Compiling main.cpp ... "
	$(CC) $(CFLAGS) $(CLIBS) main.cpp -o main.out

io_test:
	clear
	@echo "Compiling io_test.cpp ... "
	$(CC) $(CFLAGS) $(CLIBS)  io_test.cpp -o io_test.out

clean:
	rm -rf main.out
