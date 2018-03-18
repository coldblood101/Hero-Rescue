#include"Game.h"
#include"menu.h"
#include"Optionbar.h"
Game* gameStart = nullptr;
menu* gameMenu = nullptr;
Optionbar* characterChoose = nullptr;
int main(int argv, char* argc[])
{
	gameStart = new Game();
	gameStart->Initialize("Hero Rescue", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 700, SDL_WINDOW_BORDERLESS);
	//loading
	gameMenu = new menu();
	characterChoose = new Optionbar();
	//loading
	const int FPS = 60;
	const int frameDelay = 600 / FPS;
	Uint32 frameStart;
	int frameTime;
	//game menu
	Menu:while (!gameMenu->gameStart)
	{
		gameMenu->handleEvent();
		gameMenu->Draw();
		gameStart->gameEnd = gameMenu->outGame;
	}
	//game Option
	while (!characterChoose->optionMake()&& !gameStart->gameEnd)
	{
		characterChoose->handleEvent();
		characterChoose->Draw();
		//menu hit
		if (characterChoose->menuHit) {
			gameMenu->outGame = false;
			gameMenu->gameStart = false;
			characterChoose->menuHit = false;
			goto Menu;
		}
		//character choose
		if (characterChoose->choose() != -1)
			gameStart->setCharacter(characterChoose->choose());
		
	}
	//set the started value for the game 
	gameStart->setValue();
	//game play 
	while (!gameStart->gameEnd)
	{
		frameStart = SDL_GetTicks();
		gameStart->handleEvent();
		gameStart->Update();
		gameStart->Draw();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}
	gameStart->Close();
	return 0;
}