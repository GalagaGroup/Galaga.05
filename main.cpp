#include <iostream>
#include "SDL_Plotter.h"
#include "Starfighter.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Functions.h"

using namespace std;

int main(int argc, char ** argv)
{
    int ROW_MAX = 800;
    int COL_MAX = 600;
    int framecounter = 0;
    char key_pressed;
    bool bullet;
    int bottom_row = 170;
    int top_row = 130;

    // create window
    SDL_Plotter g(ROW_MAX, COL_MAX);
    for(int i = 0; i < COL_MAX; i++){
        for(int j = 0; j < ROW_MAX; j++){
            g.plotPixel(i , j, 0, 0, 0);
        }
    }
    // ceate starship
    Starfighter star;

    //create both bulletts fired by starfighter
    Bullet bull;
    Bullet llet;
    Bullet Bullets [2] = {bull, llet};

    //enemy initial.
    Enemy Enemies[32];
    EnemyInit(Enemies, 90);
    for (int i = 0; i < 32; i++){
        Enemies[i].draw(g);
        Enemies[i].isDead(g);
    }

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

            if(bull.getY() > 10 && bull.getY() < ROW_MAX - 10 && bull.getX() > 15){
                bull.eraseShip(g);
                bull.setY(bull.getY() - 1);
                bull.draw(g);
            }
            else{
                bull.eraseShip(g);
                bullet = false;

            }
        }
        //test for collision
        if(bull.getY() > bottom_row && bull.getY() < top_row){
            for(int i = 0; i < 16; i++){
                if(Enemies[i].getX() < bull.getX() && Enemies[i].getX() + 30 > bull.getX()){
                    Enemies[i].setDead(true);
                }
            }
        }
        if(bull.getY() <= framecounter % 60 + 100){   //test for sufficent y val to collide
            for(int i = 0; i < 32; i++){
                if(bull.getX() > Enemies[i].getX() && bull.getX() > Enemies[i].getX() + 30){
                    Enemies[i].setDead(true);
                    bull.destroy(g);
                }
            }
        }


        //move and update enemies
        for(int i = 0; i < 32; i++){
                if(Enemies[i].isDead(g)){
                    Enemies[i].eraseShip(g);
                    Enemies[i].setY(660);
                    Enemies[i].setX(0);
                    Enemies[i].eraseShip(g);
                }

                if(framecounter % 600 == 0){
                    if(Enemies[i].posy < 700 || Enemies[i].posy > 50){
                        Enemies[i].eraseShip(g);
                        Enemies[i].setY(Enemies[i].posy + 10);
                        bottom_row += 10;
                        top_row += 10;
                    }

                }

        Enemies[i].draw(g);
        }

        framecounter++;
		g.update();
    }
    return 0;
}
