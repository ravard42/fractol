/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 18:57:28 by ravard            #+#    #+#             */
/*   Updated: 2016/06/03 19:17:53 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(int n, float power)
{
	int		i;
	double	ret;

	i = 1;
	ret = 1;
	while (i++ <= n)
		ret *= power;
	return (ret);
}