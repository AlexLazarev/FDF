#include "../includes/fdf.h"
#include "../includes/get_next_line.h"

int	valid(int fd, t_map *map) // add validation
{
	int len;
	char	*buf;

	len = 0;
	while (get_next_line(fd, &buf))
	{
		len++;
		map->width = ft_strnsplit(buf, ' ');
	}
	map->height = len;
	free(buf);
	return (0);
}

void	parse(int fd, t_map *map)
{
	int		i;
	int		j;
	char	*buf;
	char	**str;

	i = 0;
	map->field = (t_point_3d**)malloc(sizeof(t_point_3d*) * (map->height));
	while (get_next_line(fd, &buf))
	{
		j = 0;
		str = ft_strsplit(buf, ' ');
		map->field[i] = (t_point_3d*)malloc(sizeof(t_point_3d) * (map->width));
		while (str[j])
		{
			map->field[i][j].x = j * 10;
			map->field[i][j].y = i * 10;
			map->field[i][j].z = ft_atoi(str[j]) * 10;	
			j++;
		}
		i++;
	}
}