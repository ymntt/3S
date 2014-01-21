# Makefile

all: a b c d e f g h i j
test: 1 2 3 4 5 6 7 8 9 10
a: 1.c
	gcc -o 1 1.c
b: 2.c
	gcc -o 2 2.c
c: 3.c
	gcc -o 3 3.c
d: 4.c
	gcc -o 4 4.c
e: 5.c
	gcc -o 5 5.c
f: 6.c
	gcc -o 6 6.c
g: 7.c
	gcc -o 7 7.c
h: 8.c
	gcc -o 8 8.c
i: 9.c
	gcc -o 9 9.c
j: 10.c
	gcc -o 10 10.c
clean:
	rm -f 1.o 2.o 3.o 4.o 5.o 6.o 7.o 8.o 9.o 10.o
	rm -f 1.o~ 2.o~ 3.o~ 4.o~ 5.o~ 6.o~ 7.o~ 8.o~ 9.o~ 10.o~
