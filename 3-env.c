#include "main.h"
/**
 * get_env - function searches the environment list to find the environment
 * variable name
 * @name:  environment variable name
 * Return: pointer to the corresponding value string  or NULL if no match.
 */
char *get_env(char *name)
{
	char **env = environ;
	char *result = NULL, *ptr = NULL;
	int i, j;

	j = (_strlen(name) + 2);
	ptr =  malloc(j * sizeof(char));
	if (!ptr)
		NULL;
	ptr = _strcpy(ptr, name);
	strcat(ptr, "=");
	i = 0;
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], ptr, _strlen(ptr)) == 0)
		{
			free(ptr);
			result = _strchr(env[i], '=');
			result++;
			return (result);
		}
		i++;
	}
	free(ptr);
	return (NULL);
}
