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


    char square [12][12] =  {'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q','W', 'W', 'Q', 'Q',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',
                           'B', 'B', 'R', 'R','B', 'B', 'R', 'R','B', 'B', 'R', 'R',};
    while (!g.getQuit())
    {
       star.draw(g);

        if(g.kbhit()){
			g.getKey();
		}

		g.update();
    }
}
