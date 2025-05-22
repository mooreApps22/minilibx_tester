#include "../inc/data.h"
#include <string.h>

/*

void	render_frame(t_prac *data, t_image *screen, t_image *block)
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
				blit_to_buffer(screen, blk_x + scr_x , blk_y * 2 + scr_y, color);
				blit_to_buffer(screen, blk_x + scr_x , blk_y * 2 + 1 + scr_y, color);
			}
			else
			{
				blit_to_buffer(screen, blk_x + scr_x, blk_y + scr_y, color);
				blit_to_buffer(screen, blk_x + scr_x + 1 , blk_y + scr_y, color);
			}
		}
	}
	mlx_put_image_to_window(data->mlx, data->window, screen->img, scr_x, scr_y);
}
*/
