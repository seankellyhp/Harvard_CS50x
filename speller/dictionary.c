#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

#define MAX_BUCKETS 40000

// create node
typedef struct node
{
    char word[LENGTH+1];
    struct node *next;
}
*node;

// global variables
node hashtable[MAX_BUCKETS];
int dictionary_word_counter = 0;


unsigned long bernstein(char *str);
void insert(node nodes, int index);



/**
 * Returns true if word is in dictionary
 */

bool check(const char* word)
{
    int len = strlen(word) + 1;

    char * lower_case_word = malloc(len * sizeof(char));

    if (lower_case_word == NULL)
    {
      unload();
      return 1;
    }

    lower_case_word[len] = '\0';

    // change to lowercase
    for(int i = 0; i < len; i++){
        lower_case_word[i] = tolower(word[i]);
    }

    // generate hash
    int index = bernstein(lower_case_word);

    // traverse the linked list
    node trav = hashtable[index];


    // loop through while node->next is not null
    while (trav != NULL){
        if ( strcmp(trav->word, lower_case_word) == 0){
            return true;
            free(lower_case_word);
        }
        free(lower_case_word);
        trav = trav->next;
    }


    return false;

}

/**
 * Load dictionary into memory.
 */

bool load(const char* dictionary)
{
    // create a FILE pointer and fopen() to start the stream
    FILE * dictionary_stream = fopen(dictionary, "r");

    char temp[LENGTH+1] = {'\0'};

    while (fscanf(dictionary_stream, "%s", temp) == 1){

        // allocate new space
        node d_node = malloc(sizeof(struct node));

        if (d_node == NULL)
        {
          return 1;
        }

        // next to null
        d_node->next = NULL;

        // save word
        strcpy(d_node->word, temp);

        // new hash
        int ht_index = bernstein(d_node->word);

        // insert node into hashtable
        insert(d_node, ht_index);

        dictionary_word_counter++;



    }

    fclose(dictionary_stream);
    return true;
}

/**
 * Returns words in dictionary
 */

unsigned int size(void)
{
    return dictionary_word_counter;
}

/**
 * Unloads dictionary from memory.
 */

bool unload(void)
{
////////

        for (int i = 0; i < MAX_BUCKETS; i++)
        {

        //make pointer to the head of list
        node head = hashtable[i];
        node cursor = head;

        while (cursor != NULL)
           {
               node tmp = cursor;
               cursor = cursor->next;

               free(tmp);
           }
        }

        return true;
}

/***
Functions
https://johnyzaguirre.com/2018/11/07/cs50-week-4/
***/

void insert(node nodes, int index){

    // check if the array location is null
    if ( !(hashtable[index]) ){
        hashtable[index] = nodes;
    }
    else{

        node temp = hashtable[index];
        hashtable[index] = nodes;
        nodes->next = temp;

    }

}


/***
DJB2 Hash Function
***/

unsigned long
    bernstein(char *str)
    {
      unsigned long hash = 5381;
      int c;
      while ((c = *str++))
          hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
      return hash % MAX_BUCKETS;
    }
