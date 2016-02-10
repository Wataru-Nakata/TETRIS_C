#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define width 12
#define height 21
#define blocksize 2
char block[blocksize][blocksize] = {
        {1,1},
        {1,1}
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
char field[height][width],collision_field[height][width];
void printfield(char c[height][width])
{
        int i,j;
        printf("\x1b[41m");
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

void exit_seq()
{
        printf("\x1b[0m");
        system("cls");
        exit(1);
}
int key_control(int *x,int *y)
{
        int key,i,j,tx = *x,ty = *y;
        if(kbhit()) {
                key = _getch();
                switch (key) {
                case 'a': tx-=1; break;
                case 'd': tx+=1; break;
                case 'q': exit_seq(); break;
                }
                //“–‚½‚è”»’è
                for(i = 0; i<blocksize; i++) {
                        for(j=0; j<blocksize; j++) {
                                if ((field[ty+i][tx+j] == 9)&&(block[i][j] == 1))
                                {
                                        return 0;
                                }
                        }
                }
                key = 0;
                *x = tx;
                return 1;
        }else{
                return 0;
        }
}
int main()
{

        int x = 5,y = 5,i,j;
        for(i = 0; i < height; i++) {
                for(j = 0; j< width; j++) {
                        field[i][j] = wall[i][j];
                }
        }
        while(1)
        {
                if(key_control(&x,&y)) {
                        system("cls");
                        for(i = 0; i < height; i++) {
                                for(j = 0; j< width; j++) {
                                        field[i][j] = wall[i][j];
                                }
                        }

                        for(i = 0; i<blocksize; i++) {
                                for(j=0; j<blocksize; j++) {
                                        field[y+i][x+j] = block[i][j];
                                }
                        }
                        for(i = 0; i < height; i++) {
                                for(j = 0; j< width; j++) {
                                        collision_field[i][j] = field[i][j];
                                }
                        }
                        printfield(field);
                }
        }
        return 0;
}
