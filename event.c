/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:49:21 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/16 14:52:37 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_design_change(t_env *e)
{
	system("afplay sfx/star.mp3&");
	if (e->design == 1)
		e->design = 2;
	else if (e->design == 2)
		e->design = 1;
	mlx_clear_window(e->mlx, e->win);
	ft_get_textures(e);
	ft_wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_tab, 0, 0);
}

void	ft_wolf_rotation(int key, t_env *e)
{
	double		olddirx;
	double		oldplanex;

	if (key == 14 || key == 124)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(-0.1) - e->diry * sin(-0.1);
		e->diry = olddirx * sin(-0.1) + e->diry * cos(-0.1);
		oldplanex = e->planex;
		e->planex = e->planex * cos(-0.1) - e->planey * sin(-0.1);
		e->planey = oldplanex * sin(-0.1) + e->planey * cos(-0.1);
	}
	if (key == 12 || key == 123)
	{
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(0.1) - e->diry * sin(0.1);
		e->diry = olddirx * sin(0.1) + e->diry * cos(0.1);
		oldplanex = e->planex;
		e->planex = e->planex * cos(0.1) - e->planey * sin(0.1);
		e->planey = oldplanex * sin(0.1) + e->planey * cos(0.1);
	}
	mlx_clear_window(e->mlx, e->win);
	ft_wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_tab, 0, 0);
}

/*
** 13=w 1=s 126=up 125=down
*/

void	ft_move_ws(int key, t_env *e)
{
	if (key == 13 || key == 126)
	{
		if (e->map.tab[(int)(e->posx + e->dirx * 0.2)][(int)e->posy] == 0)
			e->posx += e->dirx * 0.2;
		if (e->map.tab[(int)e->posx][(int)(e->posy + e->diry * 0.2)] == 0)
			e->posy += e->diry * 0.2;
	}
	if (key == 1 || key == 125)
	{
		if (e->map.tab[(int)(e->posx - e->dirx * 0.2)][(int)e->posy] == 0)
			e->posx -= e->dirx * 0.2;
		if (e->map.tab[(int)e->posx][(int)(e->posy - e->diry * 0.2)] == 0)
			e->posy -= e->diry * 0.2;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_tab, 0, 0);
}

/*
** a=0 d=2
*/

void	ft_move_ad(int keycode, t_env *e)
{
	if (keycode == 0)
	{
		if (e->map.tab[(int)(e->posx - e->planex * 0.2)][(int)e->posy] == 0)
			e->posx -= e->planex * 0.2;
		if (e->map.tab[(int)e->posx][(int)(e->posy - e->planey * 0.2)] == 0)
			e->posy -= e->planey * 0.2;
	}
	if (keycode == 2)
	{
		if (e->map.tab[(int)(e->posx + e->planex * 0.2)][(int)e->posy] == 0)
			e->posx += e->planex * 0.2;
		if (e->map.tab[(int)e->posx][(int)(e->posy + e->planey * 0.2)] == 0)
			e->posy += e->planey * 0.2;
	}
	mlx_clear_window(e->mlx, e->win);
	ft_wolf(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img_tab, 0, 0);
}

int		ft_wolf_keyhook(int key, void *param)
{
	t_env	*env;

	env = (t_env*)param;
	if (key == 53)
		exit(0);
	if (key == 14 || key == 12 || key == 124 || key == 123)
		ft_wolf_rotation(key, env);
	if (key == 13 || key == 1 || key == 126 || key == 125)
		ft_move_ws(key, env);
	if (key == 0 || key == 2)
		ft_move_ad(key, env);
	if (key == 49)
		ft_action_key(env);
	if (key == 8)
		ft_design_change(env);
	if (key == 18 || key == 19 || key == 20 || key == 21)
		ft_music_play(key, env);
	return (0);
}
