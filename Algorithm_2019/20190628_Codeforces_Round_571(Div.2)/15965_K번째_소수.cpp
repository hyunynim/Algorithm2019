#include<bits/stdc++.h>
using namespace std;
bool prime[8080808] = { 1, 1 };
int main() {
	vector<int> p(1);
	for (int i = 2; i * i < 8080808; ++i) {
		if (prime[i]) continue;
		for (int j = i * i; j < 8080808; j += i)
			prime[j] = 1;
	}
	for (int i = 0; i < 8080808; ++i)
		if (!prime[i])
			p.push_back(i);
	int k; scanf("%d", &k); printf("%d", p[k]);
}