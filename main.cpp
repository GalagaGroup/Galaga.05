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

       star.draw(g);

        //get input and move charactor
        if(g.kbhit()){
            g.getKey();
            key_pressed = g.getKey();
            if(key_pressed == RIGHT_ARROW && star.posx <= 720){
                star.moveShip(5, g);
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 50){
                star.moveShip(-5, g);
            }else if(key_pressed == ' '){
                Bullet bull(star.posx, star.posy);
            }
        }

       star.moveShip(5, g);




        star.draw(g);
		g.update();
    }
}
