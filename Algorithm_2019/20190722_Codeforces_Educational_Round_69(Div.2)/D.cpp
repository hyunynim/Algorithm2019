#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> PL; 
ll n, m, k;
ll d[1010101];
vector<ll> seq, sum;
ll calc(int cnt) {
	return k * (cnt / m + (cnt % m != 0));
}
ll go(int s, int cnt, ll sum) {
	if (s == n)
		return sum - calc(cnt);
	ll& res = d[s];
	res = 0;
	res = max({sum - calc(cnt), go(s + 1, cnt + 1, sum + seq[s]), go(s + 1, 1, seq[s])});
	return res;
}
int main(){
	memset(d, -1, sizeof(d));
	scanf("%lld %lld %lld", &n, &m, &k);
	seq.resize(n);
	sum.resize(n + 1);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &seq[i]);
		sum[i + 1] = sum[i] + seq[i];
	}
	printf("%lld", go(0, 0, 0));
}