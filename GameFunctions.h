#ifndef FUNCTIONS_H_
#define	FUNCTIONS_H_

#include "Enemy.h"
#include <fstream>
#include <string>

void EnemyInit(Enemy enemies[32], int a){

    //top left row
    enemies[0] = Enemy (20, a, 2);
    enemies[1] = Enemy (50, a, 2);
    enemies[2] = Enemy (80, a, 2);
    enemies[3] = Enemy (110, a, 2);
    enemies[4] = Enemy (140, a, 2);
    enemies[5] = Enemy (170, a, 2);
    enemies[6] = Enemy (200, a, 2);
    enemies[7] = Enemy (230, a, 2);

    //top right row
    enemies[8] = Enemy (340, a, 2);
    enemies[9] = Enemy (370, a, 2);
    enemies[10] = Enemy (400, a, 2);
    enemies[11] = Enemy (430, a, 2);
    enemies[12] = Enemy (460, a, 2);
    enemies[13] = Enemy (490, a, 2);
    enemies[14] = Enemy (520, a, 2);
    enemies[15] = Enemy (550, a, 2);

    //bottom left row
    enemies[16] = Enemy (20, a + 40, 2);
    enemies[17] = Enemy (50, a + 40, 2);
    enemies[18] = Enemy (80, a + 40, 2);
    enemies[19] = Enemy (110, a + 40, 2);
    enemies[20] = Enemy (140, a + 40, 2);
    enemies[21] = Enemy (170, a + 40, 2);
    enemies[22] = Enemy (200, a + 40, 2);
    enemies[23] = Enemy (230, a + 40, 2);

    //bottom right row
    enemies[24] = Enemy (340, a + 40, 2);
    enemies[25] = Enemy (370, a + 40, 2);
    enemies[26] = Enemy (400, a + 40, 2);
    enemies[27] = Enemy (430, a + 40, 2);
    enemies[28] = Enemy (460, a + 40, 2);
    enemies[29] = Enemy (490, a + 40, 2);
    enemies[30] = Enemy (520, a + 40, 2);
    enemies[31] = Enemy (550, a + 40, 2);

}

void lettersinit(int (&letters_graphics)[26][25][25]){
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
    cout << "letter initialized" << endl;
}

void numbersinit(int (&numbers_graphics)[10][25][25]){
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
    cout << "numbers initialised" << endl;
}

void scoreboard(string score, int (&letter_graphics)[26][25][25], SDL_Plotter &g){
    for(int i = 0; i < score.length(); i++){
        string letter;
        int intletter;
        letter = score.substr(i, 1);
        if (letter == " "){
            //no graphic needed for space
        }else{
            intletter = int(letter.c_str()[0]);
            intletter = (intletter - 65);
            cout << letter << " " << intletter << endl;

            for(int j = 0; j < 25; j++){
                for (int k = 0; k < 25;k++){
                    if(letter_graphics[intletter][k][j] == 1){
                        g.plotPixel(10 + j + (i * 30), 15 + k, 255, 0, 0);
                    }
                }
            }
        }
    }
}

void clearScore(SDL_Plotter &g){
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 35; j++){
            g.plotPixel(190 + i , 15 + j, 0,0,0);
        }
    }
}

void printScore(SDL_Plotter &g, int score, int numbers_graphics[][25][25]){
    clearScore(g);
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
                    g.plotPixel(190 + j + (counter * 30), 20 + i , 255 , 0 , 0 );
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
                        printScore(g, score, number_graphics);
                        cout << "just after " << score << endl;
                    }
                }
            }
        }
}







#endif // FUNCTIONS_H_
