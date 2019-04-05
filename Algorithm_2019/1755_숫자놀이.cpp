#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
vector<pair<string, int>> ans;
string i2s[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
void push_string(int num) {
	int tmp = num;
	stack<int> s;
	while (num) {
		s.push(num % 10);
		num /= 10;
	}
	string str = "";
	while (s.size()) {
		str += i2s[s.top()];
		s.pop();
		str += " ";
	}
	ans.push_back({ str, tmp });
}
int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	for (int i = m; i <= n; ++i) 
		push_string(i);
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); ++i) {
		printf("%d ", ans[i].second);
		if (i % 10 == 9)
			puts("");
	}
}