

#ifndef STARFIGHTER_H_
#define STARFIGHTER_H_

#include <string.h>
#include "SDL_Plotter.h"

class Starfighter
{

private:
        bool living = true;
        int posx;
        int posy;
        char pic[34][30];

public:
        Starfighter();
        int getX();
        int getY();
        void setX(int x);
        void setY(int y);
        bool getState();

        void hit();
        void setState(bool a);
        void draw(SDL_Plotter &g);
        void moveShip(int a, SDL_Plotter &g);
        void eraseShip(SDL_Plotter &g);


    protected:


};

#endif // STARFIGHTER_H


