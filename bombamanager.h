#pragma once
#include <vector>
#include "bomba.h"




class Bombamanager
{
public:
	Bombamanager(int spriteID);
	~Bombamanager();
	void crearbombas(int x, int y);
	void update();
	void Render();
	
private:
	std::vector<Bomba*>bombas;
	int _spriteID;
};

