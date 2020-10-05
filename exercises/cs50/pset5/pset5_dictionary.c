// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Number of words in dictionary
unsigned int wordsInDictionary = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // To lower case the word
    char lowercaseWord[strlen(word) + 1];
    for(int i = 0; i < strlen(word); i++) {
        lowercaseWord[i] = tolower(word[i]);
    }
    // Hash word to obtain a hash value
    int hashValue = hash(lowercaseWord);
    // Access linked list at that index in the hash table
    node *cursor = table[hashValue];
    // Traverse linked list, looking for the word
    while(cursor != NULL) {
        if(!strcasecmp(word, cursor->word)) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return tolower(word[0] - 'a');
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL) {
        return false;
    }

    // Initiate variable to store current word readed
    char *word = calloc(LENGTH + 1, sizeof(char));
    if(word == NULL) {
        return false;
    }

    // Read strings from file one at a time
    while(fscanf(dict, "%s", word) != EOF) {

        // Creat a new node for each word
        node *newWordNode = malloc(sizeof(node));
        if (newWordNode == NULL) {
            fclose(dict);
            return false;
        }

        // Copy word into node
        strcpy(newWordNode->word, word);
        newWordNode->next = NULL;

        // Hash word to obtain a hash value
        int hashValue = hash(word);

        // Insert node into linked list in the hash table (insert at beginning)
        if(table[hashValue] == NULL) {
            table[hashValue] = newWordNode;
        }
        else {
            newWordNode->next = table[hashValue];
            table[hashValue] = newWordNode;
        }
        wordsInDictionary++;
    }

    // Close dictionary file
    fclose(dict);
    // Release temporarily allocated string
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordsInDictionary;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i = 0; i < N; i++) {
        // Set pointer to head of list
        node *cursor = table[i];
        while (cursor != NULL) {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);
    }
    return true;
}