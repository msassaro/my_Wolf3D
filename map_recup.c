/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_recup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msassaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:00:58 by msassaro          #+#    #+#             */
/*   Updated: 2016/03/21 12:15:31 by msassaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error_map(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

int		ft_get_map_nbline(char *av)
{
	int		nb_line;
	int		fd;
	char	*line;

	nb_line = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error_map();
	while (get_next_line(fd, &line))
	{
		nb_line++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (nb_line);
}

void	ft_envinit_map_fill(t_env *env, char *line)
{
	int				i;
	int				j;
	int				len;
	static int		k;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	if (env->map.col == 0)
		env->map.col = len;
	else if (env->map.col != len)
		ft_error_map();
	if ((env->map.tab[k] = (int*)malloc(sizeof(int) * len + 1)) == NULL)
		ft_error_map();
	while (line[i] && j < env->map.col && k < env->map.line)
	{
		env->map.tab[k][j] = line[i] - 48;
		i++;
		j++;
	}
	k++;
}

void	ft_recup_map(char *av, t_env *env)
{
	int		fd;
	char	*line;

	env->map.col = 0;
	env->map.line = ft_get_map_nbline(av);
	if ((env->map.tab = (int**)malloc(sizeof(int*) * env->map.line)) == NULL)
		ft_error_map();
	if ((fd = open(av, O_RDONLY)) == -1)
		ft_error_map();
	while (get_next_line(fd, &line))
	{
		ft_envinit_map_fill(env, line);
		free(line);
	}
	if (line)
		free(line);
	close(fd);
}
