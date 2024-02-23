#include <iostream>
//#include <conio.h>

//Not sure these need to be here, it's the World position stuff.
int globalX = 0;
int globalY = 0;
bool gamePlaying = true;
bool gameMenu = false;
int playerChoice = 0;
std::string fillerHold = " ";

std::string screen[30][80] = {};


//NO LONGER A GIANT CHUNK, NOW MAKE A ZONE CHANGER.
//??Two arrays, write to second with walkable or not, 'fill' is walkable and 'border' is not on Rect.??
std::string world[100][100] = {};

//Array for the walkable objects.
//Struggling.
std::string filler[100][100] = {};




//Rects.
// Box Size, Location, Border Char and Edge Char. Prints to Screen Array.
//Thinking about adding a "has a door" bool;
//But then you need a lotta extra info for a door.

//Prints to Screen.
class Rect1
{
private:
	int drawSelf(int w, int h, int x, int y, std::string e, std::string f)
	{
		for (int i = y; i <= (y + (h - 1)); i++)
		{
			for (int l = x; l <= (x + (w -1)); l++)
			{
				if (i == y || i == y + (h - 1) || l == x || l == x + (w - 1))
				{
					screen[i][l] = e;
				}
				else
				{
					//This could be used for collision with a 2d array as bones later.
					screen[i][l] = f;
				}
				

			}
			
		}
		
		return 0;
	}
	
public:
	int width = 60;
	int height = 20;

	int posX = 1;
	int posY = 1;

	std::string windowEdge = "#";
	std::string windowFill = " ";

	int showSelf()
	{
		drawSelf(width, height, posX, posY, windowEdge, windowFill);
		return 0;
	}
	
	
};

//Prints to World.
class Rect2
{
private:
	int drawSelf(int w, int h, int xb, int yb, int x, int y, std::string e, std::string f)
	{
		for (int i = y; i <= (y + (h - 1)); i++)
		{
			for (int l = x; l <= (x + (w - 1)); l++)
			{
				if (i <= (y + yb) || i >= y + (h - (1 + yb)) || l <= (x + xb) || l >= x + (w - (1 + xb)))
				{
					world[i][l] = e;
				}
				else
				{
					//This could be used for collision with a 2d array as bones later.
					world[i][l] = f;
				}


			}

		}

		return 0;
	}

public:
	int width = 60;
	int height = 20;

	int xBord = 0;
	int yBord = 0;

	int posX = 1;
	int posY = 1;

	std::string windowEdge = "#";
	std::string windowFill = " ";

	int showSelf()
	{
		drawSelf(width, height, xBord, yBord, posX, posY, windowEdge, windowFill);
		return 0;
	}


};

//Prints to Filler.
class Rect3
{
private:
	int drawSelf(int w, int h, int x, int y, std::string e, std::string f)
	{
		for (int i = y; i <= (y + (h - 1)); i++)
		{
			for (int l = x; l <= (x + (w - 1)); l++)
			{
				if (i == y || i == y + (h - 1) || l == x || l == x + (w - 1))
				{
					filler[i][l] = e;
				}
				else
				{
					//This could be used for collision with a 2d array as bones later.
					filler[i][l] = f;
				}


			}

		}

		return 0;
	}

public:
	int width = 60;
	int height = 20;

	int posX = 1;
	int posY = 1;

	std::string windowEdge = "#";
	std::string windowFill = " ";

	int showSelf()
	{
		drawSelf(width, height, posX, posY, windowEdge, windowFill);
		return 0;
	}


};


//Could use a simple Line drawing tool.


class playerChar
{
private:
	//Update location to print like the Rects
	int locUpdate()
	{
		if (curX < 10 || curX > 85)
		{
			lockX = true;
		}
		else
		{
			lockX = false;
		}
		if (curY < 10 || curY > 85)
		{
			lockY = true;
		}
		else
		{
			lockY = false;
		}

		
		return 0;
	}
public:
	bool lockX = false;
	bool lockY = false;
	int hp = 100;
	int exp = 0;
	int curX = 10;
	int curY = 6;
	int damage = 5;
	std::string playerIcon = "W";
	std::string name = "PlayerChar";
	std::string role = "Warrior";
	int locPull()
	{
		locUpdate();
		return 0;
	}
};

//Player Classes
playerChar warrior;

//UI Boxes
Rect1 mainScreen;
Rect1 sidePanel;
Rect1 hud;
Rect1 menu;

//World constructor
int WorldReady()
{
	



	//World outline & config.
	Rect2 WorldBorder;
	WorldBorder.height = 100;
	WorldBorder.width = 100;
	WorldBorder.posX = 0;
	WorldBorder.posY = 0;
	WorldBorder.windowEdge = "#";
	WorldBorder.windowFill = "T";

	//World Fill.
	Rect2 WorldFill;
	WorldFill.height = 94;
	WorldFill.width = 94;
	WorldFill.posX = 3;
	WorldFill.posY = 3;
	WorldFill.windowEdge = "T";
	WorldFill.windowFill = " ";

	//A House or Something
	Rect2 Building01;
	Building01.height = 14;
	Building01.width = 14;
	Building01.xBord = 1;
	Building01.yBord = 1;
	Building01.posX = 10;
	Building01.posY = 10;
	Building01.windowEdge = "#";
	Building01.windowFill = " ";

	//A House or Something
	Rect2 Building02;
	Building02.height = 8;
	Building02.width = 16;
	Building02.posX = 38;
	Building02.posY = 10;
	Building02.windowEdge = "#";
	Building02.windowFill = " ";
	


	//Rect WorldFill;

	WorldBorder.showSelf();
	WorldFill.showSelf();

	Building01.showSelf();
	Building02.showSelf();

	//paths01.showSelf();

	//Gotta draw doors last, to have them be there and all.
	//Building01 Doors.
	world[10][12] = " ";
	world[10][13] = " ";
	world[10][14] = " ";
	world[11][12] = " ";
	world[11][13] = " ";
	world[11][14] = " ";

	//Building02 Doors.
	world[12][38] = " ";
	world[13][38] = " ";



	//Later a zone swapper needs to be here, the string array with the switch statements.
	//Rect BuildingOne;
	return 0;
}



//Floods the Screens 80x30 with a Char, outlines all the windows.
int fillScreen()
{
	for (int n = 0; n <= 29; n++)
	{
		for (int m = 0; m <= 79; m++)
		{
			screen[n][m] = "X";
		}
		std::cout << "\n";
	};
	return 0;
}

int choiceResolve(int i)
{
	switch (i)
	{

	case 1:


		if (world[warrior.curY][warrior.curX - 1] == " ")
		{

			world[warrior.curY][warrior.curX] = " ";
			warrior.curX -= 1;
			world[warrior.curY][warrior.curX] = warrior.playerIcon;

			if (globalX != 0 && warrior.lockX == false)
			{
				globalX -= 1;
			}
		}


		break;
	case 2:
		if (world[warrior.curY + 1][warrior.curX] == " ")
		{
			world[warrior.curY][warrior.curX] = " ";
			warrior.curY += 1;
			world[warrior.curY][warrior.curX] = warrior.playerIcon;
			if (globalY != 99 && warrior.lockY == false)
			{
				globalY += 1;
			}
		}
		break;
	case 3:
		if (world[warrior.curY - 1][warrior.curX] == " ")
		{
			world[warrior.curY][warrior.curX] = " ";
			warrior.curY -= 1;
			world[warrior.curY][warrior.curX] = warrior.playerIcon;

			if (globalY != 0 && warrior.lockY == false)
			{
				globalY -= 1;
			}
		}
		break;
	case 4:
		if (world[warrior.curY][warrior.curX + 1] == " ")
		{

			world[warrior.curY][warrior.curX] = " ";
			warrior.curX += 1;
			world[warrior.curY][warrior.curX] = warrior.playerIcon;

			if (globalX != 99 && warrior.lockX == false)
			{
				globalX += 1;
			}
		}
		break;
	case 5:
		//Main Menu Screen
		if (gameMenu == true)
		{
			gameMenu = false;
		}
		else
		{
			gameMenu = true;
		}
		break;

	case 6:
		//End Game, gonna be moved later
		gamePlaying = false;
		break;
	};
	return 0;
}

/*
int textHandler(int i, bool o)
{
	std::string menuLineOne[14] =
	{
		"6"," ","="," ","E","x","i","t"," ","G","a","m","e","."
	};

	int step = 0;
	bool menuText = o;


	if (menuText == true)
	{
		step = 0;
		for (int x = 2; x < 14; x++)
		{
			
			screen[3][x] = menuLineOne[step];
			step++;
		}
	}
	
	return 0;
}
*/

int main()
{
	WorldReady();
	
	while (gamePlaying == true)
	{
		system("cls");


		//Floods the Screens 80x30 with a Char, outlines all the windows.
		fillScreen();

		//These are just for the Screen Print I think?
		int screenHeight = 30;
		int screenWidth = 80;

		//Text Step
		int step = 0;
		std::string menuLineOne[14] =
		{
			"6",":"," "," ","E","x","i","t"," ","G","a","m","e","."
		};
	


		//UI Box settings.
		menu.posX = 61;
		menu.width = 18;
		menu.height = 8;
		menu.posY = 21;
		menu.windowFill = "~";
		sidePanel.width = 18;
		sidePanel.posX = 61;
		sidePanel.windowFill = "-";
		hud.posY = 21;
		hud.height = 8;
		hud.windowFill = "_";


		// All the UI Boxes.
		// Probably bundle with the screen fill and pack into "displayAll" thing.
		
		//mainScreen.showSelf();
		sidePanel.showSelf();
		hud.showSelf();
		menu.showSelf();


		//Text Items outside the main screen can go here, after the other Rects.
		
		

		//This is the actual play area of the world, view.
		if (gameMenu == true)
		{
			mainScreen.showSelf();
			//Other Menus in the Menu will need to replace the text drawn, probably a switch system here to swap, inv, equip, stats.
			for (int x = 3; x < 16; x++)
			{

				screen[3][x] = menuLineOne[step];
				step++;
			}
		}
		else
		{
			mainScreen.showSelf();
			for (int y = 2; y <= 19; y++)
			{
				for (int x = 2; x <= 59; x++)
				{
					screen[y][x] = world[y + (globalY - 1)][x + (globalX - 1)];
				}
			}

			/*
			for (int y = 2; y <= 19; y++)
			{
				for (int x = 2; x <= 59; x++)
				{
					fillerHold = filler[y + (globalY - 1)][x + (globalX - 1)];
					if (fillerHold != " ")
					{

						screen[y][x] = filler[y + (globalY - 1)][x + (globalX - 1)];
					}
					
					
				}
			}
			*/
			
			
		}
		

		warrior.locPull();

		//This is rendering, needs to get packed with the fill and all Rects, with a bool system for display.
		for (int j = 0; j <= (screenHeight - 1); j++)
		{
			for (int l = 0; l <= (screenWidth - 1); l++)
			{
				std::cout << screen[j][l];
			}
			std::cout << "\n";
		}


		//KEyboard
		//if (GetAsyncKeyState((unsigned short)'A') & 0x8000)

		//Handles moving the Global X and Y in the switch, will need to account for player and collision on world also.
		std::cout << " [1 = Left, 2 = Down, 3 = Up, 4 = Right, 5 = Menu] Make a Selection: ";
		std::cin >> playerChoice;

		choiceResolve(playerChoice);
		

	}
	

	


	return 0;

}