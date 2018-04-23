#ifndef ENEMY_H_
#define ENEMY_H_

#include "SDL_Plotter.h"

class Enemy{
public:
	Enemy();
	int posx;
	int posy;
	int type;
	int health;
	int getX();
	int getY();
	char pic[34][30];
	void setX(int x);
	void setY(int y);
	bool state = true;
	void setType(int a);
	void kill(SDL_Plotter &g);
	void draw(SDL_Plotter &g);
	bool getState();
	Enemy(int x, int y, int type, bool);
	void eraseShip(SDL_Plotter &g);
    void moveShip(int x, int y, SDL_Plotter &g);
};



#endif // ENEMY_H_
