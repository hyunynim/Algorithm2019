#include<bits/stdc++.h>
using namespace std;
vector<int> seq;
int d[10101];
int go(int s) {
	if (s == seq.size())
		return 1;
	int & res = d[s];
	if ((s == 0 && seq[s] == 0) ||
		(s && seq[s] == 0 && seq[s - 1] > 2))
		return -1e9;
	else if (seq[s] == 0)
		return 0;
	if (res != -1)
		return res;
	res = 0;
	if (seq[s] == 1)
		res = go(s + 1) + go(s + 2);
	else if (s < seq.size() - 1 && seq[s] == 2 && 0 <= seq[s + 1] && seq[s + 1] <= 6)
		res = go(s + 1) + go(s + 2);
	else
		res = go(s + 1);
	res %= 1000000;
	return res;
}
int main() {
	memset(d, -1, sizeof(d));
	char msg[5050];
	scanf("%s", msg);
	for (int i = 0; msg[i] != '\0'; ++i)
		seq.push_back(msg[i] - '0');
	int ans = go(0);
	printf("%d", ans < 0 ? 0 : ans);
}