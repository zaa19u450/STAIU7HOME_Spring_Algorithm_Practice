#include "film.h"

int film_create(struct film_struct *film, const char *title, const char *name, int year)
{
    int rc = OK;
    char *title_temp = NULL;
    char *name_temp = NULL;

    title_temp = calloc(strlen(title) + 1, sizeof(char));
    if (title_temp != NULL)
    {
        title_temp = strncpy(title_temp, title, strlen(title));
        name_temp = calloc(strlen(name) + 1, sizeof(char));
        if (name_temp != NULL)
        {
			name_temp = strcpy(name_temp, name);
            free(film->title);
            free(film->name);

            film->title = title_temp;
            film->name = name_temp;
            film->year = year;
        }
        else
        {
            free(title_temp);
            rc = ERRMEM;
        }
    }
    else
        rc = ERRMEM;

    return rc;
}

void film_free_strings(struct film_struct *film)
{
    free(film->title);
    film->title = NULL;
    free(film->name);
    film->name = NULL;
}



int film_read(FILE *f, struct film_struct *film)
{
    int rc = OK;

    char *title = NULL;
    char *name = NULL;
    int year = 0;

    size_t len = 0;
    ssize_t read = 0;

    if ((read = getline(&title, &len, f)) > 0)
    {
		title[strlen(title)-2] = '\0';
        len = 0;
        if ((read = getline(&name, &len, f)) > 0)
        {
			name[strlen(name)-2] = '\0';
            if ((fscanf(f, "%d\n", &year) == 1) && (year >= MINYEAR) && (year <= MAXYEAR))
            {
                rc = film_create(film, title, name, year);
            }
            else
                rc = ERRVALUE;
        }
        else
            rc = ERRVALUE;

    }
    else
        rc = ERRVALUE;

    free(title);
    free(name);

    return rc;
}

void film_print(FILE *f, struct film_struct *film)
{
    fprintf(f, "%s\n", film->title);
    fprintf(f, "%s\n", film->name);
    fprintf(f, "%d\n", film->year);
}

int film_cmp_title(const void *l, const void *r)
{
    struct film_struct *film_l = (struct film_struct *) l;
    struct film_struct *film_r = (struct film_struct *) r;

    size_t len_l = strlen(film_l->title);
    size_t len_r = strlen(film_r->title);

    if (len_l == len_r)
        return strncmp(film_l->title, film_r->title, len_l);
    else
    {
        if (len_l < len_r)
        {
            if (strncmp(film_l->title, film_r->title, len_l) <= 0)
                return -1;
            else
                return 1;
        }
        else
        {
            if (strncmp(film_l->title, film_r->title, len_r) >= 0)
                return 1;
            else
                return -1;
        }
    }
}

int film_cmp_name(const void *l, const void *r)
{
    struct film_struct *film_l = (struct film_struct *) l;
    struct film_struct *film_r = (struct film_struct *) r;

    size_t len_l = strlen(film_l->name);
    size_t len_r = strlen(film_r->name);

    if (len_l == len_r)
        return strncmp(film_l->name, film_r->name, len_l);
    else
    {
        if (len_l < len_r)
        {
            if (strncmp(film_l->name, film_r->name, len_l) <= 0)
                return -1;
            else
                return 1;
        }
        else
        {
            if (strncmp(film_l->name, film_r->name, len_r) >= 0)
                return 1;
            else
                return -1;
        }
    }
}

int film_cmp_year(const void *l, const void *r)
{
    struct film_struct *film_l = (struct film_struct *) l;
    struct film_struct *film_r = (struct film_struct *) r;

    return ((film_l->year) - (film_r->year));
}

int film_copy(struct film_struct *to, const struct film_struct *from)
{
    return film_create(to, from->title, from->name, from->year);
}
