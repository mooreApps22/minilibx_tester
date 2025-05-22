#include "../../inc/data.h"


int	close_window(void *data)
{
	exit_cleanup(data);
	return (0);
}

int	key_inputs(int key, void *data)
{
	if (key == XK_Escape || key == XK_q)
		close_window(data);
	return (0);
}
