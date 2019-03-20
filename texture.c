/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:18:26 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:18:27 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_hero(t_wolf *den)
{
	if (den->hero == 1)
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
			den->tex[7], 586, 855);
	if (den->hero == 2)
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
			den->tex[12], 586, 855);
	if (den->hero == 3)
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
			den->tex[8], 586, 855);
	if (den->hero == 4)
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
			den->tex[9], 586, 855);
	if (den->hero == 5)
		mlx_put_image_to_window(den->mlx_ptr, den->win_ptr,
			den->tex[10], 586, 855);
}

void	load_texture_two(t_wolf *den, int x, int y)
{
	den->tex[7] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/1.xpm", &x, &y);
	if (den->tex[7] == 0)
		exit_eror(5);
	den->tex[8] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/3.xpm", &x, &y);
	if (den->tex[8] == 0)
		exit_eror(5);
	den->tex[9] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/4.xpm", &x, &y);
	if (den->tex[9] == 0)
		exit_eror(5);
	den->tex[10] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/5.xpm", &x, &y);
	if (den->tex[10] == 0)
		exit_eror(5);
	den->tex[11] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/s.xpm", &x, &y);
	if (den->tex[11] == 0)
		exit_eror(5);
	den->tex[12] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/2.xpm", &x, &y);
	if (den->tex[12] == 0)
		exit_eror(5);
	den->tex[13] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/z.xpm", &x, &y);
	if (den->tex[13] == 0)
		exit_eror(5);
}

void	load_texture_help(t_wolf *den, int x, int y)
{
	den->tex[0] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/wo.xpm", &x, &y);
	if (den->tex[0] == 0)
		exit_eror(5);
	den->tex[1] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/re.xpm", &x, &y);
	if (den->tex[1] == 0)
		exit_eror(5);
	den->tex[2] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/gr.xpm", &x, &y);
	if (den->tex[2] == 0)
		exit_eror(5);
	den->tex[3] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/co.xpm", &x, &y);
	if (den->tex[3] == 0)
		exit_eror(5);
	den->tex[4] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/gl.xpm", &x, &y);
	if (den->tex[4] == 0)
		exit_eror(5);
	den->tex[5] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/12.xpm", &x, &y);
	if (den->tex[5] == 0)
		exit_eror(5);
	den->tex[6] = mlx_xpm_file_to_image(den->mlx_ptr, "texture/24.xpm", &x, &y);
	if (den->tex[6] == 0)
		exit_eror(5);
	load_texture_two(den, x, y);
}

void	load_texture(t_wolf *den)
{
	t_tex	d;
	int		y;
	int		x;
	int		i;

	i = 0;
	y = 64;
	x = 64;
	den->texwidth = 64;
	den->texheight = 64;
	load_texture_help(den, x, y);
	while (i < 6)
	{
		d.e[i] = 1;
		d.p[i] = 5;
		d.s[i] = 1;
		i++;
	}
	den->text[0] = mlx_get_data_addr(den->tex[0], &d.p[0], &d.s[0], &d.e[0]);
	den->text[1] = mlx_get_data_addr(den->tex[1], &d.p[1], &d.s[1], &d.e[1]);
	den->text[2] = mlx_get_data_addr(den->tex[2], &d.p[2], &d.s[2], &d.e[2]);
	den->text[3] = mlx_get_data_addr(den->tex[3], &d.p[3], &d.s[3], &d.e[3]);
	den->text[4] = mlx_get_data_addr(den->tex[4], &d.p[4], &d.s[4], &d.e[4]);
}
