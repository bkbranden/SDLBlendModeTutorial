// #include <SDL2/SDL.h>
// #include <stdio.h>

// const int SCREEN_WIDTH = 640;
// const int SCREEN_HEIGHT = 480;

// int main(int argc, char* args[]) {
//     // Window we are rendering to
//     SDL_Window * window = NULL;

//     // The surface contained by the window
//     SDL_Surface * screenSurface = NULL;

//     // Initialize SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
//     }
//     else{
//         // Create Window
//         window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
//         if (window == NULL) {
//             printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
//         }
//         else {
//             // Get Window Surface
//             screenSurface = SDL_GetWindowSurface(window);

//             // Fill the surface white
//             SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface -> format, 0xFF, 0xFF, 0xFF));

//             // Update the surface
//             SDL_UpdateWindowSurface(window);

//             bool is_running = true;
// 			SDL_Event event;
// 			while (is_running) {
// 				while (SDL_PollEvent(&event)) {
// 					if (event.type == SDL_QUIT) {
// 						is_running = false;
// 					}
// 				}
// 				SDL_Delay(16);
// 			}
//         }
//     }

//     SDL_DestroyWindow(window);

//     SDL_Quit();

//     return 0;
// }