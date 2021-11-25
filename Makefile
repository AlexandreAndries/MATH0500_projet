###
## Makefile
## MATH0500: Projet
## Andries Alexandre s196948
## Khaliphi Abdelilah s204896
###

#---------------
# Variables
#---------------

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes
LD=gcc
LDFLAGS=

# Files
EXEC=mtxSolver
MODULES=main.c manager.c boolean.c array.c sparse-matrix.c operations.c
OBJECTS=main.o manager.o boolean.o array.o sparse-matrix.o operations.o

## Rules

all: $(EXEC)

mtxSolver: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

manager.o: manager.c
	$(CC) -c manager.c -o manager.o $(CFLAGS)

boolean.o: boolean.c
	$(CC) -c boolean.c -o boolean.o $(CFLAGS)

array.o: array.c
	$(CC) -c array.c -o array.o $(CFLAGS)

sparse-matrix.o: sparse-matrix.c
	$(CC) -c sparse-matrix.c -o sparse-matrix.o $(CFLAGS)

operations.o: operations.c
	$(CC) -c operations.c -o operations.o $(CFLAGS)

clean:
	rm -f *.o *.gch $(EXEC) *~
	clear
