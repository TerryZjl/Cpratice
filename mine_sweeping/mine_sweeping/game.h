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

void display(char arr[Rows + 2][Cols + 2], int rows, int cols);                        //��ӡ��
void set_mine(char arr[Rows + 2][Cols + 2], int rows, int cols);                      //������
int del_mine(char arr[Rows + 2][Cols + 2], int x, int y);                             //�жϵ���ĵط�һ�ܵ�����
int aroud(char arr[Rows + 2][Cols + 2], char app[Rows + 2][Cols + 2], int x, int y); //�ѵ���ĵط�һ��û���׵ĵط�����ʾ������������ʾ��Χ�׵ĸ���
void first(char arr[Rows + 2][Cols + 2], int x, int y);                             //�����һ���ȵ��ף��Ͱ��˸����Ƶ����λ��   

#endif  //__GAME_H__