#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"

/*
** 1 line with 8 chars without Line Feed
*/

int				main(void)
{
	char		*line;
	int			fd;
	int			ret;
	int			count_lines;
	char		*filename;
	int			errors;

	filename = "tests/tt.txt";
	fd = open(filename, O_RDONLY);
	if (fd > 2)
	{
		count_lines = 0;
		errors = 0;
		line = NULL;
		while ((ret = get_next_line(fd, &line)) > 0)
		{	
		printf("\nline: %s, ret: %d\n", line, ret);
			count_lines++;
		}
		close(fd);
		printf("finished ret: %d\n", ret);
	}		
/*		if (count_lines != 1)
			printf("-> must have returned '1' once instead of %d time(s)\n", count_lines);
		if (errors > 0)
			printf("-> must have read \"12345678\" instead of \"%s\"\n", line);
		if (count_lines == 1 && errors == 0)
			printf("OK\n");
	}
	else
		printf("An error occured while opening file %s\n", filename);
*/
	return (0);
}
