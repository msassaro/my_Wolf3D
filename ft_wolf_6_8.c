/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_6_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:09:24 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:28:43 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Here its texture for the floor.
*/

void	ft_wolf_6(t_env *env)
{
	if (env->side == 0 && env->ray_dirx > 0)
	{
		env->floorxwall = env->mapx;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 0 && env->ray_dirx < 0)
	{
		env->floorxwall = env->mapx + 1.0;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 1 && env->ray_diry > 0)
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy;
	}
	else
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy + 1.0;
	}
	env->distwall = env->perpwalldist;
	env->distplayer = 0.0;
}

/*
** In this fct we check if a wall is touched, If yes and the wall
** is a Jem then, we increment nb of jems (e->key) and delete the wall on map
*/

void	ft_check_wall_touch(t_env *e)
{
	double		p;

	p = 1.5;
	if (((double)e->mapx < e->posx + p) && ((double)e->mapx > e->posx - p)
		&& ((double)e->mapy < e->posy + p) && ((double)e->mapy > e->posy - p))
	{
		if (e->map.tab[e->mapx][e->mapy] == 5 && e->key < 3)
		{
			e->key++;
			e->map.tab[e->mapx][e->mapy] = 0;
			system("afplay sfx/pop3.mp3&");
		}
	}
}

/*
** Here its texture for the cieling.
*/

void	ft_wolf_7(t_env *e, int x)
{
	int			y;
	double		currentdist;
	double		weight;
	double		currentfloorx;
	double		currentfloory;

	ft_check_wall_touch(e);
	if (e->draw_end < 0)
		e->draw_end = e->height;
	y = e->draw_end - 1;
	while (++y < e->height)
	{
		currentdist = e->height / (2.0 * y - e->height);
		weight = (currentdist - e->distplayer) /
			(e->distwall - e->distplayer);
		currentfloorx = weight * e->floorxwall +
			(1.0 - weight) * e->posx;
		currentfloory = weight * e->floorywall +
			(1.0 - weight) * e->posy;
		e->floortexx = (int)(currentfloorx * 64) % 64;
		e->floortexy = (int)(currentfloory * 64) % 64;
		e->img_tab[y][x] = e->sky_tab[1][64 * e->floortexy + e->floortexx];
		e->img_tab[e->height - y][x] = e->sky_tab[0][64 * e->floortexy
			+ e->floortexx];
	}
}

/*
** color selector for ft_wolf_5
*/

int		ft_choose_color(t_env *env)
{
	int		color;

	color = 0;
	if (env->map.tab[env->mapx][env->mapy] == 1)
		color = env->text_tab[0][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 2)
		color = env->text_tab[1][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 3)
		color = env->text_tab[2][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 4)
		color = env->text_tab[3][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 5)
		color = env->text_tab[4][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 6)
		color = env->text_tab[5][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 7)
		color = env->text_tab[6][64 * env->texy + env->texx];
	else if (env->map.tab[env->mapx][env->mapy] == 8)
		color = env->text_tab[7][64 * env->texy + env->texx];
	if (env->side == 1)
		color /= 2;
	return (color);
}
