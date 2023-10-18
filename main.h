#ifndef MAIN_H
#define MAIN_H
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <ctype.h>
extern char **environ;
void print_prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *handle_path(char *command);
void exec_cmd(char **argv);
char **get_argv(char *command);
int  run_shell(char **argv);
void free_argv(char **argv);
int check_env(char *command);
void check_exit(char **cmd);
void str_strip(char *s);
char *get_env(char *name);
char *_strcpy(char *dest, char *src);
size_t _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _atoi(char *s);
char *_strchr(char *s, char c);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, size_t n);
size_t _strcspn(char *s, const char *reject);
size_t _strspn(char *s, const char *accept);
char *_strtok(char * str, const char *delim);
int argv_len(char **argv);
#endif
