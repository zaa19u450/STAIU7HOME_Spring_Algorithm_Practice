#ifndef FILM_ARRAY_H
#define FILM_ARRAY_H

#include "main_header.h"
#include "film.h"

int films_count(FILE *f, int *n);
int films_change(struct film_struct *film1, struct film_struct *film2);

int films_read_sort(FILE *f, struct film_struct *films, int n,
                     int (*film_cmp)(const void *, const void *));
void films_print(FILE *f, struct film_struct *films, int n);

int films_search(struct film_struct *films, int n, struct film_struct *goal,
                 int (*film_cmp)(const void *, const void *));

void films_free(struct film_struct *films, int n);

#endif // FILM_ARRAY_H
