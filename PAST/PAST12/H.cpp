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

int n, x, a[3005], b[3005], c[3005];

bool visited[3005][3005];
Pii dp[3005][3005];

Pii pair_compair(Pii p, Pii q) {
  if (p.first > q.first) {
    return p;
  } else if (p.first == q.first) {
    if (p.second < q.second) {
      return p;
    } else {
      return q;
    }
  } else {
    return q;
  }
}

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  visited[0][x] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      if (!visited[i - 1][j]) {
        continue;
      }

      visited[i][j] = true;
      dp[i][j] = pair_compair(dp[i][j], dp[i - 1][j]);

      if (j - b[i] < 0) {
        continue;
      }
      visited[i][j - b[i]] = true;
      dp[i][j - b[i]] =
          pair_compair(dp[i][j - b[i]],
                       {dp[i - 1][j].first + c[i], dp[i - 1][j].second + a[i]});
    }
  }

  Pii ans = {0, 0};
  int rest = x;
  for (int j = 0; j <= x; j++) {
    if (visited[n][j]) {
      if (dp[n][j] == pair_compair(ans, dp[n][j])) {
        ans = dp[n][j];
        rest = j;
      }
    }
  }

  cout << ans.first << " " << int(1e9) - ans.second << " " << rest << endl;

  return 0;
}