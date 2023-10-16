#include "main.h"
/**
 * _strdup - returns a pointer to a new string which is a duplicate of the
 * string str. Memory for the new string is obtained with malloc, and freed
 * @str: string to be copied
 * Return: a pointer to the new str
 */
char *_strdup(char *str)
{
	int i, j;
	char *p;

	i = j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	p = malloc((i + 1) * sizeof(char));
	if (p == NULL)
		return (p);
	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

/**
 * str_strip - strip leading and trailing whitespace from a string
 * @s: The string to search.
 * Return: void
 */
void str_strip(char *s)
{
	int i, j, len;

	if (s == NULL)
		return;
	len = _strlen(s);
	/* Find the index of the first non-whitespace character */
	for (i = 0; (i < len) && isspace(s[i]); i++)
	{};
	/* Shift the non-whitespace characters to the beginning of the string*/
	for (j = 0; i < len; i++, j++)
	{
		s[j] = s[i];
	}
	s[j] = '\0';

	/*
	 * Striping whitespace character at the end of a string
	 * Start from the end of the string and move backwards
	*/
	len = _strlen(s);
	for (i = (len - 1); i >= 0; i--)
	{
		if (isspace(s[i]))
		{
			/*
			 * Replace white space characters with null terminators
			*/
			s[i] = '\0';
		}
		else
		{
			/*
			 * Stop when a non-white space character is encountered
			*/
			break;
		}
	}
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest
 * @dest: char type poiter
 * @src: char type pointer
 * Return: char type pointer
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;

	len = 0;

	while (src[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - return the length of a string
 * @s: pointer variable of char type
 * Return: length of string
 */
size_t _strlen(char *s)
{
	size_t counter, i;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}
/**
 * _strcat - appends the src string to the dest string, overwriting
 * the terminating null byte (\0) at the end of dest, and then adds a
 * terminating null byte
 * @dest: pointer to a char
 * @src: pointer to a char
 * Return: chararacter
 */
char *_strcat(char *dest, char *src)
{
	int i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
