#include "ResourceManager.h"
#include<string>
#include<iostream>
#include "SDL.h"
#include "SDL_render.h"
#include"SDL_image.h"
#include"SDL_mixer.h"
#include"video.h";
#include"sound.h"

using namespace std;


ResourceManager::~ResourceManager()
{
}

void ResourceManager::removeGraphic(const char* file)
{
	std::map<std::string, Sint32>::iterator it = mIDMap.find(file);
	if (mIDMap.find(file) == mIDMap.end())
	{
		
		SDL_DestroyTexture (mGraphicsVector[it->second]);
		mGraphicsVector[it->second] = nullptr;
	}
}

Sint32 ResourceManager::loadAndGetGraphicID(const char* file)
{
	
	int ret = 0;
	std::map<std::string, Sint32>::iterator it = mIDMap.find(file);
	if (mIDMap.find(file) == mIDMap.end())
	{
		ret = addGraphic(file);
	
		if (ret != -1)
		{
			mIDMap.insert(std::pair<std::string, Sint32>(file,ret));
		}
		return ret;
	}
	
	return it ->second;
}
std::string ResourceManager::getGraphicPathByID(Sint32 ID)
{
	for (auto it = mIDMap.begin(); it != mIDMap.end(); it++)
	{
		if (it->second == ID) 
		{
			return it->first;
		}
	}
	return "NULL";
}

void ResourceManager::getGraphicSize(Sint32 img, int& width, int& height)
{
	if (img >= -1 && img <= mGraphicsVector.size() - 1)
	{
		SDL_QueryTexture(mGraphicsVector[img], NULL, NULL, &width, &height);
	}
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
	int w;
	SDL_QueryTexture(mGraphicsVector[img], NULL, NULL, &w, NULL);
	return w;
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
	int h;
	SDL_QueryTexture(mGraphicsVector[img], NULL, NULL, NULL, &h);
	return h;
}

SDL_Texture* ResourceManager::getGraphicByID(Sint32 ID)
{
	return mGraphicsVector[ID];
}

void ResourceManager::setAlphaGraphic(Sint32 ID, Uint8 alpha_value)
{
}

void ResourceManager::printLoadedGraphics()
{
}

Sint32 ResourceManager::createGraphic(const char* name, Uint16 width, Uint16 height)
{

	return Sint32();
}
//static ResourceManager* getInstance() act1
ResourceManager* ResourceManager::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new ResourceManager();
		
	}
		return pInstance;
}
ResourceManager* ResourceManager::pInstance = NULL;
//fin act 1

ResourceManager::ResourceManager()
{
	
}

Sint32 ResourceManager::addGraphic(const char* file)
{
	Video* video = Video::getInstance();
	
		
	SDL_Surface* img = IMG_Load(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(video->gRenderer, img);
	SDL_FreeSurface(img);

		if (img == NULL)
	{
		SDL_GetError();
		return -1;
	}
	else
	{
		mGraphicsVector.push_back(texture);
		return mGraphicsVector.size()-1;
	}
	
}

//sounds

Sint32 ResourceManager::addSound(const char* file)
{

	Sound* sounds = Sound::getInstance();
	Mix_Chunk* sonido = sounds->LoadAudio(file);
	
	if (!sonido)
	{
		cout << "sound [error]:" << Mix_GetError() << endl;
		return -1;
	}
	else
	{
		mSoundsVector.push_back(sonido);
		return mSoundsVector.size();
	}
	
}

std::string ResourceManager::getSoundPathByID(Sint32 ID)
{
	for (auto sus = mIDsound.begin(); sus!=mIDsound.end(); sus++)
	{
		if (sus->second == ID)
		{
			return sus->first;
		}
	}
	return "NULL";
}

Mix_Chunk* ResourceManager::getSoundByID(Sint32 ID)
{
	if (ID >= 0 && ID < mSoundsVector.size()) {
		return mSoundsVector[ID];
	}
}

Sint32 ResourceManager::loadAndGetSoundID(const char* file)
{
	int slag = 0;
	map<string, Sint32>::iterator sus = mIDsound.find(file);
	if (sus == mIDsound.end())
	{
		slag = addSound(file);
		if (slag != -1)
		{
			mIDsound.insert(pair<string, Sint32>(file, slag));
		}
		return slag;
	}
	return sus->second;
}

void ResourceManager::ReleaseSoundName(const char* file)
{
	int Realised = 0;
	map<string, Sint32>::iterator sus = mIDsound.find(file);
	if (sus != mIDsound.end())
	{
		removeSounds(file);
		mIDsound.erase(sus);
		mSoundsVector.at(sus->second) = nullptr;
		

	}
}

void ResourceManager::removeSounds(const char* file)
{
	map<string, Sint32>::iterator sus = mIDsound.find(file);
	if (sus != mIDsound.end())
	{
		Sound::getInstance()->freeAudio(sus->second);
		mSoundsVector[sus->second] = nullptr;
	}
}

Uint32 ResourceManager::updateFirstFreeSlotSound()
{
	for (size_t i = 0; i < mSoundsVector.size(); i++)
	{
		if (mSoundsVector[i] == nullptr)
		{
			return i;
		}
	}
	return mSoundsVector.size();
}

Uint32 ResourceManager::updateFirstFreeSlotGraphic()
{
	return Uint32();
}



//int ret = 0;
//std::map<std::string, Sint32>::iterator it = mIDMap.find(file);
//if (mIDMap.find(file) == mIDMap.end())
//{
//	ret = addGraphic(file);
//
//	if (ret != -1)
//	{
//		mIDMap.insert(std::pair<std::string, Sint32>(file, ret));
//	}
//	return ret;
//}
//
//return it->second

