#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void column_fix();
void check_swap();
void swap (int i1, int j1, int i2, int j2);

int a[9][9]={0},count[9]={0},numbers[9]={1,2,3,4,5,6,7,8,9};
int count_column[10]={}, flag_array[9][9]={}, column_global=0, count_0=0, count_not_0=0;

int randoms(){
    int num = (rand() % (9 - 1 + 1)) + 1;
    if(!num)
        num=randoms();
    return num;
}
void arrangeblockwise(){
    int n,i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            while(1){
                n=randoms();
                if(count[n-1]<1){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=0;i<3;i++){
        for(j=3;j<6;j++){
            while(1){
                n=randoms();
                if(count[n-1]<2){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=0;i<3;i++){
        for(j=6;j<9;j++){
            while(1){
                n=randoms();
                if(count[n-1]<3){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=3;i<6;i++){
        for(j=0;j<3;j++){
            while(1){
                n=randoms();
                if(count[n-1]<4){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=6;i<9;i++){
        for(j=0;j<3;j++){
            while(1){
                n=randoms();
                if(count[n-1]<5){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=3;i<6;i++){
        for(j=3;j<6;j++){
            while(1){
                n=randoms();
                if(count[n-1]<6){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=3;i<6;i++){
        for(j=6;j<9;j++){
            while(1){
                n=randoms();
                if(count[n-1]<7){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=6;i<9;i++){
        for(j=3;j<6;j++){
            while(1){
                n=randoms();
                if(count[n-1]<8){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
    for(i=6;i<9;i++){
        for(j=6;j<9;j++){
            while(1){
                n=randoms();
                if(count[n-1]<9){
                    count[n-1]++;
                    break;
                }
            }
            a[i][j]=n;
        }
    }
}
void arrangerowwise(){
    int p=8,i=0,j,k,l,temp;
    while(p--){
        for(j=0;j<9;j++)
            count[j]=0;
        for(j=0;j<9;j++){
            count[a[i][j]-1]++;
        }
        for(j=0;j<3;j++){
            if(count[(a[i][j])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                    for(l=0;l<3;l++){
                        if(count[(a[k][l])-1]==0){
                            temp=a[k][l];
                            a[k][l]=a[i][j];
                            a[i][j]=temp;
                            count[(a[k][l])-1]--;
                            count[(a[i][j])-1]++;
                        }
                    }
                }
            }
        }
        for(j=3;j<6;j++){
            if(count[(a[i][j])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                    for(l=3;l<6;l++){
                        if(count[(a[k][l])-1]==0){
                            temp=a[k][l];
                            a[k][l]=a[i][j];
                            a[i][j]=temp;
                            count[(a[k][l])-1]--;
                            count[(a[i][j])-1]++;
                        }
                    }
                }
            }
        }
        for(j=6;j<9;j++){
            if(count[(a[i][j])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                    for(l=6;l<9;l++){
                        if(count[(a[k][l])-1]==0){
                            temp=a[k][l];
                            a[k][l]=a[i][j];
                            a[i][j]=temp;
                            count[(a[k][l])-1]--;
                            count[(a[i][j])-1]++;
                        }
                    }
                }
            }
        }

        i++;
    }
}
void arrangecolwise(){
    int p=8,i=0,j,k,l,temp;
    while(p--){
        for(j=0;j<9;j++)
            count[j]=0;
        for(j=0;j<9;j++){
            count[a[j][i]-1]++;
        }
        for(j=0;j<3;j++){
            if(count[(a[j][i])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                        if(count[(a[j][k])-1]==0){
                            temp=a[j][k];
                            a[j][k]=a[j][i];
                            a[j][i]=temp;
                            count[(a[j][k])-1]--;
                            count[(a[j][i])-1]++;
                        }
                }
            }
        }
        for(j=0;j<3;j++){
            if(count[(a[j][i])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                        if(count[(a[j][k])-1]==0){
                            temp=a[j][k];
                            a[j][k]=a[j][i];
                            a[j][i]=temp;
                            count[(a[j][k])-1]--;
                            count[(a[j][i])-1]++;
                        }
                }
            }
        }
        for(j=0;j<3;j++){
            if(count[(a[j][i])-1]>1){
                for(k=i+1;k<((i/3)*3)+3;k++){
                        if(count[(a[j][k])-1]==0){
                            temp=a[j][k];
                            a[j][k]=a[j][i];
                            a[j][i]=temp;
                            count[(a[j][k])-1]--;
                            count[(a[j][i])-1]++;
                        }
                }
            }
        }
        i++;
    }
}
void sudokucheck(){
    int i,j,k,l,m,n;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            for(k=0;k<9;k++){
                if(a[i][j]==a[i][k]&&j!=k){
                    printf("dherbaalerrow\n");
                    return;
                }
            }
            for(k=0;k<9;k++){
                if(a[i][j]==a[k][j]&&i!=k){
                    printf("dherbaalercolumn\n");
                    return;
                }
            }
            for(k=(i/3)*3;k<((i/3)*3)+3;k++){
                for(l=(j/3)*3;l<((j/3)*3)+3;l++){
                    if(a[i][j]==a[k][l]&&i!=k&&j!=l){
                        printf("dherbaalerblock\n");
                        return;
                    }
                }
            }
        }
    }
    printf("shuvroboss\nAHAHAHAHAHAHAHA\t Bitch Please;\n");
    return;
}
int main(){
    srand(time(NULL));
    int i=0,j,p=8,k,l,temp;
    //arrangeblockwise();
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
            scanf("%d", &a[i][j]);
    }

    arrangerowwise();
    arrangecolwise();
    column_fix();
    sudokucheck();
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void column_fix() //fixes column
{
    for(column_global=0;column_global<9;column_global++) //column_global= which column to fix
    {
        int i=0, flag1, flag2;
        for(i=0;i<10;i++)
            count_column[i]=0;
        for(i=0;i<9;i++)
            count_column[a[i][column_global]]++;
        while(1)
        {
            flag1=0;
            flag2=0;
            for(i=1;i<10;i++)
            {
                if(count_column[i]==0)
                {
                    flag1=1;
                    count_0=i;
                    break;
                }
            }
            for(i=1;i<10;i++)
            {
                if(count_column[i]>1)
                {
                    flag2=1;
                    count_not_0=i;
                    break;
                }
            }
            if((flag1==1)||(flag2==1))
                check_swap();
            if(flag1==0 && flag2==0)
                break;
        }

    }
    return;
}

void check_swap()
{
    int i=0, j=column_global;
    int flag0=0, flag2=0;
    for(i=0;i<9;i++)  //checks first column to find if count2 and count0 can be swap-able directly
    {
        if(a[i][j]==count_not_0)
        {
            if((a[i][j+1]==count_0) && ((j+1)%3!=0) && (flag_array[i][j]==0) && (flag_array[i][j+1]==0))
            {
                swap(i, j, i, j+1);
                flag2=1;
                break;
            }
            else if((a[i][j+2]==count_0) && ((j+2)%3!=0) && (flag_array[i][j]==0) && (flag_array[i][j+2]==0))
            {
                swap(i, j, i, j+2);
                flag2=1;
                break;
            }
        }
//        if(flag2==1)
//            break;
    }

    if(flag2==0) //if count2 and count0 can NOT be swap-able directly, then checks for the count0 in the next column and swaps
    {
        int x=1;
        for(x=1; (x<3) && ((x+j)%3!=0); x++)
        {
            for(i=0; i<9; i++)
            {
                if((a[i][j+x]==count_0) && (flag_array[i][j]==0) && flag_array[i][j+x]==0)
                {
                    swap(i, j, i, j+x);
                    flag0=1;
                    break;
                }
            }
            if(flag0==1)
                break;
//            if(flag0==0)
//            {
//                for(i=0; i<9; i++)
//                {
//                    if((a[i][j+2]==count_0) && ((j+2)%3!=0) && (flag_array[i][j]==0) && flag_array[i][j+2]==0)
//                    {
//                        swap(i, j, i, j+2);
//                        flag0=1;
//                        break;
//                    }
//                }
//            }
        }
    }
    if(flag0==0 && flag2==0)
        printf("Not finding count0 and count2. Check for error in check_swap (& column_fix) func.\n");
}

void swap(int i1, int j1, int i2, int j2)
{
    int temp=a[i2][j2];
    a[i2][j2]=a[i1][j1];
    a[i1][j1]=temp;
    int x=0, y=0;
    for(x=0;x<9;x++)
    {
        for(y=0;y<9;y++)
            flag_array[x][y]=0;
    }
    flag_array[i1][j1]=1;
    flag_array[i2][j2]=1;
    count_column[a[i1][j1]]++;
    count_column[a[i2][j2]]--;
    if(count_column[a[i2][j2]]==0)
    {
        count_0=a[i2][j2];
        check_swap();
    }
    return;
}
