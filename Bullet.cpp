#include "Bullet.h"
Bullet::Bullet(){
    posx = 0;
    posy = 0;
}
Bullet::Bullet(int x, int y){
		posx = x;
		posy = y;
}

Bullet::draw(SDL_Plotter &g){
	for(int j = 0; j < 3; j++){
            for(int i = 0; i < 8; i++){
                    if (pic[i][j] == 'B'){
                        //its black
                    }else if(pic[i][j] == 'R'){
                        g.plotPixel(j + posx, i + 700, 255, 0, 0);
                        //g.plotPixel(j + posx, i + 700, 255, 255, 255);
                    }else if(pic[i][j] == 'W'){
                        g.plotPixel(j  + posx, i + 700, 255, 255, 255);
                        //g.plotPixel(j + posx, i + 700, 255, 255, 255);
                    }else if(pic[i][j] == 'Q'){
                        g.plotPixel(j  + posx, i + 700, 0, 0, 255);
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
	void Bullet::eraseShip(SDL_Plotter &g, int x, int y){
         //cout << "Before: " << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 8; j++){
                     //cout << x + i << " " << y + j << endl;
                        g.plotPixel(x + i, y + j, 0, 0, 0);
            }
        }
 }


	Bullet::~Bullet(){
	}
