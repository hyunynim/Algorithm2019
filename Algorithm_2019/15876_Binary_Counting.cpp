#include<iostream>
#include<string>
using namespace std;
int main() {
	string ans = "0";
	for (int i = 1; i < 10000; ++i) {
		string tmp = "";
		int num = i;
		while (num) {
			tmp.push_back(num % 2 + '0');
			num /= 2;
		}
		reverse(tmp.begin(), tmp.end());
		ans += tmp;
	}
	int n, k;
	scanf("%d %d", &n, &k);
	--k;
	for (int i = 0; i < 5; ++i) {
		cout << ans[k + n * i] << ' ';
	}
}