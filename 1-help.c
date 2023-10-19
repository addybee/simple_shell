#include "main.h"
/**
 * exec_cmd - this executes the given command if available
 * @argv: argument vector
 * Return: nothing
*/
void exec_cmd(char **argv)
{
	char **env = environ;
	pid_t pid = 0;
	int wstatus;

	if (!argv)
		return;
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		char *cmd;

		cmd = handle_path(argv[0]);
		if (cmd == NULL)
		{
			char *sh = "./hsh: 1: ", *rt = ": not found\n";

			write(STDERR_FILENO, sh, _strlen(sh));
			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, rt, _strlen(rt));
			free_argv(argv);
			exit(127);
		}
		if (execve(cmd, argv, env) == -1)
		{
			perror("./hsh");
		}
	}
	if (wait(&wstatus) == -1)
	{
		perror("wait");
		free_argv(argv);
		exit(EXIT_FAILURE);
	}
	free_argv(argv);
}

/**
 * get_argv - convert the string from input to array of string
 * @command: pointer to the string from input.
 * Return: array to strings of the converted input string when successful
 * NULL when failed
 */
char **get_argv(char *command)
{
	char *command_dup = NULL, *command_tok = NULL, *str = NULL;
	char **argv = NULL;
	int i = 0;

	if (command == NULL)
		return (NULL);
	command_dup = _strdup(command);
	for (i = 1, str = command_dup; ; i++, str = NULL)
	{
		command_tok = _strtok(str, " ");
		if (!command_tok)
			break;
	}
	free(command_dup);
	argv = malloc(sizeof(char *) * i);
	if (argv == NULL)
		return (NULL);
	for (i = 0, str = command; ; str = NULL, i++)
	{
		command_tok = _strtok(str, " ");
		if (!command_tok)
		{
			argv[i] = command_tok;
			break;
		}
		argv[i] = malloc((1 + _strlen(command_tok)) * sizeof(char));
		if (argv[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(argv[i]);
				i--;
			}
			free(argv);
			return (NULL);
		}
		_strcpy(argv[i], command_tok);
	}
	return (argv);
}

/**
 * handle_path - check if command exist or if path needs to be added
 * @command: command whose path is to be found if it exist
 * Return: pointer to the pathname
*/
char *handle_path(char *command)
{
	char *path_var, *dup_path_var, *path_var_tok, *path;
	struct stat det;

	if (stat(command, &det) == 0)
	{
		if (access(command, F_OK) == 0)
			return (command);
		return (NULL);
	}
	path_var = get_env("PATH");
	dup_path_var = _strdup(path_var);
	path_var_tok = _strtok(dup_path_var, ":");
	while (path_var_tok != NULL)
	{
		int path_len = (_strlen(command) + _strlen(path_var_tok) + 2);

		path = malloc(path_len * sizeof(char));
		if (!path)
		{
			free(dup_path_var);
			return (NULL);
		}
		_strcpy(path, path_var_tok);
		_strcat(path, "/");
		_strcat(path, command);
		if (stat(path, &det) == 0)
		{
			free(dup_path_var);
			if (access(path, F_OK) == 0)
				return (path);
			return (NULL);
		}
		free(path);
		path_var_tok = _strtok(NULL, ":");
	}
	free(dup_path_var);
	return (NULL);
}

/**
 * parse_cmd - expands input command to its function
 * @vp: array of input command and its arguement
 * @res: holds the result of the output func
 */
void parse_cmd(char **argv, int *res)
{
	int k;
	bc cmd_s[4] = {
	{"exit", check_exit},
	{"setenv", check_set},
	{NULL, NULL}
	};

	for (k = 0; cmd_s[k].cmd; k++)
	{
		if (_strcmp(argv[0], cmd_s[k].cmd) == 0)
		{
			*res = cmd_s[k].f(argv);
			break;
		}
	}
	*res = 0;
}

