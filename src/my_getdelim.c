#include "my_getdelim.h"

int my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
    char c;
    int rc = OK;
    long int go_back;
    go_back = ftell(stream);
	
	if (go_back == SEEK_END)
		return ERRVALUE;

    if (go_back == -1L)
        return ERRFILE;

    size_t len = 0;
    while (((c = fgetc(stream)) != delim) && (c != EOF))
	{
		//printf("!%c!", c);
        len++;
	}
    if (len)
    {
        *lineptr = calloc(len + 1, sizeof(char));
        if (*lineptr != NULL)
        {
            rc = fseek(stream, go_back, SEEK_SET);
            if (rc == OK)
            {
                for (size_t i = 0; i < len; i++)
                    (*lineptr)[i] = fgetc(stream);
                c = fgetc(stream);
                (*lineptr)[len] = '\0';
            }
            else
            {
                free(*lineptr);
                rc = ERRFILE;
            }
        }
        else
            rc = ERRMEM;
    }
    else
        rc = ERRVALUE;
    *n = len;
    return rc;
}
