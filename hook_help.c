/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:19:18 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:19:19 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "stdio.h"

int		action(t_wolf *den)
{
	if (den->speed == 1)
		den->move_speed = den->move_speed * 1.5;
	if (den->fight == 1)
		sword_count(den);
	if (den->move_up == 1)
	{
		if (den->map[I(den->posy)][I((den->posx + (den->dirx * 0.4)))] == 0)
			den->posx += den->dirx * den->move_speed;
		if (den->map[I(den->posy + (den->diry * 0.4))][I(den->posx)] == 0)
			den->posy += den->diry * den->move_speed;
		if (den->i % 10 == 0)
			den->pos = den->pos == 1 ? 0 : 1;
	}
	if (den->move_down == 1)
	{
		if (den->map[I(den->posy)][I((den->posx - (den->dirx * 0.4)))] == 0)
			den->posx -= den->dirx * den->move_speed;
		if (den->map[I(den->posy - (den->diry * 0.4))][I(den->posx)] == 0)
			den->posy -= den->diry * den->move_speed;
		if (den->i % 10 == 0)
			den->pos = den->pos == 1 ? 0 : 1;
	}
	clear_image(den);
	raycasting(den);
	return (0);
}

int		mouse_fight(int keycode, int x, int y, t_wolf *den)
{
	x = 0;
	y = 0;
	if (keycode == 1)
		den->fight = 1;
	if (keycode == 2)
	{
		den->hero += den->hero == 5 ? -4 : 1;
		say_name(den);
	}
	return (0);
}

void	sword_count(t_wolf *den)
{
	den->anim = den->frametime + den->anim;
	if (den->anim > 0.05)
	{
		den->sword = 1;
		clear_image(den);
		raycasting(den);
	}
	if (den->anim > 0.12)
	{
		den->sword = 2;
		clear_image(den);
		raycasting(den);
	}
	if (den->anim > 0.2)
	{
		den->sword = 0;
		den->anim = 0;
		den->fight = 0;
		clear_image(den);
		raycasting(den);
	}
}
