/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkeever <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:07:06 by azkeever          #+#    #+#             */
/*   Updated: 2019/09/09 15:00:46 by azkeever         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_string;

	if (!(new_string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(new_string, size + 1);
	ft_putendl("new malloc in ft_strnew");
	return (new_string);
}
