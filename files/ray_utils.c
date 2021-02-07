/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:06:29 by milmi             #+#    #+#             */
/*   Updated: 2021/01/12 09:44:04 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		iswall(float x, float y)
{
	int	gridx;
	int	gridy;

	if (x < 0 || x > g_consts.mw || y < 0 || y > g_consts.mh)
		return (1);
	gridx = floor(x / g_consts.ts);
	gridy = floor(y / g_consts.ts);
	return (g_cubedata.mapgrid[gridy][gridx]);
}

void	checkangle(float angle)
{
	g_pos.angleisup = 0;
	g_pos.angleisleft = 0;
	g_pos.angleisdown = 0;
	g_pos.angleisright = 0;
	if (angle > 0 && angle < PI)
		g_pos.angleisup = 1;
	else
		g_pos.angleisdown = 1;
	if ((angle > 0 && angle < PI / 2) || (angle > 1.5 * PI && angle < 2 * PI))
		g_pos.angleisleft = 1;
	else
		g_pos.angleisright = 1;
}

void	ray_texture(float wallhitx, float wallhity)
{
	if (g_wallhit.verthitdistance <= g_wallhit.horzhitdistance)
	{
		if (wallhitx > g_player.x)
			g_ray.texturenum = 0;
		else
			g_ray.texturenum = 2;
		g_ray.textureoffset = ((int)wallhity % g_consts.ts);
	}
	else
	{
		if (wallhity > g_player.y)
			g_ray.texturenum = 1;
		else
			g_ray.texturenum = 3;
		g_ray.textureoffset = ((int)wallhitx % g_consts.ts);
	}
}
