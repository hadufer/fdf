/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:53:30 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 07:46:37 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	horizontal_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int x;
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
			break;
		x += xi;
	}
}

void	vertical_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	int y;
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
			break;
		y += yi;
	}
}

void	brasenham_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
    int dx;
    int sx;
    int dy;
    int sy;
    int err;
	int e2;

	if (a.x < b.x)
		sx = 1;
	else
		sx = -1;
	if (a.y < b.y)
		sy = 1;
	else
		sy = -1;
	dx = abs(b.x - a.x);
	dy = -abs(b.y - a.y);
	err = dx + dy;
    while (1)
    {
		if (a.x > 0 && a.x < data->s_width && a.y > 0 && a.y < data->s_height)
	    	my_mlx_pixel_put(data, a.x, a.y, color);
        if (a.x == b.x && a.y == b.y)
			break;
        e2 = 2*err;
        if (e2 >= dy)
        {
			err += dy;
            a.x += sx;
		}
        if (e2 <= dx)
        {
			err += dx;
            a.y += sy;
		}
	}
}

void    draw_line(t_data *data, t_vec2 a, t_vec2 b, int color)
{
	if (a.x == b.x)
		vertical_line(data, a, b, color);
	else if (a.y == b.y)
		horizontal_line(data, a, b, color);
	else
		brasenham_line(data, a, b, color);
}
