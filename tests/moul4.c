#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../get_next_line.h"

int	main(void)
{
	char 		*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	write(fd, "abc\n\n", 5);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);	
	if (gnl_ret != 1)
		printf("er1\n");
	if (strcmp(line, "abc\n") == 0)
		printf("er1.1, line: %s\n", line);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	if (gnl_ret != 1)
		printf("er");
	if (line == NULL || *line == '\0')
		printf("ok\n");

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	if (gnl_ret != 0)
		printf("er3\n");
	if (line == NULL || *line == '\0')
		printf("ok\n");
	
	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	if (gnl_ret != 0)
		printf("er4, gnl_ret = %d\n", gnl_ret);
	if (line == NULL || *line == '\0')
		printf("ok\n");
}

