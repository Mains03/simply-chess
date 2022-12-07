#include "texture.h"

#include <SDL2/SDL_image.h>

#include <stdlib.h>

SDL_Texture** textureMap = NULL;
int textureMapSize = 0;
int textureMapIndex = 0;

int loadTexture(char* fileName, SDL_Renderer* renderer) {
  SDL_Surface* surface = IMG_Load(fileName);
  if (surface == NULL) {
    return -1;
  }

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

  SDL_FreeSurface(surface);
  if (texture == NULL) {
    return -1;
  }

  if (textureMap == NULL) {
    textureMap = malloc(1 * sizeof(*textureMap));
    textureMapSize = 1;
  }

  if (textureMapIndex == textureMapSize) {
    textureMapSize *= 2;
    textureMap = realloc(textureMap, textureMapSize * sizeof(*textureMap));
  }

  textureMap[textureMapIndex++] = texture;
  return (textureMapIndex-1);
}

void drawTexture(int id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip) {
  if (0 <= id && id < textureMapIndex) {
    SDL_Rect srcRect, dstRect;

    srcRect.x = srcRect.y = 0;
    srcRect.w = dstRect.w = width;
    srcRect.h = dstRect.h = height;
    dstRect.x = x;
    dstRect.y = y;

    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect, 0, 0, flip);
  }
}
