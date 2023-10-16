#include "main.h"
/**
 * _getline - gets a line from fd
 * @lineptr: buffer to fill line with
 * @stream: file descriptor
 * @n:length of the buffer
 * Return: num of characters
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	ssize_t rdbyte;
	char *ptr;

	if (!lineptr || !n)
		return (-1);
	if (*lineptr == NULL)
	{
		*n = 1024;
		ptr = malloc(sizeof(char) * (*n));
		if (!ptr)
			return (-1);
		*lineptr = ptr;
	}
	rdbyte = 0;
	while (((ch = getc(stream)) != EOF) && ch != '\n')
	{
		rdbyte++;
		if (rdbyte > ((ssize_t)*n - 2))
		{
			*n *= 2;
			ptr = realloc(*lineptr, *n);
			if (!ptr)
				return (-1);
			*lineptr = ptr;
		}
		(*lineptr)[rdbyte - 1] = ch;
	}
	if (ch == '\n')
	{
		(*lineptr)[rdbyte] = ch;
		(*lineptr)[rdbyte + 1] = '\0';
		return (rdbyte);
	}
	return (-1);
}

