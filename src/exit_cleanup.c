
#include "../inc/data.h"
#include <string.h>

int	exit_cleanup(t_prac *data)
{
	if (data->screen)
	{
		mlx_destroy_image(data->mlx, data->screen->img);
		free(data->screen);
	}
	if (data->block)
	{
		mlx_destroy_image(data->mlx, data->block->img);
		free(data->block);
	}
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
