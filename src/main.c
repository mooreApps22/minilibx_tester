#include "../inc/data.h"
#include <string.h>


void	iterate_down_screen(t_image *screen, t_image *asset,
	int asset_x, int screen_x, float scale)
{
	int				screen_y;
	int				asset_y;
	unsigned int	asset_color;
	int				asset_display_height;
	int				offset;


	screen_y = 0;
	asset_display_height = (int)(asset->h * scale);
	offset = (HEIGHT - asset_display_height) / 2;
	while (screen_y < HEIGHT)
	{
		asset_y = (int)((screen_y - offset) / scale);
		if (asset_y >= 0 && asset_y < asset->h)
		{
			asset_color = get_color(asset, asset_x, asset_y);
			blit_to_buffer(screen, screen_x, screen_y, asset_color);
		}
		screen_y++;
	}
}

void	iterate_across_screen(t_prac *data, t_image *screen, t_image *asset)
{
	int		asset_x;
	int		screen_x_start;
	int		center_asset_x;
	float	local_scale;
	float	offset;

	screen_x_start = (WIDTH - asset->w) / 2;
	center_asset_x = asset->w / 2.0f;
	asset_x = 0;
	while (asset_x < asset->w)
	{
		offset = (asset_x - center_asset_x);
		local_scale = 1.0f + (offset * data->rotation * 0.01f);
		if (local_scale < 0.1f)
			local_scale = 0.1f;
		if (local_scale > 5.0f)
			local_scale = 5.0f;
		iterate_down_screen(screen, asset, asset_x, screen_x_start + asset_x, local_scale);
		asset_x++;
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
	(void)av;

	if (initialize(&data) != 0)
		exit_cleanup(&data);
//	data.block->x = atoi(av[1]);
//	data.block->y = atoi(av[2]);

	data.block->addr = get_image_addr(data.block);
	data.rotation = 0.0f;
	render_frame(&data, data.screen, data.block);

	mlx_hook(data.window, DestroyNotify, StructureNotifyMask, close_window, &data);
	mlx_key_hook(data.window, key_inputs, &data);
	mlx_loop_hook(data.mlx, render_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
