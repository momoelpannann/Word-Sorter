// Mohamed Elpannann 40251343
//COMP 348 Summer 2024
// Assignment 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a word should be skipped
// Iterates through the skip_words array and compares each word with the given word
// Returns 1 if the word should be skipped, 0 otherwise
int is_skip_word(char *word, char **skip_words, int skip_count) {
    for (int i = 0; i < skip_count; i++) {
        if (strcmp(word, skip_words[i]) == 0) {  // Use strcmp for exact match
            return 1;
        }
    }
    return 0;
}
// Function to read words from a file and store them in an array
// Continues reading words until n words are read or the end of file is reached
// Skips words that are in the skip_words array
void read_file(char *filename, int n, char **words, int *word_count, char **skip_words, int skip_count, char *wtype) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    char word[256];
    while (fscanf(file, "%255s", word) != EOF && *word_count < n) {
        if (!is_skip_word(word, skip_words, skip_count)) {
            words[*word_count] = strdup(word);
            (*word_count)++;
        }
    }

    fclose(file);
}