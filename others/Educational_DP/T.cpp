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
string s;
ll dp[3005][3005], sum[3005][3005];
int main() {
  cin >> n >> s;
  for (int j = 0; j <= n - 1; j++) {
    dp[1][j] = 1;
    sum[1][j] += dp[1][j];
    if (j - 1 >= 0) {
      sum[1][j] += sum[1][j - 1];
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= n - i; j++) {
      if (s[i - 2] == '<') {
        dp[i][j] = sum[i - 1][n - i + 1] - sum[i - 1][j];
        dp[i][j] %= mod;
        if (dp[i][j] < 0) {
          dp[i][j] += mod;
        }
      } else {
        dp[i][j] = sum[i - 1][j];
      }
    }

    sum[i][0] = dp[i][0];
    for (int j = 1; j <= n - i; j++) {
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
    }
  }

  cout << dp[n][0] << endl;

  return 0;
}
