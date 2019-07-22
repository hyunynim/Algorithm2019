#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str, ans;
vector<string> seq(6);
int cnt[6][2][1010101];
int palindrome(int left, int right, string & msg) {
	int len = (left == right ? 1 : 2);
	int prev = msg[left];
	int s = left;
	int e = right;
	while (true) {
		s--;
		e++;
		if (s == -1 || e == msg.size() || msg[s] != msg[e]) break;
		len += 2;
		prev = msg[s];
	}
	return len;
}
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		int chk[6] = { 0 };
		if (str[i] == 'a') {
			seq[0].push_back('a');
			seq[3].push_back('a');
			seq[4].push_back('a');
			chk[3] = 1;
		}
		else if (str[i] == 'b') {
			seq[1].push_back('b');
			seq[3].push_back('b');
			seq[5].push_back('b');
			chk[4] = 1;
		}
		else {
			seq[2].push_back('c');
			seq[4].push_back('c');
			seq[5].push_back('c');
			chk[5] = 1;
		}
		cnt[3][0][i + 1] = cnt[3][0][i] + chk[3];
		cnt[3][1][i + 1] = cnt[3][1][i] + chk[4];
		cnt[4][0][i + 1] = cnt[4][0][i] + chk[3];
		cnt[4][1][i + 1] = cnt[4][1][i] + chk[5];
		cnt[5][0][i + 1] = cnt[5][0][i] + chk[4];
		cnt[6][1][i + 1] = cnt[5][1][i] + chk[5];
	}
	int least = str.size() / 2 - (str.size() % 2);
	for (int i = 0; i < 6; ++i) {
		if (i < 3) {
			if (seq[i].size() >= least) {
				cout << seq[i]; return 0;
			}
		}
		else {
			for (int j = 1; j <= seq[i].size(); ++j) {
				int c1 = cnt[i][0][j];
				int c2 = cnt[i][1][]
			}
		}
	}
}

