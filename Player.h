#pragma once
#include "TextureManager.h"
#include"Game.h"
#include<cmath>
#include "weapon.h"


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
private:
	// player Texture
	SDL_Texture* texture;
	int col,row;
	//player w,h,x,y
	int picWidth, picHeight;
	int frameWidth, frameHeight;
	int playerWidth, playerHeight;
	SDL_Rect desRect, scrRect;
	//number of character
	int character;
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
	int guntype;
};

