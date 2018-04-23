#include <iostream>
#include "SDL_Plotter.h"
#include "Starfighter.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GameFunctions.h"

using namespace std;

int main(int argc, char ** argv)
{
    char key_pressed;
    int ROW_MAX = 800;
    int COL_MAX = 600;
    int framecounter = 0;
    int score = 0;
    int frequency  = 700;
    static int letter_graphics[26][25][25];
    static int number_graphics[10][25][25];

    // create window with max row and max col values
    SDL_Plotter g(ROW_MAX, COL_MAX);
    clearScreen(ROW_MAX, COL_MAX, g);

    //init. score
    lettersinit(letter_graphics);
    numbersinit(number_graphics);

    scoreboard("SCORE", letter_graphics , g);
    printScore(g, score, number_graphics);


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

    //main game loop
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
        updateBullet(Bullets, g, star, ROW_MAX);
        printScore(g, score, number_graphics);

        //test for collision
        collisionTest(g, Bullets, Enemies, score, number_graphics);

        //move enemies
        for(int i = 0; i < 32; i++){
            if(Enemies[i].getState() == false){
                //theyre dead and shouldnt be moved or diaplayed
            }
            else if(framecounter % frequency == 0){
                if(Enemies[i].posy < ROW_MAX && Enemies[i].posy > 50){
                    Enemies[i].eraseShip(g);
                    Enemies[i].setY(Enemies[i].posy + 10);
                    Enemies[i].draw(g);
                }else
            }
        }

        framecounter++;
		g.update();

		bool allDead = true;
		for(int i = 0; i < 32; i ++){
            if(Enemies[i].getState() == true)
                allDead = false;
		}
		if(allDead == true && star.getLiving() == dead){
            EnemyInit(Enemies, 100);
            frequency = frequency - 100;
		}

    }
    return 0;
}
