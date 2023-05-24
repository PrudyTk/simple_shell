#include "shell.h"
/**
 * path_concat - concatenates two strings
 * @s1: string parameter
 * @s2: string parameter
 * Return: pointer to a char or NULL
*/
char *path_concat(char *s1, char *s2)
{
	char *p;
	int n, n1, n2;
	int i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	n1 = 0;
	while (s1[n1] != '\0')
		n1++;

	n2 = 0;
	while (s2[n2] != '\0')
		n2++;

	n = n1 + 1 + n2;

	p = malloc((n + 1) * sizeof(char));

	/* if malloc fails, return NULL */
	if (p == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
		p[i] = s1[i];
	p[i] = '/';

	for (j = 0; s2[j] != '\0'; j++)
		p[n1 + 1 + j] = s2[j];

	p[n1 + 1 + j] = '\0';

	return (p);
}
