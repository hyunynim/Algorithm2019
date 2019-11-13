#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
struct POS {
	P p1, p2;
	POS operator=(POS p) {
		p1 = p.p1;
		p2 = p.p2;
	}
};
POS nx[] = {
	{ {1, 0}, {1, 0} }, { {1, 1}, {0, 0}}, {{0, 0}, {1, -1}},
	{ {0, 1}, {0, 1}}, {{0,0},{-1,1}}, {{1,1},{0,0}},
	{ {-1,0},{-1,0}}, {{0,0},{-1,-1}}, {{-1,1},{0,0}},
	{ {0,-1},{0,-1}},{{1,-1},{0,0}},{{0,0},{-1,-1}}
};
POS nxChk[] = {
	{{1, 0}, {1, 0}},{{1, 0}, {1, 0}},{{1, 0}, {1, 0}},
	{{0, 1}, {0, 1}},{{0, 1}, {0, 1}},{{0, 1}, {0, 1}},
	{{-1, 0}, {-1, 0}},{{-1, 0}, {-1, 0}},{{-1, 0}, {-1, 0}},
	{{0, -1}, {0, -1}},{{0, -1}, {0, -1}},{{0, -1}, {0, -1}}
};
bool chk[100][100][100][100];
P operator+(P p1, P p2) {
	return { p1.first + p2.first, p1.second + p2.second };
}
POS operator+(POS p1, POS p2) {
	POS tmp = { p1.p1 + p2.p1, p1.p2 + p2.p2 };
	if (tmp.p1 > tmp.p2) swap(tmp.p1, tmp.p2);
	return tmp;
}
bool vaild(POS p, int n) {
	return 0 <= p.p1.first && p.p1.first < n
		&& 0 <= p.p1.second && p.p1.second < n
		&& 0 <= p.p2.first && p.p2.first < n
		&& 0 <= p.p2.second && p.p2.second < n;
}
int solution(vector<vector<int>> board) {
	int answer = 0;
	int n = board.size();
	queue<pair<POS, int>> q;
	POS tmp = { {0, 0}, {0, 1} };
	q.push(make_pair(tmp, 0));
	chk[0][0][0][1] = 1;
	while (q.size()) {
		POS cur = q.front().first;
		int d = q.front().second;
		if ((cur.p1.first == n - 1 && cur.p1.second == n - 1)
			|| (cur.p2.first == n - 1 && cur.p2.second == n - 1))
			return d;
		q.pop();
		bool f = cur.p1.first == cur.p2.first;
		for (int i = 0; i < 12; ++i) {
			if (f && i % 3 && (i / 3) % 2) continue;
			if (!f && i % 3 && (i / 3) % 2 == 0) continue;
			POS next = cur + nx[i];
			POS check = cur + nxChk[i];
			bool c1 = vaild(next, board.size());
			bool c2 = vaild(check, board.size());
			
			bool c3 = c1 ? chk[next.p1.first][next.p1.second][next.p2.first][next.p2.second] : 1;
			bool c4 = c2 ? board[check.p1.first][check.p1.second] || board[check.p2.first][check.p2.second] : 1;
			if (c1 && c2 && !c3 && !c4) {
				chk[next.p1.first][next.p1.second][next.p2.first][next.p2.second] = 1;
				q.push({ next, d + 1 });
			}
		}
	}
	return answer;
}
int main() {
	int n; cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < n; ++i) {
		v[i].resize(n);
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	}
	cout << solution(v);
}