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

/*The main has a controlled loop that displays 
a menu to the user. The user can insert keys by 
entering a file name or just entering key by key.
The user can also search for a key  or delete a 
key in the tree. The user can choose to print the
height and size of the tree. They can also print
all the keys above or equal to a given frequency*/
int main(int argc, char* argv[])
{
    struct Tree *tree = NULL;
    struct Tree *node = NULL;
    int check = 1, choice, frequency = 0;
    char fileName[10];
    char buffer[100];
    char key[100];
    FILE *input;

    do{
        printf("\n1. Initialization\n");
        printf("2. Find\n");
        printf("3. Insert\n");
        printf("4. Remove\n");
        printf("5. Check Height and Size\n");
        printf("6. Find All (above a given frequency)\n");
        printf("7. Exit\n");
        printf("avl/> ");
        scanf("%d", &choice);
        
        if (choice == 1)
        {
        	printf("filename: ");
        	scanf("%s", fileName);
        	input = fopen(fileName, "r");
            if (input == NULL)
            {
                printf("File does not exist\n");
            }else{
                while(fscanf(input, "%s", buffer) != EOF){
                    tree = insert(buffer, tree);
                }

                printf("File Inserted Successfully\n");
            }
            fclose(input);
            
        }else if (choice == 2)
        {
            printf("Find Key: ");
            scanf("%s", key);
            node = find(key, tree);
            if (node == NULL)
            {
                printf("No_such_key\n");
            }else{
                printf("Key: %s, Frequency: %d\n", node->key, node->frequency);
            }
            
        }else if (choice == 3)
        {
            printf("Insert Key: ");
            scanf("%s", key);
            tree = insert(key, tree);
            node = find(key, tree);
            printf("Key: %s, Frequency: %d\n", node->key, node->frequency);
            
        }else if (choice == 4)
        {
            printf("Remove Key: ");
            scanf("%s", key);
            node = find(key, tree);
            if (node == NULL)
            {
                printf("No_such_key\n");
            }else{
                tree = delete(key, tree);
                node = find(key, tree);
                if (node == NULL)
                {
                    printf("Key: %s, Frequency: 0\n", key);
                }else{
                    printf("Key: %s, Frequency: %d\n", node->key, node->frequency);
                }
            }

        }else if (choice == 5)
        {
            inOrder(tree);
            printf("Height: %d, Size: %d\n", tHeight, totalNode);

        }else if (choice == 6){
            printf("Frequency: ");
            scanf("%d", &frequency);
            freqSearch(tree, frequency);
            
        }else if(choice == 7){
            check = 0;
        }else{
            printf("Invalid input\n");
        }
    }while(check == 1);
  
    return 0;
}
