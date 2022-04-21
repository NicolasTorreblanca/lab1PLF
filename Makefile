#Makefile

CC=gcc
CFLAGS=-Wall -lm -lniceprint -L  .
all : lab3 

lab3: lab3.c funciones.c funciones.h
	$(CC) funciones.c lab3.c -o lab3 $(CFLAGS)

clean:
	rm -f *.o .exe all
.PHONY : clean

run:
#  ./lab3 -N 35 -c 8 -i input.txt -o output.txt -b 64 -h 4 -D

# ./lab3 -c 8 -i input.txt -o output.txt -b 64 -h 4 -D

# ./lab3 -i input.txt -o output.txt -b 64 -h 4 -D