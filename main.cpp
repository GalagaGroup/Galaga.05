#include <iostream>
#include "SDL_Plotter.h"
#include "GameFunctions.h"
#include "Starfighter.h"
#include "Bullet.h"
#include "Enemy.h"


using namespace std;

int main(int argc, char ** argv)
{
    char key_pressed;
    char key;
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

    scoreboard("HIGHSCORE", letter_graphics , g , 180 , 15);
    printScore(g, score, number_graphics, 240, 50 , 35 , 200);


    // ceate starship
    Starfighter star;
    star.draw(g);

    scoreboard("PRESS ENTER", letter_graphics , g , 140 , 200);
    scoreboard("TO", letter_graphics , g , 270 , 300);
    scoreboard("PLAY GAME", letter_graphics , g , 180 , 400);
    g.update();




    //create both bulletts fired by starfighter
    Bullet bull;
    Bullet llet;
    Bullet Bullets [2] = {bull, llet};

    //enemy initial.
    Enemy Enemies[32];
    EnemyInit(Enemies, 700);
    for (int i = 0; i < 32; i++){
        Enemies[i].draw(g);
    }

    //main game loop
    while (!g.getQuit())
    {
        while (key != SDL_SCANCODE_RETURN && !g.getQuit())
        {
            if (g.kbhit()){
                key = g.getKey();
                if(key == SDL_SCANCODE_RETURN){
                    clearScore( g , 140 , 200 , 350 , 350);
                }
            }


    }
        //get input and move starship
        if(g.kbhit()){
            int movement = 0;
            //g.getKey();

            key_pressed = g.getKey();

            if(key_pressed == RIGHT_ARROW && star.posx <= COL_MAX - 40 && star.getLiving()){
                movement = 7;
            }
            else if(key_pressed == LEFT_ARROW && star.posx >= 10 && star.getLiving()){
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
        cout << "1" << endl;

        //move and update bullet
        updateBullet(Bullets, g, star, ROW_MAX);
        printScore(g, score, number_graphics, 240, 50 , 35 , 200);

        cout << "2" << endl;

        //test for collision
        collisionTest(g, Bullets, Enemies, score, number_graphics);

        cout << "3" << endl;

        //move enemies
        for(int i = 0; i < 32; i++){
            if(Enemies[i].getState() == false){
                //theyre dead and shouldnt be moved or diaplayed
            }
            else if(Enemies[i].getY() < ROW_MAX - 40 && Enemies[i].getY() > 50){
                    cout << "in bounds" << endl;
                if(framecounter % frequency == 0){
                    cout << "frequency check" << endl;
                    Enemies[i].eraseShip(g);
                    Enemies[i].setY(Enemies[i].getY() + 10);
                    Enemies[i].draw(g);
                }
            }else
            {
                cout << "killing all entities" << endl;
                lose(g, Enemies, star);
            }
        }

		bool allDead = true;
		for(int i = 0; i < 32; i ++){
            if(Enemies[i].getState() == true)
                allDead = false;
		}
		if(allDead == true && star.getLiving() == true){
            EnemyInit(Enemies, 100);
            frequency = frequency - 100;
		}else if(allDead == true && star.getLiving() == false){
		    clearScreen( ROW_MAX , COL_MAX , g);
            highscores( score , g ,  letter_graphics );
		}

		framecounter++;
		g.update();

    }
    return 0;
}
