/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:40:35 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/09 17:46:08 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "../lib/libft/includes/libft.h"

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 1000
# define DX 40
# define DY 40

typedef struct	s_point_3d
{
	int	x;
	int	y;
	int z;
}				t_point_3d;

typedef struct	s_line_3d
{
	t_point_3d	p1;
	t_point_3d	p2;
}				t_line_3d;

typedef struct  s_rotate
{
	double			rx;
	double			ry;
	double			rz;
}				t_rotate;

typedef struct s_map
{
	int			width;
	int			height;
	int			x;
	int			y;
	t_point_3d 	**field;
	t_rotate	*rotate;
}				t_map;

typedef struct	s_global
{
	void	*mlx;
	void	*window;
	t_map	*map;
}				t_global;


int		valid(int fd, t_map *map);
void	parse(int fd, t_map *map);
void	draw(t_global *global);
#endif
