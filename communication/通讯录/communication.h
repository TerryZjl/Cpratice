#ifndef _GAME_H__                  //game.h
#define _GAME_H__

#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#define MAX 1000


typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;


typedef struct Contact
{
	PeoInfo contact[MAX];
	int count;
}Contact, *pContact;

void InitContact(pContact pcon);


void InitContact(pContact pcon);
void AddContact(pContact pcon);
void DelContact(pContact pcon);
void SearchContact(pContact pcon);
void showContact(pContact pcon);
void sortContact(pContact pcon);
void showtopic(char *topic);
void swap(int *a, int *b);

#endif //_GAME_H__