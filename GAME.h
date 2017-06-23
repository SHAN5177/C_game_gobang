#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
struct coordinate{
	int x;
	int y;
};
void PTABLE (int table[][19]);
void HOWTOPLAY();

void PLAY(int table[][19],char *name1,char *name2);
void clear(int table[][19]);
int main(void);
