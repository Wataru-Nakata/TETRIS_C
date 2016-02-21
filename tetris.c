	/*
	 * TETRIS Program
	 * Author : Wataru Nakata
	 * TODO: add blocks erase add score system.
	 */
#include  <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define width		12
#define height		21
#define blocksize	4
#define wallchar	9
#define blockchar	1
#define lockedblock 2
#define FALL_SPEED	1
#define blockNum	7
char block[blockNum][4][blocksize][blocksize] = {
	{ {
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			} },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 },
				{ 0, 0, 0, 0 }
			},

			{
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 }
			},

			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 1 },
				{ 0, 0, 0, 0 }
			},

			{
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 }
			}, },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			},

			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 }
			},

			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			},

			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 }
			} },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 1 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 1 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 }
			} },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 1 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			} },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 0, 1, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 1, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 1 },
				{ 0, 1, 0, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 0, 1, 0 },
				{ 0, 0, 1, 0 }
			} },

	{ {
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 0, 1, 1, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 1, 1, 1, 0 },
				{ 0, 1, 0, 0 }
			},
			{
				{ 0, 0, 0, 0 },
				{ 0, 1, 0, 0 },
				{ 1, 1, 0, 0 },
				{ 0, 1, 0, 0 }
			} }
};
char wall[height][width] = {
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9 },
	{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9 }
};
char field[height][width], collision_field[height][width];
void printfield(char c[height][width])
{
	int i, j;
	for(j = 0; j < height; j++)
	{
		for(i = 0; i < width; i++)
		{
			if(c[j][i] == wallchar)
			{
				printf("??");
			}
			else if((c[j][i] == blockchar) || (c[j][i] == lockedblock))
			{
				printf("??");
			}
			else
			{
				printf("?@");
			}
		}
		printf("\n");
	}
}

void exit_seq()
{
	printf("\x1b[0m");
	system("cls");
	exit(0);
}

int collision_condition(int y, int x)
{
	if((field[y][x] == 9) || (field[y][x] == 2))
	{
		return 1;
	}
	return 0;
}

int collision_detect(int tx, int ty)
{
	int i, j;
	for(i = 0; i < blocksize; i++)
	{
		for(j = 0; j < blocksize; j++)
		{
			if(collision_condition(ty + i, tx + j) && (block[i][j] == 1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int key_control(int* x, int* y)
{
	int key, i, j, tx = *x, ty = *y;
	if(kbhit())
	{
		key = _getch();
		switch(key)
		{
		case 'a': tx -= 1; break;
		case 'd': tx += 1; break;
		case 'q': exit_seq(); break;
		case 's':
			while(collision_detect(tx, ty + 1) == 0)
			{
				ty++;
			}
			break;
		}
		// ????????
		if(collision_detect(tx, ty))
		{
			return 0;
		}

		key = 0;
		*x	= tx;
		*y	= ty;
		return 1;
	}
	else
	{
		return 0;
	}
}

// change blocks to wall
void block2wall()
{
	int i, j;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			if(field[i][j] == blockchar)
			{
				wall[i][j] = 2;
			}
		}
	}
}

void checklines()
{
	int	 i, j, k, linecheck, remainline[height] = { 0 }, remaincount = 0;
	char temp_field[height][width];
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			temp_field[i][j] = wall[i][j];
		}
	}
	for(i = 0; i < height; i++)
	{
		linecheck = 1;
		for(j = 1; j < width - 1; j++)
		{
			if(wall[i][j] != lockedblock)
			{
				linecheck = 0;
			}
		}
		if(linecheck)
		{
			remainline[remaincount] = i;
			remaincount++;
		}
	}
}

int main()
{
	int	  x	   = 5, y = 5, i, j, c = 0, oh = 0;
	float time = 0, sectime = 0;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			field[i][j] = wall[i][j];
		}
	}
	while(1)
	{
		key_control(&x, &y);
		if(key_control(&x, &y) || c)
		{
			system("cls");
			for(i = 0; i < height; i++)
			{
				for(j = 0; j < width; j++)
				{
					field[i][j] = wall[i][j];
				}
			}

			for(i = 0; i < blocksize; i++)
			{
				for(j = 0; j < blocksize; j++)
				{
					field[y + i][x + j] += block[i][j];
				}
			}
			for(i = 0; i < height; i++)
			{
				for(j = 0; j < width; j++)
				{
					collision_field[i][j] = field[i][j];
				}
			}
			time = clock() / CLOCKS_PER_SEC - sectime;
			if(time == 1)
			{
				sectime++;
				y++;
			}
			printfield(field);
			c = 0;
		}
		time = clock() / (float) (CLOCKS_PER_SEC) -sectime;
		if(time >= 0.5)
		{
			sectime += 0.5;

			if(collision_detect(x, y + 1) == 0)
			{
				y++;
				oh = 0;
			}
			else
			{
				if(oh == 1)
				{
					x = 5;
					y = 5;
					block2wall();
					checklines();
				}
				oh = 1;
			}
			c = 1;
		}
	}
}
