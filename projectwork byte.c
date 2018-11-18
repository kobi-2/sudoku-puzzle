#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int flag_array[9][9];
int main()
{
//    flag_array[9][9]={};
// for(i=0;i<10;i++)
//    {
//        for(j=0;j<10;j++)
//        flag_array[i][j]);
//    }
    int i, j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
            printf("%d\t", flag_array[i][j]);
        printf("\n");
    }
}


void menu()
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
    if (cur_pos==1)
        submenu_play();
    return cur_pos;
}

void submenu_play()
{
    int cur_pos=1;
    char ch;
    while(1)
    {
        system("cls")
        if(cur_pos==1)
            printf("==>\t1.NEW GAME\n");
        else
            printf("   \t1. New game\n");
        if(cur_pos==2)
            printf("==>\t2.LOAD SAVED GAME\n");
        else
            printf("   \t2.Load saved game\n");
//        if(cur_pos==3)
//            printf("==>\t3.BACK\n");
//        else
//            printf("   \t3.BACK\n");
        printf("Press UP and DOWN arrow to navigate the menu");
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
        else if(ch==27)
            break;
    }
    if(ch==27)
        menu();
    else if(cur_pose==1)
        sudo_generate();
    else if(cur_pos==2)
        printf("under contruction\n");

}
