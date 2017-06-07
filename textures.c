/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:09:24 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:16:11 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Here is the TEXTURES INDEX:
** ------------------------------------
** MAP	||	item		||	texture_tab
** ------------------------------------
** 0	||	empty		||
** 1	||	wall		||	0
** 2	||	door		||	1
** 3	||	blue door	||	2
** 4	||	red door	||	3
** 5	||	jem / key	||	4
** 6	||	jukebox		||	5
** 7	||	wall type 2	||	6
** 8	||	wall tpye 3	||	7
** ------------------------------------
*/

void	ft_texture_design_2(t_env *e, int *b, int *s, int *d)
{
	int		i1;
	int		i2;

	e->text[0] = mlx_xpm_file_to_image(e->mlx, "img/purplestone.xpm", &i1, &i2);
	e->text[1] = mlx_xpm_file_to_image(e->mlx, "img/door.xpm", &i1, &i2);
	e->text[2] = mlx_xpm_file_to_image(e->mlx, "img/bluedoor.xpm", &i1, &i2);
	e->text[3] = mlx_xpm_file_to_image(e->mlx, "img/reddoor.xpm", &i1, &i2);
	e->text[4] = mlx_xpm_file_to_image(e->mlx, "img/bluestone.xpm", &i1, &i2);
	e->text[5] = mlx_xpm_file_to_image(e->mlx, "img/mp3.xpm", &i1, &i2);
	e->text[6] = mlx_xpm_file_to_image(e->mlx, "img/purplestone.xpm", &i1, &i2);
	e->text[7] = mlx_xpm_file_to_image(e->mlx, "img/redbrick.xpm", &i1, &i2);
	e->text_tab[0] = (int*)mlx_get_data_addr(e->text[0], b, s, d);
	e->text_tab[1] = (int*)mlx_get_data_addr(e->text[1], b, s, d);
	e->text_tab[2] = (int*)mlx_get_data_addr(e->text[2], b, s, d);
	e->text_tab[3] = (int*)mlx_get_data_addr(e->text[3], b, s, d);
	e->text_tab[4] = (int*)mlx_get_data_addr(e->text[4], b, s, d);
	e->text_tab[5] = (int*)mlx_get_data_addr(e->text[5], b, s, d);
	e->text_tab[6] = (int*)mlx_get_data_addr(e->text[6], b, s, d);
	e->text_tab[7] = (int*)mlx_get_data_addr(e->text[7], b, s, d);
	e->sky[0] = mlx_xpm_file_to_image(e->mlx, "img/purplestone.xpm", &i1, &i2);
	e->sky[1] = mlx_xpm_file_to_image(e->mlx, "img/purplestone.xpm", &i1, &i2);
	e->sky_tab[0] = (int*)mlx_get_data_addr(e->sky[0], b, s, d);
	e->sky_tab[1] = (int*)mlx_get_data_addr(e->sky[1], b, s, d);
}

void	ft_texture_design_1(t_env *e, int *b, int *s, int *d)
{
	int		i1;
	int		i2;

	e->text[0] = mlx_xpm_file_to_image(e->mlx, "img/wood.xpm", &i1, &i2);
	e->text[1] = mlx_xpm_file_to_image(e->mlx, "img/door.xpm", &i1, &i2);
	e->text[2] = mlx_xpm_file_to_image(e->mlx, "img/bluedoor.xpm", &i1, &i2);
	e->text[3] = mlx_xpm_file_to_image(e->mlx, "img/reddoor.xpm", &i1, &i2);
	e->text[4] = mlx_xpm_file_to_image(e->mlx, "img/wood.xpm", &i1, &i2);
	e->text[5] = mlx_xpm_file_to_image(e->mlx, "img/mp3.xpm", &i1, &i2);
	e->text[6] = mlx_xpm_file_to_image(e->mlx, "img/colorstone.xpm", &i1, &i2);
	e->text[7] = mlx_xpm_file_to_image(e->mlx, "img/redbrick.xpm", &i1, &i2);
	e->text_tab[0] = (int*)mlx_get_data_addr(e->text[0], b, s, d);
	e->text_tab[1] = (int*)mlx_get_data_addr(e->text[1], b, s, d);
	e->text_tab[2] = (int*)mlx_get_data_addr(e->text[2], b, s, d);
	e->text_tab[3] = (int*)mlx_get_data_addr(e->text[3], b, s, d);
	e->text_tab[4] = (int*)mlx_get_data_addr(e->text[4], b, s, d);
	e->text_tab[5] = (int*)mlx_get_data_addr(e->text[5], b, s, d);
	e->text_tab[6] = (int*)mlx_get_data_addr(e->text[6], b, s, d);
	e->text_tab[7] = (int*)mlx_get_data_addr(e->text[7], b, s, d);
	e->sky[0] = mlx_xpm_file_to_image(e->mlx, "img/carre.xpm", &i1, &i2);
	e->sky[1] = mlx_xpm_file_to_image(e->mlx, "img/sandstone.xpm", &i1, &i2);
	e->sky_tab[0] = (int*)mlx_get_data_addr(e->sky[0], b, s, d);
	e->sky_tab[1] = (int*)mlx_get_data_addr(e->sky[1], b, s, d);
}

/*
** Here are the objects, sky, floor and wall textures stored into those arrays
*/

void	ft_get_textures(t_env *e)
{
	int		b;
	int		s;
	int		d;
	int		i1;
	int		i2;

	e->obj[0] = mlx_xpm_file_to_image(e->mlx, "img/stick0.xpm", &i1, &i2);
	e->obj[1] = mlx_xpm_file_to_image(e->mlx, "img/stick1.xpm", &i1, &i2);
	e->obj_tab[0] = (int*)mlx_get_data_addr(e->obj[0], &b, &s, &d);
	e->obj_tab[1] = (int*)mlx_get_data_addr(e->obj[1], &b, &s, &d);
	if (e->design == 1)
		ft_texture_design_1(e, &b, &s, &d);
	if (e->design == 2)
		ft_texture_design_2(e, &b, &s, &d);
}
