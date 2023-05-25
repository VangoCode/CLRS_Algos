#include <SDL2/SDL.h>
#include "./DynamicArray/dynamic_table.c"
 
int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        perror("SDL failed to initialize\n");
        exit(1);
    }

    SDL_Window *window = SDL_CreateWindow("Ron's Algo Visualizer C",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          640, 480,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL) {
        perror("window creation failed\n");
        exit(1);
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


    // value to check if the window has been closed
    int is_running = 1;
    SDL_Event event;

    // DYNAMIC TABLE TEST
    DynamicTable *dynamic_table;
    dynamic_table = malloc(sizeof(DynamicTable));
    initialize_table(dynamic_table);
    append_to_table(dynamic_table, 1);
    append_to_table(dynamic_table, 2);
    append_to_table(dynamic_table, 3);
    print_table(dynamic_table);

    while (is_running == 1) {
        while (SDL_PollEvent(&event) != 0) {
            // there is something in the event queue
            if (event.type == SDL_QUIT) {
                is_running = 0;
            }

            SDL_UpdateWindowSurface(window);
        }

        // test loop
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 1; i < dynamic_table->num_elements + 1; i++) {
            SDL_Rect rect = {(i - 1) * 100, 100, 100, 100};
            SDL_RenderDrawRect(renderer, &rect);
        }
        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    }


    // SDL_Delay(5000);

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_Quit();
 
    return 0;
}