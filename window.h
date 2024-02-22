#ifndef WINDOW_H
#define WINDOW_H
#include <SDL2/SDL.h>
#include <stdbool.h>


typedef struct{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event E;
    bool quit;
    int starting_tick;
} App;

App* init_app(App* app);
void free_app(App* app);

#endif

/*

Grunden i main.c

App* app;
    app = init_app(app);
    const float dt = 1000.0 / FPS;

    while (!app->quit) {
        while (SDL_PollEvent(&(app->E))) {
            if (app->E.type == SDL_QUIT) {
                app->quit = true;
            }
        }

        // Your game logic goes here if applicable

        // Update the window or renderer here if needed

        app->starting_tick = SDL_GetTicks();
        if (dt > SDL_GetTicks() - app->starting_tick) {
            SDL_Delay(dt - (SDL_GetTicks() - app->starting_tick));
        }
    }
    free_app(app);

*/