#pragma once
#include <vector>
#include "bomba.h"


class Enemigos;


class Bombamanager
{
public:
	Bombamanager(int spriteID);
	~Bombamanager();
	void crearbombas(int x, int y);
	void update(Enemigos* enemigo);
	void Render();
	
private:
	std::vector<Bomba*>bombas;
	int _spriteID;
};

