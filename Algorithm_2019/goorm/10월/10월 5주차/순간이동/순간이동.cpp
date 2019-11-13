#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(0, 10000000);
int chk[10101010];
void solve() {
	//TODO
	memset(chk, 0, sizeof(chk));
	int n, k; cin >> n >> k;
	queue<int> q;
	q.push(n);
	chk[n] = 1;
	while (q.size()) {
		int cur = q.front();
		if (cur == k) {
			cout << chk[cur] - 1;
			while (q.size()) q.pop();
			return;
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
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
/*		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen), k = d1(gen);
		if (cnt <= 3) {
			n = rand() % 100 + 1;
			k = rand() % 100;
		}
		if (cnt == 18) {
			n = 9997979;
			k = 0;
		}
		else if (cnt == 19) {
			n = 0;
			k = 9997979;
		}
		else if (cnt == 20) {
			n = k = 0;
		}
		printf("%d %d", n, k);
		fclose(fp);
*/

		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 20) break;
	}
}