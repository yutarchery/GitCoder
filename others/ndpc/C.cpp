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

int n;
string s[3];

ll dp[1005][15][15][15];

array<int, 3> calc_next(int j, int k, int l, char c) {
  int next_j = j, next_k = k, next_l = l;

  if (j < s[0].length() && s[0][j] == c) {
    next_j++;
  }
  if (k < s[1].length() && s[1][k] == c) {
    next_k++;
  }
  if (l < s[2].length() && s[2][l] == c) {
    next_l++;
  }

  return {next_j, next_k, next_l};
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i < 3; i++) {
    cin >> s[i];
  }

  dp[0][0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s[0].length(); j++) {
      for (int k = 0; k <= s[1].length(); k++) {
        for (int l = 0; l <= s[2].length(); l++) {
          if (dp[i - 1][j][k][l] == 0) {
            continue;
          }

          for (char c = 'a'; c <= 'z'; c++) {
            array<int, 3> nexts = calc_next(j, k, l, c);
            dp[i][nexts[0]][nexts[1]][nexts[2]] += dp[i - 1][j][k][l];
            dp[i][nexts[0]][nexts[1]][nexts[2]] %= MOD2;
          }
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < s[0].length(); j++) {
    for (int k = 0; k < s[1].length(); k++) {
      for (int l = 0; l < s[2].length(); l++) {
        ans += dp[n][j][k][l];
        ans %= MOD2;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
