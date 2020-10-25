#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <assert.h>
#include "main_header.h"
#include "film.h"
#include "film_array.h"
#include "my_getdelim.h"

Suite *film_create_suite(void);
Suite *film_free_strings_suite(void);
Suite *film_read_suite(void);
Suite *film_cmp_title_suite(void);
Suite *film_cmp_name_suite(void);
Suite *film_cmp_year_suite(void);
Suite *film_copy_suite(void);

Suite* my_getdelim_suite(void);

Suite* films_count_suite(void);
Suite* films_change_suite(void);
Suite* films_read_sort_suite(void);
Suite* films_search_suite(void);

#endif // CHECK_MAIN_H
