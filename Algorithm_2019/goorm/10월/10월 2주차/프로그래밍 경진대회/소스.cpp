#include<queue>
#include<iostream>
using namespace std;
int chk[10101010];
int main() {
	int n, k; cin >> n >> k;
	queue<int> q;
	q.push(n);
	chk[n] = 1;
	while (q.size()) {
		int cur = q.front();
		if (cur == k) {
			cout << chk[cur] - 1;
			return 0;
		}
		q.pop();
		int nx[] = { cur / 3, cur / 2, cur - 1, cur + 1, cur * 2, cur * 3 };
		for (int i = 0; i < 6; ++i) {
			if ((i == 0 && cur % 3)
				|| (i == 1 && cur % 2)) continue;
			if (0 <= nx[i] && nx[i] <= 10000000 && chk[nx[i]] == 0) {
				chk[nx[i]] = chk[cur] + 1;
				q.push(nx[i]);
			}
		}
	}
}