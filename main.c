#include <SDL2/SDL.h>
 
int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        perror("SDL failed to initialize\n");
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);

    if (window == NULL) {
        perror("window creation failed\n");
        exit(1);
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if (window_surface == NULL) {
        perror("getting surface from window failed\n");
        exit(1);
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    // SDL_Quit();
 
    // return 0;
}