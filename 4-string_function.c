#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: pointer to a character
 * Return: the integer
 */
int _atoi(char *s)
{
	int i, sign;
	unsigned int number;

	sign = 1;
	number = 0;
	i = 0;
	for (; s[i] != '\0'; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
			number = (number * 10) + (s[i] - '0');
		else if (number > 0)
			break;
	}
	return (number * sign);
}

/**
 * _strchr -  locates a character in a string.
 * @s: pointer to the string
 * @c: variable c of type character
 * Return: a pointer to the first occurrence of the character c in the string
 * s, or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (NULL);
}

/**
 * _strncmp -  compares only  the  first  (at  most)  n bytes of s1 and s2.
 * @s1: pointer to a char
 * @s2: pointer to a char
 * @n: number of character to be compared
 * Return: an integer
 */
int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strcspn - gets the length of a prefix substring.
 * @s: pointer to the string
 * @reject: pointer to a character
 * Return: the number of bytes in the initial segment of s which consist only
 * of bytes from reject
 */
size_t _strcspn(char *s, const char *reject)
{
	int n, i;
	size_t counter;

	counter = 0;
	for (i = 0; s[i]; i++)
	{
		n = 0;
		for (; reject[n] != '\0'; n++)
		{
			if (s[i] == reject[n])
			{
				break;
			}
		}
		if (s[i] == reject[n])
			break;
		counter++;
	}
	return (counter);
}

/**
 * _strspn - gets the length of a prefix substring.
 * @s: pointer to the string
 * @accept: pointer to a character
 * Return: the number of bytes in the initial segment of s which consist only
 * of bytes from accept
 */
size_t _strspn(char *s, const char *accept)
{
	int n, i;
	size_t counter;

	counter = 0;
	for (i = 0; s[i]; i++)
	{
		n = 0;
		for (; accept[n] != '\0'; n++)
		{
			if (s[i] == accept[n])
			{
				counter++;
				break;
			}
		}
		if (s[i] != accept[n])
			break;
	}
	return (counter);
}
