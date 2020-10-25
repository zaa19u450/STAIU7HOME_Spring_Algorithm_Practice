#include "main_header.h"
#include "film.h"
#include "film_array.h"
#include "my_getdelim.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int rc = OK;
    FILE *f = NULL;
    int n = 0;
    struct film_struct *films = NULL;
    struct film_struct *films_to_delete;
    struct film_struct goal;
    memset(&goal, 0, sizeof(struct film_struct));
    int index = 0;

    if ((argc < 3) || (argc > 4) || (strcmp(argv[2], "title") && strcmp(argv[2], "year")
                       && strcmp(argv[2], "name")))
    {
        rc = ERRPARAM;
    }
    else if ((argc == 4) && !strcmp(argv[2], "year"))
    {
		int year = atoi(argv[3]);
		if (((year == 0) && (argv[3][0] != '0')) ||
			(year < MINYEAR) || (year > MAXYEAR))
		rc = ERRPARAM;
    }

    if (rc == OK)
    {
        f = fopen(argv[1], "r");
        if (f)
        {
            rc = films_count(f, &n);
            if (rc == OK)
            {
                films = calloc(n, sizeof(struct film_struct));
                if (films)
                {
                    films_to_delete = films;
                    rewind(f);
                    if (!strcmp(argv[2], "title"))
                    {
                        rc = films_read_sort(f, films, n, film_cmp_title);
                        if (rc == OK)
                        {
                            if (argc == 3)
                                films_print(stdout, films, n);
                            else
                            {
                                goal.title = argv[3];
                                index = films_search(films, n, &goal, film_cmp_title);
                                if (index >= 0)
                                    film_print(stdout, (films + index));
                                else
                                    printf("Not found");
                            }

                        }
                    }
                    if (!strcmp(argv[2], "name"))
                    {
                        rc = films_read_sort(f, films, n, film_cmp_name);
                        if (rc == OK)
                        {
                            if (argc == 3)
                                films_print(stdout, films, n);
                            else
                            {
                                goal.name = argv[3];
                                index = films_search(films, n, &goal, film_cmp_name);
                                if (index >= 0)
                                    film_print(stdout, (films + index));
                                else
                                    printf("Not found");
                            }

                        }
                    }
                    if (!strcmp(argv[2], "year"))
                    {
                        rc = films_read_sort(f, films, n, film_cmp_year);
                        if (rc == OK)
                        {
                            if (argc == 3)
                                films_print(stdout, films, n);
                            else
                            {
                                goal.year = atoi(argv[3]);
                                if (((goal.year == 0) && (argv[3][0] != '0'))
                                        || (goal.year < MINYEAR) || (goal.year > MAXYEAR))
                                    rc = ERRVALUE;
                                else
                                {
                                    index = films_search(films, n, &goal, film_cmp_year);
                                    if (index >= 0)
                                        film_print(stdout, (films + index));
                                    else
                                        printf("Not found");
                                }
                            }
                        }
                    }
                    films_free(films_to_delete, n);
                }
                else
                    rc = ERRMEM;
            }
            fclose(f);
        }
        else
            rc = ERROPEN;
    }
    return rc;
}
