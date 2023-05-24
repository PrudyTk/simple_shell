#include "shell.h"
/**
 * print_unsigned_int - prints a number to stderr
 * @num: numbers
 * @fd: file descriptor
 * Return: number of character(s) are printed
*/
int print_unsigned_int(unsigned int num, int fd)
{
	unsigned int max_digit_int = 1000000000;
	int temp_num = 0;
	int count = 0;
	char c;

	if (num == 0)
	{
		c = '0';
		write(fd, &c, 1);
		return (1);
	}

	while (num / max_digit_int == 0)
		max_digit_int /= 10;

	while (max_digit_int > 0)
	{
		temp_num = num / max_digit_int;
		num = num % max_digit_int;
		c = temp_num + '0';
		write(fd, &c, 1);
		count++;
		max_digit_int /= 10;
	}
	return (count);
}
