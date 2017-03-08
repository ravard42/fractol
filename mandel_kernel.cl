kernel void		mandel(global float *env, global int *couleur)
{
	int			pixel;
	float2		c;
	float2		z;
	float		tmp;
	int			i;

	pixel = get_global_id(0);
	couleur[pixel] = pixel;
	c.x = env[2] + (pixel % (int)env[5]) * (env[3] - env[2]) / env[5];
	c.y = env[0] + (pixel / (int)env[5]) * (env[1] - env[0]) / env[4];
	z.x = env[8];
	z.y = env[7];
	i = 0;
	while (z.x * z.x + z.y * z.y <= 4 && i++ < (int)env[6])
	{
		tmp = z.x;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.y * tmp + c.y;
	}
	couleur[pixel] = (z.x * z.x + z.y * z.y > 4) ? i : -1;
}
