/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 12:50:34 by milmi             #+#    #+#             */
/*   Updated: 2021/01/18 15:53:05 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../includes/GNL/get_next_line.h"

# define MAX_VALUE 2147483647

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
# define PI 3.14159

typedef	struct
{
	int			ts;
	int			mnr;
	int			mnc;
	int			ww;
	int			wh;
	int			mw;
	int			mh;
	int			rw;
	double		nofr;
	double		fa;
	double		ai;
}				t_consts;

typedef struct
{
	int			bpp;
	int			ll;
	int			e;
	void		*img;
	char		*addr;
}				t_data;

typedef struct
{
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			texturew;
	int			textureh;
	void		*img;
	char		*addr;
}				t_texture_data;

typedef struct
{
	int			angleisup;
	int			angleisleft;
	int			angleisdown;
	int			angleisright;
}				t_pos;

typedef struct	s_mlx
{
	void		*mlx_win;
	void		*mlx_ptr;
}				t_mlx;

typedef struct
{
	float		x;
	float		y;
	float		radius;
	float		strafedirection;
	float		turndirection;
	float		walkdirection;
	float		rotationangle;
	int			movespeed;
	float		rotationspeed;
}				t_player;

typedef struct
{
	float		verticalwallhitx;
	float		verticalwallhity;
	float		horizwallhitx;
	float		horizwallhity;
	float		wallhitx;
	float		wallhity;
	float		distance;
	float		horzhitdistance;
	float		verthitdistance;

}				t_wallhit;

typedef struct
{
	float		first_ray_ang;
	float		last_ray_ang;
	float		ray_lenght;
	float		distanceprojectionplane;
	int			wallstripheight;
	float		correctdist;
	float		angel;
	int			texturenum;
	int			textureoffset;
	int			stripheight;
}				t_ray;

typedef struct
{
	long		rx;
	long		ry;
	int			playeri;
	int			playerj;
	char		playerdirection;
	char		*northtexture;
	char		*southtexture;
	char		*westtexture;
	char		*easttexture;
	char		*spritetexture;
	int			floorcolor;
	int			ceilcolor;
	int			map_rows;
	int			map_cols;
	int			**mapgrid;
}				t_cubdata;

typedef struct
{
	int			nbr;
	float		**data;
	float		*dists;
	int			height;
}				t_sprites;

typedef struct
{
	long		red;
	long		green;
	long		blue;
}				t_colornorm;

typedef struct
{
	int			fd;
	int			ret;
	int			chek;
	size_t		x;
	size_t		y;
	char		*map;
	char		*tmp;
}				t_cubnorm;

typedef struct	s_free
{
	void			*adr;
	struct s_free	*next;
}				t_free;

typedef struct	{
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			texturew;
	int			textureh;
	void		*img;
	char		*addr;
}				t_spriteimg;

typedef struct	s_bmp_file{
	int		bitmap_size;
	char	tag[2];
	int		header[13];
	char	*bitmap;
	int		dest;
	int		src;
}				t_bmp_file;

typedef struct
{
	float		rayangle;
	float		lastray;
	float		fovs;
	float		tilex;
	int			nbrofrays;
	int			i;
}				t_sprite;

long			ft_res(char	*str);
void			ft_sortsprites(void);
float			ft_fmodangle(float angle);
void			add_to_list(void	*adr);
void			free_list(void);
void			ft_error(void);
int				ft_save(char	**flag);
void			init_consts(void);
void			init_player(void);
int				texture_init();
int				my_mlx_init();
int				sprite_init(void);
int				nextposallowed(float newplayerx, float newplayery);
void			ft_move_backward_forward(int	walkdirection);
void			ft_strafe(int	strafedirection);
void			ft_rotate(int	turndirection);
int				ft_esc();
int				ft_keypressed(int keycode);
int				ft_keyrelease(int keycode);
int				key_manager();
int				update(void);
void			render_sprites();
void			sprite(float spriteangle, float spritedist, int spritenbr);
void			ft_spriteray(float rayangle, float sprtang,
				float spritedist, int tilex);
void			draw_spriteray(float tilex, float stripheight, int raynbr,
					int nbrofrays);
void			ft_sortsprites();
void			ft_swap_sprites(int i);
int				ft_checkray(float dist, float angle);
unsigned	int	ft_read_from_memory_sprite(t_spriteimg texture, int x, int y);
int				iswall(float x, float y);
void			checkangle(float angle);
void			ray_texture(float wallhitx, float wallhity);
int				ft_nexthorztinter();
int				ft_nextvertinter();
float			putray(float angle);
void			draw_wall(int tilex, int tiley, int height);
void			render_rays(void);
void			save(char *filename, char rgb[]);
void			my_mlx_pixel_put(int x, int y, int color);
unsigned	int	ft_read_from_memory(t_texture_data texture, int x, int y);
int				ft_cubdata(char *fname);
long			ft_atoi(const char *str);
void			*ft_memset(void *dest, int src, size_t n);
char			*ft_substr_cub(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
float			ft_angle(char c);
void			ft_fillmap();
int				ft_mapgridinit(char *map, int x, int y);
int				ft_spritenbr(char *str);
char			*ft_mapjoin(char const *s1, char const *s2);
int				ft_find(char c, char const *set);
void			ft_norm(int start, int j, int *len);
void			ft_swaptrim(char *ret, char const *s1, int len, int j);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_strncmp(const char *str1, const char *str2, size_t n);
int				seterrno(int err);
int				checkextenxion(char *str);
int				checkresolution(char *str);
int				checknotexture(char *str);
int				checkwetexture(char *str);
int				checkeatexture(char *str);
int				checksotexture(char *str);
int				checksptexture(char *str);
int				checkfloor(char *str);
int				checkceil(char *str);
char			*ft_strformat(char *str);
int				checkstrformat(char *str);
void			init_vars();
int				check_vars();
int				ft_checkmap();
int				ft_cubdata(char *fname);
void			write_bmp(char *filename, char *rgb);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

float			*g_raydistance;
int				g_myerrno;
t_player		g_player;
t_data			g_img;
t_mlx			g_data;
t_pos			g_pos;
t_consts		g_consts;
t_wallhit		g_wallhit;
t_ray			g_ray;
t_texture_data	g_texture[4];
t_cubdata		g_cubedata;
t_sprites		g_sprites;
t_spriteimg		g_spriteimg;
t_cubnorm		g_cubnorm;
t_colornorm		g_colornorm;
t_free			*g_freelist;
t_free			*g_head;
t_bmp_file		g_bmp;
t_sprite		g_sprt;
#endif
