#pragma once
class Cronometro
{
	Cronometro();
	~Cronometro();

	void start();
	void Update();
	void reset();
	int time();
private:
	int Timer;
};

