/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:06:49 by milmi             #+#    #+#             */
/*   Updated: 2021/01/13 10:40:49 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_swap_sprites(int i)
{
	float	temp;

	if (i + 1 < g_sprites.nbr)
	{
		temp = g_sprites.data[i][0];
		g_sprites.data[i][0] = g_sprites.data[i + 1][0];
		g_sprites.data[i + 1][0] = temp;
		temp = g_sprites.data[i][1];
		g_sprites.data[i][1] = g_sprites.data[i + 1][1];
		g_sprites.data[i + 1][1] = temp;
	}
}

unsigned	int	ft_read_from_memory_sprite(t_spriteimg texture, int x, int y)
{
	char	*dst;

	if (x >= 0 && x < texture.texturew && y >= 0 && y < texture.textureh)
	{
		dst = texture.addr + (y * texture.line_length
		+ x * (texture.bits_per_pixel / 8));
		return (*(unsigned int*)dst);
	}
	return (0);
}
