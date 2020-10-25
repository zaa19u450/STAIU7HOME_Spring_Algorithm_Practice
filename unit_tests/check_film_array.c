#include "check_main.h"

START_TEST(test_films_count_empty)
{
    int rc = OK;
    int n = 0;
    FILE *f = fopen("unit_tests\\test_films_count_empty.txt", "r");
    if (f)
    {
        rc = films_count(f, &n);
        ck_assert_int_eq(rc, ERREMPTY);
        ck_assert_int_eq(n, 0);
        fclose(f);
    }
}
END_TEST

START_TEST(test_films_count_with_error_in2)
{
    int rc = OK;
    int n = 0;
    FILE *f = fopen("unit_tests\\test_films_count_with_error_in2.txt", "r");
    if (f)
    {
        rc = films_count(f, &n);
        ck_assert_int_eq(rc, ERRVALUE);
        ck_assert_int_eq(n, 1);
        fclose(f);
    }
}
END_TEST

START_TEST(test_films_count_usual3)
{
    int rc = OK;
    int n = 0;
    FILE *f = fopen("unit_tests\\test_films_count_usual3.txt", "r");
    if (f)
    {
        rc = films_count(f, &n);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(n, 3);
        fclose(f);
    }
}
END_TEST

Suite* films_count_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("films_count");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_films_count_empty);
    tcase_add_test(tc_neg, test_films_count_with_error_in2);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_films_count_usual3);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_films_change_usual)
{
    int rc = OK;
    struct film_struct film1;
    memset(&film1, 0, sizeof(struct film_struct));
    struct film_struct film2;
    memset(&film2, 0, sizeof(struct film_struct));
    rc = film_create(&film1, "Title1", "Name1", 2001);
    ck_assert_int_eq(rc, OK);
    rc = film_create(&film2, "Title2", "Name2", 2002);
    ck_assert_int_eq(rc, OK);


    rc = films_change(&film1, &film2);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(strcmp(film1.title, "Title2"), 0);
    ck_assert_int_eq(strcmp(film1.name, "Name2"), 0);
    ck_assert_int_eq(film1.year, 2002);

    ck_assert_int_eq(strcmp(film2.title, "Title1"), 0);
    ck_assert_int_eq(strcmp(film2.name, "Name1"), 0);
    ck_assert_int_eq(film2.year, 2001);
    film_free_strings(&film1);
    film_free_strings(&film2);
}
END_TEST

Suite* films_change_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("films_change");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_films_change_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_films_read_sort_title_stb)
{
    int rc = OK;
    int n = 4;
    struct film_struct *films = NULL;
    struct film_struct *film_to_delete = NULL;
    FILE *f = fopen("unit_tests\\test_films_read_sort_title_stb.txt", "r");
    if (f)
    {
        films = calloc(n, sizeof(struct film_struct));
        if (films)
        {
            film_to_delete = films;
            rc = films_read_sort(f, films, n, film_cmp_title);
            ck_assert_int_eq(rc, OK);

            ck_assert_int_eq(strcmp((films + 0)->title, "Ab"), 0);
            ck_assert_int_eq(strcmp((films + 0)->name, "Author2"), 0);
            ck_assert_int_eq((films + 0)->year, 2002);

            ck_assert_int_eq(strcmp((films + 1)->title, "Ab"), 0);
            ck_assert_int_eq(strcmp((films + 1)->name, "Author4"), 0);
            ck_assert_int_eq((films + 1)->year, 2004);

            ck_assert_int_eq(strcmp((films + 2)->title, "T h"), 0);
            ck_assert_int_eq(strcmp((films + 2)->name, "Author3"), 0);
            ck_assert_int_eq((films + 2)->year, 2003);

            ck_assert_int_eq(strcmp((films + 3)->title, "Z"), 0);
            ck_assert_int_eq(strcmp((films + 3)->name, "Author1"), 0);
            ck_assert_int_eq((films + 3)->year, 2001);

            films_free(film_to_delete, n);
        }
        fclose(f);
    }
}
END_TEST

START_TEST(test_films_read_sort_name_one_film)
{
    int rc = OK;
    int n = 1;
    struct film_struct *films = NULL;
    struct film_struct *film_to_delete = NULL;
    FILE *f = fopen("unit_tests\\test_films_read_sort_name_one_film.txt", "r");
    if (f)
    {
        films = calloc(n, sizeof(struct film_struct));
        if (films)
        {
            film_to_delete = films;
            rc = films_read_sort(f, films, n, film_cmp_name);
            ck_assert_int_eq(rc, OK);

            ck_assert_int_eq(strcmp((films + 0)->title, "Title"), 0);
            ck_assert_int_eq(strcmp((films + 0)->name, "Name"), 0);
            ck_assert_int_eq((films + 0)->year, 2020);

            films_free(film_to_delete, n);
        }
        fclose(f);
    }
}
END_TEST

START_TEST(test_films_read_sort_year_sorted)
{
    int rc = OK;
    int n = 4;
    struct film_struct *films = NULL;
    struct film_struct *film_to_delete = NULL;
    FILE *f = fopen("unit_tests\\test_films_read_sort_year_sorted.txt", "r");
    if (f)
    {
        films = calloc(n, sizeof(struct film_struct));
        if (films)
        {
            film_to_delete = films;
            rc = films_read_sort(f, films, n, film_cmp_year);
            ck_assert_int_eq(rc, OK);

            ck_assert_int_eq(strcmp((films + 0)->title, "Title1"), 0);
            ck_assert_int_eq(strcmp((films + 0)->name, "Name1"), 0);
            ck_assert_int_eq((films + 0)->year, 2001);

            ck_assert_int_eq(strcmp((films + 1)->title, "Title2"), 0);
            ck_assert_int_eq(strcmp((films + 1)->name, "Name2"), 0);
            ck_assert_int_eq((films + 1)->year, 2002);

            ck_assert_int_eq(strcmp((films + 2)->title, "Title3"), 0);
            ck_assert_int_eq(strcmp((films + 2)->name, "Name3"), 0);
            ck_assert_int_eq((films + 2)->year, 2003);

            ck_assert_int_eq(strcmp((films + 3)->title, "Title4"), 0);
            ck_assert_int_eq(strcmp((films + 3)->name, "Name4"), 0);
            ck_assert_int_eq((films + 3)->year, 2004);

            films_free(film_to_delete, n);
        }
        fclose(f);
    }
}
END_TEST

Suite* films_read_sort_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("films_read_sort");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_films_read_sort_title_stb);
    tcase_add_test(tc_neit, test_films_read_sort_name_one_film);
    tcase_add_test(tc_neit, test_films_read_sort_year_sorted);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_films_search_title_no)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title", "Name1", 2001};
        rc = films_search(films, n, &goal, film_cmp_title);
        ck_assert_int_eq(rc, ERRNOTFOUND);

        free(films);
    }
}
END_TEST

START_TEST(test_films_search_name_no)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title1", "name1", 2001};
        rc = films_search(films, n, &goal, film_cmp_name);
        ck_assert_int_eq(rc, ERRNOTFOUND);

        free(films);
    }
}
END_TEST

START_TEST(test_films_search_year_no)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title1", "Name1", 2010};
        rc = films_search(films, n, &goal, film_cmp_year);
        ck_assert_int_eq(rc, ERRNOTFOUND);

        free(films);
    }
}
END_TEST

START_TEST(test_films_search_title_beg)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title1", "Name", 2010};
        rc = films_search(films, n, &goal, film_cmp_title);
        ck_assert_int_eq(rc, 0);

        free(films);
    }
}
END_TEST

START_TEST(test_films_search_name_mid)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title", "Name2", 2000};
        rc = films_search(films, n, &goal, film_cmp_name);
        ck_assert_int_eq(rc, 1);

        free(films);
    }
}
END_TEST

START_TEST(test_films_search_year_end)
{
    int rc = OK;
    int n = 3;
    struct film_struct *films = NULL;

    films = calloc(n, sizeof(struct film_struct));
    if (films)
    {
        (films + 0)->title = "Title1";
        (films + 0)->name = "Name1";
        (films + 0)->year = 2001;

        (films + 1)->title = "Title2";
        (films + 1)->name = "Name2";
        (films + 1)->year = 2002;

        (films + 2)->title = "Title3";
        (films + 2)->name = "Name3";
        (films + 2)->year = 2003;

        struct film_struct goal = {"Title", "Name", 2003};
        rc = films_search(films, n, &goal, film_cmp_year);
        ck_assert_int_eq(rc, 2);

        free(films);
    }
}
END_TEST

Suite* films_search_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("films_search");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_films_search_title_no);
    tcase_add_test(tc_neg, test_films_search_name_no);
    tcase_add_test(tc_neg, test_films_search_year_no);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_films_search_title_beg);
    tcase_add_test(tc_pos, test_films_search_name_mid);
    tcase_add_test(tc_pos, test_films_search_year_end);
    suite_add_tcase(s, tc_pos);

    return s;
}

