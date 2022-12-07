#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <SDL2/SDL.h>

void initTextureMap();

// returns the id >= 0 assigned to the texture
// -1 if failed
int loadTexture(char* fileName, SDL_Renderer* renderer);

void drawTexture(int id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip);

#endif
