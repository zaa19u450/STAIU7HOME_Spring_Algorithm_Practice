#ifndef CHECK_MAIN_H
#define CHECK_MAIN_H

#include <check.h>
#include <assert.h>
#include "main_header.h"
#include "film.h"
#include "film_array.h"

Suite *film_create_suite(void);
Suite *film_free_strings_suite(void);
Suite *film_read_suite(void);
Suite *film_cmp_title_suite(void);
Suite *film_cmp_name_suite(void);
Suite *film_cmp_year_suite(void);
Suite *film_copy_suite(void);


#endif // CHECK_MAIN_H
