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
char s[int(2e5 + 5)];
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

ll dp[int(2e5 + 5)][2];

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    cin >> y[i];
  }

  for (int i = 1; i <= n; i++) {
    dp[i][0] = -1e18;
    dp[i][1] = -1e18;
  }

  for (int i = 1; i <= n; i++) {
    if (s[i] == 'S') {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - x[i];

      if (i >= 2) {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + y[i - 1]);
      }
    } else {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) - x[i];
      dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);

      if (i >= 2) {
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + y[i - 1] - x[i]);
      }
    }
  }

  return max(dp[n][0], dp[n][1]);
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
