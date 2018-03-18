#include "Boss.h"
using namespace std;



Boss::Boss(int X,int Y)
{
	//set the position
	Xpos = X;
	Ypos = Y;
	//set tthe runSpeed of the boss
	runSpeed = 2;
	//set the link directory
	string fileLink = "pic/boss/boss";
	string tmp = "  ";
	tmp[0] = rand() % 2 + '0';
	if (tmp[0] == '0')
	{
		tmp[1] = (char)(rand() % 9 + '1');
	}
	else
	{
		tmp[1] = (char)(rand() % 4 + '1');
	}
	fileLink += tmp;
	fileLink += ".png";
	heart = (1 + rand() % 10) * 10;
	fullHeart = heart;
	//create the texture for the boss
	bossTex = TextureManager::LoadTexture(fileLink.c_str());
	heartT = TextureManager::LoadTexture("pic/necessary/heart.png");
	emtyHeart = TextureManager::LoadTexture("pic/necessary/emtyHeart.png");
	//get the width and the height of the acctualllty picture 
	SDL_QueryTexture(bossTex, NULL, NULL, &bossWidth, &bossHeight);
	//divided to get the w and h of once boss animation
	bossWidth /= 3;
	bossHeight /= 4;
	//set the picture cut frame 
	scrRect.x = scrRect.y = 0;
	scrRect.w = bossWidth;
	scrRect.h = bossHeight;
	/// set the pos and the width and height of the pic 
	desRect.x = Xpos;
	desRect.y = Ypos;
	desRect.w = 100;
	desRect.h = (int)((double)(100 * bossHeight) / bossWidth);
	//
	heartRect.w = heartRect.h = 10;
	


}


Boss::~Boss()
{
}

void Boss::Draw()
{
	if (heart > 0) {
		//draw the monster
		SDL_RenderCopy(Game::renderer, bossTex, &scrRect, &desRect);
		//draw the heart remain of the monster 
		for (int i = 0; i < heart; i++)
		{
			heartRect.y = Ypos + 10 - Map::Ymap;
			heartRect.x = i * 10 + Xpos - Map::Xmap;
			SDL_RenderCopy(Game::renderer, heartT, NULL, &heartRect);
		}
		//draw the heart has lost of the monster 
		for (int i = heart; i < fullHeart; i++)
		{
			heartRect.y = Ypos +10- Map::Ymap ;
			heartRect.x = Xpos - Map::Xmap + i * 10;
			SDL_RenderCopy(Game::renderer, emtyHeart, NULL, &heartRect);
		}
	}
}

void Boss::Update()
{
	frameDelay++;
	if (frameDelay == 15)
	{
		frameDelay = 0;
		scrRect.x += bossWidth;
		if (scrRect.x >= 3 * bossWidth)
			scrRect.x = 0;
	}
	////
	scrRect.y =  dir*bossHeight;
	if (sqrt((Xpos - Player::Xpos)*(Xpos - Player::Xpos) + (Ypos - Player::Ypos)*(Ypos - Player::Ypos)) > 1000)
	{
		//the thing the monster do when didn't see the player 
	}
	else
	{
		//chase the player 
		rate = (double)runSpeed / (sqrt((Xpos - Player::Xpos + 10)*(Xpos - Player::Xpos + 10) + (Ypos - Player::Ypos + 10)*(Ypos - Player::Ypos + 10)));
		Xvelocity = (int)ceil(rate*(Xpos - Player::Xpos));
		Yvelocity = (int)ceil(rate*(Ypos - Player::Ypos));
		//the direct of the monster and dir is equal to the col of the animaion in the monster frame 
		if ((Xvelocity < 0 && Yvelocity < 0) || (Xvelocity < 0 && Yvelocity>0) || (Yvelocity == 0 && Xvelocity < 0))
			dir = 2;
		else if ((Xvelocity > 0 && Yvelocity < 0) || (Xvelocity > 0 && Yvelocity > 0) || (Yvelocity == 0 && Xvelocity > 0))
			dir = 1;
		else if (Xvelocity == 0 && Yvelocity > 0)
			dir = 3;
		else if (Xvelocity == 0 && Yvelocity < 0)
			dir = 0;
		//update the pos of the monster  after each frame when the player is in range 
		Xpos -= Xvelocity;
		Ypos -= Yvelocity;
		//if the monster hasn't damage the player 
		if (!hit) {
			if (sqrt((Xpos - Player::Xpos)*(Xpos - Player::Xpos) + (Ypos - Player::Ypos)*(Ypos - Player::Ypos)) <= 15) {
				//15 is the limit range when the monster will damage the player
				if (Player::heart > 0) {
					Player::heart--;
					hit = true;
				}
			}
		}
		else
		{
			hitDelay++;//the delay time betwen two damage
			if (hitDelay == 100)
			{
				hitDelay = 0;
				hit = false;
			}
		}

	}
	//update the position of the monster 
	desRect.x = Xpos - Map::Xmap;
	desRect.y = Ypos - Map::Ymap;

	////


}
bool Boss::bulletHit(int X, int Y)
{
	return (X >= Xpos&&X <= Xpos + 100 && Y >= Ypos&&Y <= Ypos + 100);

}