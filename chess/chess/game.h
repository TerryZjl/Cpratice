#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

#define Rows 3
#define Cols 3

void is_board(char a[Rows][Cols], int rows, int cols);        //��ʼ������
void display_board(char a[Rows][Cols], int rows, int cols);  //��ӡ����
void play_person(char a[Rows][Cols], int rows, int cols); //�������
void play_computer(char a[Rows][Cols]);                   //��������
char dcide(char a[Rows][Cols], int rows, int cols);      //�ж�˭Ӯ


#endif  //__GAME_H__