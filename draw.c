/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:19:03 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:19:04 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	option_floor(t_wolf *den)
{
	if (den->side == 0 && den->raydirx > 0)
	{
		den->fxwall = den->mapx;
		den->fywall = den->mapy + den->wallx;
	}
	else if (den->side == 0 && den->raydirx < 0)
	{
		den->fxwall = den->mapx + 1.0;
		den->fywall = den->mapy + den->wallx;
	}
	else if (den->side == 1 && den->raydiry > 0)
	{
		den->fxwall = den->mapx + den->wallx;
		den->fywall = den->mapy;
	}
	else
	{
		den->fxwall = den->mapx + den->wallx;
		den->fywall = den->mapy + 1.0;
	}
	den->distwall = den->perpwalldist;
	den->dp = 0.0;
}

void	drow_floor(t_wolf *den)
{
	int y;

	option_floor(den);
	y = den->drawend;
	while (++y < HEIGHT)
	{
		den->currentdist = HEIGHT / (2.0 * y - HEIGHT);
		den->weight = (den->currentdist - den->dp) / (den->distwall - den->dp);
		den->cfx = den->weight * den->fxwall + (1.0 - den->weight) * den->posx;
		den->cfy = den->weight * den->fywall + (1.0 - den->weight) * den->posy;
		den->floortexx = (int)(den->cfx * den->texwidth) % den->texwidth;
		den->floortexy = (int)(den->cfy * den->texheight) % den->texheight;
		den->b = den->text[2][256 * den->floortexy + den->floortexx * 4];
		den->g = den->text[2][(256 * den->floortexy + den->floortexx * 4) + 1];
		den->r = den->text[2][(256 * den->floortexy + den->floortexx * 4) + 2];
		den->color = den->r * 0x10000 + den->g * 0x100 + den->b;
		den->color = (den->color >> 1) & 8355711;
		ft_create_img(den, den->x, y, den->color);
		den->b = den->text[4][256 * den->floortexy + den->floortexx * 4];
		den->g = den->text[4][(256 * den->floortexy + den->floortexx * 4) + 1];
		den->r = den->text[0][(256 * den->floortexy + den->floortexx * 4) + 2];
		den->color = den->r * 0x10000 + den->g * 0x100 + den->b;
		den->color = (den->color >> 1) & 8355711;
		ft_create_img(den, den->x, HEIGHT - y, den->color);
	}
}

void	drow_wall_teh(t_wolf *den, int k)
{
	den->tehnum = k;
	den->b = den->text[den->tehnum][256 * den->texy + den->texx * 4];
	den->g = den->text[den->tehnum][(256 * den->texy + den->texx * 4) + 1];
	den->r = den->text[den->tehnum][(256 * den->texy + den->texx * 4) + 2];
	den->color = den->r * 0x10000 + den->g * 0x100 + den->b;
	den->color = (den->color >> 1) & 8355711;
}

void	drow_wall(t_wolf *den)
{
	int y;
	int	d;

	y = den->drawstart;
	if (den->map[den->mapy][den->mapx] != 0)
		den->tehnum = (den->map[den->mapy][den->mapx]) - 1;
	while (y < den->drawend)
	{
		d = y * 256 - HEIGHT * 128 + den->lineheight * 128;
		den->texy = ((d * den->texheight) / den->lineheight) / 256;
		den->b = den->text[den->tehnum][256 * den->texy + den->texx * 4];
		den->g = den->text[den->tehnum][(256 * den->texy + den->texx * 4) + 1];
		den->r = den->text[den->tehnum][(256 * den->texy + den->texx * 4) + 2];
		den->color = den->r * 0x10000 + den->g * 0x100 + den->b;
		den->color = (den->color >> 1) & 8355711;
		if (den->side == 1)
			den->color = (den->color >> 1) & 8355711;
		ft_create_img(den, den->x, y, den->color);
		y++;
	}
}

void	drow_wall2(t_wolf *den)
{
	int y;
	int	d;
	int k;

	k = 0;
	y = den->drawstart;
	while (y < den->drawend)
	{
		d = y * 256 - HEIGHT * 128 + den->lineheight * 128;
		den->texy = ((d * den->texheight) / den->lineheight) / 256;
		if (den->stepx < 0)
			drow_wall_teh(den, 0);
		else
			drow_wall_teh(den, 1);
		if (den->side == 1)
		{
			if (den->stepy < 0)
				drow_wall_teh(den, 2);
			else
				drow_wall_teh(den, 3);
		}
		ft_create_img(den, den->x, y, den->color);
		y++;
	}
}
