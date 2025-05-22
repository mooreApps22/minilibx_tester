#ifndef DATA_H
# define DATA_H

# include "mlx.h"
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <X11/keysym.h>
#include <X11/X.h>        // for DestroyNotify, StructureNotifyMask


#ifndef WIDTH 
# define WIDTH 600 
#endif

#ifndef HEIGHT
# define HEIGHT 480
#endif

#ifndef ROTATE_STEP 
# define ROTATE_STEP 0.25f 
#endif


typedef struct	s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		en;
	int		w;
	int		h;
	int		x;
	int		y;
}	t_image;

typedef struct	s_prac
{
	void	*mlx;
	void	*window;
	int		reset_frame;
	t_image	*screen;
	t_image	*block;
	double	rotation;
}	t_prac;

//SRC
int	exit_cleanup(t_prac *data);

//CORE
int	create_images(t_prac *data);
int	initialize(t_prac *data);

// HOOKS
int	close_window(void *data);
int	key_inputs(int key, t_prac *data);

//RENDER
unsigned int	get_color(t_image* asset, int x, int y);
char			*get_image_addr(t_image *asset);
void			blit_to_buffer(t_image *asset, int x, int y, int color);
int				render_loop(t_prac *data);
void			render_frame(t_prac *data, t_image *screen, t_image *block);

#endif
