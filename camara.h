#pragma once
#include <SDL.h>
#include"Video.h"


class Jugador;

class Camara
{

public:
	Camara();
	~Camara();

	void update(Jugador* jug);


	int GetWidth() { return _Width; };
	void SetWidth(int Width) { _Width = Width; };
	int GetHeight() { return _Height; };
	void SetHeight(int Height) { _Height = Height; };
	int GetposX() { return _posX; };
	void SetposX(int posX) { _posX = posX; };
	int GetposY() { return _posY; };
	void SetposY(int posY) { _posY = posY; };


private:
	int _Width = SCREEN_WIDTH;
	int _Height = SCREEN_HEIGHT;
	int _posX;
	int _posY;
	




};

