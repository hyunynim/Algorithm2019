#include<cstdio>
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

int d[3][3][202020];
vector<int> seq;
const int inf = 123456789;
int n;
string ans;
int curCnt = inf;
bool chk(int cnt) {
	for (int i = 1; i < n; ++i)
		if (seq[i] == seq[i - 1])
			return 0;
	if (curCnt > cnt) {
		curCnt = cnt;
		ans = "";
		for (int i = 0; i < n; ++i) {
			if (seq[i] == 0)
				ans += 'R';
			else if (seq[i] == 1)
				ans += 'G';
			else
				ans += 'B';
		}
	}
	return 1;
}
int go(int s, int cnt) {
	if (s == n) {
		if(chk(cnt)) return cnt;
		return inf;
	}
	int cur = seq[s];
	int & res = d[seq[s-1]][cur][s];
	if (res != -1) return res;
	res = inf;
	for (int i = 0; i < 3; ++i) {
		seq[s] = i;
		res = min(res, go(s + 1, i == cur ? cnt : cnt + 1));
		seq[s] = cur;
	}
	return res;
}
int main() {char msg[202020];
	scanf("%d %s", &n, msg);
	memset(d, -1, sizeof(d));
	int cnt = 0;
	for (int i = 1; i < n - 1; ++i) {
		if (msg[i] == msg[i - 1]) {
			char c;
			for (int j = 0; j < 3; ++j) {
				if (j == 0)
					c = 'R';
				else if (j == 1)
					c = 'G';
				else
					c = 'B';
				if (msg[i - 1] != c && msg[i + 1] != c) {
					msg[i] = c;
					++cnt;
					break;
				}
			}
		}
	}
	if (n > 1 && msg[n - 1] == msg[n - 2]) {
		if (msg[n - 2] == 'R')
			msg[n - 1] = 'G';
		else
			msg[n - 1] = 'R';
		++cnt;
	}
	/*
	for (int i = 1; i < n; ++i) {
		if (msg[i] == 'R')
			seq.push_back(0);
		else if (msg[i] == 'G')
			seq.push_back(1);
		else
			seq.push_back(2);
	}
	*/
	printf("%d\n%s", cnt, msg);

}