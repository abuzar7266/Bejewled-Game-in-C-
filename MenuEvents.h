#ifndef _MENU_H_
#define _MENU_H_
#include<iostream>
using namespace std;
#include "GameEvent.cpp"
#include "util.h"
void renderBitmapString(float x, float y,const char *chars){
    const char *c;
    glRasterPos2f(x, y);
    for (c=chars; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
} 
class MainMenu
{
	public:
		static bool MenuCheck;
		virtual void Display()
		{
			if(getMenuCheck()){
				for(int i=0;i<6;i++){	
				DrawRoundRect(219,600-1-i*65,180+2,49,colors[BLACK],5);
				DrawRoundRect(221,600-i*65,180,45,colors[SKY_BLUE],5);
				}
				DrawString(250,613,"New Game", colors[BLACK]);
				DrawString(250,613-65,"Levels", colors[BLACK]);
				DrawString(250,613-2*65,"High Score", colors[BLACK]);
				DrawString(250,613-3*65,"Help Centre", colors[BLACK]);
				DrawString(250,613-4*65,"Settings", colors[BLACK]);	
				DrawString(250,613-5*65,"Exit", colors[BLACK]);	
			}
		}
		static bool getMenuCheck()
		{
			return MenuCheck;
		}
		static void setMenuCheck(bool a)
		{
			MenuCheck = a;
		}
};
class PauseMenu
{
	public:
		static bool PauseCheck;
		virtual void Display()
		{
			//cout<<"getPauseCheck()"<<endl;
			if(getPauseCheck()){
			cout<<"PauseOn"<<endl;
				for(int i=0;i<5;i++){	
				DrawRoundRect(219,600-1-i*65,180+2,49,colors[BLACK],5);
				DrawRoundRect(221,600-i*65,180,45,colors[SKY_BLUE],5);
				}
			DrawString(250,613,"Continue", colors[BLACK]);
			DrawString(250,613-65,"New Game", colors[BLACK]);
			DrawString(250,613-2*65,"Help Centre", colors[BLACK]);
			DrawString(250,613-3*65,"Settings", colors[BLACK]);
			DrawString(250,613-4*65,"Exit", colors[BLACK]);	}
		}
		static bool getPauseCheck()
		{
			return PauseCheck;
		}
		static void setPauseCheck(bool a)
		{
			PauseCheck = a;
		}
};
class NewGame:virtual public PauseMenu,virtual public MainMenu
{	public:
		static bool NewCheck;
		static int Mode;
		virtual void Display()
		{
			if(getNewCheck())
			{	setPauseCheck(false);
				setMenuCheck(false);
				setNewCheck(false);
				Game::RandCheck=true;
			}
		}
		static bool getNewCheck()
		{
			return NewCheck;
		}
		static void setNewCheck(bool a)
		{
			NewCheck = a;
		}
};
class HelpCentre:virtual public PauseMenu,virtual public MainMenu
{
		public:
		static bool HelpCheck;
		virtual void Display()
		{
			if(getHelpCheck()){
				DrawRoundRect(219,765-1,180+2,49,colors[BLACK],5);
				DrawRoundRect(221,765,180,45,colors[SKY_BLUE],5);
				DrawRoundRect(348+40+2,128+30-1,180+2-50,49,colors[BLACK],5);
				DrawRoundRect(350+40+2,128+30,180-50,45,colors[SKY_BLUE],5);
				DrawString(250,780,"Help Centre", colors[BLACK]);
				DrawString(350+40+2+29,128+30+15,"Back", colors[BLACK]);
				DrawRectangle(120+5-1,40+200-1,400+2,700-200+3,colors[BLACK]);
				DrawRectangle(120+5,40+200,400,700-200,colors[SKY_BLUE]);
				DrawRectangle(120+2+5,40+2+200,400-4,700-4-200,colors[BLACK]);
				DrawRectangle(120+2+5+2,40+2+2+200,400-4-4,700-4-4-200,colors[SKY_BLUE]);
				renderBitmapString(140,700+10,"Welcome To This Game,Developed By Abuzar During");
				renderBitmapString(140,700-10,"his Project in FAST University Islamabad 2020.");
				DrawString(140,700-100+20,"1- GamePlay Guide",colors[BLACK]);
				DrawString(140,700-150+20,"2- Score Guide",colors[BLACK]);
				DrawString(140,700-200+20,"3- Menu Guide",colors[BLACK]);
				DrawString(140,700-250+20,"3- Login-Scheme Guide",colors[BLACK]);
				}
		}
		static bool getHelpCheck()
		{
			return HelpCheck;
		}
		static void setHelpCheck(bool a)
		{
			HelpCheck = a;
		}
};
class Exit:virtual public PauseMenu,virtual public MainMenu
{
		public:
		static bool ExitCheck;
		virtual void Display()
		{
			if(getExitCheck())
			{
				
				exit(1);
			}
		}
		static bool getExitCheck()
		{
			return ExitCheck;
		}
		static void setExitCheck(bool a)
		{
			ExitCheck = a;
		}
};
class Settings:virtual public PauseMenu,virtual public MainMenu
{
	public:
		static bool SettingCheck;
		virtual void Display()
		{
				if(getSettingCheck())			
				{
				DrawRoundRect(219,765-1,180+2,49,colors[BLACK],5);
				DrawRoundRect(221,765,180,45,colors[SKY_BLUE],5);
				DrawRoundRect(348+40+2,128+30-1,180+2-50,49,colors[BLACK],5);
				DrawRoundRect(350+40+2,128+30,180-50,45,colors[SKY_BLUE],5);
				DrawString(250,780,"Settings", colors[BLACK]);
				DrawString(350+40+2+29,128+30+15,"Back", colors[BLACK]);
				DrawRectangle(120+5-1,40+200-1,400+2,700-200+3,colors[BLACK]);
				DrawRectangle(120+5,40+200,400,700-200,colors[SKY_BLUE]);
				DrawRectangle(120+2+5,40+2+200,400-4,700-4-200,colors[BLACK]);
				DrawRectangle(120+2+5+2,40+2+2+200,400-4-4,700-4-4-200,colors[SKY_BLUE]);
				DrawString(120+2+5+2,40+2+2+200,"",colors[BLACK]);
				renderBitmapString(140,700+10,"Welcome To This Game,Developed By Abuzar During");
				renderBitmapString(140,700-10,"his Project in FAST University Islamabad 2020.");
				renderBitmapString(140,700-30,"This Section is Used for Audio Controllling and");
				renderBitmapString(140,700-50,"Game Difficulty.");
				DrawString(140,700-100,"1- Audio Settings",colors[BLACK]);
				DrawString(140,700-150,"2- GamePlay Settings",colors[BLACK]);
				DrawString(140,700-200,"3- Themes Settings",colors[BLACK]);
				}
		}
		static bool getSettingCheck()
		{
			return SettingCheck;
		}
		static void setSettingCheck(bool a)
		{
			SettingCheck = a;
		}
};
class Continue:public PauseMenu
{
	public:
	static bool ContinueCheck;
		virtual void Display()
		{
			if(getContinueCheck()){
			setPauseCheck(false);
			setContinueCheck(false);
			}
		}
		static bool getContinueCheck()
		{
			return ContinueCheck;
		}
		static void setContinueCheck(bool a)
		{
			ContinueCheck = a;
		}
};
class HighScore:public MainMenu
{
	static int *MAXList;
	static string *ListName;
	static int ScoreStore;
	static int *MAXLevel;
	static int ListCount;
	static int Nodeid;
	public:
	static bool HighScoreCheck;
		HighScore()
		{
			 ListCount = 0;
			 ListName = NULL;
			 MAXLevel = NULL;
			 MAXList = NULL;
		}
		int PlayersCount()	
		{
			fstream File("Players.txt",ios::in | ios::app);
			string a;
			int c = 0;
			while(!File.eof())
			{
				File >> a;
				if(a=="Score")
				{
					c++;
				}
			}
			return c;
		}
		bool DescendingList()
		{
			for(int i=0;i<ListCount;i++)
			{
				for(int k=0;k<ListCount;k++)
				{
					if(MAXList[i]>MAXList[k])
					{
						string temp1;
						int temp2;
						int temp3;
						temp2 = MAXList[i];
						temp3 = MAXLevel[i];
						temp1 = ListName[i];
						MAXList[i]  = MAXList[k];
						MAXLevel[i] = MAXLevel[k];
						ListName[i] = ListName[k];
						MAXList[k]  = temp2;
						MAXLevel[k] = temp3;
						ListName[k] = temp1;
						
					}
				}
			}
		}
		bool ReadScores()
		{
			if(ListName!=NULL)
			{
				delete []ListName;
				delete []MAXLevel;
				delete []MAXList;
				ListName = NULL;
				MAXLevel = NULL;
				MAXList  = NULL;
			}
			ListCount = 0;
			ifstream File("Players.txt",ios::in);
			if(!File.eof())
			{
				string NameSearch;
				string a;
				string b;
				while(!File.eof() && ListCount<PlayersCount())
				{
					File >> NameSearch;
					if(NameSearch=="Name")
					{
						ListCount++;
						File >> NameSearch;
						getline(File,NameSearch);
						while(a!="Level")
						{
							File >> a ;
						}
						if(a=="Level")
						{
							File >> a;
							File >> a;
							//Add(NameSearch,stoi(a),ListCount);
						}
						while(b!="Score")
						{
							File >> b;
						}
						if(b=="Score")
						{
							File >> b;
							File >> b;
							Add(NameSearch,stoi(a),stoi(b),ListCount);
							NameSearch = "?";
							b = "?";
							a = "?";
						}
					}
				}
			}
			return true;
		}
		void Add(string a,int level,int score,int i)
		{
			if(ListName==NULL || i==1)
			{
				ListName = new string[i];
				ListName[i-1] = a; 
				MAXLevel = new int[i];
				MAXLevel[i-1] = level;
				MAXList = new int[i];
				MAXList[i-1] = score;
			}
			else
			{
				string *Temp = new string[i];
				int *Temp2 = new int[i];
				int *Temp3 = new int[i];
				for(int j=0;j<i;j++)
				{
					if(j<i-1)
					{
						Temp[j] = ListName[j];
						Temp2[j] = MAXLevel[j];
						Temp3[j] = MAXList[j];
					}
					else
					{
						Temp[j] = a;
						Temp2[j] = level;
						Temp3[j] = score;
					}
				}
				delete []ListName;
				delete []MAXLevel;
				delete []MAXList;
				ListName = new string[i];
				MAXLevel = new int[i];
				MAXList = new int[i];
				for(int j=0;j<i;j++)
				{
					ListName[j] = Temp[j];
					MAXLevel[j] = Temp2[j];
					MAXList[j] = Temp3[j];
				}
				delete []Temp;
				delete []Temp2;
				delete []Temp3;
			}
		}
		void DisplayScores()
		{
			ReadScores();
			DescendingList();
			for(int i=0;i<ListCount && i<8;i++)
			{
				DrawString(130+90,650-i*55,Num2Str(MAXList[i]),colors[BLACK]);
				DrawString(130+20,650-i*55,Num2Str(i+1),colors[BLACK]);
			}
		}
		virtual void Display()
			{
				if(getHighScoreCheck())
				{
					DrawRoundRect(219,765-1,180+2,49,colors[BLACK],5);
					DrawRoundRect(221,765,180,45,colors[SKY_BLUE],5);
					DrawRoundRect(348+40+2,128+30-1,180+2-50,49,colors[BLACK],5);
					DrawRoundRect(350+40+2,128+30,180-50,45,colors[SKY_BLUE],5);
					DrawString(250,780,"High Score", colors[BLACK]);
					DrawString(350+40+2+29,128+30+15,"Back", colors[BLACK]);
					DrawRectangle(120+5-1,40+200-1,400+2,700-200+3,colors[BLACK]);
					DrawRectangle(120+5,40+200,400,700-200,colors[SKY_BLUE]);
					DrawRectangle(120+2+5,40+2+200,400-4,700-4-200,colors[BLACK]);
					DrawRectangle(120+2+5+2,40+2+2+200,400-4-4,700-4-4-200,colors[SKY_BLUE]);
					DrawString(130,700," #Rank          Score                    Details",colors[BLACK]);
					//DrawLine(130-2,690,113+408,690,2,colors[BLACK]);
					DrawLine(130+100-25,736,130+100-25,240+3,2,colors[BLACK]);
					DrawLine(130+100+200,736,130+100+200,240+3,2,colors[BLACK]);
					for(int i=0;i<8;i++)
					{
						DrawRoundRect(440,640-i*55,60,40,colors[BLACK],10);
						DrawLine(130-2,690-i*55,113+408,690-i*55,2,colors[BLACK]);
						DrawString(440,650-i*55," View ",colors[GOLD]);
					}
					DisplayScores();
					DisplayHighDetail();
					glutPostRedisplay();
				}
			}
		static void DisplayHighDetail()
		{
			if(Nodeid!=-1){
			DrawString(130,640-10*55+30,"Details Of Player",colors[STEEL_BLUE]);
			DrawString(130,640-10*55,"Player Name : "+ListName[Nodeid-1],colors[BLACK]);
			DrawString(130,640-10*55-30,"Player Score : "+Num2Str(MAXList[Nodeid-1]),colors[BLACK]);
			DrawString(130,640-10*55-60,"Player Score : "+Num2Str(MAXLevel[Nodeid-1]),colors[BLACK]);
			}
		}
		static void HighInput(char key)
		{
			if((getHighScoreCheck()))
			{
				if(Nodeid==-1){
				if(key=='8')
				{
					Nodeid = 8;
				}
				if(key=='1')
				{
					Nodeid = 1;
				}
				if(key=='3')
				{
					Nodeid = 3;
				}
				if(key=='4')
				{
					Nodeid = 4;
				}
				if(key=='5')
				{
					Nodeid = 5;
				}
				if(key=='6')
				{
					Nodeid = 6;
				}
				if(key=='7')
				{
					Nodeid = 7;
				}
				if(key=='2')
				{
					Nodeid = 2;
				}}
				else if(key==8)
				{
					Nodeid=-1;
				}
			}
		}
		static bool NodeCheck()
		{
			if(Nodeid!=-1)
			return false;
			else 
			return true;
			
		}
		static bool getHighScoreCheck()
		{
			return HighScoreCheck;
		}
		static void setHighScoreCheck(bool a)
		{
			HighScoreCheck = a;
		}
		void WriteScore(string N,int S)
		{
			cout<<"Writting Scores in File"<<endl;
		}
		void ReadScore()
		{
			cout<<"Read Scores from File"<<endl;
		}
};
class Levels:public MainMenu
{
	public:
	char LevelSelect;
	static int LevelFound;
	static bool LevelCheck;
		Levels()
		{
			LevelSelect = -1;
		}
		virtual void Display()
		{
				if(getLevelCheck()){
				DrawRoundRect(219,765-1,180+2,49,colors[BLACK],5);
				DrawRoundRect(221,765,180,45,colors[SKY_BLUE],5);
				DrawRoundRect(348+40+2,128+30-1,180+2-50,49,colors[BLACK],5);
				DrawRoundRect(350+40+2,128+30,180-50,45,colors[SKY_BLUE],5);
				DrawString(250,780,"Levels", colors[BLACK]);
				DrawString(350+40+2+29,128+30+15,"Back", colors[BLACK]);
				DrawRectangle(120+5-1,40+200-1,400+2,700-200+3,colors[BLACK]);
				DrawRectangle(120+5,40+200,400,700-200,colors[SKY_BLUE]);
				DrawRectangle(120+2+5,40+2+200,400-4,700-4-200,colors[BLACK]);
				DrawRectangle(120+2+5+2,40+2+2+200,400-4-4,700-4-4-200,colors[SKY_BLUE]);
					for(int i=0;i<4;i++)
					DrawString(200,700-i*50,Num2Str(i+1)+"- Level "+Num2Str(i+1),colors[BLACK]);
				}
		}
		static bool getLevelCheck()
		{
			return LevelCheck;
		}
		static void setLevelCheck(bool a)
		{
			LevelCheck = a;
		}
		int getLevelSelect()const
		{
			return LevelSelect;
		}
		void setLevelSelect(int a)
		{
			LevelSelect = a;
		}
};
			int Levels::LevelFound = -1;
			int *HighScore::MAXList = NULL;
			string *HighScore::ListName = NULL;
			int HighScore::ScoreStore = -1;
			int *HighScore::MAXLevel = NULL;
			int HighScore::ListCount = 0;
			int HighScore::Nodeid = -1;
			bool MainMenu::MenuCheck=true;
			bool NewGame::NewCheck = false;
			bool HelpCentre::HelpCheck = false;
		
			bool Levels::LevelCheck = false;
			bool Settings::SettingCheck = false;
			bool Continue::ContinueCheck = false;
			bool HighScore::HighScoreCheck = false;
			bool Exit::ExitCheck = false;
			bool PauseMenu::PauseCheck = false;	

#endif//TERMINATE _MENU_H_
