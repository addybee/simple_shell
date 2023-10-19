#include "main.h"
/**
 * run_shell - UNIX command line interpreter
 * @argv: array of string
 * Return: 1 when successful and 0 when failed
 */
int run_shell(char **argv)
{
	char *input_line = NULL;
	size_t input_len = 0;
	ssize_t read_char = 0;
	int res = 0;

	while (1)
	{
		print_prompt();
		read_char = getline(&input_line, &input_len, stdin);
		if (read_char == -1)
		{
			if (input_line)
				free(input_line);
			return (0);
		}
		str_strip(input_line);
		if (*input_line == '\0')
		{
			free(input_line);
			input_line = NULL;
			continue;
		}
		if (check_env(input_line))
			continue;
		argv = get_argv(input_line);
		if (!argv)
		{
			perror("get_argv");
			free(input_line);
			input_line = NULL;
			continue;
		}
		free(input_line);
		input_line = NULL;
		parse_cmd(argv, &res);
		if (res)
			continue;
		exec_cmd(argv);
	}
	return (1);
}

/**
 * print_prompt - print the prompt of the shell program
 * Return: void
 */
void print_prompt(void)
{
	char *prompt;

	if (isatty(0))
	{
		prompt = "$ ";
		write(1, prompt, _strlen(prompt));
	}
}

/**
 * free_argv - free the allocated memory for arguements
 * @argv: pointer to array of the arguement
 * Return: void
 */
void free_argv(char **argv)
{
	int i = 0;

	if (!argv)
		return;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

/**
 * argv_len - gets the length of an array
 * @argv: pointer to array of the arguement
 * Return: length of element in the array
 */

int argv_len(char **argv)
{
	int i = 0;

	while (argv[i])
	i++;
	return (i);
}
