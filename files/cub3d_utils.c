/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 08:13:46 by milmi             #+#    #+#             */
/*   Updated: 2021/01/11 08:18:12 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned	int	ft_read_from_memory(t_texture_data texture, int x, int y)
{
	char	*dst;

	dst = texture.addr + (y * texture.line_length
			+ x * (texture.bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void			my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < g_consts.ww && y >= 0 && y < g_consts.wh)
	{
		dst = g_img.addr + (y * g_img.ll + x * (g_img.bpp / 8));
		*(unsigned int*)dst = color;
	}
}
