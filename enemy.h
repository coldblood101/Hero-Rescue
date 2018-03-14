#pragma once
#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include"Player.h"
#include"bullet.h"

class enemy
{
public:
	enemy(int X,int Y);
	~enemy();
	void Draw();
	void Update();
private:
	//enemy Texture 
	SDL_Texture* texture;
	//Xposition and Y position of the enemy 
	int Xpos, Ypos;
	//the speed which will be calculate after 
	int Xvelocity;
	int Yvelocity;
	//the delay time between each time the monster shoot 
	int bulletDelay=0;
	//the angle of the bullet  
	double angle = 0;
	//the real picture width and height 
	int picWidth;
	int picHeight;
	//the frame of each character animation width and height 
	int frameWidth;
	int frameHeight;
	//the width and height of each character animation in the full picture 
	int monsterWidth;
	int monsterHeight;
	// the number of row  and col monster of the full picture  so according to that we can calculate the width and height of the frame 
	int col;
	int row;
	// the delay time before switching frame 
	int frameDelay = 0;
	//cut and defined the picture size  and pos 
	SDL_Rect desRect, scrRect;
	//the type of the monster 
	int monsterType;
	//monster function and typical  information
	SDL_Rect heartRect;
	SDL_Texture* heartT, *emtyHeart;
	int fullHeart;
	int heart;
	int bulletNum;
	int runSpeed;
	double rate;
	//the direction of the monster 
	int dir = 0;
	//hit or not 
	bool hit = false;
	int hitDelay = 0;
};

