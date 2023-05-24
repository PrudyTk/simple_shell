#include "shell.h"
/**
 * print_error - prints error message contingent on invalid commands
 * @program: shell name
 * @command: command input
 * @line: iteration count of error
 * @flag: type of error
 * Return: none
*/
void print_error(char *program, char *command, unsigned int line, char *flag)
{
	int i = 0;
	error_t errors[] = {
		{ "perm", ": Permission denied\n"},
		{ "nf", ": not found\n"}
	};

	write(STDERR_FILENO, program, _strlen(program));
	write(STDERR_FILENO, ": ", 2);
	print_unsigned_int(line, 2);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));

	while (i < 2)
	{
		if (_strcmp(flag, errors[i].str) == 0)
		{
			write(STDERR_FILENO, errors[i].mes, _strlen(errors[i].mes));
			break;
		}
		else
			i++;
	}

}
