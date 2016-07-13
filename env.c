/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:54:31 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 23:57:24 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					init_env(t_env *e, int which)
{
	char	*str[5];

	str[0] = "Mandel";
	str[1] = "Burning_Ship";
	str[2] = "Tricorn";
	str[3] = "Julia";
	e->cl = (t_cl *)malloc(sizeof(t_cl));
	e->which_fract = which;
	init_cl(e);
	e->win = mlx_new_window(e->ptr, IMAGE_X / 3, IMAGE_Y / 3, str[which]);
	e->img = mlx_new_image(e->ptr, IMAGE_X, IMAGE_Y);
	e->ptr_pos = (int *)malloc(sizeof(int) * 2);
	e->img_pos = (int*)malloc(sizeof(int) * 2);
	e->decal = (int *)malloc(sizeof(int) * 2);
	e->data_info = (int *)malloc(sizeof(int) * 3);
	e->data_addr = mlx_get_data_addr(e->img,
			e->data_info, e->data_info + 1, e->data_info + 2);
	e->julia_var_up = 0;
	e->julia_var = (double *)malloc(sizeof(double) * 2);
}

void					standard_env(t_env *e)
{
	e->julia_var[0] = 0;
	e->julia_var[1] = 0;
	e->img_pos[0] = 3;
	e->img_pos[1] = 3;
	e->decal[0] = 0;
	e->decal[1] = 0;
	e->x_min = X_MIN;
	e->x_max = X_MAX;
	e->x_mid = (X_MAX + X_MIN) / 2;
	e->y_min = Y_MIN;
	e->y_max = Y_MAX;
	e->y_mid = (Y_MAX + Y_MIN) / 2;
	e->zoom = 0;
	e->x_scale = (X_MAX - X_MIN) / ft_power(e->zoom, POWER);
	e->y_scale = (Y_MAX - Y_MIN) / ft_power(e->zoom, POWER);
	host(e);
}

void					new_env(t_env *e)
{
	e->y_scale = (Y_MAX - Y_MIN) / ft_power(e->zoom, POWER);
	e->x_scale = (X_MAX - X_MIN) / ft_power(e->zoom, POWER);
	e->y_mid += e->decal[0] * e->y_scale / IMAGE_Y;
	e->x_mid += e->decal[1] * e->x_scale / IMAGE_X;
	e->y_max = e->y_mid + e->y_scale / 2;
	e->y_min = e->y_mid - e->y_scale / 2;
	e->x_max = e->x_mid + e->x_scale / 2;
	e->x_min = e->x_mid - e->x_scale / 2;
	e->decal[0] = 0;
	e->decal[1] = 0;
	host(e);
}

void					mouse_m_a_j(int button, t_env *e)
{
	e->y_mid = e->y_min + e->y_scale / IMAGE_Y *
		pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[0];
	e->x_mid = e->x_min + e->x_scale / IMAGE_X *
		pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[1];
	e->img_pos[0] = 3;
	e->img_pos[1] = 3;
	if (button == 4 || button == 5)
	{
		e->decal[0] = IMAGE_Y / 6 - e->ptr_pos[0];
		e->decal[1] = IMAGE_Y / 6 - e->ptr_pos[1];
	}
	if (button == 4)
		e->zoom--;
	if (button == 5)
		e->zoom++;
	new_env(e);
}

void					key_m_a_j(int keycode, t_env *e)
{
	if (keycode == 53)
		leave_properly(e);
	else if (keycode == 49)
		standard_env(e);
	else if (keycode == 123 || keycode == 124 ||
			keycode == 125 || keycode == 126)
		moove_img(e, keycode);
	else if (keycode == 9)
		e->julia_var_up = (e->julia_var_up == 1) ? 0 : 1;
	else if (keycode == 24 || (keycode == 27 && e->zoom != 0))
	{
		e->y_mid = e->y_min + e->y_scale / IMAGE_Y *
			pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[0];
		e->x_mid = e->x_min + e->x_scale / IMAGE_X *
			pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[1];
		e->img_pos[0] = 3;
		e->img_pos[1] = 3;
		e->decal[0] = IMAGE_Y / 6 - e->ptr_pos[0];
		e->decal[1] = IMAGE_X / 6 - e->ptr_pos[1];
		if (keycode == 27)
			e->zoom--;
		if (keycode == 24)
			e->zoom++;
		new_env(e);
	}
}
