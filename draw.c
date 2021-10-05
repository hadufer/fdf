/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/05 18:36:36 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	matrix_draw(t_data *data, t_matrix *mat)
{
	int		i;
	int		j;
	t_vec2	vec2_a;
	t_vec2	vec2_b;
	t_vec3	vec_base_a;
	t_vec3	vec_base_b;

	i = 0;
	while (i < mat->h_matrix)
	{
		j = 0;
		while (j < mat->w_matrix)
		{
			if (i < mat->h_matrix - 1)
			{
				// INIT
				vec_base_a = new_vec3(j, i, mat->matrix[i][j]);
				vec_base_b = new_vec3(j, i + 1, mat->matrix[i + 1][j]);
				//ZOOM
				vec_base_a = new_vec3(vec_base_a.x * FACTOR, vec_base_a.y * FACTOR, vec_base_a.z);
				vec_base_b = new_vec3(vec_base_b.x * FACTOR, vec_base_b.y * FACTOR, vec_base_b.z);
				//ISO
				vec2_a = new_vec2((vec_base_a.x - vec_base_a.y) * cos(ANGLE), (vec_base_a.x + vec_base_a.y) * sin(ANGLE) - vec_base_a.z);
				vec2_b = new_vec2((vec_base_b.x - vec_base_b.y) * cos(ANGLE), (vec_base_b.x + vec_base_b.y) * sin(ANGLE) - vec_base_b.z);
				//CENTER
				vec2_a = new_vec2((vec2_a.x + WIDTH) / 2 , (vec2_a.y + HEIGHT)  / 2 );
				vec2_b = new_vec2((vec2_b.x + WIDTH) / 2 , (vec2_b.y + HEIGHT)  / 2 );
				draw_line(data, vec2_a, vec2_b, 0xFF0000);
			}
			if (j < mat->w_matrix - 1)
			{
				//INIT
				vec_base_a = new_vec3(j, i, mat->matrix[i][j]);
				vec_base_b = new_vec3(j + 1, i, mat->matrix[i][j + 1]);
				//ZOOM
				vec_base_a = new_vec3(vec_base_a.x * FACTOR, vec_base_a.y * FACTOR, vec_base_a.z);
				vec_base_b = new_vec3(vec_base_b.x * FACTOR, vec_base_b.y * FACTOR, vec_base_b.z);
				//ISO
				vec2_a = new_vec2((vec_base_a.x - vec_base_a.y) * cos(ANGLE), (vec_base_a.x + vec_base_a.y) * sin(ANGLE) - vec_base_a.z);
				vec2_b = new_vec2((vec_base_b.x - vec_base_b.y) * cos(ANGLE), (vec_base_b.x + vec_base_b.y) * sin(ANGLE) - vec_base_b.z);
				//CENTER
				vec2_a = new_vec2((vec2_a.x + WIDTH) / 2 , (vec2_a.y + HEIGHT)  / 2 );
				vec2_b = new_vec2((vec2_b.x + WIDTH) / 2 , (vec2_b.y + HEIGHT)  / 2 );
				draw_line(data, vec2_a, vec2_b, 0x00FF00);
			}
			j++;
		}
		i++;
	}
	return (0);
}

