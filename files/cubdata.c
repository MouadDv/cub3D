/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:54:08 by milmi             #+#    #+#             */
/*   Updated: 2021/01/18 15:46:17 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_checkmap(void)
{
	int i;
	int j;
	int	**norm;

	i = 0;
	j = 0;
	norm = g_cubedata.mapgrid;
	while (i < g_cubedata.map_rows)
	{
		while (j < g_cubedata.map_cols)
		{
			if (g_cubedata.mapgrid[i][j] == 0 || g_cubedata.mapgrid[i][j] == 2)
				if (i == 0 || i == g_cubedata.map_rows - 1 || j == 0 ||
				j == g_cubedata.map_cols - 1 || norm[i - 1][j] == 32 ||
				norm[i][j - 1] == 32 || norm[i - 1][j - 1] == 32 ||
				norm[i + 1][j] == 32 || norm[i][j + 1] == 32 ||
				norm[i - 1][j + 1] == 32 || norm[i + 1][j - 1] == 32
				|| norm[i + 1][j + 1] == 32)
					return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		checkcubdata(int x, int y, int chek, int ret)
{
	if (x > 0 && y > 0)
		if (ft_mapgridinit(g_cubnorm.map, x, y) == 0)
			return (-1);
	if (chek < 0)
		return (seterrno(chek));
	if (ret < 0)
		return (seterrno(ret));
	if (check_vars() < 0)
		return (seterrno(-1));
	if (ft_checkmap() == 0)
		return (seterrno(-100));
	return (1);
}

int		int_req(char *fname)
{
	int	len;

	len = ft_strlen(fname);
	if (ft_strncmp(fname + (len - 4), ".cub", 4) != 0
	|| len <= 4 || fname[len - 5] == '/')
		return (seterrno(-200));
	if ((g_cubnorm.fd = open(fname, O_RDONLY)) < 0)
		return (-1);
	if (!(g_cubnorm.map = ft_calloc(1, sizeof(char))))
		ft_error();
	init_vars();
	return (1);
}

void	ft_map(char *str)
{
	if (g_cubnorm.chek == 10)
	{
		g_cubnorm.tmp = g_cubnorm.map;
		g_cubnorm.map = ft_mapjoin(g_cubnorm.map, str);
		add_to_list(g_cubnorm.tmp);
		g_sprites.nbr += ft_spritenbr(str);
		if (ft_strlen(str) > g_cubnorm.x)
			g_cubnorm.x = ft_strlen(str);
		g_cubnorm.y++;
	}
}

int		ft_cubdata(char *fname)
{
	char	*str;

	if (int_req(fname) < 0)
		return (-1);
	g_cubnorm.x = 0;
	g_cubnorm.y = 0;
	g_sprites.nbr = 0;
	while ((g_cubnorm.ret = get_next_line(g_cubnorm.fd, &str)) >= 0)
	{
		add_to_list(str);
		if ((g_cubnorm.chek = checkstrformat(str)) < 0)
			break ;
		if (g_cubnorm.y > 0 && g_cubnorm.chek != 10)
			return (seterrno(-50));
		ft_map(str);
		str = NULL;
		if (g_cubnorm.ret == 0)
			break ;
	}
	return (checkcubdata(g_cubnorm.x, g_cubnorm.y,
		g_cubnorm.chek, g_cubnorm.ret));
}
