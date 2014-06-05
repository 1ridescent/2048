#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "board.h"

using namespace std;

const char dir[4] = { 'u', 'r', 'd', 'l' };

inline int score(Board& B)
{
	int emptycnt = 0;
	for(int r = 0; r < 4; r++)
		for(int c = 0; c < 4; c++)
			if(B.board[r][c] == -1)
				emptycnt++;
	return emptycnt;
}
inline void rand_move(Board& B)
{
	while(true)
	{
		int next = rand() % 4;
		if(B.move(dir[next])) return;
	}
}

#define ITERATIONS 1000
#define STEPS_AHEAD 10

int main()
{
	srand(time(0));
	Board B;
	B.spawn();
	while(B.spawn() && !B.stuck())
	{
		B.display();

		long long best = -1;
		int bestdir = -1;
		for(int d = 0; d < 4; d++)
		{
			Board new_B = B;
			if(new_B.move(dir[d]))
			{
				long long totalscore = 0;
				for(int iter = 0; iter < ITERATIONS; iter++)
				{
					Board new_B_copy = new_B;
					for(int step = 0; step < STEPS_AHEAD && new_B_copy.spawn() && !new_B_copy.stuck(); step++)
						rand_move(new_B_copy);
					totalscore += score(new_B_copy);
				}
				if(totalscore > best)
				{
					best = totalscore;
					bestdir = d;
				}
			}
		}

		cout << "moving in direction: " << dir[bestdir] << '\n';
		B.move(dir[bestdir]);
	}

	B.display();
	cout << "Game over!\n";
	return 0;
}
