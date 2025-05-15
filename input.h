#pragma once

#include <SDL.h>
#include <unordered_map>

using namespace std;

class input
{
public:
	input();
	~input();

	bool goexit = false;

	// Métodos principales
	void Update();// precesar eventos SDL
	bool IsKeyPressed(SDL_Scancode key) const;
	bool IsKeyReleased(SDL_Scancode key) const;
	bool IsKeyHeld(SDL_Scancode key) const;

	void reset_states();

private:

	// Estado de las teclas
	bool currentKeyState;
	bool previousKeyState;

	//estado del bucle de las teclas
	bool end;

	// Métodos auxiliares
	void UpdateKeyboardState();
};

