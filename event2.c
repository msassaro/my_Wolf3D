/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:09:24 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:14:38 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_action_effects(t_env *e)
{
	system("afplay sfx/pop2.mp3&");
	if (e->object == 1)
		e->object = 0;
	else
		e->object = 1;
	if (e->map.tab[e->mapx][e->mapy] != 6)
	{
		mlx_clear_window(e->mlx, e->win);
		ft_wolf(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img_tab, 0, 0);
	}
}

void	ft_show_music_list(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	mlx_string_put(e->mlx, e->win, 120, 150, 0x990000, "music");
	mlx_string_put(e->mlx, e->win, 200, 150, 0x990000, "1: star wars cantina");
	mlx_string_put(e->mlx, e->win, 200, 180, 0x990000, "2: star wars imperial");
	mlx_string_put(e->mlx, e->win, 200, 210, 0x990000, "3: teletubbies");
	mlx_string_put(e->mlx, e->win, 200, 240, 0x990000, "4: matrix");
}

void	ft_music_play(int key, t_env *e)
{
	double		p;

	p = 1.5;
	system("killall afplay");
	if (((double)e->mapx < e->posx + p) && ((double)e->mapx > e->posx - p)
		&& ((double)e->mapy < e->posy + p) && ((double)e->mapy > e->posy - p))
	{
		if (e->map.tab[e->mapx][e->mapy] == 6)
		{
			if (key == 18)
				system("afplay sfx/sw1.mp3&");
			else if (key == 19)
				system("afplay sfx/sw2.mp3&");
			else if (key == 20)
				system("afplay sfx/telet.mp3&");
			else if (key == 21)
				system("afplay sfx/matrix.mp3&");
		}
	}
}

void	ft_door_open(t_env *e)
{
	if (e->map.tab[e->mapx][e->mapy] == 3 && e->key >= 1)
	{
		system("afplay sfx/pop.mp3&");
		e->map.tab[e->mapx][e->mapy] = 0;
		e->key--;
	}
	if (e->map.tab[e->mapx][e->mapy] == 4 && e->key == 3)
	{
		system("afplay sfx/pop5.mp3&");
		e->map.tab[e->mapx][e->mapy] = 0;
		e->key = e->key - 3;
	}
}

void	ft_action_key(t_env *e)
{
	double		p;

	p = 1.5;
	if (((double)e->mapx < e->posx + p) && ((double)e->mapx > e->posx - p)
		&& ((double)e->mapy < e->posy + p) && ((double)e->mapy > e->posy - p))
	{
		if (e->map.tab[e->mapx][e->mapy] == 2)
			e->map.tab[e->mapx][e->mapy] = 0;
		if ((e->map.tab[e->mapx][e->mapy] == 3
					|| e->map.tab[e->mapx][e->mapy] == 4) && e->key > 0)
			ft_door_open(e);
		if (e->map.tab[e->mapx][e->mapy] == 6)
			ft_show_music_list(e);
	}
	ft_action_effects(e);
}
