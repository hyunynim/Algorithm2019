#include<cstdio>
#include<string>
#include<stack>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	stack<char> s;
	while (~scanf("%1d", &n))
		s.push(n + '0');
	string ans = "";
	while (s.size()) {
		ans += s.top();
		++cnt;
		if (cnt == 3) {
			ans.push_back(',');
			cnt = 0;
		}
		s.pop();
	}
	if (ans.back() == ',') ans.pop_back();
	reverse(ans.begin(), ans.end());
	printf("%s", ans.c_str());
}