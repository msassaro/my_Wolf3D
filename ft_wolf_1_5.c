/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf_1-5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:11:42 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:30:48 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** delta distx/y = distance to the next x or y for the ray
** hit is set to 0. if wall ==> hit = 1
** HERE we calculate the camera direction, the ray position and directions
** DELTA_DIST = lenght of the ray from the current position to the next x/y
*/

void	ft_wolf_1(t_env *env, int x)
{
	env->camx = (double)(2 * (double)x / (double)env->width - 1);
	env->ray_posx = env->posx;
	env->ray_posy = env->posy;
	env->ray_dirx = env->dirx + env->planex * env->camx;
	env->ray_diry = env->diry + env->planey * env->camx;
	env->mapx = (int)env->ray_posx;
	env->mapy = (int)env->ray_posy;
	env->delta_distx = sqrt(1 + (env->ray_diry * env->ray_diry)
			/ (env->ray_dirx * env->ray_dirx));
	env->delta_disty = sqrt(1 + (env->ray_dirx * env->ray_dirx)
			/ (env->ray_diry * env->ray_diry));
	env->hit = 0;
}

/*
** What direction we need to step in x. if left --> -1
*/

void	ft_wolf_2(t_env *env)
{
	if (env->ray_dirx < 0)
	{
		env->stepx = -1;
		env->side_distx = (env->ray_posx - env->mapx) * env->delta_distx;
	}
	else
	{
		env->stepx = 1;
		env->side_distx = (env->mapx + 1 - env->ray_posx) * env->delta_distx;
	}
	if (env->ray_diry < 0)
	{
		env->stepy = -1;
		env->side_disty = (env->ray_posy - env->mapy) * env->delta_disty;
	}
	else
	{
		env->stepy = 1;
		env->side_disty = (env->mapy + 1 - env->ray_posy) * env->delta_disty;
	}
}

/*
** THIS is the DDA algorithm.
** first we jump to the next map square, in X or Y direction
** second we check if a wall is touched. If so --> hit == 1
** Then we calculate the distance of the ray to the wall
*/

void	ft_wolf_3(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->side_distx < env->side_disty)
		{
			env->side_distx += env->delta_distx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->side_disty += env->delta_disty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (env->map.tab[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
	if (env->side == 0)
		env->perpwalldist = (env->mapx - env->ray_posx
				+ (1 - env->stepx) / 2) / env->ray_dirx;
	else
		env->perpwalldist = (env->mapy - env->ray_posy
				+ (1 - env->stepy) / 2) / env->ray_diry;
	env->line_height = (int)(env->height / env->perpwalldist);
}

/*
** Just above we calculate the line height to know the height of the wall
** Here we calculate the highest and lowest pixel on the X line to draw
** The wall will be between those 2 pixels.
** And we calculate the texture for the wall
*/

void	ft_wolf_4(t_env *env)
{
	env->draw_start = -(env->line_height) / 2 + env->height / 2;
	env->draw_end = env->line_height / 2 + env->height / 2;
	if (env->draw_start < 0)
		env->draw_start = 0;
	if (env->draw_end >= env->height)
		env->draw_end = env->height - 1;
	if (env->side == 1)
		env->wallx = env->ray_posx + ((env->mapy - env->ray_posy +
			(1 - env->stepy) / 2) / env->ray_diry) * env->ray_dirx;
	else
		env->wallx = env->ray_posy + ((env->mapx - env->ray_posx +
			(1 - env->stepx) / 2) / env->ray_dirx) * env->ray_diry;
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * 64);
	if (env->side == 0 && env->ray_dirx > 0)
		env->texx = 64 - env->texx - 1;
	if (env->side == 1 && env->ray_diry < 0)
		env->texx = 64 - env->texx - 1;
}

/*
** Here we will choose the texture corresponding to the map number
** and drqw it between the 2 pixels on the x line
*/

void	ft_wolf_5(t_env *env, int x)
{
	int		y;
	int		color;

	y = env->draw_start;
	color = 0;
	while (y < env->draw_end)
	{
		env->texy = (y * 2 - env->height + env->line_height)
			* (64 / 2) / env->line_height;
		color = ft_choose_color(env);
		env->img_tab[y][x] = color;
		y++;
	}
}
