#include <iostream>
#include "ResourceManager.h"
#include "Video.h"
#include "sound.h"
//#include "input.h"  
#include <string>
#include "tileset.h"
#include "mapa.h"
#include "SDL_mixer.h"
#include "tinyxml2.h"
#include "jugador.h"
#include "camara.h"
#include"enemigos.h"
#include "bomba.h"
#include "bombamanager.h"
#include "entity.h"




using namespace std;
ResourceManager* rm = ResourceManager::getInstance();
Video* video = Video::getInstance();
Mapa* mapa = new Mapa();
Camara* camara = new Camara();





int main(int argc, char* args[])
{
	


	 

	//tailsets & maps
	vector<int>tileVector;
	tileVector.resize(0);

	tinyxml2::XMLDocument doc;
	//error
	if (doc.LoadFile("nivel.tmx") != tinyxml2::XML_SUCCESS)
	{
		cout << "Error XML: " << doc.ErrorStr();
		return 1;
	}
	//load tilset.png
	int TILEMAP = rm->loadAndGetGraphicID("mapa.png");
	int player = rm->loadAndGetGraphicID("playerUSE.png");
	int enemy = rm->loadAndGetGraphicID("enemigoUSE.png");
	int bomb = rm->loadAndGetGraphicID("bomba.png");

	Jugador* jugador = new Jugador(48, 36, 18, 29, 6, player);
	Enemigos* enemigo = new Enemigos(208, 37, 18, 29, 1, enemy);
	Bombamanager* bombasManager = new Bombamanager(bomb);
	tinyxml2::XMLElement* map = doc.FirstChildElement("map");
	//Agafar etiqueta
	cout << "maps: " << endl;
	cout << "width: " << map->Attribute("width") << endl;
	cout << "height: " << map->Attribute("height") << endl;
	cout << "tilewidth: " << map->Attribute("tilewidth") << endl;
	cout << "tileheight: " << map->Attribute("tileheight") << endl;
	//-------------variables
	mapa->Setwidth(stoi(map->Attribute("width")));
	mapa->Settilewidth(stoi(map->Attribute("tilewidth")));
	mapa->Settileheight(stoi(map->Attribute("tileheight")));
	mapa->Setheight(stoi(map->Attribute("height")));
	//-------------
	tinyxml2::XMLElement* tileset = map->FirstChildElement("tileset");
	//Agafar etiqueta
	cout << "tilemap: " << endl;
	cout << "source: " << tileset->Attribute("source") << endl;
	//-------------variables
	mapa->Setsource((tileset->Attribute("source")));
	//-------------
	cout << "layer" << endl;
	tinyxml2::XMLElement* layer = map->FirstChildElement("layer");
	int numCapa = 0;
	//-------------


	while (layer != NULL)
	{
		mapa->createLayer();
		string textmap;
		textmap = layer->FirstChildElement("data")->GetText();
		cout << "data" << endl;
		int PosI = 0;
		int PosSeguent = 0;
		int br;
		while (PosSeguent != string::npos)
		{
			PosSeguent = textmap.find(',', PosI);
			br = textmap.find("\n", PosI);
			if (PosSeguent != string::npos)
			{
				int valor = stoi(textmap.substr(PosI, PosSeguent - PosI));
				mapa->AddNewValue(valor, numCapa);
				PosI = PosSeguent + 1;
			}
			else
			{
				int valor = stoi(textmap.substr(PosI, textmap.size() - PosI));
				mapa->AddNewValue(valor, numCapa);
			}
		}
		layer = layer->NextSiblingElement("layer");
		numCapa++;
	}
	//scroll
	int ScrollPosX = 0;
	int ScrollVelocidad = 4;
	

	bool quit = false;
	while (quit == false)
	{
		if (jugador->GetStateLife() == true)
		{
			video->waitTime(16);
			video->clearScreen();

			jugador->update(bombasManager);
			enemigo->update(jugador, bombasManager);
			bombasManager->update(enemigo);

			mapa->render(TILEMAP, camara);
			enemigo->Render();
			jugador->Render();
			bombasManager->Render();

			video->updateScreen();
		}

		// ?? jugador murió
		else if (jugador->GetStateLife() == false) {
			std::cout << "GAME OVER" << std::endl;
			video->clearScreen();

			// Mostrar texto "Game Over"
			TTF_Font* font = TTF_OpenFont("level/Roboto_Condensed-Bold.ttf", 48);
			SDL_Color white = { 255, 255, 255 };
			SDL_Surface* surface = TTF_RenderText_Solid(font, "GAME OVER", white);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(video->gRenderer, surface);

			SDL_Rect rect = { SCREEN_WIDTH / 2 - surface->w / 2, SCREEN_HEIGHT / 2 - surface->h / 2, surface->w, surface->h };
			SDL_RenderCopy(video->gRenderer, texture, NULL, &rect);
			SDL_RenderPresent(video->gRenderer);

			SDL_FreeSurface(surface);
			TTF_CloseFont(font);
			SDL_Delay(5000);  // mostrar 5 segundos
			break;
		}
		else if (enemigo->GetStateLife() == false) {
			std::cout << "¡Victoria!" << std::endl;

			video->clearScreen();

			// Mostrar texto "You Win!"
			TTF_Font* font = TTF_OpenFont("level/Roboto_Condensed-Bold.ttf", 48);
			SDL_Color white = { 255, 255, 255 };
			SDL_Surface* surface = TTF_RenderText_Solid(font, "¡VICTORIA!", white);
			SDL_Texture* texture = SDL_CreateTextureFromSurface(video->gRenderer, surface);

			SDL_Rect rect = {
				SCREEN_WIDTH / 2 - surface->w / 2,
				SCREEN_HEIGHT / 2 - surface->h / 2,
				surface->w,
				surface->h
			};
			SDL_RenderCopy(video->gRenderer, texture, NULL, &rect);
			SDL_RenderPresent(video->gRenderer);

			SDL_FreeSurface(surface);
			TTF_CloseFont(font);
			SDL_Delay(3000);  // esperar 3 segundos
			quit = true;
		}

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				{
					quit = true;
				}
			}
		}
	}
	return 0;
}