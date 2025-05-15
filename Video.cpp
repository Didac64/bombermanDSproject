#include "Video.h"
#include "ResourceManager.h"
#include "SDL.h"
#include "SDL_image.h"

Video* Video::video = NULL;

Video::Video(void)
{
    gWindow = NULL;
    gRenderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    gWindow = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    gRenderer = SDL_CreateRenderer(gWindow, -1, 0);
    
    
}

Video::~Video(void)
{
}

void Video::renderGraphic(int img, int posX, int posY, int auxX, int auxY, int width, int height)
{
    SDL_Rect r, rectAux;
    r.h = height;
    r.w = width;
    r.x = posX;
    r.y = posY;

    rectAux.h = height;
    rectAux.w = width;
    rectAux.x = auxX;
    rectAux.y = auxY;

    SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);
    SDL_RenderCopy(gRenderer, origin, &r, &rectAux);

}

void Video::clearScreen()
{
    SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(gRenderer);
}

void Video::updateScreen()
{


    SDL_RenderPresent(gRenderer);
}

void Video::waitTime(int ms)
{
    SDL_Delay(ms);
}

void Video::close()
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}

