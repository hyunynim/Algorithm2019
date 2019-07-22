#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char msg[1010101];
int main() {
	string msg;
	cin >> msg;
	int sum = 0;
	vector<ll> seq, pref(1);
	for (int i = 0; i < msg.size(); ++i) {
		if (msg[i] == 'v')
			++sum;
		else {
			seq.push_back(sum);
			sum = 0;
		}
	}
	if (sum) seq.push_back(sum);
	for (int i = 0; i < seq.size(); ++i) {
		if(seq[i])
			--seq[i];
		pref.push_back(pref.back() + seq[i]);
	}
	ll ans = 0;
	for (int i = 1; i < pref.size(); ++i) {
		ans += pref[i] * (pref.back() - pref[i]);
	}
	cout << ans;
}