#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int K, N;
ll arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};

bool sieve[1010101] = { 1, 1 };
vector<ll> prime;
void pre(){
  for (int i = 2; i * i <= 1000000; ++i) {
        if (sieve[i]) continue;
        for (int j = i * i; j <= 1000000; j += i)
            sieve[j] = 1;
    }
    for(int i = 1; i<1000000; ++i){
      if(!sieve[i]) prime.push_back(i);
      if(prime.size() == 100) return;
    }
}
int main() {
  pre();
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	priority_queue<ll> pq;
  K = 100;
	for (int i = 0; i < K; i++) 
		pq.push(-prime[i]);

	ll num;
	for (int i = 0; i < 10001; i++) {
		num = pq.top();
    cout << i << ": " << num << endl;
		pq.pop();
		for (int j = 0; j < K; j++) {
			pq.push(prime[j] * num);
			if (num % prime[j] == 0)break;
		}
	}
	cout << -num<<"\n";
}