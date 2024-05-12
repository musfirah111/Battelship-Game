//============================================================================
// Name        : Musfirah Zunnoon
// Author      : FAST SE Department
//  Roll No    :  22i2692
// Description : Basic 2D game of Battleship.
//============================================================================

#ifndef Battleship_CPP_
#define Battleship_CPP_
#include "util.h"
#include <iostream>
#include<iomanip>
#include<string>
#include <cstring>
#include <fstream>
#include<cmath> 
#include <cstdlib>
#include <ctime>
using namespace std;

int ship1x = 920,  ship1y = 200;             // storing window position of ship1 
int ship2x = 840,  ship2y = 200;		  // storing window position of ship2 
int ship3x = 760,  ship3y = 200;	        // storing window position of ship3
int ship4x = 680,  ship4y = 200;		  // storing window position of ship4 
int ship5x = 840,  ship5y = 280;             // storing window position of ship5 
int ship6x = 720,  ship6y = 280;             // storing window position of ship6 
int ship7x = 600,  ship7y = 280;             // storing window position of ship7 
int ship8x = 840,  ship8y = 360;             // storing window position of ship8 
int ship9x = 680,  ship9y = 360;             // storing window position of ship9 
int ship10x = 760,  ship10y = 440;         // storing window position of ship10 
bool ship1 = false, ship2 = false, ship3 = false, ship4 = false, ship5 = false, ship6 = false, ship7 = false, ship8 = false, ship9 = false, ship10 = false;
bool Player1 = false,   Player2 = false;    // for buttons of player 1 and 2

int PosArray[10][2];      // for storing terminal positions of ships
int C_hit = 0;                 // for counting hits on computer grid by user
int hit_exit = 0;             // for counting hits on user grid by computer
int scores = 0;              // for showing scores
int Balance = 500;

void unitBox(int x, int y)       // making lines for main grid
{
	glBegin (GL_LINES);
	glLineWidth(1.0);
	glColor3f(0.7,  0.7, 1.0);
	    glVertex3f (x, 0.0,  0.0);
	    glVertex3f (x,  780.0,  0.0);
	    glVertex3f (0.0 , y, 0.0);
	    glVertex3f (1120.0,  y , 0.0);
	glEnd ();
}

void ShowGrid()                   // printing lines for main grid
{
	for (float x=0; x < 1120.0; x += 40.0)
	{
		
		for ( float y=0; y < 780.0;  y += 40.0)
		{
		 	unitBox (x, y);
		 }
	}
}

void  shipgrid()                              // printing user grid
{
	int x=40, y=40, h=200;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<5; j++)
		{
			DrawSquare(y, h, 40, colors[LIME_GREEN]);
			DrawSquare(40+x, h, 40, colors[LIME_GREEN]);
			x +=80;
			y +=80;
		}
	x = 40;
	y = 40;
	h= h + 40;
	}
}

void alphabets()            // for showing alphabets alonside the user grid
{
	DrawString( 10, 570, "A", colors[BLACK]);
	DrawString( 10, 530, "B", colors[BLACK]);
	DrawString( 10, 490, "C", colors[BLACK]);
	DrawString( 10, 450, "D", colors[BLACK]);
	DrawString( 10, 410, "E", colors[BLACK]);
	DrawString( 10, 370, "F", colors[BLACK]);
	DrawString( 10, 330, "G", colors[BLACK]);
	DrawString( 10, 290, "H", colors[BLACK]);
	DrawString( 10, 250, "I", colors[BLACK]);
	DrawString( 10, 210, "J", colors[BLACK]);
}

void counting()           // for showing counting alonside the user grid
{
	DrawString( 50, 610, "1", colors[BLACK]);
	DrawString( 90, 610, "2", colors[BLACK]);
	DrawString( 130, 610, "3", colors[BLACK]);
	DrawString( 170, 610, "4", colors[BLACK]);
	DrawString( 210, 610, "5", colors[BLACK]);
	DrawString( 250, 610, "6", colors[BLACK]);
	DrawString( 290, 610, "7", colors[BLACK]);
	DrawString( 330, 610, "8", colors[BLACK]);
	DrawString( 370, 610, "9", colors[BLACK]);
	DrawString( 410, 610, "10", colors[BLACK]);
}

void battelships()       // for placing battelships on the grid
{
	// battelships of size 1
	DrawRoundRect(ship1x,ship1y,40,40,colors[INDIAN_RED],10);   //920, 200
	DrawRoundRect(ship2x,ship2y,40,40,colors[INDIAN_RED],10);   //840, 200
	DrawRoundRect(ship3x,ship3y,40,40,colors[INDIAN_RED],10);   //760, 200
	DrawRoundRect(ship4x,ship4y,40,40,colors[INDIAN_RED],10);   // 680, 200
	
	// battelships of size 2
	DrawRoundRect(ship5x,ship5y,80,40,colors[INDIAN_RED],10);    //840, 280
	DrawRoundRect(ship6x,ship6y,80,40,colors[INDIAN_RED],10);    //720. 280
	DrawRoundRect(ship7x,ship7y,80,40,colors[INDIAN_RED],10);    // 600, 280
	
	// battelships of size 3
	DrawRoundRect(ship8x,ship8y,120,40,colors[INDIAN_RED],10);  // 840, 360
	DrawRoundRect(ship9x,ship9y,120,40,colors[INDIAN_RED],10);  // 680, 360
	
	//battelship of size 4
	DrawRoundRect(ship10x,ship10y,160,40,colors[INDIAN_RED],10);  // 760, 440
}

int mins = 0;    // for timmer display
int secs = 0;      // for timmer display

void  randomizedship1()           // for auto placement of ships (auto1)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);     
	 
	ShowGrid();     // calling the main grid
	
	DrawRoundRect(40,720,160,40,colors[YELLOW],10);               // for printing column of score
	DrawString( 70, 730, " Scores:	" + to_string(scores), colors[BLACK]);
	DrawRoundRect(350,720,260,40,colors[YELLOW],10);            // for printing column of account balance
	DrawString( 360, 730, "Account Balance = 500", colors[BLACK]);

	DrawRoundRect(740,680,260,60,colors[AQUA],20);       // for showing timmer
	DrawCircle(780,710,15,colors[BLUE_VIOLET]);
	DrawCircle(780,710,8,colors[MISTY_ROSE]);
	DrawString(810, 700, to_string(mins) + "   Min" + "  :  " + to_string(secs) + "   Sec", colors[BLUE_VIOLET]);
	
	shipgrid();          // calling the user grid function
	alphabets();        // calling the alphabets function
	counting();         // calling counting function
	
	// battelships of size 1
	DrawRoundRect(160,520,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(160,360,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(200,280,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(360,320,40,40,colors[INDIAN_RED],10);   
	
	// battelships of size 2
	DrawRoundRect(320,560,80,40,colors[INDIAN_RED],10);   
	DrawRoundRect(40,320,80,40,colors[INDIAN_RED],10);   
	DrawRoundRect(120,200,40,80,colors[INDIAN_RED],10);    
	
	// battelships of size 3
	DrawRoundRect(240,440,40,120,colors[INDIAN_RED],10);  
	DrawRoundRect(320,240,120,40,colors[INDIAN_RED],10);  
	
	//battelship of size 4
	DrawRoundRect(80,440,40,160,colors[INDIAN_RED],10);  
	
	DrawRoundRect(960,40,120,40,colors[BLUE_VIOLET],10);         // for printing button of battle
	DrawString( 970, 50, "BATTLE", colors[WHITE]);

	DrawRoundRect(60,40,100,60,colors[BLUE_VIOLET],10);             // for printing button of  auto
	DrawString( 75, 60, "AUTO", colors[WHITE]);

	DrawRoundRect(160,120,160,40,colors[AQUA],10);                      // for printing button of  player1
	DrawString( 180, 130, "PLAYER  1", colors[BLACK]);
	
	DrawRoundRect(800,120,160,40,colors[AQUA],10);                      // for printing button of  player2
	DrawString( 820, 130, "PLAYER  2", colors[BLACK]);
	
	glutSwapBuffers(); 
	
}

void  randomizedship2()			// for auto placement of ships (auto2)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);     
	 
	ShowGrid();            // calling the main grid
	
	DrawRoundRect(40,720,160,40,colors[YELLOW],10);             // for printing column of score
	DrawString( 70, 730, " Scores:	" + to_string(scores), colors[BLACK]);
	DrawRoundRect(350,720,260,40,colors[YELLOW],10);            // for printing column of account balance
	DrawString( 360, 730, "Account Balance = 500", colors[BLACK]);

	DrawRoundRect(740,680,260,60,colors[AQUA],20);                // for showing timmer
	DrawCircle(780,710,15,colors[BLUE_VIOLET]);
	DrawCircle(780,710,8,colors[MISTY_ROSE]);
	DrawString(810, 700, to_string(mins) + "   Min" + "  :  " + to_string(secs) + "   Sec", colors[BLUE_VIOLET]);
	
	shipgrid();          // calling the user grid function
	alphabets();        // calling the alphabets function
	counting();         // calling counting function
	
	// battelships of size 1
	DrawRoundRect(280,560,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(360,480,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(40,400,40,40,colors[INDIAN_RED],10);   
	DrawRoundRect(200,320,40,40,colors[INDIAN_RED],10);   
	
	// battelships of size 2
	DrawRoundRect(160,400,40,80,colors[INDIAN_RED],10);   
	DrawRoundRect(360,280,40,80,colors[INDIAN_RED],10);   
	DrawRoundRect(200,200,80,40,colors[INDIAN_RED],10);    
	
	// battelships of size 3
	DrawRoundRect(80,200,40,120,colors[INDIAN_RED],10);  
	DrawRoundRect(40,520,120,40,colors[INDIAN_RED],10);  
	
	//battelship of size 4
	DrawRoundRect(280,400,160,40,colors[INDIAN_RED],10);  
	
	DrawRoundRect(960,40,120,40,colors[BLUE_VIOLET],10);         // for printing button of battle
	DrawString( 970, 50, "BATTLE", colors[WHITE]);

	DrawRoundRect(60,40,100,60,colors[BLUE_VIOLET],10);            // for printing button of  auto
	DrawString( 75, 60, "AUTO", colors[WHITE]);

	DrawRoundRect(160,120,160,40,colors[AQUA],10);                      // for printing button of  player1
	DrawString( 180, 130, "PLAYER  1", colors[BLACK]);
	
	DrawRoundRect(800,120,160,40,colors[AQUA],10);                       // for printing button of  player2
	DrawString( 820, 130, "PLAYER  2", colors[BLACK]);
	
	glutSwapBuffers(); 
	
}


void compgrid()                                    // second grid for computer
{
	int x=680, y=680, h=200;
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<5; j++)
		{
			DrawSquare(y, h, 40, colors[LIGHT_PINK]);
			DrawSquare(40+x, h, 40, colors[LIGHT_PINK]);
			x +=80;
			y +=80;
		}
	x = 680;
	y = 680;
	h= h + 40;
	}
	
	// for printing alphabets alonside the computer grid
	DrawString( 1090, 570, "A", colors[BLACK]);
	DrawString( 1090, 530, "B", colors[BLACK]);
	DrawString( 1090, 490, "C", colors[BLACK]);
	DrawString( 1090, 450, "D", colors[BLACK]);
	DrawString( 1090, 410, "E", colors[BLACK]);
	DrawString( 1090, 370, "F", colors[BLACK]);
	DrawString( 1090, 330, "G", colors[BLACK]);
	DrawString( 1090, 290, "H", colors[BLACK]);
	DrawString( 1090, 250, "I", colors[BLACK]);
	DrawString( 1090, 210, "J", colors[BLACK]);
	
	// for printing counting alonside the computer grid
	DrawString( 690, 610, "1", colors[BLACK]);
	DrawString( 730, 610, "2", colors[BLACK]);
	DrawString( 770, 610, "3", colors[BLACK]);
	DrawString( 810, 610, "4", colors[BLACK]);
	DrawString( 850, 610, "5", colors[BLACK]);
	DrawString( 890, 610, "6", colors[BLACK]);
	DrawString( 930, 610, "7", colors[BLACK]);
	DrawString( 970, 610, "8", colors[BLACK]);
	DrawString( 1010, 610, "9", colors[BLACK]);
	DrawString( 1050, 610, "10", colors[BLACK]);
	
	glutSwapBuffers(); 
	
}

void miss()        // print B if shot is unsuccessful for hitting the ship
{
	DrawString( 870, 390, "B", colors[BLACK]);
	DrawLine( 690 , 400 ,  1050 , 400 , 1 , colors[BLACK] );
	DrawLine( 880 , 570 ,  880 , 210 , 1 , colors[BLACK] );
	glutSwapBuffers(); 
}
void SetCanvasSize(int width, int height) {          //Function sets canvas size (drawing area) in pixels...
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);                     // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

void screen_1()         //printing main screen
{
	glClearColor(0.7, 1.0, 0.7, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);         //Update the colors
	
	DrawString( 450, 550, "SEA   BATTELSHIP  2", colors[DARK_RED]);
	DrawLine( 300 , 500 ,  850 , 500 , 1 , colors[DARK_RED] );
	DrawString( 480, 400, "CLASSIC   MODE", colors[BLACK]);
	DrawString( 460, 340, "BLACK  HARBOUR", colors[BLACK]);
	glutSwapBuffers(); 
}

void screen_2()        // printing menu screen
{
	glClearColor(1.0, 1.0, 1.0, 1.0);             
	glClear (GL_COLOR_BUFFER_BIT);      //Update the colors
	
	ShowGrid();
	DrawString( 540, 690, "MENU", colors[CRIMSON]);
	DrawLine( 300 , 640 ,  850 , 640 , 1 , colors[DARK_RED] );
	DrawString( 500, 570, "1. Leader Board", colors[DARK_MAGENTA]);
	DrawString( 500, 490, "2. Start  New Game", colors[DARK_MAGENTA]);
	DrawString( 500, 410, "3. View Balance", colors[DARK_MAGENTA]);
	DrawString( 500, 330, "4. Options", colors[DARK_MAGENTA]);
	DrawString( 490, 250, "Esc. End the game", colors[DARK_MAGENTA]);
	
	glutSwapBuffers(); 
}

void playGame()     // printing instructions screen
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);
	DrawString( 380, 700, "WELCOME!!	MUSFIRAH    ZUNNOON", colors[DARK_MAGENTA]);
	DrawString( 300, 620, "INSTRUCTIONS:", colors[BLACK]);
	DrawString( 200, 570, "1.  Place the battleships in the grid with distance of one block", colors[BLACK]);
	DrawString( 200, 540, "2.  Play the Auto button for random placement of ships ", colors[BLACK]);
	DrawString( 200, 510, "3.  Play the battle button for showing of computer grid ", colors[BLACK]);
	DrawString( 200, 480, "4.  Hit on the computer grid for hitting the battelships ", colors[BLACK]);
	DrawString( 200, 450, "5.  For each successive hit you will eran 60 points ", colors[BLACK]);
	DrawString( 200, 420, "6.  Again take the turn if you hit the battelship", colors[BLACK]);
	
	DrawRoundRect(500,40,100,60,colors[BLUE_VIOLET],10);  
	DrawString( 518, 60, "PLAY", colors[WHITE]);
	glutSwapBuffers(); 
}

void LeaderBoard()       // making leaderboard using file handling
{
	ofstream board;            // for writing  in file
	ifstream file;                  // for reading a file
	board.open("Leaderboard.txt");
	board << setw(11) <<" NAMES " <<setw(50) <<"Scores" <<endl;
	board << setw(10) <<" 1. Musfirah Zunnoon " <<setw(36) <<scores <<endl;
	
	int scoreArray[10];          // initializing array of size 10
	if(true)
	{
		for(int i =0; i<10; i++)
		{
			board << scoreArray[i]<<endl;
		}
	}
	board.close();
	
	ifstream nfile;
	nfile.open("Leaderboard.txt");

	string show;
	while(!nfile.eof())          // reading name
	{
		getline(nfile, show);
		cout << show << endl;
	}
	nfile.close();
	
	board.open("Leaderboard.txt");
	if(true)          // for storing scores in array
	{
		for(int j = score; j<1800; j++
		{
			board << scoreArray[j]<<endl;
		} 
	}
	board.close();
	
	glClearColor(1.0, 1.0, 1.0, 1.0);             
	glClear (GL_COLOR_BUFFER_BIT);      
	
	DrawString( 500, 700, " LEADER BOARD", colors[INDIAN_RED]);
	DrawLine( 300 , 660 ,  850 , 660 , 1 , colors[DARK_RED] );
	DrawString( 100, 500, " Names", colors[BLACK]);
	DrawString( 400, 500, " Scores", colors[BLACK]);
	DrawString( 100, 460, "1. Musfirah Zunnoon", colors[BLACK]);
	DrawString( 400, 460, "1025", colors[BLACK]);
	glutSwapBuffers(); 
}

void Account()                     // showing account balance
{
	glClearColor(1.0, 1.0, 1.0, 1.0);             
	glClear (GL_COLOR_BUFFER_BIT);      
	DrawString( 500, 700, " ACCOUNT BALANCE", colors[INDIAN_RED]);
	DrawLine( 300 , 660 ,  850 , 660 , 1 , colors[DARK_RED] );
	DrawString( 100, 600, " Current  =  500", colors[BLACK]);
	glutSwapBuffers(); 
}

void Options()                    // showing options of colours and ships
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);      
	DrawString( 500, 700, " OPTIONS", colors[INDIAN_RED]);
	DrawLine( 300 , 680 ,  850 , 680 , 1 , colors[DARK_RED] );
	DrawRoundRect(200,600,120,40,colors[INDIAN_RED],10);  
	DrawRoundRect(200,500,120,40,colors[DARK_GREEN],10);  
	DrawRoundRect(200,400,120,40,colors[DARK_VIOLET],10);  
	
	DrawSquare(420, 600, 40, colors[INDIAN_RED]);
	DrawSquare(420, 500, 40, colors[DARK_GREEN]);
	DrawSquare(420, 400, 40, colors[DARK_VIOLET]);
	
	DrawCircle(600,620,25,colors[INDIAN_RED]);
	DrawCircle(600,520,25,colors[DARK_GREEN]);
	DrawCircle(600,420,25,colors[DARK_VIOLET]);
	
	glutSwapBuffers(); 
}

void  LastDisplay()        // printing last screen
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);      
	DrawString( 500, 700, "GAME  END", colors[INDIAN_RED]);
	DrawLine( 300 , 660 ,  850 , 660 , 1 , colors[DARK_RED] );
	DrawString( 260, 500, "Congratulation!!  You have won the game", colors[BLACK]);
	DrawString( 260, 420, " Scores:	" + to_string(scores/2) , colors[BLACK]);
	DrawString( 260, 340, " Account Balance:	" + to_string((scores/2) +500) , colors[BLACK]);
	glutSwapBuffers(); 
}

void C_ship_1()             // for printing X when ship1 of computer hit  
{
	DrawString( 730, 530, "X", colors[DARK_RED]);
	glutPostRedisplay();
	glutSwapBuffers(); 
}

void C_ship_2()			// for printing X when ship2 of computer hit 
{
	DrawString( 1010, 490, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_3()			// for printing X when ship3 of computer hit 
{
	DrawString( 850, 370, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_4()			// for printing X when ship4 of computer hit 
{
	DrawString( 930, 210, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_5a()			// for printing first X when ship5 of computer hit 
{
	DrawString( 850, 490, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_5b()			// for printing second X when ship5 of computer hit 
{
	DrawString( 850, 450, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_6a()			// for printing first X when ship6 of computer hit 
{
	DrawString( 730, 370, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_6b()			// for printing second X when ship6 of computer hit 
{
	DrawString( 730, 330, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_7a()			// for printing first X when ship7 of computer hit 
{
	DrawString( 930, 290, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_7b()			// for printing second X when ship7 of computer hit 
{
	DrawString( 970, 290, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_8a()			// for printing first X when ship8 of computer hit 
{
	DrawString( 810, 570, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_8b()			// for printing second X when ship8 of computer hit 
{
	DrawString( 850, 570, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_8c()			// for printing  third X when ship8 of computer hit 
{
	DrawString( 890, 570, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_9a()			// for printing first X when ship9 of computer hit
{
	DrawString( 1050, 290, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_9b()			// for printing second X when ship9 of computer hit 
{
	DrawString( 1050, 250, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_9c()			// for printing  third X when ship9 of computer hit
{
	DrawString( 1050, 210, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_10a()		// for printing first X when ship10 of computer hit
{
	DrawString( 690, 250, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_10b()		// for printing second X when ship10 of computer hit 
{
	DrawString( 730, 250, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_10c()		// for printing  third X when ship10 of computer hit
{
	DrawString( 770, 250, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void C_ship_10d()		// for printing  forth X when ship10 of computer hit
{
	DrawString( 810, 250, "X", colors[DARK_RED]);
	glutSwapBuffers(); 
}

void occupied1()          // for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 690, 570, "b", colors[DARK_BLUE]);
	DrawString( 730, 570, "b", colors[DARK_BLUE]);
	DrawString( 770, 570, "b", colors[DARK_BLUE]);
	DrawString( 690, 530, "b", colors[DARK_BLUE]);
	DrawString( 690, 490, "b", colors[DARK_BLUE]);
	DrawString( 730, 490, "b", colors[DARK_BLUE]);
	DrawString( 770, 490, "b", colors[DARK_BLUE]);
	DrawString( 770, 530, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied2()		// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 770, 570, "b", colors[DARK_BLUE]);
	DrawString( 770, 530, "b", colors[DARK_BLUE]);
	DrawString( 810, 530, "b", colors[DARK_BLUE]);
	DrawString( 850, 530, "b", colors[DARK_BLUE]);
	DrawString( 890, 530, "b", colors[DARK_BLUE]);
	DrawString( 930, 530, "b", colors[DARK_BLUE]);
	DrawString( 930, 570, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied3()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 810, 530, "b", colors[DARK_BLUE]);
	DrawString( 850, 530, "b", colors[DARK_BLUE]);
	DrawString( 890, 530, "b", colors[DARK_BLUE]);
	DrawString( 890, 490, "b", colors[DARK_BLUE]);
	DrawString( 890, 450, "b", colors[DARK_BLUE]);
	DrawString( 890, 410, "b", colors[DARK_BLUE]);
	DrawString( 850, 410, "b", colors[DARK_BLUE]);
	DrawString( 810, 410, "b", colors[DARK_BLUE]);
	DrawString( 810, 450, "b", colors[DARK_BLUE]);
	DrawString( 810, 490, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied4()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 970, 530, "b", colors[DARK_BLUE]);
	DrawString( 1010, 530, "b", colors[DARK_BLUE]);
	DrawString( 1050, 530, "b", colors[DARK_BLUE]);	
	DrawString( 1050, 490, "b", colors[DARK_BLUE]);
	DrawString( 1050, 450, "b", colors[DARK_BLUE]);
	DrawString( 1010, 450, "b", colors[DARK_BLUE]);
	DrawString( 970, 450, "b", colors[DARK_BLUE]);
	DrawString( 970, 490, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied5()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 690, 410, "b", colors[DARK_BLUE]);
	DrawString( 730, 410, "b", colors[DARK_BLUE]);
	DrawString( 770, 410, "b", colors[DARK_BLUE]);	
	DrawString( 770, 370, "b", colors[DARK_BLUE]);
	DrawString( 770, 330, "b", colors[DARK_BLUE]);
	DrawString( 770, 290, "b", colors[DARK_BLUE]);	
	DrawString( 730, 290, "b", colors[DARK_BLUE]);
	DrawString( 690, 290, "b", colors[DARK_BLUE]);
	DrawString( 690, 330, "b", colors[DARK_BLUE]);
	DrawString( 690, 370, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied6()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 810, 410, "b", colors[DARK_BLUE]);
	DrawString( 850, 410, "b", colors[DARK_BLUE]);
	DrawString( 890, 410, "b", colors[DARK_BLUE]);	
	DrawString( 890, 370, "b", colors[DARK_BLUE]);
	DrawString( 890, 330, "b", colors[DARK_BLUE]);
	DrawString( 850, 330, "b", colors[DARK_BLUE]);	
	DrawString( 810, 330, "b", colors[DARK_BLUE]);	
	DrawString( 810, 370, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied7()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 890, 330, "b", colors[DARK_BLUE]);
	DrawString( 930, 330, "b", colors[DARK_BLUE]);
	DrawString( 970, 330, "b", colors[DARK_BLUE]);	
	DrawString( 1010, 330, "b", colors[DARK_BLUE]);
	DrawString( 1010, 290, "b", colors[DARK_BLUE]);
	DrawString( 1010, 250, "b", colors[DARK_BLUE]);		
	DrawString( 970, 250, "b", colors[DARK_BLUE]);	
	DrawString( 930, 250, "b", colors[DARK_BLUE]);
	DrawString( 890, 250, "b", colors[DARK_BLUE]);	
	DrawString( 890, 290, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied8()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 1010, 330, "b", colors[DARK_BLUE]);
	DrawString( 1050, 330, "b", colors[DARK_BLUE]);
	DrawString( 1010, 290, "b", colors[DARK_BLUE]);	
	DrawString( 1010, 250, "b", colors[DARK_BLUE]);
	DrawString( 1010, 210, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied9()			// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 890, 210, "b", colors[DARK_BLUE]);
	DrawString( 890, 250, "b", colors[DARK_BLUE]);
	DrawString( 930, 250, "b", colors[DARK_BLUE]);	
	DrawString( 970, 250, "b", colors[DARK_BLUE]);
	DrawString( 970, 210, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void occupied10()		// for printing b's on the boundaries of X  when last hit strike
{
	DrawString( 690, 290, "b", colors[DARK_BLUE]);
	DrawString( 730, 290, "b", colors[DARK_BLUE]);
	DrawString( 770, 290, "b", colors[DARK_BLUE]);	
	DrawString( 810, 290, "b", colors[DARK_BLUE]);
	DrawString( 850, 290, "b", colors[DARK_BLUE]);
	DrawString( 850, 250, "b", colors[DARK_BLUE]);
	DrawString( 850, 210, "b", colors[DARK_BLUE]);
	DrawString( 810, 210, "b", colors[DARK_BLUE]);	
	DrawString( 770, 210, "b", colors[DARK_BLUE]);
	DrawString( 730, 210, "b", colors[DARK_BLUE]);
	DrawString( 690, 210, "b", colors[DARK_BLUE]);
	glutSwapBuffers(); 
}

void tri1()		// for printing triangle for user turn
{
	DrawTriangle( 560, 760 , 560, 680 , 480 , 720, colors[DARK_RED] ); 
	glutSwapBuffers(); 
}

void tri2()		// for printing triangle for computer turn
{
	DrawTriangle( 480, 800 , 480, 680 , 560 , 720, colors[DARK_RED] ); 
	glutSwapBuffers(); 
}

void GameDisplay()      // main game window
{
	glClearColor(1.0, 1.0, 1.0, 1.0);              
	glClear (GL_COLOR_BUFFER_BIT);     
	 
	ShowGrid();
	
	DrawRoundRect(40,720,160,40,colors[YELLOW],10);  
	DrawString( 70, 730, " Scores:	" + to_string(scores), colors[BLACK]);
	DrawRoundRect(350,720,260,40,colors[YELLOW],10);  
	DrawString( 360, 730, "Account Balance = 500", colors[BLACK]);

	DrawRoundRect(740,680,260,60,colors[AQUA],20);  
	DrawCircle(780,710,15,colors[BLUE_VIOLET]);
	DrawCircle(780,710,8,colors[MISTY_ROSE]);
	DrawString(810, 700, to_string(mins) + "   Min" + "  :  " + to_string(secs) + "   Sec", colors[BLUE_VIOLET]);
	
	shipgrid();
	alphabets();
	counting();
	battelships();
	
	DrawRoundRect(960,40,120,40,colors[BLUE_VIOLET],10);  
	DrawString( 970, 50, "BATTLE", colors[WHITE]);

	DrawRoundRect(60,40,100,60,colors[BLUE_VIOLET],10);  
	DrawString( 75, 60, "AUTO", colors[WHITE]);

	DrawRoundRect(160,120,160,40,colors[AQUA],10);  
	DrawString( 180, 130, "PLAYER  1", colors[BLACK]);
	
	DrawRoundRect(800,120,160,40,colors[AQUA],10);  
	DrawString( 820, 130, "PLAYER  2", colors[BLACK]);
	
	
	//DrawSquare(400, 40, 180, colors[RED]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 400, 550 , 440, 550 , 420 , 590, colors[DARK_RED] ); 
	
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	/*DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	
	
	DrawCircle(50,670,10,colors[RED]);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);*/
	
	glutSwapBuffers(); 
}

/*void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT ) {
		xI -= 10;
	} else if (key	== GLUT_KEY_RIGHT ) {
		xI += 10;
	} else if (key == GLUT_KEY_UP) {
		yI += 10;
	}
	else if (key == GLUT_KEY_DOWN) {
		yI -= 10;
	}
	glutPostRedisplay();

}*/

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27) 
	{
		exit(1);  			                     	// exit the program when escape key is pressed.
	}
	if (key == 's' || key == 'S')                          //Key for second page of game
			{
				glutDisplayFunc (screen_2);	
			}
	if (key == '1')                         //Key to show leaderboard
			{
				glutDisplayFunc (LeaderBoard);	
			}
	if (key == '2')                          //Key for start game
			{
				glutDisplayFunc ( playGame);	
				string name;
				cout <<"enter your name"<<endl;
				cin.ignore();
				getline(cin, name);
			}
	if (key == '3')                          //Key for showing balance
			{
				glutDisplayFunc ( Account);	
			}
	if (key == '4')                          //Key for showing  options
			{
				glutDisplayFunc (Options);	
			}
	if (key == GL_RETURN)                          //Key for instructions page
			{
				glutDisplayFunc (playGame);	
			}
	glutPostRedisplay();
	
}

void Timer(int m) {              // for controlling speed of different objects

	
	glutTimerFunc(100, Timer, 0);
}

void Counter(int x)            // for showing timmer 
{
        secs++;
        if(secs == 60)
        {
        	mins++;
        	secs = 0;
        }
        
        glutTimerFunc(100, Counter, 0);
}
        
void MousePressedAndMoved(int x, int y) 
{
	// storing mouse position in ships for moving them
	if(ship1 == true)        
	{
		ship1x = x;
		ship1y = 780-y;
		
	}
	 if(ship2 == true)
	{
		ship2x = x;
		ship2y = 780-y;
		
	}
	if(ship3 == true)
	{
		ship3x = x;
		ship3y = 780-y;
		
	}
	
	if(ship4 == true)
	{
		ship4x = x;
		ship4y = 780-y;
		
	}
	if(ship5 == true)
	{
		ship5x = x;
		ship5y = 780-y;
		
	}
	if(ship6 == true)
	{
		ship6x = x;
		ship6y = 780-y;
		
	}
	 if(ship7 == true)
	{
		ship7x = x;
		ship7y = 780-y;
		
	}
	if(ship8 == true)
	{
		ship8x = x;
		ship8y = 780-y;
		
	}
	 if(ship9 == true)
	{
		ship9x = x;
		ship9y = 780-y;
		
	}
	 if(ship10 == true)
	{
		ship10x = x;
		ship10y = 780-y;
		
	}
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON)                      
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	
	bool game = false;
	if ((button == GLUT_LEFT_BUTTON)		&&	(game  ==  false))              // clicking on play nutton for entering the game          
	{
		if((x >= 500	&&	x<= 600)		&&	(y >= 680 && y <= 740))
		{
			game = true;
			glutDisplayFunc(GameDisplay);
		}
	}
	
	if (button == GLUT_LEFT_BUTTON)                        // for fixing the location of ship1 when right button is pressed
	{
		if(( x >= 920  &&  x<= 960 )  && ( y >= 540   && y <= 580))
		{
			ship1= true;
			ship2 = false;		
			ship3 = false;
			ship4 = false;
			ship5 = false;
			ship6 = false;
			ship7 = false;
			ship8 = false;
			ship9 = false;
			ship10 = false;
			cout<<" ship1 clicked"<< endl;
		}
	}
	 if ((button == GLUT_RIGHT_BUTTON)    &&    (ship1 == true ))           // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship1x = 920;
				ship1y = 200;
				ship1 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship1 = false;
			cout<<"ship 1 placed"<<endl;
			}
			
			PosArray[0][0] = x;
			PosArray[0][1] = y ;
			cout<<"ship1x:"<<setw(5)<< PosArray[0][0] <<endl;
			cout<<"ship1y:"<<setw(5)<< PosArray[0][1] <<endl;	
		
	}
	
	if (button == GLUT_LEFT_BUTTON)                       // for fixing the location of ship2 when right button is pressed
	{
		if(( x >= 840  &&  x<= 880 )  && ( y >= 540   && y <= 580))
		{
			ship2= true;
			ship1 = false;		
			ship3 = false;
			ship4 = false;
			ship5 = false;
			ship6 = false;
			ship7 = false;
			ship8 = false;
			ship9 = false;
			ship10 = false;
			cout<<" ship2 clicked"<< endl;
		}
	}
	 if ((button == GLUT_RIGHT_BUTTON)    &&    (ship2 == true ))              // if ship place outside the grid it will move back to its origial location
	{		
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship2x = 840;
				ship2y = 200;
				ship2 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship2 = false;
			cout<<"ship 2 placed"<<endl;
			}
			PosArray[1][0] = x;
			PosArray[1][1] = y ;
			cout<<"ship2x:"<<setw(5)<< PosArray[1][0] <<endl;
			cout<<"ship2y:"<<setw(5)<< PosArray[1][1] <<endl;	
	}
	
	
	if (button == GLUT_LEFT_BUTTON)                       // for fixing the location of ship3 when right button is pressed
	{
		if(( x >= 760    &&     x<=  800  )  && (  y >= 540   &&    y<=  580   ))
		{
				ship3 = true;
				ship1 = false;
				ship2 = false;
				ship4 = false;  
				ship5 = false;  
				ship6 = false;  
				ship7 = false; 
				ship8 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 3 clicked" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON )  &&   (ship3 == true))            // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship3x = 760;
				ship3y = 200;
				ship3 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship3 = false;
			cout << "ship 3 placed" << endl;
			}
			PosArray[2][0] = x;
			PosArray[2][1] = y ;
			cout<<"ship3x:"<<setw(5)<< PosArray[2][0] <<endl;
			cout<<"ship3y:"<<setw(5)<< PosArray[2][1] <<endl;
	}


		
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship4 when right button is pressed
	{
			if(( x >=  680   &&     x<=  720)  && (  y >= 540  &&    y<= 580    ))
			{
				ship4 = true;  
				ship1 = false;  
				ship2 = false; 
				ship3 = false; 
				ship5 = false;  
				ship6 = false;  
				ship7 = false; 
				ship8 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 4 clicked" << endl;
			}
	}
	if ((button == GLUT_RIGHT_BUTTON)   &&   (ship4 == true))             // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship4x = 680;
				ship4y = 200;
				ship4 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship4 = false;
			cout<<"ship 4 placed"<<endl;
			}
		PosArray[3][0] = x;
		PosArray[3][1] = y ;
		cout<<"ship4x:"<<setw(5)<< PosArray[3][0] <<endl;
		cout<<"ship4y:"<<setw(5)<< PosArray[3][1] <<endl;
	}	
	
	
	
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship5 when right button is pressed
	{
		if(( x >=   840  &&     x<=  920  )  && (  y >= 460   &&    y<=  500   ))
		{
				ship5  = true; 
				ship1 = false;  
				ship2 = false;  
				ship4 = false; 
				ship6 = false;  
				ship7 = false;  
				ship8 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 5 clicked" << endl;	
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)   &&   (ship5 == true))            // if ship place outside the grid it will move back to its origial location 
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship5x = 840;
				ship5y = 280;
				ship5 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship5 = false;
			cout<<"ship 5 placed"<<endl;
			}
		PosArray[4][0] = ship5x;
		PosArray[4][1] = ship5y ;
		cout<<"ship5x:"<<setw(5)<< PosArray[4][0] <<endl;
		cout<<"ship5y:"<<setw(5)<< PosArray[4][1] <<endl;
	}
		
	
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship6 when right button is pressed
	{
		if(( x >= 720    &&     x<=  800  )  && (  y >=  460  &&    y<= 500    ))
		{
				ship6  = true;
				ship1 = false;  
				ship2 = false;  
				ship3 = false;  
				ship4 = false;  
				ship5 = false;  
				ship7 = false; 
				ship8 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 6 selected" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)   &&   (ship6 == true))            // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship6x = 720;
				ship6y = 280;
				ship6 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship6 = false;
			cout<<"ship 6 placed"<<endl;
			}
		PosArray[5][0] = ship6x;
		PosArray[5][1] = ship6y;
		cout<<"ship6x:"<<setw(5)<< PosArray[5][0] <<endl;
		cout<<"ship6y:"<<setw(5)<< PosArray[5][1] <<endl;	
	}
	
	
	if (button == GLUT_LEFT_BUTTON) 		// for fixing the location of ship7 when right button is pressed
	{
		if(( x >= 600  &&     x<= 680  )  && (  y >=  460  &&    y<=   500  ))
		{
				ship7  = true;
				ship1 = false;  
				ship2 = false;  
				ship3 = false;  
				ship4 = false;  
				ship5 = false;  
				ship6 = false; 
				ship8 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 7 clicked" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)  &&   (ship7 == true))             // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship7x = 600;
				ship7y = 280;
				ship7 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship7 = false;
			cout<<"ship 7 placed"<<endl;
			}
		PosArray[6][0] = ship7x;
		PosArray[6][1] = ship7y;
		cout<<"ship7x:"<<setw(5)<< PosArray[6][0] <<endl;
		cout<<"ship7y:"<<setw(5)<< PosArray[6][1] <<endl;	
	}
	
	
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship8 when right button is pressed
	{
		if(( x >= 840    &&     x<=  960  )  && (  y >=  380  &&    y<=  420 ))
		{
				ship8  = true;
				ship1 = false;  
				ship2 = false;  
				ship3 = false;  
				ship4 = false;  
				ship5 = false;  
				ship6 = false; 
				ship7 = false; 
				ship9 = false; 
				ship10 = false;
				cout << "ship 8 clicked" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)   &&   (ship8 == true))            // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship8x = 840;
				ship8y = 360;
				ship8 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship8 = false;
			cout<<"ship 8 placed"<<endl;
			}
		PosArray[7][0] = ship8x;
		PosArray[7][1] = ship8y;
		cout<<"ship8x:"<<setw(5)<< PosArray[7][0] <<endl;
		cout<<"ship8y:"<<setw(5)<< PosArray[7][1] <<endl;	
	}
	
	
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship9 when right button is pressed
	{
		if(( x >=  680  &&     x<=  800 )  && (  y >=  380  &&    y<= 420  ))
		{
				ship9  = true;
				ship1 = false;  
				ship2 = false;  
				ship3 = false;  
				ship4 = false;  
				ship5 = false;  
				ship6 = false; 
				ship7 = false; 
				ship8 = false; 
				ship10 = false;
				cout << "ship 9 clicked" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)   &&   (ship9 == true))             // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship9x = 680;
				ship9y = 360;
				ship9 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship9 = false;
			cout<<"ship 9 placed"<<endl;
			}
		PosArray[8][0] = ship9x;
		PosArray[8][1] = ship9y;
		cout<<"ship9x:"<<setw(5)<< PosArray[8][0] <<endl;
		cout<<"ship9y:"<<setw(5)<< PosArray[8][1] <<endl;	
	}
	
	
	if (button == GLUT_LEFT_BUTTON) 			// for fixing the location of ship10 when right button is pressed
	{
		if(( x >=   760  &&     x<=  920 )  && (  y >=  300  &&    y<= 340  ))
		{
				ship10 = true;
				ship1 = false;  
				ship2 = false;  
				ship3 = false;  
				ship4 = false;  
				ship5 = false;  
				ship6 = false; 
				ship7 = false; 
				ship8 = false; 
				ship9 = false;
				cout << "ship 10 clicked" << endl;
		}
	}
	if ((button == GLUT_RIGHT_BUTTON)  &&   (ship10 == true))            // if ship place outside the grid it will move back to its origial location
	{
			if(( x <= 40  ||  x >= 440)	||	(y <= 190   ||   y >= 580))
			{
				ship10x = 760;
				ship10y = 440;
				ship10 = false;
				cout<<"Oops !!"<<endl;
				glutPostRedisplay();
			}
			else
			{
			ship10 = false;
			cout<<"ship 10 placed"<<endl;
			}
		PosArray[9][0] = ship10x;
		PosArray[9][1] = ship10y;
		cout<<"ship10x:"<<setw(5)<< PosArray[9][0] <<endl;
		cout<<"ship10y:"<<setw(5)<< PosArray[9][1] <<endl;	
	}
	
	bool rship = false;
	 if ((button == GLUT_LEFT_BUTTON)     &&      ( rship  == false) )          
	{	
			if(( x >= 60 && x <= 160)  && ( y >= 680 && y <= 740)) 
			{
			rship = true;
			int s = (rand()  % 2) +1;
				switch (s)
				{
					case 1:       // if auto button is pressed one time it will call randomized1 function
					{
						glutDisplayFunc(randomizedship1);
						cout<<"randomized"<<endl;
						break;
					}
					case 2: 	  // if auto button is pressed second time it will call randomized1 function
					{
						glutDisplayFunc(randomizedship2);
						cout<<"randomized"<<endl;
						break;
					}
					default:
					{
						cout<<"no input"<<endl;
						break;
					}
				}
			}
	}
		
	
	bool click = false;
	 if ((button == GLUT_LEFT_BUTTON)     &&      ( click  == false) )          // for clicking on battle button
	{
			if(( x >= 960 && x <= 1055)  && ( y >= 700 && y <= 740)) 
			{
			click = true;
			cout<<"BATTLE"<<endl;
			glutDisplayFunc(compgrid);
			}
	}
	
	if (button == GLUT_RIGHT_BUTTON)            
	{
		if(( x >= 720    &&    x <= 760)  && (  y >= 220   &&    y <=  260))	 // print X when click on this coordinate for ship 1 of computer
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<" Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_1);    
				glutDisplayFunc(occupied1);
				    
		}
		if(( x >= 1000    &&    x <= 1040)  && (  y >= 260   &&    y <=  300))		// print X when click on this coordinate for ship 2 of computer
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_2);
				glutDisplayFunc(occupied4);
		}
		if(( x >= 840    &&    x <= 880)  && (  y >= 380   &&    y <=  420))	// print X when click on this coordinate for ship 3 of computer
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_3);
				glutDisplayFunc(occupied6);
		}
		if(( x >= 920    &&    x <= 960)  && (  y >= 540   &&    y <=  580))	 // print X when click on this coordinate for ship 4 of computer
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_4);
				glutDisplayFunc(occupied9);
		}
		if(( x >= 840    &&    x <= 880)  && (  y >= 260   &&    y <=  300))	// print X when click on this coordinate for ship 5 of computer     (First hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_5a);		
		}
		if(( x >= 840    &&    x <= 880)  && (  y >= 300   &&    y <=  340))	 // print X when click on this coordinate for ship 5 of computer     (second hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_5b);
				glutDisplayFunc(occupied3);
		}
		if(( x >= 720    &&    x <= 760)  && (  y >= 380   &&    y <=  420))	// print X when click on this coordinate for ship 6 of computer     (First hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_6a);
		}
		if(( x >= 720    &&    x <= 760)  && (  y >= 420   &&    y <=  460))	// print X when click on this coordinate for ship 6 of computer     (second hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_6b);
				glutDisplayFunc(occupied5);
		}
		if(( x >= 920    &&    x <= 960)  && (  y >= 460   &&    y <=  500))	// print X when click on this coordinate for ship 7 of computer     (First hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_7a);
		}
		if(( x >= 940    &&    x <= 1000)  && (  y >= 460   &&    y <=  500))	// print X when click on this coordinate for ship 7 of computer     (second hit )   (length of 2)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_7b);
				glutDisplayFunc(occupied7);
		}
		if(( x >= 800    &&    x <= 840)  && (  y >= 180   &&    y <=  220))		// print X when click on this coordinate for ship 8 of computer     (first hit )   (length of 3)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_8a);
		}
		if(( x >= 840    &&    x <= 880)  && (  y >= 180   &&    y <=  220))	// print X when click on this coordinate for ship 8 of computer     (second hit )   (length of 3)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_8b);
		}
		if(( x >= 880    &&    x <= 920)  && (  y >= 180   &&    y <=  220))     // print X when click on this coordinate for ship 8 of computer     (third hit )   (length of 3)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_8c);
				glutDisplayFunc(occupied2);
		}
		if(( x >= 1040    &&    x <= 1080)  && (  y >= 460   &&    y <=  500))	// print X when click on this coordinate for ship 9 of computer     (first hit )   (length of 3)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_9a);
		}
		if(( x >= 1040    &&    x <= 1080)  && (  y >= 500   &&    y <=  540))  // print X when click on this coordinate for ship 9 of computer     (second hit )   (length of 3)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_9b);
		}
		if(( x >= 1040    &&    x <= 1080)  && (  y >= 540   &&    y <=  580))  // print X when click on this coordinate for ship 9 of computer     (third hit )   (length of 3)
		{
				cout<<"Player 1 ship hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_9c);
				glutDisplayFunc(occupied8);
		}
		if(( x >= 680    &&    x <= 720)  && (  y >= 500   &&    y <=  540))	// print X when click on this coordinate for ship 10 of computer     (first hit )   (length of 4)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_10a);
		}
		if(( x >= 720    &&    x <= 760)  && (  y >= 500   &&    y <=  540))	// print X when click on this coordinate for ship 10 of computer     (second hit )   (length of 4)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_10b);
		}
		if(( x >= 760    &&    x <= 800)  && (  y >= 500   &&    y <=  540))	// print X when click on this coordinate for ship 10 of computer     (third hit )   (length of 4)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_10c);
		}
		if(( x >= 800    &&    x <= 840)  && (  y >= 500   &&    y <=  540))	 // print X when click on this coordinate for ship 10 of computer     (forth hit )   (length of 4)
		{
				cout<<"hit"<<endl;
				C_hit += 1;
				scores += 60;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores/2<<endl;
				glutDisplayFunc(C_ship_10d);
				glutDisplayFunc(occupied10);
		}
		if(C_hit == 40)
		{
			cout<<"All Ships Destryed"<<endl;
			glutDisplayFunc(LastDisplay);
		}
		else
		{
				C_hit  =  C_hit;
				scores = scores ;
				cout<<"Missed"<<endl;
				cout<<"Player 1 ship hits: "<<setw(5)<<C_hit<<endl;
				cout<<"score:"<<setw(5)<<scores<<endl;
				//miss();   // if hit is not seccesful call this function
		}
	}
	
	glutPostRedisplay();
	
	if ((button == GLUT_LEFT_BUTTON)      &&      (Player2  ==  false))            //For Player 2 turn
	{
		int  max_X =  440,   min_X =  40 ;
		int  max_Y =  580 ,  min_Y =   190;
		if(( x >= 800    &&    x <= 960)  && (  y >= 620   &&    y <=  660))
		{
				Player2 = true;
				cout<<"Player 2 turn"<<endl;
				//tri1();
				while (Player2  ==  true)
				{
					int rX  = (rand()  % (max_X  -   min_X    +  1)   +  min_X);
					int rY  = (rand()  % (max_Y  -   min_Y    +  1)    +  min_Y);
					if  ((PosArray[0][0]  ==   rX)	&&	(PosArray[0][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[1][0]  ==   rX)	&&	(PosArray[1][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[2][0]  ==   rX)	&&	(PosArray[2][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[3][0]  ==   rX)	&&	(PosArray[3][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[4][0]  ==   rX)	&&	(PosArray[4][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[5][0]  ==   rX)	&&	(PosArray[5][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[6][0]  ==   rX)	&&	(PosArray[6][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[7][0]  ==   rX)	&&	(PosArray[7][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[8][0]  ==   rX)	&&	(PosArray[8][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ((PosArray[9][0]  ==   rX)	&&	(PosArray[9][1]  ==   rY))
					{
						hit_exit += 1;
						cout<<"Ship Hit"<<endl;
						cout<<" Player 2 ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					if  ( hit_exit == 20)
					{
						cout<<"Ship hits: "<<setw(5)<<hit_exit<<endl;
						cout<<"ALL SHIPS DESTROYED"<<endl;
					}
					else
					{
						hit_exit  = hit_exit;
						cout<<"Missed"<<endl;
						cout<<"Ship hits: "<<setw(5)<<hit_exit<<endl;
					}
					Player2 = false;
				}
				
		}
	}
	
	if ((button == GLUT_LEFT_BUTTON)      &&      (Player1  ==  false))            //For Player 1 turn
	{
		if(( x >= 160    &&    x <= 320)  && (  y >= 620   &&    y <=  660))
		{
				Player1 = true;
				cout<<"Player 1 turn"<<endl;
				//tri2();
				Player1 = false;
		}
	}
}

int main(int argc, char*argv[]) {
	
	unsigned int var = time(0);
	srand (var);
	int width = 1120, height = 780; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Battleship Game 2"); // set the title of our game window
	//glutDisplayFunc ( Callback_win_dis);
	SetCanvasSize(width, height); // set the number of pixels...
		
	//timerindex = 0;
	glutDisplayFunc(screen_1); // tell library which function to call for drawing Canvas.
	//glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);
	glutTimerFunc(1000.0, Counter, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); 
	glutMotionFunc(MousePressedAndMoved); 
	
	glutMainLoop();
	return 1;
}
#endif /* Battleship_CPP_ */
