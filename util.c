/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:24:48 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/08 07:33:08 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include "ft_printf.h"
#include "fdf.h"

t_vec3	new_vec3(float x, float y, float z)
{
	t_vec3	out;

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
	while (i < mat->h_matrix)
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

int	open_fd_read(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("errno: %s\n", strerror(errno));
		exit(-1);
	}
	return (fd);
}
