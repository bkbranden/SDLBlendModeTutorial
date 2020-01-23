#include "SDL2/SDL.h"
#include <stdio.h>

const int SCREEN_WIDTH = 680;
const int SCREEN_HEIGHT = 480;

bool init();

bool loadMedia();

void close();

// The window we are rendering to
SDL_Window * gWindow = NULL;

// The surface contained by the window
SDL_Surface * gScreenSurface = NULL;

// The image we will load and show on the screen
SDL_Surface * gHelloWorld = NULL;

bool init() {
    // Initialization flag
    bool success = true;

    // InitializeSDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
        success = false;
    }
    else{
        // Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL){
            printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
            success = false;
        }   
        else {
            // Get Window Surface
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

bool loadMedia(){
    // Loading success flag
    bool success = true;

    // Load splash image
    gHelloWorld = SDL_LoadBMP("./src/02_imageonscreen/hello_world.bmp");
    if (gHelloWorld == NULL){
        printf("Unable to load image %s. SDL Error: %s\n", "./src/02_imageonscreen/hello_world.bmp", SDL_GetError());
        success = false;
    }

    return success;
}

void close(){
    // Deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    // Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    // Quit SDL subsystem
    SDL_Quit();
}

int main(int argc, char* argsp[]){

    if (!init()){
        printf("Failed to initialize.\n");
    }
    else{
        // Load media
        if(!loadMedia()){
            printf("Failed to load media.\n");
        }
        else{
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        }

        // Update the surface
        SDL_UpdateWindowSurface(gWindow);
        
        // Loop to keep the window visible
        bool is_running = true;
        SDL_Event event;
        while (is_running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    is_running = false;
                }
            }
            SDL_Delay(16);
        }
    }

    // Free resources and close SDL
    close();

    return 0;
}