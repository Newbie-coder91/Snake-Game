#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <dos.h>
#include<stdlib.h>
void snake();
void set();
void food();
void score();

int x[100][4]={ {100,100,110,110} };    //first rectangle
int ch,ch2;
int n=1;
int t=150;
int r1,r2;
//--------------------------------------------------------------------------
void main()
{
int a=DETECT;
int b;
clrscr();
initgraph(&a,&b,"");
//--------------------------------------------------------------------------
outtextxy(200,220,"Welcome to this Snake Game!");
delay(1500);
settextstyle(0,0,2);

outtextxy(130,240,"Created by Atul Agrawal");
delay(2000);
cleardevice();
settextstyle(0,0,1);

m:
outtextxy(200,220,"Press Enter To Start the Game!");  //starting window
int n;
n=getch();
if(n==13)
{
r1=50+random(450);
r2=50+random(350);
do
{
snake();
if(ch!=13)
{
ch=getch();
}
}while(ch!=13);
}
else
{
goto m;
}
}
//--------------------------------------------------------------------------
void snake()
{
while(kbhit()==0)
{
int flag=0;
food();
score();
//--------------------------------------------------------------------------
for(int i=0;i<n;i++)                                //snake length
{
bar(x[i][0],x[i][1],x[i][2],x[i][3]);
setcolor(0);
rectangle(x[i][0],x[i][1],x[i][2],x[i][3]);
}
setcolor(14);
rectangle(0,0,639,479);
line(0,30,639,30);
setcolor(15);
//--------------------------------------------------------------------------
if(ch==77)                                          //right movement
{
set();
x[0][0]+=10;
x[0][2]+=10;
}
if(ch==75)                                          //left movement
{
set();
x[0][0]-=10;
x[0][2]-=10;
}
if(ch==72)                                          //up movement
{
set();
x[0][1]-=10;
x[0][3]-=10;
}
if(ch==80)                                          //down movement
{
set();
x[0][1]+=10;
x[0][3]+=10;
}
//--------------------------------------------------------------------------
if(x[0][0]==r1&&x[0][1]==r2)                         //new food
{
n++;
t-=2;
r1=50+random(450);
r2=50+random(350);
}
//--------------------------------------------------------------------------
if(x[0][1]>478||x[0][1]<0||x[0][0]<0||x[0][0]>638)   //game over
{
cleardevice();
settextstyle(0,0,2);
outtextxy(225,215,"GAME OVER!!");
char c[5];
int n1=n-1;
sprintf(c,"%d",n1);
settextstyle(0,0,1);
outtextxy(245,240,"Your Score is ");
outtextxy(360,240,c);
ch=13;
delay(2000);
break;
}
for(i=3;i<n;i++)
{
if(x[0][0]==x[i][0]&&x[0][1]==x[i][1])
{
cleardevice();
settextstyle(0,0,2);
outtextxy(225,215,"GAME OVER!!");
char c[5];
int n1=n-1;
sprintf(c,"%d",n1);
settextstyle(0,0,1);
outtextxy(245,240,"Your Score is ");
outtextxy(360,240,c);
ch=13;
flag=1;
}
}
if(flag==1){
delay(2000);
break;
}
delay(t);
cleardevice();
}
}
//--------------------------------------------------------------------------
void set()            //movement of Snake
{
for(int i=n-1;i>0;i--)
{
x[i][0]=x[i-1][0];
x[i][1]=x[i-1][1];
x[i][2]=x[i-1][2];
x[i][3]=x[i-1][3];
}
}
//--------------------------------------------------------------------
void food()                               //food generation
{
r1=r1-r1%10;
r2=r2-r2%10;
setcolor(15);
circle(r1+5,r2+5,5);
floodfill(r1+5,r2+5,15);
}
//--------------------------------------------------------------------
void score()                              //display score
{
outtextxy(10,10,"Score : ");
char ch[4];
int n2=n-1;
sprintf(ch,"%d",n2);
outtextxy(70,10,ch);
}

