#include "film_array.h"

int films_count(FILE *f, int *n)
{
    int rc = OK;
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    *n = 0;

    while ((!feof(f)) && (rc == OK))
    {
        rc = film_read(f, &film);
        if (rc == OK)
        {
            (*n)++;
            film_free_strings(&film);
        }
    }
    if ((*n) == 0)
        rc = ERREMPTY;
    return rc;
}

int films_change(struct film_struct *film1, struct film_struct *film2)
{
    struct film_struct film_temp;
    memset(&film_temp, 0, sizeof(struct film_struct));
    if (film_copy(&film_temp, film1) || film_copy(film1, film2) || film_copy(film2, &film_temp))
    {
        return ERRMEM;
    }

    film_free_strings(&film_temp);
    return OK;
}

void films_print(FILE *f, struct film_struct *films, int n)
{
    for (int i = 0; i < n; i++)
        film_print(f, (films + i));
}

int films_read_sort(FILE *f, struct film_struct *films, int n,
                     int (*film_cmp)(const void *, const void *))
{
    int rc = OK;
    for (int i = 0; (i < n) && (rc == OK); i++)
    {
        film_read(f, films + i);
        for (int j = i; (j > 0) && (film_cmp((films + j), (films + (j - 1))) < 0); j--)
            rc = films_change((films + j), (films + (j - 1)));
    }
    return rc;
}

int films_search(struct film_struct *films, int n, struct film_struct *goal,
                 int (*film_cmp)(const void *, const void *))
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (film_cmp(goal, films+middle) < 0)
            high = middle - 1;
        else if (film_cmp(goal, films+middle) > 0)
            low = middle + 1;
        else
            return middle;
    }
    return ERRNOTFOUND;
}

void films_free(struct film_struct *films, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((films + i))
            film_free_strings((films + i));
    }
    free(films);
}

