/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:06:13 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/30 20:01:06 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	makewolf(t_wolf *den)
{
	den->line = 0;
	if (readeng(den) == -1)
	{
		ft_putendl("Error map");
		return ;
	}
	check_map(den);
	den->mlx_ptr = mlx_init();
	den->win_ptr = mlx_new_window(den->mlx_ptr, WIDTH, HEIGHT, "Wolf_3D");
	plaer_option(den);
	find_img_addr(den);
	load_texture(den);
	raycasting(den);
	mlx_hook(den->win_ptr, 6, 1L << 7, mouse_hints, den);
	mlx_hook(den->win_ptr, 17, 1L << 17, exit_x, den);
	mlx_hook(den->win_ptr, 2, 0, key_p, den);
	mlx_hook(den->win_ptr, 3, 0, key_liv, den);
	mlx_mouse_hook(den->win_ptr, mouse_fight, den);
	signal(SIGINT, exit_s);
	mlx_loop_hook(den->mlx_ptr, action, den);
	mlx_loop(den->mlx_ptr);
}

int		get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (-1);
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd > 0)
			return (fd);
		else
			return (-1);
	}
}

int		main(int argc, char **argv)
{
	t_wolf	den;

	if (argc == 2)
	{
		den.name = argv[1];
		den.fd = get_fd(den.name);
		if (den.fd > 0)
			makewolf(&den);
	}
	else
		ft_putendl("usage: ./wolf3d map file min 5 x 5,"
			"digit 0,1,2,3,4 written in space\n"
		"                   example:\n"
		"                   1 1 1 1 1\n"
		"                   1 0 0 0 1\n"
		"                   1 0 0 0 1\n"
		"                   1 0 0 0 1\n"
		"                   1 1 1 1 1");
	return (0);
}
