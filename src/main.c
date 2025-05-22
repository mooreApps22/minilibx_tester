#include "../inc/data.h"
#include <string.h>

unsigned int	get_color(t_image* asset, int x, int y)
{
	unsigned int color;	

	color = *(unsigned int*)(asset->addr
		+ y * asset->llen + x * (asset->bpp / 8));
	return (color);
}

char	*get_image_addr(t_image *asset)
{
	char *str;

	str = mlx_get_data_addr(asset->img,
		&asset->bpp, &asset->llen, &asset->en);
	return (str);
}

void	render_to_screen(t_image *asset, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(unsigned int*)(asset->addr + y * asset->llen
			+ x * (asset->bpp / 8)) = color;
}

void	render_scene(t_prac *data, t_image *screen, t_image *block)
{
	int	scr_x = block->x;
	int	scr_y = block->y;
	int	blk_x;
	int	blk_y;
	int	left_half = block->w / 2;

	for (blk_y = 0; blk_y < block->h; blk_y++)
	{
		for (blk_x = 0; blk_x < block->w; blk_x++)
		{
			unsigned int color = get_color(block, blk_x, blk_y);
			if (blk_x < left_half)
			{
			//	render_to_screen(screen, blk_x , blk_y * 2, color);
			//	render_to_screen(screen, blk_x , blk_y * 2 + 1, color);
				render_to_screen(screen, blk_x , blk_y / 2, color);
			}
			else
				render_to_screen(screen, blk_x , blk_y, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->window,
		screen->img, scr_x, scr_y);
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
	render_scene(&data, data.screen, data.block);


	
	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, close_window, &data);
	mlx_key_hook(data.window, key_inputs, &data);
	mlx_loop(data.mlx);
	return (0);
}
