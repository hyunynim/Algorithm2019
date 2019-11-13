#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(2, 10000);
uniform_int_distribution<int> d2(1, 100);
vector<int> seq;
int n, a;
bool chk[10101];
bool go(int s) {
	if (s == n - 1) return 1;
	if (chk[s]) return 0;
	chk[s] = 1;
	for (int i = 1; i <= a; ++i) {
		int nx = s + i;
		if (nx < n && seq[nx])
			if(go(nx)) return 1;
	}
	return 0;
}
bool solve() {
	memset(chk, 0, sizeof(chk));
	//TODO
	cin >> n >> a;
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	if (go(0)) {
		cout << "yes";
		return 1;
	}
	else {
		cout << "no";
		return 0;
	}
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 1, tmp;
	bool aChk = 1;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		int a = d2(gen);
		if (cnt <= 3) {
			n = rand() % 10 + 5;
			a = rand() % 3 + 1;
		}
		else if (cnt <= 6)
			n = 10000;

		printf("%d %d\n1 ", n, a);
		for(int i = 0; i<n - 2; ++i)
			printf("%d ", rand() % 2);
		printf("1 ");
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if (aChk ^ solve())
			--cnt;
		else
			aChk ^= 1;
		if (cnt > 10) break;
	}
}