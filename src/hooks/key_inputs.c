#include "../../inc/data.h"


int	close_window(void *data)
{
	exit_cleanup(data);
	return (0);
}

int	key_inputs(int key, t_prac *data)
{
	if (key == XK_Escape || key == XK_q)
		close_window(data);
	else if (key == XK_a)
	{
		data->rotation -= ROTATE_STEP;
		if (data->rotation < -50.0f)
			data->rotation = -50.0f;
	}
	else if (key == XK_d)
	{
		data->rotation += ROTATE_STEP;
		if (data->rotation > 50.0f)
			data->rotation = 50.0f;
	}
	data->reset_frame = 1;
	memset(data->screen->addr, 0, data->screen->llen * HEIGHT);
	return (0);
}
