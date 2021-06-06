#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;
int i,j,k=0,n,m,x,y,score1=0,score2=0;
char a[16][16];
int b[16][16];

void playchess(char a[16][16],int k,int n,int m);
void error(char a[16][16],int k,int n,int m)
{
	cout<<"你输入的位置不在棋盘上或者已有棋子啦~"<<endl<<"请重新输入吧：" <<endl;
	playchess(a,k,n,m); 
}
void playchess(char a[16][16],int k,int n,int m)
{
	if (k%2==1)
	{
		cout<<endl;
		cout<<"                  ☆现在轮到玩家A，请输入下子的位置 行n 和 列m :\n"<<endl;
		cin>>n>>m;
		if (n<=15&&m<=15&&n>0&&m>0&&a[n][m]==0) 
		{
			a[n][m]=1;
			b[n][m]=1;
		}
		else
		error(a,k,n,m);	
	}
	else
	{
		cout<<endl;
		cout<<"                  ☆现在轮到玩家B，请输入下子的位置 行n 和 列m :\n"<<endl;
		cin>>n>>m;
		if (n<=15&&m<=15&&n>0&&m>0&&a[n][m]==0) 
		{
			a[n][m]=2;
			b[n][m]=2;
		}
		else
		error(a,k,n,m);
	}
}
void chessboard(int i,int j)
{
	system("cls");
	cout<<endl<<"                          ◇***☆*** 这是棋盘啦~ ***☆***◇                 ◇***☆*** 这是分数啦~ ***☆***◇"<<endl<<endl; 
	for (i=0;i<16;i++)
	{
		cout<<"                 ";
		for (j=0;j<16;j++)
	      {
	      	if (i==0)
	      	    {
					 cout.width(3);
	      	    	 cout<<j;
	      	    }
	        else if (j==0)
	            {
	      	    	 cout.width(3);
	      	    	 cout<<i;
	      	    }
			else if (a[i][j]==1)
				cout<<" ●";
	      	else if (a[i][j]==2)
	      	    cout<<" ○";
	      	else
				cout<<" ┼";
	      }
	      if(i==4)
	      	cout<<std::right<<setw(35)<<"玩家A的分数：";
	      	if(i==5)
	      	cout<<std::right<<setw(28)<<score1;
	      	if(i==9)
	      	cout<<std::right<<setw(35)<<"玩家B的分数：";
	      	if(i==10)
	      	cout<<std::right<<setw(28)<<score2;
	      cout<<endl;
	}
}
int win(int x,int y,char a[16][16],int i,int j)
{
	for (i=1;i<16;i++)
	{
		for (j=1;j<16;j++)
	      {
	          if (i<12&&b[i][j]==1&&b[i][j+1]==1&&b[i][j+2]==1&&b[i][j+3]==1&&b[i][j+4]==1)
	          {y=1;return y;}
	          if (i<12&&b[i][j]==2&&b[i][j+1]==2&&b[i][j+2]==2&&b[i][j+3]==2&&b[i][j+4]==2)
	          {y=2;return y;}
	          if (j<12&&b[i][j]==1&&b[i+1][j]==1&&b[i+2][j]==1&&b[i+3][j]==1&&b[i+4][j]==1)
	          {y=1;return y;}
	          if (j<12&&b[i][j]==2&&b[i+1][j]==2&&b[i+2][j]==2&&b[i+3][j]==2&&b[i+4][j]==2)
	          {y=2;return y;}
	          if (j<12&&i<12&&b[i][j]==1&&b[i+1][j+1]==1&&b[i+2][j+2]==1&&b[i+3][j+3]==1&&b[i+4][j+4]==1)
	          {y=1;return y;}
	          if (j<12&&i<12&&b[i][j]==2&&b[i+1][j+1]==2&&b[i+2][j+2]==2&&b[i+3][j+3]==2&&b[i+4][j+4]==2)
	          {y=2;return y;}
	          if (j<12&&i>4&&b[i][j]==1&&b[i-1][j+1]==1&&b[i-2][j+2]==1&&b[i-3][j+3]==1&&b[i-4][j+4]==1)
	          {y=1;return y;}
	          if (j<12&&i>4&&b[i][j]==2&&b[i-1][j+1]==2&&b[i-2][j+2]==2&&b[i-3][j+3]==2&&b[i-4][j+4]==2)
	          {y=2;return y;}	          
	          else
	          y=0;
	      }
    }
	return y;
}
void home();
void style();
void retry3(int p)
{
	cout<<"哎呀，输错了鸭，重新来一遍吧:"<<endl;
	cin>>p;
	if(p==1) system("color 3f");
	else if(p==2) system("color 4f");
	else if(p==3) system("color 0f");
	else if(p==4) system("color Bf");
	else if(p==5) system("color f0");
	else if(p==6) home();	
	else retry3(p);
} 
void retry2()
{
    char p;
	cout<<"不行，还是输错了鸭，快点重来(n/y)"<<endl;
	cin>>p;
	if (p!='y')
	    retry2();
	else if (p=='y')
	{
		system("cls");
		home();
	}
	    	
}
void retry()
{
	char p;
	cout<<"哎呀，输错了鸭，重新来一遍吧(n/y)"<<endl;
	cin>>p;
	if (p!='y')
	    retry2();
	else if (p=='y')
	{
		system("cls");
		home();
	}
	    
}
void style()
{
	system("cls");
	int p; 
	char q;
	cout<<endl; 
	cout<<"\t\t╔*☆***◎***◇***☆***界面风格***☆***◇***◎***☆*╗\n";
    cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
	cout<<"\t\t|★|\t\t     请选择：  \t\t\t|★|\n";
    cout<<"\t\t|☆|\t\t   1.蓝底白字(默认)  \t\t|☆|\n";
	cout<<"\t\t|★|\t\t   2.红底白字  \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t   3.黑底白字  \t\t\t|☆|\n";
	cout<<"\t\t|★|\t\t   4.绿底白字  \t\t\t|★|\n";
	cout<<"\t\t|★|\t\t   5.白底黑字  \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t   6.返回      \t\t\t|☆|\n";
	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
	cout<<"\t\t╚*☆***◎***◇****☆****★****☆****◇***◎***☆*╝\n\n";
	cin>>p;
	if(p==1) system("color 3f");
	else if(p==2) system("color 4f");
	else if(p==3) system("color 0f");
	else if(p==4) system("color Bf");
	else if(p==5) system("color f0");
	else if(p==6) home();
	else retry3(p);
	cout<<"切换完成，是否返回？(n/y)"<<endl;
	cin>>q;
	    if (q!='y')
	    {
	    	system("cls");
	    	retry();
	    }
	    else if (q=='y')
	    {
	    	system("cls");
	    	home();	
	    } 	
} 
void judge()
{
	if(score1>score2)
	{
		system("cls"); 
		cout<<endl; 
		cout<<"\t\t╔*☆***◎***◇***☆***恭喜你***☆***◇***◎***☆*╗\n";
   		cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
		cout<<"\t\t|☆|\t\t     玩家A     \t\t\t|☆|\n";
		cout<<"\t\t|★|\t\t 获得最终胜利  \t\t\t|★|\n";
    	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
		cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
		cout<<"\t\t╚*☆***◎***◇****☆****★****☆****◇***◎***☆*╝\n\n";
	}
	else
	{
		system("cls");
		cout<<endl; 
		cout<<"\t\t╔*☆***◎***◇***☆***恭喜你***☆***◇***◎***☆*╗\n";
   		cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
		cout<<"\t\t|☆|\t\t     玩家B     \t\t\t|☆|\n";
		cout<<"\t\t|★|\t\t 获得最终胜利  \t\t\t|★|\n";
    	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
		cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
		cout<<"\t\t╚*☆***◎***◇****☆****★****☆****◇***◎***☆*╝\n\n";
	}
	cout<<"\t游戏已经结束啦，是否返回主界面?(n/y)"<<endl;
	char q;
	cin>>q;
	    if (q!='y')
	    {
	    	system("cls");
	    	retry();
	    }
	    else if (q=='y')
	    {
	    	system("cls");
	    	home();	
	    } 		
}
void game()
{
	int g;
	while(1) 
		{
			k++;
			playchess(a,k,n,m);
			g=win(x,y,a,i,j);
			if (g==1)
			{
				cout<<"-恭喜玩家A得分啦-"<<endl; 
				score1=score1+1;
				break;
			}
			else if(g==2) 
			{
				cout<<"-恭喜玩家B得分啦-"<<endl; 
				score2=score2+1;
				break;
			}			
			else
			{
				system("cls");
				chessboard(i,j); 		
			}
		}
		if(score1+score2==5||score1==3||score2==3)
		judge();
		else
		{
			cout<<"是否进入下一局?(确定请输入y/返回主界面输入n)"<<endl;
			char p;
			cin>>p;
			if (p!='y')
	 	    {
	  	  		system("cls");
	 	  	 	home();	
	  	 	}
	    	else
	  		{
	  			for (i=1;i<16;i++)
	  			for (j=1;j<16;j++) 
	  			{
					a[i][j]=0;
					b[i][j]=0;
			    }
	  			x=0;y=0;
	  			g=0;
	  			m=0;n=0;
	  			chessboard(i,j);
		        game();
			}	
		}

}
void home()
{
	system("cls");
	int h;
	cout<<endl; 
	cout<<"\t\t╔*☆***◎***◇***☆***五子棋***☆***◇***◎***☆*╗\n";
    cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
	cout<<"\t\t|★|\t\t     请选择：  \t\t\t|★|\n";
    cout<<"\t\t|☆|\t\t   1.玩法介绍  \t\t\t|☆|\n";
	cout<<"\t\t|★|\t\t   2.开始游戏  \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t   3.界面风格  \t\t\t|☆|\n";
	cout<<"\t\t|★|\t\t               \t\t\t|★|\n";
	cout<<"\t\t|☆|\t\t               \t\t\t|☆|\n";
	cout<<"\t\t╚*☆***◎***◇****☆****★****☆****◇***◎***☆*╝\n\n";
	cin>>h;
	if (h==1)
	{
		system("cls");
		cout<<"                ◇***☆*** 五子棋 ***☆***◇"<<endl<<endl; 
		cout<<"1.先由第一位玩家输入要下子的位置，将在该位置画上 ×"<<endl; 
		cout<<"2.再由第二位玩家输入要下子的位置，将在该位置画上 ○"<<endl;
		cout<<"3.以此循环往复，当一位玩家在水平或竖直或斜线上达到五颗子即为胜利"<<endl;
		cout<<"4.本游戏采用5局3胜的得分制"<<endl; 
		cout<<"5.第一回合A先手，之后每回合结束后由输的人先下子"<<endl<<endl; 
		char q;
	    cout<<"是否返回?n/y"<<endl;
	    cin>>q;
	    if (q!='y')
	    {
	    	system("cls");
	    	retry();
	    }
	    else if (q=='y')
	    {
	    	system("cls");
	    	home();	
	    } 
	}
	else if(h==2) 
	{
		chessboard(i,j);
		game();
	} 
	else if(h==3)
	style();
	else
	retry();	
}
int main()
{
	system("color 3f");
	home();
	system("pause");
	return 0;
}

