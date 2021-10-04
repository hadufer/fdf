/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:24:48 by hadufer           #+#    #+#             */
/*   Updated: 2021/10/04 15:38:09 by hadufer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
