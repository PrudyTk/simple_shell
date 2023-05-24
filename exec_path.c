#include "shell.h"
/**
 * exec_path - executes arguments concatenated to path directory
 * @command: array of arguments
 * Return: the directory with argument
*/
char exec_path(char **command)
{
	int i, j, status, error;
	char *full_path;
	char **path_array;
	pid_t child;

	path_array = tok_path();
	for (i = 0; path_array[i] != NULL; i++)
	{
		full_path = path_concat(path_array[i], command[0]);
		if (access(full_path, X_OK) == 0)
		{
			child = fork();
			if (child == 0)
			{
				error = execve(full_path, command, NULL);
				if (error == -1)
				{
					perror("Error:");
					exit(91);
				}
				free(path_array[i]);
				free(path_array);
				free(full_path);
			}
			wait(&status);
			for (j = 0; path_array[j] != NULL; j++)
				free(path_array[j]);
			free(path_array[j]);
			free(path_array);
			free(full_path);
			return (0);
		}
		else
			free(full_path);
	}
	for (j = 0; path_array[j] != NULL; j++)
		free(path_array[j]);
	free(path_array[j]);
	free(path_array);
	return (1);
}
