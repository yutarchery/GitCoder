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
ll w, weight[105], value[105], dp[105][int(1e5 + 5)];

int main() {
  ll value_sum = 0;

  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> weight[i] >> value[i];
    value_sum += value[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= value_sum; j++) {
      dp[i][j] = 1e16;
    }
  }
  dp[0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= value_sum; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);

      if (j + value[i] <= value_sum) {
        dp[i][j + value[i]] =
            min(dp[i][j + value[i]], dp[i - 1][j] + weight[i]);
      }
    }
  }

  for (int j = value_sum; j >= 0; j--) {
    if (dp[n][j] <= w) {
      cout << j << endl;
      return 0;
    }
  }

  return 0;
}
