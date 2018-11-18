#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int array [9][9];
int main()
{
    int i=0, j=0;
    int cur_i=0, cur_j=0;
    char ch;
    while(1)
    {
        system("cls");
        for(i=0; i<9; i++)
        {
            if(cur_i==i)
            {
                for(j=0;j<9;j++)
                {
                    if(cur_j==j)
                        printf("+---+\t");
                    else
                        printf("   \t");
                }
            }
            printf("\n");

            for(j=0; j<9; j++)
            {
                if(cur_j==j && cur_i==i)
                    printf("| %d |\t", array[i][j]);
                else
                    printf(" %d \t", array[i][j]);
            }
            printf("\n");

            if(cur_i==i)
            {
                for(j=0;j<9;j++)
                {
                    if(cur_j==j)
                        printf("+---+\t");
                    else
                        printf("   \t");
                }
                //printf("\n");
            }
            //printf("\n");
        }
        ch=getch();
        if(ch==27)
            exit(1);
        else if(ch==80)
        {
            if(++cur_i>8)
                cur_i=0;
        }
        else if(ch==72)
        {
            if(--cur_i<0)
                cur_i=8;
        }
        else if(ch==77)
        {
            if(++cur_j>8)
                cur_j=0;
        }
        else if(ch==75)
         {
             if(--cur_j<0)
                cur_j=8;
        }
        else if(ch>48 && ch<58)
            array[cur_i][cur_j]=ch-'0';
    }
}
