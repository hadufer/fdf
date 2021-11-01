/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:58:27 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/30 16:02:07 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "ft_printf.h"

void	count_matrix(char *file_path, t_matrix *mat)
{
	int		fd;
	char	*line;
	char	**line_cut;
	int		i[2];

	fd = open_fd_read(file_path);
	i[1] = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_cut = ft_split(line, ' ');
		free(line);
		i[0] = 0;
		while (line_cut[i[0]])
			i[0]++;
		if (i[0] > mat->w_matrix)
			mat->w_matrix = i[0];
		while (i[0] >= 0)
			free(line_cut[i[0]--]);
		line = get_next_line(fd);
		free(line_cut);
		i[1]++;
	}
	mat->h_matrix = --i[1];
	close(fd);
}

void	alloc_matrix(char *file_path, t_matrix *mat)
{
	int	fd;
	int	i;

	fd = open_fd_read(file_path);
	i = 0;
	mat->matrix = malloc(sizeof(int *) * mat->h_matrix);
	while (i < mat->h_matrix)
	{
		mat->matrix[i] = malloc(sizeof(int) * mat->w_matrix);
		i++;
	}
	close(fd);
}

void	fill_matrix(char *file_path, t_matrix *mat)
{
	int		i[2];
	int		fd;
	char	*line;
	char	**line_cut;

	fd = open_fd_read(file_path);
	line = get_next_line(fd);
	i[0] = 0;
	while (line)
	{
		line_cut = ft_split(line, ' ');
		free(line);
		i[1] = 0;
		while (line_cut[i[1]] && (i[0] < mat->h_matrix && i[1] < mat->w_matrix))
		{
			mat->matrix[i[0]][i[1]] = ft_atoi(line_cut[i[1]]);
			i[1]++;
		}
		i[0]++;
		while (i[1]-- > 0)
			free(line_cut[i[1]]);
		free(line_cut);
		line = get_next_line(fd);
	}
	close(fd);
}

t_matrix	*init_mat(void)
{
	t_matrix	*mat;

	mat = malloc(sizeof(t_matrix));
	mat->matrix = NULL;
	mat->w_matrix = 0;
	mat->h_matrix = 0;
	return (mat);
}

t_matrix	*file_to_matrix(char *file_path)
{
	t_matrix	*mat;

	mat = init_mat();
	count_matrix(file_path, mat);
	alloc_matrix(file_path, mat);
	fill_matrix(file_path, mat);
	return (mat);
}
