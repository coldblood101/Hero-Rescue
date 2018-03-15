#include "bullet.h"
#include <cmath>
//static Texture
SDL_Texture* bullet:: bullet1;
SDL_Texture* bullet:: bullet2;
SDL_Texture* bullet:: bullet3;
SDL_Texture* bullet:: bullet4;
SDL_Texture* bullet:: bullet5;
SDL_Texture* bullet:: bullet6;
SDL_Texture* bullet:: bullet7;
SDL_Texture* bullet:: bullet8;
SDL_Texture* bullet:: bullet9;
SDL_Texture* bullet:: bullet10;
SDL_Texture* bullet:: bullet11;
SDL_Texture* bullet:: bullet12;
SDL_Texture* bullet:: bullet13;
SDL_Texture* bullet:: bullet14;
SDL_Texture* bullet::bullet15;

bullet::bullet(double angle,int bulletKind,int i)
{
	//the number of the bullet int he array 
	pos = i;
	//classify the bullet kind for each gun
	bulletType = bulletKind;
	bulletSpeed = 7;
	//the first angle of the gun when shoot 
	bulletAngle = angle+45;
	bulletAngle = (int)(angle + 45) % 360;
	bullet1 =TextureManager::LoadTexture("pic/bullet/bullet1.png" );
	bullet2 =TextureManager::LoadTexture("pic/bullet/bullet2.png" );
	bullet3 =TextureManager::LoadTexture("pic/bullet/bullet3.png" );
	bullet4 =TextureManager::LoadTexture("pic/bullet/bullet4.png" );
	bullet5 =TextureManager::LoadTexture("pic/bullet/bullet5.png" );
	bullet6 =TextureManager::LoadTexture("pic/bullet/bullet6.png" );
	bullet7 =TextureManager::LoadTexture("pic/bullet/bullet7.png" );
	bullet8 =TextureManager::LoadTexture("pic/bullet/bullet8.png" );
	bullet9 =TextureManager::LoadTexture("pic/bullet/bullet9.png" );
	bullet10=TextureManager::LoadTexture("pic/bullet/bullet10.png");
	bullet11=TextureManager::LoadTexture("pic/bullet/bullet11.png");
	bullet12=TextureManager::LoadTexture("pic/bullet/bullet12.png");
	bullet13=TextureManager::LoadTexture("pic/bullet/bullet13.png");
	bullet14=TextureManager::LoadTexture("pic/bullet/bullet14.png");
	bullet15 = TextureManager::LoadTexture("pic/bullet/bullet15.png");
	
	switch (bulletType)
	{
	case 1:
		SDL_QueryTexture(bullet1, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 2:
		SDL_QueryTexture(bullet2, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 3:
		SDL_QueryTexture(bullet3, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 4:
		SDL_QueryTexture(bullet4, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 5:
		SDL_QueryTexture(bullet5, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 6:
		SDL_QueryTexture(bullet6, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 7:
		SDL_QueryTexture(bullet7, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 8:
		SDL_QueryTexture(bullet8, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 9:
		SDL_QueryTexture(bullet9, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 10:
		SDL_QueryTexture(bullet10, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 11:
		SDL_QueryTexture(bullet11, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 12:
		SDL_QueryTexture(bullet12, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 13:
		SDL_QueryTexture(bullet13, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	case 14:
		SDL_QueryTexture(bullet14, NULL, NULL, &bulletWidth, &bulletHeight);
		break;
	default:
		break;
	}

	desRect.w = 20;
	desRect.h = (int )round((20.0*bulletHeight) / bulletWidth);
	//bullet start pos
	Xpos = Player::playerPosX + 30;
	desRect.x = Xpos;
	Ypos = Player::playerPosY +15;
	desRect.y = Ypos;
	//bullet point rotate 
	rotate.x = 10;
	rotate.y = (int)round((20.0*bulletHeight) / bulletWidth);
}


bullet::~bullet()
{
}
void bullet::Draw()
{
	if (distance()) {
		switch (bulletType)
		{
		case 1:
			SDL_RenderCopyEx(Game::renderer, bullet1, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 2:
			SDL_RenderCopyEx(Game::renderer, bullet2, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 3:
			SDL_RenderCopyEx(Game::renderer, bullet3, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 4:
			SDL_RenderCopyEx(Game::renderer, bullet4, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 5:
			SDL_RenderCopyEx(Game::renderer, bullet5, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 6:
			SDL_RenderCopyEx(Game::renderer, bullet6, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 7:
			SDL_RenderCopyEx(Game::renderer, bullet7, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 8:
			SDL_RenderCopyEx(Game::renderer, bullet8, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 9:
			SDL_RenderCopyEx(Game::renderer, bullet9, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 10:
			SDL_RenderCopyEx(Game::renderer, bullet10, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 11:
			SDL_RenderCopyEx(Game::renderer, bullet11, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 12:
			SDL_RenderCopyEx(Game::renderer, bullet12, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 13:
			SDL_RenderCopyEx(Game::renderer, bullet13, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		case 14:
			SDL_RenderCopyEx(Game::renderer, bullet14, NULL, &desRect, bulletAngle, &rotate, SDL_FLIP_NONE);
			break;
		default:
			break;
		}
	}
}
void bullet::Update()
{
		
		 if (bulletAngle == 0)
		{
			Yvelocity = bulletSpeed;
			Xvelocity = 0;
			Xvelocity = (int)round(Xvelocity);
			Yvelocity = (int)round(Yvelocity);
			Ypos -= (int)Yvelocity;
			Game::Ybullet[pos] -= Yvelocity;

		}
		else if (bulletAngle == 90)
		{
			Xvelocity = bulletSpeed;
			Yvelocity = 0;
			Xvelocity = (int)round(Xvelocity);
			Yvelocity = (int)round(Yvelocity);
			Xpos += (int)Xvelocity;
			Game::Xbullet[pos] += Xvelocity;
		}
		else if (bulletAngle == 180)
		{
			Xvelocity = 0;
			Yvelocity = bulletSpeed;
			Xvelocity = (int)round(Xvelocity);
			Yvelocity = (int)round(Yvelocity);
			Ypos += (int)Yvelocity;
			Game::Ybullet[pos] += Yvelocity;
		}
		else if (bulletAngle == 270)
		{
			Xvelocity = bulletSpeed;
			Yvelocity = 0;
			Xvelocity = (int)round(Xvelocity);
			Yvelocity = (int)round(Yvelocity);
			Xpos -= (int)Xvelocity;
			Game::Xbullet[pos] -= Xvelocity;
		}
		else if (bulletAngle == 360)
		{
			Xvelocity =0;
			Yvelocity = bulletSpeed;
			Xvelocity = (int)round(Xvelocity);
			Yvelocity = (int)round(Yvelocity);
			Ypos -= (int)Yvelocity;
			Game::Ybullet[pos] -= Yvelocity;
		}
	desRect.x = Xpos;
	desRect.y = Ypos;
}
bool bullet::distance()
{
	//700 is the map width and height 
return (Xpos >= 0 && Xpos <= 700 && Ypos >= 0 && Ypos <= 700);

}
