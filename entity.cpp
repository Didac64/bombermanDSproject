#include "entity.h"
#include"Video.h"
#include "mapa.h"
#include "bomba.h"




extern Mapa* mapa;
extern Video* video;


Entity::Entity(int posX, int posY, int w, int h, int vel, int spriteID)
{
	_posX = posX;
	_posY = posY;
	_w = w;
	_h = h;
	_vel = vel;
	_spriteID = spriteID;
	_life = true;
}

Entity::~Entity()
{
}
void Entity::Render()
{
	video->renderGraphic(_spriteID, 0, 0, _posX, _posY, _w, _h);

}

void Entity::Move(Dir newDir)
{
	if (newDir == RIGHT)
	{
		if (!mapa->checkcolision(GetPosX() + GetWidth() + GetVel(), GetPosY()) && !mapa->checkcolision(GetPosX() + GetWidth() + GetVel(), GetPosY() + GetHeight()))
		{
			SetPosX(GetPosX() + GetVel());
		}

	}
	else if (newDir == LEFT)
	{
		if (!mapa->checkcolision(GetPosX() - GetVel(), GetPosY()) && !mapa->checkcolision(GetPosX() - GetVel(), GetPosY() + GetHeight()))
		{
			SetPosX(GetPosX() - GetVel());
		}

	}
	else if (newDir == UP)
	{
		if (!mapa->checkcolision(GetPosX(), GetPosY() - GetVel()) && !mapa->checkcolision(GetPosX() + GetWidth(), GetPosY() - GetVel()))
		{
			SetPosY(GetPosY() - GetVel());
		}

	}
	else if (newDir == DOWN)
	{
		if (!mapa->checkcolision(GetPosX(), GetPosY() + GetHeight() + GetVel()) && !mapa->checkcolision(GetPosX() + GetWidth(), GetPosY() + GetHeight() + GetVel()))
		{
			SetPosY(GetPosY() + GetVel());
		}

	}
}



