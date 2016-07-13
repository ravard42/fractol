/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 20:44:52 by ravard            #+#    #+#             */
/*   Updated: 2016/07/13 21:27:48 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define IMAGE_X 3000
# define IMAGE_Y 3000
# define IT_MAX  320
# define X_MIN	-5.5
# define X_MAX	4.5
# define Y_MIN	-5.0
# define Y_MAX	5.0
# define POWER	1.5

# include <OpenCL/opencl.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef struct		s_cl
{
	cl_context			context;
	cl_command_queue	cmd_queue;
	cl_kernel			kernel;
	cl_mem				env_cl_mem;
	cl_mem				couleur_cl_mem;
	size_t				gws;
}					t_cl;

typedef struct		s_env
{
	t_cl		*cl;
	void		*ptr;
	void		*win;
	void		*img;
	int			*ptr_pos;
	int			*img_pos;
	int			*decal;
	char		*data_addr;
	int			*data_info;
	double		x_min;
	double		x_max;
	double		x_mid;
	double		y_min;
	double		y_max;
	double		y_mid;
	int			zoom;
	double		x_scale;
	double		y_scale;
	int			julia_var_up;
	double		*julia_var;
	int			which_fract;
}					t_env;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
int					mouse_hook(int button, int j, int i, t_env *e);
int					hook(int j, int i, t_env *e);
int					loop_hook(t_env *e);

void				expose(t_env **e, int i);

void				init_env(t_env *e, int which);
void				standard_env(t_env *e);
void				mouse_m_a_j(int button, t_env *e);
void				key_m_a_j(int keycode, t_env *e);
void				get_device_info(cl_device_id device);
void				moove_img(t_env *e, int keycode);
int					*pixel_coord_in_img(t_env *e, int x, int y);
void				m_a_j_env(t_env *e, int keycode, int button);
void				leave_properly(t_env *e);

char				*load_kernel_source(int i);
cl_kernel			load_kernel(cl_program program, int i);

void				init_cl(t_env *e);
void				run_cl(double *env, int *couleur, t_env *e);
void				release_cl(t_cl *cl);

void				host(t_env *e);
void				color(t_env *e, int pixel, int couleur);

#endif
