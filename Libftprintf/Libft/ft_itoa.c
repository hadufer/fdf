/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 18:22:09 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/04 19:28:44 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		ret[0] = '-';
		ret[1] = 0;
		ret = ft_strjoin(ret, ft_itoa(-n));
	}
	else if (n >= 10)
		ret = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	else if (n < 10)
	{
		ret[0] = (n % 10) + 48;
		ret[1] = 0;
	}
	return (ret);
}
