/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:27:53 by ravard            #+#    #+#             */
/*   Updated: 2016/07/04 15:53:48 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			host(t_env *e)
{
	double		*env;
	int			*couleur;
	size_t		i;

	env = (double *)malloc(sizeof(double) * 9);
	env[0] = e->y_min;
	env[1] = e->y_max;
	env[2] = e->x_min;
	env[3] = e->x_max;
	env[4] = IMAGE_Y;
	env[5] = IMAGE_X;
	env[6] = IT_MAX;
	env[7] = (e->julia_var_up) ? e->y_min + e->y_scale / IMAGE_Y
		* pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[0]
		: e->julia_var[0];
	env[8] = (e->julia_var_up) ? e->x_min + e->x_scale / IMAGE_X
		* pixel_coord_in_img(e, e->ptr_pos[1], e->ptr_pos[0])[1]
		: e->julia_var[1];
	couleur = (int *)malloc(sizeof(int) * e->cl->gws);
	run_cl(env, couleur, e);
	i = -1;
	while (++i < e->cl->gws)
		color(e, i, couleur[i]);
	free(env);
	free(couleur);
}
