// Mohamed Elpannann 40251343
//COMP 348 Summer 2024
// Assignment 1
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// Helper function to check if a character is alphanumeric
int is_alphanum(char c) {
    return isalnum(c);
}

// Helper function to check if a character is alphabetic
int is_alpha(char c) {
    return isalpha(c);
}
//function that iterates through the list of words and filters out words that do not match the given word type
//The function updates the word_count and the words array to only include valid words
void filter_words(char **words, int *word_count, char *wtype) {
    int new_count = 0;
    for (int i = 0; i < *word_count; i++) {
        int valid = 1;
        for (char *c = words[i]; *c; c++) {
            if ((strcmp(wtype, "ALPHA") == 0 && !is_alpha(*c)) ||
                (strcmp(wtype, "ALPHANUM") == 0 && !is_alphanum(*c))) {
                valid = 0;
                break;
            }
        }
        if (valid || strcmp(wtype, "ALL") == 0) {  // Include all words for the "ALL" type
            words[new_count++] = words[i];
        } else {
            free(words[i]);
        }
    }
    *word_count = new_count;
}