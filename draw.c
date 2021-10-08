/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/08 07:15:08 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	draw_vertical_ortho(t_data *d, int i, int j)
{
	t_vec2	v2a;
	t_vec2	v2b;
	t_vec3	v3a;
	t_vec3	v3b;

	if (i < d->mat->h_matrix - 1)
	{
		v3a = new_vec3(j, i, d->mat->matrix[i][j]);
		v3b = new_vec3(j, i + 1, d->mat->matrix[i + 1][j]);
		v3a = new_vec3(v3a.x * d->zoom, v3a.y * d->zoom, v3a.z * d->zoom);
		v3b = new_vec3(v3b.x * d->zoom, v3b.y * d->zoom, v3b.z * d->zoom);
		v2a = new_vec2(v3a.x, v3a.y);
		v2b = new_vec2(v3b.x, v3b.y);
		v2a = new_vec2((v2a.x + d->s_height) / 2, (v2a.y + d->s_height) / 2);
		v2b = new_vec2((v2b.x + d->s_width) / 2, (v2b.y + d->s_height) / 2);
		v2a = new_vec2(v2a.x + d->offset_x, v2a.y + d->offset_y);
		v2b = new_vec2(v2b.x + d->offset_x, v2b.y + d->offset_y);
		draw_line(d, v2a, v2b, create_trgb(0,
				125 - (int)(round(v3a.z / d->draw_max_num) * 255),
				125 - (int)(round(v3a.z / d->draw_max_num) * 255),
				125 - (int)(round(v3a.z / d->draw_max_num) * 255)));
	}
}

static void	draw_horizontal_ortho(t_data *d, int i, int j)
{
	t_vec2	v2a;
	t_vec2	v2b;
	t_vec3	v3a;
	t_vec3	v3b;

	if (j < d->mat->w_matrix - 1)
	{
		v3a = new_vec3(j, i, d->mat->matrix[i][j]);
		v3b = new_vec3(j + 1, i, d->mat->matrix[i][j + 1]);
		v3a = new_vec3(v3a.x * d->zoom, v3a.y * d->zoom, v3a.z * d->zoom);
		v3b = new_vec3(v3b.x * d->zoom, v3b.y * d->zoom, v3b.z * d->zoom);
		v2a = new_vec2(v3a.x, v3a.y);
		v2b = new_vec2(v3b.x, v3b.y);
		v2a = new_vec2((v2a.x + d->s_width) / 2, (v2a.y + d->s_height) / 2);
		v2b = new_vec2((v2b.x + d->s_width) / 2, (v2b.y + d->s_height) / 2);
		v2a = new_vec2(v2a.x + d->offset_x, v2a.y + d->offset_y);
		v2b = new_vec2(v2b.x + d->offset_x, v2b.y + d->offset_y);
		draw_line(d, v2a, v2b, create_trgb(0,
				125 -(int)(round(v3a.z / d->draw_max_num) * 255),
				125 - (int)(round(v3a.z / d->draw_max_num) * 255),
				125 - (int)(round(v3a.z / d->draw_max_num) * 255)));
	}
}

void	draw_ortho(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->mat->h_matrix)
	{
		j = 0;
		while (j < d->mat->w_matrix)
		{
			draw_horizontal_ortho(d, i, j);
			draw_vertical_ortho(d, i, j);
			j++;
		}
		i++;
	}
}

int	matrix_draw(t_data *img)
{
	if (img->iso == 1)
		draw_iso(img);
	else
		draw_ortho(img);
	return (0);
}
