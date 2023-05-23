#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdarg.h>
#include <errno.h>
#define MAX_TOKENS 1024
#define MAX_TOKEN_LENGTH 1024
#define MAX_BUFFER 100

/*the global variables*/
extern char **environ;
int exit_status;

/*the input hanlers */
ssize_t _getline(char **stdin_line, int stm);
char *path_finder(char *tokens, char *s, int count);
char *_getenv(char *name);

/*the output handler*/
void _printf(char *str, int stream);

/* tokenizing the sdtin*/
void tokenization(char *token, char *tokens[]);
int _free_tokens(int token_count, char *tokens[]);
void _fork_exec(char *cmd, char *tokens[], int count, char *av, int i);

/*string functions*/
int _strspn(const char *s, const char *accept);
char *_strdup(char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, const char *src, size_t num);
char *_strchr(char *str, char c);
int _strspn(const char *s, const char *accept);
size_t _strcspn(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
void *_memset(void *destination, int character, size_t number_bytes_memory_to_fill);

/*the concatination string*/
void write_char(char **p, char ch, int *count);
void write_str(char **p, const char *str, int *count);
void write_int(char **p, int num, int *count);
void write_float(char **p, double num, int *count);
int _sprintf(char *str, const char *format, ...);

/*the error handler*/
void _error(char *cmd, char *av, int count);
void _exit_error(char *cmd, char *av, int count, char *status);

/*the memry checks*/
void *_realloc(void *ptr, size_t size);

/*the built in functions*/
void handl_exit(char *str, int status, char *av, int count);
void handleComment(char *string);
void handl_env(void);
void handl_ctrl_d(int n, char *str);

/*the converting functions*/
char *int_to_string(int num);
int toNumber(char *s);

#endif
