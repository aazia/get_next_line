#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
/*
**  1 line with 8 chars with Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "gnl1_1.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			ft_putendl("in while loop");
			if (count_lines == 0 && strcmp(line, "1234567") != 0)
			{
				ft_putendl("in if");
				errors++;
			}
			ft_putstr("errors: ");
			ft_putnbr(errors);
			ft_putchar('\n');
			count_lines++;
			if (count_lines > 50)
				break;
		}
		ft_putendl("outside while loop");
		close(fd);
		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"1234567\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
	return (0);
}
