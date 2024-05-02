#include "shell.h"
#define BUFFER_SIZE 1024

/**
 * custom getline function
*/
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream) {
    char *buffer = *lineptr;
    size_t size = *n;
    size_t pos = 0;
    int c;

    if (buffer == NULL || size == 0) {
        size = BUFFER_SIZE;
        buffer = (char *)malloc(size);
        if (buffer == NULL) {
            return -1;  // Error allocating memory
        }
    }

    while (1) {
        c = getc(stream);  // Read one character at a time from the specified stream
        if (c == EOF || c == '\n') {
            buffer[pos] = '\0';  // Terminate the string
            break;
        }
        buffer[pos] = c;
        pos++;

        if (pos >= size - 1) {
            size *= 2;  // Double the buffer size if needed
            char *new_buffer = (char *)realloc(buffer, size);
            if (new_buffer == NULL) {
                free(buffer);
                return -1;  // Error reallocating memory
            }
            buffer = new_buffer;
        }
    }

    *lineptr = buffer;
    *n = size;
    return pos;  // Return the number of characters read
}
