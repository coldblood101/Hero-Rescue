#pragma once
#include "Game.h"
class Map
{
public:
	Map(int mapNum);
	~Map();
	void Draw();
	static int map1[200][200];
	static int map2[200][200];
	static int map3[200][200];
	static int Xmap ;
	static int Ymap ;
private:
	int mapName;
	SDL_Texture* floor;
	SDL_Texture* wall;
	SDL_Texture* water;
	SDL_Texture* rock;
	SDL_Rect blockRect;
};

