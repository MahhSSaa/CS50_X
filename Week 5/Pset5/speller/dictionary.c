// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 150000;

// Hash table
node *table[N];

int sizeofdic = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_num = hash(word);
    node *new_node = table[hash_num];

    while (new_node != NULL)
    {
        if (strcasecmp(word, new_node->word) == 0)
        {
            return true;
        }
        new_node = new_node->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dic_open = fopen(dictionary, "r");
    if (dictionary == NULL)
    {
        printf("Unable to open %s \n", dictionary);
        return false;
    }

    // array for words
    char input_word[LENGTH + 1];
    while (fscanf(dic_open, "%s", input_word) != EOF) // scan untill end of file
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // coping input word in new node
        strcpy(new_node->word, input_word);
        int hash_num = hash(input_word);

        // putting new node in wright place in hash table
        new_node->next = table[hash_num];
        table[hash_num] = new_node;
        sizeofdic++;
    }

    fclose(dic_open);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sizeofdic;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *new_node = table[i];
        while (new_node != NULL)
        {
            node *temp = new_node;
            new_node = new_node->next;
            free(temp);
        }
        if (new_node == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
