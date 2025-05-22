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
	t_image	*screen;
	t_image	*block;
}	t_prac;

//SRC
int	exit_cleanup(t_prac *data);

//CORE
int	create_images(t_prac *data);
int	initialize(t_prac *data);

// HOOKS
int	close_window(void *data);
int	key_inputs(int key, void *data);



#endif
