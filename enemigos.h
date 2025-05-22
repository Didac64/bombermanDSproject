#pragma once
#include "entity.h"
#include "bombamanager.h"


class Jugador;
class Mapa;

enum stats
{
	moverse, matar
};

class Enemigos:public Entity
{
private:
	
	bool vista;
	stats _estadoActual;
	vector<pair<int, int>> _camino;

public:
	Enemigos(int posX, int posY, int w, int h, int vel, int spriteID);
	~Enemigos();

	void setState(stats estado, Jugador* player);

	void init();
	void update(Jugador* jug, Bombamanager* bm);
	
	

};

