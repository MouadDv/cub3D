/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubdata_norm3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:36:01 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 08:48:52 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		seterrno(int err)
{
	g_myerrno = err;
	return (-1);
}

int		checkextenxion(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '.')
			break ;
		i--;
	}
	i++;
	if (ft_strncmp(str + i, "xpm", 3) == 0 && str[i + 3] == '\0')
		return (1);
	else if (ft_strncmp(str + i, "XPM", 3) == 0 && str[i + 3] == '\0')
		return (1);
	return (0);
}

int		checkresolution(char *str)
{
	int i;

	i = 2;
	if (str[1] == ' ' && g_cubedata.rx == -1 && g_cubedata.ry == -1)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if ((g_cubedata.rx = ft_res(str + i)) <= 0)
			return (-3);
		while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == '\0')
			return (-3);
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if ((g_cubedata.ry = ft_res(str + i)) <= 0)
			return (-3);
		while ((str[i] != '\0' && str[i] >= '0' && str[i] <= '9'))
			i++;
		if (str[i] == '\0')
			return (1);
		return (-3);
	}
	return (-2);
}

int		checknotexture(char *str)
{
	int	i;

	i = 3;
	if (str[0] == 'N' && str[1] == 'O' &&
		str[2] == ' ' && g_cubedata.northtexture == NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_cubedata.northtexture = ft_substr_cub(str, i, ft_strlen(str + i));
		if (!g_cubedata.northtexture)
			return (-4);
		add_to_list(g_cubedata.northtexture);
		if (checkextenxion(str) == 0)
			return (-4);
		return (1);
	}
	return (-2);
}

int		checkwetexture(char *str)
{
	int i;

	i = 3;
	if (str[0] == 'W' && str[1] == 'E' &&
		str[2] == ' ' && g_cubedata.westtexture == NULL)
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		g_cubedata.westtexture = ft_substr_cub(str, i, ft_strlen(str + i));
		if (!g_cubedata.westtexture)
			return (-5);
		add_to_list(g_cubedata.westtexture);
		if (checkextenxion(str) == 0)
			return (-5);
		return (1);
	}
	return (-2);
}
