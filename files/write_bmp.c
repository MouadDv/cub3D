/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:22:22 by milmi             #+#    #+#             */
/*   Updated: 2021/01/22 19:09:48 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_info_header(int filesize)
{
	g_bmp.header[0] = filesize + 54;
	g_bmp.header[1] = 0;
	g_bmp.header[2] = 0x36;
	g_bmp.header[3] = 0x28;
	g_bmp.header[4] = g_consts.ww;
	g_bmp.header[5] = g_consts.wh;
	g_bmp.header[6] = 0x200001;
	g_bmp.header[7] = 0;
	g_bmp.header[8] = 0;
	g_bmp.header[9] = 0;
	g_bmp.header[10] = 0;
	g_bmp.header[11] = 0;
	g_bmp.header[12] = 0;
}

void	init_bmp(void)
{
	int k;

	k = 0;
	g_bmp.bitmap = (char *)malloc(g_bmp.bitmap_size * sizeof(char));
	if (g_bmp.bitmap == NULL)
		ft_error();
	add_to_list(g_bmp.bitmap);
	while (k < g_bmp.bitmap_size)
	{
		g_bmp.bitmap[k] = 0;
		k++;
	}
}

void	rempli_bmp(char **rgb)
{
	int		i;
	int		j;
	int		l;
	char	*rgb1;

	i = 0;
	l = 0;
	rgb1 = *rgb;
	j = g_consts.wh - 1;
	while (j >= 0)
	{
		while (i < g_consts.ww)
		{
			g_bmp.dest = ((l * (g_consts.ww * 4) + i * 4));
			g_bmp.src = ((j * g_img.ll + i * (g_img.bpp / 8)));
			g_bmp.bitmap[g_bmp.dest] = rgb1[g_bmp.src];
			g_bmp.bitmap[g_bmp.dest + 1] = rgb1[g_bmp.src + 1];
			g_bmp.bitmap[g_bmp.dest + 2] = rgb1[g_bmp.src + 2];
			g_bmp.bitmap[g_bmp.dest + 3] = rgb1[g_bmp.src + 3];
			i++;
		}
		i = 0;
		j--;
		l++;
	}
}

void	write_bmp(char *filename, char *rgb)
{
	int	i;
	int	j;
	int	l;
	int fd;

	i = 0;
	j = 0;
	l = 0;
	g_bmp.tag[0] = 'B';
	g_bmp.tag[1] = 'M';
	g_bmp.bitmap_size = g_consts.ww * g_consts.wh * 4;
	bmp_info_header(g_bmp.bitmap_size);
	init_bmp();
	rempli_bmp(&rgb);
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write(fd, g_bmp.tag, 2);
	write(fd, g_bmp.header, sizeof(g_bmp.header));
	write(fd, g_bmp.bitmap, g_bmp.bitmap_size * sizeof(char));
}
