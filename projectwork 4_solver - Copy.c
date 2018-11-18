//adding solver algorithm _mueeze

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>


int solve_array[9][9][10];


void reduce_cell_candidate();
void check_1(); //easy
void check_2(); //medium
int main()
{
    int i, j, k;

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
    for(i=0;i<30;i++)
        check_1();  //easy

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            printf("%d\t", solve_array[i][j][0]);
        printf("\n");
    }
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

void check_1()  //easy
{
    int i, j, k=1, count_x=0, x;
    int ro, col, col_flag=0, ro_flag=0, block_flag=0;

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(solve_array[i][j][0]==0)
            {
                // if there's only one candidate
                int count_1=0;
                for(k=1;k<10;k++)
                {
                    if(solve_array[i][j][k]>0)
                    {
                        x=k;
                        count_1++;
                    }
                }
                if(count_1==1)
                {
                    solve_array[i][j][0]=x;

                    //remove x
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

                //if there's more candidate in a cell

                for(k=1; k<10; k++) //number of candidates in a cell
                {
                    count_x=0;

                    if(solve_array[i][j][k]>0)
                    {
                        x=k;
                        count_x=1;

                        //row check if x occurred 1 time;
                        for(col=0; col<9; col++)
                        {
                            if(solve_array[i][col][k]>0)
                                count_x++;
                        }
                        if(count_x==1)  //if x occurred 1 time in row, then put x in the candidate cell in consideration
                        {
                            solve_array[i][j][0]=x;
                            col_flag=1;
                        }
                        //remove x
                        if(col_flag==1)
                        {
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

                        //col check if x occurred 1 time;
                        count_x=1;
                        for(ro=0; ro<9; ro++)
                        {
                            if(solve_array[ro][j][k]>0)
                                count_x++;
                        }
                        if(count_x==1)
                        {
                            solve_array[i][j][0]=x;
                            ro_flag=1;
                        }
                        if(ro_flag==1)
                        {
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
                        count_x=1;
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                            if(block_flag==1) //remove x
                            {
                                for(col=0;col<9;col++) //remove x from row
                                    solve_array[i][col][x]=0;
                                for(ro=0;ro<9;ro++)    //remove x from column
                                    solve_array[ro][j][x]=0;

                                solve_array[i][j][x]=0; //remove x from that block
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
                                solve_array[i][j][0]=x;   //x occurred 1 time in block, so put x in the cell
                            }
                            if(block_flag==1) //remove x
                            {
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
    }
}

void check_2()  //medium
{
    int i, j, k=1, count_x=0, x;
    int ro, col, col_flag=0, ro_flag=0, block_flag=0;
    for()
}

