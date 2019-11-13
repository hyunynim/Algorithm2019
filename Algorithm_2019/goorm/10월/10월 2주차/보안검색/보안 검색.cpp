#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);
uniform_int_distribution<ll> d2(1, 1e16);
ll chk(vector<ll> & seq, ll mid) {
	ll res = 0;
	for (int i = 0; i < seq.size(); ++i)
		res += mid / seq[i];
	return res;
}
void solve() {
	int n; ll k; cin >> n >> k;
	vector<ll> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	ll l = 0, r = 1e18;
	ll ans = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (chk(seq, mid) >= k) {
			ans = min(ans, mid);
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 10, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d1(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1;
		ll k = d2(gen);
		if (cnt <= 3)
			k = rand() % 100 + 5;
		else if (cnt <= 6)
			k = 1000000;
		cout << n << ' ' << k << endl;
		for (int i = 0; i < n; ++i)
			cout << (cnt <= 3 ? rand()%5 + 1 : d1(gen)) << ' ';
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
	}
}