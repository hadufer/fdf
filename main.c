/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 11:51:29 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/04 16:52:28 by hadufer          ###   ########.fr       */
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
	int fd;

	if (argc < 2)
	{
		ft_printf("Please enter a valid file.\nUsage: ./fdf [filename].fdf\n", 1);
		exit(-1);
	}
	if (ft_strlen(argv[1]) < 4 || ft_strncmp(".fdf", argv[1] + (ft_strlen(argv[1]) - 4), 4))
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

int	main(int argc, char **argv)
{
	t_matrix	*mat;
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	handle_entry_fd(argc, argv);
	mat = file_to_matrix(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	matrix_draw(&img, mat);
	mlx_clear_window(mlx, mlx_win);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
