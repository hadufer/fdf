/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:19:57 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/04 17:36:44 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	matrix_draw(t_data *data, t_matrix *mat)
{
	int		i;
	int		j;
	t_vec2	vec_iso1;
	t_vec2	vec_iso2;

	i = 0;
	while (i < mat->h_matrix)
	{
		j = 0;
		while (j < mat->w_matrix)
		{
			if (i != 0)
			{
				vec_iso1 = new_vec2(((j + i - 1) * FACTOR) * cos(0.8), ((j + i) * FACTOR) * sin(0.8) - mat->matrix[i][j]);
				vec_iso2 = new_vec2(((j + i) * FACTOR) * cos(0.8), ((j + i) * FACTOR) * sin(0.8) - mat->matrix[i][j]);
				vec_iso1 = new_vec2((vec_iso1.x + WIDTH) / 2 , (vec_iso1.y + HEIGHT ) / 2 );
				vec_iso2 = new_vec2((vec_iso2.x + WIDTH) / 2 , (vec_iso2.y + HEIGHT ) / 2 );
				draw_line(data, vec_iso1, vec_iso2, 0x00FF00);
			}
			if (j < mat->w_matrix)
			{
				vec_iso1 = new_vec2(((j - i) * FACTOR) * cos(0.8), ((j + i) * FACTOR) * sin(0.8) - mat->matrix[i][j]);
				vec_iso2 = new_vec2(((j - i) * FACTOR) * cos(0.8), ((j + i + 1) * FACTOR) * sin(0.8) - mat->matrix[i][j]);
				vec_iso1 = new_vec2((vec_iso1.x + WIDTH) / 2, (vec_iso1.y + HEIGHT) / 2 );
				vec_iso2 = new_vec2((vec_iso2.x + WIDTH) / 2, (vec_iso2.y + HEIGHT) / 2 );
				draw_line(data, vec_iso1, vec_iso2, 0x00FF00);
			}
			j++;
		}
		i++;
	}
	return (0);
}
