#pragma once
#include"TextureManager.h"
#include"Game.h"
#include"bullet.h"	
#include"Player.h"


class weapon
{
public:
	weapon(int gunNum);
	~weapon();
	void Update(int gunType);
	void Draw();
	void handleEvent();
	//gun angle
	int  angle = 135;
private:
	int gunWidth;
	int gunHeight;
	//gun Pos
	int Xpos, Ypos;
	//gun w,h,x,y
	SDL_Rect desRect;
	//gun rotating point
	SDL_Point rotate;
	//gun Texture 
	SDL_Texture* gun1;
	SDL_Texture* gun2;
	SDL_Texture* gun3;
	SDL_Texture* gun4;
	SDL_Texture* gun5;
	SDL_Texture* gun6;
	SDL_Texture* gun7;
	SDL_Texture* gun8;
	SDL_Texture* gun9;
	SDL_Texture* gun10;
	SDL_Texture* gun11;
	SDL_Texture* gun12;
	SDL_Texture* gun13;
	SDL_Texture* gun14;
	//the gun king 
	int gunKind;
	//the number of the bullet has shoot
	int bulletNum = 0;
	//limit the hold press button
	bool hit = false;
};

