#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> seq;
int n, h;

int main() {
	scanf("%d %d", &n, &h);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	priority_queue<int> l, r;
	reverse(seq.begin(), seq.end());
	l.push(seq.back());
	seq.pop_back();
	int totH = seq[0];
	while (1) {
		while (seq.size() && totH < h) {
			l.push(seq.back());
			totH += seq.back();
			seq.pop_back();
		}
	}
}