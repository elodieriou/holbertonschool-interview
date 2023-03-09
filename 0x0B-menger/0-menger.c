#include "menger.h"

/**
 * merger - Function that draws a 2D Menger Sponge
 * @level: the level of the menger sponge to draw
 * Return: Nothing
 */
void menger(int level)
{
	int size, x, y, width;
	bool small, big;

	if (level < 0)
		return;

	else if (level == 0)
		printf("#\n");

	else
	{
		size = pow(3, level);
		for (x = 0; x < size; x++)
		{
			for (y = 0; y < size; y++)
			{
				width = size / 3;
				while (width >= 1)
				{
					small = x % 3 == 1 && y % 3 == 1;
					big = (x / width) % 3 == 1 && (y / width) % 3 == 1;
					if (big == true || small == true)
					{
						putchar(' ');
						break;
					}
					width /= 3;
				}
				if (width == 0)
					putchar('#');
			}
			putchar('\n');
		}
	}
}
