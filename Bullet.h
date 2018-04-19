#ifndef BULLET_H_
#define BULLET_H_

struct Bullet{
	int posx;
	int posy;
	bool state = true;

	Bullet(int x, int y){
		posx = x;
		posy = y;
	}
};

#endif // BULLET_H_

