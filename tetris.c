#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define width 12
#define height 21

void printfield(char c[21][12])
{
        int i,j;
        //printf("\x1b[41m");
        for(j= 0; j<height; j++)
        {
                for(i= 0; i<width; i++)
                {
                        if(c[j][i] == 9) {
                                printf("¡");
                        }else if(c[j][i] == 1) {
                                printf(" ");
                        }else{
                                printf("@");
                        }
                }
                printf("\n");
        }
}

int main()
{
        char block[2][2] = {
                {1,1},
                {1,1},
        };
        char wall[21][12] ={
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,0,0,0,0,0,0,0,0,0,0,9},
                {9,9,9,9,9,9,9,9,9,9,9,9}
        };
        char field[height][width],key = 0;
        int x = 5,y = 5,i,j;
        while(1)
        {
                if(kbhit()) {
                        system("cls");
                        for(i = 0; i < height; i++) {
                                for(j = 0; j< width; j++) {
                                        field[i][j] = wall[i][j];
                                }
                        }
                        key = _getch();
                        switch (key) {
                        case 'a': y--; break;
                        case 'd': y++; break;
                        case 'q': goto out; break;
                        }
                        key = 0;
                        for(i = 0;i<2;i++){
                          for(j=0;j<2;j++){
                            field[x+i][y+j] = block[i][j];
                          }
                        }
                        printfield(field);
                }
        }
out:
				printf("\x1b[0m");
				system("cls");
        return 0;
}
