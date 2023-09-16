#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

string s;
int cnt[26][26], m = 0;

int main() {
  cin >> s;
  for (int i = 0; i < s.length() - 1; i++) {
    cnt[s[i] - 'a'][s[i + 1] - 'a']++;
    m = max(m, cnt[s[i] - 'a'][s[i + 1] - 'a']);
  }

  for (char i = 'a'; i <= 'z'; i++) {
    for (char j = 'a'; j <= 'z'; j++) {
      if (m == cnt[i - 'a'][j - 'a']) {
        cout << i << j << endl;
        return 0;
      }
    }
  }

  return 0;
}