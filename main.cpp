#include <iostream>

#include "SDL_Plotter.h"
#include "Starfighter.h"

using namespace std;

int main(int argc, char ** argv)
{
    int ROW_MAX = 800;
    int COL_MAX = 800;
    Starfighter star;

    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < ROW_MAX; i++){
            for(int j = 0; j < COL_MAX; j++){
                g.plotPixel(i , j, 0, 0, 0);
            }
        }

    while (!g.getQuit())
    {
       star.draw(g);
       star.moveShip(5, g);

        if(g.kbhit()){
			g.getKey();
		}

		g.update();
    }
}
