#include<bits/stdc++.h>
using namespace std;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	int m = key.size(), n = lock.size();
	bool answer = true;
	vector<vector<int>> kr[4];
	kr[0] = key;
	for (int i = 1; i < 4; ++i) {
		kr[i].resize(key.size());
		for (int tmp = 0; tmp < key.size(); ++tmp)
			kr[i][tmp].resize(key.size());
		for (int j = 0; j<key.size(); ++j)
			for(int k = 0; k<key.size(); ++k)
				kr[i][k][key.size() - 1 - j] = kr[i-1][j][k];
	}
	int cnt = 0;
	for (int i = 0; i < lock.size(); ++i) {
		for (int j = 0; j < lock.size(); ++j) {
			if (lock[i][j] == 0) {
				++cnt;
			}
		}
	}
	puts("");
	for (int i = 0; abs(i) < lock.size() * 2; ++i) {
		for (int j = 0; abs(j) < lock.size() * 2; ++j) {
			for (int num = 0; num < 4; ++num) {
				int sum = 0;
				for (int k = 0; k < key.size(); ++k) {
					bool stop = 0;
					for (int l = 0; l < key.size(); ++l) {
						if (0 > i - n + k || i - n + k >= n || j - n + l < 0 || j - n + l >= n) continue;
						if (kr[num][k][l] == lock[i - n + k][j - n + l]) {
							stop = 1;
							break;
						}
						else if (kr[num][k][l] != lock[i - n + k][j - n + l] && kr[num][k][l])
							++sum;
					}
					if (stop) break;
				}
				if (sum == cnt) return 1;
			}
		}
	}
	return 0;
}
int main() {
	vector<vector<int>> k(3), a(3);
	for (int i = 0; i < 3; ++i) {
		k[i].resize(3);
		for (int j = 0; j < 3; ++j)
			cin >> k[i][j];
	}
	for (int i = 0; i < 3; ++i) {
		a[i].resize(3);
		for (int j = 0; j < 3; ++j)
			cin >> a[i][j];
	}
	cout << solution(k, a);
}
