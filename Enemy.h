#ifndef ENEMY_H_
#define ENEMY_H_

#include "SDL_Plotter.h"

class Enemy{
public:
private:
	int posx;
	int posy;
	int type;
	int health;
	bool state;
	char pic[34][30];

public:
	Enemy();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	bool getState();
	void setState(bool a);
	void setType(int a);

	void kill(SDL_Plotter &g);
	void draw(SDL_Plotter &g);
	void eraseShip(SDL_Plotter &g);
	Enemy(int x, int y, int type, bool);
    void moveShip(int x, int y, SDL_Plotter &g);
};



#endif // ENEMY_H_
