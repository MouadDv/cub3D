/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:14:38 by milmi             #+#    #+#             */
/*   Updated: 2021/01/25 09:26:25 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files/cub3d.h"

void	free_list(void)
{
	t_free	*temp;

	temp = g_head;
	while (g_head)
	{
		free(g_head->adr);
		g_head = g_head->next;
	}
	g_head = temp;
	while (temp)
	{
		temp = temp->next;
		free(g_head);
		g_head = temp;
	}
	free(g_head);
}

void	add_to_list(void *adr)
{
	t_free	*temp;

	if ((temp = malloc(sizeof(t_free))) != NULL)
	{
		g_freelist->adr = adr;
		g_freelist->next = temp;
		temp->next = NULL;
		g_freelist = temp;
	}
	else
		ft_error();
}

void	ft_errorn(void)
{
	if (g_myerrno == -8)
		write(2, "Invalid S texture", 17);
	else if (g_myerrno == -9)
		write(2, "Invalid floor color", 19);
	else if (g_myerrno == -10)
		write(2, "Invalid ceil color", 18);
	else if (g_myerrno == -50)
		write(2, "Map should be the last element in the cub file", 46);
	else if (g_myerrno == -100)
		write(2, "Invalid map", 11);
	else if (g_myerrno == -200)
		write(2, "Invalid file extencion (.cub)", 29);
	else if (g_myerrno == -2000)
		write(2, "Invalid argument!", 17);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	if (g_myerrno == 0)
		perror("");
	else if (g_myerrno == -1)
		write(2, "Uncompleted cub file", 20);
	else if (g_myerrno == -2)
		write(2, "Invalid Information", 19);
	else if (g_myerrno == -3)
		write(2, "Invalid resolution", 18);
	else if (g_myerrno == -4)
		write(2, "Invalid NO texture", 18);
	else if (g_myerrno == -5)
		write(2, "Invalid WE texture", 18);
	else if (g_myerrno == -6)
		write(2, "Invalid EA texture", 18);
	else if (g_myerrno == -7)
		write(2, "Invalid SO texture", 18);
	else
		ft_errorn();
	exit(0);
}

int		main(int argc, char **argv)
{
	g_myerrno = 0;
	if (argc > 3)
		write(2, "Error\nInvalid argument", 22);
	else if (argc == 3)
	{
		if (ft_save(argv) < 0)
			ft_error();
	}
	else if (argc == 2)
	{
		if ((g_freelist = malloc(sizeof(t_free))) == NULL)
			ft_error();
		g_head = g_freelist;
		if (ft_cubdata(argv[1]) == -1)
			ft_error();
		init_consts();
		init_player();
		if (!my_mlx_init() || texture_init() == -1 || sprite_init() == -1)
			ft_error();
		mlx_hook(g_data.mlx_win, 2, 1L << 0, ft_keypressed, 0);
		mlx_hook(g_data.mlx_win, 3, 1 << 1, ft_keyrelease, 0);
		mlx_hook(g_data.mlx_win, 17, 0, ft_esc, 0);
		mlx_loop_hook(g_data.mlx_ptr, update, 0);
		mlx_loop(g_data.mlx_ptr);
	}
}
