#pragma once
#include "TextureManager.h"
#include"Game.h"
#include<cmath>
#include "weapon.h"
#include<fstream>

class Player
{
public:
	Player(int characterNum);
	~Player();
	void handleEvent();
	void Draw();
	void Update();
	static int heart;
	static const int playerPosX;
	static const int playerPosY;
	static int Xpos;
	static int Ypos;
	//number of character
	int character;
	//gun type
	int guntype;

private:
	// player Texture
	SDL_Texture* texture;
	int col,row;
	//player w,h,x,y
	int picWidth, picHeight;
	int frameWidth, frameHeight;
	int playerWidth, playerHeight;
	SDL_Rect desRect, scrRect;
	
	//character function
	
	SDL_Rect heartRect;
	
	int fullHeart;
	int runSpeed;
	int FPS = 0;
	int dir = 0;
	//get the character I and J
	void getIJ();
	int Ipos, Jpos;
	//necessary thing 
	SDL_Texture* heartT, *ghost, *emtyHeart;
	int money = 0;
	int gunHave[15];
	
};

