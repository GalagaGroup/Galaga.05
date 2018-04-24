
#include <fstream>
#include <string>
#include "Enemy.h"
#include "Starfighter.h"
#include "GameFunctions.h"

using namespace std;

void EnemyInit(Enemy enemies[], int a){

    //enemy init
    for(int i = 0; i < 8; i++){

        enemies[i] = Enemy (20 + (30 * i), a, 2, true);
        enemies[8 + i] = Enemy (20 + (30 * i), a + 40, 2, true);
        enemies[16 + i] = Enemy(340 + (30 * i), a, 2, true);
        enemies[24 + i] = Enemy(340 + (30 * i), a + 40, 2, true);

    }

}

void lettersinit(int letters_graphics[][25][25]){
    ifstream inLetters;
    inLetters.open("Letters.txt");

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                inLetters >> letters_graphics[i][j][k];
            }
        }
    }
    inLetters.close();
}

void numbersinit(int numbers_graphics[][25][25]){
    ifstream inNumbers;
    inNumbers.open("Numbers.txt");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                inNumbers >> numbers_graphics[i][j][k];
            }
        }
    }
    inNumbers.close();
}

void scoreboard(string score, int letter_graphics[][25][25], SDL_Plotter &g, int x, int y){
    for(int i = 0; i < score.length(); i++){
        string letter;
        int intletter;
        letter = score.substr(i, 1);
        if (letter == " "){
            //no graphic needed for space
        }else{
            intletter = int(letter.c_str()[0]);
            intletter = (intletter - 65);

            for(int j = 0; j < 25; j++){
                for (int k = 0; k < 25;k++){
                    if(letter_graphics[intletter][k][j] == 1){
                        g.plotPixel(x + j + (i * 30), y + k, 255, 0, 0);
                    }
                }
            }
        }
    }
}

void clearScore(SDL_Plotter &g, int x , int y , int wide , int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < wide; j++){
            g.plotPixel(x + i , y + j, 0,0,0);
        }
    }
}

void printScore(SDL_Plotter &g, int score, int numbers_graphics[][25][25] , int x , int y , int wide , int height){
    clearScore(g, x, y , wide , height);
    int singlenum;
    string str_score = to_string(score);
    string element;
    int counter = 0;

    for(int i = 0; i < str_score.length(); i ++){
        counter++;
        element = str_score.substr(i,1);
        singlenum = element.c_str()[0] - 48;
        for(int i = 0; i < 25; i++){
            for(int j = 0; j < 25; j++){
                if(numbers_graphics[singlenum][i][j] == 1){
                    g.plotPixel(240 + j + (counter * 30), 50 + i , 255 , 0 , 0 );
                }
            }
        }
    }
}

void clearScreen(int ROW_MAX, int COL_MAX, SDL_Plotter &g){
    for(int i = 0; i < ROW_MAX; i++){
        for(int j = 0; j < COL_MAX ; j++){
            g.plotPixel(j, i, 0, 0, 0);
        }
    }
}

void updateBullet(Bullet Bullets[], SDL_Plotter &g, Starfighter star, int ROW_MAX){
    for(int i = 0; i < 2; i++){
        if(Bullets[i].getState() == true){
            if(Bullets[i].getY() > 100 && Bullets[i].getY() < ROW_MAX - 10 && Bullets[i].getX() > 15){
            Bullets[i].eraseShip(g);
            Bullets[i].setY(Bullets[i].getY() - 1);
            Bullets[i].draw(g);
            star.draw(g);
            }else{
                Bullets[i].destroy(g);
            }
        }
    }
}

void collisionTest(SDL_Plotter &g,Bullet Bullets[], Enemy Enemies[],  int &score, int number_graphics[][25][25]){
    for(int i = 0; i < 32; i++){
            for(int j = 0; j < 2; j++){
                if(Bullets[j].getY() > Enemies[i].getY() && Bullets[j].getY() < Enemies[i].getY() + 30){
                    if(Bullets[j].getX() > Enemies[i].getX() && Bullets[j].getX() < Enemies[i].getX() + 30){
                        //bullet colided
                        Enemies[i].kill(g);
                        Bullets[j].destroy(g);
                        score += 100;
                        printScore(g, score, number_graphics, 240, 50 , 35 , 200);
                    }
                }
            }
        }
}

void lose(SDL_Plotter &g, Enemy Enemies[], Starfighter star){
    for(int i = 0; i < 32; i++){
        Enemies[i].kill(g);
    }
    star.setLiving(false);
}

//string score, int letter_graphics[][25][25], SDL_Plotter &g, int x, int y

void highscores(int score, SDL_Plotter &g , int letter_graphics [][25][25]){
    string user;
    string existingscore;
    ofstream out;
    ifstream in;
    in.open("Highscores.txt");
    int yval = 200;
    if(in){
        while(in >> user >> existingscore){
            cout << user << ", " << existingscore << endl;
            scoreboard( user , letter_graphics , g , 140 , yval);
            scoreboard( existingscore , letter_graphics , g , 140 , yval);
            yval += 100;
        }
    }
}

