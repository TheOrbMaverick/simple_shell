#include "shell.h"

/**
 * our_printf - Write a string to standard output.
 * @format: The string to be written.
 *
 * Returns the number of characters written(excluding null terminator).
 */

void our_printf(const char *format, ...)
{
	/* Declare a va_list to hold the variable arguments. */
	va_list args;

	/* Initialize the va_list with the provided format. */
	va_start(args, format);
	/* Use vprintf to print the formatted output with variable arguments. */
	vprintf(format, args);
	/* Clean up and free resources associated with va_list. */
	va_end(args);
}
