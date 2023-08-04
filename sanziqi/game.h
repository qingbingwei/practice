//
// Created by 38016 on 2023/8/3.
//

#ifndef SANZIQI_GAME_H
#define SANZIQI_GAME_H

#endif //SANZIQI_GAME_H
#define ROW 3
#define COL 3
#include <stdlib.h>
#include <time.h>
void menu();
void game();
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row, int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row, int col);
char IsWin(char board[ROW][COL],int row,int col);
int IsFull(char board[ROW][COL],int row,int col);

