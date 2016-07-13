/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 15:30:42 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 23:57:49 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void					moove_img(t_env *e, int keycode)
{
	if (keycode == 126 && e->img_pos[0] != 0)
		e->img_pos[0]--;
	else if (keycode == 125 && e->img_pos[0] != 6)
		e->img_pos[0]++;
	else if (keycode == 123 && e->img_pos[1] != 0)
		e->img_pos[1]--;
	else if (keycode == 124 && e->img_pos[1] != 6)
		e->img_pos[1]++;
}

int						*pixel_coord_in_img(t_env *e, int x, int y)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int) * 2);
	ret[0] = 1.0 / 9 * IMAGE_Y * e->img_pos[0] + y;
	ret[1] = 1.0 / 9 * IMAGE_X * e->img_pos[1] + x;
	return (ret);
}

void					m_a_j_env(t_env *e, int keycode, int button)
{
	if (keycode != 0)
		key_m_a_j(keycode, e);
	else if (button == 1 || (button == 4 && e->zoom != 0) || button == 5)
		mouse_m_a_j(button, e);
}

void					leave_properly(t_env *e)
{
	release_cl(e->cl);
	free(e);
	exit(0);
}
