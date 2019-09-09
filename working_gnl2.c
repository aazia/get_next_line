#include "get_next_line.h"

int	ft_checkline(char **str, char **line, int ret)
{
	char 	*tmp;
	int	i;


	// option a: is last line
	// option b: is not last line

	// case 1: str is empty
	// case 2: str contains a \n with characters on either side => 2 lines
	// case 3: str contains a \n and no characters after it => exactly 1 line



	i = 0;
//	printf("\n\nstr in checkline : XXX%sXXX, ret : %d\n\n", *str, ret);



	if (ret < 0)
		return (-1);

	if (ret == 0) {
		// last line...

		// case 1, 2 or 3
		// case 1
		if (*str == NULL) return 0;
		// case 2
		while ((*str)[i] != '\n' && ((*str)[i] != '\0')) {
			i++;	
		}

		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = ft_strdup(tmp);
		
		if (((*str)[i] == '\n') || ((*str)[i] == '\0' && *line[0] != '\0'))
		{
			return (1);
		}
	//	if ((*str)[i] == '\0' && *line[0] != '\0') {
	//		return (1);
	//	}
		return (0);
		}
	if (ret > 0) {
		while ((*str)[i] != '\n' && ((*str)[i] != '\0')) {
			i++;	
		}

		*line = ft_strsub(*str, 0, i);
		tmp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = ft_strdup(tmp);
		// case 1 2 or 3
//		printf("\nret > 0: new line : XXX%sXXX, str[fd] : XXX%sXXXX\n", *line, *str);
		return (1);
	}
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*buffer;
	int		nbread;
	char		*tmpstr;
	if (!line || fd < 0 || fd >= 1025 || (read(fd, str[fd], 0) < 0) || \
		!((buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	while ((nbread = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[nbread] = '\0';

		if (str[fd] == NULL)
		{
		//	printf("\n\nstrdup buffer\n\n");
			str[fd] = ft_strdup(buffer);	
		}
		else
		{
			tmpstr = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(tmpstr);
		}
		if (ft_strchr(str[fd], '\n'))
			break;
	}
	return (ft_checkline(&str[fd], line, nbread));
}
