#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[10101010];
int visit[10101010];
void print(int s) {
	stack<int> st;
	while (visit[s]) {
		st.push(s);
		s = visit[s];
	}
	while (st.size()) {
		cout << st.top() << ' ';
		st.pop();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	memset(d, 0x3f, sizeof(d));
	ll n, x, y;
	cin >> n >> x >> y;
	d[0] = 0;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) {
//			d[i] = min(d[i - 1] + x, d[(i + 1) / 2] + x + y);
			if (d[i - 1] + x > d[(i + 1) / 2] + x + y) {
				d[i] = d[(i + 1) / 2] + x + y;
				visit[i + 1] = (i + 1) / 2;
				visit[i] = i + 1;
			}
			else {
				d[i] = d[i - 1] + x;
				visit[i] = i - 1;
			}
		}
		else {
//			d[i] = min(d[i - 1] + x, d[i / 2] + y);
			if (d[i - 1] + x > d[i / 2] + y) {
				d[i] = d[i / 2] + y;
				visit[i] = i / 2;
			}
			else {
				d[i] = d[i - 1] + x;
				visit[i] = i - 1;
			}
		}
	}
	cout << d[n] << '\n';
	freopen("res.txt", "w", stdout);
	print(n);
}