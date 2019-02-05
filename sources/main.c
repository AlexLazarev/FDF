/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 20:58:00 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/17 20:58:02 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../lib/libft/includes/libft.h"
#include "../includes/fdf.h"
#include "../includes/keys.h"

void	init_map(t_map *map)
{
	map->rotate.x = 0;
	map->rotate.y = 0;
	map->rotate.z = 0;
	map->stretch.x = 1;
	map->stretch.y = 1;
	map->stretch.z = 1;
	map->scale = 10;
	map->colour.c[ALPHA] = 0;
	map->colour.c[RED] = 0xD7;
	map->colour.c[GREEN] = 0x10;
	map->colour.c[BLUE] = 0xFF;
	map->x = WINDOW_WIDTH / 2;
	map->y = WINDOW_HEIGHT / 2;
}

int		deal_key(int key, void *param)
{
	if (!check_translate(key, ((t_global*)param)->map))
		if (!check_rotate(key, ((t_global*)param)->map))
			if (!check_scale(key, ((t_global*)param)->map))
				if (!check_stretch(key, ((t_global*)param)->map))
					if (!(check_colour(key, ((t_global*)param)->map)))
					{
						if (key == KEY_SPACE)
							init_map(((t_global*)param)->map);
						else if (key == KEY_ESC)
							exit(1);
					}
	mlx_clear_window(((t_global*)param)->mlx, ((t_global*)param)->window);
	faq(((t_global*)param));
	draw(param);
	return (0);
}

int		exit_x(void *param)
{
	exit(1);
	return (1);
}

void	init_global(t_global *global, int fd, char *file)
{
	global->map = (t_map*)malloc(sizeof(t_map));
	if (!valid(fd, global->map))
		ft_error("some problems with validation");
	global->mlx = mlx_init();
	global->window = mlx_new_window(global->mlx,
				WINDOW_WIDTH, WINDOW_HEIGHT, "FDF");
	global->mouse = (t_mouse*)malloc(sizeof(t_mouse));
	global->mouse->state = RELEASED;
	close(fd);
	fd = open(file, O_RDONLY);
	parse(fd, global->map);
	close(fd);
	init_map(global->map);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_global	*global;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			global = (t_global*)malloc(sizeof(t_global));
			init_global(global, fd, argv[1]);
			faq(global);
			draw(global);
			mlx_hook(global->window, 2, 0, deal_key, global);
			mlx_hook(global->window, 4, 0, mouse_press, global);
			mlx_hook(global->window, 5, 0, mouse_release, global);
			mlx_hook(global->window, 6, 0, mouse_move, global);
			mlx_hook(global->window, 17, 0, exit_x, global);
			mlx_loop(global->mlx);
		}
		else
			ft_error("file not exist");
	}
	else
		ft_error("count of arguments is not OK");
	return (0);
}
