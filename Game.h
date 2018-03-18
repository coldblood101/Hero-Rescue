#ifndef Game_hpp
#define Game_hpp
#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<time.h>

///user library declear 
#include "Map.h"
#include"Player.h"
#include"enemy.h"
#include"Boss.h"

class Game
{
public:
	Game();
	~Game();
	void Initialize(const char* title, int x, int y, int width, int height, int screenOption);
	void Draw();
	void Update();
	void Close();
	void handleEvent();
	void setValue();
	void setCharacter(int characterType);

	static SDL_Event e;
	static SDL_Renderer* renderer;
	static int Xbullet[20];
	static int Ybullet[20];
	bool gameEnd = false;
	
private:
	SDL_Window* window = NULL;
	int characterNum=0;

};

#endif // !1