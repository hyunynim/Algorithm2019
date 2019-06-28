#include<bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string str, msg;
	cin >> str >> msg;
	priority_queue<pair<int, int>> q;
	for (int i = 0; i < str.size(); ++i)
		q.push({ -str[i], -i });
	int sz = msg.size() / str.size();
	vector<string> seq(sz);
	for (int i = 0; i < msg.size(); ++i) 
		seq[i % sz].push_back(msg[i]);
	int i = 0;
	while (q.size()) {
		int k = -q.top().second; q.pop();
		str[k] = i++;
	}
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < str.size(); ++j)
			cout << seq[i][str[j]];
	}
}