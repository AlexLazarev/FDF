/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:58:13 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/17 20:58:15 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

void	rgb_prop(t_global *global)
{
	char *str;

	mlx_string_put(global->mlx,
		global->window, 30, WINDOW_HEIGHT - 40, 0xFF0000, " R ");
	mlx_string_put(global->mlx, global->window, 60, WINDOW_HEIGHT - 40,
		0xFF0000, (str = ft_itoa(global->map->colour.c[RED])));
	free(str);
	mlx_string_put(global->mlx,
		global->window, 90, WINDOW_HEIGHT - 40, 0xFF0000, " G ");
	mlx_string_put(global->mlx, global->window, 120, WINDOW_HEIGHT - 40,
		0xFF0000, (str = ft_itoa(global->map->colour.c[GREEN])));
	free(str);
	mlx_string_put(global->mlx,
		global->window, 150, WINDOW_HEIGHT - 40, 0xFF0000, " B ");
	mlx_string_put(global->mlx, global->window, 180, WINDOW_HEIGHT - 40,
		0xFF0000, (str = ft_itoa(global->map->colour.c[BLUE])));
	free(str);
	mlx_string_put(global->mlx,
		global->window, 210, WINDOW_HEIGHT - 40, 0xFF0000, " P ");
	mlx_string_put(global->mlx, global->window, 240, WINDOW_HEIGHT - 40,
		0xFF0000, (str = ft_itoa(global->map->colour.c[ALPHA])));
	free(str);
}

void	faq(t_global *global)
{
	int		i;
	int		j;
	char	*str[4];
	char	*colour;

	str[0] = "SCALE  : REDUCE - N INCREASE - M\0";
	str[1] = "ROTATE : y - W,S x - A,D z - Q,E\0";
	str[2] = "STRETCH: y - Y,H x - U,J z - I,K\0";
	str[3] = "MOVE   : ARROWS / MOUSE\0";
	i = 0;
	while (i < 4)
	{
		mlx_string_put(global->mlx,
				global->window, 30, 30 * i + 30,
				0x00FF00, str[i]);
		i++;
	}
	rgb_prop(global);
}
