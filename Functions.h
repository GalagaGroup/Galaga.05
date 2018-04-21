#ifndef FUNCTIONS_H_
#define	FUNCTIONS_H_

#include "Enemy.h"

void EnemyInit(Enemy enemies[32], int a){

    //bottom left row
    enemies[0] = Enemy (20, a, 2);
    enemies[1] = Enemy (50, a, 2);
    enemies[2] = Enemy (80, a, 2);
    enemies[3] = Enemy (110, a, 2);
    enemies[4] = Enemy (140, a, 2);
    enemies[5] = Enemy (170, a, 2);
    enemies[6] = Enemy (200, a, 2);
    enemies[7] = Enemy (230, a, 2);

    //bottom right row
    enemies[8] = Enemy (340, a, 2);
    enemies[9] = Enemy (370, a, 2);
    enemies[10] = Enemy (400, a, 2);
    enemies[11] = Enemy (430, a, 2);
    enemies[12] = Enemy (460, a, 2);
    enemies[13] = Enemy (490, a, 2);
    enemies[14] = Enemy (520, a, 2);
    enemies[15] = Enemy (550, a, 2);

    //top left row
    enemies[16] = Enemy (20, a + 40, 2);
    enemies[17] = Enemy (50, a + 40, 2);
    enemies[18] = Enemy (80, a + 40, 2);
    enemies[19] = Enemy (110, a + 40, 2);
    enemies[20] = Enemy (140, a + 40, 2);
    enemies[21] = Enemy (170, a + 40, 2);
    enemies[22] = Enemy (200, a + 40, 2);
    enemies[23] = Enemy (230, a + 40, 2);

    //top right row
    enemies[24] = Enemy (340, a + 40, 2);
    enemies[25] = Enemy (370, a + 40, 2);
    enemies[26] = Enemy (400, a + 40, 2);
    enemies[27] = Enemy (430, a + 40, 2);
    enemies[28] = Enemy (460, a + 40, 2);
    enemies[29] = Enemy (490, a + 40, 2);
    enemies[30] = Enemy (520, a + 40, 2);
    enemies[31] = Enemy (550, a + 40, 2);

}

void collisionTest();


#endif // FUNCTIONS_H_
