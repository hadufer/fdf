/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:58:27 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 15:18:44 by hadufer          ###   ########.fr       */
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
#include "ft_printf.h"
#include <stdio.h>

void	count_matrix(char *file_path, t_matrix *mat)
{
	int		fd;
	char	*line;
	char	**line_cut;
	int		i;
	int		j;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("errno: %s\n", strerror(errno));
		exit(-1);
	}
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_cut = ft_split(line, ' ');
		free(line);
		i = 0;
		while (line_cut[i])
			i++;
		if (i > mat->w_matrix)
			mat->w_matrix = i;
		while (i >= 0)
			free(line_cut[i--]);
		line = get_next_line(fd);
		free(line_cut);
		j++;
	}
	mat->h_matrix = --j;
	close(fd);
}

void	alloc_matrix(char *file_path, t_matrix *mat)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("errno: %s\n", strerror(errno));
		exit(-1);
	}
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
	int		i;
	int		j;
	int		fd;
	char	*line;
	char	**line_cut;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("errno: %s\n", strerror(errno));
		exit(-1);
	}
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		line_cut = ft_split(line, ' ');
		free(line);
		j = 0;
		while (line_cut[j])
		{
			mat->matrix[i][j] = ft_atoi(line_cut[j]);
			j++;
		}
		i++;
		while (j-- > 0)
			free(line_cut[j]);
		free(line_cut);
		line = get_next_line(fd);
	}
	close(fd);
}

t_matrix	*init_mat()
{
	t_matrix *mat;

	mat = malloc(sizeof(t_matrix));
	mat->matrix = NULL;
	mat->w_matrix = 0;
	mat->h_matrix = 0;
	return (mat);
}

void	debug_print_matrix(t_matrix *mat)
{
	int i;
	int j;

	i = 0;
	while (i < mat->h_matrix)
	{
		j = 0;
		while (j < mat->w_matrix)
		{
			ft_putnbr_fd(mat->matrix[i][j], 1);
			ft_putchar_fd(' ', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

t_matrix	*file_to_matrix(char *file_path)
{
	t_matrix *mat;

	mat = init_mat();
	count_matrix(file_path, mat);
	alloc_matrix(file_path, mat);
	fill_matrix(file_path, mat);
	debug_print_matrix(mat);
	return (mat);
}
