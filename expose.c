/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/04 16:07:30 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 21:44:01 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			expose(t_env **e, int i)
{
	if (i == 2)
	{
		mlx_expose_hook(e[0]->win, &expose_hook, e[0]);
		mlx_key_hook(e[0]->win, &key_hook, e[0]);
		mlx_mouse_hook(e[0]->win, &mouse_hook, e[0]);
		mlx_hook(e[0]->win, 6, 1L << 6, &hook, e[0]);
		mlx_loop_hook(e[0]->ptr, &loop_hook, e[0]);
		mlx_loop(e[0]->ptr);
	}
	else
	{
		mlx_expose_hook(e[0]->win, &expose_hook, e[0]);
		mlx_key_hook(e[0]->win, &key_hook, e[0]);
		mlx_mouse_hook(e[0]->win, &mouse_hook, e[0]);
		mlx_hook(e[0]->win, 6, 1L << 6, &hook, e[0]);
		mlx_loop_hook(e[0]->ptr, &loop_hook, e[0]);
		mlx_expose_hook(e[1]->win, &expose_hook, e[1]);
		mlx_key_hook(e[1]->win, &key_hook, e[1]);
		mlx_mouse_hook(e[1]->win, &mouse_hook, e[1]);
		mlx_hook(e[1]->win, 6, 1L << 6, &hook, e[1]);
		mlx_loop(e[0]->ptr);
	}
}
