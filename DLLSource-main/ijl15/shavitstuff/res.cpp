#include "res.h"

void change_res(int width, int height)
{
	if (height != 600) write_to_mem(0x0064208F + 1, 300 + static_cast<int>((768 - 600) / 1.75f)); // viewrange.bottom
	write_to_mem<uint8_t>(0x00620827 + 1, 120);
}