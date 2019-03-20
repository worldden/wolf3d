/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:51:23 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/31 18:51:25 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		deal_key(int key)
{
	if (key == 53)
	{
		system("killall afplay");
		exit(1);
	}
	return (0);
}

void	exit_s(int par)
{
	par = 0;
	system("killall afplay");
	exit(1);
}

int		exit_x(void *par)
{
	par = NULL;
	system("killall afplay");
	exit(1);
	return (0);
}

void	check_map(t_wolf *den)
{
	int eror;
	int i;
	int	j;

	i = 0;
	j = -1;
	eror = 0;
	while (++j < den->width)
	{
		if (den->map[i][j] == 0)
			eror = 1;
		if (den->map[(den->line - 1)][j] == 0)
			eror = 1;
	}
	j = 0;
	while (i < den->line)
	{
		if (den->map[i][j] == 0)
			eror = 1;
		if (den->map[i][(den->width - 1)] == 0)
			eror = 1;
		i++;
	}
	if (eror != 0)
		exit_eror(eror);
}

int		exit_eror(int eror)
{
	if (eror == 1)
	{
		ft_putendl("Error map, the map must be covered"
			"with walls from all sides");
	}
	if (eror == 2)
		ft_putendl("Error map, textura in position plaer (2, 2),"
			" and (2, 1), (1, 1), (1, 2) need bee '0' too!");
	if (eror == 3)
		ft_putendl("Error map, max map 100x100!");
	if (eror == 4)
		ft_putendl("Error map, wrong textures!");
	if (eror == 5)
		ft_putendl("texture error, texture not found!");
	system("say Error&");
	exit(1);
	return (0);
}
