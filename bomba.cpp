#include "bomba.h"


Bomba::Bomba(int posX, int posY, int spriteID):Entity(posX, posY, 14, 15, 0, spriteID)
{
	_explota = false;
	_time = 0;
}
Bomba::~Bomba()
{
}

void Bomba::update()
{
	_time++;
	if (_time == 5000)
	{
		_explota = true;
	}
}
