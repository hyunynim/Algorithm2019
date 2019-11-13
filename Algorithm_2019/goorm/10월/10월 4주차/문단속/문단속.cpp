#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d(1, 1000000);

bool solve() {
	//TODO
	int n, num; scanf("%d", &n);
	stack<int> s;
	for (int i = 0; i < 2 * n; ++i) {
		scanf("%d", &num);
		if (num > 0)
			s.push(num);
		else {
			if (s.empty() || s.top() != -num) {
				printf("no");
				return 0;
			}
			s.pop();
		}
	}
	if (s.empty())
		printf("yes");

	else
		printf("no");

	return !s.empty();
}
void makeit(int n) {
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		seq[i] = i + 1;
	random_shuffle(seq.begin(), seq.end());
	stack<int> s;
	while(seq.size()){
		bool open = rand() % 2;
		if (open) {
			printf("%d ", seq.back());
			s.push(seq.back());
			seq.pop_back();
		}
		else {
			if (s.empty()) continue;
			printf("%d ", -s.top());
			s.pop();
		}
	}
	while (s.size()) {
		printf("%d ", -s.top());
		s.pop();
	}
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 3, tmp;
	bool chk = 1;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d(gen);
		if (cnt <= 3)
			n = rand() % 5 + 5;
		else if (cnt <= 6)
			n = 1000000;
		printf("%d\n", n);
		if (chk)
			makeit(n);
		else {
			vector<int> seq(n);
			for (int i = 0; i < n; ++i) {
				seq[i] = i + 1;
				seq.push_back(-(i + 1));
			}
			random_shuffle(seq.begin(), seq.end());
			for (int i = 0; i < seq.size(); ++i)
				printf("%d ", seq[i]);
			seq.clear();
		}
		fclose(fp);
		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		solve();
		if (cnt > 10) break;
		chk ^= 1;
	}
}