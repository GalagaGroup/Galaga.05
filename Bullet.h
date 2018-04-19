#ifndef BULLET_H_
#define BULLET_H_

#include "SDL_Plotter.h"

class Bullet{
public:
	 int posx;
	 int posy;
	bool state = true;
	const char pic[8][3] = {	     'B', 'Q', 'B',
                                     'B', 'Q', 'B',
                                     'Q', 'Q', 'Q',
                                     'Q', 'W', 'Q',
                                     'B', 'R', 'B',
                                     'B', 'R', 'B',
                                     'B', 'R', 'B',
                                     'B', 'R', 'B',};

	Bullet(int x, int y);
	Bullet();
	~Bullet();
	void eraseShip(SDL_Plotter &g, int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	draw(SDL_Plotter &g);
};

#endif // BULLET_H_

