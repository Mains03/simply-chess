#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

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

  SDL_Surface* image = IMG_Load("assets/chess_piece_2_white_king.png");

  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);

  SDL_RenderClear(renderer);

  SDL_RenderCopy(renderer, texture, NULL, NULL); 

  SDL_RenderPresent(renderer);

  SDL_Delay(5000);

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

  return 0;
}
