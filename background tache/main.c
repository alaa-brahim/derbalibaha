#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "background.h"

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG);
    int multiplayer = 0;
TTF_Init();

    SDL_Surface* screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

printf("Choose mode:\n1. Single Player\n2. Multiplayer\n> ");
scanf("%d", &multiplayer);  // multiplayer will be 1 or 2
    Background bg1, bg2;
   if (multiplayer == 2) {
    // Multiplayer: split screen
    initBackground(&bg1, "bg.jpg", 1280 / 2, 720);
    initBackground(&bg2, "bg.jpg", 1280 / 2, 720);
} else {
    // Single player: full screen
    initBackground(&bg1, "bg.jpg", 1280, 720);
}
   SDL_Surface* guideImage= IMG_Load("guide.png");
   SDL_Rect guideRect;             
   Uint32 guideStartTime = 0;      
   temps t;
    Uint32 timer,elapsed;
    initialiser_temps(&t);
    t.police= TTF_OpenFont("ASTRO.ttf", 20);
    
   int showGuide = 0;      
   Uint32 currentTime;


    SDL_Event event;
    int running = 1;
    int direction1 = 0, direction2 = 0;



    while (running) {

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = 0;

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_g) {
        showGuide = 1;  
        guideStartTime = SDL_GetTicks();  
    }
                switch (event.key.keysym.sym) {

                    case SDLK_ESCAPE: running = 0; break;
                    case SDLK_UP:
                    case SDLK_DOWN:
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        direction1 = event.key.keysym.sym;
                        break;
                    case 'w':
                    case 's':
                    case 'a':
                    case 'd':
                        direction2 = event.key.keysym.sym;
                        break;
                }
            }

            if (event.type == SDL_KEYUP) {
                if (event.key.keysym.sym == direction1)
                    direction1 = 0;
                if (event.key.keysym.sym == direction2)
                    direction2 = 0;
            }
        }

      
