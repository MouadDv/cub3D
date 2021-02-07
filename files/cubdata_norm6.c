/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:52:48 by milmi             #+#    #+#             */
/*   Updated: 2021/01/14 17:15:38 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkstrformat(char *str)
{
	char	*tmp;

	tmp = ft_strformat(str);
	add_to_list(tmp);
	if (tmp[0] == 'R')
		return (checkresolution(tmp));
	else if (tmp[0] == 'N' && tmp[1] == 'O')
		return (checknotexture(tmp));
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		return (checkwetexture(tmp));
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		return (checkeatexture(tmp));
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		return (checksotexture(tmp));
	else if (tmp[0] == 'S')
		return (checksptexture(tmp));
	else if (tmp[0] == 'F')
		return (checkfloor(tmp));
	else if (tmp[0] == 'C')
		return (checkceil(tmp));
	else if (str[0] == '\0')
		return (1);
	else if (str[0] == '1' || str[0] == ' ' || str[0] == '0')
		return (10);
	return (-6);
}

void	init_vars(void)
{
	g_cubedata.rx = -1;
	g_cubedata.ry = -1;
	g_cubedata.playeri = -1;
	g_cubedata.playerj = -1;
	g_cubedata.playerdirection = -1;
	g_cubedata.northtexture = NULL;
	g_cubedata.southtexture = NULL;
	g_cubedata.westtexture = NULL;
	g_cubedata.easttexture = NULL;
	g_cubedata.spritetexture = NULL;
	g_cubedata.floorcolor = -1;
	g_cubedata.ceilcolor = -1;
	g_cubedata.map_rows = -1;
	g_cubedata.map_cols = -1;
	g_cubedata.mapgrid = NULL;
}

int		ft_spritenbr(char *str)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '2')
			ret++;
		i++;
	}
	return (ret);
}

char	*ft_mapjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	k;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	k = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(ret = (char *)ft_calloc(j + k + 2, sizeof(char))))
		ft_error();
	j = 0;
	k = 0;
	while (s1[k] != '\0')
	{
		ret[k] = s1[k];
		k++;
	}
	while (s2[j] != '\0')
	{
		ret[k] = s2[j];
		j++;
		k++;
	}
	ret[k] = '\n';
	return (ret);
}

long	ft_res(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		i++;
		count++;
	}
	if (count > 4)
		return (100000);
	return (ft_atoi(str));
}
