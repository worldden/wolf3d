/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:06:36 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/21 19:06:39 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# include <mlx.h>
# include <math.h>
# include <signal.h>
# include <time.h>
# include "libft/libft.h"
# define WIDTH 1400
# define HEIGHT 1000
# define I (int)

typedef struct	s_wolf
{
	char		*name;
	int			fd;
	void		*mlx_ptr;
	void		*win_ptr;
	int			line;
	int			width;
	int			bpp;
	int			sl;
	int			endian;
	int			end;
	char		*img_data_addr;
	void		*img_ptr;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		frametime;
	double		move_speed;
	double		anim;
	int			fight;
	int			move_up;
	int			move_down;
	int			**map;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			x;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	double		oldrix;
	double		oldplanetx;
	int			tehnum;
	int			texy;
	int			texx;
	double		wallx;
	int			texwidth;
	int			texheight;
	int			floortexx;
	int			floortexy;
	int			floortexture;
	int			checkerboardpattern;
	double		fxwall;
	double		fywall;
	double		distwall;
	double		dp;
	double		currentdist;
	double		cfx;
	double		cfy;
	double		weight;
	int			r;
	int			g;
	int			b;
	int			speed;
	void		*tex[14];
	char		*text[6];
	int			xpos;
	int			ypos;
	int			pos;
	int			hero;
	int			walls;
	int			i;
	int			sword;
	int			m;
}				t_wolf;

typedef struct	s_tex
{
	int			p[6];
	int			s[6];
	int			e[6];
}				t_tex;

typedef struct	s_read
{
	char		*line;
	char		**tab;
	int			i;
	int			j;
	int			k;
}				t_read;

int				exit_eror(int eror);
int				exit_x(void *par);
void			check_map(t_wolf *den);
int				deal_key(int key);
void			exit_s();
void			drow_floor(t_wolf *den);
void			drow_wall(t_wolf *den);
void			drow_wall_teh(t_wolf *den, int y);
void			drow_wall2(t_wolf *den);
void			option_floor(t_wolf *den);
void			plaer_option(t_wolf *den);
void			find_img_addr(t_wolf *den);
void			ft_create_img(t_wolf *den, int x, int y, int color);
void			clear_image(t_wolf *den);
void			time_count(t_wolf *den);
int				say_name(t_wolf *den);
int				mouse_hints(int x, int y, t_wolf *den);
int				povorot(int k, t_wolf *den);
int				key_liv(int key, t_wolf *den);
int				key_p(int key, t_wolf *den);
int				action(t_wolf *den);
int				mouse_fight(int keycode, int x, int y, t_wolf *den);
void			sword_count(t_wolf *den);
int				get_fd(char *filename);
void			makewolf(t_wolf *den);
int				readeng(t_wolf *den);
int				valid(t_wolf *den);
void			reading_help(t_read *rd, t_wolf *den);
int				valid_line(char *line);
void			load_texture_help(t_wolf *den, int x, int y);
void			load_texture(t_wolf *den);
void			load_texture_two(t_wolf *den, int x, int y);
void			put_hero(t_wolf *den);
void			raycasting(t_wolf *den);
void			raycasting_if(t_wolf *den);
void			raycasting_hit(t_wolf *den);
void			raycasting_draw(t_wolf *den);
void			drow_sword(t_wolf *den);
int				get_fd(char *filename);
void			makewolf(t_wolf *den);

#endif
