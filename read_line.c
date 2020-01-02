#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

/**
 *read_textfile - program that reads a file
 *@filename: The character to print
 *@letters: number of letters it prints
 *Return: On success 1.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd;
	char *buff;
	ssize_t fd_write, n_bytes;

	if (filename == NULL)
	{
		return (0);
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			return (0);
		}
	}
	buff = malloc(sizeof(size_t) * letters);
	if (buff == NULL)
	{
		return (0);
	}
	n_bytes = read(fd, buff, letters);
	if (n_bytes == -1)
	{
		free(buff);
		return (0);
	}
	else
	{
		fd_write = write(STDOUT_FILENO, buff, n_bytes);
		if (fd_write == -1)
		{
			free(buff);
			return (0);
		}
	}
	close(fd);
	return ();


/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	frase = read_textfile(av[1]);
	tokenizar = strtok(frase);


}
