/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:04:36 by milmi             #+#    #+#             */
/*   Updated: 2021/01/11 11:05:11 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_backward_forward(int walkdirection)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = walkdirection * g_player.movespeed;
	newplayerx = g_player.x + cos(g_player.rotationangle) * movestep;
	newplayery = g_player.y + sin(g_player.rotationangle) * movestep;
	if (nextposallowed(newplayerx, newplayery) == 0)
	{
		g_player.x = newplayerx;
		g_player.y = newplayery;
	}
}

void	ft_strafe(int strafedirection)
{
	float	movingangle;
	float	newplayerx;
	float	newplayery;

	movingangle = g_player.rotationangle + (0.5 * PI * strafedirection);
	newplayerx = g_player.x + cos(movingangle) * g_player.movespeed;
	newplayery = g_player.y + sin(movingangle) * g_player.movespeed;
	if (nextposallowed(newplayerx, newplayery) == 0)
	{
		g_player.x = newplayerx;
		g_player.y = newplayery;
	}
}

void	ft_rotate(int turndirection)
{
	if (turndirection == 1)
		g_player.rotationangle += g_player.rotationspeed;
	else	if (turndirection == -1)
		g_player.rotationangle -= g_player.rotationspeed;
}

int		ft_esc(void)
{
	free_list();
	mlx_destroy_image(g_data.mlx_ptr, g_img.img);
	mlx_destroy_window(g_data.mlx_ptr, g_data.mlx_win);
	exit(0);
	return (0);
}

int		key_manager(void)
{
	if (g_player.turndirection != 0)
		ft_rotate(g_player.turndirection);
	if (g_player.walkdirection != 0)
		ft_move_backward_forward(g_player.walkdirection);
	if (g_player.strafedirection != 0)
		ft_strafe(g_player.strafedirection);
	return (0);
}
