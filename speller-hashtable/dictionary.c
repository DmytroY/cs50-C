// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
//#define N 26
#define N 457678

unsigned long word_count = 0;   // uploaded dictionary words count
    
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// temporary routine
void print_list(node *head)
{
    node *pointer;
    printf("head pointer = %p ", head);
    for (pointer = head; pointer != NULL; pointer = pointer->next)
    {
        printf(", %s",  pointer->word);
    }
}


// Hashes word to a number between 0 and 457678, inclusive, based on its first 3 letters
unsigned int hash(const char *word)
{
    //return tolower(word[0]) - 'a';
    unsigned int i;
    int l = strlen(word);
    switch (l)
    {
        case 1 :
            if(word[0] == 39) { return 0; } // 0-cell in case of word contain '
            i = (tolower(word[0]) - 96);
            break;
        case 2 :
            if(word[0] == 39 || word[1] == 39){ return 0; }
            i = (tolower(word[0]) - 96) + 26 * (tolower(word[1]) - 96);
            break;
        default : 
            if(word[0] == 39 || word[1] == 39 || word[2] == 39){ return 0; }
            i = (tolower(word[0]) - 96) + 26 * (tolower(word[1]) - 96) + 26 * 26 * (tolower(word[2]) - 96); 
    }
    return i;
}

// add node to the begining of linked list
int push_first(node **head, char * arg)
{
    node *new_node;
    new_node = malloc(sizeof(node));
    if (new_node == NULL) 
    {
        return 1;   // malloc can't allocate memory
    }
    strcpy(new_node->word, arg);
    new_node->next = *head;
    *head = new_node;
    return 0;
}

// freeing memory
void free_first(node ** head)
{
    node * temp_pointer;
    temp_pointer = (*head)->next;
    free(*head);
    *head = temp_pointer;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    int i;
    // Initialize hash table
    for (i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)     // Insert words into hash table
    {
        // DONE
        i = hash(word);                         // define number of cell in hashtable by first letter of word (0 for a, 1 for b, 2 for c .....)
        if (push_first(&hashtable[i], word))    // add a word to proper hashtable cell with linked list inside, push_first() returns 0 if success
        {
            fclose(file);                       // push_first() returns 1 because can't allocate memory for new node
            word_count = 0;                     // reset counter of uploaded words;
            for (i = 0; i < N; i++)             // free memory allocated to already uploaded nodes
            {
                while (hashtable[i] != NULL)
                {
                    free_first(&hashtable[i]);
                }
            }            
            return false;
        }
        word_count++;
    }
    fclose(file);       // Close dictionary file
    
    // temporary code
    for (i = 0; i < 10; i++)
    {
        print_list(hashtable[i]);
        printf("\n");
    }
    
    return true;        // Indicate success
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // DONE
    return word_count;
}

// Returns true if word is in dictionary else false
bool check(const char *word_for_check)
{
    // TODO -DONE
    int i;
    char temp_word[LENGTH + 1];
    strcpy(temp_word, word_for_check);
    // define cell of hashtable
    i = hash(word_for_check);                 
    // convert word to lowercase
    for (int j = 0; temp_word[j] != '\0'; j++)
    {
        temp_word[j] = tolower(temp_word[j]);
    }
    node *temp_node = hashtable[i];
    while (temp_node != NULL)
    {
        if (strcmp(temp_node->word, temp_word))
        {
            temp_node = temp_node->next;
        }
        else
        {
            return true;
        }
    }
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO - DONE
    for (int i = 0; i < N; i++)
    {
        while (hashtable[i] != NULL)
        {
            free_first(&hashtable[i]);
        }
    } 
    return true;
}
