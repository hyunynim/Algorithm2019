#include<map>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

map<string, pair<string, int>> group;
map<string, int> gNumber;
vector<string> member[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string mem, g;
		int k;
		cin >> g >> k;
		gNumber[g] = i;
		for (int j = 0; j < k; ++j) {
			cin >> mem;
			group[mem] = { g, i };
			member[i].push_back(mem);
		}
		sort(member[i].begin(), member[i].end());
	}
	for (int i = 0; i < m; ++i) {
		string s; int k;
		cin >> s >> k;
		if (k)
			cout << group[s].first << '\n';
		else {
			int gNum = gNumber[s];
			for (int j = 0; j < member[gNum].size(); ++j)
				cout << member[gNum][j] << '\n';
		}
	}
}