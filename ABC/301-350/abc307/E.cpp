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

ll n, m, dp[int(1e6 + 5)][2];

int main() {
  cin >> n >> m;
  dp[1][1] = m;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = (dp[i - 1][0] * (m - 2) + dp[i - 1][1] * (m - 1)) % MOD2;
    dp[i][1] = dp[i - 1][0];
  }
  cout << dp[n][0] << endl;

  return 0;
}
