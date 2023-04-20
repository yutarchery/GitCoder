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

int n;
double p[3005], dp[3005][3005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] += dp[i - 1][j] * (1 - p[i]);
      if (j - 1 >= 0) {
        dp[i][j] += dp[i - 1][j - 1] * p[i];
      }
    }
  }

  double ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i > (n - i)) {
      ans += dp[n][i];
    }
  }
  cout << setprecision(32) << ans << endl;

  return 0;
}