#pragma once
#include"entity.h"

class Enemigos:public Entity
{
private:
	enum stats
	{
		Vigilar, Cambiar,
		Alerta, Ataque, choque, salto
	};
	bool vista;
	stats _estadoActual;


public:
	Enemigos(int posX, int posY, int w, int h, int vel, int spriteID);
	~Enemigos();

	void init();
	void update();
	//void CambioDeEstado(stats Cambiar);
	void estadoVigilar();
	void estadoCambiar();
	void estadoAlerta();
	void estadoAtaque();
	void estadoChoque();
	void estadoSalto();

	//enemy

	

};

