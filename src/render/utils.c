#include "../inc/data.h"
#include <string.h>

unsigned int	get_color(t_image* asset, int x, int y);
char	*get_image_addr(t_image *asset);
void	blit_to_buffer(t_image *asset, int x, int y, int color);

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

void	blit_to_buffer(t_image *asset, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(unsigned int*)(asset->addr + y * asset->llen
			+ x * (asset->bpp / 8)) = color;
}

int	render_loop(t_prac *data)
{
	if (data->reset_frame)
	{
		render_frame(data, data->screen, data->block);
		data->reset_frame = 0;
	}
	return (0);
}
