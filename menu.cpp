#include "menu.h"
using namespace std;


menu::menu()
{
	//the Texture menu 
	backGround=TextureManager::LoadTexture("pic/menu/entry.png");
	optionBar=TextureManager::LoadTexture("pic/menu/OptionBar.png");
	newGame = TextureManager::LoadTexture("pic/menu/newGame.png");
	preGame = TextureManager::LoadTexture("pic/menu/continue.png");
	chooseBar = TextureManager::LoadTexture("pic/menu/selection.png");
	title = TextureManager::LoadTexture("pic/menu/title.png");
	exitT = TextureManager::LoadTexture("pic/menu/exit.png");
	backGround2 = TextureManager::LoadTexture("pic/menu/back.png");
	shade = TextureManager::LoadTexture("pic/menu/backShade.png");
	//the main option menu 
	optionRect.x = 100;
	optionRect.y = 100;
	optionRect.w = 500;
	optionRect.h = 500;

	//the option bar Rect
	chooseRect.x = 310;
	chooseRect.y = 275;
	chooseRect.w = 100;
	chooseRect.h = 20;
	//backGround 2 rect
	backRect.x = 20;
	backRect.y = -10;
	backRect.w = 700;
	backRect.h = 300;
	//title rect
	titleRect.x = 50;
	titleRect.y = 600;
	titleRect.w = 600;
	titleRect.h = 100;
}


menu::~menu()
{
}

void menu::Draw()
{
	SDL_RenderClear(Game::renderer);
	SDL_RenderCopy(Game::renderer, backGround, NULL, NULL);
	backRect.y = -30;
	SDL_RenderCopy(Game::renderer, shade, NULL, &backRect);
	backRect.y = -10;
	SDL_RenderCopy(Game::renderer, backGround2, NULL, &backRect);
	SDL_RenderCopy(Game::renderer, title, NULL, &titleRect);
	SDL_RenderCopy(Game::renderer, optionBar, NULL, &optionRect);
	chooseRect.y = 275;
	SDL_RenderCopy(Game::renderer, newGame, NULL, &chooseRect);
	chooseRect.y = 275+85;
	SDL_RenderCopy(Game::renderer, preGame, NULL, &chooseRect);
	chooseRect.y = 275+175;
	SDL_RenderCopy(Game::renderer, exitT, NULL, &chooseRect);
	SDL_RenderPresent(Game::renderer);
	
}
void menu::handleEvent()
{
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_KEYUP:
		break;
	case SDL_MOUSEBUTTONDOWN:
		if (e.motion.x >= 270 && e.motion.x <= 445)
		{
			if (e.motion.y >= 275 && e.motion.y <= 305)
			{
				//new game button
				ofstream playerFile;  
				playerFile.open("preData/character.txt");
				playerFile.clear();
				playerFile << "0 ";
				playerFile.close();
				playerFile.open("preData/gun.txt");
				playerFile.clear();
				playerFile << "1 ";
				playerFile.close();
				playerFile.open("preData/lv.txt");
				playerFile.clear();
				playerFile << "1 ";
				playerFile.close();
				playerFile.open("preData/money.txt");
				playerFile.clear();
				playerFile << "0 ";
				playerFile.close();
				gameStart = true;
			}
			else if (e.motion.y >= 365 && e.motion.y <= 395)
			{
				//continua button
				gameStart = true;
			}
			else if (e.motion.y >= 450 && e.motion.y <= 480)
			{
				//exit button
				gameStart = true;
				outGame = true;
				
			}
		}
		break;
	}
}