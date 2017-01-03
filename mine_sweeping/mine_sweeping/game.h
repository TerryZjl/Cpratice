#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define Rows 10
#define Cols 10
#define NUM_MINE 10

void display(char arr[Rows + 2][Cols + 2], int rows, int cols);                        //打印雷
void set_mine(char arr[Rows + 2][Cols + 2], int rows, int cols);                      //布置雷
int del_mine(char arr[Rows + 2][Cols + 2], int x, int y);                             //判断点击的地方一周的雷数
int aroud(char arr[Rows + 2][Cols + 2], char app[Rows + 2][Cols + 2], int x, int y); //把点击的地方一周没有雷的地方都显示出来，并且显示周围雷的个数
void first(char arr[Rows + 2][Cols + 2], int x, int y);                             //如果第一步踩到雷，就把乃个雷移到别的位置   

#endif  //__GAME_H__