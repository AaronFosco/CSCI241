#include<iostream.h>
#include<graphics.h>
#include<iomanip.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "//bgi");


clock_t start,end,r;
  int x,y,i,x1,y1,j,l,m,temp,tail,col,scr,scr1,tempo;

char scrn[10];
// char key=0;
  temp=30;tail=3;
   scr1=0;
int a[300],b[300];
  i=y=x=0;


const char up='w';
const char dw='s';
const char ls='a';
const char rs='d';

cout<<"  RULES FOR THE GAME"<<endl;
cout<<"KEYS---"<<endl<<"  w- FORWARD"<<endl<<"  a- LEFT TURN"<<endl<<"  d- RIGHT TURN"<<endl<<"  s- DOWN"<<endl;
cout<<"  Q- QUIT"<<endl;
cout<<"  TURN CAPS LOCK OFF"<<endl;
cout<<"  EAT THE INSECTS N LIVE...U DIE IF U CROSS THE LIMIT / MOVE OVER UR SELF /"<<endl;
cout<<"  CROSS UR LEFTOVER SKIN."<<endl;
cout<<"  SHEADS SKIN AFTER REGULAR INTERVALS.."<<endl;
cout<<"  KEEP MOVING TO FIND FOOD ELSE U DIE"<<endl;
cout<<"	 POINTS ARE ADDED FOR EVERY INSECT YOU EAT,BUT EAT THE FIRST ONE BEFORE SECOND ONE COMES UP ELSE NO SCORE WILL BE ADDED UP"<<endl<<endl;
cout<<"  PRESS MOVE(a) KEY TO CONTINUE.....";
getch();

cleardevice();
setbkcolor(9);
for(j=0;j<=7;j++)
a[j]=b[j]=0;

rectangle(20,21,600,441);
outtextxy(20,5,"SCORE..");
randomize();
l=(random(520)+60);
if(l<=99)
{l=l/10;
l=l*10;}
else {l=l/10;
l=l*10;  }

m=(random(400)+40);
if(m<=99)
{m=m/10;
m=m*10; }
else {m=m/10;
m=m*10;  }
outtextxy(l,m,"*");

char key;
do

{

setcolor(15);
rectangle(20,21,600,440);
if(i==60||i==120||i==190||i==270)
{
l=(random(520)+50);
if(l<=99)
{l=l/10;
l=l*10;}
else {l=l/10;
  l=l*10;  }

m=(random(400)+30);
if(m<=99)
{m=m/10;
m=m*10; }
else {m=m/10;
  m=m*10;  }

setcolor(15);
outtextxy(l,m,"ь");
sound(3800);

 }

start=clock();
 key=getch();
   end=clock();
    r=end-start;
   if(r>=15)
    { outtextxy(100,100,"YOU ARE TOO SLOW...:-( ");
    delay(1000);nosound();break;}

if (i==300 )
{ i=0;}

{
 if(key==up)
 { y-=10;}
 if(key==dw)
 { y+=10;}
  if(key==ls)
 { x-=10;}
  if(key==rs)
 { x+=10;}
  }
  setcolor(10);
 a[i]= x1=210+x;
 b[i]= y1=210+y;
if(x1==l && y1==m)
 { scr1++;
 scr=10*scr1;
 sprintf(scrn,"%d",scr);
   nosound();
   setcolor(0);
outtextxy(70,5,"лл");
setcolor(15);
outtextxy(70,5,scrn);

  temp+=10;tail++; }

if(x1==20||x1==600||y1==20||y1==440)
{nosound();break;}

col=getpixel(x1,y1);
if(col>0)
  break;
  nosound();
  tempo=tail;

 if(i>=(299-tempo))
{ setcolor(4);
 tempo--  ;
}
 outtextxy(x1,y1,"X");
  setcolor(0);
  outtextxy(a[i-tail],b[i-tail],"X" );
i++;


} while (key !='q');

settextstyle(2,0,26);
outtextxy(210,210,"OUT");
 getch();
closegraph();

}