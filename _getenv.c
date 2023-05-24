#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @name: name of the variable
 * Return: the value of the variable
*/
char *_getenv(const char *name)
{
	unsigned int i, j;

	/* Loop through the environment string */
	i = 0;
	while (environ[i] != NULL)
	{
		/* While environ[i][j] matches name[j] */
		j = 0;

		while (environ[i][j] == name[j] && name[j] != '\0')
			j++;

		if (environ[i][j] == '=' && name[j] == '\0')
		{
			/* return the address of environ[i][j + 1] */
			return (&environ[i][j + 1]);
		}

		i++;
	}

	/* Otherwise, return NULL */
	return (NULL);
}
