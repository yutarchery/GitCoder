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

int n, m, a[int(1e5 + 5)], b[int(1e5 + 5)];

const int offset = 100;
int dp[int(1e5 + 5)][205];
bool visited[int(1e5 + 5)][205];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  visited[0][offset] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = -1 * m + offset; j <= m + offset; j++) {
      if (!visited[i - 1][j]) {
        continue;
      }

      if (j + a[i] <= m + offset) {
        visited[i][j + a[i]] = true;
        dp[i][j + a[i]] = max(dp[i][j + a[i]], dp[i - 1][j] + a[i]);
      }
      if (-1 * m + offset <= j - b[i]) {
        visited[i][j - b[i]] = true;
        dp[i][j - b[i]] = max(dp[i][j - b[i]], dp[i - 1][j]);
      }
    }
  }

  int ans = -1;
  for (int j = -1 * m + offset; j <= m + offset; j++) {
    if (visited[n][j]) {
      ans = max(ans, dp[n][j]);
    }
  }
  cout << ans << '\n';

  return 0;
}
