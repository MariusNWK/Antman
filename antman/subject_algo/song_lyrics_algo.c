/*
** EPITECH PROJECT, 2021
** song_lyrics_algo
** File description:
** antman
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int words_counter(char *text)
{
    int words_nbr = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n') {
            words_nbr++;
        }
        if (text[i + 1] == '\0' && text[i] != ' ' && text[i] != '\n') {
            words_nbr++;
        }
    }
    return (words_nbr);
}

int *words_size(char *text, int words_nbr)
{
    int *sizes = malloc(sizeof(int) * words_nbr);

    for (int i = 0, k = 0, s = 0; k < words_nbr; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\0') {
            sizes[k] = s;
            k++;
            s = 0;
        }
        else {
            s++;
        }
    }
    return (sizes);
}

char **set_words(char *text)
{
    int words_nbr = words_counter(text);
    int *sizes = words_size(text, words_nbr);
    char **words = malloc(sizeof(char *) * words_nbr);

    for (int i = 0, k = 0; i < words_nbr; i++) {
        words[i] = malloc(sizeof(char) * sizes[i] + 1);
        for (int j = 0; j <= sizes[i]; j++, k++) {
            if (j == sizes[i]) {
                words[i][j] = '\0';
            }
            else {
                words[i][j] = text[k];
            }
        }
    }
    sizes = set_twin_words(words_nbr, words, sizes);
    display_unique(words_nbr, words, sizes);
    display_values(words_nbr, words, sizes);
    free(sizes);
    return (words);
}

void song_lyrics_algo(const char *filepath)
{
    char *song_lyrics = file_reader(filepath);
    char **words = set_words(song_lyrics);

    for (int i = 0, nbr = words_counter(song_lyrics); i < nbr; i++) {
        free(words[i]);
    }
    free(words);
    free(song_lyrics);
}