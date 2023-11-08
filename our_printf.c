#include "shell.h"

/**
 * our_printf - Write a string to standard output.
 * @text: The string to be written.
 *
 * Returns the number of characters written(excluding null terminator).
 */

void our_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
