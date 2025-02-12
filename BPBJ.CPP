#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char username[40]={'\0'},o;
int mac[52]={0};
long int money=0;
void master()
{
 int s=0,d=13;
 for(int j=1;j<=4;j++,s+=13,d+=13)
  {
   for(int i=s;i<d;i++)
    {
     if(i==s)
     mac[i]='A';
     else if(i==s+10)
     mac[i]='J';
     else if(i==s+11)
     mac[i]='Q';
     else if(i==s+12)
     mac[i]='K';
     else
      {
       if(i<13)
       mac[i]=i+1;
       else if(i<26)
       mac[i]=i-12;
       else if(i<39)
	       mac[i]=i-25;
       else
       mac[i]=i-38;
      }
    }
  }
}

void newuser()
{
 ofstream f("BJUSER.dat",ios::app|ios::binary);
 if(!f)
  {
   cout<<"file not opened "<<endl;return;
  }
 char u[40],uc[40],p[40],pc[40],pj[40];
 long int mj,c;
 do
  {
   c=0;
   ifstream g("BJUSER.dat",ios::in|ios::binary);
   if(!g)
    {
     cout<<"file not opened "<<endl;return;
    }
   clrscr();
   cout<<"ENTER NEW USERNAME : ";
   gets(u);
   cout<<"ENTER PASSWORD : ";
   int i=0, flag=1;
   while(flag)
   {
    p[i]=getch();
    cout<<"*";
    if(p[i]==13)
    {
     cout<<"\b \b";
     i--;
     flag=0;
    }
    else if(p[i]==8)
    {
     cout<<"\b\b  \b\b";
     i--;
     i--;
    }
   i++;
   }
   p[i-1]='\0';
   cout<<endl<<"RE-ENTER THE SAME PASSWORD TO CHECK : ";
   i=0;
   flag=1;
   while(flag)
   {
    pc[i]=getch();
    cout<<"*";
    if(pc[i]==13)
    {
     cout<<"\b \b";
     i--;
     flag=0;
    }
    else if(pc[i]==8)
    {
     cout<<"\b\b  \b\b";
     i--;
     i--;
    }
    i++;
   }
   pc[i-1]='\0';
   if(strcmpi(pc,p)!=0)
    {
     c++;cout<<endl<<"please enter the correct password";getch();
    }
   else
    {
     for(g.read((char*)&uc,sizeof(uc));!g.eof();g.read((char*)&uc,sizeof(uc)))
      {
       g.read((char*)&pj,sizeof(pj));
       g.read((char*)&mj,sizeof(mj));
       if(strcmpi(uc,u)==0)
	{
	 c++;cout<<endl<<"the username already exists";getch();
	}
      }
    }
   g.close();
  }
 while(c);
 mj=100000;
 f.write((char*)&u,sizeof(u));
 f.write((char*)&p,sizeof(p));
 f.write((char*)&mj,sizeof(mj));
 money=mj;
 f.close();
 strcpy(username,u);
}

void check()
{
 char u[40],uc[40],p[40],pc[40];
 long int m,c;
 do
  {
   ifstream g("BJUSER.dat",ios::in|ios::binary);
   if(!g)
   {
    cout<<"file not opened "<<endl;return;
   }
   clrscr();
   cout<<"ENTER USERNAME : ";
   gets(u);
   cout<<"ENTER PASSWORD : ";
   int i=0,flag=1;
   while(flag)
   {
    p[i]=getch();
    cout<<"*";
    if(p[i]==13)
    {
     cout<<"\b \b";
     i--;
     flag=0;
    }
    else if(p[i]==8)
    {
     cout<<"\b\b \b\b";
     i--;
     i--;
    }
    i++;
   }
   p[i-1]='\0';
   for(g.read((char*)&uc,sizeof(uc));!g.eof();g.read((char*)&uc,sizeof(uc)))
    {
     g.read((char*)&pc,sizeof(pc));
     g.read((char*)&m,sizeof(m));
     if(strcmpi(uc,u)==0&&strcmpi(p,pc)==0)
      {
       strcpy(username,u);money=m;
       cout<<endl<<"successful...";
       c=0;
       break;
      }
     else
     c++;
    }
   g.close();
  }
 while(c);
 getch();
}

void monupdat()
{
 fstream f("BJUSER.dat",ios::in|ios::out|ios::binary);
 if(!f)
  {
   cout<<"error ";return;
  }
 struct player
  {
   char uc[40],p[40];long int m;
  }
 obj;
 f.read((char*)&obj,sizeof(obj));
 while(!f.eof())
  {
   if(strcmpi(username,obj.uc)==0)
    {
     obj.m=money;
     f.seekg(f.tellg()-sizeof(obj));
     f.write((char*)&obj,sizeof(obj));
    }
   f.read((char*)&obj,sizeof(obj));
  }
 f.close();
}

int hit(int a[],int x,int&y,int&s,int&d,int&c,int&h)
{
 int i,r;
 srand(time(0));
 i=rand()%(h+1);
 gotoxy(x+1,y-1);
 cout<<" --" ;
 gotoxy(x+1,y+1);
 cout<<" --" ;
 gotoxy(x,y);
 if(i>0&&i<=s)
  {
   if(a[i]==65)
    {
     cout<<" |A\6| ";
     r=11;
    }
   else if(a[i]==74)
    {
     cout<<" |J\6| ";
     r=10;
    }
   else if(a[i]==81)
    {
     cout<<" |Q\6| ";
     r=10;
    }
   else if(a[i]==75)
    {
     cout<<" |K\6| ";
     r=10;
    }
   else
    {
     cout<<" |"<<a[i]<<"\6| ";
     r=a[i];
    }
   for(int j=i;j<h;j++)
   a[j]=a[j+1];
   s--;d--;c--;h--;
  }
 else if(i>s&&i<=d)
  {
   if(a[i]==65)
    {
     cout<<" |A\4| ";
     r=11;
    }
   else if(a[i]==74)
    {
     cout<<" |J\4| ";
     r=10;
    }
   else if(a[i]==81)
    {
     cout<<" |Q\4| ";
     r=10;
    }
   else if(a[i]==75)
    {
     cout<<" |K\4| ";
     r=10;
    }
   else
    {
     cout<<" |"<<a[i]<<"\4| ";
     r=a[i];
    }
   for(int j=i;j<h;j++)
   a[j]=a[j+1];
   d--;c--;h--;
  }
 else if(i>d&&i<=c)
  {
   if(a[i]==65)
    {
     cout<<" |A\5| ";
     r=11;
    }
   else if(a[i]==74)
    {
     cout<<" |J\5| ";
     r=10;
    }
   else if(a[i]==81)
    {
     cout<<" |Q\5| ";
     r=10;
    }
   else if(a[i]==75)
    {
     cout<<" |K\5| ";
     r=10;
    }
   else
    {
     cout<<" |"<<a[i]<<"\5| ";
     r=a[i];
    }
   for(int j=i;j<h;j++)
   a[j]=a[j+1];
   c--;h--;
  }
 else if(i>c&&i<=h)
  {
   if(a[i]==65)
    {
     cout<<" |A\3| ";
     r=11;
    }
   else if(a[i]==74)
    {
     cout<<" |J\3| ";
     r=10;
    }
   else if(a[i]==81)
    {
     cout<<" |Q\3| ";
     r=10;
    }
   else if(a[i]==75)
    {
     cout<<" |K\3| ";
     r=10;
    }
   else
    {
     cout<<" |"<<a[i]<<"\3| ";
     r=a[i];
    }
   for(int j=i;j<h;j++)
   a[j]=a[j+1];
   h--;
  }
 y+=3;
 return r;
}

void main()
{
 clrscr();
 master();
 char a;
 cout<<"enter n if new user and enter o if old user ";
 cin>>a;
 if(a=='n'||a=='N')
 newuser();
 else if(a=='o'||a=='O')
 check();
 int card[52],u,de,yu,yd,buf=0;
 long int bet;
 char ch=0;
 do
  {
   clrscr();
   cout<<"welcome to BLACK JACK "<<endl;
    puts(username);
    gotoxy(1+strlen(username),2);
     cout<<": "<<money;
   int su[20],sd[20],sup=0,sdp=0;
   u=de=0;
   for(int i=0;i<52;i++)
   card[i]=mac[i];
   int s=12,d=25,c=38,h=51,x;
   yu=yd=6;
   cout<<endl<<"enter amount to bet : ";
   cin>>bet;
   if(bet<=money)
    {
     gotoxy(10,4);
     puts(username);
     gotoxy(65,4);
     cout<<"dealer";
     x=hit(card,10,yu,s,d,c,h);
     u+=x;
     su[sup++]=x;
     gotoxy(10,25);
     cout<<"sum = "<<u;
     x=hit(card,65,yd,s,d,c,h);
     de+=x;
     sd[sdp++]=x;
     gotoxy(65,25);
     cout<<"sum = "<<de;
     x=hit(card,10,yu,s,d,c,h);
     su[sup++]=x;
     if(x==11&&u==11)
      {
       u++;
       gotoxy(10,25);
       cout<<"sum = "<<u;
      }
     else
      {
       u+=x;
       gotoxy(10,25);
       cout<<"sum = "<<u;
      }
     do
      {
       if(u==21)
	{
	 gotoxy(10,22);
	 cout<<endl<<"          BLACK JACK";
	 gotoxy(10,25);
	 cout<<"sum = "<<u;
	 ch='s';
	}
       else
	{
	 int ct=0,p;
	 gotoxy(10,24);
	 cout<<"enter 'h' to hit or 's' stand : ";
	 cin>>ch;
	 if(ch=='h')
	  {
	   x=hit(card,10,yu,s,d,c,h);
	   u+=x;
	   su[sup++]=x;
	   for(int z=0;z<sup;z++)
	   if(su[z]==11)
	    {
	     ct++;p=z;
	    }
	   if(x==11&&u>21)
	    {
	     u-=10;
	     gotoxy(10,25);
	     cout<<"sum = "<<u;
	    }
	   else if(u==21)
	    {
	     gotoxy(10,22);
	     cout<<endl<<"          BLACK JACK";
	     gotoxy(10,25);
	     cout<<"sum = "<<u;
	     ch='s';
	    }
	   else if(u>21&&ct!=0)
	    {
	     u=u-10;su[p]=1;
	    }
	   else if(u>21)
	    {
	     gotoxy(10,23);
	     cout<<"BUSTED"<<endl;
	     gotoxy(10,25);
	     cout<<"sum = "<<u;
	     ch='s';
	     u=0;
	    }
	   else
	    {
	     gotoxy(10,25);
	     cout<<"sum = "<<u;
	    }
	   if(buf==1)
	    {
	     gotoxy(44,24);
	     cout<<"             ";
	     buf=0;
	    }
	  }
	 else if(ch!='s')
	  {
	   gotoxy(44,24);
	   cout<<"wrong option ";
	   buf=1;
	  }
	 else if(ch=='s'&&buf==1)
	  {
	   gotoxy(44,24);
	   cout<<"             ";
	   buf=0;
	  }
	}
      }
     while(ch!='s');
     int ct=0,p;
     x=hit(card,65,yd,s,d,c,h);
     sd[sdp++]=x;
     if(x==11&&de==11)
      {
       sd[sdp-1]=1;
       de++;
       gotoxy(65,25);
       cout<<"sum = "<<de;
      }
     else
      {
       de+=x;
       if(de==21)
	{
	 gotoxy(65,25);
	 cout<<"sum = "<<de;
	 gotoxy(65,24);
	 cout<<"BLACK JACK";
	}
       else
	{
	 gotoxy(65,25);
	 cout<<"sum = "<<de;
	}
      }
     if(u!=0)
      {
       while(de<17&&de!=0)
	{
	 int ct=0,p=0;
	 x=hit(card,65,yd,s,d,c,h);
	 de+=x;
	 sd[sdp++]=x;
	 for(int z=0;z<sdp;z++)
	 if(sd[z]==11)
	  {
	   ct++;p=z;
	  }
	 if(x==11&&de>21)
	  {
	   de-=10;
	   gotoxy(65,25);
	   cout<<"sum = "<<de;
	  }
	 else if(de==21)
	  {
	   gotoxy(65,25);
	   cout<<"sum = "<<de;
	   gotoxy(65,24);
	   cout<<"BLACK JACK";
	  }
	 else if(de>21&&ct!=0)
	  {
	   de=de-10;sd[p]=1;
	  }
	 else if(de>21)
	  {
	   gotoxy(65,24);
	   cout<<"BUSTED";
	   gotoxy(65,25);
	   cout<<"sum = "<<de;
	   de=0;
	  }
	 else
	  {
	   gotoxy(65,25);
	   cout<<"sum = "<<de;
	  }
	}
      }
     if(u>de)
      {
       money+=bet;
      }
     else if(u<de)
      {
       money-=bet;
      }
    }
   else if(bet>money)
    {
     cout<<endl<<"bet invalid:don't have money ";
    }
   o='p';
   while(o!='y' && o!='Y'&& o!='n' && o!='N')
    {
     cout<<endl<<"          enter 'y' to continue playing and 'n' to exit ";
     cin>>o;
     if(o!='y' && o!='Y'&& o!='n'&& o!='N')
     cout<<"invalid opion"<<endl;
    }
  }
 while(o=='y' || o=='Y');
 monupdat();
 cout<<endl<<" THANK YOU FOR PLAYING "<<username<<"  YOUR BALANCE IS :"<<money<<"  "<<endl;
 getch();
}