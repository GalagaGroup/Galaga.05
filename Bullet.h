#ifndef BULLET_H_
#define BULLET_H_

#include "SDL_Plotter.h"

class Bullet{
public:
	 int posx;
	 int posy;
	//bool state = true;
	const char pic[16][6] = {	     'B', 'B', 'Q', 'Q', 'B', 'B',
									 'B', 'B', 'Q', 'Q', 'B', 'B',
                                     'B', 'B', 'Q', 'Q', 'B', 'B',
                                     'B', 'B', 'Q', 'Q', 'B', 'B',
                                     'Q', 'Q', 'Q', 'Q', 'Q', 'Q',
                                     'Q', 'Q', 'Q', 'Q', 'Q', 'Q',
                                     'Q', 'Q', 'W', 'W', 'Q', 'Q',
                                     'Q', 'Q', 'W', 'W', 'Q', 'Q',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',
                                     'B', 'B', 'R', 'R', 'B', 'B',};

	Bullet(int x, int y);
	Bullet();
	~Bullet();
	void eraseShip(SDL_Plotter &g, int x, int y);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void draw(SDL_Plotter &g);
};

#endif // BULLET_H_

