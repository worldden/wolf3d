/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:18:52 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:18:53 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	raycasting_if(t_wolf *den)
{
	if (den->raydirx < 0)
	{
		den->stepx = -1;
		den->sidedistx = (den->posx - den->mapx) * den->deltadistx;
	}
	else
	{
		den->stepx = 1;
		den->sidedistx = (den->mapx + 1.0 - den->posx) * den->deltadistx;
	}
	if (den->raydiry < 0)
	{
		den->stepy = -1;
		den->sidedisty = (den->posy - den->mapy) * den->deltadisty;
	}
	else
	{
		den->stepy = 1;
		den->sidedisty = (den->mapy + 1.0 - den->posy) * den->deltadisty;
	}
}

void	raycasting_hit(t_wolf *den)
{
	while (den->hit == 0)
	{
		if (den->sidedistx < den->sidedisty)
		{
			den->sidedistx += den->deltadistx;
			den->mapx += den->stepx;
			den->side = 0;
		}
		else
		{
			den->sidedisty += den->deltadisty;
			den->mapy += den->stepy;
			den->side = 1;
		}
		if (den->map[den->mapy][den->mapx] > 0)
			den->hit = 1;
	}
	if (den->side == 0)
		den->perpwalldist = (den->mapx - den->posx +
			(1 - den->stepx) / 2) / den->raydirx;
	else
		den->perpwalldist = (den->mapy - den->posy +
			(1 - den->stepy) / 2) / den->raydiry;
	den->lineheight = I(HEIGHT / den->perpwalldist);
	den->drawstart = -den->lineheight / 2 + HEIGHT / 2;
}

void	raycasting_draw(t_wolf *den)
{
	if (den->drawstart < 0)
		den->drawstart = 0;
	den->drawend = den->lineheight / 2 + HEIGHT / 2;
	if (den->drawend >= HEIGHT)
		den->drawend = HEIGHT - 1;
	if (den->side == 0)
		den->wallx = den->posy + den->perpwalldist * den->raydiry;
	else
		den->wallx = den->posx + den->perpwalldist * den->raydirx;
	den->wallx -= floor((den->wallx));
	den->texx = I(den->wallx * den->texwidth);
	if (den->side == 0 && den->raydirx > 0)
		den->texx = den->texwidth - den->texx - 1;
	if (den->side == 1 && den->raydiry < 0)
		den->texx = den->texwidth - den->texx - 1;
	drow_floor(den);
	if (den->walls == 0)
		drow_wall(den);
	else
		drow_wall2(den);
}

void	raycasting(t_wolf *den)
{
	den->x = 0;
	den->m = 0;
	time_count(den);
	while (den->x < WIDTH)
	{
		den->camerax = 2 * den->x / (double)WIDTH - 1;
		den->raydirx = den->dirx + den->planex * den->camerax;
		den->raydiry = den->diry + den->planey * den->camerax;
		den->mapx = I(den->posx);
		den->mapy = I(den->posy);
		den->deltadistx = fabs(1 / den->raydirx);
		den->deltadisty = fabs(1 / den->raydiry);
		den->hit = 0;
		raycasting_if(den);
		raycasting_hit(den);
		raycasting_draw(den);
		den->x++;
	}
	mlx_put_image_to_window(den->mlx_ptr, den->win_ptr, den->img_ptr, 0, 0);
	drow_sword(den);
}

void	drow_sword(t_wolf *den)
{
	if (den->sword == 0)
	{
		if (den->pos == 0)
			den->m = 2;
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
								den->tex[5], 500, 550 + den->m);
	}
	if (den->sword == 1)
	{
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
								den->tex[11], 570, 550);
	}
	if (den->sword == 2)
	{
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
								den->tex[13], 500, 600);
	}
	mlx_put_image_to_window(den->mlx_ptr, den->win_ptr, den->tex[6], 0, 850);
	put_hero(den);
}
