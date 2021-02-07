/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:57:42 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 09:12:16 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_consts(void)
{
	int	x;
	int	y;

	g_consts.ts = 64;
	g_consts.mnr = g_cubedata.map_rows;
	g_consts.mnc = g_cubedata.map_cols;
	mlx_get_screen_size(g_data.mlx_ptr, &x, &y);
	g_consts.ww = g_cubedata.rx;
	g_consts.wh = g_cubedata.ry;
	if (g_consts.ww > x)
		g_consts.ww = x;
	if (g_consts.wh > y)
		g_consts.wh = y;
	g_consts.mw = g_consts.mnc * g_consts.ts;
	g_consts.mh = g_consts.mnr * g_consts.ts;
	g_consts.nofr = g_consts.ww;
	g_consts.fa = 60 * (PI / 180);
	g_consts.ai = g_consts.fa / g_consts.nofr;
}

void	init_player(void)
{
	g_player.x = (g_cubedata.playerj * g_consts.ts) + (g_consts.ts / 2);
	g_player.y = (g_cubedata.playeri * g_consts.ts) + (g_consts.ts / 2);
	g_player.rotationangle = ft_angle(g_cubedata.playerdirection);
	g_player.movespeed = 10;
	g_player.rotationspeed = 6 * (PI / 180);
}

int		texture_init(void)
{
	g_texture[0].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_cubedata
.westtexture, &g_texture[0].texturew, &g_texture[0].textureh);
	if (g_texture[0].img == NULL)
		return (-1);
	g_texture[0].addr = mlx_get_data_addr(g_texture[0].img, &g_texture[0]
.bits_per_pixel, &g_texture[0].line_length, &g_texture[0].endian);
	g_texture[1].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_cubedata
.northtexture, &g_texture[1].texturew, &g_texture[1].textureh);
	if (g_texture[1].img == NULL)
		return (-1);
	g_texture[1].addr = mlx_get_data_addr(g_texture[1].img, &g_texture[1]
.bits_per_pixel, &g_texture[1].line_length, &g_texture[1].endian);
	g_texture[2].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_cubedata
.easttexture, &g_texture[2].texturew, &g_texture[2].textureh);
	if (g_texture[2].img == NULL)
		return (-1);
	g_texture[2].addr = mlx_get_data_addr(g_texture[2].img, &g_texture[2]
.bits_per_pixel, &g_texture[2].line_length, &g_texture[2].endian);
	g_texture[3].img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_cubedata
.southtexture, &g_texture[3].texturew, &g_texture[3].textureh);
	if (g_texture[3].img == NULL)
		return (-1);
	g_texture[3].addr = mlx_get_data_addr(g_texture[3].img, &g_texture[3]
.bits_per_pixel, &g_texture[3].line_length, &g_texture[3].endian);
	return (1);
}

int		my_mlx_init(void)
{
	if ((g_data.mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((g_data.mlx_win = mlx_new_window(g_data.mlx_ptr, g_consts.ww,
		g_consts.wh, "cub3D")) == NULL)
		return (0);
	g_img.img = mlx_new_image(g_data.mlx_ptr, g_consts.ww, g_consts.wh);
	if (g_img.img == NULL)
		return (-1);
	g_img.addr = mlx_get_data_addr(g_img.img, &g_img.bpp, &g_img.ll,
			&g_img.e);
	return (1);
}

int		sprite_init(void)
{
	g_spriteimg.img = mlx_xpm_file_to_image(g_data.mlx_ptr, g_cubedata
.spritetexture, &g_spriteimg.texturew, &g_spriteimg.textureh);
	if (g_spriteimg.img == NULL)
		return (-1);
	g_spriteimg.addr = mlx_get_data_addr(g_spriteimg.img, &g_spriteimg
.bits_per_pixel, &g_spriteimg.line_length, &g_spriteimg.endian);
	return (1);
}
