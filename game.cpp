//============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include "Shape.cpp"
#include "Game.cpp"
#include "MenuEvents.cpp"
#include "Engine.cpp"
#include <iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<fstream>
#include<cstdlib>
#include<sstream>
using namespace std;


void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
void GameDisplay()
{
	
	glClearColor(0.529, 0.808,0.92, 0.2 );
	glClear (GL_COLOR_BUFFER_BIT);  
	static GameEngine Bejeweled;
	Bejeweled.BUILD_WALLS();
	//Bejeweled.RUN_BOARD();
	Bejeweled.RUN_GAME();
	Bejeweled.MENU_MODE();
	Game::DisplayAxp();
	//GameTimer(10,200,650);*/
	//renderBitmapString(200,300,const char *string)
	glutSwapBuffers(); 

}
void NonPrintableKeys(int key, int x, int y) {
	if (key== GLUT_KEY_LEFT) 
	{
		
	} 
	else if (key== GLUT_KEY_RIGHT) 
	{

	}
	 else if (key== GLUT_KEY_UP)
	{

	}

	else if (key== GLUT_KEY_DOWN)
	{

	}

	glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y) 
{
	GameEngine::MenuManipulator(x,y,key);
	HighScore::HighInput(key);
	glutPostRedisplay();
}

void Timer(int m) 
{
	GameEngine::RefereshSystem();
	glutPostRedisplay();
	glutTimerFunc(1.0, Timer, 0);
}


void MousePressedAndMoved(int x, int y) {
	
	cout << x << " " << 800-y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	
	glutPostRedisplay();
}
void MouseClicked(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON) 
     {	
		 
	GameEngine::SwapManipulator(x,y,state);
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

     } 
    else if (button == GLUT_RIGHT_BUTTON)
     {
		cout<<"Right Button Pressed"<<endl;

     }
	glutPostRedisplay();
}
int main(int argc, char*argv[])
{
	int width = 645, height = 830;

	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
	glutInitWindowPosition(50, 50); 
	glutInitWindowSize(width, height);
	glutCreateWindow("Bejeweled 3");
	SetCanvasSize(width, height); 


	glutDisplayFunc(GameDisplay);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);
	glutMotionFunc(MousePressedAndMoved);

	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
