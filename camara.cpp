#include "camara.h"
#include "jugador.h"

Camara::Camara()
{
	_posX = 0;
	_posY = 0;
}

Camara::~Camara()
{
}



void Camara::update(Jugador* jug)//update
{
	_posX = jug->GetPosX() + GetWidth() / 2;
	_posY = jug->GetPosY() + GetHeight() / 2;
}
