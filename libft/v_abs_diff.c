/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_abs_diff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 04:24:15 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 04:24:18 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float			v_abs_diff(float a, float b)
{
	float	c;

	c = b - a;
	if (c < 0)
		return (-c);
	return (c);
}