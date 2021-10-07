/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:44:34 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/07 08:14:56 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#define ANGLE 0.523599
#define KEY_ESCAPE 65307
#define KEY_MINUS 45
#define KEY_PLUS 61
#define KEY_LEFT 65361
#define KEY_RIGHT 65363
#define KEY_DOWN 65364
#define KEY_UP 65362
#define KEY_1 49
#include <mlx.h>

typedef struct	s_matrix
{
	int	h_matrix;
	int	w_matrix;
	int	**matrix;
}				t_matrix;

typedef struct	s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			s_width;
	int			s_height;
	int			zoom;
	int			offset_x;
	int			offset_y;
	int			iso;
	t_matrix	*mat;
}				t_data;

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
void			draw_ortho(t_data *data);
void			draw_iso(t_data *data);
int				matrix_draw(t_data *data);
void			matrix_destroy(t_matrix *mat);
int				key_handle(int keycode, t_data *img);
#endif
