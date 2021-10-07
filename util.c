/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:24:48 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 09:10:20 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3 out;

	out.x = x;
	out.y = y;
	out.z = z;

	return (out);
}

t_vec2	new_vec2(float x, float y)
{
	t_vec2	out;

	out.x = x;
	out.y = y;
	return (out);
}

void	matrix_destroy(t_matrix *mat)
{
	int	i;

	i = 0;
	while (i < mat->h_matrix)
	{
		free(mat->matrix[i++]);
	}
	free(mat->matrix);
	free(mat);
}

int	matrix_biggest_z(t_matrix *mat)
{
	int	i;
	int	j;
	int	out;

	i = 0;
	out = 0;
	while(i < mat->h_matrix)
	{
		j = 0;
		while (j < mat->w_matrix)
		{
			if ((mat->matrix[i][j]) > out)
				out = (mat->matrix[i][j]);
			j++;
		}
		i++;
	}
	return (out);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	my_abs(double in)
{
	if (in < 0)
		return (in * -1);
	return (in);
}
