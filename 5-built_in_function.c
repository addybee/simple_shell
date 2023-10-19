#include "main.h"
/**
 * check_exit - Check and handle the 'exit' command.
 * @argv: The command passed in as input.
 * Return: 0 when failed
 */
int check_exit(char **argv)
{
	int staat;

	if (argv_len(argv) == 1)
	{
		free_argv(argv);
		exit(EXIT_SUCCESS);
	}
	else
	{
		str_strip(argv[1]);
		staat = _atoi(argv[1]);
		if (staat != -1)
		{
			free_argv(argv);
			exit(staat);
		}
	}
	write(STDERR_FILENO, "./hsh: 1: exit: Illegal number: ", 32);
	write(STDERR_FILENO, argv[1], _strlen(argv[1]));
	write(STDERR_FILENO, "\n", 1);
	free_argv(argv);
	return (0);
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

/**
 * check_set - Check and handle the 'setenv' command.
 * @argv: The command passed in as input.
 * Return: 1 on success and 0 on failure
 */
int check_set(char **argv)
{
	if (argv_len(argv) == 3)
	{
		if (_setenv(argv[1], argv[2]) == 0)
		{	free_argv(argv);
			return (1);
		}
	}
	write(STDERR_FILENO, "./hsh: 1: setenv: Error setting:", 32);
	write(STDERR_FILENO, "\n", 1);
	free_argv(argv);
	return (0);
}
