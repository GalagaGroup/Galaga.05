

#ifndef STARFIGHTER_H_
#define STARFIGHTER_H_

#include <string.h>
#include "SDL_Plotter.h"

class Starfighter
{
    public:
        bool living = true;
        bool getLiving();
        void setLiving(bool a);
        int posx;
        int posy;
        char pic[34][30];
        ~Starfighter();
        Starfighter();
        void setposX(int x);
        void setposY(int y);
        int getX();
        int getY();
        void hit();
        void draw(SDL_Plotter &g);
        void moveShip(int a, SDL_Plotter &g);
        void eraseShip(SDL_Plotter &g);


    protected:

    private:
};

#endif // STARFIGHTER_H


