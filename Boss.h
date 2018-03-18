#pragma once
#include"TextureManager.h"
#include"Game.h"

class Boss
{
public:
	Boss(int X,int Y);
	~Boss();
	void Draw();
	void Update();
	bool bulletHit(int X, int Y);
	int heart;
private:
	//the Texture of the boss
	SDL_Texture* bossTex;
	SDL_Texture* heartT, *emtyHeart;
	//the width and height of the pic
	int frameWidth, frameHeight;
	//the w and height of each boss frame 
	int bossWidth, bossHeight;
	//the life of the boss 
	int fullHeart;
	//thedelay between frame 
	int frameDelay = 0;
	//frame cut controls and pos control
	SDL_Rect desRect, scrRect,heartRect;
	//position of the boss
	int Xpos, Ypos;
	//the run speed of the boss
	double rate;
	int Xvelocity;
	int Yvelocity;
	bool hit = false;
	int hitDelay = 0;
	int runSpeed;
	//the direction of the boss
	int dir = 0;
};

