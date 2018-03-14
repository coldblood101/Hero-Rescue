#include "enemy.h"
#include<cmath>

using namespace std;


enemy::enemy(int X,int Y)
{
	//the necessary information of the picture 
	col = 4;
	row = 2;
	Xpos = X;
	Ypos = Y;
	//get the random monster frame and png picture
	string monsterLink = "pic/monster/monster";
	string tmp = " ";
	tmp[0] = (char)(rand() % 8+ '1');
	monsterLink += tmp;
	monsterLink += ".png";
	monsterType = rand() % 8;
	//set the monster life and runSpeed
	heart = monsterType + 1;
	fullHeart = heart;
	runSpeed = 2;
	bulletNum = rand()%5+1;
	//convernt from string to const char*
	texture = TextureManager::LoadTexture(monsterLink.c_str());
	heartT = TextureManager::LoadTexture("pic/necessary/heart.png");
	emtyHeart = TextureManager::LoadTexture("pic/necessary/emtyHeart.png");
	//get the real width and height of the picture 
	SDL_QueryTexture(texture, NULL, NULL, &picWidth, &picHeight);
	//get the frame Width and Height 
	frameWidth = picWidth / col;
	frameHeight = picHeight / row;
	//get the monster size 
	monsterWidth = frameWidth / 3;
	monsterHeight = frameHeight / 4;
	//define the pos and form of the monster 
	desRect.x = Xpos;
	desRect.y = Ypos;
	desRect.w = desRect.h = 50;
	//cut start point 
	scrRect.x = (monsterType % col)*frameWidth;
	scrRect.y = (monsterType / col)*frameHeight;
	scrRect.w = monsterWidth;
	scrRect.h = monsterHeight;
	//heart w& h
	heartRect.w = heartRect.h = 10;
}


enemy::~enemy()
{
}

void enemy:: Draw()
{
	if(heart>0)
	SDL_RenderCopy(Game::renderer, texture, &scrRect, &desRect);
	for (int i = 0; i < heart; i++)
	{
		heartRect.y = Ypos - 20-Map::Ymap;
		heartRect.x = i * 10 + Xpos-Map::Xmap;
		SDL_RenderCopy(Game::renderer, heartT, NULL, &heartRect);
	}
	for (int i = heart; i < fullHeart; i++)
	{
		heartRect.y = Ypos-Map::Ymap - 20;
		heartRect.x =Xpos-Map::Xmap + i * 10;
		SDL_RenderCopy(Game::renderer, emtyHeart, NULL, &heartRect);
	}
}
void enemy::Update()
{
	desRect.x = Xpos;
	desRect.y = Ypos;
	frameDelay++;
	if (frameDelay == 15)
	{
		frameDelay = 0;
		if (scrRect.x + monsterWidth >= ((monsterType % 4)*frameWidth + 3 * monsterWidth))
			scrRect.x = (monsterType % 4)*frameWidth;
		else
			scrRect.x += monsterWidth;
	}
	scrRect.y = (monsterType / col)*frameHeight + dir*monsterHeight;
	if (sqrt((Xpos - Player::Xpos)*(Xpos - Player::Xpos) + (Ypos  - Player::Ypos)*(Ypos  - Player::Ypos)) > 600)
	{
	}
	else
	{

		rate = (double)runSpeed / (sqrt((Xpos - Player::Xpos+20)*(Xpos - Player::Xpos + 20) + (Ypos - Player::Ypos + 20)*(Ypos  - Player::Ypos + 20)));
		Xvelocity = (int)ceil(rate*(Xpos - Player::Xpos));
		Yvelocity = (int)ceil(rate*(Ypos - Player::Ypos));

		if ((Xvelocity < 0 && Yvelocity < 0) || (Xvelocity < 0 && Yvelocity>0) || (Yvelocity == 0 && Xvelocity < 0))
			dir = 2;
		else if ((Xvelocity > 0 && Yvelocity < 0) || (Xvelocity > 0 && Yvelocity > 0) || (Yvelocity == 0 && Xvelocity > 0))
			dir = 1;
		else if (Xvelocity == 0 && Yvelocity > 0)
			dir = 3;
		else if (Xvelocity == 0 && Yvelocity < 0)
			dir = 0;
		Xpos -= Xvelocity;
		Ypos -= Yvelocity;
		if (!hit) {
			if (sqrt((Xpos - Player::Xpos)*(Xpos - Player::Xpos) + (Ypos - Player::Ypos)*(Ypos - Player::Ypos)) <= 10) {
				if (Player::heart > 0) {
					Player::heart--;
					hit = true;
				}
			}
		}
		else
			{
				hitDelay++;
				if (hitDelay == 100)
				{
					hitDelay = 0;
					hit = false;
				}
			}
		
	}
	desRect.x = Xpos - Map::Xmap;
	desRect.y = Ypos - Map::Ymap;
}