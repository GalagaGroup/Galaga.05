#ifndef FUNCTIONS_H_
#define	FUNCTIONS_H_

#include "Enemy.h"
#include "Bullet.h"
#include "SDL_Plotter.h"
#include <fstream>
#include <string>
#include "Starfighter.h"

using namespace std;

/*
Precondition:
	An array of enemies of size 32 exists, an int value existts
Postcondition:
	The array of enemies is changed to enemies with predetermined
	characotoristics
Return:
	void
Description:
	Instantiates the array of enemies  to a height of a on the screen
*/
void EnemyInit(Enemy enemies[], int a);

/*
Precondition:
	a 3D array of ints exists and is passed by refrence
Postcondition:
	The array is filled with the graphics of letters. the first index is the
	number in the allphabet, the second and third numbers are the size of the
	square graphic
Return:
	void
Description:
	Reads in  graphics from a file and saves the graphics to the array
*/
void lettersinit(int letters_graphics[][25][25]);

/*
Precondition:
	a 3D array of ints exists and is passed by refrence
Postcondition:
	The array is filled with the graphics of numbers. the first index is the
	number , the second and third numbers are the size of the
	square graphic
Return:
	void
Description:
	Reads in graphics from a file and saves the graphics to the array
*/
void numbersinit(int numbers_graphics[][25][25]);

/*
Precondition:
	a string, a 3D int array passed by refrence and an SDL_Plotter object
	which is spassed by refrence.
Postcondition:
	The string in unchanged, the letter graphics are unchanged the Plotter
	is changed,
Return:
	void
Description:
	The score string is printed to the screen using the letters from the
	letter graphics array to the plotter window object.
*/
void scoreboard( string , int [26][25][25] , SDL_Plotter& , int , int  );

/*
Precondition:
	A SDL_Plotter object exists and is passed by refrence
Postcondition:
	The SDL window is changed
Return:
	void
Description:
	The SDL window where the score is located is painted to black
*/
void clearScore( SDL_Plotter& , int , int , int , int);

/*
Precondition:
	A SDL window object exists and is passed by refrence, an int value exists,
	a 3D int array is passed by refrence
Postcondition:
	The SDL window has the score painted ot it using the numbers from the
	numbers array
Return:
	void
Description:
	The SDL window has the score printed to it using the fonts from the
	Number 3D int array
*/
void printScore( SDL_Plotter& , int  , int [][25][25] , int , int , int , int);

/*
Precondition:
	two int values exist as well as a SDL plotter object by refrence
Postcondition:
	The plotter window is changed
Return:
	void
Description:
	The entire window is painted black the two int values are the max
	values of the window(row and col)
*/
void clearScreen( int , int , SDL_Plotter& );

/*
Precondition:
	An array of bullets, a plotter window, a starfighter and an int exists
Postcondition:
	The plotter window is changed, the array of bullets is changed, the
	starfighter object is unchanged, the int val is unchaged
Return:
	void
Description:
	If the bullett is within the bounds of the window it is moved upward on
	the window, otherwise it is destroyed
*/
void updateBullet( Bullet[] , SDL_Plotter& , Starfighter , int );

/*
Precondition:
	An SDL window an array of bullets, an array of enemies, an int, and a
	3D array of ints exists
Postcondition:
	The plotter window, the array of bullets, the array of enemies,
	the score are all changed, the 3D int array in unchanged
Return:
	void
Description:
	The collision of the bullet, and all of the enemies is tested, if it is
	detected then the bullet is destroyed as well as the enemy and the score is
	incremented
*/
void collisionTest( SDL_Plotter& , Bullet[] , Enemy[] ,  int& , int[][25][25] );

/*
Precondition:
	A plotter window an array of enemies and a starfighter object exists
Postcondition:
	The SDL window is cahanged, the array of enemies is changed,
	the starfighter object is changed
Return:
	void
Description:
	All of the enemies are killed as well as the starfighter
*/
void lose( SDL_Plotter& , Enemy[] , Starfighter );

/*
Precondition:
	an SDL window object, a 3D in array two int values and a string exist
Postcondition:
	The SDL window is changed, the int array is unchanged, the two int values
	as well as the string are unchanged
Return:
	voiid
Description:
	A message is printed to the window, using the font from the letter array at
	the two int values(x, y)
*/
void printMessage( SDL_Plotter& , int[][25][25] , int , int , string );

#endif // FUNCTIONS_H_
