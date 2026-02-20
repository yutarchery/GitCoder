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

int n, m, p[1005];
ll v[1005];

ll dp1[1005][int(5e4 + 5)], dp2[1005][int(5e4 + 5)];

char ans[1005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      dp1[i][j] = max(dp1[i][j], dp1[i - 1][j]);
    }
    for (int j = 0; j + p[i] <= m; j++) {
      dp1[i][j + p[i]] = max(dp1[i][j + p[i]], dp1[i - 1][j] + v[i]);
    }
  }

  ll v_max = 0;
  for (int j = 0; j <= m; j++) {
    v_max = max(v_max, dp1[n][j]);
  }

  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= m; j++) {
      dp2[i][j] = max(dp2[i][j], dp2[i + 1][j]);
    }
    for (int j = 0; j + p[i] <= m; j++) {
      dp2[i][j + p[i]] = max(dp2[i][j + p[i]], dp2[i + 1][j] + v[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    bool flag1 = false;
    for (int j = 0; j <= m; j++) {
      if (dp1[i - 1][j] + dp2[i + 1][m - j] >= v_max) {
        flag1 = true;
      }
    }

    bool flag2 = false;
    for (int j = 0; j <= m - p[i]; j++) {
      if (dp1[i - 1][j] + dp2[i + 1][(m - p[i]) - j] >= v_max - v[i]) {
        flag2 = true;
      }
    }

    if (flag1 && flag2) {
      ans[i] = 'B';
    } else if (flag1) {
      ans[i] = 'C';
    } else {
      ans[i] = 'A';
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
