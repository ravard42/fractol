/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 20:26:56 by ravard            #+#    #+#             */
/*   Updated: 2016/07/04 15:24:42 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			get_device_info(cl_device_id device)
{
	char				vendor_name[1024];
	char				device_name[1024];

	clGetDeviceInfo(device, CL_DEVICE_VENDOR,
			sizeof(vendor_name), vendor_name, NULL);
	clGetDeviceInfo(device, CL_DEVICE_NAME,
			sizeof(device_name), device_name, NULL);
	ft_putstr("connecting to ");
	ft_putstr(vendor_name);
	ft_putstr(", ");
	ft_putstr(device_name);
	ft_putstr("...\n");
}

cl_kernel		load_kernel(cl_program program, int i)
{
	if (i == 0)
		return (clCreateKernel(program, "mandel", NULL));
	else if (i == 1)
		return (clCreateKernel(program, "burning_ship", NULL));
	else if (i == 2)
		return (clCreateKernel(program, "tricorn", NULL));
	else
		return (clCreateKernel(program, "julia", NULL));
}

void			init_cl(t_env *e)
{
	char				*source;
	cl_program			program;
	cl_device_id		device;

	clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &device, NULL);
	get_device_info(device);
	e->cl->context = clCreateContext(0, 1, &device, NULL, NULL, NULL);
	e->cl->cmd_queue = clCreateCommandQueue(e->cl->context, device, 0, NULL);
	source = load_kernel_source(e->which_fract);
	program = clCreateProgramWithSource(e->cl->context,
			1, (const char **)&source, NULL, NULL);
	clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
	e->cl->kernel = load_kernel(program, e->which_fract);
	e->cl->env_cl_mem = clCreateBuffer(e->cl->context,
			CL_MEM_READ_ONLY, 9 * sizeof(double), NULL, NULL);
	e->cl->gws = IMAGE_X * IMAGE_Y;
	e->cl->couleur_cl_mem = clCreateBuffer(e->cl->context,
			CL_MEM_READ_WRITE, e->cl->gws * sizeof(int), NULL, NULL);
	clFinish(e->cl->cmd_queue);
}

void			run_cl(double *env, int *couleur, t_env *e)
{
	clEnqueueWriteBuffer(e->cl->cmd_queue, e->cl->env_cl_mem,
			CL_TRUE, 0, 9 * sizeof(double), (void *)env, 0, NULL, NULL);
	clFinish(e->cl->cmd_queue);
	clSetKernelArg(e->cl->kernel, 0, sizeof(cl_mem), &e->cl->env_cl_mem);
	clSetKernelArg(e->cl->kernel, 1, sizeof(cl_mem), &e->cl->couleur_cl_mem);
	clEnqueueNDRangeKernel(e->cl->cmd_queue, e->cl->kernel,
			1, NULL, &e->cl->gws, NULL, 0, NULL, NULL);
	clFinish(e->cl->cmd_queue);
	clEnqueueReadBuffer(e->cl->cmd_queue, e->cl->couleur_cl_mem,
			CL_TRUE, 0, e->cl->gws * sizeof(int), couleur, 0, NULL, NULL);
	clFinish(e->cl->cmd_queue);
}

void			release_cl(t_cl *cl)
{
	clReleaseCommandQueue(cl->cmd_queue);
	clReleaseContext(cl->context);
}
