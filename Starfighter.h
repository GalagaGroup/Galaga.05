

#ifndef STARFIGHTER_H_
#define STARFIGHTER_H_

#include <string.h>
#include "SDL_Plotter.h"

class Starfighter
{
    public:
        int health;
        int posx;
        int posy;
        char pic[34][30];
        ~Starfighter();
        Starfighter();
        void setposX(int x);
        void setposY(int Y);
        int getposX();
        int getposY();
        void draw(SDL_Plotter &g);
        void moveShip(int a, SDL_Plotter &g);
        void eraseShip(SDL_Plotter &g, int x, int y);


    protected:

    private:
};

#endif // STARFIGHTER_H


