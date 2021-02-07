/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:14:02 by milmi             #+#    #+#             */
/*   Updated: 2021/01/14 16:19:11 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_nextvertnorm(float nvtx, float nvty)
{
	if (iswall(nvtx, nvty) == 1)
	{
		g_wallhit.verticalwallhitx = nvtx;
		g_wallhit.verticalwallhity = nvty;
		if (g_pos.angleisleft)
			g_wallhit.verticalwallhitx++;
		return (1);
	}
	return (0);
}

int		ft_nextvertinter(void)
{
	float	xstep;
	float	ystep;
	float	nvtx;
	float	nvty;

	nvtx = floor(g_player.x / g_consts.ts) * g_consts.ts;
	nvtx += g_pos.angleisright ? g_consts.ts : 0;
	nvty = g_player.y + (nvtx - g_player.x) * tan(g_ray.angel);
	xstep = g_consts.ts;
	xstep *= g_pos.angleisleft ? -1 : 1;
	ystep = g_consts.ts * tan(g_ray.angel);
	ystep *= (g_pos.angleisup && ystep > 0) ? -1 : 1;
	ystep *= (g_pos.angleisdown && ystep < 0) ? -1 : 1;
	nvtx -= (g_pos.angleisleft) ? 1 : 0;
	while (nvtx >= 0 && nvtx < g_consts.mw && nvty >= 0 && nvty < g_consts.mh)
	{
		if (ft_nextvertnorm(nvtx, nvty) == 1)
			return (1);
		else
		{
			nvtx += xstep;
			nvty += ystep;
		}
	}
	return (0);
}

void	putray_norm(void)
{
	if (g_wallhit.verthitdistance <= g_wallhit.horzhitdistance)
	{
		g_wallhit.distance = g_wallhit.verthitdistance;
		g_wallhit.wallhitx = g_wallhit.verticalwallhitx;
		g_wallhit.wallhity = g_wallhit.verticalwallhity;
	}
	else
	{
		g_wallhit.distance = g_wallhit.horzhitdistance;
		g_wallhit.wallhitx = g_wallhit.horizwallhitx;
		g_wallhit.wallhity = g_wallhit.horizwallhity;
	}
}

float	putray(float angle)
{
	g_ray.angel = angle;
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	checkangle(angle);
	g_wallhit.horzhitdistance = (ft_nexthorztinter())
	? sqrt((g_wallhit.horizwallhitx - g_player.x) *
	(g_wallhit.horizwallhitx - g_player.x) +
	(g_wallhit.horizwallhity - g_player.y) *
	(g_wallhit.horizwallhity - g_player.y)) : MAX_VALUE;
	g_wallhit.verthitdistance = (ft_nextvertinter())
	? sqrt((g_wallhit.verticalwallhitx - g_player.x) *
	(g_wallhit.verticalwallhitx - g_player.x) +
	(g_wallhit.verticalwallhity - g_player.y) *
	(g_wallhit.verticalwallhity - g_player.y)) : MAX_VALUE;
	putray_norm();
	ray_texture(g_wallhit.wallhitx, g_wallhit.wallhity);
	return (g_wallhit.distance);
}

void	render_rays(void)
{
	int		i;

	i = 0;
	g_ray.ray_lenght = 0;
	g_ray.first_ray_ang = g_player.rotationangle - (g_consts.fa / 2);
	g_ray.last_ray_ang = g_player.rotationangle + (g_consts.fa / 2);
	if ((g_raydistance = malloc(sizeof(float) * g_consts.nofr)) == NULL)
		ft_error();
	while (i < g_consts.nofr)
	{
		g_ray.ray_lenght = putray(g_ray.first_ray_ang);
		g_ray.correctdist = g_ray.ray_lenght
		* cos(fabs(g_ray.first_ray_ang - g_player.rotationangle));
		g_ray.distanceprojectionplane = (g_consts.mw / 2)
		/ tan(g_consts.fa / 2);
		g_ray.wallstripheight = (g_consts.ts / g_ray.correctdist)
		* g_ray.distanceprojectionplane;
		g_ray.stripheight = (g_ray.wallstripheight * g_consts.ww) / g_consts.mw;
		draw_wall(i, (g_consts.wh / 2) - (g_ray.stripheight / 2),
		g_ray.stripheight);
		g_ray.first_ray_ang += g_consts.ai;
		g_raydistance[i] = g_ray.ray_lenght;
		i++;
	}
}
