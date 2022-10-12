#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<windows.h>

#include<conio.h>

#include<time.h>

struct time_t{

int tm_hour;

int tm_min;

int tm_sec;

};

struct topscore{

char name[100];

int score;

};

int pattern()//starting of pattern function

{

int i,k,j;

for(k=0;k<5;k++)

{

for(j=0;j<=60;j++)

{

if(k==2)

{

if(j==20)

{

system("COLOR 7d");

printf(" ***!!!!!!!!!!///WELCOME TO HANGMAN GAME\\\\\\!!!!!!!!!!***");

}

}

else

{

printf("*");

}

}

printf("\n");

}

printf("\n");

for(j=0;j<10;j++)

{

printf("=");

}

printf("\n");

for(i=0;i<10;i++)

{

if(i==0)

{

printf("|| |");

}

else

{

printf("||");

}

printf("\n");

}

}//ending of pattern function

int manstructure(int count,struct topscore st1);

int guesspart(int l,char a[100],int nl,struct topscore st1);

int main()

{//starting of main

// it will store starting time.

time_t start=time(NULL);

struct tm *tstart=localtime(&start);

int shour = tstart->tm_hour;

int sminute = tstart->tm_min;

int ssecond = tstart->tm_sec;

char a[100];

struct topscore st1;

int l,i,check,nl;

Beep(200,500);

Beep(500,500);

Beep(400,500);

Beep(300,500);

system("color b5");

printf("\nWELCOME TO HANGMAN\nTWO PLAYER VERSION");

printf("\nINSTRUCTIONS:\nPlayer one gives a word and the guesser i.e player two has to guess it \nin the end we will see can the guesser guess it or not\?");

printf("\n \nEnter word you want player to guess:");

scanf(" %s",a);

printf("\n\n NOw GIVE YOUR FRIEND THE COMPUTER AND SEE IF HE\\SHE CAN CRACK IT!!!!!!!");

printf("\n\t\tHIT ENTER!");

getch();

l=strlen(a);

system("cls");

for(i=0;a[i]!='\0';i++)

{//starting of for loop for checking if its a letter

if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))

{//starting check if

check=1;

}//ending check if

else //starting 0 check

{

check=0;

break;

}//ending 0 check

}

if(check==1)//guess again if

{

printf("\nenter guesser's name:");

scanf(" %s",http://st1.name);

nl=strlen(http://st1.name);

system("cls");

guesspart(l,a,nl,st1);

}//ending guess if

else//starting else guess

{

printf("invalid,Please enter alphabets between a and z(:");

gets(a);

check=1;

l=strlen(a);

system("cls");

printf("\nenter guesser's name:");

scanf(" %s",http://st1.name);

nl=strlen(http://st1.name);

system("cls");

guesspart(l,a,nl,st1);

}//ending else guess

time_t now = time(NULL);

struct tm *t = localtime(&now);

int hour = t->tm_hour;

int minute = t->tm_min;

int second = t->tm_sec;

int time1= hour-shour;

int time2= minute-sminute;

int time3= second-ssecond;

printf("\n you have consumed =%d(hours):%d(minutes):%d(seconds) during playing this game.",time1,time2,time3);

}//ending main

int manstructure(int count,struct topscore st1)

{//starting

int i;

FILE *fp1,*fp2;

struct topscore top[10];

fp1=fopen("Topscore.txt","a");

fp2=fopen("leaderboard.dat","r+");

if(fp1==NULL){

printf("Error! opening file.");

exit(1);

}

int score=0;

system("cls");

switch(count)

{

case 1:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

for(i=1;i<=9;i++)

{printf("\n\t ||");

}

break;

case 2:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || |");

for(i=1;i<=8;i++)

{printf("\n\t ||");

}

break;

case 3:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || |");

printf("\n\t || |");

for(i=1;i<=7;i++)

{printf("\n\t ||");

}

break;

case 4:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || |");

printf("\n\t || |");

printf("\n\t || /");

for(i=1;i<=6;i++)

{printf("\n\t ||");

}

break;

case 5:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || |");

printf("\n\t || |");

printf("\n\t || / \\ ");

for(i=1;i<=5;i++)

{printf("\n\t ||");

}

break;

case 6:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || /|");

printf("\n\t || |");

printf("\n\t || / \\ ");

for(i=1;i<=4;i++)

{printf("\n\t ||");

}

break;

case 7:

printf("\n\t ==========");

printf("\n\t || |");

printf("\n\t || O");

printf("\n\t || /|\\");

printf("\n\t || |");

printf("\n\t || / \\ ");

for(i=1;i<=3;i++)

{printf("\n\t ||");

}

Beep(400,500);

Beep(300,500);

printf("\nYOU LOSE!!!!YOU KILLED THE POOR MAN:(");

printf("\n score is %d\n",score);

for(i=0;i<5;i++)

{

Beep(250*i,400);

}

fflush(stdin);

fprintf(fp1,"\n%s %d",http://st1.name,st1.score);

fclose(fp1);

int fi=0;

while(!EOF)

{

fread(&top[fi],sizeof(struct topscore),1,fp2);

fi++;

}

fclose(fp2);

fp2=fopen("leaderboard.dat","w+");

int lb;

for (lb=0; lb<10; lb++)

{

if(top[i].score==st1.score)

{

strcpy(top[lb].name,http://st1.name);

top[lb].score=top[lb].score;

break;

}

}

fclose(fp2);

fp2=fopen("leaderboard.dat","w+");

for(lb=0;lb<10;lb++)

{

fwrite(&top[lb],sizeof(struct topscore),1,fp2);

}

fclose(fp2);

break;

return 0;

}

}

int guesspart(int l,char a[100],int nl,struct topscore st1)

{

st1.score=7000;

int gn=0;

int i,k,x,j,count=0,check,chck,max=0,sno=0,gi,gj,guessed=0;

char b[100],compwrong[100],guessdone[100];

char ch,cha;

FILE *fp1,*fp2;

struct topscore top[10];

fp1=fopen("Topscore.txt","a");

fp2=fopen("leaderboard.dat","r+");

if(fp1==NULL){

printf("Error! opening file.");

exit(1);

}

if(fp2==NULL){

printf("Error! opening file.");

exit(1);

}

for(i=0;i<l;i++)

{

compwrong[i]=a[i];

}

pattern();

printf("You would have to guess %d words.\n",l);

for(i=0;i<l;i++)

{

b[i]='_';

b[l]='\0';

}

for(i=0;i<l;i++){

printf(" %c",b[i]);

}

for(j=0;count<7;j++){//starting of for loop

if(strcmp(b,a) == 0)

{

x=1;

}

else

{

printf("\nenter guessing word:");

scanf(" %c",&ch);

getch();

guessdone[gn]=ch;

gn++;

for(gi=0;gi<gn;gi++)

{

for(gj=0;gj<gn;gj++)

{

if(guessdone[gi]==guessdone[gj] && gi!=gj)

{

guessed=3;

break;

}

else{

guessed=4;

break;

}

}

}

if((ch>='a'&& ch<='z')||(ch>='A' && ch<='Z'))

{

chck=1;

}

else

{

chck=0;

}

if(chck==0)

{

printf("\nenter guessing word from a to z:");

scanf(" %c",&ch);

}

if(strchr(a, ch) != NULL){

printf("\a\a\a");

printf("\n%c is correct guess!!!",ch);

for(i=0;i<l;i++)

{

if(a[i]==ch)

{

b[i]=ch;

}

}

if(i==l-1)

{

if(strcmp(b,a) == 0)

{

x=1;

}

}

}

else

{

Beep(400,500);

//wrong guess ke jaga admi ka function

//else incase if user puts wrong input

for(gi=0;gi<gn;gi++)

{

for(gj=0;gj<gn;gj++)

{

if(guessdone[gi]==guessdone[gj] && gi!=gj)

{

guessed=1;

break;

}

else{

guessed=0;

break;

}

}

}

if(guessed==1)

{

printf("\nalready guessed");

}

else

{

count++;

st1.score=7000-(1000*count);

manstructure(count,st1);

printf("\n%c was wrong",ch);

getchar();

if(count==7)

{

printf("\nyour word was %s",compwrong);

}

}

}

for(i=0;i<l;i++){ // starting of for loop =>right guess

printf(" %c",b[i]);

if(i==l-1)

{

if(strcmp(b,a) == 0)

{

x=1;

if(x==1)

{

Beep(200,500);

Beep(500,500);

printf("\n %s's score is %d",http://st1.name,st1.score);

printf("\nWOOOHOO YOU WON!!!!!! :)");

fflush(stdin);

fprintf(fp1,"\n%s %d",http://st1.name,st1.score);

fclose(fp1);

int fi=0;

while(!EOF)

{

fread(&top[fi],sizeof(struct topscore),1,fp2);

fi++;

}

fclose(fp2);

fp2=fopen("leaderboard.dat","w+");

int lb;

for (lb=0; lb<10; lb++)

{

if(top[i].score==st1.score)

{

strcpy(top[lb].name,http://st1.name);

top[lb].score=top[lb].score;

break;

}

}

fclose(fp2);

fp2=fopen("leaderboard.dat","w+");

for(lb=0;lb<10;lb++)

{

fwrite(&top[lb],sizeof(struct topscore),1,fp2);

}

fclose(fp2);

return 0;

}

}

}

}

}

}

}
