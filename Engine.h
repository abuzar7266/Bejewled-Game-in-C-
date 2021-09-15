#ifndef _ENGINE_H_
#define _ENGINE_H_
#include<iostream>
using namespace std;
#include "MenuEvents.h"
#include "Game.h"
#include <sstream>
#include <string.h>
using namespace std;	
//#include "GameEvent.cpp"
class GameEngine
{
	private:
		float GameTime;
		float TimeCount;
		int TotalMoves;
		int MovesCount;
		int ScoreRange;
		int ScoreCount;
		bool win;
		MainMenu *Main;
		NewGame *New;
		HelpCentre *Help;
		Exit *Quit;
		Settings *Manip;
		PauseMenu *Pause;
		Continue *Resume;
		Levels *Level;
		HighScore *ScoreList;
		Game *Bejewled;
		bool update_key;
		char *name;
		static bool EnterPressed;
		static bool Nputs;
		static char KEY;
		static bool NameInput;
		static char InputCase;
		static bool ShowStat;
		bool LevelChangePause;
		bool lose;
		bool levelUpdate;
		bool WonDisplay;
		bool GameMode;
	public:
		GameEngine()
		{
			NameInput = false;
			update_key = false;
			lose = false;
			LevelChangePause = true;
			win = false;
			levelUpdate = true;
		}
		void BUILD_WALLS()
		{
			DrawRectangle(0,0,100,835,colors[BLACK]);
			DrawRectangle(550,0,100,835,colors[BLACK]);
			DrawRectangle(105-1,10-1,440+2,810+3,colors[BLACK]);
			DrawRectangle(105,10,440,810,colors[PINK]);
		}
		void RUN_BOARD()
		{
			if(NameInput == true)
			{
				bool RunState = !MainMenu::getMenuCheck() && !PauseMenu::getPauseCheck();
				if(RunState)
				{
						float *f = colors[BROWN];
						int j=0;
						int xi = 0;
						for(int i=0;i<64;i++)
						{
							if(i%8==0)
							{
								j++;
								xi = 0;
							}
							if(i%2==0)
							f = colors[RED];
							else
							f = colors[BLACK];
							DrawSquare(105+5+2+xi*53,650-j*54,53,f);
							xi++;
						}
				}
		
			}
		}
		void GAME_BOOT()
		{
			Main = new MainMenu;
			New = new NewGame;
			Help = new HelpCentre;
			Quit = new Exit;
			ScoreList = new HighScore;
			Manip = new Settings;
			Level = new Levels;
			Pause = new PauseMenu;
			Resume = new Continue;
			Bejewled = new Game;
			GameTime = -1;
			TimeCount = -1;
			TotalMoves = -1;
			MovesCount = -1;
			ScoreRange = -1;
			
			//string a;
			/*cout<<"Enter Player Name";
			getline(cin,a);
			bool b = false;
			Level->setLevelSelect(Bejewled->getLevel("Players.txt",a,b));//"Abuzar"));
			if(b==true)
			{
				//cout<<"Level Set : "<<Level->getLevelSelect()<<endl;
				Bejewled->setName(a);
				//PLAYER_DATA(a);
			}*/
			TIME_UPDATE();
			MOVES_UPDATE();
			SCORE_UPDATE();
			win=false;	
		}
		void SCORE_UPDATE()
		{
			if(win==false && lose==false)
			{
				int x = rand()%100;
				ScoreRange=Bejewled->getScore()+Level->getLevelSelect()*(Level->getLevelSelect()*2+Level->getLevelSelect())+x+200;
				cout<<"Score Set"<<ScoreRange<<endl;
			}
		}
		void RUN_GAME()
		{
				static bool boot = false;
				if(boot == false)
				{
					GAME_BOOT();
					boot = true;
				}
				if(MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false && NameInput)
				{
					GAME_START();
					if(update_key==false)
					{			
						DISTRIBUTION();
						SWAP_GEMS();
						DISPLAY_MOVES();
						LEVEL_STATUS();
						LEVEL_UPDATE();
					}	
					DisplayWinPost();
				}
				DrawKeyboard();
				PLAYER_DATA();
				if(Game::GamesStart==true && NameInput && MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false)
				{
					GameTimer(GameTime,113,649);
					GamePlayDetails();
					DisplayWinPost();
				}
				
		}
		void START_LOAD()
		{
			if(NameInput)
			{
				static bool LoadCheck = false;
					static int random = 0;	
						static int Load = 0;
					static int x = 0;
					if(Load==false && x<=400)
					{		
					Load++;
						if(Load==1)
						{
							x+=2;
							if(LoadCheck==false)
							Load = 0;
						}
						if(x%26==0)
						{
							random = rand()%3;
						}
					}
					else
					{
						Load = true;
						MainMenu::MenuCheck = true;
					}
					if(Load==false){
					for(int i=0;i<=x;i++)
					{
						DrawRectangle(199-70,198,403+2,23,colors[BLUE]);			
						DrawRectangle(199-1-70,198,403+4,23+1,colors[BLACK]);				float Percent = x/4;	
						if(Load==false){
						string a = "Loading "+Num2Str(Percent)+"%";
						DrawString(330,234,a,colors[BLACK]);
						}
						if(Load==true)		
						DrawString(330,234,"Completed 100%",colors[BLUE]);
						DrawRectangle(200-70,200,i,20,colors[SKY_BLUE]);
					}
					for(int j=0;j<9;j++){
					for(int i=0;i<9;i++){
					DrawSquare(175+j*45-50,270+i*45,42,colors[BLACK]);
					}}
					for(int j=0;j<9;j++){
					for(int i=0;i<2;i++){
					DrawSquare(175+j*45-50,2+55+i*45-1,42,colors[BLACK]);
					}}
					for(int j=0;j<9;j++){
					for(int i=0;i<9;i++){				
					DrawSquare(175+j*45-50,271+i*45,40,colors[SKY_BLUE]);
					}}
					for(int j=0;j<9;j++){
					for(int i=0;i<2;i++){				
					DrawSquare(175+j*45-50,2+55+i*45,40,colors[SKY_BLUE]);
					}}
				}
			}
		}
		void MENU_MODE()
		{
			if(NameInput)
			{
				if(PauseMenu::PauseCheck==true || MainMenu::MenuCheck==true){
				Pause->Display();
				Main->Display();
				New->Display();
				Help->Display();
				if(Exit::ExitCheck==true)
				{
					Bejewled->STORE_LEVEL("Players.txt",Level->getLevelSelect());
					Quit->Display();			
				}
				Manip->Display();
				Resume->Display();
				Level->Display();
				ScoreList->Display();
				}
				if(Game::RandCheck==true)
				{
					TimeCount = 0;
					MovesCount = 0;
					ScoreCount = 0;
				}
			}
		}
		void GAME_START()
		{
			if(MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false && NameInput)
			{
				Game::GamesStart=true;
			}
			else if((MainMenu::MenuCheck==true || PauseMenu::PauseCheck==true) && NameInput)
			{
				Game::GamesStart=false;
			}
		}
		void DISTRIBUTION()
		{
			if(Game::GamesStart==true && NameInput)
			{
				Bejewled->Game::PlaceGems();
			}
		}
		void SWAP_GEMS()
		{
			//if(Game::GamesStart==true)
			if(NameInput){
				//Bejewled->DestoryAll();
				Bejewled->Game::Swap(Game::xswapid,Game::yswapid);
				if(Bejewled->gameSwapped==1)
				{
					MovesCount++;
					Bejewled->gameSwapped= 0;
				}
			}
		}
		void LEVEL_STATUS()
		{
			if(MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false && NameInput)
			{
				
			}
		}
		void Timer()
		{
			if(win==false && lose==false){
			static int x = 0;
			if(x<100)
			x++;
			else{
			bool h = (Game::InitGems==false && Game::GemsWait==false && Game::GemsIncrWait==false && Game::GemsIncr==false);
			if(h)
			TimeCount++;
			x = 0;
			}}
		}
		void LEVEL_UPDATE()
		{
			if(Game::GamesStart==true && NameInput)
			{
				if(win==false && lose==false && levelUpdate)
				{
					Game::RandCheck=true;
					Game::GamesStart = false;
					levelUpdate = false;
				}
				else
				{
					static int x = 0;
					if(win==true && x == 0)
					Level->setLevelSelect(Level->getLevelSelect()+1);
					if(win==false)
					x = 0;
					if(win==true && x == 0)
					x++;
				}
			}
		}
		void DISPLAY_MOVES()
		{
			/*if(Game::GamesStart==true && win==false && NameInput)
			{
				DrawString(113,755,"Total Moves   : "+Num2Str(TotalMoves),colors[BLACK]);
				DrawString(113,730,"Moves Attempt : "+Num2Str(MovesCount),colors[BLACK]);
				DrawString(113,755+25,"Level : "+Num2Str(Level->getLevelSelect()),colors[BLACK]);
			}*/
		}
		void TIME_UPDATE()
		{
			if(NameInput && win==false && lose==false){
			GameTime  = Level->getLevelSelect()*40+rand()%10-Level->getLevelSelect()*3;
			TimeCount = 0;}
		}
		void MOVES_UPDATE()
		{
			if(NameInput && win==false && lose==false)
			{
				int x = rand()%10;
				TotalMoves = rand()%15+rand()%Level->getLevelSelect()*Level->getLevelSelect();
				if(TotalMoves<10 || TotalMoves%5==0)
				{
					TotalMoves = 25-rand()%8;
				}
				MovesCount = 0;
			}
		}
		bool PLAYER_DATA()
		{
			if(!NameInput)
			{
				static bool Valid = false;
				static char* NameFiler = NULL;
				static int sizefiler=0;
				static int u = 1000;
				DrawString(200+30,600-10+40+20,"Enter Player Name",colors[STEEL_BLUE]);
				DrawLine(200-20,600-10,200+260,600-10,3,colors[STEEL_BLUE]);
				DrawLine(200-20,600-10+40,200+260,600-10+40,3,colors[STEEL_BLUE]);
				if(NameFiler!=NULL)
				{
					DrawLine(200,600-10,200+100,600-10,3,colors[STEEL_BLUE]);
					DrawString(200,600,NameFiler,colors[RED]);
					if(sizefiler > 15){
					sizefiler = 0;
					delete []NameFiler;
					NameFiler = NULL;
					u = 0;
					}
					if(u<100){
					DrawString(200+30,600-10+40+50," Length Exceeded!",colors[BLACK]);
					u++;}
				}
				//Bejewled->EnterPlayer(a);
				if(Nputs && KEY!='-' && KEY!='+' && KEY!='?')
				{
					cout<<"Character Add"<<endl;
						if(NameFiler==NULL)
						{
							NameFiler = new char[2];
							NameFiler[0] = KEY;
							NameFiler[1] = '\0';
							sizefiler++;
						}
						else
						{
							sizefiler++;
							char* temp = new char[sizefiler+1];
							for(int i=0;i<=sizefiler;i++)
							{
								if(i<sizefiler-1)
								{
									temp[i] = NameFiler[i];
								}
								else if(i<sizefiler)
								{
									temp[i] = KEY;
								}
								else
								{
									temp[i] = '\0';
								}
							}
							delete []NameFiler;
							NameFiler = temp;
						}
				}
				else if(KEY!='?' && Nputs)
				{
					if(KEY=='+')
					{
						Bejewled->setName(NameFiler);
						cout<<"Input Done"<<endl;
						name = new char[sizefiler+1];
						name[sizefiler]	= '\0';
						for(int i=0;i<sizefiler;i++)
						name[i] = NameFiler[i];
						sizefiler = 0;	
						bool b = false;
						Level->setLevelSelect(Bejewled->getLevel("Players.txt",NameFiler,b));
						ReadScore(NameFiler);
						Bejewled->EnterPlayer(NameFiler);
						delete []NameFiler;
						Game::NameCheck=true;
						NameInput = true;
						NameFiler = NULL;
						KEY = '?';	
						TIME_UPDATE();
						MOVES_UPDATE();
						Nputs = false;	
								
					}
					else if(KEY=='-')
					{
						//cin.ignore();
						sizefiler--;
						char* temp = new char[sizefiler+1];
							for(int i=0;i<=sizefiler;i++)
							{
								if(i<sizefiler)
								{
									temp[i] = NameFiler[i];
								}
								else
								{
									temp[i] = '\0';
								}
							}
							delete []NameFiler;
							NameFiler = temp;
					}
				}
				Nputs = false;
				KEY='?';
			}
		}
		void DrawKeyboard()
		{
			if(!NameInput)
			{
				DrawRectangle(115,320,420,250,colors[BLACK]);
				DrawRectangle(117,320+2,420-4,250-4,colors[STEEL_BLUE]);
				int xi = 0;
							if(InputCase=='U')
							{
								xi = 32;
							}
				char Print = 97-xi;
				for(int i=0;i<5;i++)
				{
					if(i>0){
					for(int j=0;j<9;j++)
					{
						DrawSquare(118+j*46,420-50+i*46-40,45,colors[BLACK]);
						if(i==4)
						{
							DrawString(130+j*46,420-50+i*46-30,Num2Str(j+1),colors[BLUE]);
						}
						else
						{
							
								char ai[2];
								ai[0] = Print;
								ai[1] = '\0';
								if(i==3 && j==8)
								ai[0]='0';
								DrawString(130+j*46,420-50+i*46-30,ai,colors[BLUE]);
								Print++;
						}
						
					}}
					else
					{
						for(int j=0;j<4;j++)
						{
							DrawSquare(232+j*46,420-50+i*46-40,45,colors[BLACK]);
							if(j==0)
								DrawString(236+j*46+15,420-50+i*46-30,"/",colors[BLUE]);
							else if(j==1)
								DrawString(236+j*46+15,420-50+i*46-30,">",colors[BLUE]);
							else if(j==2)
								DrawString(236+j*46+15,420-50+i*46-30,"^",colors[BLUE]);
							else if(j==3)
								DrawString(236+j*46+5,420-50+i*46-30,"__",colors[BLUE]);
						}
					}			
				}
			}
		}
		void ReadScore(string a)
		{
			bool c = false;
			int x = Bejewled->getScore("Players.txt",a,c);
			Bejewled->setScore(x);
			cout<<"Score : "<<x<<endl;
		}
		static void CheckInputName(int x,int y)
		{
			if(!NameInput)
			{
				y-=20;
				KEY='?';
				if(y>=330+10 && y<=570 && x>=115 && x<=536)
				{
					bool Found = false;
					char Print = 95;
					int rowNum = -1;
					int colNum = -1;
					for(int i=0;i<5;i++)
					{
						if(y>=510-i*46+8 && y<=510-i*46-20+23+36)
						{
							cout<<"Found i : "<<i+1<<endl;
							rowNum = i+1;
						}	
					}
					if(rowNum!=-1 && rowNum<=4)
					{
						for(int j=0;j<9;j++)
						{
							if(x>=118+j*46+8 && x<=118+j*46+23+36)
							{
								colNum = j+1;
								cout<<"Found j : "<<j+1<<endl;
							}	
						}
					}
					if(rowNum==5)
					{
							for(int j=0;j<4;j++)
							{
								if(x>=232+j*46+8 && x<=232+j*46+23+36)
								{
									colNum = j+1;
									cout<<"Found j : "<<j+1<<endl;
								}	
							}
					}
					if(rowNum==2 && colNum==9)
					{
						KEY = '0';
						Found = true;
					}
					if(rowNum!=-1 && colNum!=-1 &&!Found)
					{
						for(int j=0;j<9 && !Found;j++)
						{
								if(rowNum==1 && colNum==j+1)
								{
									KEY = 48+(colNum);
									Found = true;
								}
						}
						if((rowNum==2 || rowNum==3 || rowNum==4)&&!Found)
						{
							int xi = 0;
							if(InputCase=='U')
							{
								xi = 32;
							}
							for(int i=0;i<9;i++)
							{
								if(colNum==i+1)
								{
									KEY = 97+(4-rowNum)*9+i-xi;
									//cout<<"Clicked Button : "<<Clock<<endl;//(119+(4-rowNum)*9+i)<<endl;
									Found = true;
								}
							}
						}
						if(rowNum==5&& !Found)
						{
							for(int i=0;i<4;i++)
							{
								if(colNum==i+1)
								{
									if(i==0)
										KEY = '-';
									if(i==1){
										KEY = '+';}
									if(i==3)
										KEY = ' ';
									if(i==2){
										KEY = '?';
									if(InputCase=='L')
										InputCase = 'U';
									else
										InputCase = 'L';
									}
								}
							}
						}
						Found = true;
					}
					if(Found)
					{
						cout<<"BUTTON PRESSED : "<<KEY<<endl;
						Nputs = true;
					}
				}
			}
		}
		static void MenuManipulator(int x,int y,char key)
		{
			if (key == 27)
			{
				if(!MainMenu::getMenuCheck() && !PauseMenu::getPauseCheck())
				MainMenu::setMenuCheck(false);
			}

			if (key == 'b' || key == 'B')
			{ 
				cout<<"b is called"<<endl;
			}
			bool a = !NewGame::getNewCheck() && !HelpCentre::getHelpCheck() && !Settings::getSettingCheck() && !Exit::getExitCheck();
			bool b = !Levels::getLevelCheck() && !HighScore::getHighScoreCheck() && !Continue::getContinueCheck();
			bool OpenCondition = a&&b;
			if((key=='P' || key=='p') && !PauseMenu::getPauseCheck() && OpenCondition)
			{
				PauseMenu::setPauseCheck(true);
			}
			if(key==8 && (MainMenu::getMenuCheck() || PauseMenu::getPauseCheck()))
			{
				if(OpenCondition && PauseMenu::getPauseCheck())
				{
					PauseMenu::setPauseCheck(false);
				}
				if(OpenCondition && MainMenu::getMenuCheck())
				{
					MainMenu::setMenuCheck(false);
				}
				else if(MainMenu::getMenuCheck() || PauseMenu::getPauseCheck())
				{
					bool MenuBack = HelpCentre::getHelpCheck() && !Settings::getSettingCheck()
					&& !Levels::getLevelCheck() && !HighScore::getHighScoreCheck();
					if(MenuBack)
					{
						HelpCentre::setHelpCheck(false);
					}
					MenuBack = !HelpCentre::getHelpCheck() && Settings::getSettingCheck()
					&& !Levels::getLevelCheck() && !HighScore::getHighScoreCheck();
					if(MenuBack)
					{
						Settings::setSettingCheck(false);
					}
					MenuBack = !HelpCentre::getHelpCheck() && !Settings::getSettingCheck()
					&& Levels::getLevelCheck() && !HighScore::getHighScoreCheck();
					if(MenuBack)
					{
						Levels::setLevelCheck(false);
					}
					MenuBack = !HelpCentre::getHelpCheck() && !Settings::getSettingCheck()
					&& !Levels::getLevelCheck() && HighScore::getHighScoreCheck() && HighScore::NodeCheck();
					if(MenuBack)
					{
						HighScore::setHighScoreCheck(false);
					}
				}
			}
			if((MainMenu::getMenuCheck() || PauseMenu::getPauseCheck()) && OpenCondition)
			{
				if(key=='N' || key=='n')
				NewGame::setNewCheck(true);
				if(key=='H' || key=='h')
				HelpCentre::setHelpCheck(true);
				if(key=='S' || key=='s')
				Settings::setSettingCheck(true);
				if(key=='e' || key=='E')
				Exit::setExitCheck(true);
				if(MainMenu::getMenuCheck() && !PauseMenu::getPauseCheck())
				{
					if(key=='L' || key=='l')
					Levels::setLevelCheck(true);
					if(key=='O' || key=='o')
					HighScore::setHighScoreCheck(true);
				}
				if(!MainMenu::getMenuCheck() && PauseMenu::getPauseCheck())
				{
					if(key=='C' || key=='c')
					Continue::setContinueCheck(true);
				}
		
			}
		} 
	static void RefereshSystem()
	{
		if(Game::shift==true && Game::swapwait==false)
			Game::swapwait = true;
		if(Game::shift==false && Game::swapwait==true)
			Game::swapwait = false;
		if(Game::InitGems==true && Game::GemsWait==false)
			Game::GemsWait=true;
		if(Game::InitGems==false && Game::GemsWait==true)
			Game::GemsWait=false;
		if(Game::GemsIncrWait==true && Game::GemsIncr==false)
			Game::GemsIncrWait==false;
		if(Game::GemsIncrWait==false && Game::GemsIncr==true)
			Game::GemsIncrWait==true;
		if(Game::OtherGenerated && !Game::OtherGenerateWait)
			Game::OtherGenerateWait = true;
		if(!Game::OtherGenerated && Game::OtherGenerateWait)
			Game::OtherGenerateWait = false;
		Game::DisplayAxp();
			
	}
	static bool CheckToSwap(int x,int y,int &ix,int &jy)
	{

		ix = -1;
		jy = -1;
		for(int j=0;j<8;j++){
			for(int i=0;i<8;i++)
			{
				if(x>113+i*53 && x<155-5+i*53 && y>605-j*45 && y<645-j*45)
				{
					ix = i;
					jy = j;
					return true; 
					break;
				}
			}
		}
		return false;
	}
	static bool CheckToSwap(int x,int y,int xD,int yD,char &Direct)
	{
		Direct = '?';
		if(x<xD && x>xD-90 && y>yD-15 && y<yD+15)
			Direct = 'L';
		else if(x>xD && x<xD+90 && y>yD-15 && y<yD+15)
			Direct = 'R';
		else if(x>xD-15 && x<xD+15 && y<yD && y>yD-90)
			Direct = 'U';
		else if(x>xD-15 && x<xD+15 && y>yD && y<yD+90)
			Direct = 'D';
		if(Direct=='?')
		return false;
		else
		return true;
	}
	static bool CheckDirection(int i1,int j1,int i2,int j2,char &Direct)
	{
		Direct = '?';
		if(i1==i2-1 && j1==j2)
		{
			Direct = 'R';
		}
		else if(i1==i2+1 && j1==j2)
		{
			Direct = 'L';
		} 
		else if(i1==i2 && j1==j2-1)
		{
			Direct = 'D';
		}
		else if(i1==i2 && j1==j2+1)
		{
			Direct = 'U';
		}
		if(Direct=='?')
		{
			return false;
		}
		else
		return true;
	}

	static void ResetClick()
	{
		
				Game::DirectionSwap = '?';
				Game::xswapid = -1;
				Game::yswapid = -1;
	}
	void CheckState()
	{
		bool h = (Game::InitGems==false && Game::GemsWait==false && Game::GemsIncrWait==false && Game::GemsIncr==false);
		if((MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false) && NameInput && h)
		{
			if(ShowStat || (GameTime==TimeCount || TotalMoves==MovesCount))
			{
				if(ScoreRange<=Bejewled->getScore())
				{
					win = true;
					
				}
				else
				{
					lose = true;
				}
			}
			DisplayWinPost();
		}
	}
	void DisplayWinPost()
	{
		static int  x = 0;
		static int y = 0;
		if(win==true)
		{
			if(x<200)
			{
				x++;
				DrawRectangle(113+3*53+26-60,600-3*54-27-10,100+60,40,colors[BLACK]);
				DrawString(113+3*53+26-50,600-3*54-27,"YOU WIN!",colors[GREEN]);
			}
			else
			{
				x = 0;
				win = false;
				update_key=true;
				levelUpdate = true;
				LEVEL_UPDATE();
				SCORE_UPDATE();
				TIME_UPDATE();
				MOVES_UPDATE();
			}
		}
		else if(lose==true)
		{
			if(y<200)
			{
				y++;
				DrawRectangle(113+3*53+26-60,600-3*54-27-10,100+60,40,colors[BLACK]);
				DrawString(113+3*53+26-50,600-3*54-27,"YOU LOSE!",colors[GREEN]);
			}
			else
			{
				y = 0;
				lose = false;
				update_key=true;
				levelUpdate = true;
				//LEVEL_UPDATE();
				TimeCount = 0;
				MovesCount = 0;
				Bejewled->setScore(Bejewled->getScore()-ScoreCount);
				Bejewled->setScore(0);
			}
		}
	}
	void GameTimer(int Total,int x,int y)
	{
		{
			static int Z = 0 ;
			static int CountDown = 0;
			if(Game::InitGems==true)
			{
				Z = 0;
				CountDown = 0;
				ShowStat = false;
				win = false;
				lose = false;
				update_key=false;
				Bejewled->setScore(Bejewled->getScore()-ScoreCount);
				Bejewled->setScore(0);
				TimeCount = 0;
			}
			if(update_key==true)
			{
				Z = 0;
				CountDown = 0;
				ShowStat = false;
				win = false;
				lose = false;
				update_key=false;
			}
			cout<<"Z         : "<< Z<<endl;
			cout<<"CountDown : "<< CountDown<<endl;
				int n = 4*(((CountDown*100)/Total))+(((CountDown*100)/Total))/4;
				if(n>=250+2+200-28)
				{
					n = 250+2+200-28;
				}
				DrawRectangle(x-1,y-1,250+2+200-28,12+2,colors[BLACK]);
				DrawRectangle(x,y,250+200-28,12,colors[BLUE]);
				DrawRectangle(x,y,n,12,colors[GOLD]);
				DrawRectangle(x-1,y-1-443,250+2+200-28,12+2,colors[BLACK]);
				DrawRectangle(x,y-443,250+200-28,12,colors[BLUE]);
				DrawRectangle(x,y-443,n,12,colors[GOLD]);
			Timer();
			bool h = (Game::InitGems==false && Game::GemsWait==false && Game::GemsIncrWait==false && Game::GemsIncr==false);
			if(h)
			{if(Total>CountDown && !ShowStat)
			{
				Z++;
				if(Z==100)
				{
					CountDown++;
					Z = 0;
				}
			}
			else
			{
				//CheckWin();
				static bool k=0;
				if(k==0)
				{
					ShowStat = true;
					CheckState();
					k = 1;	
					Z = 0 ;
					CountDown = 0;
				}
			}}
		}
	
	}
	void GamePlayDetails()
	{
		if((MainMenu::MenuCheck==false && PauseMenu::PauseCheck==false) && NameInput)
		{
			DrawRectangle(200-80-15,130+5-80+20-20+665-100+40+20,470+5-35,100-20+100-40,colors[GRAY]);
			DrawRectangle(200-80-15,130+5-80+20+665-100+40,470+5-35,100-20+100-40,colors[GOLD]);
			DrawString(200-80,130+670,"",colors[WHITE]);
			int length = 0;
			while(name[length]!='\0')
			length++;
			char *then;
			then = new char[length+1];
			for(int i=0;i<length;i++)
			then[i] = name[i];
			then[length] = '\0';
			renderBitmapString(200-80,130+665,"Player Name  : ");
			renderBitmapString(200+40,130+665,then);
			int number = (Level->getLevelSelect());
			stringstream strs;
			  strs << number;
			  string temp_str = strs.str();
			  char* level = (char*) temp_str.c_str();
			renderBitmapString(200-80,130-20+665,"Player Level : ");
			renderBitmapString(200+40,130-20+665,level);
			renderBitmapString(200-80,130-40+665,"Player Score : ");
			renderBitmapString(200-80,130-60+665,"Score Range  : ");
			renderBitmapString(200-80,130-80+665,"Moves Left   : ");
			renderBitmapString(200-80,130-100+665,"Time  Left   : ");
			number = Bejewled->getScore();
			stringstream strs2;
			strs2 << number;
			 string temp_str2 = strs2.str();
			  char* score = (char*) temp_str2.c_str();
			renderBitmapString(200+40,130-40+665,score);
			CheckState();
			number = ScoreRange;
			stringstream strs3;
			strs3 << number;
			 string temp_str3 = strs3.str();
			  char* scor3 = (char*) temp_str3.c_str();
			renderBitmapString(200+40,130-60+665,scor3);
			number = TotalMoves-MovesCount;
			stringstream strs4;
			strs4 << number;
			 string temp_str4 = strs4.str();
			  char* scor4 = (char*) temp_str4.c_str();
			renderBitmapString(200+40,130-80+665,scor4);
			number = GameTime-TimeCount;
			stringstream strs5;
			strs5 << number;
			 string temp_str5 = strs5.str();
			  char* scor5 = (char*) temp_str5.c_str();
			renderBitmapString(200+40,130-100+665,scor5);
			//DrawString(100,100,"Score R: "+Num2Str(ScoreRange),colors[BLACK]);
			//DrawString(100,100-50,"Score R: "+Num2Str(Bejewled->getScore()),colors[BLACK]);
			{
				//DrawString(350,700+100,"Score Required : "+Num2Str(TotalMoves-MovesCount),colors[WHITE]);
				//DrawString(350,700+50,"Moves Left : "+Num2Str(TotalMoves-MovesCount),colors[WHITE]);
				//DrawString(100,100+100,"Moves  : "+Num2Str(MovesCount),colors[BLACK]);
			}
			//DrawRectangle(200-80-15,650+5-80+20-20+100,100,120-20,colors[WHITE]);
			//renderBitmapString(200+40,130,level);
			//renderBitmapString(200,700,a);*//
		}
	}
	static void SwapManipulator(int x,int y,int state)
	{
		if(!Game::shift){
		if(Game::GamesStart)
		{
		static int xCord = 0;
		static int yCord = 0;
		cout<<"State : "<<state<<endl;
		if(state==0)
		{
			GameEngine::CheckInputName(x,800-y);
		}
		if(state==0)
		{
			xCord = x;
			yCord = y;
			bool a = CheckToSwap(x,800-y,Game::xswapid,Game::yswapid);			

		}
		if(state==1 && (Game::xswapid!=-1 && Game::yswapid!=-1))
		{
			int Direcx = -1,Direcy = -1;
			bool a = CheckToSwap(x,y,xCord,yCord,Game::DirectionSwap);
			bool b = (Game::DirectionSwap=='U' || Game::DirectionSwap=='D' || Game::DirectionSwap=='L' || Game::DirectionSwap=='R');
			if(a && b){			
			if(Game::DirectionSwap=='U' && Game::yswapid>0)
			{
				Game::shift = true;
						Game::swapwait = true;
			}
			else if(Game::DirectionSwap=='D' && Game::yswapid<7)
			{
					Game::shift = true;
						Game::swapwait = true;
			}	
			else if(Game::DirectionSwap=='L' && Game::xswapid<7)
			{
				Game::shift = true;
						Game::swapwait = true;
			}
			else if(Game::DirectionSwap=='R' && Game::xswapid>0)			
			{			Game::shift = true;
						Game::swapwait = true;}
		}}
	}
		}
		
	}
		
};
bool GameEngine::EnterPressed=false;
bool GameEngine::Nputs = false;
char GameEngine::KEY = '\0';
bool GameEngine::NameInput = false;
char GameEngine::InputCase = 'L';
bool GameEngine::ShowStat = false;
#endif//Terminate _ENGINE_H_
