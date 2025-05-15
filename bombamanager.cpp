#include "bombamanager.h"


Bombamanager::Bombamanager(int spriteID)
{
	_spriteID = spriteID;
}
Bombamanager::~Bombamanager()
{
}
void Bombamanager::crearbombas(int x, int y)
{
	bombas.push_back(new Bomba(x, y, _spriteID));
}

void Bombamanager::update()
{
	for (int i = 0; i < bombas.size(); i++)
	{
		bombas[i]->update();
	}
	auto item = bombas.begin();
	while (item != bombas.end())
	{
		if ((*item)->GetExplota())
		{
			item = bombas.erase(item);
		}
		else
		{
			item++;
		}
	}
}

void Bombamanager::Render()
{
	for (int i = 0; i < bombas.size(); i++)
	{
		bombas[i]->Render();
	}

}
