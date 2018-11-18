#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randoms(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}
int main()
{
    int bc,br,n,k,l,flag=0, lower = 1, upper = 9;
    srand(time(0));
    int a[9][9]={},i,j;
    for(i=0; i<9; i++)
    {
        flag=0;
        for(j=0; j<9; j++)
        {
            while(1)
            {
                flag=0;
                n=randoms(lower,upper);
                for(k=0; k<i; k++)
                {
                    if(n==a[k][j]&&k!=i)
                        flag=1;
                    continue;
                }
                if(flag==0)
                {
                    for(k=0; k<j; k++)
                    {
                        if(n==a[i][k]&&k!=j)
                            flag=1;
                        continue;
                    }
                }

                br=i/3;
                bc=j/3;
                if(flag==0)
                {
                    for(k=br*3; (k<br+3) && (k<=i); k++)
                    {
                        for(l=bc*3; l<bc+3 && ((!(k==i))||(l<j)); l++)
                        {
                            if(n==a[k][l]&&k!=i&&l!=j)
                                flag=1;
                            break;
                        }
                        if(flag==1)
                            continue;
                    }
                }

                if(flag==0)
                {
                    a[i][j]=n;
                     printf("i:%d j:%d %d\t",i+1, j+1, a[i][j]);
                    break;
                }
            }
        }
    }
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            printf("i:%d j:%d %d\t",(i+1), (j+1), a[i][j]);
        }
        printf("\n");
    }
    return 0;
}


