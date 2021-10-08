/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:51:29 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/08 07:29:31 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "ft_printf.h"
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int	handle_entry_fd(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_printf("Please enter a valid file.\nUsage: ./fdf [filename].fdf\n", 1);
		exit(-1);
	}
	if (ft_strlen(argv[1]) < 4
		|| ft_strncmp(".fdf", argv[1] + (ft_strlen(argv[1]) - 4), 4))
	{
		ft_printf("Please enter a valid file.\nUsage: ./fdf [filename].fdf\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Please enter a valid file.\nUsage: ./fdf [filename].fdf\n");
		ft_printf("errno: %s\n", strerror(errno));
		close(fd);
		exit(-1);
	}
	close(fd);
	return (0);
}

int	render(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, img->s_width, img->s_height);
	matrix_draw(img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_matrix	*mat;
	t_data		img;

	img.s_width = 500;
	img.s_height = 500;
	img.offset_x = 0;
	img.offset_y = 0;
	img.zoom = 1;
	img.iso = 1;
	handle_entry_fd(argc, argv);
	mat = file_to_matrix(argv[1]);
	img.mat = mat;
	img.draw_max_num = matrix_biggest_z(img.mat);
	ft_putnbr_fd(img.draw_max_num, 1);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.s_width, img.s_height, "fdf");
	img.img = mlx_new_image(img.mlx, img.s_width, img.s_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	mlx_hook(img.win, 2, 1L << 0, key_handle, &img);
	mlx_loop_hook(img.mlx, render, &img);
	mlx_loop(img.mlx);
}
