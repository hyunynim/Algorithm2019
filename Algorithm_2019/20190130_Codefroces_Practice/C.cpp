#include<iostream>
#include<algorithm>
#include<tuple>
#include<utility>
#include<functional>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

char msg[1010101];

int main() {
	int n; string str;
	string col[6] = { "", "", "" };
	cin >> n;
	cin >> str;
	int cnt[6] = { 0 };
	for (int i = 0; i < n; ++i) {
		switch (i % 3) {
		case 0:
			col[0] += 'R';
			col[1] += 'R';
			col[2] += 'G';
			col[3] += 'G';
			col[4] += 'B';
			col[5] += 'B';
			break;
		case 1:
			col[0] += 'G';
			col[1] += 'B';
			col[2] += 'R';
			col[3] += 'B';
			col[4] += 'R';
			col[5] += 'G';
			break;
		case 2:
			col[0] += 'B';
			col[1] += 'G';
			col[2] += 'B';
			col[3] += 'R';
			col[4] += 'G';
			col[5] += 'R';
			break;
		}
		for (int j = 0; j < 6; ++j) {
			if (str[i] != col[j][i])
				cnt[j]++;
		}
	}
	int m = min({ cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5] });
	cout << m << endl;
	for (int i = 0; i < 6; ++i) {
		if (m == cnt[i]) {
			cout << col[i];
			return 0;
		}
	}
}