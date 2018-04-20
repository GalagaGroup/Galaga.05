#ifndef ENEMY_H_
#define ENEMY_H_

#include "SDL_Plotter.h"

class Enemy{
public:
	int health;
	bool dead = false;
	int posx;
	int posy;
	int type;
	char pic[34][30];
    Enemy(int x, int y, int type);
    Enemy();
    void draw(SDL_Plotter &g);
    void moveShip(int x, int y, SDL_Plotter &g);
    void eraseShip(SDL_Plotter &g);
    void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void setType(int a);
};



#endif // ENEMY_H_
