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

int n, m;
double x[20], y[20];

bool visited[int(1e6 + 5)][20];
double dp[int(1e6 + 5)][20];

int calc_point(int idx) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if ((idx & (1 << i)) != 0) {
      res++;
    }
  }
  return res;
}

int calc_booster(int idx) {
  int res = 0;
  for (int i = n + 1; i <= n + m; i++) {
    if (((idx) & (1 << i)) != 0) {
      res++;
    }
  }
  return res;
}

double calc_dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < (1 << (n + m + 1)); i++) {
    for (int j = 0; j <= n + m; j++) {
      dp[i][j] = 1e18;
    }
  }

  for (int i = 1; i <= n + m; i++) {
    cin >> x[i] >> y[i];

    visited[(1 << i)][i] = true;
    dp[(1 << i)][i] = calc_dist(0, 0, x[i], y[i]);
  }

  for (int i = 0; i < (1 << (n + m + 1)); i++) {
    for (int j = 1; j <= n + m; j++) {
      if (!visited[i][j]) {
        continue;
      }

      double booster = (1 << calc_booster(i));
      for (int k = 1; k <= n + m; k++) {
        if ((i & (1 << k)) != 0) {
          continue;
        }

        int next_idx = (i | (1 << k));
        dp[next_idx][k] =
            min(dp[next_idx][k],
                dp[i][j] + calc_dist(x[j], y[j], x[k], y[k]) / booster);
        visited[next_idx][k] = true;
      }
    }
  }

  double ans = 4e18;
  for (int i = 0; i < (1 << (n + m + 1)); i++) {
    if (calc_point(i) != n) {
      continue;
    }

    for (int j = 1; j <= n + m; j++) {
      if (visited[i][j]) {
        double booster = 1 << (calc_booster(i));
        ans = min(ans, dp[i][j] + calc_dist(x[j], y[j], 0, 0) / booster);
      }
    }
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
