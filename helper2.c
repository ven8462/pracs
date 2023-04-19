#include "main.h"

/* writes string to stderr */
void writeStringToStderr(char *str) 
{
    size_t len = str_len(str);

    write(STDERR_FILENO, str, len);
}

/**
*_memory1 - memory buffer
 * @buffer: buffer
 *
 * Return: int
 * On error, -1 is returned, and errno is set appropriately.
 */

int _memory1(char *buffer)
{
	int i, count = 2;
	char *delim = ":";

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == delim[0])
			count++;
	}
	return (count);
}
