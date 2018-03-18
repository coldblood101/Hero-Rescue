#include "Player.h"
#include"TextureManager.h"
//static var declear 
int Player::Xpos;
int Player::Ypos;
const int Player:: playerPosX = 250;
const int Player:: playerPosY = 250;
int Player:: heart;
//pointer declear 
weapon* gun = nullptr;


Player::Player(int characterNum)
{
	//Initialize the texture
	texture = TextureManager::LoadTexture("pic/character/character4.png");
	//number of character
	character = characterNum;
	//number of the characcol in the full pic 
	col = 4;
	row = 2;
	//set the character function
	switch (character)
	{
	case 0:
		heart = 4;
		runSpeed = 4;
		break;
	case 1:
		heart = 5;
		runSpeed = 3;
		break;
	case 2:
		heart = 3;
		runSpeed = 6;
		break;
	case 3:
		heart = 5;
		runSpeed = 4;
		break;
	case 4:
		heart = 7;
		runSpeed = 2;
		break;
	case 5:
		heart = 2;
		runSpeed = 9;
		break;
	case 6:
		heart = 7;
		runSpeed = 7;
		break;
	case 7:
		heart = 9;
		runSpeed = 7;
		break;
	}
	fullHeart = heart;
	//get the texture information
	SDL_QueryTexture(texture, NULL, NULL, &picWidth, &picHeight);
	
	frameWidth = picWidth / col;
	frameHeight = picHeight / row;//width and height ofthe character frame 

	playerWidth = frameWidth / 3;
	playerHeight = frameHeight / 4;
	//set the first pos of the character
	Xpos = 250;
	Ypos = 250;
	//set the character w,h,x,y
	desRect.x = playerPosX;
	desRect.y = playerPosY;
	desRect.w = desRect.h = 60;
	//set the scrRect to tcut and move animation
	scrRect.x = (character%col)*frameWidth;
	scrRect.y = (character / col)*frameHeight;
	scrRect.w = playerWidth;
	scrRect.h = playerHeight;
	//set the life w,h,x,y
	heartRect.w = heartRect.h = 10;
	//necessary thing 
	heartT = TextureManager::LoadTexture("pic/necessary/heart.png");
	emtyHeart = TextureManager::LoadTexture("pic/necessary/emtyHeart.png");
	ghost = TextureManager::LoadTexture("pic/necessary/ghost.png");
	
	//load the previous information
	std::ifstream myfile;
	myfile.open("preData/gun.txt");
	for (int i = 0; i < 15; i++)
		myfile >> gunHave[i];


	//gun modivate
	guntype = 1;
	gun = new weapon(guntype);
}


Player::~Player()
{
}

void Player::handleEvent()
{
	if (heart > 0) {
		gun->handleEvent();
		switch (Game::e.type)
		{
		case SDL_KEYDOWN:
			if (Game::e.key.keysym.sym == SDLK_LEFT)
			{
				FPS++;
				Map::Xmap -= runSpeed;
				Xpos -= runSpeed;
				dir = 1;
				gun->angle = 225;
			}
			else if (Game::e.key.keysym.sym == SDLK_RIGHT)
			{
				FPS++;
				Map::Xmap += runSpeed;
				Xpos += runSpeed;
				dir = 2;
				gun->angle = 45;
			}
			else if (Game::e.key.keysym.sym == SDLK_UP)
			{
				FPS++;
				Map::Ymap -= runSpeed;
				Ypos -= runSpeed;
				dir = 3;
				gun->angle = 315;
			}
			else if (Game::e.key.keysym.sym == SDLK_DOWN)
			{
				FPS++;
				Map::Ymap += runSpeed;
				Ypos += runSpeed;
				dir = 0;
				gun->angle = 135;
			}
			break;
		}
	}
}
void Player::Draw()
{
	if (FPS == 10)
	{
		//update the frame of the character animation
		FPS = 0;
		scrRect.x+=playerWidth;
		if(scrRect.x>= (character%col)*frameWidth+3*playerWidth)
			scrRect.x = (character%col)*frameWidth;
	}
	
	//render the player
	SDL_RenderCopy(Game::renderer, texture, &scrRect, &desRect);
	if (heart > 0)
	{
		//render the player heart 
		for (int i = 0; i < heart; i++)
		{
			heartRect.y = playerPosY-20;
			heartRect.x = i * 10 + playerPosX;
			SDL_RenderCopy(Game::renderer,heartT, NULL, &heartRect);
		}
		for (int i = heart; i < fullHeart; i++)
		{
			heartRect.y = playerPosY - 20;
			heartRect.x = playerPosX + i * 10;
			SDL_RenderCopy(Game::renderer, emtyHeart, NULL, &heartRect);
		}

	}
	else
	{
		heartRect.y = playerPosX - 50;
		heartRect.x = playerPosX;
		heartRect.w = heartRect.h = 50;
		SDL_RenderCopy(Game::renderer, ghost, NULL, &heartRect);
	}
	gun->Draw();
}
void Player::Update()
{
	//get the pos of the character in the map
	getIJ();
	//limit the chracter move by block 
	if (dir == 0 && Map::map1[Ipos][Jpos] == 1) {
		Map::Ymap -= runSpeed;
		Ypos -= runSpeed;
	}
	if (dir == 1 && (Map::map1[Ipos][Jpos] == 1 || Map::map1[Ipos][Jpos - 1] == 1)) {
		Map::Xmap += runSpeed;
		Xpos += runSpeed;
	}
	if (dir == 2 && Map::map1[Ipos][Jpos] == 1) {
		Map::Xmap -= runSpeed;
		Xpos -= runSpeed;
	}
	if (dir == 3 && Map::map1[Ipos - 1][Jpos] == 1) {
		Map::Ymap += runSpeed;
		Ypos += runSpeed;
	}
	scrRect.y = (character / col)*frameHeight + dir*playerHeight;
	desRect.y = playerPosY;
	desRect.x = playerPosX;

	//update the gun posittion
	gun->Update(guntype);
}
void Player::getIJ()
{
	//pass the Ipos and Jpos of the character in the map 
	Jpos = (int)ceil((double)(playerPosX+Map::Xmap)/50);
	Ipos = (int)ceil((double)(playerPosY+Map::Ymap) / 50);
}