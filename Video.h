#pragma once

#define SCREEN_WIDTH 860
#define SCREEN_HEIGHT 540

#include "ResourceManager.h"

class Video
{
private:
    Video(void);
    static Video* video;

public:
   
    ~Video(void);
    static Video* getInstance()
    {
        if (video == NULL)
            video = new Video();
        return video;
    }


    void renderGraphic(int img, int posX, int posY, int auxX, int auxY, int width, int height);
    void clearScreen();
    void updateScreen();
    void waitTime(int ms);
    void close();

    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
};
