#include<iostream>
#include<windows.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

void PrintXY(int x, int y, int reveal[][10])
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
cout << reveal[x][y];
cout.flush();
}
		void PrintXY(int x, int y, int color)
		 {
			COORD c;
			c.X = x;
			c.Y = y;
			HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(h, &info);
			short ret = info.wAttributes;
			SetConsoleCursorPosition(h, c);
			SetConsoleTextAttribute(h, color);
			cout << "";
			cout.flush();
			SetConsoleTextAttribute(h, ret);
		}

			void place_mines(int arr[][10] )
			{
				int r,c,m;
				int count=0;
					srand(time(NULL));
					m= (rand() %5)+10;
				for(int i=0;i<10 && count!=m;i++)
				{
					for(int j=0;j<10 && count!=m;j++)
					{
						c= (rand() %9);
						r= (rand() %9);
						arr[r][c]=1;
						count++;
					}
				}
			}
			int Count_Neighboring_Mines(int arr[][10],int &count1,int &row ,int &col)
			{
				int m;
				arr[10][10];
				count1=0;
				int i,j;
					for( i=col-1;i<=col+1;i++)
					{
						
							for( j=row-1;j<=row+1;j++)
							{
								if(arr[j][i]==1)
								{
									count1++;
						    		if(i==row && j==col)
						    		{
							   		 	count1--;
							   		 } 
								}
						  }
					}
				return count1;
			}


	void colour(int &k)
	{
			for( int i=1;i<11;i++)
		{
			for(int  j=1;j<11;j++)
			{
				k=i+j;
						if(k%2==0)
						{
							PrintXY(i,j,1000);
			     	    }
			     	   else
			   		   {
			   		   	PrintXY(i,j,1231);
					   }   
            }  
        }
    }
 void PrintX1Y1(int x, int y, int &row,int&col)
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
cout<<endl;
cout << "enter the cordinates for box"<<endl;
cin>>row;
cin>>col;
cout.flush();
}
 void PrintX2Y2(int x, int y)
{
COORD c;
c.X = x;
c.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

cout.flush();
}
void playgame(int &row,int &col,int arr[][10],int reveal[][10],int &count1,int flag[][10])
{
			    	int number;
			     bool check=true;					    	
				 for(int i=0;i<100;i++)
					{
								for(int i=0;i<10;i++)
							  	{
							      		for(int j=0;j<10;j++)
							      		{
							      			if(reveal[i][j]!=0)
							      			{
							      			check=false;	
									    	}
									    	 else
									    	  {
									    	  	check=true;
									    	  	break;
											  }
									   
										 }
							   }
							   PrintX2Y2(0,11);
							   cout<<endl;
							   cout<<"To put a flag enter 1 OR to open a box enter 0 "<<endl;
							   cin>>number;
								if(number==1)
								{
									PrintX1Y1( 0,14,row,col);
									 PrintXY(row,col,3123);
									 flag[row][col]=15;
								}
							   else if(number==0)
							   {
							   	PrintX1Y1( 0,14,row,col);
								
										   if(check==false)
										  	    {
										     	cout<<"YOU WIN";
										     	break;
										   		}
								 
							                	cout<<endl;
									      	if(arr[row][col]==1)
												{
											  	cout<<"GAME OVER";
											  	break;	
												}
								     	
							          		
								            Count_Neighboring_Mines(arr,count1,row,col); 
											reveal[row][col]=count1;
												
												for(int s=0;s<10;s++)
												{
												for(int m=0;m<10;m++)
												{ 
													 if(flag[s][m]!=15)
													 {
													
														if(reveal[s][m]!=0 )
														{ 
														
														  PrintXY(s+1,m+1,0);
														  PrintXY(s+1,m+1,reveal);
												    	}
												    	else if(reveal[row][col]==0)
												    	{
												    			for( int i=col-1;i<=col+1 && i<10;i++)
																	{
																		
																			for( int j=row-1;j<=row+1 && j<10;j++)
																			{
																				 Count_Neighboring_Mines(arr,count1,i,j);
																				 reveal[i][j]=count1;
																				 PrintXY(i,j,0);
															                     PrintXY(i,j,reveal);	
																		    }
																	}
														}
													}
												}
											}
							         	}
                      }
}
int main()
{
	int x=0,y=0,k,m;
int arr[10][10]={0},count1;
int row=0,col=0;
int reveal[10][10]={0};
int flag[10][10]={0};
	cout<<" ";
	for(int i=0;i<10;i++)
	{
		cout<<i;
	}
	cout<<endl;
	for(int j=0;j<10;j++)
	{
		cout<<j<<endl;
	}
	cout<<endl;
				     place_mines(arr);     
					 colour(k); 	
				     playgame(row,col,arr,reveal,count1,flag);
}          
	
	
        
