#pragma once
#include "entity.h"
#include "bombamanager.h"
#include <vector>


class Jugador;
class Mapa;
//idle
enum stats
{
	moverse, matar
};

class Enemigos:public Entity
{
private:
	
	bool vista;
	stats _estadoActual;
	//std::vector<std::pair<int, int>> _camino;

public:
	Enemigos(int posX, int posY, int w, int h, int vel, int spriteID);
	~Enemigos();

	//void setState(stats estado, Jugador* player);

	void init();
	void update(Jugador* jug, Bombamanager* bm);
	
	

};

