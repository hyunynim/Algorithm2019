#include<iostream>
#include<string>
using namespace std;
char str[2555];
char cmp[55];
int main() {
   cin.getline(str, 2500);
   cin.getline(cmp, 50);
   int s_len = 0, c_len = 0;
   for (int i = 0; i < 2500; i++) {
      if (str[i] == '\0') break;
      s_len++;
   }
   for (int i = 0; i < 50; i++) {
      if (cmp[i] == '\0') break;
      c_len++;
   }
   if (s_len == 0 || c_len == 0 || s_len < c_len) {
      cout << '0';
      return 0;
   }
   int ans = 0;
   for (int i = 0; i < s_len - c_len + 1;) {
      bool f = 0;
      for (int j = 0; j < c_len; j++) {
         if (str[i + j] != cmp[j]) f = 1;
      }
      if (!f) {
         ans++;
         i += c_len;
         if (c_len > 1) i++;
      }
      else i++;
   }
   cout << ans;
   return 0;
}