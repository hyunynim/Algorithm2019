#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;
int status[101][101];
int d[20][1 << 20];
int ans = 2e9;
int n;
int abs(int a) { return a > 0 ? a : -a; }
int go(int s, int stat) {
	if (s == n) {
		int score[2] = { 0 };
		bool chk[20] = { 0 };
		for (int i = 0; i < n; ++i)
			if (stat & (1 << i))
				chk[i] = 1;
		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j) 
				if (chk[i] == chk[j])
					score[chk[i]] += status[i][j];
		return abs(score[0] - score[1]);
	}
	int & res = d[s][stat];
	if (res != -1)
		return res;
	res = min(go(s + 1, stat | (1 << s)), go(s + 1, stat));
	return res;
}
int main() {
	scanf("%d", &n);
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &status[i][j]);
	printf("%d", go(0, 0));
}