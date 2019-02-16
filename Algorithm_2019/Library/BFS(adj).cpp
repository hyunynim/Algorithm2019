#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
using namespace std;

#define MAX_V 12345

vector<pair<int, int>> edge[MAX_V];
bool chk[MAX_V];

void bfs(int start) {
	queue<int> q;
	chk[start] = 1; q.push(start);
	while (q.size()) {
		int cur = q.front(); q.pop();
		printf("%d ", cur);
		for (int i = 0; i < edge[cur].size(); ++i) {
			int next = edge[cur][i];
			if (!chk[next]) {
				chk[next] = 1; q.push(next);
			}
			else
				edge[cur].erase(edge[cur].begin() + i);
		}
	}
}