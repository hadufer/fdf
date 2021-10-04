/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:44:34 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/04 17:34:26 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#define HEIGHT 500
#define WIDTH 500
#define FACTOR 10
#include <mlx.h>
typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_matrix
{
	int	h_matrix;
	int	w_matrix;
	int	**matrix;
}				t_matrix;


typedef struct	s_vec2
{
	int			x;
	int			y;
}				t_vec2;

typedef struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_line(t_data *data, t_vec2 a, t_vec2 b, int color);
t_vec3			new_vec3(float x, float y, float z);
t_vec2			new_vec2(float x, float y);
t_matrix		*file_to_matrix(char *file_path);
int				matrix_draw(t_data *data, t_matrix *mat);
#endif
