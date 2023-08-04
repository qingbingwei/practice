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

    //��ʼ�����̺������ո�,�������̻����
    InitBoard(board,ROW,COL);
    //��ӡ���̺���
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
        //�ж���Ӯ
        ComputerMove(board,ROW,COL);
        DisplayBoard(board,ROW,COL);
        ret = IsWin(board,ROW,COL);
        if(ret != 'C')
        {
            break;
        }

        //�ж���Ӯ
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
//��ӡ�汾1��������ӡ�����������������̴�С
/*void DisplayBoard(char board[ROW][COL],int row,int col)
{
     int i = 0;
     for(i = 0;i < row;i++)
     {
         //��ӡ����
         printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
         //��ӡ�ָ���Ϣ
         if(i < row-1)
         printf("---|---|---\n");
     }
}*/
//��ӡ�汾2����С�ɸ��ģ�
void DisplayBoard(char board[ROW][COL],int row,int col)
{
    int i = 0;
    for(i = 0;i < row;i++)
    {
        int j = 0;
        //��ӡ����
        for(j = 0;j < col;j++)
        {

            printf(" %c ",board[i][j]);
            if(j < col-1)
                printf("|");
        }
        printf("\n");
        //��ӡ�ָ���Ϣ
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
        //���귶Χ�Ϸ��ж�
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
//�ڿհ�λ���������
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
//�ж���Ӯ
char IsWin(char board[ROW][COL],int row,int col)
{
    //���У����У����Խ���
    //��
    int i = 0;
    for(i = 0;i < row;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            return board[i][1];//���ⲻ��Ҫ�ĵ��ж�
        }
    }
    //��
    int j = 0;
    for(j = 0;j < col;j++)
    {
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
        {
            return board[1][j];//���ⲻ��Ҫ�ĵ��ж�
        }
    }
    //�Խ���
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        return board[1][1];
    }
    //�ж�ƽ��
    if(IsFull(board,row,col))
    {
        return 'Q';//ƽ��
    }

    //��Ϸ����
    return 'C';
    //���Ӯ -congratulate��
    //����Ӯ -oh no...
    //���� -continue   C
    //ƽ�� -again��  Q
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
    //���˷���1.���򷵻�0
}
