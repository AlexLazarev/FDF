/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:39:21 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/09 17:27:53 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../lib/libft/includes/libft.h"
#include "../includes/fdf.h"
#include "../includes/keys.h"

int deal_key(int key, void *param)
{
	if (key == KEY_W)
	{
		((t_global*)param)->map->rotate->ry += 10;
	}
	else if (key == KEY_S)
	{
		((t_global*)param)->map->rotate->ry -= 10;
	}
	else if (key == KEY_A)
	{
		((t_global*)param)->map->rotate->rx += 10;	
	}
	else if (key == KEY_D)
	{
		((t_global*)param)->map->rotate->rx -= 10;	
	}
	else if (key == KEY_Q)
	{
		((t_global*)param)->map->rotate->rz += 10;
	}
	else if (key == KEY_E)
	{
		((t_global*)param)->map->rotate->rz -= 10;
	}
	else if (key == KEY_LEFT)
	{
		((t_global*)param)->map->x += DX;
	}
	else if (key == KEY_RIGHT)
	{
		((t_global*)param)->map->y += DY;
	}
	printf("%f %f %f\n", ((t_global*)param)->map->rotate->rx, ((t_global*)param)->map->rotate->ry, ((t_global*)param)->map->rotate->rz);
	mlx_clear_window(((t_global*)param)->mlx, ((t_global*)param)->window);
	//draw(param);
	return (0);
}

/*
int	main(int argc, char **argv)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)malloc(sizeof(t_mlx));

	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, 750, 750, "LOL");
	


	mlx_key_hook(mlx->window, deal_key, mlx);
	mlx_loop(mlx->mlx);

	return (0);
}*/void	print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{	
		j = 0;
		while (j < map->width)
		{

			printf("%d %d %d\n", map->field[i][j].x, map->field[i][j].y, map->field[i][j].z);
			j++;
		}
		i++;
	}
}


int main(int argc, char **argv)
{
	int 		fd;
	t_global	*global;
	//mlx
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			global = (t_global*)malloc(sizeof(t_global));
			global->mlx = mlx_init();
			global->window = mlx_new_window(global->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "LOL");
			//map
			global->map = (t_map*)malloc(sizeof(t_map));
			valid(fd, global->map);
			close(fd);
			fd = open(argv[1], O_RDONLY);
			parse(fd, global->map);
			close(fd);
			//rotate
			global->map->rotate = (t_rotate*)malloc(sizeof(t_rotate));
			global->map->rotate->rx = 0;
			global->map->rotate->ry = 0;
			global->map->rotate->rz = 0;
			global->map->x = WINDOW_WIDTH / 2;
			global->map->y = WINDOW_HEIGHT / 2;
			//draw
			print_map(global->map);
			draw(global);
			mlx_key_hook(global->window, deal_key, global);
			mlx_loop(global->mlx);
		}
	}
	return (0);
}