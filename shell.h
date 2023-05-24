#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <limits.h>

/* prototypes */
char **splitstring(char *buffer);
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
char **tok_path(void);
char *path_concat(char *s1, char *s2);
void printenviron(char **environ, char **command);
int __exit(char **command);
char exec_path(char **command);
int exec_cmd(char **command);
char *_strdup(char *str);
int _atoi(char *s);
int _strlen(char *s);
int print_unsigned_int(unsigned int num, int fd);
void print_error(char *program, char *command, unsigned int line, char *flag);
void _siginterrupt(int __attribute__ ((unused)));

/* structures */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 * Description - signly linked list node structure
*/
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/**
 * struct error_s - error struct
 * @str: string error
 * @mes: error message to be printed
 * Description - struct
*/
typedef struct error_s
{
	char *str;
	char *mes;
} error_t;

/* global variables */
extern char **environ;
