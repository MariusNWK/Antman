/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *tab, int size)
{
    int a = 0;
    int b = 0;

    while (b < size) {
        for (int i = 0; tab[i] <= tab[size]; i++) {
            if (i >= 1 && tab[i] > tab[i - 1]) {
                a = tab[i];
                tab[i] = tab[i - 1];
                tab[i - 1] = a;
            }
            else
                b++;
        }
    }
}
