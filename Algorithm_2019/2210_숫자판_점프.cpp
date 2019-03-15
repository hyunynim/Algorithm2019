#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

int board[5][5];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
set<int> chk;
void go(int toPick, int x, int y, int cur){
	if (toPick == 0){
		chk.insert(cur);
		return;
	}

	for (int i = 0; i < 4; ++i){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < 5 && 0 <= ny && ny < 5){
			cur *= 10;
			cur += board[nx][ny];
			go(toPick - 1, nx, ny, cur);
			cur /= 10;
		}
	}
}

int main(){
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			scanf("%d", &board[i][j]);

		for (int i = 0; i < 5; ++i){
			for (int j = 0; j < 5; ++j){
				go(6, i, j, 0);
			}
		}

		printf("%d", chk.size());
}
