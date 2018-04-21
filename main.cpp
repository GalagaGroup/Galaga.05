#include <iostream>
#include "SDL_Plotter.h"
#include "Starfighter.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Functions.h"

using namespace std;

int main(int argc, char ** argv)
{
    bool bullet;
    char key_pressed;
    int ROW_MAX = 800;
    int COL_MAX = 600;
    int framecounter = 0;
    int top_row = 130;
    int bottom_row = 170;


    // create window with max row and max col values
    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < COL_MAX; i++){
        for(int j = 0; j < ROW_MAX; j++){
            g.plotPixel(i , j, 0, 0, 0);
        }
    }

    // ceate starship
    Starfighter star;
    star.draw(g);

    //create both bulletts fired by starfighter
    Bullet bull;
    Bullet llet;
    Bullet Bullets [2] = {bull, llet};

    //enemy initial.
    Enemy Enemies[32];
    EnemyInit(Enemies, 90);
    for (int i = 0; i < 32; i++){
        Enemies[i].draw(g);
    }

    while (!g.getQuit())
    {
        //get input and move starship
        if(g.kbhit()){
            int movement = 0;
            g.getKey();

            key_pressed = g.getKey();

            if(key_pressed == RIGHT_ARROW && star.posx <= COL_MAX - 40){
                movement = 7;
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 10){
                movement = -7;
            }
            else if(key_pressed == ' '){
                    bool shot = false;
                for(int i = 0; i < 2; i++){
                    if(Bullets[i].getState() == false && shot == false){
                    Bullets[i].setX(star.getX() + 10);
                    Bullets[i].setY(star.getY() - 10);
                    Bullets[i].setState(true);
                    shot = true;
                    }
                }
            }
            star.eraseShip(g);
            star.moveShip(movement, g);
            star.draw(g);
        }

        //move and update bullet
        for(int i = 0; i < 2; i++){
            if(Bullets[i].getState() == true){
                if(Bullets[i].getY() > 10 && Bullets[i].getY() < ROW_MAX - 10 && Bullets[i].getX() > 15){
                Bullets[i].eraseShip(g);
                Bullets[i].setY(Bullets[i].getY() - 1);
                Bullets[i].draw(g);
                star.draw(g);
                }else{
                    Bullets[i].destroy(g);
                }
            }
        }

        //test for collision
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 2; j++){
                if(Bullets[j].getY() > Enemies[i].getY() && Bullets[j].getY() < Enemies[i].getY() + 30){
                    if(Bullets[j].getX() > Enemies[i].getX() && Bullets[j].getX() < Enemies[i].getX() + 30){
                        Enemies[i].kill(g);
                        Bullets[j].destroy(g);
                    }
                }
            }
        }

        //move and update enemies
        for(int i = 0; i < 32; i++){
                if(Enemies[i].getState(g) == true){
                    Enemies[i].eraseShip(g);
                    Enemies[i].setY(660);
                    Enemies[i].setX(0);
                    Enemies[i].eraseShip(g);
                }

                if(framecounter % 600 == 0){
                    if(Enemies[i].posy < 700 || Enemies[i].posy > 50){
                        Enemies[i].eraseShip(g);
                        Enemies[i].setY(Enemies[i].posy + 10);
                    }

                }
            Enemies[i].draw(g);
        }

        framecounter++;
		g.update();
    }
    return 0;
}
