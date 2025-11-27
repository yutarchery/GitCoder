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

int m;
int a[5][5];

ll dp[20][35][35][35][35];

void solve(int idx, int i, int j) {
  if (a[i][j] == -1) {
    for (int i1 = 0; i1 <= m; i1++) {
      for (int i2 = 0; i2 <= m; i2++) {
        for (int i3 = 0; i3 <= m; i3++) {
          for (int i4 = 0; i4 <= m; i4++) {
            if (idx % 4 == 1) {
              for (int v = i1 + 1; v <= m; v++) {
                dp[idx][i2][i3][i4][v] += dp[idx - 1][i1][i2][i3][i4];
                dp[idx][i2][i3][i4][v] %= MOD2;
              }
            } else {
              for (int v = max(i1 + 1, i4 + 1); v <= m; v++) {
                dp[idx][i2][i3][i4][v] += dp[idx - 1][i1][i2][i3][i4];
                dp[idx][i2][i3][i4][v] %= MOD2;
              }
            }
          }
        }
      }
    }
  } else {
    for (int i1 = 0; i1 <= m; i1++) {
      for (int i2 = 0; i2 <= m; i2++) {
        for (int i3 = 0; i3 <= m; i3++) {
          for (int i4 = 0; i4 <= m; i4++) {
            if (idx % 4 == 1 && i1 < a[i][j]) {
              dp[idx][i2][i3][i4][a[i][j]] += dp[idx - 1][i1][i2][i3][i4];
              dp[idx][i2][i3][i4][a[i][j]] %= MOD2;
            } else if (idx % 4 != 1 && i1 < a[i][j] && i4 < a[i][j]) {
              dp[idx][i2][i3][i4][a[i][j]] += dp[idx - 1][i1][i2][i3][i4];
              dp[idx][i2][i3][i4][a[i][j]] %= MOD2;
            }
          }
        }
      }
    }
  }

  return;
}

int main() {
  cin >> m;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      cin >> a[i][j];
    }
  }

  dp[0][0][0][0][0] = 1;
  int idx = 1;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      solve(idx, i, j);
      idx++;
    }
  }

  ll ans = 0;
  for (int a = 1; a <= m; a++) {
    for (int b = 1; b <= m; b++) {
      for (int c = 1; c <= m; c++) {
        for (int d = 1; d <= m; d++) {
          ans += dp[16][a][b][c][d];
          ans %= MOD2;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
