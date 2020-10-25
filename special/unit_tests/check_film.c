#include "check_main.h"

START_TEST(test_film_create_usual)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc = film_create(&film, "Title", "Name", 2020);

    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(strcmp(film.title, "Title"), 0);
    ck_assert_int_eq(strcmp(film.name, "Name"), 0);
    ck_assert_int_eq(film.year, 2020);
    free(film.title);
    free(film.name);
}
END_TEST

Suite* film_create_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_create");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_create_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_film_free_strings_usual)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc = film_create(&film, "Title", "Name", 2020);
    if (rc == OK)
    {
        film_free_strings(&film);
    }
}
END_TEST

Suite* film_free_strings_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_free_strings");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_free_strings_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_film_read_empty_title)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_empty_title.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_empty_name)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_empty_name.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_neg_year)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_neg_year.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_big_year)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_bif_year.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_float_year)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_float_year.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_letter_year)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_letter_year.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_not_enough_info)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_not_enough_info.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, ERRVALUE);
        fclose(f);
    }
}
END_TEST

START_TEST(test_film_read_one_letters)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_one_letters.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(strcmp(film.title, "A"), 0);
        ck_assert_int_eq(strcmp(film.name, "B"), 0);
        ck_assert_int_eq(film.year, 2000);
        free(film.title);
        free(film.name);
    }
}
END_TEST

START_TEST(test_film_read_usual)
{
    struct film_struct film;
    memset(&film, 0, sizeof(struct film_struct));
    int rc;
    FILE *f = fopen("unit_tests/test_film_read_usual.txt", "r");
    if (f)
    {
        rc = film_read(f, &film);
        ck_assert_int_eq(rc, OK);
        ck_assert_int_eq(strcmp(film.title, "Two words"), 0);
        ck_assert_int_eq(strcmp(film.name, "One"), 0);
        ck_assert_int_eq(film.year, 2002);
        free(film.title);
        free(film.name);
    }
}
END_TEST

Suite* film_read_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("film_read");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_film_read_empty_title);
    tcase_add_test(tc_neg, test_film_read_empty_name);
    tcase_add_test(tc_neg, test_film_read_neg_year);
    tcase_add_test(tc_neg, test_film_read_big_year);
    tcase_add_test(tc_neg, test_film_read_float_year);
    tcase_add_test(tc_neg, test_film_read_letter_year);
    tcase_add_test(tc_neg, test_film_read_not_enough_info);
    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_film_read_one_letters);
    tcase_add_test(tc_pos, test_film_read_usual);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_film_cmp_title_eq)
{
    struct film_struct film_l = {"Same title", "name", 1999};
    struct film_struct film_r = {"Same title", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_film_cmp_title_eq_lshorter)
{
    struct film_struct film_l = {"Same titl", "name", 1999};
    struct film_struct film_r = {"Same title", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_title_eq_rshorter)
{
    struct film_struct film_l = {"Same title", "name", 1999};
    struct film_struct film_r = {"Same", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_film_cmp_title_eqlen_lsmaller)
{
    struct film_struct film_l = {"Abc", "name", 1999};
    struct film_struct film_r = {"Abd", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_title_eqlen_rsmaller)
{
    struct film_struct film_l = {"AZ", "name", 1999};
    struct film_struct film_r = {"AB", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_film_cmp_title_noteqlen_lsmaller)
{
    struct film_struct film_l = {"Abcd", "name", 1999};
    struct film_struct film_r = {"Abd", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_title_noteqlen_rsmaller)
{
    struct film_struct film_l = {"A ZX", "name", 1999};
    struct film_struct film_r = {"A B", "Some name", 1997};
    int rc;

    rc = film_cmp_title(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* film_cmp_title_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_cmp_title");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_cmp_title_eq);
    tcase_add_test(tc_neit, test_film_cmp_title_eq_lshorter);
    tcase_add_test(tc_neit, test_film_cmp_title_eq_rshorter);
    tcase_add_test(tc_neit, test_film_cmp_title_eqlen_lsmaller);
    tcase_add_test(tc_neit, test_film_cmp_title_eqlen_rsmaller);
    tcase_add_test(tc_neit, test_film_cmp_title_noteqlen_lsmaller);
    tcase_add_test(tc_neit, test_film_cmp_title_noteqlen_rsmaller);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_film_cmp_name_eq)
{
    struct film_struct film_l = {"Some title", "Same", 1999};
    struct film_struct film_r = {"title", "Same", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_film_cmp_name_eq_lshorter)
{
    struct film_struct film_l = {"Same titl", "abc", 1999};
    struct film_struct film_r = {"title", "abcd", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_name_eq_rshorter)
{
    struct film_struct film_l = {"Same title", "nameee", 1999};
    struct film_struct film_r = {"ere", "name", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_film_cmp_name_eqlen_lsmaller)
{
    struct film_struct film_l = {"Abc", "abc", 1999};
    struct film_struct film_r = {"fdzfs", "abd", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_name_eqlen_rsmaller)
{
    struct film_struct film_l = {"AZ", "ABZ", 1999};
    struct film_struct film_r = {"dz", "ABC", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_film_cmp_name_noteqlen_lsmaller)
{
    struct film_struct film_l = {"Abcd", "Nameeeee", 1999};
    struct film_struct film_r = {"fsf", "Xname", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_name_noteqlen_rsmaller)
{
    struct film_struct film_l = {"A ZX", "name", 1999};
    struct film_struct film_r = {"sdgsg", "A name", 1997};
    int rc;

    rc = film_cmp_name(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* film_cmp_name_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_cmp_name");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_cmp_name_eq);
    tcase_add_test(tc_neit, test_film_cmp_name_eq_lshorter);
    tcase_add_test(tc_neit, test_film_cmp_name_eq_rshorter);
    tcase_add_test(tc_neit, test_film_cmp_name_eqlen_lsmaller);
    tcase_add_test(tc_neit, test_film_cmp_name_eqlen_rsmaller);
    tcase_add_test(tc_neit, test_film_cmp_name_noteqlen_lsmaller);
    tcase_add_test(tc_neit, test_film_cmp_name_noteqlen_rsmaller);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_film_cmp_year_eq)
{
    struct film_struct film_l = {"AZ", "ABZ", 2000};
    struct film_struct film_r = {"dz", "ABC", 2000};
    int rc;

    rc = film_cmp_year(&film_l, &film_r);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(test_film_cmp_year_lsmaller)
{
    struct film_struct film_l = {"Abcd", "nameeeee", 1990};
    struct film_struct film_r = {"fsf", "X name", 1997};
    int rc;

    rc = film_cmp_year(&film_l, &film_r);
    if (rc < 0)
        rc = -1;
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_film_cmp_year_rsmaller)
{
    struct film_struct film_l = {"A ZX", "name", 1999};
    struct film_struct film_r = {"sdgsg", "A name", 1997};
    int rc;

    rc = film_cmp_year(&film_l, &film_r);
    if (rc > 0)
        rc = 1;
    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* film_cmp_year_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_cmp_year");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_cmp_year_eq);
    tcase_add_test(tc_neit, test_film_cmp_year_lsmaller);
    tcase_add_test(tc_neit, test_film_cmp_year_rsmaller);
    suite_add_tcase(s, tc_neit);

    return s;
}

START_TEST(test_film_copy_usual)
{
    struct film_struct film_original = {"Title here", "name", 2020};
    struct film_struct film_temp;
    memset(&film_temp, 0, sizeof(struct film_struct));
    int rc;

    rc = film_copy(&film_temp, &film_original);
    ck_assert_int_eq(rc, OK);
    ck_assert_int_eq(strcmp(film_temp.title, "Title here"), 0);
    ck_assert_int_eq(strcmp(film_temp.name, "name"), 0);
    ck_assert_int_eq(film_temp.year, 2020);
    free(film_temp.title);
    free(film_temp.name);
}
END_TEST


Suite* film_copy_suite(void)
{
    Suite *s;
    TCase *tc_neit;

    s = suite_create("film_copy");

    tc_neit = tcase_create("neitral");
    tcase_add_test(tc_neit, test_film_copy_usual);
    suite_add_tcase(s, tc_neit);

    return s;
}
