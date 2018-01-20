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
#include "functions.h"

/*Function takes a key and the tree as parameters. Returns NULL 
if key is not found and returns the node that has the 
key if it is found*/
struct Tree* find(char* key, struct Tree* treeNode )
{
    if( treeNode == NULL )
        return NULL;
    if( strcmp(key, treeNode->key) < 0 )
        return find(key, treeNode->left );
    else if(strcmp(key, treeNode->key) > 0)
        return find(key, treeNode->right );
    else
        return treeNode;
}

/*Function takes a key and the tree as parameters. Goes through
the tree and calls itself recursivly until and empty node (NULL) 
is found and then it creates a new node with the new key. If the 
key already existed it would just add 1 to its frequency. Then 
based on the balance factor it balances the tree by calling the 
appropriate functions.*/
struct Tree* insert(char* key, struct Tree * treeNode){
    int bf;
    if(treeNode == NULL)
    {
        treeNode = (struct Tree*)malloc(sizeof(struct Tree));
        treeNode->key = malloc(sizeof(char*)*strlen(key)+1);

        strcpy(treeNode->key, key);
        treeNode->frequency = 1;
        treeNode->height = 1;
        treeNode->left = NULL;
        treeNode->right = NULL;
        
    }
    else if(strcmp(key, treeNode->key) < 0)
    {
        treeNode->left = insert( key, treeNode->left );
    }
    else if(strcmp(key, treeNode->key) > 0)
    {
        treeNode->right = insert( key, treeNode->right );

    }else if (strcmp(key, treeNode->key) == 0)
    {
        treeNode->frequency++;
    }

	treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;

    bf = bFactor(treeNode);
  
    if (bf > 1 && (strcmp(key, treeNode->left->key) < 0))
        return rightRotate(treeNode);
 
    if (bf < -1 && (strcmp(key, treeNode->right->key) > 0))
        return leftRotate(treeNode);
 
    if (bf > 1 && (strcmp(key, treeNode->left->key) > 0))
    {
        return rLRotation(treeNode);
    }
 
    if (bf < -1 && (strcmp(key, treeNode->right->key) < 0))
    {
        return lRRotation(treeNode);
    }
	return treeNode;
}

/*Function takes a key and the tree as parameters. Goes through
the tree and calls itself recursivly until the node with the key
looked for is found and then delets the node. If the key's 
frequency is more than one it just takes away 1. Then based
on the balance factor it balances the tree by calling the 
appropriate functions.*/
struct Tree* delete(char* key, struct Tree * treeNode){
    int bf;
    struct Tree * parent;
    if(treeNode == NULL)
    {
        return NULL;    
    }
    else if(strcmp(key, treeNode->key) < 0)
    {
        treeNode->left = delete( key, treeNode->left );
    }
    else if(strcmp(key, treeNode->key) > 0)
    {
        treeNode->right = delete( key, treeNode->right );

    }else if (strcmp(key, treeNode->key) == 0)
    {
        if(treeNode->frequency > 1){
            treeNode->frequency--;
        }else if (treeNode->frequency == 1)
        {
            if(treeNode->right !=NULL)
            {  
                parent=treeNode->right;
                while(parent->left != NULL)
                    parent = parent->left;
                    treeNode->key=parent->key;
                    treeNode->right=delete(parent->key, treeNode->right);
            }
            else
                return(treeNode->left);
            
        }
    }

    treeNode->height = max(height(treeNode->left), height(treeNode->right)) + 1;

    bf = bFactor(treeNode);
 
    if (bf > 1 && (strcmp(key, treeNode->left->key) < 0))
        return rightRotate(treeNode);
 
    if (bf < -1 && (strcmp(key, treeNode->right->key) > 0))
        return leftRotate(treeNode);
 
    if (bf > 1 && (strcmp(key, treeNode->left->key) > 0))
    {
        return rLRotation(treeNode);
    }
 
    if (bf < -1 && (strcmp(key, treeNode->right->key) < 0))
    {
        return lRRotation(treeNode);
    }

    return treeNode;
}

/*Returns the balance factor of the node*/
int bFactor(struct Tree *node)
{
    if (node == NULL){
        return 0; 
    }
    return height(node->left) - height(node->right);
}

/*Returns the height of the node*/
int height( struct Tree* node )
{
    if( node == NULL ){
        return -1;      
    }
    else{
        return node->height;
    }
}

/*returns the maximum of two intgers*/
int max(int left, int right)
{
    return left > right ? left: right;
}

/*Left Left Case Rotation */
struct Tree * rightRotate(struct Tree * z)
{
    struct Tree *y = z->left;
    struct Tree *T2 = y->right;
 
    y->right = z;
    z->left = T2;
 
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}

/*Right Right Case Rotation */ 
struct Tree * leftRotate(struct Tree * z)
{
    struct Tree *y = z->right;
    struct Tree *T2 = y->left;
 
    y->left = z;
    z->right = T2;
 
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}

/*Left Right Case Rotation */ 
struct Tree * rLRotation(struct Tree * z)
{
    z->left = leftRotate(z->left);
    return rightRotate(z);
}
 
/*Right Left Case Rotation */ 
struct Tree * lRRotation(struct Tree * z)
{
    z->right = rightRotate(z->right);
    return leftRotate(z);
}

/*takes the tree and sets the size and height of it*/
void inOrder(struct Tree * treeNode)
{
	if (treeNode != NULL)
    {
        inOrder(treeNode->left);
        if (tHeight < treeNode->height)
        {
            tHeight = treeNode->height;
        }
        totalNode++;
        inOrder(treeNode->right);
	}

}

/*Takes the tree and a frquency and then prints all 
the keys which frequency is equal to or more than the 
frequency requested*/
void freqSearch(struct Tree * treeNode, int frequency)
{
    if (treeNode != NULL)
    {
        freqSearch(treeNode->left, frequency);
        if (treeNode->frequency >= frequency)
        {
            printf("Key: %s, Frequency: %d\n",treeNode->key, treeNode->frequency);
        }
        freqSearch(treeNode->right, frequency);
    }
}
