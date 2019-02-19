#include<cstdio>
#include<string.h>

struct Trie {
	bool finish;
	Trie* next[26];
	Trie() : finish(false) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		if (*key == '\0')
			finish = true;
		else {
			int curr = *key - '0';
			if (next[curr] == NULL)
				next[curr] = new Trie();
			next[curr]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0')	return 0;
		int curr = *key - '0';
		if (finish)return 1;
		return next[curr]->find(key + 1);
	}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		char msg[10101][101];
		Trie tr;
		bool ans = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%s", msg[i]);
			tr.insert(msg[i]);
		}
		for (int i = 0; i < n; ++i) {
			if (tr.find(msg[i])) {
				ans = 0; puts("NO"); break;
			}
		}

		if (ans)
			puts("YES");
	}
}