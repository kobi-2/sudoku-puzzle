//adding solver algorithm _mueeze

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int solve_array[9][9][10];


void reduce_cell_candidate();
int check_1(); //easy
int check_2(); //medium
int check_3(); //hard

int main()
{
    int i, j, k, loop_check_1=0, loop_check_2=0, loop_check_3=0, flag=0;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            scanf("%d", &solve_array[i][j][0]);  //array input
            if(solve_array[i][j][0]==0)
            {
                for(k=1; k<10; k++)
                    solve_array[i][j][k]=1;       //initializing candidates
            }
        }
    }

    reduce_cell_candidate();
    int q=0;
    flag=0;
    while(1)
    {
        loop_check_1=0;
        loop_check_2=0;
        loop_check_3=0;

        loop_check_1=check_1();  //easy
        loop_check_2=check_2();  //medium??
        loop_check_3= check_3(); //hard

        q++;
        if(loop_check_1==0 && loop_check_2==0 && loop_check_3==0)
            break;

    }

    printf("loop count: %d\nFinal: \n", q);
    int count0=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            printf("%d\t", solve_array[i][j][0]);
            if(solve_array[i][j][0]==0)
                count0++;
        }

        printf("\n");
    }
    printf("count 0: %d\n", count0);
}

void reduce_cell_candidate()
{
    int i=0, j=0, k=1;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(solve_array[i][j][0]==0)
            {
                for(k=1; k<10; k++)     // k = 3D element
                {
                    if(solve_array[i][j][k]>0) //candidate check
                    {
                        int x=k;
                        int ro, col, col_flag=0, ro_flag=0, block_flag=0;

                        //row check
                        for(col=0; col<9; col++)
                        {
                            if(solve_array[i][col][0]==x)
                            {
                                solve_array[i][j][k]=0;
                                ro_flag=1;
                                break;
                            }
                        }
                        if(ro_flag==1)
                            continue;

                        //column check
                        for(ro=0; ro<9; ro++)
                        {
                            if(solve_array[ro][j][0]==x)
                            {
                                solve_array[i][j][k]=0;
                                col_flag=1;
                                break;
                            }
                        }
                        if(col_flag==1)
                            continue;

                        //block check

                        //1st block
                        if(i>=0 && i<3 && j>=0 && j<3)
                        {
                            for(ro=0; ro<3; ro++)
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //2ns block
                        else if(i>=0 && i<3 && j>2 && j<6)
                        {
                            for(ro=0; ro<3; ro++)
                            {
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }
                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;


                        //3rd block
                        else if(i>=0 && i<3 && j>5 && j<9)
                        {
                            for(ro=0; ro<3; ro++)
                            {
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //4th block
                        else if(i>2 && i<6 && j>=0 && j<3)
                        {
                            for(ro=3; ro<6; ro++)
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //5th block
                        else if(i>2 && i<6 && j>2 && j<6)
                        {
                            for(ro=3; ro<6; ro++)
                            {
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //6th block
                        else if(i>2 && i<6 && j>5 && j<9)
                        {
                            for(ro=3; ro<6; ro++)
                            {
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //7th block
                        else if(i>5 && i<9 && j>=0 && j<3)
                        {
                            for(ro=6; ro<9; ro++)
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //8th block
                        else if(i>5 && i<9 && j>2 && j<6)
                        {
                            for(ro=6; ro<9; ro++)
                            {
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        if(block_flag==1)
                            continue;

                        //9th block
                        else if(i>5 && i<9 && j>5 && j<9)
                        {
                            for(ro=6; ro<9; ro++)
                            {
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][0]==x)
                                    {
                                        solve_array[i][j][k]=0;
                                        block_flag=1;
                                        break;
                                    }
                                }

                                if(block_flag==1)
                                    break;
                            }
                        }
                        //end of block check
                    }
                }
            }
        }
    }
}

int check_1()  //easy
{
    int i, j, k=1, l=1, count_x=0, x, loop_flag=0;
    int ro, col, col_flag=0, ro_flag=0, block_flag=0;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(solve_array[i][j][0]==0)
            {
                // count number of candidates
                int count_1=0;
                for(k=1;k<10;k++)
                {
                    if(solve_array[i][j][k]>0)
                    {
                        x=k;
                        count_1++;
                    }
                }

                if(count_1==1)  //if there's only one candidate
                {
                    solve_array[i][j][0]=x;

                    //remove x
                            loop_flag=1;
                            solve_array[i][j][x]=0;  //remove x from that cell
                            for(col=0; col<9; col++) //remove x from that row
                                solve_array[i][col][x]=0;
                            for(ro=0; ro<9; ro++)     //remove x form that column
                                solve_array[ro][j][x]=0;

                            if(i>=0 && i<3 && j>=0 && j<3)                   //remove x from that block
                            {
                                //1st block
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>2 && j<6)      //2nd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>5 && j<9)      //3rd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>=0 && j<3)      //4th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>2 && j<6)      //5th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>5 && j<9)      //6th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>=0 && j<3)      //7th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>2 && j<6)      //8th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>5 && j<9)      //9th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            continue;
                }

                //if there's more candidate in a cell

                for(k=1; k<10; k++) //k = candidates in a cell
                {
                    count_x=0;
                    col_flag=0;
                    ro_flag=0;
                    block_flag=0;

                    if(solve_array[i][j][k]>0)
                    {
                        x=k;
                        count_x=0;

                        //row check if x occurred 1 time;
                        for(col=0; col<9; col++)
                        {
                            if(solve_array[i][col][k]>0)
                                count_x++;
                        }

                        if(count_x==1)  //if x occurred 1 time in row, then put x in the candidate cell in consideration
                        {
                            solve_array[i][j][0]=x;
                            ro_flag=1;

                        //remove x

                            loop_flag=1;
                            for(l=1; l<10; l++)        //remove every candidate from that cell
                                solve_array[i][j][l]=0;
                            for(col=0; col<9; col++) //remove x from that row
                                solve_array[i][col][x]=0;
                            for(ro=0; ro<9; ro++)     //remove x form that column
                                solve_array[ro][j][x]=0;

                            if(i>=0 && i<3 && j>=0 && j<3)                   //remove x from that block
                            {
                                //1st block
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>2 && j<6)      //2nd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>5 && j<9)      //3rd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>=0 && j<3)      //4th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>2 && j<6)      //5th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>5 && j<9)      //6th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>=0 && j<3)      //7th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>2 && j<6)      //8th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>6 && j<9)      //9th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }

                            continue;
                        }

                        //col check if x occurred 1 time;
                        count_x=0;
                        for(ro=0; ro<9; ro++)
                        {
                            if(solve_array[ro][j][k]>0)
                                count_x++;
                        }
                        if(count_x==1)
                        {
                            solve_array[i][j][0]=x;
                            col_flag=1;

                        //remove x

                            loop_flag=1;
                            for(l=1; l<10; l++)        //remove every candidate from that cell
                                solve_array[i][j][l]=0;
                            for(col=0; col<9; col++) //remove x from that row
                                solve_array[i][col][x]=0;
                            for(ro=0; ro<9; ro++)     //remove x form that column
                                solve_array[ro][j][x]=0;

                            if(i>=0 && i<3 && j>=0 && j<3)                   //remove x from that block
                            {
                                //1st block
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>2 && j<6)      //2nd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>=0 && i<3 && j>5 && j<9)      //3rd block
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>=0 && j<3)      //4th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>2 && j<6)      //5th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>2 && i<6 && j>5 && j<9)      //6th block
                            {
                                for(ro=3; ro<6; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>=0 && j<3)      //7th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=0; col<3; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>2 && j<6)      //8th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=3; col<6; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }
                            else if(i>5 && i<9 && j>6 && j<9)      //9th block
                            {
                                for(ro=6; ro<9; ro++)
                                {
                                    for(col=6; col<9; col++)
                                        solve_array[ro][col][x]=0;
                                }
                            }

                            continue;
                        }
                        //end of remove

                        //block check if x occurred 1 time
                        count_x=0;
                        if(i>=0 && i<3 && j>=0 && j<3) //1st block
                        {
                            for(ro=0;ro<3;ro++)
                            {
                                for(col=0;col<3;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }

                        else if(i>=0 && i<3 && j>2 && j<6)  //2nd block
                        {
                            for(ro=0;ro<3;ro++)
                            {
                                for(col=3;col<6;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }

                        else if(i>=0 && i<3 && j>5 && j<9)  //3rd block
                        {
                            for(ro=0;ro<3;ro++)
                            {
                                for(col=6;col<9;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }
                        else if(i>2 && i<6 && j>=0 && j<3)  //4th block
                        {
                            for(ro=3;ro<6;ro++)
                            {
                                for(col=0;col<3;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }
                        else if(i>2 && i<6 && j>2 && j<6)  //5th block
                        {
                            for(ro=3;ro<6;ro++)
                            {
                                for(col=3;col<6;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }
                        else if(i>2 && i<6 && j>5 && j<9)  //6th block
                        {
                            for(ro=3;ro<6;ro++)
                            {
                                for(col=6;col<9;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                                }
                        }
                        else if(i>5 && i<9 && j>=0 && j<3)  //7th block
                        {
                            for(ro=6;ro<9;ro++)
                            {
                                for(col=0;col<3;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }
                        else if(i>5 && i<9 && j>2 && j<6)  //8th block
                        {
                            for(ro=6;ro<9;ro++)
                            {
                                for(col=3;col<6;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                        }
                        else if(i>5 && i<9 && j>5 && j<9)  //9th block
                        {
                            for(ro=6;ro<9;ro++)
                            {
                                for(col=6;col<9;col++)
                                {
                                    if(solve_array[ro][col][k]>0)  //counting x
                                        count_x++;
                                }
                            }
                            if(count_x==1)
                            {
                                block_flag=1;
                                solve_array[i][j][0]=x;  //x occurred 1 time in block, so put x in the cell
                            }
                        }

                        //remove x for block check
                        if(block_flag==1)
                        {
                            loop_flag=1;
                                for(l=1; l<10; l++)        //remove every candidate from that cell
                                    solve_array[i][j][l]=0;
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
                        }

                    }
                }

            }
        }
    }
    return loop_flag;
}

int check_2()  //medium
{
    int i, j, k=1, count_x=0, x, loop_flag=0;
    int ro, col, col_flag=0, ro_flag=0, block_flag=0, flag_1=0, flag_0=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(solve_array[i][j][0]==0)
            {
                for(k=1;k<10;k++)
                {
                    count_x=0;
                    if(solve_array[i][j][k]>0)
                    {
                        //1. "same col/row in same block. absent in other columns/rows in that block. ==> remove x from other blocks' same col/row"
                        //2. "absent in the same row/col in other 2 blocks. ==> remove x from other cells in that block."

                        if(i>=0 && i<3 && j>=0 && j<3) //1st block
                        {
                            for(col=0; col<3; col++) //column check  //count x
                            {
                                if(col==j)
                                    continue;
                                for(ro=0; ro<3;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=3; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=0; ro<3; ro++)  //row check //count x
                            {
                                if(ro==i)
                                    continue;
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=3; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }

                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=3; ro<9; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=0; col<3; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=0; ro<3; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=3; col<9; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=0; ro<3; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=0; col<3; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }

                        else if(i>=0 && i<3 && j>2 && j<6) //2nd block
                        {
                            for(col=3; col<6; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=0; ro<3;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=3; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=0; ro<3; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=3; ro<9; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=3; col<6; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=0; ro<3; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<3; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            for(col=6; col<9; col++)  //row check //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=0; ro<3; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=3; col<6; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>=0 && i<3 && j>5 && j<9)  // 3rd block
                        {
                            for(col=6; col<9; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=0; ro<3;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=3; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=0; ro<3; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<6; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=3; ro<9; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=6; col<9; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=0; ro<3; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<6; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=0; ro<3; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=6; col<9; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>2 && i<6 && j>=0 && j<3)  // 4th block
                        {
                            for(col=0; col<3; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=3; ro<6;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(ro=6; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=3; ro<6; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=3; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<3; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            for(ro=6; ro<9; ro++)
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=0; col<3; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=3; ro<6; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=3; col<9; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=3; ro<6; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=0; col<3; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>2 && i<6 && j>2 && j<6)  //5th block
                        {
                            for(col=3; col<6; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=3; ro<6;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(ro=6; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=3; ro<6; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<3; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            for(ro=6; ro<9; ro++)
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=3; col<6; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=3; ro<6; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<3; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            for(col=6; col<9; col++)
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=3; ro<6; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=3; col<6; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>2 && i<6 && j>5 && j<9)  //6th block
                        {
                            for(col=6; col<9; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=3; ro<6;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<3; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(ro=6; ro<9; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=3; ro<6; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<6; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<3; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            for(ro=6; ro<9; ro++)
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=6; col<9; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=3; ro<6; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<6; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=3; ro<6; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=6; col<9; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>5 && i<9 && j>=0 && j<3)  //7th block
                        {
                            for(col=0; col<3; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=6; ro<9;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<6; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=6; ro<9; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=3; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<6; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=0; col<3; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=6; ro<9; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=3; col<9; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=6; ro<9; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=0; col<3; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>5 && i<9 && j>2 && j<6)  //8th block
                        {
                            for(col=3; col<6; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=6; ro<9;ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<6; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=6; ro<9; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=3; col<6; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<3; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<6; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=3; col<6; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=6; ro<9; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<3; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            for(col=6; col<9; col++)
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=6; ro<9; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=3; col<6; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        else if(i>5 && i<9 && j>5 && j<9)  //9th block
                        {
                            for(col=6; col<9; col++) //column check //count_x
                            {
                                if(col==j)
                                    continue;
                                for(ro=6; ro<9; ro++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same column
                            {
                                for(ro=0; ro<6; ro++)
                                {
                                    if(solve_array[ro][j][k]>0)
                                    {
                                        solve_array[ro][j][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;
                            for(ro=6; ro<9; ro++)  //row check //count_x
                            {
                                if(ro==i)
                                    continue;
                                for(col=6; col<9; col++)
                                {
                                    if(solve_array[ro][col][k]>0)
                                        count_x++;
                                }
                            }
                            if(count_x==0) //remove x from other block's same row
                            {
                                for(col=0; col<6; col++)
                                {
                                    if(solve_array[i][col][k]>0)
                                    {
                                        solve_array[i][col][k]=0;
                                        loop_flag=1;
                                    }
                                }
                            }
                            count_x=0;

                            // commencing 2.
                            for(ro=0; ro<6; ro++) //column check  //count x
                            {
                                if(solve_array[ro][j][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(col=6; col<9; col++) //removing x from that block's other columns
                                {
                                    if(col==j)
                                        continue;
                                    for(ro=6; ro<9; ro++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                             solve_array[ro][col][k]=0;
                                             loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                            for(col=0; col<6; col++)  //row check  //count x
                            {
                                if(solve_array[i][col][k]>0)
                                    count_x++;
                            }
                            if(count_x==0)
                            {
                                for(ro=6; ro<9; ro++)  //removing x from that block's other rows
                                {
                                    if(ro==i)
                                        continue;
                                    for(col=6; col<9; col++)
                                    {
                                        if(solve_array[ro][col][k]>0)
                                        {
                                            solve_array[ro][col][k]=0;
                                            loop_flag=1;
                                        }
                                    }
                                }
                            }
                            count_x=0;
                        }
                        // end

                    }
                }
            }
        }
    }
    return loop_flag;
}

int check_3()  //hard
{
    int i, j, k=1, l=1, count_x=0, x, loop_flag=0, count_candidate=0, m, n;
    int ro, col, col_flag=1, ro_flag=1, block_flag=1;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(solve_array[i][j][0]==0)
            {
                count_candidate=0;
                int c[2]={};
                x=0;
                for(k=1; k<10; k++)
                {
                    if(solve_array[i][j][k]>0)
                    {
                        count_candidate++;
                        c[x]=k;
                        x++;
                    }

                }
                if(count_candidate==2)
                {
                    //row
                    for(col=0, ro=i; col<9; col++)
                    {
                        ro_flag=1;
                        if(col==j)
                            continue;
                        if(solve_array[ro][col][0]==0)
                        {
                            count_candidate=0;
                            for(k=1; k<10; k++)
                            {
                                if(solve_array[ro][col][k]>0)
                                    count_candidate++;
                            }
                            if(count_candidate==2)
                            {
                                for(k=1; k<10; k++)
                                {
                                    if(solve_array[i][j][k]!=solve_array[ro][col][k])
                                    {
                                        ro_flag=0;
                                        break;
                                    }
                                }
                                if(ro_flag==1)
                                {

                                    for(n=0, m=i; n<9; n++) //deleting candidates from row
                                    {
                                        if(n==j || n==col)
                                            continue;
                                        if(solve_array[m][n][c[0]]>0 || solve_array[m][n][c[1]]>0)
                                        {
                                            loop_flag=1;
                                            solve_array[m][n][c[0]]=0;
                                            solve_array[m][n][c[1]]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    //column
                      for(ro=0, col=j; ro<9; ro++)
                    {
                        col_flag=1;
                        if(ro==i)
                            continue;
                        if(solve_array[ro][col][0]==0)
                        {
                            count_candidate=0;
                            for(k=1; k<10; k++)
                            {
                                if(solve_array[ro][col][k]>0)
                                    count_candidate++;
                            }
                            if(count_candidate==2)
                            {
                                for(k=1; k<10; k++)
                                {
                                    if(solve_array[i][j][k]!=solve_array[ro][col][k])
                                    {
                                        col_flag=0;
                                        break;
                                    }
                                }
                                if(col_flag==1)
                                {

                                    for(m=0, n=j; m<9; m++) //deleting candidates from column
                                    {
                                        if(m==i || m==ro)
                                            continue;
                                        if(solve_array[m][n][c[0]]>0 || solve_array[m][n][c[1]]>0)
                                        {
                                            loop_flag=1;
                                            solve_array[m][n][c[0]]=0;
                                            solve_array[m][n][c[1]]=0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return loop_flag;
}
