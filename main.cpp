#include <iostream>

#include "SDL_Plotter.h"
#include "Starfighter.h"

using namespace std;

int main(int argc, char ** argv)
{
    int ROW_MAX = 800;
    int COL_MAX = 800;
    Starfighter star;


    SDL_Plotter g(ROW_MAX, COL_MAX, true);
    for(int i = 0; i < ROW_MAX; i++){
            for(int j = 0; j < COL_MAX; j++){
                g.plotPixel(i , j, 0, 0, 0);
            }
        }

    while (!g.getQuit())
    {

        char key_Pressed;
        if(g.kbhit()){
			key_Pressed = g.getKey();
			cout << key_Pressed << endl;
			if(key_Pressed == LEFT_ARROW){
                star.eraseShip(g);
                star.moveShip(-1, g);
                //star.eraseShip(g, false);
			}else if(key_Pressed == RIGHT_ARROW){
                star.eraseShip(g);
                star.moveShip(1, g);
                //star.eraseShip(g, false);
            }

		}
        star.draw(g);
		g.update();
    }
}
