#include "sound.h"
#include"SDL.h"
#include <iostream>
#include"ResourceManager.h"


using namespace std;

Sound* Sound::p_instance = NULL;
Sound::Sound(void)
{
	int error = SDL_InitSubSystem(SDL_INIT_AUDIO);
	if (error != 0)
	{
		cout << "mixer no puede iniciarse: " << Mix_GetError() << endl;
	}
}
Sound::~Sound(void)
{

}

void Sound::InitAudio()
{
	//iniciar el audio mixer
	SDL_InitSubSystem(SDL_INIT_AUDIO);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	//asignar cuantos canales vamos a utilizar
	Mix_AllocateChannels(128);
}

void Sound::playAudio(Sint32 SID)
{
	ResourceManager* rm = ResourceManager::getInstance();
	Mix_Chunk* sonidoP = rm->getSoundByID(SID);
	Mix_PlayChannel(1, sonidoP, 0);
}

Mix_Chunk* Sound::LoadAudio(std::string sound_path)
{
	//cargar los audios de mixer
	
	Mix_Chunk* sound = Mix_LoadWAV(sound_path.c_str());
	if (!sound)
	{
		std::cout << "mixer [error]:" << Mix_GetError() << endl;
		return NULL;
	}

	return sound;
	
	
	//Mix_Chunk* sound = Mix_LoadWAV("sounds/victory.wav");
	
	//Mix_VolumeChunk: cambiar volumen
	//Mix_VolumeChunk: liberar el chunk
}
void Sound::CloseAudio()
{
	//cierra el audio mixer
	Mix_CloseAudio();
}

void Sound::freeAudio(Sint32 SID)
{
	ResourceManager* rm = ResourceManager::getInstance();
	Mix_Chunk* sonidoP = rm->getSoundByID(SID);
	Mix_FreeChunk(sonidoP);
}



