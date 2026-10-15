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
ll x[int(2e5 + 5)], c[int(2e5 + 5)];

ll dp[int(2e5 + 5)][2], loc[int(2e5 + 5)][2];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    loc[i][0] = ll(1e18);
    loc[i][1] = ll(-1e18);

    dp[i][0] = ll(1e18);
    dp[i][1] = ll(1e18);
  }
  dp[n + 1][0] = ll(1e18);
  dp[n + 1][1] = ll(1e18);

  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> c[i];

    loc[c[i]][0] = min(loc[c[i]][0], x[i]);
    loc[c[i]][1] = max(loc[c[i]][1], x[i]);
  }

  ll before_loc[2] = {loc[0][0], loc[0][1]};
  for (int i = 1; i <= n + 1; i++) {
    if (loc[i][0] > loc[i][1]) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = dp[i - 1][1];
      continue;
    }

    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        dp[i][j] =
            min(dp[i][j], dp[i - 1][k] + abs(before_loc[k] - loc[i][1 - j]) +
                              abs(loc[i][1 - j] - loc[i][j]));
      }
    }

    for (int j = 0; j < 2; j++) {
      before_loc[j] = loc[i][j];
    }
  }

  cout << min(dp[n + 1][0], dp[n + 1][1]) << '\n';

  return 0;
}
