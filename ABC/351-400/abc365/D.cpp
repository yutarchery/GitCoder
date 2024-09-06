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
char c[int(2e5 + 5)];

const char hands[4] = {'R', 'P', 'S', 'R'};
bool visited[int(2e5 + 5)][3][3];
int dp[int(2e5 + 5)][3][3];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int j = 1; j <= 3; j++) {
    for (int k = 1; k <= 3; k++) {
      if (c[1] == hands[k - 1]) {
        dp[1][j % 3][k % 3] = 1;
      }
      visited[1][j % 3][k % 3] = true;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 3; j++) {
      for (int k = 1; k <= 3; k++) {
        if (visited[i - 1][j % 3][k % 3]) {
          for (int l = 1; l <= 3; l++) {
            if (l == k) {
              continue;
            }
            if (c[i] == hands[(l - 1) % 3]) {
              visited[i][k % 3][l % 3] = true;
              dp[i][k % 3][l % 3] =
                  max(dp[i][k % 3][l % 3], dp[i - 1][j % 3][k % 3] + 1);
            } else if (c[i] == hands[l % 3]) {
              visited[i][k % 3][l % 3] = true;
              dp[i][k % 3][l % 3] =
                  max(dp[i][k % 3][l % 3], dp[i - 1][j % 3][k % 3]);
            }
          }
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < 3; j++) {
    for (int k = 0; k < 3; k++) {
      if (visited[n][j][k]) {
        ans = max(ans, dp[n][j][k]);
      }
    }
  }
  cout << ans << endl;

  return 0;
}
