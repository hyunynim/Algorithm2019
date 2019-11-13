#include<bits/stdc++.h>
#include<random>
#include<unordered_map>
using namespace std;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 1000000);
uniform_int_distribution<int> d2(1, 1000000000);
bool solve() {
	int n, k, c; cin >> n >> k >> c;
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	sort(seq.begin(), seq.end());
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		int key; cin >> key;
		if (binary_search(seq.begin(), seq.end(), key))
			++cnt;
	}
	if (cnt >= c) {
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
	int cnt = 5, tmp;
	bool flag = 0;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);
		int n = d1(gen);
		if (cnt == 1)
			n = 6;
		else if (cnt <= 3)
			n = rand() % 10 + 5;
		else if (cnt <= 5)
			n = 1000000;
		uniform_int_distribution<int> d3(1, n);
		int k = d1(gen);
		if (cnt <= 3)
			k = rand() % 10 + 5;
		else if (cnt <= 5)
			k = 1000000;
		int c = d3(gen);
		uniform_int_distribution<int> d4(c, n);
		if (cnt > 3 && cnt % 2)
			while (k < c)
				k = d4(gen);
		vector<int> seq;
		unordered_map<int, int> chk;
		printf("%d %d %d\n", n, k, c);
		for (int i = 0; i < n; ++i) {
			int num;
			do {
				num = d2(gen);
				if (cnt <= 3)
					num = rand() % 100 + 1;
			} while (chk[num]);
			chk[num] = 1;
			seq.push_back(num);
			printf("%d ", num);
		}
		puts("");
		uniform_int_distribution<int> d5(0, seq.size() - 1);
		for (int i = 0; i < k; ++i) {
			int num = d2(gen);
			if (cnt <= 3)
				num = rand() % 100 + 1;
			if (cnt % 2) {
				num = d5(gen);
				printf("%d ", seq[num]);
			}
			else
				printf("%d ", num);
		}
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if (flag == solve())
			--cnt;
		else
			flag ^= 1;
		chk.clear();
		seq.clear();
		if (cnt > 10) break;
	}
}