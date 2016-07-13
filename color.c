/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 00:15:37 by ravard            #+#    #+#             */
/*   Updated: 2016/06/26 20:37:27 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			color(t_env *e, int pixel, int couleur)
{
	int boool[4];

	if (couleur == -1)
		*((unsigned int *)e->data_addr + pixel) = 0x000000;
	else
	{
		couleur = couleur % 160;
		boool[0] = (couleur > 16 && couleur <= 50) ? 1 : 0;
		boool[1] = (couleur > 50 && couleur <= 110) ? 1 : 0;
		boool[2] = (couleur > 110 && couleur <= 160) ? 1 : 0;
		*((unsigned int *)e->data_addr + pixel) =
			0x000020 + boool[0] * (couleur - 16) * 0x070700
			+ boool[1] * ((couleur - 50) * 0x040002)
			+ boool[2] * (couleur - 110) * 0x000504;
	}
}
