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

int n, t[int(1e5 + 5)], x[int(1e5 + 5)];
ll a[int(1e5 + 5)], dp[int(1e5 + 5)][5];
bool visited[int(1e5 + 5)][5];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> x[i] >> a[i];
  }

  visited[0][0] = true;
  int idx = 1;

  for (int i = 1; i <= t[n]; i++) {
    for (int j = 0; j < 5; j++) {
      if (j - 1 >= 0 && visited[i - 1][j - 1]) {
        visited[i][j] = true;
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
      if (visited[i - 1][j]) {
        visited[i][j] = true;
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      }
      if (j + 1 <= 4 && visited[i - 1][j + 1]) {
        visited[i][j] = true;
        dp[i][j] = max(dp[i][j], dp[i - 1][j + 1]);
      }
    }

    if (t[idx] == i) {
      if (visited[i][x[idx]]) {
        dp[i][x[idx]] += a[idx];
      }
      idx++;
    }
  }

  ll ans = 0;
  for (int j = 0; j < 5; j++) {
    ans = max(ans, dp[t[n]][j]);
  }
  cout << ans << endl;

  return 0;
}