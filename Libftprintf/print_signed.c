/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:43:59 by hadufer           #+#    #+#             */
/*   Updated: 2021/09/03 17:16:18 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_length(long nb, int base, t_printf *pf)
{
	int	count;

	count = 1;
	nb /= base;
	if (pf->plus_sign || nb < 0)
		pf->length--;
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

static void	output_signed(int sign_char, t_printf *pf, char *ret)
{
	if (sign_char == '-')
		ft_putchar_fd('-', 1);
	else if (pf->plus_sign == '+' || pf->plus_sign == ' ')
		ft_putchar_fd(pf->plus_sign, 1);
	if (pf->padc == '0' && !pf->ladjust)
		while ((--pf->length - (int)ft_strlen(ret)) >= 0)
			ft_putchar_fd(pf->padc, 1);
	else if (pf->prec)
		while ((--pf->prec - (int)ft_strlen(ret)) >= 0)
			ft_putchar_fd('0', 1);
	while (!pf->ladjust && (--pf->length - (int)ft_strlen(ret)) >= 0)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(ret, 1);
	while (pf->ladjust && (--pf->length - (int)ft_strlen(ret)) >= 0)
		ft_putchar_fd(' ', 1);
}

void	print_signed(long nb, int base, t_printf *pf)
{
	const char	char_list[] = "0123456789abcdef0123456789ABCDEF";
	char		ret[14];
	int			i;
	int			sign_char;

	if (pf->prec == 0 && nb == 0)
		return ;
	if (pf->truncate)
		nb = (long)((int)nb);
	i = int_length(nb, base, pf);
	if (nb < 0)
	{
		sign_char = '-';
		nb = -nb;
	}
	ret[i--] = 0;
	ret[i--] = char_list[(nb % base) + pf->capitals];
	nb /= base;
	while (nb)
	{
		ret[i--] = char_list[(nb % base) + pf->capitals];
		nb /= base;
	}
	output_signed(sign_char, pf, ret);
}
