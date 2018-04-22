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

void scoreinit(string score, SDL_Plotter &g){
    ifstream inLetters;
    inLetters.open("Letters.txt");
    int letter_graphics[26][25][25];

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                inLetters >> letter_graphics[i][j][k];

            }
        }
    }
    for(int i = 0; i < score.length(); i++){
        string letter;
        int intletter;
        letter = score.substr(i, 1);
        intletter = int(letter.c_str()[0]);
        cout << intletter << endl;
        intletter = (intletter - 65);

        cout << "letter " << letter << " " << intletter << endl;

        for(int j = 0; j < 25; j++){
            for (int k = 0; k < 25;k++){
                if(letter_graphics[intletter][k][j] == 1){
                    g.plotPixel(10 + j + (i * 30), 15 + k, 255, 0, 0);
                }
            }
        }
    }
}





#endif // FUNCTIONS_H_