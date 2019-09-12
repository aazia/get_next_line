/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:15:07 by azkeever          #+#    #+#             */
/*   Updated: 2019/09/12 10:57:13 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_checkline(char **str, char **line, int ret)
{
	char	*tmp;
	int		i;

	i = 0;
	if (ret < 0)
		return (-1);
	if (ret == 0 && *str == NULL)
	{
		return (0);
	}
	while ((*str)[i] != '\n' && ((*str)[i] != '\0'))
		i++;
	*line = ft_strsub(*str, 0, i);
	tmp = ft_strdup(&((*str)[i + 1]));
	free(*str);
	*str = ft_strdup(tmp);
	if (ret == 0)
	{
		if (((*str)[i] == '\n') || ((*str)[i] == '\0'\
			&& *line[0] != '\0') || *line[0])
			return (1);
		return (0);
	}
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	static char	*str[1025];
	char		*buffer;
	int			ret;
	char		*tmpstr;

	if (!line || fd < 0 || fd >= 1025 || (read(fd, str[fd], 0) < 0) || \
		!((buffer = ft_strnew(BUFF_SIZE))))
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			tmpstr = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = ft_strdup(tmpstr);
			free(tmpstr);
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ft_checkline(&str[fd], line, ret));
}
