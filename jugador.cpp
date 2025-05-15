#include "jugador.h"
#include "mapa.h"






Jugador::Jugador(int posX, int posY, int w, int h, int vel, int spriteID):Entity(posX, posY, w, h, vel, spriteID)
{
	


}

Jugador::~Jugador()
{
}



void Jugador::update(Bombamanager* bm)//update
{
	SDL_Event keys;
	while (SDL_PollEvent(&keys))
	{
		switch (keys.type) {
		case SDL_KEYDOWN:
			if (keys.key.keysym.scancode == SDL_SCANCODE_RIGHT)
			{
				Move(Dir::RIGHT);
				
			}
			else if (keys.key.keysym.scancode == SDL_SCANCODE_LEFT)
			{
				Move(Dir::LEFT);
				
			}
			else if (keys.key.keysym.scancode == SDL_SCANCODE_UP)
			{
				Move(Dir::UP);
				
			}
			else if (keys.key.keysym.scancode == SDL_SCANCODE_DOWN)
			{
				Move(Dir::DOWN);
			}
			else if (keys.key.keysym.scancode == SDL_SCANCODE_SPACE)
			{
				bm->crearbombas(GetPosX(), GetPosY());
			}
		}
	}


}





