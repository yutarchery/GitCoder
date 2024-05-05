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
string s;
ll dp[int(1e6 + 5)][2];

int main() {
  cin >> n;
  cin >> s;

  dp[0][s[0] - '0']++;
  for (int i = 1; i < n; i++) {
    if (s[i] == '0') {
      dp[i][0] = 1;
      dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
    } else {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = dp[i - 1][0] + 1;
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += dp[i][1];
  }
  cout << ans << endl;

  return 0;
}
