#include "window.h"
#include <time.h>
#include <stdbool.h>
const int FPS = 60;
const int GRIDSIZE = 100;
const int WIDTH = 1000;
const int HEIGHT = 1000;


void draw_points(App* app, int grid[100][100]);
void step_world(int grid[100][100], int next[100][100]);



int main(int argc, char* args[]){
    srand(time(NULL));
    int mousex,mousey;
    
        //int** grid = malloc(sizeof(int) * 100 * 100);
    int grid[100][100];
    int next[100][100];

    for (size_t x = 0; x < 100; x++)
    {
        for (size_t y = 0; y < 100; y++)
        {
            grid[x][y] = 0;
        }
        
    }
    App* app;
    app = init_app(app);
    const float dt = 1000.0 / FPS;
    
    int count = 0;
    int mousexc = 0;
    int mouseyc = 0;
    bool mousebuttondown = false;
    while (!app->quit) {
        while (SDL_PollEvent(&(app->E))) {
            if (app->E.type == SDL_QUIT) {
                app->quit = true;
            }
            if(app->E.type == SDL_MOUSEBUTTONDOWN){
                mousebuttondown = true;
                SDL_Log("Down");
            }
            if(app->E.type == SDL_MOUSEBUTTONUP){
                mousebuttondown = false;
                SDL_Log("Up");
            }
        }        
        
        if(mousebuttondown && count % 2 == 0){
            SDL_GetMouseState(&mousex, &mousey);

                mouseyc = mousey/10;
                mousexc = mousex/10;
                grid[mouseyc+1][mousexc] = 1;
                grid[mouseyc-1][mousexc] = 1;
                grid[mouseyc][mousexc+1] = 1;
                grid[mouseyc][mousexc-1] = 1;
            

        }
        count++;
        step_world(grid, next);
        SDL_RenderClear(app->renderer);
        draw_points(app, grid);
        SDL_RenderPresent(app->renderer);


        app->starting_tick = SDL_GetTicks();
        if (dt > SDL_GetTicks() - app->starting_tick) {
            SDL_Delay(dt - (SDL_GetTicks() - app->starting_tick));
        }
    }
    
    free_app(app);
    return 0;
}

void draw_points(App* app, int grid[100][100]) {
    SDL_Rect r;

    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if(grid[y][x] == 1){
                r.x = x*10;
                r.y = y*10;
                r.w = 10;  
                r.h = 10;

                SDL_SetRenderDrawColor(app->renderer, 200, 200, 0, 0);
                SDL_RenderFillRect(app->renderer, &r);
                SDL_SetRenderDrawColor(app->renderer, 0, 0, 0, 0);

            }else{
                SDL_SetRenderDrawColor(app->renderer, 0, 0, 100, 0);

            }
        
            
        }
    }
}


void step_world(int grid[100][100], int next[100][100]) {
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            next[y][x] = 0;
        }
    }

for (int y = 99; y > 0; y--) {
    for (int x = 0; x < 100; x++) {
        if (grid[y][x] == 1) {
            // Check if there is space below
            if (y < 99 && grid[y + 1][x] == 0) {
                next[y + 1][x] = 1;
                next[y][x] = 0;
            } else if (y < 99 && x > 0 && grid[y + 1][x - 1] == 0) {
                // Check if there is space below and to the left
                next[y + 1][x - 1] = 1;
            } else if (y < 99 && x < 99 && grid[y + 1][x + 1] == 0) {
                // Check if there is space below and to the right
                next[y + 1][x + 1] = 1;
                
            } else {
                next[y][x] = 1;
            }
        }
    }
}

    // Copy the result back to the original grid
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            grid[y][x] = next[y][x];
        }
    }
}