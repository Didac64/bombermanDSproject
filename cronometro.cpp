#include "Cronometro.h"

Cronometro::Cronometro()
{
}
Cronometro::~Cronometro()
{
}

void Cronometro::start() //init
{
	Timer = 0;
}

void Cronometro::Update()
{
	Timer++;
}

void Cronometro::reset()
{
	Timer = 0;
}

int Cronometro::time()
{
	return Timer;
}
