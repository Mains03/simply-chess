#include <SDL2/SDL.h>
#include <stdio.h>

#include "texture.h"

int main() {
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    if (window != NULL) {
      renderer = SDL_CreateRenderer(window, -1, 0);
    } else {
      fprintf(stderr, "SDL error: %s\n", SDL_GetError());
      return -1;
    }
  } else {
    fprintf(stderr, "SDL error: %s\n", SDL_GetError());
    return -1;
  }

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

  int i = loadTexture("assets/chess_piece_2_white_king.png", renderer);

  SDL_RenderClear(renderer);

  drawTexture(i, 0, 0, 100, 100, renderer, SDL_FLIP_NONE);

  SDL_RenderPresent(renderer);

  SDL_Delay(5000);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return 0;
}
