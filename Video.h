#pragma once

#define SCREEN_WIDTH 860
#define SCREEN_HEIGHT 540

#include "ResourceManager.h"
#include <SDL_ttf.h>

class Video
{
private:
    Video(void);
    static Video* video;
    TTF_Font* font;

public:
   
    ~Video(void);
    bool init(); // Nueva función de inicialización
    void drawText(const std::string& message, int x, int y, SDL_Color color);
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
