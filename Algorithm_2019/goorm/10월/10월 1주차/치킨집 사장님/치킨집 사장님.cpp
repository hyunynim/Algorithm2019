#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);
const ll mod = 1e9 + 7;
ll d[1010101];
int main() {
//	int n; cin >> n;
	d[1] = d[2] = 1;
	for (int i = 3; i <= 1000000; ++i) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= mod;
	}
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d1(gen);
		if (cnt == 1) n = 3;
		else if (cnt == 2) n = 1000;
		else if (cnt == 3) n = 42;
		else if (cnt == 20) n = 1000000;
		else if (cnt == 19) 987654;
		else if (cnt == 10) n = 1;
		cout << n;
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		cout << d[n];
		if (cnt > 20) break;
	}
}