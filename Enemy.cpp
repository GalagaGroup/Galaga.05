#include "Enemy.h"

	Enemy::Enemy(int x, int y, int type,bool a){
		health = 1;
		posx = x;
		posy = y;
		state = a;
		const char moth[34][30] = {	'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Y', 'Y', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B',//1
									'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Y', 'Y', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B',//1
									'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R', 'Y', 'Y', 'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
									'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R', 'Y', 'Y', 'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
									'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'R', 'R', 'R', 'R', 'Y', 'Y', 'R', 'R', 'R', 'R', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
									'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'R', 'R', 'R', 'R', 'Y', 'Y', 'R', 'R', 'R', 'R', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
									'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
									'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
									'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'R', 'R', 'R', 'R', 'R', 'R', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
									'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'R', 'R', 'R', 'R', 'R', 'R', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
									'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B',//7
									'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B',//7
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',//8
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',//8
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',//9
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',//9
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',//10
									'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'Q', 'Q', 'Q', 'Q', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',};//10

		const char galaga[34][30] = {	'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//1
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//1
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
									'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
									'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'B', 'B', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//7
									'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//7
									'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B',//8
									'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B',//8
									'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G',//9
									'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G',//9
									'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B',//8
									'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B',//8
									'B', 'B', 'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G', 'B', 'B',//7
									'B', 'B', 'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G', 'B', 'B',//7
									'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'O', 'O', 'B', 'B', 'O', 'O', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G',//6
									'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'O', 'O', 'B', 'B', 'O', 'O', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G',//6
									'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'O', 'O', 'B', 'B', 'O', 'O', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G',//5
									'G', 'G', 'O', 'O', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'O', 'O', 'B', 'B', 'O', 'O', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'O', 'O', 'G', 'G',//5
									'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G',//4
									'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G',//4
									'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G',//3
									'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'O', 'O', 'O', 'O', 'G', 'G',//3
									'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G',//2
									'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G',//2
									'B', 'B', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'B', 'B',//1
									'B', 'B', 'G', 'G', 'G', 'G', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'G', 'G', 'G', 'G', 'B', 'B',};//1
		if(type == 2){
			for(int i = 0; i < 30; i++){
				for(int j = 0; j < 34; j++){
					pic[i][j] = moth[i][j];
            }
        }
		}else if(type == 3){
			for(int i = 0; i < 30; i++){
				for(int j = 0; j < 34; j++){
					pic[i][j] = galaga[i][j];
            }
        }

		}
	}

	Enemy::Enemy(){
		posx = 0;
		posy = 0;
		type = 2;
		state = true;
	}
    void Enemy::draw(SDL_Plotter &g){
		for(int j = 0; j < 30; j++){
            for(int i = 0; i < 30; i++){
                    if (pic[i][j] == 'B'){
                        //is black no need to paint
                    }else if(pic[i][j] == 'R'){
                        g.plotPixel(j + posx, i + posy, 255, 0, 0);
                    }else if(pic[i][j] == 'W'){
                        g.plotPixel(i  + posx, j + posy,  255, 255, 255);
                    }else if(pic[i][j] == 'Q'){
                        g.plotPixel(j  + posx, i + posy, 0, 0, 255);
                    }else if(pic[i][j] == 'G'){
						g.plotPixel(j + posx, i + posy, 54, 160, 111);
                    }else if(pic[i][j] == 'O'){
						g.plotPixel(j + posx, i + posy, 255, 148, 0);
                    }else if(pic[i][j] == 'Y'){
						g.plotPixel(j + posx, i + posy, 255, 246, 12);
                    }

            }
        }
    }
    void Enemy::moveShip(int x, int y, SDL_Plotter &g){
		posx = posx + x;
		posy = posy + y;
    }
    void Enemy::eraseShip(SDL_Plotter &g){
		for(int i = 0; i < 30; i++){
            for(int j = 0; j < 45; j++){
                        g.plotPixel(posx + i, posy + j, 0, 0, 0);
            }
        }
    }

    void Enemy::setState(bool a){
		state = a;
    }
    void Enemy::kill(SDL_Plotter &g){
    	cout << "1killing" << endl;
		state = false;
		cout << "2killing" << endl;
		eraseShip(g);
		cout << "3killing" << endl;
		posx = 1;
		cout << "4killing" << endl;
		posy = 100;
		cout << "5killing" << endl;
		eraseShip(g);
		cout << "6killing" << endl;
    }

    void Enemy::setX(int x){
		posx = x;
    }

	void Enemy::setY(int y){
		posy = y;
	}

	void Enemy::setType(int a){
		type = a;
	}

	int Enemy::getX(){
		return posx;
	}

	int Enemy::getY(){
		return posy;
	}

	bool Enemy::getState(){
		return state;
	}
