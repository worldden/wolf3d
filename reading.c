/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:18:10 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/08/04 16:18:12 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		valid_line(char *line)
{
	char	**tab;
	int		i;
	int		k;
	int		r;

	tab = ft_strsplit(line, ' ');
	i = 0;
	k = 0;
	r = 0;
	while (tab[i])
	{
		if ((tab[i][0] != '0' && tab[i][0] != '1' && tab[i][0] != '2'
			&& tab[i][0] != '3' && tab[i][0] != '4') || tab[i][1] != '\0')
			r = 1;
		i++;
	}
	k = i;
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
	if (r == 1)
		return (exit_eror(4));
	return (k);
}

void	readeng_help(t_read *rd, t_wolf *den)
{
	den->map[rd->j][rd->k] = ft_atoi(rd->tab[rd->k]);
	free(rd->tab[rd->k]);
	if (den->line > 100 || den->width > 100)
		exit_eror(3);
}

int		valid(t_wolf *den)
{
	char	*line;
	int		i;
	int		k;

	k = 0;
	while (get_next_line(den->fd, &line) == 1)
	{
		i = valid_line(line);
		if (i < 5)
			k = 1;
		if (den->width == 0)
			den->width = i;
		if (den->width != i)
			k = 1;
		den->line += 1;
		free(line);
		line = NULL;
	}
	den->width = i;
	den->map = (int **)malloc(sizeof(int *) * (den->line));
	close(den->fd);
	den->fd = open(den->name, O_RDONLY);
	if (den->line < 5 || k == 1)
		return (0);
	return (1);
}

int		readeng(t_wolf *den)
{
	t_read	rd;

	rd.i = 0;
	rd.j = 0;
	den->width = 0;
	if (valid(den) != 0)
	{
		while (get_next_line(den->fd, &rd.line))
		{
			rd.tab = ft_strsplit(rd.line, ' ');
			den->map[rd.j] = (int *)malloc(sizeof(int) * (den->width));
			rd.k = 0;
			while (rd.k < den->width)
			{
				readeng_help(&rd, den);
				rd.k++;
			}
			rd.j++;
			free(rd.tab);
			free(rd.line);
			rd.line = NULL;
		}
		return (0);
	}
	return (-1);
}
