#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[202020] = { 0 };
vector<int> adj[202020];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

}