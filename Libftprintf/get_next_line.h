/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 15:40:40 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/24 00:50:22 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stddef.h>
typedef struct s_gnl
{
	char			*buf;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strndup(char	*str, size_t n);
int		clear_curr_lst(t_gnl **curr_lst, char **newbuf);
#endif
