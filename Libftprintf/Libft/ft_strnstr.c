/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:59:17 by hadufer           #+#    #+#             */
/*   Updated: 2021/07/29 19:07:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	tmp_len;
	size_t	s2_len;
	size_t	i;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	tmp_len = len;
	s2_len = ft_strlen(s2);
	while (*(char *)s1 && (tmp_len >= s2_len))
	{
		if (*(char *)s1 == *s2)
		{
			if (ft_strncmp((char *)s2, (char *)s1, s2_len) == 0)
				return ((char *)s1);
		}
		i++;
		tmp_len--;
		(char *)s1++;
	}
	return (NULL);
}
