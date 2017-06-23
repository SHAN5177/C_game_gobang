//By Shan Tsai
//:)

#include"GAME.h"

void SetColor(int color = 7){
HANDLE hConsole;
hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole,color);
}

void HOWTOPLAY(){
	
	printf("       歡迎遊玩 五子棋       \n");
	printf("      黑子先行 後為白子      \n");
	printf("  一方先連至5顆棋子即為獲勝  \n");
	printf(" ~~請輸入玩家姓名及棋盤顏色~~\n"); 
	printf("色號: 白底 252 紫底95") ;
	printf("\n");
	
}

void PTABLE (int table[][19]){
	
for(int i=0;i<20;i++) printf("%2d ",i);
	printf("\n");	
	
	for(int i=1;i<=19;i++){	
	    printf("%2d ",i);		
			    
		for(int j=1;j<20;j++){	  
		      
		 printf(" %c ",table[i-1][j-1]);
		}			
		printf("\n");
	}	
}

void PLAY(int table[][19],char *name1,char *name2,int l){

	int i,j;
	int k=0;
	int again;
	struct coordinate player1;
	struct coordinate player2;
	
	do{
	found:
	SetColor(10);	
	printf("%s ENTER coordinate:",&name1);
	scanf("%d %d",&player1.x,&player1.y);
	
	if(table[player1.y-1][player1.x-1]=='W'||table[player1.y-1][player1.x-1]=='B') {
		printf("這裡下過了吼，給我重下!!\n");
		goto found;
	}
	
	else {
//	SetColor(15);	
	table[player1.y-1][player1.x-1]='B';
	}
	
	SetColor(l);	
	system("cls");
	
	PTABLE (table);
	
	SetColor(207);	
	
	for(int i=0;i<19;i++){
		
		for(int j=0;j<19;j++){
			
			if(table[i][j]=='B'&&table[i+1][j]=='B'&&table[i+2][j]=='B'&&table[i+3][j]=='B'&&table[i+4][j]=='B') {
			    k++;
				printf("恭喜壓~~~~~%s WIN \nenter (0,0) to next",&name1);
			}
			if(table[i][j]=='B'&&table[i][j+1]=='B'&&table[i][j+2]=='B'&&table[i][j+3]=='B'&&table[i][j+4]=='B'){
				k++;
			 printf("恭喜壓~~~~~%s WIN \nenter (0,0) to next",&name1);
			}
			if(table[i][j]=='B'&&table[i+1][j+1]=='B'&&table[i+2][j+2]=='B'&&table[i+3][j+3]=='B'&&table[i+4][j+4]=='B') {
				k++;
			 printf("恭喜壓~~~~~%s WIN \nenter (0,0) to next",&name1);
			}
			if(table[i][j]=='B'&&table[i+1][j-1]=='B'&&table[i+2][j-2]=='B'&&table[i+3][j-3]=='B'&&table[i+4][j-4]=='B') {
				k++;
			 printf("恭喜壓~~~~~%s WIN \nenter (0,0) to next",&name1);
			}	
			
		}		
	}
	
	
	found1:
	SetColor(10);
	printf("%s ENTER coordinate:",&name2);
	scanf("%d %d",&player2.x,&player2.y);
	
	if(table[player2.y-1][player2.x-1]=='W'||table[player2.y-1][player2.x-1]=='B') {
		printf("這裡下過了吼，給我重下!!\n");
		goto found1;
	}
	
	else {
//	SetColor(240);
	table[player2.y-1][player2.x-1]='W';
	}
	
	SetColor(l);	
	system("cls");
	
	PTABLE (table);
	
	SetColor(207);	
	for(int i=0;i<19;i++){
		for(int j=0;j<19;j++){
			if(table[i][j]=='W'&&table[i+1][j]=='W'&&table[i+2][j]=='W'&&table[i+3][j]=='W'&&table[i+4][j]=='W') {
				k++;
			 printf("恭喜壓~~~~~%s WIN\n",&name2);
			}
			if(table[i][j]=='W'&&table[i][j+1]=='W'&&table[i][j+2]=='W'&&table[i][j+3]=='W'&&table[i][j+4]=='W')  {
				k++;
			 printf("恭喜壓~~~~~%s WIN\n",&name2);
			}
			if(table[i][j]=='W'&&table[i+1][j+1]=='W'&&table[i+2][j+2]=='W'&&table[i+3][j+3]=='W'&&table[i+4][j+4]=='W')  {
				k++;
			 printf("恭喜壓~~~~~%s WIN\n",&name2);
			}
			if(table[i][j]=='W'&&table[i+1][j-1]=='W'&&table[i+2][j-2]=='W'&&table[i+3][j-3]=='W'&&table[i+4][j-4]=='W')  {
				k++;
			 printf("恭喜壓~~~~~%s WIN\n",&name2);
			}
		}
	}
	
}while(k!=1);
}

void clear(int table[][19]){
	for(int i=0;i<19;i++){		   
			
			for(int j=0;j<20;j++){
			if(i==9&&j==9||i==9&&j==3||i==9&&j==15||i==3&&j==9||i==15&&j==9||i==3&&j==3||i==3&&j==15||i==15&&j==3||i==15&&j==15) 
			table[i][j]='X';
			else table[i][j]='+';
			}				
	
		}	
}

int main(void){


 	char *name1;
 	name1= (char*)malloc(sizeof(char)*40);
 	char *name2;
 	name2= (char*)malloc(sizeof(char)*40);
    int table[19][19];
	int i,j,l;
	int k=0;
	int again;
	struct coordinate player1;
	struct coordinate player2;
	
	SetColor(79);
	HOWTOPLAY();

	SetColor(112);
	printf("選擇棋盤顏色 ENTER:");
	scanf("%d",&l); 
	printf("ENTER PLAYER 1's NAME:");
	scanf("\n%s",&name1);
	printf("ENTER PLAYER 2's NAME:");
	scanf("\n%s",&name2);
	
	do{

	SetColor(13);
	printf("WELECOME!\n");
	printf("Player1 %s:black Player2 %s:white\n",&name1,&name2);
	
	clear(table);
	
	SetColor(l);	
	PTABLE (table);
	PLAY(table,(char*)name1,(char*)name2,l);
	
	printf("AGAIN? YES enter 1 / NO enter 2 :");
	scanf("%d",&again);

	switch(again){
		
		case 1:
			
			clear(table);
			PLAY(table,(char*)name1,(char*)name2,l);
			break;
			
		case 2:
			break;			
	}
	
	}while(again!=2);
	
	system("PAUSE");
	return 0;
}
