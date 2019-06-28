#include<bits/stdc++.h>
using namespace std;
int main() {
	string a, b;
	cin >> a >> b;
	int sz = a.size();
	bitset<1000000> ba, bb;
	for (int i = 0; i < a.size(); ++i) 
		if (a[i] == '1')
			ba.set(i);
	
	for (int i = 0; i < b.size(); ++i) 
		if (b[i] == '1')
			bb.set(i);
	int ans = 0;
	for (int i = 0; i < a.size() - b.size() + 1; ++i) {
		int k = (ba ^ bb).count();
		if (k % 2 == 0)
			++ans;
		bb <<= 1;
	}
	printf("%d", ans);
}