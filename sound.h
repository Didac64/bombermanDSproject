#pragma once
#include<string>
#include <SDL_mixer.h>
//SDL_Mixer treballa el so per chunks. Un chunk es una struct:

//typedef struct Mix_Chunk {
//	int allocated;
//	Uint8* abuf;
//	Uint32 alen;
//	Uint8 volume; /* Per-sample volume, 0-128 */
//} Mix_Chunk;

class Sound
{
protected:
	Sound(void);
private:
	static Sound* p_instance;
public:
	~Sound(void);
	static Sound* getInstance()
	{
		if (p_instance == nullptr)
			p_instance = new Sound();

		return p_instance;

		
	}

	

	void InitAudio();
	void playAudio(Sint32 SID);
	void CloseAudio();
	void freeAudio(Sint32 SID);

	Mix_Chunk* LoadAudio(std::string sound_path);

};

