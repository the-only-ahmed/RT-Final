#include "rt.h"

unsigned long		creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void				image_pixel_put(t_data *e, int x, int y, int color)
{
	int addr;

	addr = (e->bpp >> 3) * ((y * (e->sl >> 2)) + x);
	memcpy(e->str + addr, &color, 4);
}
