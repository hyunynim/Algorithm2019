#include<cstdio>
int d[11][1010];
int mul[]{ 2, 3, 2, 3, 4, 3, 3, 3, 2, 1 };
const int mod = 1234567;
int main() {
	int t; scanf("%d", &t);
	for (int i = 1; i <= 10; ++i) {
		d[i][1] = 1;
		d[0][1] += d[i][1];
	}
	for (int i = 2; i <= 1000; ++i) {
		d[1][i] = d[2][i - 1] + d[4][i - 1];
		d[2][i] = d[1][i - 1] + d[3][i - 1] + d[5][i - 1];
		d[3][i] = d[2][i - 1] + d[6][i - 1];
		d[4][i] = d[1][i - 1] + d[5][i - 1] + d[7][i - 1];
		d[5][i] = d[2][i - 1] + d[4][i - 1] + d[6][i - 1] + d[8][i - 1];
		d[6][i] = d[3][i - 1] + d[5][i - 1] + d[9][i - 1];
		d[7][i] = d[4][i - 1] + d[8][i - 1] + d[10][i - 1];
		d[8][i] = d[5][i - 1] + d[7][i - 1] + d[9][i - 1];
		d[9][i] = d[6][i - 1] + d[8][i - 1];
		d[10][i] = d[7][i - 1];
		for (int j = 1; j <= 10; ++j) {
			d[j][i] %= mod;
			d[0][i] += d[j][i];
			d[0][i] %= mod;
		}
	}
	while (t--) {
		int num; scanf("%d", &num);
		printf("%d\n", d[0][num]);
	}
}