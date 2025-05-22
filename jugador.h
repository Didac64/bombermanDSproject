#pragma once
#include <SDL.h>
#include"Video.h"
#include"entity.h"
#include "bombamanager.h"


class Jugador:public Entity
{
public:
	Jugador(int posX, int posY, int w, int h, int vel, int spriteID);
	~Jugador();

	void update(Bombamanager* bm);
	




private:

};

