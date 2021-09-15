#ifndef _PERSON_H_
#define _PERSON_H_
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Player
{
	string PName;
	int Score;
	public:
	Player()
	{
		PName = " ";
		Score = 0;
	}
	string getName()const
	{
		return PName;
	}
	int getScore()const
	{
		return Score;
	}
	void setName(string a)
	{
		PName = a;
	}
	void setScore(int a)
	{
		Score = a;
	}
	void setPlayer(string id,int s)
	{
		PName = id;
		Score = s;
	}	
};


#endif//Terminate _PERSON_H_
