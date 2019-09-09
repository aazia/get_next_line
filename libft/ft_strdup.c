/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:38:51 by azkeever          #+#    #+#             */
/*   Updated: 2019/09/09 14:59:51 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;

	len = 0;
	while (s1[len])
		++len;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
		while (len >= 0)
		{
			str[len] = s1[len];
			len--;
		}
	else
		return (NULL);
	ft_putendl("malloc in ft_strdup");
	return (str);
}
