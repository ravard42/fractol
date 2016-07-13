/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_kernel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 20:26:32 by ravard            #+#    #+#             */
/*   Updated: 2016/07/04 15:25:19 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static char		*load_program_source_mandel(void)
{
	int		fd;
	char	*line;
	char	*source;

	fd = open("./mandel_kernel.cl", O_RDONLY);
	source = (char *)malloc(sizeof(char) * 4096);
	source[0] = '\0';
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

static char		*load_program_source_burning_ship(void)
{
	int		fd;
	char	*line;
	char	*source;

	fd = open("./burning_ship_kernel.cl", O_RDONLY);
	source = (char *)malloc(sizeof(char) * 4096);
	source[0] = '\0';
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

static char		*load_program_source_tricorn(void)
{
	int		fd;
	char	*line;
	char	*source;

	fd = open("./tricorn_kernel.cl", O_RDONLY);
	source = (char *)malloc(sizeof(char) * 4096);
	source[0] = '\0';
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

static char		*load_program_source_julia(void)
{
	int		fd;
	char	*line;
	char	*source;

	fd = open("./julia_kernel.cl", O_RDONLY);
	source = (char *)malloc(sizeof(char) * 4096);
	source[0] = '\0';
	while (get_next_line(fd, &line) == 1)
		ft_strcat(source, line);
	return (source);
}

char			*load_kernel_source(int i)
{
	if (i == 0)
		return (load_program_source_mandel());
	else if (i == 1)
		return (load_program_source_burning_ship());
	else if (i == 2)
		return (load_program_source_tricorn());
	else
		return (load_program_source_julia());
}
