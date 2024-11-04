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

ll x, y, z, dp[int(3e5 + 5)][2];
string s;

int main() {
  cin >> x >> y >> z;
  cin >> s;

  for (int i = 1; i <= s.length(); i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = 1e18;
    }
  }
  dp[0][0] = 0;
  dp[0][1] = z;

  for (int i = 1; i <= s.length(); i++) {
    if (s[i - 1] == 'A') {
      dp[i][0] = min(dp[i - 1][0] + min(y, x + 2 * z),
                     dp[i - 1][1] + min(y + z, x + z));
      dp[i][1] = min(dp[i - 1][0] + min(x + z, y + z),
                     dp[i - 1][1] + min(x, y + 2 * z));
    } else {
      dp[i][0] = min(dp[i - 1][0] + min(x, y + 2 * z),
                     dp[i - 1][1] + min(x + z, y + z));
      dp[i][1] = min(dp[i - 1][0] + min(x + z, y + z),
                     dp[i - 1][1] + min(y, x + 2 * z));
    }
  }

  cout << min(dp[s.length()][0], dp[s.length()][1]) << endl;

  return 0;
}
