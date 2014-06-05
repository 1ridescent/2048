#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

char dir[4] = { 'u', 'r', 'd', 'l' };

int main()
{
	srand(time(0));
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		int next = rand() % 4;
		printf("%c", dir[next]);
	}
}
