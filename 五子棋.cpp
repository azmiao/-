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
	cout<<"�������λ�ò��������ϻ�������������~"<<endl<<"����������ɣ�" <<endl;
	playchess(a,k,n,m); 
}
void playchess(char a[16][16],int k,int n,int m)
{
	if (k%2==1)
	{
		cout<<endl;
		cout<<"                  �������ֵ����A�����������ӵ�λ�� ��n �� ��m :\n"<<endl;
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
		cout<<"                  �������ֵ����B�����������ӵ�λ�� ��n �� ��m :\n"<<endl;
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
	cout<<endl<<"                          ��***��*** ����������~ ***��***��                 ��***��*** ���Ƿ�����~ ***��***��"<<endl<<endl; 
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
				cout<<" ��";
	      	else if (a[i][j]==2)
	      	    cout<<" ��";
	      	else
				cout<<" ��";
	      }
	      if(i==4)
	      	cout<<std::right<<setw(35)<<"���A�ķ�����";
	      	if(i==5)
	      	cout<<std::right<<setw(28)<<score1;
	      	if(i==9)
	      	cout<<std::right<<setw(35)<<"���B�ķ�����";
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
	cout<<"��ѽ�������Ѽ��������һ���:"<<endl;
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
	cout<<"���У����������Ѽ���������(n/y)"<<endl;
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
	cout<<"��ѽ�������Ѽ��������һ���(n/y)"<<endl;
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
	cout<<"\t\t�X*��***��***��***��***������***��***��***��***��*�[\n";
    cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t     ��ѡ��  \t\t\t|��|\n";
    cout<<"\t\t|��|\t\t   1.���װ���(Ĭ��)  \t\t|��|\n";
	cout<<"\t\t|��|\t\t   2.��װ���  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   3.�ڵװ���  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   4.�̵װ���  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   5.�׵׺���  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   6.����      \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t�^*��***��***��****��****��****��****��***��***��*�a\n\n";
	cin>>p;
	if(p==1) system("color 3f");
	else if(p==2) system("color 4f");
	else if(p==3) system("color 0f");
	else if(p==4) system("color Bf");
	else if(p==5) system("color f0");
	else if(p==6) home();
	else retry3(p);
	cout<<"�л���ɣ��Ƿ񷵻أ�(n/y)"<<endl;
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
		cout<<"\t\t�X*��***��***��***��***��ϲ��***��***��***��***��*�[\n";
   		cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t     ���A     \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t �������ʤ��  \t\t\t|��|\n";
    	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t�^*��***��***��****��****��****��****��***��***��*�a\n\n";
	}
	else
	{
		system("cls");
		cout<<endl; 
		cout<<"\t\t�X*��***��***��***��***��ϲ��***��***��***��***��*�[\n";
   		cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t     ���B     \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t �������ʤ��  \t\t\t|��|\n";
    	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
		cout<<"\t\t�^*��***��***��****��****��****��****��***��***��*�a\n\n";
	}
	cout<<"\t��Ϸ�Ѿ����������Ƿ񷵻�������?(n/y)"<<endl;
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
				cout<<"-��ϲ���A�÷���-"<<endl; 
				score1=score1+1;
				break;
			}
			else if(g==2) 
			{
				cout<<"-��ϲ���B�÷���-"<<endl; 
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
			cout<<"�Ƿ������һ��?(ȷ��������y/��������������n)"<<endl;
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
	cout<<"\t\t�X*��***��***��***��***������***��***��***��***��*�[\n";
    cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t     ��ѡ��  \t\t\t|��|\n";
    cout<<"\t\t|��|\t\t   1.�淨����  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   2.��ʼ��Ϸ  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t   3.������  \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t|��|\t\t               \t\t\t|��|\n";
	cout<<"\t\t�^*��***��***��****��****��****��****��***��***��*�a\n\n";
	cin>>h;
	if (h==1)
	{
		system("cls");
		cout<<"                ��***��*** ������ ***��***��"<<endl<<endl; 
		cout<<"1.���ɵ�һλ�������Ҫ���ӵ�λ�ã����ڸ�λ�û��� ��"<<endl; 
		cout<<"2.���ɵڶ�λ�������Ҫ���ӵ�λ�ã����ڸ�λ�û��� ��"<<endl;
		cout<<"3.�Դ�ѭ����������һλ�����ˮƽ����ֱ��б���ϴﵽ����Ӽ�Ϊʤ��"<<endl;
		cout<<"4.����Ϸ����5��3ʤ�ĵ÷���"<<endl; 
		cout<<"5.��һ�غ�A���֣�֮��ÿ�غϽ������������������"<<endl<<endl; 
		char q;
	    cout<<"�Ƿ񷵻�?n/y"<<endl;
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

