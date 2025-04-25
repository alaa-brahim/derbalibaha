#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

typedef struct {
    SDL_Surface* image;
    SDL_Rect position;
    SDL_Rect camera;
} Background;
typedef struct temps {
    SDL_Surface *texte;
    SDL_Rect position;
    TTF_Font *police;
    char entree[20];
    SDL_Color couleurBlanche, couleurNoire;
    int tempsActuel, tempsPrecedent;
    int min, cmp;
} temps;
void initBackground(Background* bg, const char* imagePath, int screenWidth, int screenHeight);
void displayBackground(SDL_Surface* screen, Background* bg, int renderX, int renderY);
void updateCamera(Background* bg, int direction, int maxX, int maxY);
void initialiser_temps(temps *t);
void afficher_temps(temps *t, SDL_Surface *screen);

