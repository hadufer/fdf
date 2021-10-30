/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 03:49:49 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/03 17:32:55 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uint_length(long nb, int base)
{
	int	count;

	count = 1;
	nb /= base;
	if (nb)
	{
		count++;
		nb /= base;
		while (nb)
		{
			nb /= base;
			count++;
		}
	}
	return (count);
}

static void	output_signed(t_printf *pf, char *ret)
{
	if (pf->padc == '0' && !pf->ladjust)
		while ((--pf->length - (int)ft_strlen(ret)) >= 0)
			ft_putchar_fd(pf->padc, 1);
	else if (pf->prec)
		while ((--pf->prec - (int)ft_strlen(ret)) >= 0)
			ft_putchar_fd('0', 1);
	while (!pf->ladjust && (--pf->length - (int)ft_strlen(ret)) >= 0)
		ft_putchar_fd(' ', 1);
	if (pf->prefix)
		ft_putstr_fd(pf->prefix, 1);
	ft_putstr_fd(ret, 1);
	while (pf->ladjust && (--pf->length - (int)ft_strlen(ret)) >= 0)
		ft_putchar_fd(' ', 1);
}

void	print_unsigned(unsigned long nb, int base, t_printf *pf)
{
	const char	char_list[] = "0123456789abcdef0123456789ABCDEF";
	char		ret[14];
	int			i;

	if (pf->prec == 0 && nb == 0)
		return ;
	if (pf->truncate)
		nb = (unsigned long)((unsigned int)nb);
	i = uint_length(nb, base);
	ret[i--] = 0;
	ret[i--] = char_list[(nb % base) + pf->capitals];
	nb /= base;
	while (nb)
	{
		ret[i--] = char_list[(nb % base) + pf->capitals];
		nb /= base;
	}
	output_signed(pf, ret);
}
