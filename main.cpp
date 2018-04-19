#include <iostream>

#include "SDL_Plotter.h"
#include "Starfighter.h"
#include "Bullet.h"

using namespace std;

int main(int argc, char ** argv)
{
    int ROW_MAX = 800;
    int COL_MAX = 800;
    Starfighter star;
    char key_pressed;

    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < ROW_MAX; i++){
            for(int j = 0; j < COL_MAX; j++){
                g.plotPixel(i , j, 0, 0, 0);
            }
        }

    while (!g.getQuit())
    {
<<<<<<< HEAD
       star.draw(g);
=======
        //get input

       star.moveShip(5, g);
>>>>>>> 503af351b7d8fe0a0b77816761ca295c0ced0f62

        if(g.kbhit()){
          g.getKey();
          key_pressed = g.getKey();
          if(key_pressed == RIGHT_ARROW && star.posx <= 720){
            star.moveShip(5, g);
          }
          else if(key_pressed == LEFT_ARROW && star.posx >= 50){
            star.moveShip(-5, g);
          }
        }

        star.draw(g);
		g.update();
    }
}
