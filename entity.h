#pragma once

enum Dir {UP, DOWN, LEFT, RIGHT};

class Entity
{
public:
	Entity(int posX, int posY, int w, int h, int vel, int spriteID);
	~Entity();

	void Render();
	void Move(Dir newDir);

	int GetWidth() { return _w; };
	int GetHeight() { return _h; };
	int GetPosX() { return _posX; };
	void SetPosX(int posX) { _posX = posX; };
	int GetPosY() { return _posY; };
	void SetPosY(int posY) { _posY = posY; };
	int GetVel() { return _vel; };
	int GetSpriteid() { return _spriteID; };

private:
	int _w;
	int _h;
	int _posX;
	int _posY;
	int _vel;
	int _spriteID;
};

