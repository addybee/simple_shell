#include "main.h"
/**
 * check_exit - Check and handle the 'exit' command.
 * @command: The command passed in as input.
 */
void check_exit(char **argv)
{
	int p, staat;
	char *ptr = "exit";

	if (argv_len(argv) == 1)
	{
		p = strcmp(ptr, argv[0]);
		if (p != 0)
			return;
		free_argv(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (strcmp(ptr, argv[0]) != 0)
				return;
		str_strip(argv[1]);
		staat = _atoi(argv[1]);
		if (staat == -1)
		{
			write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
			write(STDERR_FILENO, argv[1], _strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);
			free_argv(argv);
			exit(2);
		}
	}
	free_argv(argv);
	exit(staat);
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
