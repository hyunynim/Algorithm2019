#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 50000);
uniform_int_distribution<int> d2(0, 9);
ll d[2][50505];
vector<int> seq;
struct OP {
	int op, cur, prev;
};
ll go(int op, int cur, int prev) {
	if (cur == seq.size()) return prev;
	ll& res = d[op][cur];
	if (~res) return res;
	res = min(go(0, cur + 1, 0) + seq[cur] + prev, go(1, cur + 1, 2) + 9 - seq[cur]);
	return res;
}
void solve() {
	memset(d, -1, sizeof(d));
	string str; cin >> str;
	for (auto c : str)
		seq.push_back(c - '0');
	cout << min(go(0, 0, 0), go(1, 0, 0));
}
int main() {
#ifdef TESTING
	solve();
	return 0;
#endif
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
/*		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		if (cnt <= 3)
			n = 0;
		else if (cnt <= 6)
			n = 50000;
		string str = "";
		if (cnt == 3)
			str = "0";
		else 
			for (int i = 0; i < n; ++i)
				str.push_back(d2(gen) + '0');
		printf("%s\n", str.c_str());
		fclose(fp);


*/		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		seq.clear();
		if (cnt > 20) break;
	}
}