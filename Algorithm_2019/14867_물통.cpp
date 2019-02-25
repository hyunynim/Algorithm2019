#include<cstdio>
#include<queue>
#include<algorithm>
#include<map>
#include<utility>
#include<tuple>
using namespace std;

int a, b, c, d;
pair<int, int> move(int x, int y, int f) {
	if (f) {
		if (x + y <= b)
			return { 0, x + y };
		else
			return { x + y - b, b };
	}
	else {
		if (x + y <= a)
			return { x + y, 0 };
		else
			return { a, x + y - a };
	}
}

int main() {scanf("%d %d %d %d", &a, &b, &c, &d);
	map<pair<int, int>, int> chk;
	chk[{0, 0}] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	while (q.size()) {
		int x, y, dist;
		tie(x, y, dist) = q.front(); q.pop();
		if (x == c && y == d) {
			printf("%d", dist); return 0;
		}
		if (chk[{a, y}] == 0) {
			chk[{a, y}] = 1;
			q.push({ a, y, dist + 1 });
		}
		if (chk[{x, b}] == 0) {
			chk[{x, b}] = 1;
			q.push({ x, b, dist + 1 });
		}
		if (chk[{0, y}] == 0) {
			chk[{0, y}] = 1;
			q.push({ 0, y, dist + 1 });
		}
		if (chk[{x, 0}] == 0) {
			chk[{x, 0}] = 1;
			q.push({ x, 0, dist + 1 });
		}
		int nx, ny;
		tie(nx, ny) = move(x, y, 0);
		if (chk[{nx, ny}] == 0) {
			chk[{nx, ny}] = 1;
			q.push({ nx, ny, dist + 1 });
		}
		tie(nx, ny) = move(x, y, 1);
		if (chk[{nx, ny}] == 0) {
			chk[{nx, ny}] = 1;
			q.push({ nx, ny, dist + 1 });
		}
	}
	printf("-1");
}