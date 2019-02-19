#include<algorithm>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string, int> p;
int price[4][4] = {		{100, 70, 40, 0},
						{70, 50, 30, 0},
						{40, 30, 20, 0},
						{0, 0, 0, 0}};
string bean[21];
int n;
int d[1 << 14][14 * 14];
const int inf = -1234567890;
int go(int mask, int cur) {
	if (cur == n * n) {
		if (mask == 0) return 0;
		else return inf;
	}
	int & res = d[mask][cur];
	if (res != -1) return res;
	res = 0;
	int ny = cur / n;
	int nx = cur % n;
	if (nx != n - 1 && mask % 2 == 0) {
		if (mask & 2);
		else {
			string str = "";
			str += bean[ny][nx];
			str += bean[ny][nx + 1];
			res = max(res, go(mask >> 2, cur + 2) + p[str]);
		}
	}
	if (ny != n - 1 && mask % 2 == 0) {
		string str = "";
		str += bean[ny][nx];
		str += bean[ny + 1][nx];
		res = max(res, go((mask >> 1) | (1 << (n - 1)), cur + 1) + p[str]);
	}
	res = max(res, go(mask >> 1, cur + 1));
	return res;
}

int main() {
	memset(d, -1, sizeof(d));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s = "ABCF";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			string str = "";
			str += s[i];
			str += s[j];
			p[str] = price[i][j];
		}
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> bean[i];
	cout << go(0, 0);
}