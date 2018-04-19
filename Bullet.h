<<<<<<< HEAD
/*struct Bullet{
	int posx,
	int posy,
	bool state = true;
}
*/
=======
#ifndef BULLET_H_
#define BULLET_H_

struct Bullet{
	int posx;
	int posy;
	bool state = true;

	Bullet(int x, int y){
		posx = x;
		posy = y;
	}
};

#endif // BULLET_H_

>>>>>>> 9e3f89fdad2caf1bf728d1356e73b3fe02db2fc6
