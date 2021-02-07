/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:24:32 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 09:32:10 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_save(char **flag)
{
	if (ft_strncmp(flag[2], "--save", 7))
		return (seterrno(-2000));
	if ((g_freelist = malloc(sizeof(t_free))) == NULL)
		ft_error();
	g_head = g_freelist;
	if (ft_cubdata(flag[1]) == -1)
		ft_error();
	init_consts();
	init_player();
	if (!my_mlx_init())
		ft_error();
	if (texture_init() == -1 || sprite_init() == -1)
		ft_error();
	update();
	write_bmp("image.bmp", g_img.addr);
	return (1);
}
