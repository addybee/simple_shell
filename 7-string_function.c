#include "main.h"

/**
 * _strcmp - compares two strings.
 * @s1: pointer to a char
 * @s2: pointer to a char
 * Return: an integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strtok - extract tokens from strings
 * @str: the parsed string to be tokenize
 * @delim: set of bytes that delimit the tokens in the parsed string
 * Return:  pointer to the next token, or NULL if there are  no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *var;

	if (str == NULL)
	{
		str = var;
		if (str == NULL)
			return (NULL);
	}
	str = str + _strspn(str, delim);
	if (*str == '\0')
	{
		var = NULL;
		return (var);
	}
	var = str + _strcspn(str, delim);
	if (*var == '\0')
	{
		var = NULL;
	}
	else
	{
		*var = '\0';
		var++;
	}
	return (str);
}
