/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:35:11 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/24 00:54:32 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static t_gnl	*gnl_lstnew(int fd, char *buf)
{
	t_gnl	*lst;

	lst = malloc(sizeof(t_gnl));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	lst->buf = buf;
	lst->next = NULL;
	return (lst);
}

static t_gnl	*gnl_lstfind(t_gnl *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static void	gnl_addback(t_gnl *lst, t_gnl *new)
{
	while (lst && lst->next)
		lst = lst->next;
	lst->next = new;
}

int	get_next_line_util(t_gnl **lst, t_gnl **curr_lst, int fd, char **newbuf)
{
	if (!*lst)
		*lst = gnl_lstnew(fd, NULL);
	else if (!gnl_lstfind(*lst, fd))
		gnl_addback(*lst, gnl_lstnew(fd, NULL));
	*curr_lst = gnl_lstfind(*lst, fd);
	if (!(*curr_lst)->buf)
	{
		(*curr_lst)->buf = malloc(sizeof(char) * BUFFER_SIZE);
		if (!(*curr_lst)->buf)
			return (0);
	}
	else
	{
		*newbuf = (*curr_lst)->buf;
		(*curr_lst)->buf = ft_strchr((*curr_lst)->buf, '\n');
		if (!(*curr_lst)->buf)
			return (0);
		(*curr_lst)->buf = \
		ft_strndup((*curr_lst)->buf + 1, ft_strlen((*curr_lst)->buf));
		if (!clear_curr_lst(curr_lst, newbuf))
			return (0);
		free(*newbuf);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst;
	t_gnl			*curr_lst;
	char			*buff[2];
	int				i;

	curr_lst = NULL;
	if (!get_next_line_util(&lst, &curr_lst, fd, &buff[0]))
		return (NULL);
	buff[0] = malloc(sizeof(char) * BUFFER_SIZE);
	i = 0;
	while (i <= BUFFER_SIZE)
		*(buff[0] + i++) = (unsigned char)0;
	if (!buff[0])
		return (NULL);
	while (!ft_strchr(curr_lst->buf, '\n') && read(fd, buff[0], BUFFER_SIZE) > 0)
	{
		buff[1] = curr_lst->buf;
		curr_lst->buf = ft_strjoin(curr_lst->buf, buff[0]);
		free(buff[1]);
	}
	free(buff[0]);
	if (!ft_strchr(curr_lst->buf, '\n'))
		return (curr_lst->buf);
	return (ft_strndup(curr_lst->buf, \
	ft_strlen(curr_lst->buf) - ft_strlen(ft_strchr(curr_lst->buf, '\n') + 1)));
}
