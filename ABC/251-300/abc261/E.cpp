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

int n, t[int(2e5 + 5)];
ll c, a[int(2e5 + 5)];

bool dp[int(2e5 + 5)][30][2];

bool ans[int(2e5 + 5)][30];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> a[i];
  }

  for (int j = 0; j < 30; j++) {
    for (int k = 0; k < 2; k++) {
      dp[0][j][k] = k;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 30; j++) {
      bool now = ((a[i] & (1 << j)) > 0);
      for (int k = 0; k < 2; k++) {
        if (t[i] == 1) {
          dp[i][j][k] = dp[i - 1][j][k] & now;
        } else if (t[i] == 2) {
          dp[i][j][k] = dp[i - 1][j][k] | now;
        } else {
          dp[i][j][k] = dp[i - 1][j][k] ^ now;
        }
      }
    }
  }

  for (int j = 0; j < 30; j++) {
    ans[0][j] = c % 2;
    c /= 2;
  }
  for (int i = 1; i <= n; i++) {
    ll now = 0;

    for (int j = 0; j < 30; j++) {
      ans[i][j] = dp[i][j][ans[i - 1][j]];

      if (ans[i][j]) {
        now += (1 << j);
      }
    }
    cout << now << '\n';
  }

  return 0;
}
