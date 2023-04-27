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

int h, w;
ll a[105][105], dp[105][105][205];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      for (int k = 1; k <= h + w - 1; k++) {
        dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k]);
        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + a[i][j]);
        dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + a[i][j]);
      }
    }
  }

  for (int k = 1; k <= h + w - 1; k++) {
    cout << dp[h][w][k] << endl;
  }

  return 0;
}