#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "board.h"

using namespace std;

const char dir[4] = { 'u', 'r', 'd', 'l' };

int main()
{
	Board B;
	B.spawn();
	while(B.spawn() && !B.stuck())
	{
		B.display();
		if(!B.move('u')) if(!B.move('l')) if(!B.move('r')) B.move('d');
	}
	B.display();
	cout << "Game over!\n";
	return 0;
}
