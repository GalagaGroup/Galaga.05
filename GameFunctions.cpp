
#include <fstream>
#include <string>
#include "Enemy.h"
#include "Starfighter.h"
#include "GameFunctions.h"

using namespace std;

void EnemyInit(Enemy enemies[], int a){

    //enemy init
    for(int i = 0; i < 8; i++){

        enemies[i] = Enemy (20 + (30 * i), a, 2, true);
        enemies[8 + i] = Enemy (20 + (30 * i), a + 40, 2, true);
        enemies[16 + i] = Enemy(340 + (30 * i), a, 2, true);
        enemies[24 + i] = Enemy(340 + (30 * i), a + 40, 2, true);

    }

}

void lettersinit(int letters_graphics[][25][25]){
    ifstream inLetters;
    inLetters.open("Letters.txt");

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                inLetters >> letters_graphics[i][j][k];
            }
        }
    }
    inLetters.close();
}

void numbersinit(int numbers_graphics[][25][25]){
    ifstream inNumbers;
    inNumbers.open("Numbers.txt");

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 25; j++){
            for(int k = 0; k < 25; k++){
                inNumbers >> numbers_graphics[i][j][k];
            }
        }
    }
    inNumbers.close();
}

void printMessage(SDL_Plotter &g, int letter_graphics[][25][25] , int x , int y , string message){
    for(int i = 0; i < message.length(); i++){
        string letter;
        int intletter;
        letter = message.substr(i, 1);
        if (letter == " "){
            //no graphic needed for space
        }else{
            intletter = int(letter.c_str()[0]);
            intletter = (intletter - 65);

            for(int j = 0; j < 25; j++){
                for (int k = 0; k < 25;k++){
                        //cout << "Printing letter: " << intletter << endl;
                    if(letter_graphics[intletter][k][j] == 1){
                        g.plotPixel(x + j + (i * 30), y + k, 255, 0, 0);
                    }
                }
            }
        }
    }
}

void clearArea(SDL_Plotter &g, int x , int y , int wide , int height){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < wide; j++){
            g.plotPixel(x + i , y + j, 0,0,0);
        }
    }
}

/*
void printNumber( SDL_Plotter &g , int numbers_graphics[][25][25] , int x , int y , int number,  int wide , int height){
    clearArea(g , x, y , wide , height);
    int singlenum;
    string str_score = to_string(number);
    string element;
    int counter = 0;

    for(int i = 0; i < str_score.length(); i ++){
        counter++;
        element = str_score.substr(i,1);
        singlenum = element.c_str()[0] - 48;
        for(int i = 0; i < 25; i++){
            for(int j = 0; j < 25; j++){
                if(numbers_graphics[singlenum][i][j] == 1){
                        //cout << "printing score: " << singlenum << endl;
                    g.plotPixel(240 + j + (counter * 30), 50 + i , 255 , 0 , 0 );
                }
            }
        }
    }
}
*/

void printNumber( SDL_Plotter &g , int numbers_graphics[][25][25] , int x , int y , int number){
    int singlenum;
    string str_score = to_string(number);
    string element;
    int counter = 0;

    for(int i = 0; i < str_score.length(); i ++){
        counter++;
        element = str_score.substr(i,1);
        singlenum = element.c_str()[0] - 48;
        for(int i = 0; i < 25; i++){
            for(int j = 0; j < 25; j++){
                if(numbers_graphics[singlenum][i][j] == 1){
                        //cout << "printing number: " << singlenum << endl;
                    g.plotPixel(x + j + (counter * 30), y + i , 255 , 0 , 0 );
                }
            }
        }
    }
}

void updateBullet(Bullet Bullets[], SDL_Plotter &g, Starfighter star, int ROW_MAX){
    for(int i = 0; i < 2; i++){
        if(Bullets[i].getState() == true){
            if(Bullets[i].getY() > 100 && Bullets[i].getY() < ROW_MAX - 10 && Bullets[i].getX() > 15){
            Bullets[i].eraseShip(g);
            Bullets[i].setY(Bullets[i].getY() - 1);
            Bullets[i].draw(g);
            star.draw(g);
            }else{
                Bullets[i].destroy(g);
            }
        }
    }
}

void collisionTest(SDL_Plotter &g,Bullet Bullets[], Enemy Enemies[],  int &score, int number_graphics[][25][25]){
    for(int i = 0; i < 32; i++){
            for(int j = 0; j < 2; j++){
                if(Bullets[j].getY() > Enemies[i].getY() && Bullets[j].getY() < Enemies[i].getY() + 30){
                    if(Bullets[j].getX() > Enemies[i].getX() && Bullets[j].getX() < Enemies[i].getX() + 30){
                        //bullet colided
                        Enemies[i].kill(g);
                        Bullets[j].destroy(g);
                        score += 100;
                        clearArea( g , 240 , 50 , 35 , 200);
                        printNumber(g, number_graphics, 240, 50 , score);
                    }
                }
            }
        }
}

void lose(SDL_Plotter &g, Enemy Enemies[], Starfighter star){
    for(int i = 0; i < 32; i++){
        Enemies[i].kill(g);
    }
    star.setState(false);
}

//SDL_Plotter &g , int numbers_graphics[][25][25] , int x , int y , int number

void highscores(int score, SDL_Plotter &g , int letter_graphics [][25][25] , int number_graphics[][25][25]){
    string user;
    int existingscore;
    int oldscore;
    ofstream out;
    ifstream in;
    string playernames[3];
    int playerscores[3];

    in.open("Highscores.txt");
    int yval = 200;
    if(!in){
        out.open("Highscores.txt");
        out.close();
        in.open("Highscores.txt");
    }
    if(in){
        for(int i = 0; i < 3; i++){
            in >> playernames[i];
            in >> playerscores[i];

            if (score > playerscores[i]){
                if(i < 2){
                    int scoreholder = playerscores[i];
                    string nameholder = playernames[i];
                    playerscores[i] = score;

                    cout << "CONGRADULATIONS! You Made a top score!" << endl;
                    cout << "Please Enter Your Username : " << endl;
                    string username;
                    cin >> username;

                    playernames[i] = username;

                }else{
                }

            }
        printMessage( g , letter_graphics , 130 , yval , user);
        printNumber( g , number_graphics , 270 , yval , existingscore );
        yval += 50;
        }
    }
}


/*
    printMessage( g , letter_graphics , 130 , yval , user);
            printNumber( g , number_graphics , 270 , yval , existingscore );
            yval += 50;
*/
