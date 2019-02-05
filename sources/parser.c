/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:08:41 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/17 17:09:47 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/get_next_line.h"
#include "../lib/libft/includes/libft.h"

int		check(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if ((buf[i] < 48 || buf[i] > 57) && buf[i] != ' ')
		{
			if (buf[i] != '-' || (buf[i + 1] < 48 || buf[i + 1] > 57))
				return (0);
		}
		i++;
	}
	return (1);
}

int		valid(int fd, t_map *map)
{
	int		height;
	char	*buf;
	int		ret;

	height = 0;
	while ((ret = get_next_line(fd, &buf)))
	{
		if (ret == -1 || !check(buf))
			return (0);
		if (!height)
			map->width = ft_strnsplit(buf, ' ');
		else if (map->width != ft_strnsplit(buf, ' '))
			return (0);
		height++;
		free(buf);
	}
	map->height = height;
	return (1);
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
			map->field[i][j].x = j;
			map->field[i][j].y = i;
			map->field[i][j].z = ft_atoi(str[j]);
			free(str[j]);
			j++;
		}
		free(str);
		free(buf);
		i++;
	}
}
