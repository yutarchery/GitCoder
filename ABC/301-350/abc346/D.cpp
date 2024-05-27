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
string s, t;
ll c[int(2e5 + 5)];

ll dp[int(2e5 + 5)][4];

int main() {
  cin >> n;
  cin >> s;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      t += '0';
    } else {
      t += '1';
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0];
    dp[i][2] = dp[i - 1][2];

    if (s[i - 1] != t[i - 1]) {
      dp[i][0] += c[i - 1];
    } else {
      dp[i][2] += c[i - 1];
    }
  }
  for (int i = n; i >= 1; i--) {
    dp[i][1] = dp[i + 1][1];
    dp[i][3] = dp[i + 1][3];

    if (s[i - 1] != t[i - 1]) {
      dp[i][1] += c[i - 1];
    } else {
      dp[i][3] += c[i - 1];
    }
  }

  ll ans = dp[1][0] + dp[2][3];
  for (int i = 1; i + 1 <= n; i++) {
    ans = min(ans, dp[i][0] + dp[i + 1][3]);
    ans = min(ans, dp[i][2] + dp[i + 1][1]);
  }
  cout << ans << endl;

  return 0;
}
