#include "enemigos.h"
#include "jugador.h"
#include "mapa.h"
#include <queue>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

extern Mapa* mapa;

struct node {
	int x, y;
	float gcost, hcost;
	node* parent;

	node(int x, int y, float g = 0, float h = 0, node* p = nullptr)
		:x(x), y(y), gcost(g), hcost(h), parent(p){}

	float fcost() const {
		return gcost + hcost;
	}
	bool operator ==(const node& other) const {
		return x == other.x && y == other.y;
	}
};

struct compare
{
	bool operator()(node* a, node* b) {
		return a->fcost() > b->fcost();
	}
};

float heuristic(int x1, int y1, int x2, int y2)
{
	return abs(x1 - x2) + abs(y1 - y2);
}

Enemigos::Enemigos(int posX, int posY, int w, int h, int vel, int spriteID) :Entity(posX, posY, w, h, vel, spriteID)
{
	_estadoActual = moverse;
	vista = false;
}

Enemigos::~Enemigos()
{
}

void Enemigos::setState(stats estado, Jugador* player)
{
	if (estado == moverse)
	{
		
		if (!_camino.empty())
		{
			_camino.clear();
		}
		_camino = astar(mapa, GetPosX(), GetPosY(), player->GetPosX(), player->GetPosY());
		_estadoActual = estado;
	}
}

vector<pair<int, int>> astar(Mapa* mapa, int Sx, int Sy, int Ex, int Ey)
{
	priority_queue<node*, vector<node*>, compare> openSet;
	vector<vector<bool>>closedSet(mapa->Getheight(), vector<bool>(mapa->Getwidth(), false));
	openSet.push(new node(Sx, Sy, 0, heuristic(Sx, Sy, Ex, Ey)));

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	while (!openSet.empty())
	{
		node* current = openSet.top();
		openSet.pop();

		if (current->x == Ex && current->y == Ey) {
			vector<pair<int, int>> path;
			while (current) {
				path.push_back({ current->x, current->y });
				current = current->parent;
			}
			reverse(path.begin(), path.end());  // Reverse the path
			return path;
		}

		closedSet[current->y][current->x] = true;

		for (int i = 0; i < 4; ++i) {
			int nx = current->x + dx[i];
			int ny = current->y + dy[i];

			if (!mapa->isValid(nx, ny) || closedSet[ny][nx])
				continue;

			float g = current->gcost + 1;
			float h = heuristic(nx, ny, Ex, Ey);
			node* neighbor = new node(nx, ny, g, h, current);
			openSet.push(neighbor);
		}
	}
}

void Enemigos::init()
{
	_estadoActual = moverse;
	vista = false;
}

void Enemigos::update(Jugador* jug, Bombamanager* bm)
{
	switch (_estadoActual)
	{
	case stats::moverse:
		if (_camino[0].first == GetPosX() && _camino[0].second == GetPosY())
		{
			_camino.pop_back();
		}
		if (!_camino.empty())
		{
			if (_camino[0].first < GetPosX())
			{
				Move(Dir::LEFT);
			}
			else if (_camino[0].first > GetPosX())
			{
				Move(Dir::RIGHT);
			}
			else if (_camino[0].second < GetPosY())
			{
				Move(Dir::UP);
			}
			else if (_camino[0].second > GetPosY())
			{
				Move(Dir::DOWN);
			}
		}
		else
		{
			setState() = matar;
		}


		

	break;
	case stats::matar:
		if ((jug->GetPosX() >= GetPosX()) || (jug->GetPosX() <= GetPosX()) && (jug->GetPosY() >= GetPosY()) || (jug->GetPosY() <= GetPosY())) {
			cout << "die" << endl;
			_estadoActual = moverse;
		}
		
		break;
	
	default:
		break;
	}

	
}

