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
                movement = 7;
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 10){
                movement = -7;
            }
            else if(key_pressed == ' '){
                bull.posx = 100;
                bull.posy = 100;
                bullet = true;
            }
            cout << "start:" << endl;
            cout << star.posy << endl;
            star.eraseShip(g, star.posx, star.posy);
            cout << "End: " << endl;
            star.moveShip(movement, g);
        }



        star.draw(g);
        if(bullet){
                if(bull.posy > 4){
                    bull.eraseShip(g, bull.posx, bull.posy);
                    bull.posy = bull.posy - 1;
                    bull.draw(g);
                }
                else{
                    bull.eraseShip(g, bull.posx, bull.posy);
                    ~bullet;
                }

        }




		g.update();
    }
    return 0;
}
