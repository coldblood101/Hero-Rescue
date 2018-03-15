#include "weapon.h"
#include <cmath>
using namespace std;
bullet* Fire[20];

weapon::weapon(int gunNum)
{
	angle = 135;
	gunKind = gunNum;
	//declear the gun Texture 
	gun1 =TextureManager::LoadTexture("pic/gun/gun01.png");
	gun2 =TextureManager::LoadTexture("pic/gun/gun02.png");
	gun3 =TextureManager::LoadTexture("pic/gun/gun03.png");
	gun4 =TextureManager::LoadTexture("pic/gun/gun04.png");
	gun5 =TextureManager::LoadTexture("pic/gun/gun05.png");
	gun6 =TextureManager::LoadTexture("pic/gun/gun06.png");
	gun7 =TextureManager::LoadTexture("pic/gun/gun07.png");
	gun8 =TextureManager::LoadTexture("pic/gun/gun08.png");
	gun9 =TextureManager::LoadTexture("pic/gun/gun09.png");
	gun10=TextureManager::LoadTexture("pic/gun/gun10.png");
	gun11=TextureManager::LoadTexture("pic/gun/gun11.png");
	gun12=TextureManager::LoadTexture("pic/gun/gun12.png");
	gun13=TextureManager::LoadTexture("pic/gun/gun13.png");
	gun14=TextureManager::LoadTexture("pic/gun/gun14.png");
	//GET THE GUN WIDTH AND HEIGHT
	switch (gunKind) {
	case 1:
		SDL_QueryTexture(gun1, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 2:
		SDL_QueryTexture(gun2, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 3:
		SDL_QueryTexture(gun3, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 4:
		SDL_QueryTexture(gun4, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 5:
		SDL_QueryTexture(gun5, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 6:
		SDL_QueryTexture(gun6, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 7:
		SDL_QueryTexture(gun7, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 8:
		SDL_QueryTexture(gun8, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 9:
		SDL_QueryTexture(gun9, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 10:
		SDL_QueryTexture(gun10, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 11:
		SDL_QueryTexture(gun11, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 12:
		SDL_QueryTexture(gun12, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 13:
		SDL_QueryTexture(gun13, NULL, NULL, &gunWidth, &gunHeight);
		break;
	case 14:
		SDL_QueryTexture(gun14, NULL, NULL, &gunWidth, &gunHeight);
		break;
	}
	//set the gun pos w and height 
	desRect.x = Player::playerPosX + 30;
	desRect.y = Player::playerPosY + 30;
	desRect.w = 30;
	desRect.h = (int)round((30.0*gunHeight) / gunWidth);

	//Set the gun rotate point 
	rotate.x = 10;
	rotate.y = (int)round((30.0*gunHeight) / gunWidth)/2 ;
}


weapon::~weapon()
{
}

void weapon::Update(int gunType)
{
	for (int i = 0; i < 20; i++) {
		if (Fire[i] != nullptr) {
			Fire[i]->Update();
			if (!Fire[i]->distance()) {
				Fire[i] = nullptr;
				Game::Xbullet[i] = 0;
				Game::Ybullet[i] = 0;
			}
		}
	}
	gunKind = gunType;
	desRect.x = Player::playerPosX + 30;
	
}
void weapon::Draw()
{
	for (int i = 0; i<20; i++)
		if (Fire[i] != nullptr)
			Fire[i]->Draw();
	switch (gunKind) {
	case 1:
		SDL_RenderCopyEx(Game::renderer,gun1, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 2:
		SDL_RenderCopyEx(Game::renderer,gun2, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 3:
		SDL_RenderCopyEx(Game::renderer,gun3, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 4:
		SDL_RenderCopyEx(Game::renderer,gun4, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 5:
		SDL_RenderCopyEx(Game::renderer,gun5, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 6:
		SDL_RenderCopyEx(Game::renderer,gun6, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 7:
		SDL_RenderCopyEx(Game::renderer,gun7, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 8:
		SDL_RenderCopyEx(Game::renderer,gun8, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 9:
		SDL_RenderCopyEx(Game::renderer,gun9, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 10:
		SDL_RenderCopyEx(Game::renderer,gun10, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 11:
		SDL_RenderCopyEx(Game::renderer,gun11, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 12:
		SDL_RenderCopyEx(Game::renderer,gun12, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 13:
		SDL_RenderCopyEx(Game::renderer,gun13, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	case 14:
		SDL_RenderCopyEx(Game::renderer,gun14, NULL,&desRect, angle, &rotate, SDL_FLIP_NONE);
		break;
	}
}
void weapon::handleEvent()
{

	switch (Game::e.type)
	{
	case SDL_KEYDOWN:
		if (Game::e.key.keysym.sym == SDLK_SPACE&&!hit)
		{
			hit = true;
			if (bulletNum == 19)
				bulletNum = 0;
			if (Fire[bulletNum] != nullptr)
				Fire[bulletNum] = nullptr;
			Fire[bulletNum] = new bullet(angle, gunKind,bulletNum);
			Game::Xbullet[bulletNum] = Player::Xpos;
			Game::Ybullet[bulletNum] = Player::Ypos;
			bulletNum++;
			
		}
		break;
	case SDL_KEYUP:
		if (Game::e.key.keysym.sym == SDLK_SPACE)
			hit = false;
		break;
	default:
		break;
	}
}
