/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:49:55 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/16 14:53:21 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** Here we have thee initialisation of the environement
** And the creation of arrays for mlx images
*/

int		**ft_img_tab_create(t_env *env)
{
	int		**img_tab;
	int		i;

	i = 0;
	img_tab = (int**)malloc(sizeof(int*) * ((int)env->height + 1));
	while (i < env->height)
	{
		img_tab[i] = &env->data_add[i * env->width];
		i++;
	}
	return (img_tab);
}

void	ft_init_envmlx(t_env *e)
{
	int		b;
	int		s;
	int		d;

	e->width = 512;
	e->height = 384;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->width, e->height, "WOLF3D");
	e->img = mlx_new_image(e->mlx, e->width, e->height);
	e->data_add = (int*)mlx_get_data_addr(e->img, &b, &s, &d);
	e->img_tab = ft_img_tab_create(e);
}

void	ft_env_init(t_env *e)
{
	e->posx = 2;
	e->posy = 2;
	e->dirx = -1;
	e->diry = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->key = 0;
	e->object = 0;
	e->design = 1;
	e->object = 1;
	ft_get_textures(e);
}
