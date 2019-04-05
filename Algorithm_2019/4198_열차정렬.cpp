#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
vector<int> seq;
const int minit = 1e9, Minit = -1e9;
int d[2][2020];
int go(int s, int inc, int m, int M) {
	if (s == n - 1) {
		return inc;
	}
	int & res = d[inc][s];
	if (s != 0 && res != -1) return res;
	res = inc;
	int next = seq[s + 1];
	if (m > next) 
		res = max(res, go(s + 1, 1, next, M) + 1);
	if (M < next) 
		res = max(res, go(s + 1, 1, m, next) + 1);
	res = max(res, go(s + 1, 0, m, M));
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	printf("%d", max(go(0, 0, minit, Minit), go(0, 1, seq[0], seq[0])));
}