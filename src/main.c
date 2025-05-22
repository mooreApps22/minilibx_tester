#include "../inc/data.h"
#include <string.h>


void	iterate_down_screen(t_image *screen, t_image *asset, int i)
{
	int				j;
	unsigned int	asset_color;

	j = 0;
	while (j < HEIGHT)
	{
		if (j >= 0 && j < asset->h)
		{
			asset_color = get_color(asset, i, j);
			blit_to_buffer(screen, i + asset->x, j + asset->y, asset_color);
		}
		j++;
	}
}

void	iterate_across_screen(t_prac *data, t_image *screen, t_image *asset)
{
	int i;

	i = 0;
	while (i < WIDTH)
	{
		if (i >= 0 && i < asset->w)
			iterate_down_screen(screen, asset, i);
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->window, screen->img, asset->x, asset->y);
}


void	render_frame(t_prac *data, t_image *screen, t_image *asset)
{
	iterate_across_screen(data, screen, asset);
}

int	main(int ac, char **av)
{
	t_prac	data;
	(void)ac;

	if (initialize(&data) != 0)
		exit_cleanup(&data);
	data.block->x = atoi(av[1]);
	data.block->y = atoi(av[2]);

	data.block->addr = get_image_addr(data.block);
	render_frame(&data, data.screen, data.block);

	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, close_window, &data);
	mlx_key_hook(data.window, key_inputs, &data);
	mlx_loop_hook(data.mlx, render_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
