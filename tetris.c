/*
 * TETRIS Program
 * Author : Wataru Nakata
 * TODO: add blocks add score system.
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
char field[height][width], collision_field[height][width], temp_field[height][width];
void printfield(char c[height][width])
{
	int i, j;
	for(j = 0; j < height; j++)
	{
		for(i = 0; i < width; i++)
		{
			if(c[j][i] == wallchar)
			{
				printf("■");
			}
			else if((c[j][i] == blockchar) || (c[j][i] == lockedblock))
			{
				printf("□");
			}
			else
			{
				printf("　");
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

int collision_detect(int tx, int ty, int blockselect, int tilt)
{
	int i, j;
	for(i = 0; i < blocksize; i++)
	{
		for(j = 0; j < blocksize; j++)
		{
			if(collision_condition(ty + i, tx + j) && (block[blockselect][tilt][i][j] == 1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int key_control(int* x, int* y, int* t, int blockse)
{
	int key, i, j, tx = *x, ty = *y, tempt = *t;
	if(kbhit())
	{
		key = _getch();
		switch(key)
		{
		case 'a': tx -= 1; break;
		case 'd': tx += 1; break;
		case 'w': tempt++; break;
		case 'q': exit_seq(); break;
		case 's':
			while(collision_detect(tx, ty + 1, blockse % blockNum, tempt % 4) == 0)
			{
				ty++;
			}
			break;
		}

		if(collision_detect(tx, ty, blockse % blockNum, tempt % 4))
		{
			return 0;
		}

		key = 0;
		*x	= tx;
		*y	= ty;
		*t	= tempt;
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
	int i, j, k, linecheck, remainline[height] = { 0 }, remaincount = 0, delcount = 0;
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
		if(linecheck == 0)
		{
			remainline[remaincount] = i;
			remaincount++;
		}
		else
		{
			for(j = 0; j < width; j++)
			{
				temp_field[i][j] = 0;
			}
			delcount++;
		}
	}
	k = delcount;
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			wall[k][j] = temp_field[remainline[i]][j];
		}
		k++;
	}
}

int main()
{
	int x = width/2, y = 0, i, j, c = 0, oh = 0, bs= 0, tilt = 0,
		blockori[blockNum] = { 0, 1, 2, 3, 4, 5, 6}, blockselect[blockNum],
		index;
	float  Nowtime = 0, sectime = 0;
	time_t randseed;
	for(i = 0; i < blockNum; i++)
	{
		index = rand() % (blockNum - i);
		blockselect[i] = blockori[index];
		for(j = index; j < blockNum - 1; j++)
		{
			blockori[j] = blockori[j + 1];
		}
	}
	for(i = 0; i < height; i++)
	{
		for(j = 0; j < width; j++)
		{
			field[i][j] = wall[i][j];
		}
	}
	randseed = time(NULL);
	srand((unsigned int) randseed);
	while(1)
	{
		if(key_control(&x, &y, &tilt, bs) || c)
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
					field[y + i][x + j] += block[blockselect[bs]][tilt % 4][i][j];
				}
			}
			for(i = 0; i < height; i++)
			{
				for(j = 0; j < width; j++)
				{
					collision_field[i][j] = field[i][j];
				}
			}
			Nowtime = clock() / CLOCKS_PER_SEC - sectime;
			if(Nowtime == 1)
			{
				sectime++;
				y++;
			}
			printfield(field);
			printfield(temp_field);
			c = 0;
		}
		Nowtime = clock() / (float) (CLOCKS_PER_SEC) -sectime;
		if(Nowtime >= 0.5)
		{
			sectime += 0.5;

			if(collision_detect(x, y + 1, blockselect[bs], tilt % 4) == 0)
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
					bs++;
					if(bs >= blockNum)
					{
						bs = 0;
						// ブロック乱数
						for(i = 0; i < blockNum; i++)
						{
							index = rand() % (blockNum - i);
							blockselect[i] = blockori[index];
							for(j = index; j < blockNum - 1; j++)
							{
								blockori[j] = blockori[j + 1];
							}
						}
					}
				}
				oh = 1;
			}
			c = 1;
		}
	}
}
