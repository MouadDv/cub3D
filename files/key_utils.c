/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:03:27 by milmi             #+#    #+#             */
/*   Updated: 2021/01/11 11:05:15 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		nextposallowed(float newplayerx, float newplayery)
{
	int	gridx;
	int	gridy;

	if (newplayerx < 0 || newplayerx > g_consts.mw
		|| newplayery < 0 || newplayery > g_consts.mh)
		return (1);
	gridx = floor(newplayerx / g_consts.ts);
	gridy = floor(newplayery / g_consts.ts);
	return (g_cubedata.mapgrid[gridy][gridx]);
}

int		update(void)
{
	key_manager();
	render_rays();
	render_sprites();
	mlx_put_image_to_window(g_data.mlx_ptr, g_data.mlx_win, g_img.img, 0, 0);
	return (0);
}

int		ft_keyrelease(int keycode)
{
	if (keycode == KEY_RIGHT)
		g_player.turndirection = 0;
	if (keycode == KEY_LEFT)
		g_player.turndirection = 0;
	if (keycode == KEY_W)
		g_player.walkdirection = 0;
	if (keycode == KEY_S)
		g_player.walkdirection = 0;
	if (keycode == KEY_A)
		g_player.strafedirection = 0;
	if (keycode == KEY_D)
		g_player.strafedirection = 0;
	return (1);
}

int		ft_keypressed(int keycode)
{
	if (keycode == KEY_RIGHT)
		g_player.turndirection = 1;
	if (keycode == KEY_LEFT)
		g_player.turndirection = -1;
	if (keycode == KEY_W)
		g_player.walkdirection = -1;
	if (keycode == KEY_S)
		g_player.walkdirection = 1;
	if (keycode == KEY_A)
		g_player.strafedirection = 1;
	if (keycode == KEY_D)
		g_player.strafedirection = -1;
	if (keycode == KEY_ESC)
		ft_esc();
	return (0);
}
