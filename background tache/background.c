#include "background.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>


void initBackground(Background* bg, const char* imagePath, int screenWidth, int screenHeight) {
    bg->image = IMG_Load(imagePath);
    if (!bg->image) {
        fprintf(stderr, "Failed to load image %s: %s\n", imagePath, IMG_GetError());
        exit(EXIT_FAILURE);
    }

    bg->position.x = 0;
    bg->position.y = 0;

    bg->camera.x = (bg->image->w - screenWidth) / 2;
    bg->camera.y = (bg->image->h - screenHeight) / 2;
    bg->camera.w = screenWidth;
    bg->camera.h = screenHeight;
}

void displayBackground(SDL_Surface* screen, Background* bg, int renderX, int renderY) {
    SDL_Rect dest;
    dest.x = renderX;
    dest.y = renderY;
    SDL_BlitSurface(bg->image, &bg->camera, screen, &dest);
}

void updateCamera(Background* bg, int direction, int maxX, int maxY) {
    const int speed = 10;
    switch (direction) {
        case SDLK_UP:
        case 'w':
            bg->camera.y -= speed;
            break;
        case SDLK_DOWN:
        case 's':
            bg->camera.y += speed;
            break;
        case SDLK_LEFT:
        case 'a':
            bg->camera.x -= speed;
            break;
        case SDLK_RIGHT:
        case 'd':
            bg->camera.x += speed;
            break;
    }

    if (bg->camera.x < 0) bg->camera.x = 0;
    if (bg->camera.y < 0) bg->camera.y = 0;
    if (bg->camera.x > maxX - bg->camera.w) bg->camera.x = maxX - bg->camera.w;
    if (bg->camera.y > maxY - bg->camera.h) bg->camera.y = maxY - bg->camera.h;
}
void initialiser_temps(temps *t)
{
t->texte = NULL;

t->position.x=0;
t->position.y=0;

t->police = NULL;
t->police = TTF_OpenFont("ASTRO.ttf", 20);
if(t->police==NULL)
printf("error police\n");
strcpy( t->entree,"");    
t->tempsActuel = 0; 
t->tempsPrecedent = 0;
t->min = 0;
t->cmp=0;

}
void afficher_temps(temps *t,SDL_Surface *screen)
{



TTF_Font *police = NULL;//


 SDL_Event event;
   // TTF_Init();
 SDL_Color couleurNoire = {0, 0, 0}, couleurRouge = {255, 255, 255};
 


t->tempsActuel = SDL_GetTicks();
 

  sprintf(t->entree, "temps: %dm %ds",t->min,t->cmp); 

t->texte = TTF_RenderText_Shaded(t->police,t->entree, couleurNoire, couleurRouge);  //probleme police    gdb prog   where


t->tempsActuel = SDL_GetTicks();

 
     
     
