// Mohamed Elpannann 40251343
//COMP 348 Summer 2024
// Assignment 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void read_file(char *filename, int n, char **words, int *word_count, char **skip_words, int skip_count, char *wtype);
void filter_words(char **words, int *word_count, char *wtype);
void sort_words(char **words, int word_count, char *sorttype);
void print_output(char **words, int word_count);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <inputfile> <n> <wtype> [<sorttype>] [<skipword1> <skipword2> ...]\n", argv[0]);
        return 1;  // Return 1 for incorrect usage
    }

    char *inputfile = argv[1];
    int n = atoi(argv[2]);
    char *wtype = argv[3];
    char *sorttype = (argc > 4) ? argv[4] : "ASC";
    char **skip_words = (argc > 5) ? &argv[5] : NULL;
    int skip_count = (argc > 5) ? argc - 5 : 0;

    if (n <= 0) {
        fprintf(stderr, "Error: The number of words to read must be a positive integer.\n");
        return 2;  // Return 2 for invalid number of words
    }

    if (strcmp(wtype, "ALPHA") != 0 && strcmp(wtype, "ALPHANUM") != 0 && strcmp(wtype, "ALL") != 0) {
        fprintf(stderr, "Error: Invalid word type. Use 'ALPHA', 'ALPHANUM', or 'ALL'.\n");
        return 3;  // Return 3 for invalid word type
    }

    if (strcmp(sorttype, "ASC") != 0 && strcmp(sorttype, "DESC") != 0) {
        fprintf(stderr, "Error: Invalid sort type. Use 'ASC' or 'DESC'.\n");
        return 4;  // Return 4 for invalid sort type
    }

    FILE *file = fopen(inputfile, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", inputfile);
        return 5;  // Return 5 for file open error
    }
    fclose(file);
//Array to store the words read from the file
    char *words[n];
    int word_count = 0;
//reading file and processing words
    read_file(inputfile, n, words, &word_count, skip_words, skip_count, wtype);
    printf("Words read: %d\n", word_count);

    filter_words(words, &word_count, wtype);
    printf("Words after filtering: %d\n", word_count);

    sort_words(words, word_count, sorttype);
    print_output(words, word_count);
//freeing the memory
    for (int i = 0; i < word_count; i++) {
        free(words[i]);
    }

    return 0;
}