#include "SDL.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int WIDTH = 1200, HEIGHT = 800;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window = SDL_CreateWindow("Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_WarpMouseInWindow(window, 50, 50);/*sets mouse position to 50, 50 relative to the window */


    SDL_RenderPresent(renderer);
    //ball



    //real ball
    SDL_Rect ball;
    ball.x = 600;
    ball.y = 360;
    ball.w = 40;
    ball.h = 40;

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &ball);

    SDL_Event windowEvent;

    const int TARGET_FPS = 280;
    const float FRAME_TIME = 1000.0f / TARGET_FPS;
    Uint32 frameStart;
    int frameTime;

    while (true)
    {
        int mouseX, mouseY;
        Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);

        frameStart = SDL_GetTicks();

        // Your code goes here
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &ball);
        // draw the updated square at position (200, 200)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderPresent(renderer);

        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < FRAME_TIME) {
            SDL_Delay((Uint32)(FRAME_TIME - frameTime));
        }
        

        
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
            switch (windowEvent.type) {
                /* Look for a keypress */
            case SDL_KEYDOWN:
                break;

            }
            switch (windowEvent.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (windowEvent.button.button == SDL_BUTTON_LEFT)
                {
                    const float current_pos[] = { mouseX, mouseY };
                    std::cout << current_pos[0] << std::endl;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                const float current_pos_sekond[] = { mouseX, mouseY };
                std::cout << current_pos_sekond[0] << std::endl;
                break;
            };
        }

    }

    // Don't forget to free your surface and texture
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

//int update_player_one_pos(SDL_Renderer* renderer, SDL_Rect square)
//{
//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//SDL_RenderFillRect(renderer, &ball);/
//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//SDL_RenderClear(renderer);
//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
////
//SDL_RenderPresent(renderer);
//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//SDL_RenderFillRect(renderer, &ball);
// draw the updated square at position (200, 200)
//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//SDL_RenderPresent(renderer);
//}
