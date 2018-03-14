#include"Game.h"
Game* gameStart = nullptr;
int main(int argv, char* argc[])
{
	gameStart = new Game();
	gameStart->Initialize("Hero Rescue", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 700, 700, SDL_WINDOW_SHOWN);
	const int FPS = 60;
	const int frameDelay = 600 / FPS;
	Uint32 frameStart;
	int frameTime;
	while (!gameStart->isRunning())
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