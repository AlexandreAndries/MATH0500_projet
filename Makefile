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
MODULES=source/main.c source/manager.c source/boolean.c source/array.c source/sparse-matrix.c source/operations.c source/sparse-vector.c
OBJECTS=source/main.o source/manager.o source/boolean.o source/array.o source/sparse-matrix.o source/operations.o source/sparse-vector.o

## Rules

all: $(EXEC)

mtxSolver: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

source/manager.o: source/manager.c
	$(CC) -c source/manager.c -o source/manager.o $(CFLAGS)

source/boolean.o: source/boolean.c
	$(CC) -c source/boolean.c -o source/boolean.o $(CFLAGS)

source/array.o: source/array.c
	$(CC) -c source/array.c -o source/array.o $(CFLAGS)

source/sparse-matrix.o: source/sparse-matrix.c
	$(CC) -c source/sparse-matrix.c -o source/sparse-matrix.o $(CFLAGS)

source/operations.o: source/operations.c
	$(CC) -c source/operations.c -o source/operations.o $(CFLAGS)

source/sparse-vector.o: source/sparse-vector.c
	$(CC) -c source/sparse-vector.c -o source/sparse-vector.o $(CFLAGS)

clean:
	rm -f source/*.o source/*.gch $(EXEC) *~
	clear
