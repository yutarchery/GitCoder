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

int n, m, a[5005], b[5005], c[5005], dp[5005][5005];
vector<Pii> p[5005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    p[b[i]].push_back({a[i], c[i]});
  }

  for (int i = 0; i <= 5000; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = 1e9;
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= 5000; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);

      for (Pii k : p[i]) {
        dp[i][min(j + k.second, m)] =
            min(dp[i][min(j + k.second, m)], dp[i - 1][j] + k.first);
      }
    }
  }

  if (dp[5000][m] == 1e9) {
    cout << -1 << endl;
  } else {
    cout << dp[5000][m] << endl;
  }

  return 0;
}
