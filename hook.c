/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:18:40 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:18:41 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		say_name(t_wolf *den)
{
	if (den->hero == 1)
		system("say Repeta&");
	if (den->hero == 2)
		system("say Lemar&");
	if (den->hero == 3)
		system("say Florin&");
	if (den->hero == 4)
		system("say Deman&");
	if (den->hero == 5)
		system("say Alex&");
	return (0);
}

int		mouse_hints(int x, int y, t_wolf *den)
{
	int k;

	k = 2;
	y = 0;
	if (x > den->xpos)
	{
		den->xpos = x;
		k = 2;
	}
	if (x < den->xpos || x < 0)
	{
		den->xpos = x;
	 	k = 0;
	 }
	povorot(k, den);
	return (0);
}

int		key_liv(int key, t_wolf *den)
{
	if (key == 13)
		den->move_up = 0;
	if (key == 1)
		den->move_down = 0;
	if (key == 257)
		den->speed = 0;
	return (0);
}

int		key_p(int key, t_wolf *den)
{
	if (key == 13)
	{
		den->move_up = 1;
		den->i++;
	}
	if (key == 1)
	{
		den->move_down = 1;
		den->i++;
	}
	if (key == 0)
		povorot(key, den);
	if (key == 2)
		povorot(key, den);
	if (key == 53)
		deal_key(53);
	if (key == 49)
		den->walls = den->walls == 1 ? 0 : 1;
	if (key == 257)
		den->speed = 1;
	return (0);
}

int		povorot(int k, t_wolf *den)
{
	if (k == 0)
	{
		den->oldrix = den->dirx;
		den->dirx = den->dirx * cos(0.1) - den->diry * sin(0.1);
		den->diry = den->oldrix * sin(0.1) + den->diry * cos(0.1);
		den->oldplanetx = den->planex;
		den->planex = den->planex * cos(0.1) - den->planey * sin(0.1);
		den->planey = den->oldplanetx * sin(0.1) + den->planey * cos(0.1);
		den->i = 0;
	}
	if (k == 2)
	{
		den->oldrix = den->dirx;
		den->dirx = den->dirx * cos(-0.1) - den->diry * sin(-0.1);
		den->diry = den->oldrix * sin(-0.1) + den->diry * cos(-0.1);
		den->oldplanetx = den->planex;
		den->planex = den->planex * cos(-0.1) - den->planey * sin(-0.1);
		den->planey = den->oldplanetx * sin(-0.1) + den->planey * cos(-0.1);
		den->i = 0;
	}
	clear_image(den);
	raycasting(den);
	return (0);
}
