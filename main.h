#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_PATH 1024

char *read_input();
int tokenize(char *input, char **tokens, int max_tokens);
void execute(char **tokens);
int str_len(char *str);
char *str_cpy(char *dest, char *src);
char *str_dup(char *str);
int str_cmp(const char *s1, const char *s2);
char *str_cat(char *dest, const char *src);
char *_getenv(const char *path);
char **get_path_directories(void);
char *found_function(char *command);
char *get_full_path(char *dir, char *command);
char *_strstr(char *haystack, char *needle);
void writeStringToStderr(char *str);
int _memory1(char *buffer);

#endif
