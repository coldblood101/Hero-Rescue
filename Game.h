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


class Game
{
public:
	Game();
	~Game();
	void Initialize(const char* title, int x, int y, int width, int height, int screenOption);
	void Draw();
	bool isRunning();
	void Update();
	void Close();
	void handleEvent();
	static SDL_Event e;
	static SDL_Renderer* renderer;
	
	
	
private:
	SDL_Window* window = NULL;
	bool gameEnd = false;

};

#endif // !1