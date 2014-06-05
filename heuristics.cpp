#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "board.h"

using namespace std;

const char dir[4] = { 'u', 'r', 'd', 'l' };

#define HEURISTIC_TYPE 2

int main()
{
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
				long long totalscore;

				switch(HEURISTIC_TYPE)
				{
				case 1: // distance heuristic
					{
						totalscore = 2000000000;
						for(int r1 = 0; r1 < 4; r1++)
							for(int c1 = 0; c1 < 4; c1++)
								for(int r2 = 0; r2 < 4; r2++)
									for(int c2 = 0; c2 < 4; c2++)
										if(new_B.board[r1][c1] == new_B.board[r2][c2])
											totalscore -= new_B.board[r1][c1] * (abs(r1 - r2) + abs(c1 - c2));
					}
					break;
				case 2:
					{
						totalscore = 0;
						for(int r = 0; r < 4; r++)
							for(int c = 0; c < 4; c++)
								totalscore += (1 << (4 * r + c)) * new_B.board[r][c];
					}
					break;
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
