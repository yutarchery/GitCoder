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

int n, a[105], sum;
double dp[105][105][105];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      for (int k = 0; k <= sum; k++) {
        dp[i][j][k] = 1e9;
      }
    }
  }
  dp[1][0][sum] = 0;

  for (int i = 2; i <= n; i++) {
    for (int k = 0; k <= sum; k++) {
      for (int j = 0; j <= k; j++) {
        for (int l = 0; k + l <= sum; l++) {
          dp[i][j][k] = min(dp[i][j][k],
                            dp[i - 1][l][k + l] + sqrt(1 + (j - l) * (j - l)));
        }
      }
    }
  }
  cout << setprecision(32) << dp[n][0][0] << endl;

  return 0;
}