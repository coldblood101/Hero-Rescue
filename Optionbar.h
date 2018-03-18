#pragma once
#include"Game.h"
#include<fstream>
#include<string.h>

class Optionbar
{
public:
	Optionbar();
	~Optionbar();
	void handleEvent();
	bool optionMake();
	void Draw();
	int choose();
	bool findList(int n);
	bool menuHit = false;
private:
	int characterSet[8];
	bool option = false;
	int characterChoose = -1;
	
	SDL_Texture* character[8];
	SDL_Texture* shade[8];
	SDL_Texture* selectionBar;
	SDL_Texture* nextButton;
	SDL_Texture* menuButton;


	SDL_Rect menuRect, nextRect;
	SDL_Rect shadeRect;
};

