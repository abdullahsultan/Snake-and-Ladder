#include<iostream>
#include<time.h>
using namespace std;
int ary[5][5];
class sl
{
private:

 int x,row,col,player,stack;


public:

 sl(int p)
 {row=0;col=0;player=p;stack=0;
  for (int x = 0; x < 5; x++) {
    {
      for (int y = 0; y < 5; y++)
       ary[x][y]=0;
    }
  }
 }

 void incrementer()
 {
   int temp=stack;
    for(int i=0;i<5 && temp>=1;i++)
    {
      for(int j=0;j<5 && temp>=1;j++,temp--)
      {
        if(temp==1)
        {
          checker(i,j);
          cout<<"i = "<<i<<"  j = "<<j<<"  stack = "<<stack<<endl;
      //    row=i;col=j;
        }
      }
    }
  }

void checker(int i,int j)
{
  if((i!=1 && j!=3) || (i!=2 && j!=4) || (i!=3 && j!=1)) //&& (i!=4 && j!=3))
  {
    if(ary[row][col]==player)
    {ary[row][col]=0;}
    row=i;col=j;ary[i][j]=player;
  }
  else
  {
    ary[row][col]=0;
    row=i;col=j;
  switch (i,j)
   {
    case (1,3):
    cout<<"You got a ladder \n";
    ary[2][3]=player;

    break;
    case (2,4):
    cout<<"You got a snake \n";
    ary[2][0]=player;
    break;
    case (3,1):
    cout<<"You got a ladder \n";
    ary[4][0]=player;
    break;
  /*  case (4,3):
    ary[3][4]=player;
    break; */
    }
  }

}
  int radomizer()
 {
   x= rand()%7+1;
   stack=stack+x;
   return x;
 }

 void get()
 {
   for(int x=0;x<5;x++)
   {
     for(int l=0;l<5;l++)
     {cout<<"  _ ";}
     cout<<endl;
     for(int y=0;y<5;y++)
     {
       cout<<" | "<<ary[x][y];
     }
     cout<<" | "<<endl;
   }
 }


};
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  sl p1(1);sl p2(2);
  int choice;
  while(true)
  {
    cout<<"Player 1 turn press 1 to throw dice other wise you will loose your turn \n";
    cin>>choice;
    if(choice==1)
    {
       cout<<"Dice = "<<p1.radomizer()<<endl;
       p1.incrementer();
       p1.get();
    }
    cout<<"Player 2 turn press 2 to throw dice other wise you will loose your turn \n";
    cin>>choice;
    if(choice==2)
    {
       cout<<"Dice = "<<p2.radomizer()<<endl;
       p2.incrementer();
       p2.get();
    }
    if(ary[4][4]!=0)
    {
      if(ary[4][4]==1)
      {cout<<"Player 1 won \n";
      return 0;}

      else
      {cout<<"Player 2 won \n";
      return 0;}
    }
  }
  return 0;
}
