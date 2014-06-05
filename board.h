#ifndef BOARD_H_
#define BOARD_H_


#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

inline bool match(int& a, int& b, int& c, int& d)
{
	bool matched = false;
	if(a != -1 && a == b) a *= 2, b = -1, matched = true;
	if(b != -1 && b == c) b *= 2, c = -1, matched = true;
	if(c != -1 && c == d) c *= 2, d = -1, matched = true;
	return matched;
}
inline bool collapse(int& a, int& b, int& c, int& d)
{
	int A[4], next = 0;
	if(a != -1) A[next++] = a;
	if(b != -1) A[next++] = b;
	if(c != -1) A[next++] = c;
	if(d != -1) A[next++] = d;
	for(int i = next; i < 4; i++) A[i] = -1;

	bool collapsed = false;
	if(a != A[0]) a = A[0], collapsed = true;
	if(b != A[1]) b = A[1], collapsed = true;
	if(c != A[2]) c = A[2], collapsed = true;
	if(d != A[3]) d = A[3], collapsed = true;
	return collapsed;
}

class Board
{
public:
	int board[4][4];
	inline Board()
	{
		srand(time(0));
		for(int r = 0; r < 4; r++)
			for(int c = 0; c < 4; c++)
				board[r][c] = -1;
	}
	inline bool full()
	{
		for(int r = 0; r < 4; r++)
			for(int c = 0; c < 4; c++)
				if(board[r][c] == -1)
					return false;
		return true;
	}
	inline bool stuck()
	{
		if(!full()) return false;
		for(int r = 0; r < 4; r++)
			for(int c = 0; c < 4; c++)
			{
				if(r > 0 && board[r][c] == board[r - 1][c]) return false;
				if(c > 0 && board[r][c] == board[r][c - 1]) return false;
			}
		return true;
	}
	inline bool spawn()
	{
		if(full()) return false;
		int next = (rand() % 10 == 0 ? 4 : 2);
		while(true)
		{
			int r = rand() % 4, c = rand() % 4;
			if(board[r][c] == -1)
			{
				board[r][c] = next;
				return true;
			}
		}
	}
	inline bool move(char dir)
	{
		bool moved = false;
		switch(dir)
		{
		case 'u':
			for(int c = 0; c < 4; c++)
			{
				moved |= collapse(board[0][c], board[1][c], board[2][c], board[3][c]);
				moved |= match(board[0][c], board[1][c], board[2][c], board[3][c]);
				moved |= collapse(board[0][c], board[1][c], board[2][c], board[3][c]);
			}
			break;
		case 'r':
			for(int r = 0; r < 4; r++)
			{
				moved |= collapse(board[r][3], board[r][2], board[r][1], board[r][0]);
				moved |= match(board[r][3], board[r][2], board[r][1], board[r][0]);
				moved |= collapse(board[r][3], board[r][2], board[r][1], board[r][0]);
			}
			break;
		case 'd':
			for(int c = 0; c < 4; c++)
			{
				moved |= collapse(board[3][c], board[2][c], board[1][c], board[0][c]);
				moved |= match(board[3][c], board[2][c], board[1][c], board[0][c]);
				moved |= collapse(board[3][c], board[2][c], board[1][c], board[0][c]);
			}
			break;
		case 'l':
			for(int r = 0; r < 4; r++)
			{
				moved |= collapse(board[r][0], board[r][1], board[r][2], board[r][3]);
				moved |= match(board[r][0], board[r][1], board[r][2], board[r][3]);
				moved |= collapse(board[r][0], board[r][1], board[r][2], board[r][3]);
			}
			break;
		}
		return moved;
	}
	inline void display()
	{
		cout << "+----+----+----+----+\n";
		for(int r = 0; r < 4; r++)
		{
			cout << "|";
			for(int c = 0; c < 4; c++)
			{
				if(board[r][c] == -1) cout << "    " << "|";
				else cout << setw(4) << board[r][c] << "|";
			}
			cout << "\n+----+----+----+----+\n";
		}
		cout << '\n';
	}
};


#endif /* BOARD_H_ */
