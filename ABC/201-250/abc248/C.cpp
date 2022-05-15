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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, m, k;
ll dp[55][2505];

int main() {
  cin >> n >> m >> k;
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 1; l <= m; l++) {
        if (j + l > k) {
          break;
        }

        dp[i][j + l] += dp[i - 1][j];
        dp[i][j + l] %= mod2;
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j <= k; j++) {
    ans += dp[n][j];
    ans %= mod2;
  }
  cout << ans << endl;

  return 0;
}