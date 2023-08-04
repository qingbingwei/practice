//
// Created by 38016 on 2023/8/3.
//
#include <stdio.h>
#include "game.h"
void menu()
{
    printf("*****************************\n");
    printf("****** 1. play 0. exit ******\n");
    printf("*****************************\n");

}
void game()
{
    char ret = 0;
    printf("start game\n");
    char board[ROW][COL]={0};

    //初始化棋盘函数（空格）,否则棋盘会歪掉
    InitBoard(board,ROW,COL);
    //打印棋盘函数
    DisplayBoard(board,ROW,COL);
    while (1)
    {
        PlayerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')
        {
            break;
        }
        //判断输赢
        ComputerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')
        {
            break;
        }

        //判断输赢
    }
    if(ret == '*')
    {
        printf("Congratulate,you win!\n");
    }
    else if(ret == '#')
    {
        printf("Oh no,you lose...\n");
    }
    else
    {
        printf("Draw,again?\n");
    }
}
void InitBoard(char board[ROW][COL],int row, int col)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < row;i++)
    {
        for(j = 0;j <col;j++)
        {
            board[i][j] = ' ';
        }
    }
}
//打印版本1，暴力打印，不方便后续变更棋盘大小
/*void DisplayBoard(char board[ROW][COL],int row,int col)
{
     int i = 0;
     for(i = 0;i < row;i++)
     {
         //打印数据
         printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
         //打印分割信息
         if(i < row-1)
         printf("---|---|---\n");
     }
}*/
//打印版本2（大小可更改）
void DisplayBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    for(i = 0;i < row;i++)
    {
        int j = 0;
        //打印数据
        for(j = 0;j < col;j++)
        {

            printf(" %c ",board[i][j]);
            if(j < col-1)
                printf("|");
        }
        printf("\n");
        //打印分割信息
        if(i < row-1)
        {
            for(j = 0;j < col;j++)
            {
                printf("---");
                if(j < col-1)
                    printf("|");
            }
            printf("\n");
        }
    }
}
void PlayerMove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;

    printf("player move:>\n");

    while(1)
    {
        printf("please scanf:>");
        scanf("%d %d",&x,&y);
        //坐标范围合法判断
        if(x >=1 && x <= row && y >=1 && y <= col)
        {
            if(board[x - 1][y -1] == ' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("wrong,please choose again\n");
            }
        }
        else
        {
            printf("wrong,please scanf again\n");
        }
    }
}
//在空白位置随机下棋
void ComputerMove(char board[ROW][COL],int row, int col)
{
    int x = 0;
    int y = 0;
    printf("computer move>\n");

    while (1)
    {
        x = rand()%row;//0 ~ 2
        y = rand()%col;//0 ~ 2
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}
//判断输赢
char IsWin(char board[ROW][COL],int row,int col)
{
    //先行，再列，最后对角线
    //行
    int i = 0;
    for(i = 0;i < row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];//避免不必要的的判断
        }
    }
    //列
    int j = 0;
    for(j = 0;j < col;j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
        {
            return board[1][j];//避免不必要的的判断
        }
    }
    //对角线
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //判断平局
    if(IsFull(board,row,col))
    {
        return 'Q';//平局
    }

    //游戏继续
    return 'C';
    //玩家赢 -congratulate！
    //电脑赢 -oh no...
    //继续 -continue   C
    //平局 -again？  Q
}
int IsFull(char board[ROW][COL],int row,int col)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < row;i++)
    {
        for(j = 0;j < col;j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
    //满了返回1.否则返回0
}
