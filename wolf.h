/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:01:44 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 18:12:10 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include "mlx/mlx.h"
# include "math.h"

typedef struct		s_inttab
{
	int				**tab;
	int				col;
	int				line;
}					t_inttab;

typedef struct		s_env
{
	t_inttab		map;
	int				design;
	void			*mlx;
	void			*win;
	void			*img;
	int				*data_add;
	int				**img_tab;
	int				width;
	int				height;
	double			dirx;
	double			olddirx;
	double			posx;
	double			planex;
	double			oldplanex;
	double			diry;
	double			olddiry;
	double			posy;
	double			planey;
	double			oldplaney;
	double			camx;
	double			camy;
	double			ray_posx;
	double			ray_posy;
	double			ray_dirx;
	double			ray_diry;
	int				mapx;
	int				mapy;
	double			side_distx;
	double			side_disty;
	double			delta_distx;
	double			delta_disty;
	int				stepx;
	int				stepy;
	double			perpwalldist;
	int				line_height;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	int				key;
	void			*sky[2];
	int				*sky_tab[2];
	void			*text[8];
	int				*text_tab[8];
	double			wallx;
	int				texx;
	int				texy;
	double			floorxwall;
	double			floorywall;
	int				floortexx;
	int				floortexy;
	double			distwall;
	double			distplayer;
	int				object;
	void			*obj[2];
	int				*obj_tab[2];
}					t_env;

/*
** map_recup.c
*/

void				ft_error_map(void);
int					ft_get_map_nbline(char *av);
void				ft_envinit_map_fill(t_env *env, char *line);
void				ft_recup_map(char *av, t_env *env);

/*
** main.c
*/

void				ft_wolf(t_env *env);
void				ft_controls(void);

/*
** event.c
*/

void				ft_design_change(t_env *e);
void				ft_wolf_rotation(int key, t_env *e);
void				ft_move_ws(int key, t_env *env);
void				ft_move_ad(int keycode, t_env *env);
int					ft_wolf_keyhook(int key, void *param);

/*
** event2.c
*/

void				ft_action_effects(t_env *e);
void				ft_show_music_list(t_env *e);
void				ft_music_play(int key, t_env *e);
void				ft_door_open(t_env *e);
void				ft_action_key(t_env *e);

/*
** textures.c
*/

void				ft_texture_design_2(t_env *e, int *b, int *s, int *d);
void				ft_texture_design_1(t_env *e, int *b, int *s, int *d);
void				ft_get_textures(t_env *e);

/*
** init.c
*/

void				ft_init_envmlx(t_env *e);
int					**ft_img_tab_create(t_env *env);
void				ft_env_init(t_env *env);

/*
** ft_wolf_1-5.c
*/

void				ft_wolf_1(t_env *env, int x);
void				ft_wolf_2(t_env *env);
void				ft_wolf_3(t_env *env);
void				ft_wolf_4(t_env *env);
void				ft_wolf_5(t_env *env, int x);

/*
** ft_wolf_6-8.c
*/

void				ft_wolf_6(t_env *env);
void				ft_check_wall_touch(t_env *e);
void				ft_wolf_7(t_env *env, int x);
int					ft_choose_color(t_env *env);

/*
** ui.c
*/

void				ft_draw_stick(t_env *e);
void				ft_draw_menu_3(t_env *e);
void				ft_draw_menu_2(t_env *e);
void				ft_draw_menu(t_env *e);

#endif
