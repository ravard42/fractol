/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:56:15 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 23:58:03 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->ptr, e->win, e->img, -1.0 / 9 *
		IMAGE_X * e->img_pos[1], -1.0 / 9 * IMAGE_Y * e->img_pos[0]);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	m_a_j_env(e, keycode, 0);
	expose_hook(e);
	return (0);
}

int		mouse_hook(int button, int j, int i, t_env *e)
{
	e->ptr_pos[0] = i;
	e->ptr_pos[1] = j;
	m_a_j_env(e, 0, button);
	expose_hook(e);
	return (0);
}

int		hook(int j, int i, t_env *e)
{
	e->ptr_pos[0] = i;
	e->ptr_pos[1] = j;
	return (0);
}

int		loop_hook(t_env *e)
{
	if (e->julia_var_up)
	{
		e->julia_var[0] = e->y_min + e->y_scale / IMAGE_Y *
			pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[0];
		e->julia_var[1] = e->x_min + e->x_scale / IMAGE_X *
			pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[1];
		host(e);
	}
	expose_hook(e);
	return (0);
}
