/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:20:13 by milmi             #+#    #+#             */
/*   Updated: 2021/01/12 10:21:22 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_nexthorztnorm(float nhtx, float nhty)
{
	if (iswall(nhtx, nhty) == 1)
	{
		g_wallhit.horizwallhitx = nhtx;
		g_wallhit.horizwallhity = nhty;
		if (g_pos.angleisup)
			g_wallhit.horizwallhity++;
		return (1);
	}
	return (0);
}

int		ft_nexthorztinter(void)
{
	float	xstep;
	float	ystep;
	float	nhty;
	float	nhtx;

	nhty = floor(g_player.y / g_consts.ts) * g_consts.ts;
	nhty += g_pos.angleisdown ? g_consts.ts : 0;
	nhtx = g_player.x + (nhty - g_player.y) / tan(g_ray.angel);
	ystep = g_consts.ts;
	ystep *= g_pos.angleisup ? -1 : 1;
	xstep = g_consts.ts / tan(g_ray.angel);
	xstep *= (g_pos.angleisleft && xstep > 0) ? -1 : 1;
	xstep *= (g_pos.angleisright && xstep < 0) ? -1 : 1;
	nhty -= (g_pos.angleisup) ? 1 : 0;
	while (nhtx >= 0 && nhtx < g_consts.mw && nhty >= 0 && nhty < g_consts.mh)
	{
		if (ft_nexthorztnorm(nhtx, nhty) == 1)
			return (1);
		else
		{
			nhtx += xstep;
			nhty += ystep;
		}
	}
	return (0);
}

void	draw_wall(int tilex, int tiley, int height)
{
	unsigned int	color;
	int				j;

	j = 0;
	if (tilex >= 0 && tilex < g_consts.ww)
	{
		while (j < g_consts.wh)
		{
			if (j < tiley)
				color = g_cubedata.ceilcolor;
			else if (j < height + tiley)
				color = ft_read_from_memory(g_texture[g_ray.texturenum],
				(g_texture[g_ray.texturenum].texturew * g_ray.textureoffset)
				/ g_consts.ts, (g_texture[g_ray.texturenum].textureh *
				(j - tiley)) / height);
			else
				color = g_cubedata.floorcolor;
			my_mlx_pixel_put(tilex, j, color);
			j++;
		}
	}
}
