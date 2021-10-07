/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 12:52:34 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	draw_vertical_ortho(t_data *data, int i, int j)
{
	t_vec2	vec2_a;
	t_vec2	vec2_b;
	t_vec3	vec_base_a;
	t_vec3	vec_base_b;
	if (i < data->mat->h_matrix - 1)
	{
		// INIT
		vec_base_a = new_vec3(j, i, data->mat->matrix[i][j]);
		vec_base_b = new_vec3(j, i + 1, data->mat->matrix[i + 1][j]);
		//ZOOM
		vec_base_a = new_vec3(vec_base_a.x * data->zoom, vec_base_a.y * data->zoom, vec_base_a.z * data->zoom);
		vec_base_b = new_vec3(vec_base_b.x * data->zoom, vec_base_b.y * data->zoom, vec_base_b.z * data->zoom);
		//PARALLEL
		vec2_a = new_vec2(vec_base_a.x, vec_base_a.y);
		vec2_b = new_vec2(vec_base_b.x, vec_base_b.y);
		//CENTER
		vec2_a = new_vec2((vec2_a.x + data->s_height) / 2, (vec2_a.y + data->s_height) / 2);
		vec2_b = new_vec2((vec2_b.x + data->s_width) / 2, (vec2_b.y + data->s_height) / 2);
		//OFFSET
		vec2_a = new_vec2(vec2_a.x + data->offset_x, vec2_a.y + data->offset_y);
		vec2_b = new_vec2(vec2_b.x + data->offset_x, vec2_b.y + data->offset_y);
		draw_line(data, vec2_a, vec2_b, create_trgb(0, 125 - (int)(round(vec_base_a.z/data->draw_max_num) * 255), 125 - (int)(round(vec_base_a.z/data->draw_max_num)* 255), 125 - (int)(round(vec_base_a.z/data->draw_max_num)* 255)));
	}
}

static void	draw_horizontal_ortho(t_data *data, int i, int j)
{
	t_vec2	vec2_a;
	t_vec2	vec2_b;
	t_vec3	vec_base_a;
	t_vec3	vec_base_b;

	if (j < data->mat->w_matrix - 1)
	{
		//INIT
		vec_base_a = new_vec3(j, i, data->mat->matrix[i][j]);
		vec_base_b = new_vec3(j + 1, i, data->mat->matrix[i][j + 1]);
		//ZOOM
		vec_base_a = new_vec3(vec_base_a.x * data->zoom, vec_base_a.y * data->zoom, vec_base_a.z * data->zoom);
		vec_base_b = new_vec3(vec_base_b.x * data->zoom, vec_base_b.y * data->zoom, vec_base_b.z * data->zoom);
		//PARALLEL
		vec2_a = new_vec2(vec_base_a.x, vec_base_a.y);
		vec2_b = new_vec2(vec_base_b.x, vec_base_b.y);
		//CENTER
		vec2_a = new_vec2((vec2_a.x + data->s_width) / 2, (vec2_a.y + data->s_height) / 2);
		vec2_b = new_vec2((vec2_b.x + data->s_width) / 2, (vec2_b.y + data->s_height) / 2);
		//OFFSET
		vec2_a = new_vec2(vec2_a.x + data->offset_x, vec2_a.y + data->offset_y);
		vec2_b = new_vec2(vec2_b.x + data->offset_x, vec2_b.y + data->offset_y);
		draw_line(data, vec2_a, vec2_b, create_trgb(0, 125 -(int)(round(vec_base_a.z/data->draw_max_num) * 255), 125 -(int)(round(vec_base_a.z/data->draw_max_num)* 255), 125 -(int)(round(vec_base_a.z/data->draw_max_num)* 255)));
	}
}

void	draw_ortho(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->mat->h_matrix)
	{
		j = 0;
		while (j < data->mat->w_matrix)
		{
			draw_horizontal_ortho(data, i, j);
			draw_vertical_ortho(data, i, j);
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
