#
#Name: Daniel Srouji
#ID: 100945542
#Date: November 3, 2015
#Assignment 4
#
all: avltree

avltree: avltree.c
	gcc -Wall -ansi -pedantic -Iinclude avltree.c functions.c -o avltree
clean:
	-rm -rf *o avltree