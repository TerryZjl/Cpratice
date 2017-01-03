#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define Rows 3
#define Cols 3

void is_board(char a[Rows][Cols], int rows, int cols);        //初始化棋盘
void display_board(char a[Rows][Cols], int rows, int cols);  //打印棋盘
void play_person(char a[Rows][Cols], int rows, int cols); //玩家下棋
void play_computer(char a[Rows][Cols]);                   //电脑下棋
char dcide(char a[Rows][Cols], int rows, int cols);      //判断谁赢


#endif  //__GAME_H__