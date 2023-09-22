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

int n, q;
ll x, y, p, t, queries[int(2e5 + 5)];
ll dp[int(1e5 + 5)][840];

int main() {
  for (int j = 0; j < 840; j++) {
    dp[1][j] = j;
  }

  cin >> n >> x >> y;
  for (int i = 1; i <= n - 1; i++) {
    cin >> p >> t;
    for (int j = 0; j < 840; j++) {
      if (dp[i][j] % p == 0) {
        dp[i + 1][j] = dp[i][j] + t;
      } else {
        dp[i + 1][j] = (dp[i][j] / p + 1) * p + t;
      }
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> queries[i];
  }

  for (int i = 0; i < q; i++) {
    ll now = x + queries[i];
    cout << (now / 840) * 840 + dp[n][now % 840] + y << endl;
  }

  return 0;
}