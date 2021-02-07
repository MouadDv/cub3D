/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:54:16 by milmi             #+#    #+#             */
/*   Updated: 2021/01/14 16:58:34 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_fmodangle(float angle)
{
	angle = fmod(angle, 2 * PI);
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}

void	ft_sortsprites(void)
{
	int		i;
	float	temp;
	double	*dists;

	if ((dists = malloc(sizeof(double) * g_sprites.nbr)) == NULL)
		ft_error();
	i = 0;
	while (i++ < g_sprites.nbr)
		dists[i - 1] = sqrt(((g_player.y - g_sprites.data[i - 1][1])
		* (g_player.y - g_sprites.data[i - 1][1])) + ((g_player.x -
		g_sprites.data[i - 1][0]) * (g_player.x - g_sprites.data[i - 1][0])));
	i = 0;
	while (i + 1 < g_sprites.nbr)
	{
		if (dists[i] < dists[i + 1])
		{
			ft_swap_sprites(i);
			temp = dists[i];
			dists[i] = dists[i + 1];
			dists[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	free(dists);
}
