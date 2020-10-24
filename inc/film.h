#ifndef FILM_H
#define FILM_H

#include "main_header.h"

struct film_struct
{
    char *title;
    char *name;
    int year;
};

int film_create(struct film_struct *film, const char *title, const char *name, int year);
void film_free_strings(struct film_struct *film);

int film_read(FILE *f, struct film_struct *film);
void film_print(FILE *f, struct film_struct *film);

int film_cmp_title(const void *l, const void *r);
int film_cmp_name(const void *l, const void *r);
int film_cmp_year(const void *l, const void *r);

int film_copy(struct film_struct *to, const struct film_struct *from);

#endif // FILM_H
