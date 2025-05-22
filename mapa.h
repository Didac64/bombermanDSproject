#pragma once
#include <string>
#include <vector>


using namespace std;

class Camara;


class Mapa
{
public:
	Mapa(void);
	~Mapa(void);

	void render(int id, Camara* cam);

	//colision

	bool checkcolision(int x, int y);

	//---
	
	int Getwidth() { return _width; };
	void Setwidth(int width) { _width = width; };
	int Getheight() { return _height; };
	void Setheight(int height) { _height = height; };
	int Gettilewidth() { return _tilewidth; };
	void Settilewidth(int widthTile) { _tilewidth = widthTile; };
	int Gettileheight() { return _tileheight; };
	void Settileheight(int heightTile) { _tileheight = heightTile; };
	string Gesource() { return _source; };
	void Setsource(string source) { _source = source; };

	void AddNewValue(int valor, int capa);
	int getlogics(int col, int row, int capa)const;
	bool isValid(int px, int py);
	void createLayer();
	

private:

	int _width;
	int _height;
	int _tilewidth;
	int _tileheight;
	string _source;
	bool pared;
	
	vector<vector<int>> _mmaps;
	
	
};
