/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 19:05:20 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/31 19:05:21 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_create_img(t_wolf *den, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(den->img_data_addr + ((x + y * WIDTH) * 4)) = color;
}

void	find_img_addr(t_wolf *den)
{
	den->bpp = 8;
	den->sl = 1;
	den->endian = (WIDTH * HEIGHT);
	den->img_ptr = mlx_new_image(den->mlx_ptr, WIDTH, HEIGHT);
	den->img_data_addr = mlx_get_data_addr(den->img_ptr,
		&den->bpp, &den->sl, &den->endian);
}

void	clear_image(t_wolf *den)
{
	ft_memset(den->img_data_addr, 0, ((WIDTH * HEIGHT) * 4));
}

void	time_count(t_wolf *den)
{
	den->oldtime = den->time;
	den->time = clock();
	den->frametime = (den->time - den->oldtime) / CLOCKS_PER_SEC;
	den->move_speed = den->frametime * 5.0;
}

void	plaer_option(t_wolf *den)
{
	den->posx = 2;
	den->posy = 2;
	if (den->map[I(den->posy)][I(den->posx)] != 0 ||
		den->map[I(den->posy)][I(den->posx - 1)] != 0 ||
		den->map[I(den->posy - 1)][I(den->posx - 1)] != 0 ||
		den->map[I(den->posy - 1)][I(den->posx)] != 0)
		exit_eror(2);
	den->dirx = -1;
	den->diry = 0;
	den->planex = 0;
	den->planey = 0.66;
	den->time = 0;
	den->oldtime = 0;
	den->time = 0;
	den->oldtime = 0;
	den->hero = 1;
	den->sword = 0;
	den->anim = 0;
	den->move_up = 0;
	den->move_down = 0;
	den->fight = 0;
	den->speed = 0;
	system("afplay texture/muzyka.mp3&");
}
