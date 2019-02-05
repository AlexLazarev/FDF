/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:53:20 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/16 19:14:33 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>
#include <math.h>

void	transform(int *x, int *y, int const z, t_point_3d rotate)
{
	t_point_3d p0;
	t_point_3d p1;

	p0.x = *x;
	p0.y = *y * cos(rotate.x) + z * sin(rotate.x);
	p0.z = z * cos(rotate.x) - *y * sin(rotate.x);
	p1.x = p0.x * cos(rotate.y) - p0.z * sin(rotate.y);
	p1.y = p0.y;
	p1.z = p0.z * cos(rotate.y) + p0.x * sin(rotate.y);
	*x = p1.x * cos(rotate.z) + p1.y * sin(rotate.z);
	*y = p1.y * cos(rotate.z) - p1.x * sin(rotate.z);
}

void	draw_pixel(t_global *global, int x, int y)
{
	mlx_pixel_put(global->mlx, global->window,
			global->map->x + x, global->map->y + y,
			global->map->colour.rgba);
}

void	draw_line(t_global *global, int p1[2], int p2[2])
{
	int delta[2];
	int sign[2];
	int error[2];

	delta[X] = abs(p2[X] - p1[X]);
	delta[Y] = abs(p2[Y] - p1[Y]);
	sign[X] = p1[X] < p2[X] ? 1 : -1;
	sign[Y] = p1[Y] < p2[Y] ? 1 : -1;
	error[0] = delta[X] - delta[Y];
	draw_pixel(global, p2[X], p2[Y]);
	while (p1[X] != p2[X] || p1[Y] != p2[Y])
	{
		draw_pixel(global, p1[X], p1[Y]);
		error[1] = error[0] * 2;
		if (error[1] > -delta[Y])
		{
			error[0] -= delta[Y];
			p1[X] += sign[X];
		}
		if (error[1] < delta[X])
		{
			error[0] += delta[X];
			p1[Y] += sign[Y];
		}
	}
}

void	ft_normik(t_global *global, int const p[2], int i, int j)
{
	int p2[2];
	int	p1[2];

	p1[X] = p[X];
	p1[Y] = p[Y];
	p2[X] = global->map->field[i][j].x *
		global->map->scale *
		global->map->stretch.x;
	p2[Y] = global->map->field[i][j].y *
		global->map->scale *
		global->map->stretch.y;
	transform(&p2[X], &p2[Y],
			global->map->field[i][j].z *
			global->map->scale *
			global->map->stretch.z,
			global->map->rotate);
	draw_line(global, p1, p2);
}

void	draw(t_global *global)
{
	int i;
	int	j;
	int	p1[2];
	int	p2[2];

	i = -1;
	while (++i < global->map->height)
	{
		j = -1;
		while (++j < global->map->width)
		{
			p1[X] = global->map->field[i][j].x *
					global->map->scale * global->map->stretch.x;
			p1[Y] = global->map->field[i][j].y *
					global->map->scale * global->map->stretch.y;
			transform(&p1[X], &p1[Y],
					global->map->field[i][j].z *
					global->map->scale *
					global->map->stretch.z, global->map->rotate);
			if (j < global->map->width - 1)
				ft_normik(global, p1, i, j + 1);
			if (i < global->map->height - 1)
				ft_normik(global, p1, i + 1, j);
		}
	}
}
