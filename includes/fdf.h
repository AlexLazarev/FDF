/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:40:35 by alazarev          #+#    #+#             */
/*   Updated: 2018/04/17 20:53:56 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "../lib/libft/includes/libft.h"

# define ABS(x) (x > 0 ? x : -(x))

# define WINDOW_WIDTH 1800
# define WINDOW_HEIGHT 1200
# define DX 40
# define DY 40
# define ALPHA 3
# define RED 2
# define GREEN 1
# define BLUE 0
# define X 0
# define Y 1
# define PRESSED 1
# define RELEASED 0

typedef struct	s_point_3d
{
	float	x;
	float	y;
	float	z;
}				t_point_3d;

typedef struct	s_line_3d
{
	t_point_3d	p1;
	t_point_3d	p2;
}				t_line_3d;

typedef union	u_rgb
{
	int				rgba;
	unsigned char	c[4];
}				t_rgb;

typedef struct	s_map
{
	int			width;
	int			height;
	int			x;
	int			y;
	t_point_3d	**field;
	t_point_3d	rotate;
	t_point_3d	stretch;
	t_rgb		colour;
	int			scale;
}				t_map;

typedef struct	s_mouse
{
	int	state;
}				t_mouse;

typedef struct	s_global
{
	void	*mlx;
	void	*window;
	t_map	*map;
	t_mouse	*mouse;
}				t_global;

void			faq(t_global *global);
int				valid(int fd, t_map *map);
void			parse(int fd, t_map *map);
void			draw(t_global *global);
int				check_stretch(int key, t_map *map);
int				check_rotate(int key, t_map *map);
int				check_scale(int key, t_map *map);
int				check_translate(int key, t_map *map);
int				check_colour(int key, t_map *map);
int				mouse_press(int key, int x, int y, void *param);
int				mouse_release(int key, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);

#endif
