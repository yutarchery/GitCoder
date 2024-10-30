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

string s, t, u = "atcoder";
int cnt[2][26], rest[2];

int main() {
  cin >> s;
  cin >> t;
  for (int i = 0; i < int(s.length()); i++) {
    if (s[i] == '@') {
      rest[0]++;
    } else {
      cnt[0][s[i] - 'a']++;
    }
  }
  for (int i = 0; i < int(t.length()); i++) {
    if (t[i] == '@') {
      rest[1]++;
    } else {
      cnt[1][t[i] - 'a']++;
    }
  }

  for (int j = 0; j < int(u.length()); j++) {
    if (cnt[0][u[j] - 'a'] > cnt[1][u[j] - 'a']) {
      rest[1] -= cnt[0][u[j] - 'a'] - cnt[1][u[j] - 'a'];
      cnt[1][u[j] - 'a'] = cnt[0][u[j] - 'a'];
    } else {
      rest[0] -= cnt[1][u[j] - 'a'] - cnt[0][u[j] - 'a'];
      cnt[0][u[j] - 'a'] = cnt[1][u[j] - 'a'];
    }
  }

  for (int j = 0; j < 26; j++) {
    if (cnt[0][j] != cnt[1][j]) {
      No();
      return 0;
    }
  }

  if (rest[0] >= 0 && rest[1] >= 0) {
    Yes();
  } else {
    No();
  }

  return 0;
}
