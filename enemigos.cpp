#include "enemigos.h"


Enemigos::Enemigos(int posX, int posY, int w, int h, int vel, int spriteID) :Entity(posX, posY, w, h, vel, spriteID)
{
	_estadoActual = Vigilar;
	vista = false;
}

Enemigos::~Enemigos()
{
}

void Enemigos::init()
{
	_estadoActual = Vigilar;
	vista = false;
}

void Enemigos::update()
{
	switch (_estadoActual)
	{
	case Enemigos::Vigilar:
		break;
	case Enemigos::Cambiar:
		break;
	case Enemigos::Alerta:
		break;
	case Enemigos::Ataque:
		break;
	case Enemigos::choque:
		break;
	case Enemigos::salto:
		break;
	default:
		break;
	}
}



void Enemigos::estadoVigilar()
{
}

void Enemigos::estadoCambiar()
{
}

void Enemigos::estadoAlerta()
{
}

void Enemigos::estadoAtaque()
{
}

void Enemigos::estadoChoque()
{
}

void Enemigos::estadoSalto()
{
}

/*void enemigos::CambioDeEstado(stats Cambiar)
{
}*/
