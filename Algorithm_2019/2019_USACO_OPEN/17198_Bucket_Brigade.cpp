#include<bits/stdc++.h>
using namespace std;
struct POS {
	int x, y, d;
};
char farm[11][11];
bool chk[11][11];
int main() {
	queue<POS> q;
	for (int i = 0; i < 10; ++i) {
		scanf("%s", farm[i]);
		for (int j = 0; j < 10; ++j) {
			if (farm[i][j] == 'L') {
				q.push({ i, j, 0 });
				chk[i][j] = 1;
			}
		}
	}
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1, 1, 0, 0 };
	while (q.size()) {
		int x = q.front().x, y = q.front().y, d = q.front().d; q.pop();
		if (farm[x][y] == 'B') {
			printf("%d", d - 1); return 0;
		}
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < 10 && 0 <= ny && ny < 10 && !chk[nx][ny] && farm[nx][ny] == '.' || farm[nx][ny] == 'B') {
				chk[nx][ny] = 1;
				q.push({ nx, ny, d + 1 });
			}
		}
	}

}