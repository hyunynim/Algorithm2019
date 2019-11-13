#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<ll> d(10, (ll)1e16);
void solve() {
	ll n;
	int k; cin >> n >> k;
	ll box[33];
	for (int i = 0; i < k; ++i)
		cin >> box[i];
	ll ans = 0;
	for (int i = k - 1; i >= 0; --i) {
		ans += (n / box[i]);
		n %= box[i];
	}
	cout << ans;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE * fp = freopen(msg, "w", stdout);
		vector<ll> seq;
		ll n = d(gen);
		int k = rand() % 29 + 2;
		seq.push_back(1);
		printf("%lld %d\n%lld ", n, k, seq.back());
		for (int i = 0; i < k - 1; ++i) {
			seq.push_back(seq.back() * (rand() % 4 + 2));
			printf("%lld ", seq.back());
		}
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if (cnt > 100) break;
	}
}