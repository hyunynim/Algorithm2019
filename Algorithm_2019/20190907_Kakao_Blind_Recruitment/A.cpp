#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000013999999951;
int solution(string s) {

	int answer = 1e9;
	for (int i = 1; i < s.size(); ++i) {
		vector<pair<ll, int>> cnt;
		for (int j = 0; j <= s.size() - i; j += i) {
			string str = s.substr(j, i);
			ll h = 0;
			for (int k = 0; k < i; ++k) {
				h = h * 26 + (str[k] - 'a');
				h %= mod;
			}
			if (cnt.empty() || cnt.back().first != h)
				cnt.push_back({ h, 1 });
			else
				cnt.back().second++;
		}
		int sum = 0;
		for (int j = 0; j < cnt.size(); ++j) {
			sum += i;
			int tmp = 0;
			if (cnt[j].second == 1) continue;
			while (cnt[j].second) {
				++tmp;
				cnt[j].second /= 10;
			}
			sum += tmp;
		}
		sum += s.size() % i;
		answer = min(answer, sum);
	}
	return answer;
}
int main() {
	string str;
	cin >> str;
	cout << solution(str);
}