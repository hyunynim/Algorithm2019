#include<cstdio>
#include<vector>
using namespace std;
int map[101][101];
bool chk[101][101];
vector<int> blue, white;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };
int n, m;
int bfs(int x, int y) {
	chk[x][y] = 1;
	int res = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && !chk[nx][ny] && map[nx][ny] == map[x][y]) {
			res += bfs(nx, ny);
		}
	}
	return res;
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i) {
		char msg[101];
		scanf("%s", msg);
		for (int j = 0; j < m; ++j) 
			if (msg[j] == 'B')
				map[i][j] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!chk[i][j]) {
				if (map[i][j])
					blue.push_back(bfs(i, j));
				else
					white.push_back(bfs(i, j));
			}
		}
	}
	int w = 0, b = 0;
	for (auto i : blue)
		b += i * i;
	for (auto i : white)
		w += i * i;
	printf("%d %d", w, b);
}