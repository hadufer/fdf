/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:13:48 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 08:29:00 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

static void	key_handle_transform(int keycode, t_data *img)
{
	if (keycode == KEY_PLUS)
		img->zoom += 1;
	else if (keycode == KEY_LEFT)
		img->offset_x -= 1;
	else if (keycode == KEY_RIGHT)
		img->offset_x += 1;
	else if (keycode == KEY_DOWN)
		img->offset_y += 1;
	else if (keycode == KEY_UP)
		img->offset_y -= 1;
	else if (keycode == KEY_1)
		img->iso ^= 0x1;
}

int	key_handle(int keycode, t_data *img)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(img->mlx, img->win);
		matrix_destroy(img->mat);
		exit(0);
	}
	else if (keycode == KEY_MINUS)
	{
		if (img->zoom <= 1)
			img->zoom = 1;
		else
			img->zoom -= 1;
	}
	else
		key_handle_transform(keycode, img);
	return (0);
}
