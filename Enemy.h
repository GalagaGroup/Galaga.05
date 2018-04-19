#ifndef ENEMY_H_
#define ENEMY_H_

class Enemy{

	int health;
	int posx;
	int posy;
    Enemy();
    void draw(SDL_Plotter &g);
    void moveShip(SDL_Plotter &g);
    void eraseShip(SDL_Plotter &g);
    void setX(int x);
	void setY(int y);
	int getX();
	int getY();
};



#endif // ENEMY_H_
