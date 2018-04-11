#include "../includes/fdf.h"
#include "../includes/mlx.h"
#include <math.h>



void	transform(int *x, int *y, int const z, t_rotate *rotate)
{
	/*
	t_point_3d p0;
	t_point_3d p1;

	p0.x = *x;
	p0.y = *y * cos(rotate->rx) + z * sin(rotate->rx);
	p0.z = z * cos(rotate->rx) - *y * sin(rotate->rx);
	p1.x = p0.x * cos(rotate->ry) + p0.z * sin(rotate->ry);
	p1.y = p0.y;
	p1.z = p0.z * cos(rotate->ry) + p0.x * sin(rotate->ry);
	//
	*x = p1.x * cos(rotate->rz) + p1.y * sin(rotate->rz);
	*y = p1.y * cos(rotate->rz) - p1.x * sin(rotate->rz);
	printf("%d %d\n", *x, *y);
	getchar();*/
}

void	draw(t_global *global)
{
	int i;
	int	j;
	int	k;
	i = 0;
	while (i < global->map->height)
	{	
		j = 0;
		while (j < global->map->width)
		{
			k = global->map->field[i][j].x;
			transform(&k, &global->map->field[i][j].y, global->map->field[i][j].z, global->map->rotate);
			while (j < global->map->width - 1 && k < global->map->field[i][j + 1].x)
			{
				mlx_pixel_put(global->mlx, global->window, global->map->x + k, global->map->y + global->map->field[i][j].y, 0xFF00FF);
				k++;
			}
			k = global->map->field[i][j].y;
			transform(&global->map->field[i][j].x, &k, global->map->field[i][j].z, global->map->rotate);
			while (i < global->map->height - 1 && k < global->map->field[i + 1][j].y)
			{
				mlx_pixel_put(global->mlx, global->window, global->map->x + global->map->field[i][j].x, global->map->y + k, 0xFF00FF);
				k++;
			}
			j++;
		}
		i++;
	}
}