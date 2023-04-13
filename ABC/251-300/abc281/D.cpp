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

int n, k, d;
ll a[105], dp[105][105][105];
bool visited[105][105][105];

int main() {
  cin >> n >> k >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  visited[0][0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int l = 0; l < d; l++) {
        if (!visited[i - 1][j][l]) {
          continue;
        }

        visited[i][j][l] = true;
        dp[i][j][l] = max(dp[i][j][l], dp[i - 1][j][l]);

        visited[i][j + 1][(l + a[i]) % d] = true;
        dp[i][j + 1][(l + a[i]) % d] =
            max(dp[i][j + 1][(l + a[i]) % d], dp[i - 1][j][l] + a[i]);
      }
    }
  }

  if (!visited[n][k][0]) {
    cout << -1 << endl;
  } else {
    cout << dp[n][k][0] << endl;
  }

  return 0;
}