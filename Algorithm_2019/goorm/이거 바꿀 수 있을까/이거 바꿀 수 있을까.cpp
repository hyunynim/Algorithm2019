#include<bits/stdc++.h>
#include<random>
using namespace std;
typedef long long ll;
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> d1(1, 50);
uniform_int_distribution<int> d2(1, 10000);
uniform_int_distribution<int> d3(1, 100000);

bool solve() {
	//TODO
	int d[101010];
	int n, m, tmp;
	scanf("%d", &n);
	vector<int> price(n);
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &price[i]);
		d[price[i]] = 1;
	}
	scanf("%d", &m);
	sort(price.begin(), price.end());
	for (int i = 1; i <= m; ++i)
		for (int j = 0; j < n && price[j] <= i; ++j)
			d[i] = min(d[i], d[i - price[j]] + 1);
	printf("%d", d[m] > 100000 ? -1 : d[m]);
	return d[m] > 100000;
}
int main() {
	srand(time(0));
	char msg[1010];
	int cnt = 3, tmp;
	while (1) {
		sprintf(msg, "goorm/input.%d.txt", cnt);
		FILE* fp = freopen(msg, "w", stdout);

		//TODO
		int n = d1(gen);
		int m = d3(gen);
		if (cnt <= 3) {
			n = rand() % 5 + 3;
			m = rand() % 100 + 50;
		}
		else if (cnt <= 6) {
			n = 50;
			m = 100000;
		}
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) {
			if (cnt <= 3)
				printf("%d ", rand() % 5 + 5);
			else
				printf("%d ", d2(gen));
		}
		printf("\n%d\n", m);
		fclose(fp);


		freopen(msg, "r", stdin);
		sprintf(msg, "goorm/output.%d.txt", cnt++);
		freopen(msg, "w", stdout);
		if(!solve()) --cnt;
		if (cnt > 3) break;
	}
}