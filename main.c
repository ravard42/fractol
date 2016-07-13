/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:56:25 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 23:59:44 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_print_usage(void)
{
	int		i;
	char	*str[8];

	str[0] = "usage :\n";
	str[1] = "./fractol 0 -> mandel\n";
	str[2] = "./fractol 1 -> burning_ship\n";
	str[3] = "./fractol 2 -> tricorn\n";
	str[4] = "./fractol 3 -> julia\n";
	str[5] = "Il est possible de lancer deux fenetres en meme temps\n";
	str[6] = "Utiliser la fenetre 1 pour faire varier le param de julia\n";
	i = -1;
	while (++i < 7)
		ft_putstr(str[i]);
	exit(0);
}

static int		is_fractal_number(int f)
{
	if (f == 0 || f == 1 || f == 2 || f == 3)
		return (1);
	else
		return (0);
}

static void		usage(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		ft_print_usage();
	if (argc == 2)
	{
		if ((argv[1][0] != '0' && argv[1][0] != '1' &&
				argv[1][0] != '2' && argv[1][0] != '3')
				|| argv[1][1] != '\0')
			ft_print_usage();
		if (!is_fractal_number(ft_atoi(argv[1])))
			ft_print_usage();
	}
	else
	{
		if ((argv[1][0] != '0' && argv[1][0] != '1' &&
				argv[1][0] != '2' && argv[1][0] != '3')
				|| argv[1][1] != '\0')
			ft_print_usage();
		if ((argv[2][0] != '0' && argv[2][0] != '1' &&
				argv[2][0] != '2' && argv[2][0] != '3')
				|| argv[2][1] != '\0')
			ft_print_usage();
		if (!is_fractal_number(ft_atoi(argv[1])) ||
				!is_fractal_number(ft_atoi(argv[2])))
			ft_print_usage();
	}
}

static void		init_win(t_env *e, int fract)
{
	init_env(e, fract);
	standard_env(e);
}

int				main(int argc, char **argv)
{
	void	*ptr;
	t_env	*e[2];

	usage(argc, argv);
	ptr = mlx_init();
	if (argc == 2)
	{
		e[0] = (t_env *)malloc(sizeof(t_env));
		e[0]->ptr = ptr;
		init_win(e[0], ft_atoi(argv[1]));
	}
	else
	{
		e[0] = (t_env *)malloc(sizeof(t_env));
		e[0]->ptr = ptr;
		init_win(e[0], ft_atoi(argv[1]));
		e[1] = (t_env *)malloc(sizeof(t_env));
		e[1]->ptr = ptr;
		init_win(e[1], ft_atoi(argv[2]));
	}
	expose(e, argc);
	return (0);
}
