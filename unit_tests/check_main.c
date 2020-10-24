#include "check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner *sr;
    sr = srunner_create(film_create_suite());
    srunner_add_suite(sr, film_free_strings_suite());
    srunner_add_suite(sr, film_read_suite());
    srunner_add_suite(sr, film_cmp_title_suite());
    srunner_add_suite(sr, film_cmp_name_suite());
    srunner_add_suite(sr, film_cmp_year_suite());
    srunner_add_suite(sr, film_copy_suite());

    srunner_run_all(sr, CK_VERBOSE);
    no_failed = srunner_ntests_failed(sr);

    srunner_free(sr);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
