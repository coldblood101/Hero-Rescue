#include "Map.h"
#include "TextureManager.h"
#include<fstream>
using namespace std;
//declear the static Variable
int Map::Xmap;
int Map::Ymap;

//declear the map construct 
int Map::map1[200][200];
int Map::map2[200][200];
int Map::map3[200][200];

Map::Map(int mapNum)
{
	//set the map name
	//mapName = mapNum % 3+1;//%3 so it can only be 1,2,3
	mapName = mapNum;
	ifstream myMap;
	myMap.open("preData/map1.txt");
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
			myMap >> map1[i][j];
	myMap.close();

	//declear the map element 
	floor=TextureManager::LoadTexture("pic/map/floor.png");
	wall = TextureManager::LoadTexture("pic/map/wall.png");
	water = TextureManager::LoadTexture("pic/map/water.png");
	rock = TextureManager::LoadTexture("pic/map/rock.png");
	//set  the width and the height of the texture 
	blockRect.w = 50;
	blockRect.h = 50;

}


Map::~Map()
{
}

void Map::Draw()
{
	//1 = wall
	//2 = floor
	//3 = water
	//4 = rock
	switch (mapName)
	{
	case 1:
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++) {
				blockRect.x = 50 * j-Xmap;
				blockRect.y = 50 * i-Ymap;
				if (map1[i][j] == 1)
					SDL_RenderCopy(Game::renderer, wall, NULL, &blockRect);
				else if(map1[i][j]==2)
					SDL_RenderCopy(Game::renderer, floor, NULL, &blockRect);
				else if (map1[i][j] == 3)
					SDL_RenderCopy(Game::renderer, water, NULL, &blockRect);
				else if (map1[i][j] == 4)
					SDL_RenderCopy(Game::renderer, rock, NULL, &blockRect);
			}
		break;
	case 2:
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++) {
				blockRect.x = 50 * i-Xmap;
				blockRect.y = 50 * j-Ymap;
				if (map2[i][j] == 1)
					SDL_RenderCopy(Game::renderer, wall, NULL, &blockRect);
				else if (map2[i][j] == 2)
					SDL_RenderCopy(Game::renderer, floor, NULL, &blockRect);
				else if (map2[i][j] == 3)
					SDL_RenderCopy(Game::renderer, water, NULL, &blockRect);
				else if (map2[i][j] == 4)
					SDL_RenderCopy(Game::renderer, rock, NULL, &blockRect);
			}
		break;
	case 3:
		for (int i = 0; i < 200; i++)
			for (int j = 0; j < 200; j++) {
				blockRect.x = 50 * i-Xmap;
				blockRect.y = 50 * j-Ymap;
				if (map3[i][j] == 1)
					SDL_RenderCopy(Game::renderer, wall, NULL, &blockRect);
				else if (map3[i][j] == 2)
					SDL_RenderCopy(Game::renderer, floor, NULL, &blockRect);
				else if (map3[i][j] == 3)
					SDL_RenderCopy(Game::renderer, water, NULL, &blockRect);
				else if (map3[i][j] == 4)
					SDL_RenderCopy(Game::renderer, rock, NULL, &blockRect);
			}
		break;
	default:
		break;
	}
}
