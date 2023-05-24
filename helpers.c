#include "shell.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: difference of bytes between the strings, otherwise 0
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string parameter
 * Return: pointer to a char or NULL
*/
char *_strdup(char *str)
{
	char *p;
	int n = 0;
	int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[n] != '\0')
		n++;

	p = malloc((n + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);

	while (i <= n)
	{
		p[i] = str[i];
		i++;
	}

	return (p);
}
/**
 * is_digit - checks if character is a digit.
 * @c: character argument
 * Return: returns 1 success, 0 otherwise
*/
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/**
 * _atoi - converts a string to an integer
 * @s: string argument
 * Return: the converted int, 0 otherwise
*/

int _atoi(char *s)
{
	unsigned int n = 0;
	int i = 0, sign = 1;

	/* count number of negative signs */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (is_digit(s[i]))
			break;
		i++;
	}

	if (s[i] == '\0')
		return (n);

	while (is_digit(s[i]))
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}

	return (n  * sign);
}
/**
 * _strlen - returns length of a string
 * @str: string argument
 * Return: length of string
*/
int _strlen(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}
