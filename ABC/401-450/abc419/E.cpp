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

int n, m, l, a[505];
int dp[505][505], ans[505][505];

int main() {
  cin >> n >> m >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int idx = i % l;
      if (idx == 0) {
        idx = l;
      }

      dp[idx][j] += (m + j - (a[i] % m)) % m;
    }
  }

  for (int j = 0; j < m; j++) {
    ans[1][j] = dp[1][j];
  }
  for (int i = 2; i <= l; i++) {
    for (int j = 0; j < m; j++) {
      ans[i][j] = 1e9;
    }

    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        ans[i][(j + k) % m] =
            min(ans[i][(j + k) % m], ans[i - 1][j] + dp[i][k]);
      }
    }
  }
  cout << ans[l][0] << endl;

  return 0;
}
