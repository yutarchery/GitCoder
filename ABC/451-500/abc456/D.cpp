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

string s;
ll dp[int(3e5 + 5)][3];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;
  dp[0][s[0] - 'a']++;

  for (int i = 1; i < s.length(); i++) {
    dp[i][s[i] - 'a']++;
    for (int j = 0; j < 3; j++) {
      dp[i][j] += dp[i - 1][j];
      dp[i][j] %= MOD2;
    }

    for (int j = 0; j < 3; j++) {
      if (s[i] != char(j + 'a')) {
        dp[i][s[i] - 'a'] += dp[i - 1][j];
        dp[i][s[i] - 'a'] %= MOD2;
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < 3; j++) {
    ans += dp[s.length() - 1][j];
    ans %= MOD2;
  }
  cout << ans << '\n';

  return 0;
}
