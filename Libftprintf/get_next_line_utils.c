/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:40:26 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/04 09:44:35 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strndup(char	*str, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ret)
		return (NULL);
	while (str[i] && i < n)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	clear_curr_lst(t_gnl **curr_lst, char **newbuf)
{
	if (!(*curr_lst)->buf)
	{
		free((*curr_lst)->buf);
		free(*newbuf);
		return (0);
	}
	return (1);
}
