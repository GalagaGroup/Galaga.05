#include "Starfighter.h"

Starfighter::Starfighter()
{
        bool living = true;
        posx = 285;
        posy = 700;
        char graphic[34][30] = {        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//1
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//1
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//1
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//2
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//3
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//4
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//5
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//6
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', //7
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', //7
                                        'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B',//8
                                        'R', 'R', 'B', 'B', 'B', 'B', 'B', 'B', 'Q', 'Q', 'B', 'B', 'W', 'W', 'R', 'R', 'W', 'W', 'B', 'B', 'Q', 'Q', 'B', 'B', 'B', 'B', 'B', 'B', 'R', 'R',//8
                                        'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'W', 'W', 'W', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'W', 'W', 'W', 'W', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R',//7
                                        'R', 'R', 'B', 'B', 'B', 'B', 'Q', 'Q', 'W', 'W', 'W', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'W', 'W', 'W', 'W', 'Q', 'Q', 'B', 'B', 'B', 'B', 'R', 'R',//7
                                        'W', 'W', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'W', 'W',//6
                                        'W', 'W', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'W', 'W',//6
                                        'W', 'W', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W',//5
                                        'W', 'W', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'W', 'W',//5
                                        'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W',//4
                                        'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W',//4
                                        'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W',//3
                                        'W', 'W', 'W', 'W', 'W', 'W', 'B', 'B', 'R', 'R', 'R', 'R', 'W', 'W', 'W', 'W', 'W', 'W', 'R', 'R', 'R', 'R', 'B', 'B', 'W', 'W', 'W', 'W', 'W', 'W',//3
                                        'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'W', 'W', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W',//2
                                        'W', 'W', 'W', 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'W', 'W', 'B', 'B', 'R', 'R', 'R', 'R', 'B', 'B', 'B', 'B', 'W', 'W', 'W', 'W',//2
                                        'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W',
                                        'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'W', 'W',};
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 34; j++){
                pic[i][j] = graphic[i][j];
            }
        }

}

 void Starfighter::draw(SDL_Plotter &g){
        for(int j = 0; j < 30; j++){
            for(int i = 0; i < 34; i++){
                    if (pic[i][j] == 'B'){
                        //its black
                    }else if(pic[i][j] == 'R'){
                        g.plotPixel(j + posx, i + posy, 255, 0, 0);
                    }else if(pic[i][j] == 'W'){
                        g.plotPixel(j  + posx, i + posy, 255, 255, 255);
                    }else if(pic[j][j] == 'Q'){
                        g.plotPixel(j  + posx, i + posy, 0, 0, 255);
                    }

            }
        }
 }

 void Starfighter::moveShip(int a, SDL_Plotter &g){
    posx += a;
    draw(g);
 }

 void Starfighter::eraseShip(SDL_Plotter &g){
        //cout << "Before: " << endl;
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 34; j++){
                     //cout << x + i << " " << y + j << endl;
                        g.plotPixel(posx + i, posy + j, 0, 0, 0);
            }
        }
 }

void Starfighter::setX(int x){
        posx = x;
}
void Starfighter::setY(int y){
        posy = y;
}
int Starfighter::getX(){
        return posx;
}
int Starfighter::getY(){
        return posy;
}
bool Starfighter::getState(){
        return living;
}
void Starfighter::setState(bool a){
        living = a;
}
