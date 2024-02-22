#include "window.h"

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

App* init_app(App* app){
    app = malloc(sizeof(App));
    app->window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    app->renderer = SDL_CreateRenderer(app->window, -1, 0);
    app->starting_tick = 0;
    app->quit = false;
    SDL_Init(SDL_INIT_EVERYTHING);
    return app;
}
void free_app(App* app){
    SDL_DestroyRenderer(app->renderer);
    SDL_DestroyWindow(app->window);
    SDL_Quit();
    free(app);
}