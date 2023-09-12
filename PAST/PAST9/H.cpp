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

int dp[5005][5005];
string s, t;

int main() {
  cin >> s >> t;

  for (int i = 1; i <= s.length(); i++) {
    for (int j = 1; j <= t.length(); j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s[i - 1] != t[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      } else {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
      }
    }
  }
  cout << dp[int(s.length())][int(t.length())] << endl;

  return 0;
}