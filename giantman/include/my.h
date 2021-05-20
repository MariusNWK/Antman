/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** task 2
*/
#include <stddef.h>

void my_putchar(char);
char *my_strstr(char *, char const *);
int my_isneg(int);
int my_strcmp(char const *, char const *);
int my_put_nbr(int);
int my_strncmp(char const *, char const *, int);
void my_swap(int *, int *);
char *my_strupcase(char *);
int my_putstr(char const *);
char *my_strlowcase(char *);
int my_strlen(char const *);
char *my_strcapitalize(char *);
int my_getnbr(char const *);
int my_str_isalpha(char const *);
void my_sort_int_array(int *, int);
int my_str_isnum(char const *);
int my_compute_power_rec(int, int);
int my_str_islower(char const *);
int my_compute_square_root(int);
int my_str_isupper(char const *);
int my_is_prime(int);
int my_str_isprintable(char const *);
int my_find_prime_sup(int);
int my_showstr(char const *);
char *my_strcpy(char *, char const *);
int my_showmem(char const *, int);
char *my_strncpy(char *, char const *, int);
char *my_strcat(char *, char const *);
char *my_revstr(char *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);

///////////////////////////////////////////////////////////

int error_handling(int, char **);
char *file_reader(char const *);
size_t getfilesize(char const *);

///////////////////////////////////////////////////////////

void lzw_decompress_algo(const char *);

///////////////////////////////////////////////////////////

typedef struct char_infos
{
    int index;
    int input;
    int output;
    char *entry;
} infos_t;

typedef struct Cell
{
    infos_t data;
    struct Cell *next;
} list_t, cell_t;

list_t *empty_list(void);
int is_empty_list(list_t *);
long len_list(list_t *);
list_t *add_at(list_t *, infos_t, int);
infos_t get_at(list_t *, int);
void set_at(list_t *, infos_t, int);
list_t *free_at(list_t *, int);
list_t *move_at(list_t *, int, int);
list_t *free_list(list_t *);
void print_list(list_t *);

///////////////////////////////////////////////////////////

void display_decompressed(list_t *, int);

///////////////////////////////////////////////////////////