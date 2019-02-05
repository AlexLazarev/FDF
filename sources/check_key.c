/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:50:05 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/16 15:53:11 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"

int	check_stretch(int key, t_map *map)
{
	if (key == KEY_Y)
		map->stretch.y += 1;
	else if (key == KEY_H)
		map->stretch.y -= 1;
	else if (key == KEY_U)
		map->stretch.x += 1;
	else if (key == KEY_J)
		map->stretch.x -= 1;
	else if (key == KEY_I)
		map->stretch.z += 1;
	else if (key == KEY_K)
		map->stretch.z -= 1;
	else
		return (0);
	return (1);
}

int	check_scale(int key, t_map *map)
{
	if (key == KEY_N)
		map->scale -= 5;
	else if (key == KEY_M)
		map->scale += 5;
	else
		return (0);
	return (1);
}

int	check_rotate(int key, t_map *map)
{
	if (key == KEY_W)
		map->rotate.y += 0.1;
	else if (key == KEY_S)
		map->rotate.y -= 0.1;
	else if (key == KEY_A)
		map->rotate.x += 0.1;
	else if (key == KEY_D)
		map->rotate.x -= 0.1;
	else if (key == KEY_Q)
		map->rotate.z += 0.1;
	else if (key == KEY_E)
		map->rotate.z -= 0.1;
	else
		return (0);
	return (1);
}

int	check_colour(int key, t_map *map)
{
	if (key == KEY_P)
	{
		if ((map->colour.c[ALPHA] += 10) > 255)
			map->colour.c[ALPHA] = 0;
	}
	else if (key == KEY_R)
	{
		if ((map->colour.c[RED] += 10) > 255)
			map->colour.c[RED] = 0;
	}
	else if (key == KEY_G)
	{
		if ((map->colour.c[GREEN] += 10) > 255)
			map->colour.c[GREEN] = 0;
	}
	else if (key == KEY_B)
	{
		if ((map->colour.c[BLUE] += 10) > 255)
			map->colour.c[BLUE] = 0;
	}
	else
		return (0);
	return (1);
}

int	check_translate(int key, t_map *map)
{
	if (key == KEY_LEFT)
		map->x -= DX;
	else if (key == KEY_RIGHT)
		map->x += DX;
	else if (key == KEY_UP)
		map->y -= DY;
	else if (key == KEY_DOWN)
		map->y += DY;
	else
		return (0);
	return (1);
}
