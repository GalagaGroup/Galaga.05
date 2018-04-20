#include <iostream>
#include "SDL_Plotter.h"
#include "Starfighter.h"
#include "Bullet.h"
#include "Enemy.h"

using namespace std;

int main(int argc, char ** argv)
{
    int ROW_MAX = 800;
    int COL_MAX = 600;
    Starfighter star;
    Bullet bull;
    Bullet llet;
    Bullet Bullets [2] = {bull, llet};
    //Enemy Enemies[8];
    char key_pressed;
    bool bullet;

    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < COL_MAX; i++){
            for(int j = 0; j < ROW_MAX; j++){
                g.plotPixel(i , j, 0, 0, 0);
            }
        }

    //for(int i = 0; i < 1; i++){
    //    Enemies[i].setX(150 + (50 * i));
    //    Enemies[i].setY(150);
    //    Enemies[i].setType(2);
    //    Enemies[i].draw(g);
    //}
    Enemy e1(150, 150, 2);
    Enemy e2(180, 150, 3);
    e1.draw(g);
    e2.draw(g);

    while (!g.getQuit())
    {
        //get input and move character
        if(g.kbhit()){
                int movement = 0;
            g.getKey();

            key_pressed = g.getKey();

            if(key_pressed == RIGHT_ARROW && star.posx <= 560){
                movement = 7;
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 10){
                movement = -7;
            }
            else if(key_pressed == ' '){
                bull.posx = star.getX() + 10;
                bull.posy = star.getY() - 10;
                bullet = true;
            }
            star.eraseShip(g);
            star.moveShip(movement, g);
        }

        //update starfighter
        star.draw(g);

        //move and update bullet
        if(bullet){
                if(bull.getY() > 0 && bull.getY() < ROW_MAX){
                    bull.eraseShip(g, bull.getX(), bull.getY());
                    bull.setY(bull.getY() - 1);
                    bull.draw(g);
                }
                else{
                    bull.eraseShip(g, bull.getX(), bull.getY());
                    bullet = false;
                    bull.~Bullet();
                }

        }

        //move and update enemies
        //for(int i = 0; i < 8; i++){
        //    Enemies[i].draw(g);
    //}


		g.update();
    }
    return 0;
}
