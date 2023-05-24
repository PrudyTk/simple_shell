#include "shell.h"
/**
 * exec_cmd - executes tokenized commands
 * @command: array of arguments
 * Return: 1 on success amd -1 on failure
*/
int exec_cmd(char **command)
{
	int status, error;
	pid_t child;

	/* program is present */
	/* fork program */
	child = fork();
	if (child == 0)
	{
		/* execute the command in child */
		error = execve(command[0], command, NULL);
		if (error == -1)
		{
			perror("Error:");
			return (error);
		}
		else
			return (1);
	}
	wait(&status);

	return (1);
}
