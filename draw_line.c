/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:53:30 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/08 06:57:09 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	horizontal_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int	x;
	int	xi;

	x = a.x;
	if (a.x < b.x)
		xi = 1;
	else
		xi = -1;
	while (1)
	{
		if (a.y > 0 && a.y < data->s_height && x > 0 && x < data->s_width)
			my_mlx_pixel_put(data, x, a.y, color);
		if (x == b.x)
			break ;
		x += xi;
	}
}

void	vertical_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int	y;
	int	yi;

	y = a.y;
	if (a.y < b.y)
		yi = 1;
	else
		yi = -1;
	while (1)
	{
		if (a.x > 0 && a.x < data->s_width && y > 0 && y < data->s_height)
			my_mlx_pixel_put(data, a.x, y, color);
		if (y == b.y)
			break ;
		y += yi;
	}
}

static void	brasenham_init_iterators(t_vec2 a, t_vec2 b, int *sx, int *sy)
{
	if (a.x < b.x)
		*sx = 1;
	else
		*sx = -1;
	if (a.y < b.y)
		*sy = 1;
	else
		*sy = -1;
}

void	brasenham_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int	tab[6];

	brasenham_init_iterators(a, b, &tab[1], &tab[3]);
	tab[0] = abs(b.x - a.x);
	tab[2] = -abs(b.y - a.y);
	tab[4] = tab[0] + tab[2];
	while (1)
	{
		if (a.x > 0 && a.x < data->s_width && a.y > 0 && a.y < data->s_height)
			my_mlx_pixel_put(data, a.x, a.y, color);
		if (a.x == b.x && a.y == b.y)
			break ;
		tab[5] = 2 * tab[4];
		if (tab[5] >= tab[2])
		{
			tab[4] += tab[2];
			a.x += tab[1];
		}
		if (tab[5] <= tab[0])
		{
			tab[4] += tab[0];
			a.y += tab[3];
		}
	}
}

void	draw_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	if (a.x == b.x)
		vertical_line(data, a, b, color);
	else if (a.y == b.y)
		horizontal_line(data, a, b, color);
	else
		brasenham_line(data, a, b, color);
}
