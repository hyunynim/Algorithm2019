#include<vector>
#include<algorithm>
#include<utility>

using namespace std;

#define MAX_V 12345

vector<pair<int, int>> edge[MAX_V];
bool chk[MAX_V];

void dfs(int start) {
	chk[start] = 1;
	printf("%d ", start);
	for (int i = 0; i < edge[start].size(); ++i) {
		int next = edge[start][i].first;
		if (!chk[next])
			dfs(next);
	}
}