#ifndef _GAME_H_
#define _GAME_H_
#include<iostream>
using namespace std;
#include "GameEvent.cpp"
#include "Person.cpp"
#include "Shape.cpp"
class Game:public GameEvent
{
	protected:
	Player ID;
	Shape *Gems[8][8];
	public:
	static int xSwap1Cord;
	static int xSwap2Cord;
	static int ySwap1Cord;
	static int ySwap2Cord;
	static bool GamesStart;
	static bool gameSwapped;
	static bool OtherGenerated;
	static bool OtherGenerateWait;
	static bool SwapDestruct;
	static int xps;
	static int ix;
	static int iy;








	static bool NameCheck;
	 static char DirectionSwap;
	static int xswapid;
	static int yswapid;
	 static bool swapwait;
	 static bool RandCheck;
	 static bool shift;
	 static bool GameCheck;
	static int count;
	static bool InitGems;
	static bool GemsWait;
	static bool DestroyerCheck;
	static bool SortWait;


	static bool GemsIncr;
	static bool GemsIncrWait;
	static int ScoreUp;

	void setScore(int a)
	{
		ID.setScore(a);
	}
	static int getxSwapCord1()
	{
		return xSwap1Cord;
	}
	static int getxSwapCord2()
	{
		return xSwap2Cord;
	}
	static int getySwapCord1()	
	{
		return ySwap1Cord;
	}
	static int getySwapCord2()
	{
		return ySwap2Cord;
	}
	static void setxSwapCord1(int a)
	{
		xSwap1Cord = a;
	}
	static void setxSwapCord2(int a)
	{
		xSwap2Cord = a;
	}
	static void setySwapCord1(int a)
	{
		ySwap1Cord = a;
	}
	static void setySwapCord2(int a)
	{
		ySwap2Cord = a;
	}
	Game()
	{
		
	}
	/*void setScore(int a)
	{
		ID.setScore(a);
	}*/
	void Initialization()
	{
					for(int i=0;i<8;i++)
					{
						for(int j=0;j<8;j++)
						{
							
							int x = rand()%6;
							if(x==0){
							Gems[i][j] = new Square;
							Gems[i][j]->setGemType(0);
							}
							else if(x==1){ 
							Gems[i][j] = new Triangle;
							Gems[i][j]->setGemType(1);
							}
							else if(x==2)
							{
								Gems[i][j] = new Circle;
								Gems[i][j]->setGemType(2);
							}
							else if(x==3)
							{
								Gems[i][j] = new Emerald;
								Gems[i][j]->setGemType(3);
							}
							else if(x==4)
							{
								Gems[i][j] = new Diamond;
								Gems[i][j]->setGemType(4);
							}
							else if(x==5)
							{
								Gems[i][j] = new Asscher;
								Gems[i][j]->setGemType(5);
							}
						}
					}
					for(int i=0;i<8;i++)
					{
						for(int j=0;j<8;j++)
						{
							
							int *Arr1 =  NULL;
							int *Arr2 = NULL;
							int Size = 0;
							while(SEARCH_GEMS(Arr1,Arr2,Size,i,j)){
							int x = rand()%6;
							if(x==0){
							Gems[i][j] = new Square;
							Gems[i][j]->setGemType(0);
							}
							else if(x==1){ 
							Gems[i][j] = new Triangle;
							Gems[i][j]->setGemType(1);
							}
							else if(x==2)
							{
								Gems[i][j] = new Circle;
								Gems[i][j]->setGemType(2);
							}
							else if(x==3)
							{
								Gems[i][j] = new Emerald;
								Gems[i][j]->setGemType(3);
							}
							else if(x==4)
							{
								Gems[i][j] = new Diamond;
								Gems[i][j]->setGemType(4);
							}
							else if(x==5)
							{
								Gems[i][j] = new Asscher;
								Gems[i][j]->setGemType(5);
							}
							}
						}
					}
						for(int i=0;i<8;i++)
							{
								for(int j=0;j<8;j++)
								{
									Gems[i][j]->setAxis(113+i*53,600);
								}
							}
						if(RandCheck==true)
						{
							RandCheck=false;
							InitGems=true;
							GemsWait=true;
						}
	}
	void ANIMA()
	{
			 InitialGemsAnim();
				 for(int i=0;i<8;i++)
				{
					for(int j=7-count;j<8;j++)
					{
						if(Gems[i][j]!=NULL)
						Gems[i][j]->Draw();
					}
				}
	}
	void NormalMode()
	{
				for(int i=0;i<8;i++)
				{
					for(int j=0;j<8;j++)
					{
						if(Gems[i][j]!=NULL)
						Gems[i][j]->Draw();
					}
				}
				if(swapwait==false && shift==false && GemsIncrWait==false && GemsIncr==false)
				{
					for(int i=0;i<8;i++)
						{
							for(int j=0;j<8;j++)
							{
								if(Gems[i][j]!=NULL)
								Gems[i][j]->setAxis(113+i*53,600-j*54);
							}
						}
				}
				//GemsIncre();
				DrawString(180,700,Num2Str(ID.getScore()),colors[BLACK]);
				DrawString(180+100,700,(ID.getName()),colors[BLACK]);
	}
	void PlaceGems()
	{
		cout<<"Enter"<<endl;
		if(GamesStart==true)
		{
				if(RandCheck==true)
				{cout<<"Enter1"<<endl;
				Initialization();}
				else
				{
					if(InitGems==true && GemsWait==true)
					ANIMA();
					else if(InitGems==false && GemsWait==false)
					NormalMode();
				}
		}
		glutPostRedisplay();
		
	}
	void InitialGemsAnim()
	{
		if(GemsIncr==false && GemsIncr==false){
		static int count2 = 0;
		if(count>=7)
		{
			InitGems = false;
			GemsWait = false;
			count = 0;
			count2 = 0;
			
			for(int i=0;i<8;i++)
					{
						for(int j=0;j<8;j++)
						{
							Gems[i][j]->setAxis(113+i*53,600-54*j);
						}
					}
		}
		if(InitGems==true && GemsWait==true)
		{
			for(int i=0;i<8;i++)
			{
				Gems[i][7-count]->YDecrementAxis(10);
				GemsWait=false;
			}
			count2+=10;
			if(count2>=54*(7-count))
			{
				count++;
				count2 = 0;
			}
			
		}
			}
		glutPostRedisplay();
	}
	/*void GemsIncre()
	{
		static int count2 = 0;
		if(GemsIncr==true && GemsIncrWait==true)
		{
			cout<<"Entering"<<endl;
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8-count+1;j++)
				{
					if(Gems[i][j]->gety()<=600-j*54)
					{	
						cout<<"Copied : "<<count<<","<<i<<"-"<<j<<endl;
						//Gems[i][j]->YDecrementAxis(10);
						
					}
				}
			}
			count2+=10;
			if(count2>=54*(count))
			{
				cout<<"count : "<<count<<endl;
				count--;
				count2 = 0;
			}
			GemsIncrWait = false;
		}
		if(count==0 && GemsIncrWait==true)
		{
			GemsIncr = false;
			GemsIncrWait = false;
			cout<<"End"<<endl;
			count = 0;
		}
	}*/
	void EnterPlayer(string a)
	{
		
			ID.setPlayer(a,0);
			STORE_DATA("Players.txt",a);
	}
	string getName()
	{		
		return ID.getName();
	}
	static void Update()
	{
		swapwait = false;
		shift = false;
		RandCheck  = true;
		GameCheck = false;
	}
	static void DisplayAxp()
	{
		if(xps>3)
		{
			static int x = 0;
			cout<<"XpaX : "<<ix<<endl;
			cout<<"XpaY : "<<iy<<endl;
			DrawRectangle(113+ix*53+10-5+5-20+10,600-iy*54+20-30+20-15,30+50-35,30+40-20,colors[BLACK]);
			DrawString(113+ix*53+5,600-iy*54+20-15,"X"+Num2Str(xps),colors[GREEN]);
			if(x<100)
			{
				x++;
			}
			else
			{
				ix = -1;
				iy = -1;
				xps = -1;
				x = 0;
			}
		}
		else if(xps==3)
		{
			static int x = 0;
			cout<<"XpaX : "<<ix<<endl;
			cout<<"XpaY : "<<iy<<endl;
			DrawRectangle(113+3*53+26-60,600-3*54-27-10,100+60,40,colors[BLACK]);
			DrawString(113+3*53+26-50,600-3*54-27,"GOOD WIN!",colors[GREEN]);
			if(x<100)
			{
				x++;
			}
			else
			{
				ix = -1;
				iy = -1;
				xps = -1;
				x = 0;
			}
		}
	}
	void Swap(int i1,int j1)
	{
		static int Count = 1;
		int Directx,Directy;
		static int count3 = 0;
		//static int EnterTimes = 0;
cout<<"Game Start Check : ("<<i1<<","<<j1<<") = "<<swapwait<<"-"<<shift<<"-"<<InitGems<<"-"<<GemsWait<<"-"<<GemsIncrWait<<"-"<<GemsIncr<<endl;
	if(swapwait==true && shift==true && InitGems==false && GemsWait==false && GemsIncrWait==false && GemsIncr==false)
		{
			if(DirectionSwap=='R')
			{
				if(Count==1)
				{
					setxSwapCord1(Gems[i1][j1]->getx());
					setySwapCord1(Gems[i1][j1]->gety());
					setxSwapCord2(Gems[i1-1][j1]->getx());
					setySwapCord2(Gems[i1-1][j1]->gety());
				}
				Gems[i1][j1]->XIncrementAxis(1);
				Gems[i1+1][j1]->XDecrementAxis(1);
				Directx = i1+1;
				Directy = j1;
			}
			else if(DirectionSwap=='L')
			{
				if(Count==1)
				{
					setxSwapCord1(Gems[i1][j1]->getx());
					setySwapCord1(Gems[i1][j1]->gety());
					setxSwapCord2(Gems[i1+1][j1]->getx());
					setySwapCord2(Gems[i1+1][j1]->gety());
				}
				Gems[i1-1][j1]->XIncrementAxis(1);
				Gems[i1][j1]->XDecrementAxis(1);
				Directx = i1-1;
				Directy = j1;
			}
			else if(DirectionSwap=='U')
			{
				if(Count==1)
				{
					setxSwapCord1(Gems[i1][j1]->getx());
					setySwapCord1(Gems[i1][j1]->gety());
					setxSwapCord2(Gems[i1][j1-1]->getx());
					setySwapCord2(Gems[i1][j1-1]->gety());
				}
				Gems[i1][j1]->YIncrementAxis(1);
				Gems[i1][j1-1]->YDecrementAxis(1);
				Directx = i1;
				Directy = j1-1;
			}
			else if(DirectionSwap=='D')
			{
				if(Count==1)
				{
					setxSwapCord1(Gems[i1][j1]->getx());
					setySwapCord1(Gems[i1][j1]->gety());
					setxSwapCord2(Gems[i1][j1+1]->getx());
					setySwapCord2(Gems[i1][j1+1]->gety());
				}
				Gems[i1][j1]->YDecrementAxis(1);
				Gems[i1][j1+1]->YIncrementAxis(1);
				Directx = i1;
				Directy = j1+1;
			}
			Count++;
			swapwait=false;






			if(Count>=54 && count3 == 0)
			{
				static bool SwappedAct = true;
					int ix = i1;
					int jy = j1;
					Shape *Arr = Gems[i1][j1];
					Gems[i1][j1] = Gems[Directx][Directy];
					Gems[Directx][Directy] = Arr;
					Count = 1;
					SwappedAct = false;
				bool a = false;
				bool b = false;
				int *xi = NULL;
				int *yi = NULL;
				int ElementsFound = 0;
				int Size = 0;
				int *Ax = NULL;
				int *Ay = NULL;
				int Size2 = 0;
				int *Ax2 = NULL;
				int *Ay2 = NULL;
				int i2 = Directx;
				int j2 = Directy;
				int T1=Gems[i1][j1]->getGemType();
				int T2=Gems[Directx][Directy]->getGemType();
				if(T1!=T2)
				{
					a = SEARCH_GEMS(Ax,Ay,Size,i1,j1);
					b = SEARCH_GEMS(Ax2,Ay2,Size2,i2,j2);
					if(a==true || b==true)
					{
						MergeAxis(Ax,Ax2,Size,Size2,xi);
						MergeAxis(Ay,Ay2,Size,Size2,yi);
						ElementsFound = Size+Size2;
					}
					if(a==true || b==true)
					{
						/*for(int i=0;i<ElementsFound;i++)
							{
								cout<<i+1<<"-["<<xi[i]<<"]["<<yi[i]<<"]"<<endl;
							}*/
						GemsRemove(xi,yi,ElementsFound,i1,j1);
						swapwait = false;
						shift = false;
						SwapDestruct = true; 
						gameSwapped = 1;
						count3 = 0;
						
					}
					else
						count3 = 1;
				}
				else
				count3 = 1;
			}
			if(Count>=54 && count3 == 1)
			{
				swapwait = false;
				shift = false;
				Shape *Arr = Gems[i1][j1];
					Gems[i1][j1] = Gems[Directx][Directy];
					Gems[Directx][Directy] = Arr;
				Count = 1;
				count3 = 0;
			}
		}
		glutPostRedisplay();
	}
	void STORE_DATA(string Dir,string a)
	{
		fstream File(Dir,ios::out | ios::app);
		File <<"---------------------------"<<endl;
		File <<"Player Name  : " + a <<endl;
	}
	bool Search()
	{
		fstream File("Players.txt",ios::out| ios::in);
		File.clear();
		string a;
		bool t = false;
			while(!File.eof() && a!=ID.getName())
			{
				File >> a;
				if(a==ID.getName())
				return true;
			}
		return false;
	}	
	void STORE_LEVEL(string Dir,int Level)
	{
		if(Search())
		{
			fstream File("Players.txt",ios::out| ios::in);
			File.clear();
			string a;
			bool t = false;
				while(!File.eof() && a!=ID.getName())
				{
					File >> a;
				}
					File << "Player Level : " + Num2Str(Level) <<endl;
					File << "Player Score : " + Num2Str(ID.getScore()) <<endl;
		}
		else
		{
			fstream File("Players.txt",ios::out| ios::in | ios::app);
			File.clear();
			File << "Player Level : " + Num2Str(Level) <<endl;
			File << "Player Score : " + Num2Str(ID.getScore()) <<endl;
		}
	}
	void setName(string a)
	{
		ID.setName(a);
	}
	int getScore(string Dir,string a,bool &c)
	{
		fstream File(Dir,ios::in | ios::app);
		string Name;
		bool Find = false;
		bool LevelFind = false;
		while(!File.eof() && LevelFind == false && Find == false)
		{
			//File >> Name;
			getline(File,Name);
			cout<< Name <<endl;
			if(Name=="Player Name  : "+a)
			{
				cout<<"Matched" + Name <<endl;
				Find = true;
				File >> Name;
				File >> Name;
				
				if((Name=="Score"))
				{
					c = true;
					File >> Name;
					File >> Name;
					cout<<"Score Retrieved : "<<Name<<endl;
					return stoi(Name);
				}
				else
				return 1;
				break;
			}
		}
		return 1;
	}
	int getLevel(string Dir,string a,bool &c)
	{
		fstream File(Dir,ios::in | ios::app);
		string Name;
		bool Find = false;
		bool LevelFind = false;
		while(!File.eof() && LevelFind == false && Find == false)
		{
			//File >> Name;
			getline(File,Name);
			cout<< Name <<endl;
			if(Name=="Player Name  : "+a)
			{
				cout<<"Matched" + Name <<endl;
				Find = true;
				File >> Name;
				File >> Name;
				
				if((Name=="Level"))
				{
					c = true;
					while(!File.eof())
					{
						File >> Name;
						File >> Name;
						return stoi(Name);
					}
				}
				else
				return 1;
				break;
			}
		}
		return 1;
	}
	void GemsRemove(int *x,int *y,int Size,int i,int j)
	{
		/*if(Size>0)
		{
			GemsIncr = true;
			GemsIncrWait = true;
		}*/
		Game::SwapDestruct = false;
		for(int i=0;i<Size;i++)
		{
			if(Gems[x[i]][y[i]]!=NULL)
			{
				delete Gems[x[i]][y[i]];
				Gems[x[i]][y[i]] = NULL;
			}
		}
		SortGemsLine();
		count = 0;
		int ScoreCount = 0;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(Gems[j][i]==NULL)
				{
					ScoreCount++;
				}
			}
		}
		ix = i;
		iy = j;
		xps = ScoreCount;
				int bonus = 0;
				if(ScoreCount==3)
				bonus = 0;
				if(ScoreCount==4)
				bonus = ScoreCount*2*0.2;
				if(ScoreCount>4)
				bonus = ScoreCount*2*0.5;
				ID.setScore(ID.getScore()+(ScoreCount)*3+bonus);
				cout<<"Counts : "<<ID.getScore()<<endl;
				sleep(1);
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<8;j++)
			{
				if(Gems[i][j]==NULL)
				{
					int x = rand()%6;
							if(x==0){
							Gems[i][j] = new Square;
							Gems[i][j]->setGemType(0);
							}
							else if(x==1){ 
							Gems[i][j] = new Triangle;
							Gems[i][j]->setGemType(1);
							}
							else if(x==2)
							{
								Gems[i][j] = new Circle;
								Gems[i][j]->setGemType(2);
							}
							else if(x==3)
							{
								Gems[i][j] = new Emerald;
								Gems[i][j]->setGemType(3);
							}
							else if(x==4)
							{
								Gems[i][j] = new Diamond;
								Gems[i][j]->setGemType(4);
							}
							else if(x==5)
							{
								Gems[i][j] = new Asscher;
								Gems[i][j]->setGemType(5);
							}
					Gems[i][j]->setAxis(113+i*53,600);
				}
				else
				{
					Gems[i][j]->setAxis(113+i*53,600-j*54);
				}
			}
		}
		
	}
	void SortGemsLine()
	{
		for(int z=0;z<8;z++)
		{
			for(int i=7;i>=0;i--)
			{
				for(int j=0;j<8;j++)
				{
					if(j-1>=0 && j-1<=7){
					if(Gems[i][j]==NULL && Gems[i][j-1]!=NULL)
					{
						int x =Gems[i][j-1]->getGemType();
						
							if(x==0){
							Gems[i][j] = new Square;
							Gems[i][j]->setGemType(0);
							}
							else if(x==1){ 
							Gems[i][j] = new Triangle;
							Gems[i][j]->setGemType(1);
							}
							else if(x==2)
							{
								Gems[i][j] = new Circle;
								Gems[i][j]->setGemType(2);
							}
							else if(x==3)
							{
								Gems[i][j] = new Emerald;
								Gems[i][j]->setGemType(3);
							}
							else if(x==4)
							{
								Gems[i][j] = new Diamond;
								Gems[i][j]->setGemType(4);
							}
							else if(x==5)
							{
								Gems[i][j] = new Asscher;
								Gems[i][j]->setGemType(5);
							}
						delete Gems[i][j-1];
						Gems[i][j-1] = NULL;
					}}
				}
			}
		}
		
					for(int i=0;i<8;i++)
						{
							for(int j=0;j<8;j++)
							{
								if(Gems[i][j]!=NULL)
								Gems[i][j]->setAxis(113+i*53,600-j*54);
							}
						}
	}	



























	void MergeAxis(int *FIRST,int *SECOND,int Size1,int Size2,int *&RESULTANT)
	{
		RESULTANT = new int[Size1+Size2];
		for(int i=0;i<Size1;i++)
		{
			RESULTANT[i] = FIRST[i];
		}
		int x=0;
		for(int i=Size1;i<Size1+Size2;i++)
		{
			RESULTANT[i] = SECOND[x];
			x++;
		}
	}
	int getScore()const
	{
		return ID.getScore();
	}
	bool SEARCH_GEMS(int *&iAxis,int *&jAxis,int &Size,int x,int y)
	{

			if(iAxis!=NULL)
			delete []iAxis;
			if(jAxis!=NULL)
			delete []jAxis;
			Size = 0;
			int *SET_OF_GEMS = new int[8];
			int GEMTYPE = Gems[x][y]->getGemType();
			int *Hori = NULL;
			int *Verti = NULL;
			int S1 = 0,S2 = 0;
			for(int i=0;i<8;i++)
			{
				SET_OF_GEMS[i] = Gems[i][y]->getGemType();
			}
			GET_IDX(Hori,S1,SET_OF_GEMS,GEMTYPE,x);
			for(int i=0;i<8;i++)
			{
				SET_OF_GEMS[i] = Gems[x][i]->getGemType();
			}
			GET_IDX(Verti,S2,SET_OF_GEMS,GEMTYPE,y);
			int RESULTANT_COUNT = S1+S2;
			if(RESULTANT_COUNT>0){
			iAxis = new int[RESULTANT_COUNT];
			jAxis = new int[RESULTANT_COUNT];
			for(int i=0;i<S1;i++)
			{
				iAxis[i] = Hori[i];
				jAxis[i] = y;
			}
			int j = 0;
			for(int i=S1;i<RESULTANT_COUNT;i++)
			{
				iAxis[i] = x;
				jAxis[i] = Verti[j];
				j++;
			}}
			Size = RESULTANT_COUNT;
			if(Size>0)
			return true;
			else
			return false;
	}
	void  GET_IDX(int *&Ax,int &Size,int *GEM_TYPES,int Type,int ax)
	{
		int ACTIVE_1 = true;
		int ACTIVE_2 = false;
		
		int *x = NULL;
		int SETS_COUNTER1 = 0;
		int SETS_COUNTER2 = 0;
		int FirstS = -1;	
		int SecondS = -1;
		static bool S_1 = false;
		static bool S_2 = false;
		S_1 = true;
		S_2 = false;	
		for(int i=0;i<8;i++)
		{
			if(GEM_TYPES[i] == Type)
			{
				if(ACTIVE_1==true)
				{
					SETS_COUNTER1++;
					if(S_1==true)
					{
						if(i<=5){
						FirstS = i;
						S_1 = false;}
					}	
				}
				else if(ACTIVE_2==true)
				{
					SETS_COUNTER2++;
					if(S_2==true)
					{
						if(i<=5){
						SecondS = i;
						S_2 = false;}	
					}
				}
			}
			else
			{
	
				if(ACTIVE_1==true)
				{
					if(SETS_COUNTER1<3)
					{
						S_1 = true;
						FirstS = -1;
						SETS_COUNTER1 = 0;
					}
					else
					{
						S_2 = true;
						S_1 = false;
						ACTIVE_1=false;	
						ACTIVE_2=true;					
					}
				}
				else if(ACTIVE_2==true)
				{
					if(SETS_COUNTER2<3)
					{
						S_2 = true;
						SecondS = -1;
						SETS_COUNTER2 = 0;
					}
					else
					{
						S_2 = false;
						S_1 = false;
						ACTIVE_1=false;	
						ACTIVE_2=false;					
					}
				}
			}	
		}
		if(SETS_COUNTER1<3)
		SETS_COUNTER1 = 0;
		if(SETS_COUNTER2<3)
		SETS_COUNTER2 = 0;
		if(SETS_COUNTER1!=0)
		{
			if(ax>=FirstS && ax<FirstS+SETS_COUNTER1)
			{
				if(Ax == NULL)
				{
					Ax = new int[SETS_COUNTER1];
					Size = SETS_COUNTER1;
					int x=0;
					for(int i=FirstS;i<FirstS+SETS_COUNTER1;i++)
					{
						Ax[x] = i;
						x++;
					}
				}
				else
				{
					int *Temp = new int[Size+SETS_COUNTER1];
					for(int i=0;i<Size;i++)
					Temp[i] = Ax[i];
					int x = Size;
					Size += SETS_COUNTER1;
					for(int i=FirstS;i<FirstS+SETS_COUNTER1;i++)
					{
						Temp[x] = i;
						x++;
					}
					delete []Ax;
					Ax = new int[Size];
					for(int i=0;i<Size;i++)
					Ax[i] = Temp[i];
					delete []Temp;
					
				}
			}
		}
		if(SETS_COUNTER2!=0)
		{
			if(ax>=SecondS && ax<SecondS+SETS_COUNTER2)
			{
				if(Ax == NULL)
				{
					Ax = new int[SETS_COUNTER2];
					Size = SETS_COUNTER2;
					int x=0;
					for(int i=SecondS;i<SecondS+SETS_COUNTER2;i++)
					{
						Ax[x] = i;
						x++;
					}
				}
				else
				{
					int *Temp = new int[Size+SETS_COUNTER2];
					for(int i=0;i<Size;i++)
					Temp[i] = Ax[i];
					int x = Size;
					Size += SETS_COUNTER2;
					for(int i=SecondS;i<SecondS+SETS_COUNTER2;i++)
					{
						Temp[x] = i;
						x++;
					}
					delete []Ax;
					Ax = new int[Size];
					for(int i=0;i<Size;i++)
					Ax[i] = Temp[i];
					delete []Temp;
					
				}
			}
		}
	}
};

	int Game::xSwap1Cord = 0;
	int Game::xSwap2Cord = 0;
	int Game::ySwap1Cord = 0;
	int Game::ySwap2Cord = 0;
	bool Game::GamesStart = true;
	int Game::ScoreUp = 0;
bool Game::NameCheck = false;
 bool Game::swapwait = false;
 bool Game::RandCheck = true;
 bool Game::shift = false;
 bool Game::GameCheck = true;
int Game::xswapid = -1;
int Game::yswapid = -1;
char Game::DirectionSwap = '?';
bool Game::InitGems=false;
bool Game::GemsWait=false;
bool Game::DestroyerCheck = false;
bool Game::SortWait = false;
int Game::count = 0;
bool Game::GemsIncr = false;
bool Game::GemsIncrWait = false;
bool Game::OtherGenerated = false;
bool Game::OtherGenerateWait = false;
bool Game::gameSwapped = false;
 bool Game::SwapDestruct = false;

int Game::xps = -1;
int Game::ix = -1;
int Game::iy = -1;
#endif//TERMINATE _GAME_H_
