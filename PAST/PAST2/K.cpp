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

int n;
char s[3005];
ll c[3005], d[3005];

bool visited[3005][3005];
ll dp[3005][3005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      dp[i][j] = 1e16;
    }
  }
  dp[0][0] = 0;
  visited[0][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (!visited[i - 1][j]) {
        continue;
      }

      if (s[i] == '(') {
        dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j]);
        if (j >= 1) {
          dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j] + c[i]);
        }
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + d[i]);
      } else {
        if (j >= 1) {
          dp[i][j - 1] = min(dp[i][j - 1], dp[i - 1][j]);
        }
        dp[i][j + 1] = min(dp[i][j + 1], dp[i - 1][j] + c[i]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + d[i]);
      }

      for (int k = -1; k <= 1; k++) {
        if (j + k >= 0) {
          visited[i][j + k] = true;
        }
      }
    }
  }

  cout << dp[n][0] << endl;

  return 0;
}
