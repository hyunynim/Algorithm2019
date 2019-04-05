#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
struct POS {
	int x, y;
};
vector<POS> seq;
int dist(POS p1, POS p2) {
	return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
int go(int s, int e) {
	if (e - s == 1)
		return dist(seq[s], seq[e]);
	else if (e - s == 2) 
		return min({ dist(seq[s], seq[s + 1]), dist(seq[s + 1], seq[e]), dist(seq[s], seq[e]) });
	int mid = (s + e) / 2;
	int res = min(go(s, mid), go(mid + 1, e));
	int midLine = (seq[mid].x + seq[mid + 1].x) / 2;
	vector<POS> tmp;
	for (int i = s; i <= e; ++i) {
		int d = midLine - seq[i].x;
		if (d * d < res) tmp.push_back(seq[i]);
	}
	sort(tmp.begin(), tmp.end(), [](POS p1, POS p2) {
		return p1.y < p2.y;
	});
	for (int i = 0; i < tmp.size(); ++i) 
		for (int j = i + 1; j < tmp.size() && tmp[j].y - tmp[i].y < res; ++j) 
			res = min(res, dist(tmp[i], tmp[j]));
	
	return res;
}
int main() {
	int n; scanf("%d", &n);
	seq.resize(n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &seq[i].x, &seq[i].y);
	sort(seq.begin(), seq.end(), [](POS p1, POS p2) {
		return p1.x < p2.x;
	});
	printf("%d", go(0, n - 1));
}