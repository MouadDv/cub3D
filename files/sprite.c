/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:09:04 by milmi             #+#    #+#             */
/*   Updated: 2021/01/17 14:45:56 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_spriteray(float tilex, float sh, int raynbr, int nbrofrays)
{
	int				i;
	unsigned	int	color;
	float			tiley;

	i = 0;
	if (tilex >= 0 && tilex < g_consts.ww)
	{
		tiley = (g_consts.wh / 2) - (sh / 2);
		if (sh > g_consts.wh)
			i = (sh / 2) - (g_consts.wh / 2);
		while (i < sh)
		{
			color = ft_read_from_memory_sprite(g_spriteimg,
			(g_spriteimg.texturew * raynbr) / nbrofrays,
			(g_spriteimg.textureh * i) / sh);
			if (color != 0)
				my_mlx_pixel_put(tilex, tiley + i, color);
			if (tiley + i >= g_consts.wh)
				break ;
			i++;
		}
	}
}

void	ft_spriteray(float rayangle, float sprtang, float spritedist, int tilex)
{
	float	correctdist;
	float	distanceprojectionplane;
	float	wallstripheight;
	float	stripheight;

	sprtang = fmod(sprtang, 2 * PI);
	if (sprtang < 0)
		sprtang = (2 * PI);
	correctdist = spritedist / cos(fabs(rayangle - sprtang));
	while (g_sprt.i < g_sprt.nbrofrays)
	{
		distanceprojectionplane = (g_consts.mw / 2) / tan(g_consts.fa / 2);
		wallstripheight = (g_consts.ts / correctdist) * distanceprojectionplane;
		stripheight = (wallstripheight * g_consts.ww) / g_consts.mw;
		if (g_raydistance[tilex] > spritedist)
			draw_spriteray(tilex, stripheight, g_sprt.i, g_sprt.nbrofrays);
		g_sprt.i++;
		tilex++;
		rayangle += g_consts.ai;
	}
}

void	sprite_norm(float *rayangle, float *lastray, float sa, int spritenbr)
{
	float	xa;
	float	ya;

	xa = g_sprites.data[spritenbr][0] - cos(sa - 90 *
	(PI / 180)) * (g_consts.ts / 2);
	ya = g_sprites.data[spritenbr][1] - sin(sa - 90 *
	(PI / 180)) * (g_consts.ts / 2);
	*rayangle = atan2(g_player.y - ya, g_player.x - xa);
	*rayangle = ft_fmodangle(*rayangle);
	xa = g_sprites.data[spritenbr][0] - cos(sa + 90 *
	(PI / 180)) * (g_consts.ts / 2);
	ya = g_sprites.data[spritenbr][1] - sin(sa + 90 *
	(PI / 180)) * (g_consts.ts / 2);
	*lastray = atan2(g_player.y - ya, g_player.x - xa);
	*lastray = fmod(*lastray, 2 * PI);
	if (*lastray < 0)
		*lastray = (2 * PI) + *lastray;
	if (*lastray < *rayangle)
		*lastray += 2 * PI;
	g_sprt.i = 0;
	g_sprt.tilex = -1;
	g_sprt.nbrofrays = fabs(g_sprt.rayangle - g_sprt.lastray) / g_consts.ai;
	g_sprt.fovs = g_player.rotationangle - (g_consts.fa / 2);
}

void	sprite(float spriteangle, float spritedist, int spritenbr)
{
	sprite_norm(&g_sprt.rayangle, &g_sprt.lastray, spriteangle, spritenbr);
	g_sprt.fovs = ft_fmodangle(g_sprt.fovs);
	while (g_sprt.rayangle < g_sprt.lastray)
	{
		g_sprt.rayangle = ft_fmodangle(g_sprt.rayangle);
		if (g_sprt.rayangle >= g_sprt.fovs
		&& g_sprt.rayangle <= g_sprt.fovs + g_consts.fa)
		{
			g_sprt.tilex = fabs(g_sprt.rayangle - g_sprt.fovs) / g_consts.ai;
			break ;
		}
		else if (g_sprt.fovs + g_consts.fa > 2 * PI
			&& g_sprt.rayangle <= fmod(g_sprt.fovs + g_consts.fa, 2 * PI))
		{
			g_sprt.tilex = g_consts.ww - (fabs(g_sprt.rayangle -
			fmod(g_sprt.fovs + g_consts.fa, 2 * PI)) / g_consts.ai);
			break ;
		}
		g_sprt.i++;
		g_sprt.rayangle += g_consts.ai;
	}
	if (g_sprt.tilex != -1)
		ft_spriteray(g_sprt.rayangle, spriteangle, spritedist, g_sprt.tilex);
}

void	render_sprites(void)
{
	int		i;
	float	spritedist;
	float	spriteangle;
	float	adj;
	float	opp;

	i = 0;
	if (g_sprites.nbr > 1)
		ft_sortsprites();
	while (i < g_sprites.nbr)
	{
		adj = g_player.x - g_sprites.data[i][0];
		opp = g_player.y - g_sprites.data[i][1];
		spriteangle = atan2(opp, adj);
		spritedist = sqrt((opp * opp) + (adj * adj));
		spriteangle = fmod(spriteangle, 2 * PI);
		if (spriteangle < 0)
			spriteangle = (2 * PI) + spriteangle;
		sprite(spriteangle, spritedist, i);
		i++;
	}
	free(g_raydistance);
}
