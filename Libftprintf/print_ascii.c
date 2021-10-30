/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:07:01 by hadufer           #+#    #+#             */
/*   Updated: 2021/08/24 21:11:55 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int c, t_printf *pf)
{
	while (!pf->ladjust && (--pf->length - 1) >= 0)
		ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	while (pf->ladjust && (--pf->length - 1) >= 0)
		ft_putchar_fd(' ', 1);
}

void	print_string(char *str, t_printf *pf)
{
	while (!pf->ladjust && (--pf->length - (int)ft_strlen(str)) >= 0)
		ft_putchar_fd(' ', 1);
	ft_putstr_fd(str, 1);
	while (pf->ladjust && (--pf->length - (int)ft_strlen(str)) >= 0)
		ft_putchar_fd(' ', 1);
}
