#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * custom getline function
*/
ssize_t custom_getline(
    char ** __restrict __linep, size_t * __restrict __linecapp, FILE * __restrict __stream)
    {
    if (__linep == NULL || __linecapp == NULL || __stream == NULL) {
        return -1;
    }

    char *line = *__linep;
    size_t linecap = *__linecapp;
    ssize_t linelen = 0;
    int c;

    if (line == NULL || linecap == 0) {
        linecap = 128;
        line = malloc(linecap);
        if (line == NULL) {
            return -1;
        }
    }

    while ((c = getc(__stream)) != EOF) {
        if (linelen + 1 >= linecap) {
            size_t newcap = linecap * 2;
            char *newline = realloc(line, newcap);
            if (newline == NULL) {
                return -1;
            }
            line = newline;
            linecap = newcap;
        }
        line[linelen++] = c;
        if (c == '\n') {
            break;
        }
    }

    if (linelen == 0 || ferror(__stream)) {
        free(line);
        return -1;
    }

    line[linelen] = '\0';
    *__linep = line;
    *__linecapp = linecap;
    return linelen;
}
