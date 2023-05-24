#include "shell.h"
/**
 * tok_path - stores each directory from path into an array
 *
 * Return: address of the array
*/
char **tok_path(void)
{
	char *path, *path_cpy, *token;
	char **path_array;
	int token_c = 0;

	/* Initialize */
	path = _strdup(_getenv("PATH"));
	path_cpy = _strdup(path);

	/* Find memory size for array */
	token = strtok(path_cpy, ":");
	while (token)
	{
		token = strtok(NULL, ":");
		token_c++;
	}

	/* Allocate memory for array */
	path_array = malloc(sizeof(char *) * (token_c + 1));

	if (path_array == NULL)
		return (NULL);

	/* Create tokens */
	token_c = 0;
	token = strtok(path, ":");
	while (token)
	{
		++token_c;
		path_array[token_c - 1] = _strdup(token);
		token = strtok(NULL, ":");
	}
	path_array[token_c] = NULL;
	free(path);
	free(path_cpy);
	return (path_array);
}
