#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>

void sudo_generate(int _level);
void column_fix();
void check_swap();
void swap (int i1, int j1, int i2, int j2);

void random_2();
void game_play(int _level);
void reduce_cell_candidate();
int check_1(); //easy
int check_2();

void cursor_play();

int menu();
int submenu_play();
int submenu_play_new();
//void save_game();
//void game_file(char *p, int size);
//void load_game();

int a[9][9]={0},count[9]={0},numbers[9]={1,2,3,4,5,6,7,8,9},  random_index[81]={}, cur_array[9][9]={}, game_array[9][9]={}, solve_array[9][9][10]={};
int count_column[10]={}, flag_array[9][9]={}, column_global=0, count_0=0, count_not_0=0;
int loop_check_1=0, loop_check_2=0;


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
    printf("shuvroboss\nAHAHAHAHAHAHAHA\t Bitch Please;\n\n");
    return;
}

int main(){
//    sudo_generate();
   int main_cur, sub_play_cur, sub_play_new_cur;
   main_cur=menu();
   if(main_cur==1)
        sub_play_cur=submenu_play();
   if(sub_play_cur==1)
        sub_play_new_cur= submenu_play_new();
    if(sub_play_new_cur)
        sudo_generate(sub_play_new_cur);
//    int i=0, j=0;
//    for(i=0;i<9;i++){
//        for(j=0;j<9;j++){
//            printf("%d\t",a[i][j]);
//        }
//        printf("\n");
//    }

/*    printf("\nTo save game, press S/s. To exit, press E/e. To go back to main menu, press esc.\n\n");
    char ch= getch();
    if(ch=='s'|| ch=='S')
        save_game();
    else if(ch=='e'||ch=='E')
    {
        printf("Exit without saving? Y/N:");
        ch=getch();
        if(ch=='y'||ch=='Y')
            exit(1);
        else if(ch=='n'||ch=='N')
        {
            save_game();
            exit(1);
        }
    }
    else if(ch==27)
        menu();
*/
    return 0;
}

void sudo_generate(int _level)
{
    system("cls");
    srand(time(NULL));
    arrangeblockwise();
    arrangerowwise();
    arrangecolwise();
    column_fix();
    sudokucheck();
    int i=0, j=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    game_play(_level);
    int count0=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            printf("%d\t", game_array[i][j]);
            if(game_array[i][j]==0)
                count0++;
        }
        printf("\n");
    }
    printf("\nCount 0: %d\n", count0);
    printf("press any key...");
    char ch=getch();
    cursor_play();
    return;
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

void random_2()
{
   srand(time(NULL));
   int num;
   int i=0, j=0, flag=0;
   for(i=0; i<81; i++)
    {
        flag=0;
        num = (rand() % 81);
        for(j=0; j<i; j++)
        {
            if(random_index[j]==num)
            {
                flag=1;
                i--;
                break;
            }
        }
        if(flag==1)
            continue;
        random_index[i]=num;
    }
    return;
}

void game_play(int _level)
{
    int i=0, j=0, ro=0, col=0, k=1, num, x=0, flag=1, count0=0; //*p=&cur_array[0][0]
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            cur_array[i][j]=a[i][j];
            game_array[i][j]=a[i][j];
        }
    }

    random_2();  //initializing "random_index[81]" array

    int level_size=81;
    if(_level==1)
        level_size= (rand() % (43 - 41 + 1))+ 41 ;
    int random_index_flag=0;

    for(i=0; i<level_size; i++)
    {

        if(random_index[i]==-1)
            continue;
        x=random_index[i];
        num=cur_array[x/9][x%9];
        cur_array[x/9][x%9]=0;

        for(ro=0; ro<9; ro++)
        {
            for(col=0; col<9; col++)
            {
                solve_array[ro][col][0]=cur_array[ro][col];
                if(solve_array[ro][col][0]==0)
                {
                    for(k=1; k<10; k++)
                        solve_array[ro][col][k]=1;       //initializing candidates
                }
            }
        }

        reduce_cell_candidate();  //reduce_cell_candidate

        //sudo_solver_check
        while(1)
        {
            if(_level==1)
            {
                loop_check_1=0;
                loop_check_1=check_1();

                if(loop_check_1==0)
                    break;
            }

            else if(_level==2)
            {
                loop_check_1=0;
                loop_check_2=0;

                loop_check_1=check_1();
                loop_check_2=check_2();
                if(loop_check_1==0 && loop_check_2==0)
                    break;
            }
        }

        //flag_res 0=> fail; 1=>success
        count0=0;
        flag=1;
        for(ro=0; ro<9; ro++)
        {
            for(col=0; col<9; col++)
            {
                    if(solve_array[ro][col][0]==0)
                    {
                        count0++;
                        flag=0;
                        break;
                    }
            }
            if(count0>0)
                break;
        }
        if(flag==1)  //success
        {
            for(ro=0; ro<9; ro++)
            {
                for(col=0; col<9; col++)
                    game_array[ro][col]=cur_array[ro][col];
            }
            random_index[i]=-1;  //think about it thoroughly
        }
        else if(flag==0)  //failed
            cur_array[x/9][x%9]=num;

        if(i==80 && random_index_flag<4 && _level==2)  //resetting random_index for _level=2;
            {
                i=0;
                random_index_flag++;
            }
    }
    return;
}

void cursor_play()
{
    int i=0, j=0;
    int cur_i=0, cur_j=0;
    char ch;
    while(1)
    {
        system("cls");
        for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
                printf(" %d \t", a[i][j]);
            printf("\n");
        }
        for(i=0; i<9; i++)
        {
            if(cur_i==i)
            {
                for(j=0; j<9; j++)
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
                    printf("| %d |\t", game_array[i][j]);
                else
                    printf(" %d \t", game_array[i][j]);
            }
            printf("\n");

            if(cur_i==i)
            {
                for(j=0; j<9; j++)
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
        //else if(ch==13)
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
            game_array[cur_i][cur_j]=ch-'0';
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

int check_1()  //easy
{
    int i, j, k=1, count_x=0, x, loop_flag=0;
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
                        }
                        //remove x
                        if(ro_flag==1)
                        {
                            loop_flag=1;
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
                        }
                        if(col_flag==1)
                        {
                            loop_flag=1;
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
                            if(block_flag==1) //remove x
                            {
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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
                                loop_flag=1;
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

int menu()
{
    int cur_pos=1;
    char ch;
    while(1)
    {

        system("cls");
        if(cur_pos==1)
            printf("==>\t1. PLAY GAME\n");
        else
            printf("   \t1. Play game\n");
        if(cur_pos==2)
            printf("==>\t2. PROFILE\n");
        else
            printf("   \t2. Profile\n");
        if(cur_pos==3)
            printf("==>\t3. EXIT\n");
        else
            printf("   \t3. Exit\n");
        printf("Press UP and DOWN arrow to navigate the menu");
        ch=getch();
        if(ch==13)
            break;
        else if(ch==72)
        {
            if(--cur_pos<1)
                cur_pos=3;
        }
        else if(ch==80)
        {
            if(++cur_pos>3)
                cur_pos=1;
        }
    }
    /*
    printf("\n\n");
    if (cur_pos==1)
        submenu_play();
    else if(cur_pos==2)
        printf("will do later\n");
    else if(cur_pos==3)
        exit(1);
    */
    return cur_pos;
}

int submenu_play()
{
    int cur_pos=1;
    char ch;
    while(1)
    {
        system("cls");
        if(cur_pos==1)
            printf("==>\t1. NEW GAME\n");
        else
            printf("   \t1. New game\n");
        if(cur_pos==2)
            printf("==>\t2. LOAD SAVED GAME\n");
        else
            printf("   \t2. Load saved game\n");
//        if(cur_pos==3)
//            printf("==>\t3.BACK\n");
//        else
//            printf("   \t3.BACK\n");
        printf("Press UP and DOWN arrow to navigate the menu\n\n");
        ch=getch();
        if(ch==13)
            break;
        else if(ch==72)
        {
            if(--cur_pos<1)
                cur_pos=2;
        }
        else if(ch==80)
        {
            if(++cur_pos>2)
                cur_pos=1;
        }
//        else if(ch==27)   //esc
//            break;
    }
    /*
    printf("\n\n");
    if(ch==27)
        menu();
    else if(cur_pos==1)
        sudo_generate();
    else if(cur_pos==2)
        {
            load_game();
            int i=0, j=0;
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                    printf("%d\t", a[i][j]);
                printf("\n");
            }
        }
    */
    return cur_pos;
}

int submenu_play_new()
{
    int cur_pos=1;
    char ch;
    while(1)
    {
        system("cls");
        printf("Difficulty level: \n");
        if(cur_pos==1)
            printf("==>\t1. EASY\n");
        else
            printf("   \t1. Easy\n");
        if(cur_pos==2)
            printf("==>\t2. MEDIUM\n");
        else
            printf("   \t2. Medium\n");
//        if(cur_pos==3)
//            printf("==>\t3. Hard\n");
//        else
//            printf("   \t3. Hard\n");
        printf("Press UP and DOWN arrow to navigate the menu\n\n");
        ch=getch();
        if(ch==13)
            break;
        else if(ch==72)
        {
            if(--cur_pos<1)
                cur_pos=2;
        }
        else if(ch==80)
        {
            if(++cur_pos>2)
                cur_pos=1;
        }
    }
    return cur_pos;
}
