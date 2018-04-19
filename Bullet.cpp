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
	for(int j = 0; j < 30; j++){
            for(int i = 0; i < 34; i++){
                    if (pic[i][j] == 'B'){
                        //its black
                    }else if(pic[i][j] == 'R'){
                        g.plotPixel(j + posx, i + 700, 255, 0, 0);
                    }else if(pic[i][j] == 'Q'){
                        g.plotPixel(j  + posx, i + 700, 0, 0, 255);
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
