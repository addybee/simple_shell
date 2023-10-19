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
	_strcpy(ptr, name);
	_strcat(ptr, "=");
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

/**
 * _setenv - change or add an environment variable
 * @var: the variable name
 * @value: the value of the variable
 * Return: 0 on success and -1 for error
 */
int _setenv(char *var, char *value)
{
	char *new_var;
	size_t new_var_len;
	char **env = environ;

	if (!var || !value)
		return (-1);
	new_var_len = _strlen(var) + _strlen(value) + 2;
	new_var = malloc(new_var_len * sizeof(char));
	if (!new_var)
		return (-1);
	_strcpy(new_var, var);
	_strcat(new_var, "=");
	_strcat(new_var, value);
	if (get_env(var))
	{
		for (; *env; env++)
		{
			if (_strncmp(*env, var, _strlen(var)) == 0)
			{
				free(*env);
				*env = new_var;
				return (0);
			}
		}
	}
	else
	{
		int result = add_var(new_var);

		if (result == -1)
			return (-1);
	}
	return (0);
}
/**
 * add_var - create new variable new env variable
 * @new_var: new variable to be added
 * Return: 0 success or -1 for failure
*/
int add_var(char *new_var)
{
	char **new_env, **env = environ;
	int i, len;

	len = argv_len(env) + 2;
	new_env = (char **)malloc(len * sizeof(char *));
	if (!new_env)
	{
		free(new_var);
		return (-1);
	}
	for (i = 0; *env; env++, i++)
		new_env[i] = *env;
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	environ = new_env;
	return (0);
}
