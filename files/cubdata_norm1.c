/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:27:17 by milmi             #+#    #+#             */
/*   Updated: 2021/01/17 14:45:50 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fillmap(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < g_cubedata.map_rows)
	{
		while (j < g_cubedata.map_cols)
		{
			g_cubedata.mapgrid[i][j] = 32;
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_gridreq(int x, int y)
{
	int l;

	l = 0;
	if ((g_cubedata.mapgrid = malloc(y * sizeof(int *))) == NULL)
		ft_error();
	add_to_list(g_cubedata.mapgrid);
	while (l++ < y)
	{
		if ((g_cubedata.mapgrid[l - 1] = malloc(x * sizeof(int))) == NULL)
			ft_error();
		add_to_list(g_cubedata.mapgrid[l - 1]);
	}
	l = 0;
	if (g_sprites.nbr > 0)
	{
		if ((g_sprites.data = malloc(g_sprites.nbr * sizeof(float *))) == NULL)
			ft_error();
		add_to_list(g_sprites.data);
		while (l++ < g_sprites.nbr)
		{
			if ((g_sprites.data[l - 1] = malloc(2 * sizeof(float))) == NULL)
				ft_error();
			add_to_list(g_sprites.data[l - 1]);
		}
	}
}

void	playerdata(char *map, int i, int j, int k)
{
	g_cubedata.playeri = i;
	g_cubedata.playerj = j;
	g_cubedata.playerdirection = map[k];
	g_cubedata.mapgrid[i][j] = 0;
}

int		ft_mapgridnorm(char *map, int *s, int *k, int i)
{
	int j;

	j = 0;
	while (map[*k] != '\0' && map[*k] != '\n')
	{
		if (map[*k] == '2')
		{
			g_sprites.data[*s][0] = (64 * j) + (32);
			g_sprites.data[*s][1] = (64 * i) + (32);
			*s = *s + 1;
			g_cubedata.mapgrid[i][j] = 2;
		}
		else if ((map[*k] == 'N' || map[*k] == 'S' || map[*k] == 'W'
					|| map[*k] == 'E') && g_cubedata.playerdirection == -1)
			playerdata(map, i, j, *k);
		else if (map[*k] == '0' || map[*k] == '1')
			g_cubedata.mapgrid[i][j] = map[*k] - '0';
		else if (map[*k] == ' ')
			g_cubedata.mapgrid[i][j] = ' ';
		else
			return (seterrno(-100));
		j++;
		*k = *k + 1;
	}
	return (1);
}

int		ft_mapgridinit(char *map, int x, int y)
{
	int	s;
	int	i;
	int	k;

	g_cubedata.map_cols = x;
	g_cubedata.map_rows = y;
	init_gridreq(x, y);
	ft_fillmap();
	k = 0;
	s = 0;
	i = 0;
	while (i < y)
	{
		if (ft_mapgridnorm(map, &s, &k, i) == -1)
			return (-1);
		k++;
		i++;
	}
	return (1);
}
