#ifndef ENEMYINIT_H_
#define	ENEMYINIT_H_

#include "Enemy.h"

void EnemyInit(Enemy enemies[32]){

    //bottom left row
    enemies[0] = Enemy (50, 130, 2);
    enemies[1] = Enemy (80, 130, 2);
    enemies[2] = Enemy (110, 130, 2);
    enemies[3] = Enemy (140, 130, 2);
    enemies[4] = Enemy (170, 130, 2);
    enemies[5] = Enemy (200, 130, 2);
    enemies[6] = Enemy (230, 130, 2);
    enemies[7] = Enemy (260, 130, 2);

    //bottom right row
    enemies[8] = Enemy (340, 130, 2);
    enemies[9] = Enemy (370, 130, 2);
    enemies[10] = Enemy (400, 130, 2);
    enemies[11] = Enemy (430, 130, 2);
    enemies[12] = Enemy (460, 130, 2);
    enemies[13] = Enemy (490, 130, 2);
    enemies[14] = Enemy (520, 130, 2);
    enemies[15] = Enemy (550, 130, 2);

    //top left row

    //top right row

    //enemies[32] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e12, e13, e14, e15, e16}

}


#endif // ENEMYINITIALISER
