/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 19:09:24 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 18:20:23 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_wolf(t_env *env)
{
	int		x;

	x = 0;
	while (x < env->width)
	{
		ft_wolf_1(env, x);
		ft_wolf_2(env);
		ft_wolf_3(env);
		ft_wolf_4(env);
		ft_wolf_5(env, x);
		ft_wolf_6(env);
		ft_wolf_7(env, x);
		x++;
	}
	ft_draw_stick(env);
	ft_draw_menu(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_hook(env->win, 2, 0, ft_wolf_keyhook, env);
	mlx_loop(env->mlx);
}

/*
** This is the user manual for controls printed into shell
*/

void	ft_controls(void)
{
	ft_putstr("\033[32m-----------\n  WOLF 3D\n-----------\033[31m\n");
	ft_putstr("SYNOPSIS\033[0;0m\n\t./wolf3d [argument = map]\n\n\033[31m");
	ft_putstr("DESCRIPTION\033[0;0m\n\nYou have to find the red room. To open");
	ft_putstr(" blue\ndoor you need 1 jem, for red door you need 3 jems.\n");
	ft_putstr("Jems are hidden in walls. Use c to have spe-vision.\n\n");
	ft_putstr("\033[31mCONTROLS\n\n\033[32m");
	ft_putstr("spacebar\taction key\narrows\t\tmove\n");
	ft_putstr("wasd\t\tmove 2\nc\t\tchange display\n1234\t\ton/off music ");
	ft_putstr("while on hi-fi\n\033[0;0m");
}

void	ft_check_arg(char *av, t_env *env)
{
	if (!ft_strcmp(av, "1"))
		ft_recup_map("scenes/lvl1.w3d", env);
	else if (!ft_strcmp(av, "2"))
		ft_recup_map("scenes/lvl2.w3d", env);
	else if (!ft_strcmp(av, "3"))
		ft_recup_map("scenes/lvl3.w3d", env);
	else if (!ft_strcmp(av, "4"))
		ft_recup_map("scenes/lvl4.w3d", env);
	else if (!ft_strcmp(av, "5"))
		ft_recup_map("scenes/lvl5.w3d", env);
	else
		ft_error_map();
}

int		main(int ac, char **av)
{
	t_env	env;

	if (ac == 2 || ac == 1)
	{
		if (ac == 1)
			ft_recup_map("scenes/lvl1.w3d", &env);
		else
			ft_check_arg(av[1], &env);
		ft_controls();
		ft_init_envmlx(&env);
		ft_env_init(&env);
		ft_wolf(&env);
	}
	return (0);
}
