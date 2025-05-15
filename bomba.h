#pragma once
#include"entity.h"


class Bomba :public Entity
	//tamaño bomba w14 h15
{
public:
	Bomba(int posX, int posY, int spriteID);
	~Bomba();

	bool GetExplota() const { return _explota; };

	void update();

private:
	bool _explota;
	int _time;
};

