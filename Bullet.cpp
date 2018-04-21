#include "Bullet.h"
#include <iostream>

using namespace std;

Bullet::Bullet(){
    posx = 0;
    posy = 0;
    state = false;
}
Bullet::Bullet(int x, int y){
		posx = x;
		posy = y;
}

void Bullet::draw(SDL_Plotter &g){
	for(int j = 0; j < 6; j++){
            for(int i = 0; i < 16; i++){
                    if (pic[i][j] == 'B'){
                        //its black
                    }else if(pic[i][j] == 'R'){
                        g.plotPixel(j + posx, i + posy, 255, 0, 0);
                        //g.plotPixel(j + posx, i + 700, 255, 255, 255);
                    }else if(pic[i][j] == 'W'){
                        g.plotPixel(j  + posx, i + posy, 255, 255, 255);
                        //g.plotPixel(j + posx, i + 700, 255, 255, 255);
                    }else if(pic[i][j] == 'Q'){
                        g.plotPixel(j  + posx, i + posy, 0, 0, 255);
                        //g.plotPixel(j + posx, i + 700, 255, 255, 255);
                    }

            }
        }
}

void Bullet::setX(int x){
    posx = x;
}

void Bullet::setY(int y){
	posy = y;
}

int Bullet::getX(){
	return posx;
}

int Bullet::getY(){
	return posy;
}

void Bullet::eraseShip(SDL_Plotter &g){
	for(int i = 0; i < 6; i++){
		for(int j = 0; j < 16; j++){
					g.plotPixel(posx + i, posy + j, 0, 0, 0);
		}
	}
}
void Bullet::destroy(SDL_Plotter &g){
	cout << "bullet destroyed" << endl;
	eraseShip(g);
	posx = 1;
	posy = 1;
	eraseShip(g);
	setState(false);
}

Bullet::~Bullet(){

}

bool Bullet::getState(){
	return state;
}
void Bullet::setState(bool a){
	state = a;
}
