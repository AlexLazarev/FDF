/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:29:46 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/17 20:32:13 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/keys.h"
#include <mlx.h>

int	mouse_press(int key, int x, int y, void *param)
{
	if (key == MOUSE_KEY_LEFT)
		((t_global*)param)->mouse->state = PRESSED;
	else if (key == MOUSE_SCROLL_UP)
		((t_global*)param)->map->scale += 5;
	else if (key == MOUSE_SCROLL_DOWN)
	{
		if (((t_global*)param)->map->scale > 0)
			((t_global*)param)->map->scale -= 5;
	}
	mlx_clear_window(((t_global*)param)->mlx, ((t_global*)param)->window);
	faq(((t_global*)param));
	draw(param);
	return (0);
}

int	mouse_release(int key, int x, int y, void *param)
{
	if (key == MOUSE_KEY_LEFT)
		((t_global*)param)->mouse->state = RELEASED;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	if (((t_global*)param)->mouse->state == PRESSED)
	{
		((t_global*)param)->map->x = x -
			(((t_global*)param)->map->scale *
			((t_global*)param)->map->width / 2);
		((t_global*)param)->map->y = y -
			(((t_global*)param)->map->scale *
			((t_global*)param)->map->height / 2);
	}
	mlx_clear_window(((t_global*)param)->mlx, ((t_global*)param)->window);
	faq(((t_global*)param));
	draw(param);
	return (0);
}
