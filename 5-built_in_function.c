#include "main.h"
/**
 * check_exit - Check and handle the 'exit' command.
 * @command: The command passed in as input.
 */
void check_exit(char *command)
{
	int p;

	p = strcmp("exit", command);
	if (p == 0)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}
}

/**
 * check_env - check and handle 'env' command by print the environment variable
 * @command: is the command from terminal
 * Return: 1 success 0 otherwise
 */
int check_env(char *command)
{
	if (_strcmp(command, "env") == 0)
	{
		unsigned int i;
		char **env = environ;

		i = 0;
		while (env[i] != NULL)
		{
			write(STDOUT_FILENO, env[i], _strlen(env[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}
	return (0);
}
