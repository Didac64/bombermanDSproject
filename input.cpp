#include "input.h"

input::input()
{
	//inicia limpiando el estado de las teclas
	currentKeyState.clear();
	previousKeyState.clear();
	end = false;
}

input::~input()
{
}

void input::Update()
{
	while (!end)
	{
		previousKeyState = currentKeyState;

		SDL_Event inputs;
		while (SDL_PollEvent(&inputs))
		{
			switch (inputs.type) 
			{
				case SDL_KEYDOWN:
					if (inputs.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						goexit = true;
					}
					if (!inputs.key.repeat) 
					{
						currentKeyState[inputs.key.keysym.scancode] = true;
					}
					break;
				case SDL_KEYUP:
					currentKeyState[inputs.key.keysym.scancode] = false;
					break;
				case SDL_QUIT:
					end = true;
			}

		}
	}
}

bool input::IsKeyPressed(SDL_Scancode key) const
{ //de esta forma no
	return currentKeyState.count(key) && currentKeyState.at(key) &&
		(!previousKeyState.count(key) && !previousKeyState.at(key));
}

bool input::IsKeyReleased(SDL_Scancode key) const
{ //de esta forma no
	return currentKeyState.count(key) && !currentKeyState.at(key) &&
		(previousKeyState.count(key) && previousKeyState.at(key));
}

bool input::IsKeyHeld(SDL_Scancode key) const
{ //de esta forma no
	return currentKeyState.count(key) && currentKeyState.at(key);
}



void input::reset_states()
{
	previousKeyState.clear();
	currentKeyState.clear();
}

void input::UpdateKeyboardState()
{
}
