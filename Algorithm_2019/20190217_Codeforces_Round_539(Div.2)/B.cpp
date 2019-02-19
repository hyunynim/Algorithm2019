#include<cstdio>
#include<string.h>
#include<algorithm>
#include<utility>
#include<functional>
#include <array>
#include <algorithm>
#include <fstream>
#include <list>
#include <unordered_map>
#include <map>
#include <numeric>
#include <set>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <iomanip>
#include <array>
#include <math.h>
#include <cassert>
#include <limits>
#include <memory.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define all(c) (c).begin(), (c).end()

int main()
{
	int n; scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	int sum = accumulate(seq.begin(), seq.end(), 0);
	int ans = sum;
	sort(seq.begin(), seq.end());

	for (int i = n - 1; i > 0; --i) 
		for (int j = 2; j * j <= seq[i]; ++j) 
			if (seq[i] % j == 0) 
				ans = min(sum, sum - seq[0] - seq[i] + seq[0] * j + seq[i] / j);
	printf("%d", ans);
}