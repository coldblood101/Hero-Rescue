#pragma once
#include "Game.h"
#include"TextureManager.h"
#include"Player.h"
class bullet
{
public:
	bullet(double angle ,int bulletKind);
	~bullet();
	void Draw();
	void Update();
	bool distance();
private:

	//bullet Texture 
	static SDL_Texture* bullet1;
	static SDL_Texture* bullet2;
	static SDL_Texture* bullet3;
	static SDL_Texture* bullet4;
	static SDL_Texture* bullet5;
	static SDL_Texture* bullet6;
	static SDL_Texture* bullet7;
	static SDL_Texture* bullet8;
	static SDL_Texture* bullet9;
	static SDL_Texture* bullet10;
	static SDL_Texture* bullet11;
	static SDL_Texture* bullet12;
	static SDL_Texture* bullet13;
	static SDL_Texture* bullet14;
	static SDL_Texture* bullet15;
	//bullet angle 
	double bulletAngle=135;
	//bullet velocity and speed 
	double Xvelocity, Yvelocity;
	int bulletSpeed;
	int bulletType;
	//buller width and height 
	int bulletWidth, bulletHeight;
	//bulletRectc
	SDL_Rect desRect;
	SDL_Point rotate;
	//bullet pos 
	int Xpos, Ypos;
};

