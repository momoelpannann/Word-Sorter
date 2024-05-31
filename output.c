// Mohamed Elpannann 40251343
//COMP 348 Summer 2024
// Assignment 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to compare two strings in ascending order
int compare_asc(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

//function to compare two strings in descending order
int compare_desc(const void *a, const void *b) {
    return strcmp(*(const char **)b, *(const char **)a);
}

//function to sort the words array based on the given sort type
void sort_words(char **words, int word_count, char *sorttype) {
    if (strcmp(sorttype, "ASC") == 0) {
        qsort(words, word_count, sizeof(char *), compare_asc);
    } else if (strcmp(sorttype, "DESC") == 0) {
        qsort(words, word_count, sizeof(char *), compare_desc);
    }
}
//function that iterates through the sorted word array
//prints all the contents and skips a line at the 10th word
void print_output(char **words, int word_count) {
    for (int i = 0; i < word_count; i++) {
        printf("%s", words[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}