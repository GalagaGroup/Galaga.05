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
    Bullet bull;
    char key_pressed;
    bool bullet;

    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < ROW_MAX; i++){
            for(int j = 0; j < COL_MAX; j++){
                g.plotPixel(i , j, 0, 0, 0);
            }
        }

    while (!g.getQuit())
    {
        //get input and move character
        if(g.kbhit()){
                int movement = 0;
            g.getKey();

            key_pressed = g.getKey();

            if(key_pressed == RIGHT_ARROW && star.posx <= 760){
                movement = 5;
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 10){
                movement = -5;
            }
            else if(key_pressed == ' '){
                bull.posx = star.posx;
                bull.posy = star.posy;
                bullet = true;
            }
            cout << "start:" << endl;
            cout << star.posy << endl;
            star.eraseShip(g, star.posx, star.posy);
            cout << "End: " << endl;
            star.moveShip(movement, g);
        }

        if(bull.posy < 0){
            //bullet.eraseShip(g);
            bullet = false;
        }

        star.draw(g);
        if(bullet){
            bull.draw(g);
        }



		g.update();
    }
}
