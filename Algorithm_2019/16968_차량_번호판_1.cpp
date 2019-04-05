#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<string> ans;
char msg[10];
void go(int s, string & picked) {
	if (msg[s] == '\0')
		ans.push_back(picked);
	else {
		if (msg[s] == 'c') {
			for (int i = 11; i < 37; ++i) {
				if (s > 0 && picked.back() == i) continue;
				picked.push_back(i);
				go(s + 1, picked);
				picked.pop_back();
			}
		}
		else {
			for (int i = 1; i < 11; ++i) {
				if (s > 0 && picked.back() == i) continue;
				picked.push_back(i);
				go(s + 1, picked);
				picked.pop_back();
			}
		}
	}
}
int main() {
	scanf("%s", msg);
	int toPick = 0;
	for (; msg[toPick] != '\0'; ++toPick);
	string tmp;
	go(0, tmp);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	printf("%d", ans.size());
}