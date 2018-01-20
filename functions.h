/*
*Name: Daniel Srouji
*ID: 100945542
*Date: November 24, 2015
*Assignment 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*Tree Struct*/
struct Tree { 
    char* key;
    struct Tree * left;
    struct Tree * right;
    int height;
    int frequency;
};

/*Function Prototypes*/
struct Tree* find(char* key, struct Tree* treeNode );
struct Tree* insert(char* key, struct Tree * treeNode);
struct Tree* delete(char* key, struct Tree * treeNode);
void inOrder(struct Tree * treeNode);
void freqSearch(struct Tree * treeNode, int frequency);
int height(struct Tree* node);
int max(int left, int right);
struct Tree * rightRotate(struct Tree * z);
struct Tree * leftRotate(struct Tree * z);
struct Tree * rLRotation(struct Tree * z); 
struct Tree * lRRotation(struct Tree * z);
int bFactor(struct Tree *node);

/*Global Variables*/
int totalNode;
int tHeight;
