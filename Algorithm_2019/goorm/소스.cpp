#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[1000005];
int n, k;
int start = 1e6;
ll chk(vector<int>& seq, int mid) {
	ll sum = 0;
	for (int i = 0; i < seq.size(); ++i)
		sum += min(mid, seq[i]);
	return sum;
}
void solve() {
	int n; cin >> n;
	vector<int> seq(n);
	int l = 0, r = 0, s, sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> seq[i];
		r = max(r, seq[i]);
		sum += seq[i];
	}
	cin >> s;
	if (s >= sum) { //예외처리: 전체 인원의 합이 K보다 작은 경우
		cout << r; return;
	}
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (chk(seq, mid) > s)
			r = mid - 1;
		else {
			l = mid + 1;
			ans = mid;
		}
	}
	cout << ans; 
}

ll calculate(int mid) {
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		sum += min(arr[i], mid);
	}
	return sum;
}

int main() {
	freopen("goorm/10월 2주차/프로그래밍 경진대회/input.4.txt", "r", stdin);
	solve();
	return 0;
	scanf("%d", &n);
	int maxans = 0, sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxans = max(arr[i], maxans);
		sum += arr[i];
	}

	scanf("%d", &k);
	if (k >= sum) {
		printf("%d", maxans);
		return 0;
	}

	int start = 0, end = maxans;
	int ans = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		ll temp = calculate(mid);
		if (temp > k) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			ans = mid;
		}
	}
	printf("%d", ans);
	return 0;
}