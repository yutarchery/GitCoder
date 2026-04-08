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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

string s, t;
int next_s[int(2e5 + 5)][26];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  cin >> t;

  for (int j = 0; j < 26; j++) {
    next_s[s.length() - 1][j] = -1;
  }
  for (int i = s.length() - 2; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      next_s[i][j] = next_s[i + 1][j];
    }

    next_s[i][s[i + 1] - 'a'] = i + 1;
  }

  ll ans = ll(s.length()) * (ll(s.length()) + 1) / 2;
  for (int i = 0; i < s.length(); i++) {
    int now_s = i, t_idx = 0;
    if (s[i] == t[t_idx]) {
      t_idx++;
    }

    while (t_idx < t.length()) {
      int s_idx = next_s[now_s][t[t_idx] - 'a'];
      now_s = s_idx;
      if (now_s == -1) {
        break;
      }
      t_idx++;
    }

    if (now_s != -1) {
      ans -= s.length() - now_s;
    }
  }
  cout << ans << '\n';

  return 0;
}
