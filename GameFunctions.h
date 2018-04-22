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

    for(int i = 0; i < 26; i++){
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
    cout << "graphic printed" << endl;
}

void clearScore(SDL_Plotter &g){
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 30; j++){
            g.plotPixel(190 + i , 15 + j, 0,0,0);
        }
    }
    cout << "score cleared" << endl;
}

void incrementScore(SDL_Plotter &g, int &score, int (&numbers_graphics)[10][25][25]){
    score += 100;
    int singlenum = score;
    int counter = 0;
    int mod = 10000;
    do {
        singlenum = (score - (score % mod)) / mod;
        score = score - (score - (score % mod));
        mod /= 10;
        counter ++;
        for(int i = 0; i < 25; i++){
            for(int j = 0; j < 25; j++){
                if(numbers_graphics[singlenum][i][j] == 1){
                        cout << singlenum << endl;
                     g.plotPixel(190 + i + (counter * 30), 25 + j , 255,0,0);
                }

            }
        }
    }while (mod != 0);
}







#endif // FUNCTIONS_H_
