#include "Optionbar.h"
using namespace std;


Optionbar::Optionbar()
{
	memset(characterSet, -1, sizeof(characterSet));
	ifstream myFile;
	myFile.open("preData/character.txt");
	for (int i = 0; i < 8; i++)
		myFile >> characterSet[i];
	//texture define
	selectionBar = TextureManager::LoadTexture("./pic/menu/selection.png");

	for (int i = 0; i < 8; i++)
	{
		//set the character link
		std::string pic = "./pic/menu/";
		std::string tmp = " ";
		tmp[0] = i + '0';
		pic += tmp;
		pic += ".png";
		character[i] = TextureManager::LoadTexture(pic.c_str());
		//set the shade link
		pic = "./pic/menu/shade";
		pic += tmp;
		pic += ".png";

		shade[i] = TextureManager::LoadTexture(pic.c_str());
	}
	nextButton=TextureManager::LoadTexture("pic/menu/nextButton.png");
	menuButton=TextureManager::LoadTexture("pic/menu/menuButton.png");
	//width and height picture define
	shadeRect.w = 150;
	shadeRect.h = 150;
	//
	menuRect.w = menuRect.h = 60;
	menuRect.x = menuRect.y = 20;
	//
	nextRect.w = nextRect.h = 60;
	nextRect.x = 630;
	nextRect.y = 280;
}


Optionbar::~Optionbar()
{
}

void Optionbar::handleEvent()
{
	//catch event
	SDL_Event e;
	SDL_PollEvent(&e);
	switch (e.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (e.motion.y >= 70 && e.motion.y <= 220)
		{
			if (e.motion.x >= 100 && e.motion.x <= 250) {
				characterChoose = 0;
				option = true;
			}
			else if (e.motion.x >= 250 && e.motion.x <= 400&&findList(1)) {

				characterChoose = 1;
				option = true;
			}
			else if (e.motion.x >= 400 && e.motion.x <= 550 && findList(2)) {
				characterChoose = 2;
				option = true;
			}
		}
		else if (e.motion.y >= 250 && e.motion.y <= 400) 
		{
			if (e.motion.x >= 100 && e.motion.x <= 250 && findList(3)) {
				characterChoose = 3;
				option = true;
			}
			else if (e.motion.x >= 250 && e.motion.x <= 400 && findList(4)) {
				characterChoose = 4;
				option = true;
			}
			else if (e.motion.x >= 400 && e.motion.x <= 550 && findList(5)) {
				characterChoose = 5;
				option = true;
			}
		}
		else if (e.motion.y >= 430 && e.motion.y <= 580)
		{
			if (e.motion.x >= 100 && e.motion.x <= 250 && findList(6)) {
				characterChoose = 6;
				option = true;
			}
			else if (e.motion.x >= 250 && e.motion.x <= 400 && findList(7)) {
				characterChoose = 7;
				option = true;
			}
		}
		//menu button hit
		else if (e.motion.x >= 20 && e.motion.x <= 80 && e.motion.y >= 20 && e.motion.y <= 80)
		{
			menuHit = true;
		}
		break;
	default:
		break;
	}
}
bool Optionbar::optionMake()
{
	return option;
}
void Optionbar::Draw()
{
	SDL_RenderClear(Game::renderer);
	//render the background
	SDL_RenderCopy(Game::renderer, selectionBar, NULL, NULL);
	//render the button 
	SDL_RenderCopy(Game::renderer, menuButton,NULL,&menuRect);
	//renderr the player that still being lock
	for (int i = 0; i < 8; i++)
	{
		int tmp;
		if (i < 3) {
			shadeRect.y = 70;
			tmp = i;
		}
		else if (i >= 3 && i <= 5) {
			shadeRect.y = 250;
			tmp = i - 3;
		}
		else {
			shadeRect.y = 430;
			tmp = i - 6;
		}
		shadeRect.x = 100 + tmp * 150;
		SDL_RenderCopy(Game::renderer, shade[i], NULL, &shadeRect);
	}
	//render the plaer has been unlock
	for (int i = 0; i < 8; i++)
	{
		if (characterSet[i] != -1) {
			int tmp;
			if (characterSet[i] < 3) {
				shadeRect.y = 70;
				tmp = characterSet[i];
			}
			else if (characterSet[i] >= 3 && characterSet[i] <= 5) {
				shadeRect.y = 250;
				tmp = characterSet[i] - 3;
			}
			else {
				shadeRect.y = 430;
				tmp = characterSet[i] - 6;
			}
			shadeRect.x = 100 + tmp * 150;
			SDL_RenderCopy(Game::renderer, character[characterSet[i]], NULL, &shadeRect);
		}
	}
	SDL_RenderPresent(Game::renderer);
}
int Optionbar::choose()
{
	return characterChoose;
}
bool Optionbar::findList(int n)
{
	for (int i = 0; i < 8; i++)
		if (characterSet[i] == n)
			return true;
	return false;
}