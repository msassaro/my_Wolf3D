/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:09:24 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/17 16:02:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Here are the function for the usier interface
** Stick and jems numbers and UID
*/

void	ft_draw_stick(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->height)
	{
		x = 0;
		while (x < e->width)
		{
			if (e->object == 0)
				if (e->obj_tab[0][e->width * y + x] != 0xff7bac)
					e->img_tab[y][x] = e->obj_tab[0][e->width * y + x];
			if (e->object == 1)
				if (e->obj_tab[1][e->width * y + x] != 0xff7bac)
					e->img_tab[y][x] = e->obj_tab[1][e->width * y + x];
			x++;
		}
		y++;
	}
}

void	ft_draw_menu_3(t_env *e)
{
	int		y;
	int		x;

	if (e->key >= 2)
	{
		y = e->height - 30 - 1;
		while (++y < e->height - 10)
		{
			x = 220 - 1;
			while (++x < 240)
				e->img_tab[y][x] = 0x0000ff;
		}
	}
	if (e->key == 3)
	{
		y = e->height - 30 - 1;
		while (++y < e->height - 10)
		{
			x = 260 - 1;
			while (++x < 280)
				e->img_tab[y][x] = 0x0000ff;
		}
	}
}

void	ft_draw_menu_2(t_env *e)
{
	int		y;
	int		x;

	y = e->height - 40 - 1;
	while (++y < e->height)
	{
		x = -1;
		while (++x < e->width)
			e->img_tab[y][x] = 0x004d4d;
	}
	if (e->key >= 1)
	{
		y = e->height - 30 - 1;
		while (++y < e->height - 10)
		{
			x = 180 - 1;
			while (++x < 200)
				e->img_tab[y][x] = 0x0000ff;
		}
	}
	ft_draw_menu_3(e);
}

void	ft_draw_menu(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < 10)
	{
		x = -1;
		while (++x < e->width)
			e->img_tab[y][x] = 0x004d4d;
	}
	y = -1;
	while (++y < e->height)
	{
		x = -1;
		while (++x < 10)
			e->img_tab[y][x] = 0x004d4d;
	}
	y = -1;
	while (++y < e->height)
	{
		x = e->width - 10 - 1;
		while (++x < e->width)
			e->img_tab[y][x] = 0x004d4d;
	}
	ft_draw_menu_2(e);
}
