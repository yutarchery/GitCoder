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
char a[1005][1005];

ll dp[1005][1005];

int main() {
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j + 1] == '.') {
        dp[i][j + 1] += dp[i][j];
        dp[i][j + 1] %= mod;
      }

      if (a[i + 1][j] == '.') {
        dp[i + 1][j] += dp[i][j];
        dp[i + 1][j] %= mod;
      }
    }
  }

  cout << dp[h - 1][w - 1] << endl;

  return 0;
}
