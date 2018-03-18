#ifndef menu_hpp
#define menu_hpp
#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<fstream>

#include"TextureManager.h"
#include"Game.h"



class menu
{
public:
	menu();
	~menu();
	void Draw();
	void handleEvent();
	bool gameStart = false;
	bool outGame = false;
private:
	
	SDL_Texture* backGround;
	SDL_Texture* optionBar;
	SDL_Texture* backGround2;
	SDL_Texture* shade;
	SDL_Texture* title;
	SDL_Texture  *newGame, *preGame,*chooseBar,*exitT;
	SDL_Rect optionRect,chooseRect,backRect,titleRect;


};
#endif
