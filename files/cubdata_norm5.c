/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:47:06 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 08:52:53 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		checkceil_norm(char *str, int *i)
{
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] >= '0' && str[*i] <= '9')
		g_colornorm.red = ft_atoi(str + *i);
	else
		return (-10);
	if (g_colornorm.red < 0 || g_colornorm.red > 255)
		return (-10);
	while (str[*i] != '\0' && (str[*i] >= '0' && str[*i] <= '9'))
		*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	if (str[*i] != ',')
		return (-10);
	*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	g_colornorm.green = ft_atoi(str + *i);
	if (g_colornorm.green < 0 || g_colornorm.green > 255)
		return (-10);
	while (str[*i] != '\0' && (str[*i] >= '0' && str[*i] <= '9'))
		*i = *i + 1;
	while (str[*i] != '\0' && str[*i] == ' ')
		*i = *i + 1;
	return (1);
}

int		checkceil(char *str)
{
	int	i;
	int	ret;

	i = 2;
	if (str[0] == 'C' && str[1] == ' ' && g_cubedata.ceilcolor == -1)
	{
		if ((ret = checkceil_norm(str, &i)) < 0)
			return (ret);
		if (str[i] != ',' || str[i + 1] == '\0')
			return (-10);
		i++;
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_colornorm.blue = ft_atoi(str + i);
		if (g_colornorm.blue < 0 || g_colornorm.blue > 255)
			return (-10);
		while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == '\0')
			return ((g_cubedata.ceilcolor = (g_colornorm.red << 16)
			+ (g_colornorm.green << 8) + g_colornorm.blue));
			return (-10);
	}
	return (-2);
}

char	*ft_strformat(char *str)
{
	char	*tmp;

	tmp = ft_strtrim(str, " ");
	return (tmp);
}

int		check_vars(void)
{
	if (g_cubedata.rx == -1 || g_cubedata.ry == -1
	|| g_cubedata.northtexture == NULL || g_cubedata.southtexture == NULL
	|| g_cubedata.westtexture == NULL || g_cubedata.easttexture == NULL
	|| g_cubedata.spritetexture == NULL || g_cubedata.floorcolor == -1
	|| g_cubedata.ceilcolor == -1 || g_cubedata.playeri == -1
	|| g_cubedata.playerj == -1)
		return (-1);
	return (1);
}
