#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(0, 9);
vector<int> seq[8];
int chk[202020];
int m = 199;
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[] = { -1, 1, -1, 1, 1, -1, 0, 0 };
void go(int x, int y, int toPick, int cur) {
	if (x < 0 || y < 0 || x >= 8 || y >= 14) return;
	chk[cur] = 1;
	if (toPick == 0)
		return;
	for (int i = 0; i < 8; ++i) {
		int nx = x + dx[i], ny = y + dy[i];
		go(nx, ny, toPick - 1, cur * 10 + seq[x][y]);
	}
}
void solve() {
	//TODO
	memset(chk, 0, sizeof(chk));
	for (int j = 0; j < 8; ++j)
		for (int k = 0; k < 14; ++k)
			go(j, k, 5, 0);
}
int main() {
	while (1) {
		for (int i = 0; i < 8; ++i)
			for (int j = 0; j < 14; ++j)
				seq[i].push_back(d1(gen));
		solve();
		int res = 0;
		for (int i = 1; i < 202020; ++i) {
			if (chk[i] == 0) break;
			res = i;
		}
		if (m < res) {
			m = res;
			char msg[1010];
			sprintf(msg, "./icecream/%d.txt", m);
			FILE* fp = fopen(msg, "a");
			for (int i = 0; i < 8; ++i) {
				for (int j = 0; j < 14; ++j)
					fprintf(fp, "%d", seq[i][j]);
				fprintf(fp, "\n");
			}
			fclose(fp);
		}
		for (int i = 0; i < 8; ++i)
			seq[i].clear();
	}
}