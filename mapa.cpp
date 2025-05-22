#include "mapa.h"
#include"Video.h"
#include <vector>
#include <iostream>
//#include "jugador.h"
#include "camara.h"

using namespace std;

extern Video* video;


Mapa::Mapa(void)
{
	 _width = 0;
	 _height = 0;
	 _tilewidth = 0;
	 _tileheight = 0;
	_source = "";

	//pillar capas

	
	_mmaps.resize(0);
	
}

Mapa::~Mapa(void)
{
}

void Mapa::render(int id, Camara* cam)
{
	int posheight = 0;
	int poswidth = 0;
	

	for (int i = 0; i < _mmaps.size(); i++)
	{
		for (int y = 0; y < _height; y++)//row
		{
			for (int x = 0; x < _width; x++)//col
			{
				if ((x * _tilewidth + _tilewidth) >= cam->GetposX() && (x * _tilewidth - _tilewidth) <= (cam->GetposX() + cam->GetWidth()) &&
					(y * _tileheight + _tileheight) >= cam->GetposY() && (y * _tileheight - _tileheight) <= (cam->GetposY() + cam->GetHeight()))
				{
					int PosY = (_mmaps.at(i)[y * _width + x] - 1) / 6;
					int PosX = (_mmaps.at(i)[y * _width + x] - 1) % 6;
					int TileX = PosX * (_tilewidth);
					int TileY = PosY * (_tileheight);

					poswidth = x * _tilewidth - cam->GetposX();
					posheight = y * _tileheight - cam->GetposY();

					video->renderGraphic(id, TileX, TileY, poswidth, posheight, _tilewidth, _tileheight);
				}
			}
			
		}
		
	}
}

void Mapa::AddNewValue(int valor, int capa)
{
	_mmaps.at(capa).push_back(valor);
}

int Mapa::getlogics(int col, int row, int capa) const
{
	return _mmaps.at(capa)[row * _width + col];
}

bool Mapa::isValid(int px, int py)
{
	return px >= 0 && py >= 0 && px < Getwidth() && py < Getheight() && checkcolision(px, py);
}

void Mapa::createLayer()
{
	_mmaps.push_back(vector<int>());
}
bool Mapa::checkcolision(int x, int y)
{
	int positionX = 0;
	int positionY = 0;
	
	positionX = x / _tilewidth;
	positionY = y / _tileheight;

	if (_mmaps.at(1)[positionY * _width + positionX] == 0)
	{
		return false;
	}


	return true;
}

// para hacer pruebas
/*
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
		{
			cout << _Mmaps.at(i * _width + j) << ",";
		}
		cout << "\n";
	}*/