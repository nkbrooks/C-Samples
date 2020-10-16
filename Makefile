# this is a simple Makefile to compile the available project7 files
CC = gcc
CFLAGS = -ansi -pedantic-errors -Wall -Werror -Wshadow -Wwrite-strings -g
#3 execeutable programs project1.x, main.x, tester.x
all: program1.x main.x tester.x
#link object files to form executables
program1.x: program1.o compare-arrays.o
	$(CC) program1.o compare-arrays.o -o program1.x

main.x: main.o compare-arrays.o fill-array.o
	$(CC) main.o compare-arrays.o fill-array.o -o main.x

tester.x: tester.o incr-array.o fill-array.o sum-array.o
	$(CC) tester.o incr-array.o fill-array.o sum-array.o -o tester.x

#create object files - 7 object files
program1.o: program1.c compare-arrays.h
	$(CC) $(CFLAGS) -c program1.c 

main.o: main.c compare-arrays.h fill-array.h
	$(CC) $(CFLAGS) -c main.c

tester.o: tester.c sum-array.h incr-array.h fill-array.h
	$(CC) $(CFLAGS) -c tester.c

compare-arrays.o: compare-arrays.c compare-arrays.h
	$(CC) $(CFLAGS) -c compare-arrays.c

fill-array.o:fill-array.c fill-array.h
	$(CC) $(CFLAGS) -c fill-array.c

incr-array.o:incr-array.c incr-array.h
	$(CC) $(CFLAGS) -c incr-array.c

sum-array.o:sum-array.c sum-array.h 
	$(CC) $(CFLAGS) -c sum-array.c

#removes files
clean:
	rm -f *.o *.x

