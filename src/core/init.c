#include "../inc/data.h"

/*

typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		en;
	int		h;
	int		w;
}	t_image;

typedef struct	s_prac
{
	void	*mlx;
	void	*window;
	t_image	*screen;
	t_image	*block;
}	t_prac;

*/

int	create_images(t_prac *data)
{
	data->screen = malloc(sizeof(t_image));
	if (!data->screen)
		return (1);
	else
		memset(data->screen, 0, sizeof(t_image));
	data->block = malloc(sizeof(t_image));
	if (!data->block)
		return (2);
	else
		memset(data->block, 0, sizeof(t_image));

	data->screen->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->screen->addr = mlx_get_data_addr(data->screen->img,
		&data->screen->bpp, &data->screen->llen, &data->screen->en);

	data->block->img = mlx_xpm_file_to_image(data->mlx, "textures/big_east.xpm", &data->block->w, &data->block->h);
	data->reset_frame = 1;
	data->rotation = 0.0;
	return (0);
}

int	initialize(t_prac *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (perror("mlx failed init."), 1);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Practice");
	if (!data->mlx)
		return (perror("window failed init."), 2);
	if (create_images(data) != 0)
		return (perror("images failed init."), 3);
		
	return (0);
}
