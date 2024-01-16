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

string s, t;
int dp[3005][3005], di[2] = {0, 1}, dj[2] = {1, 0};

char ans[3005];

int main() {
  cin >> s >> t;
  int n = s.length(), m = t.length();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      } else {
        dp[i][j] = max(dp[i][j], dp[1 - 1][j - 1]);
      }
    }
  }

  int i = n, j = m;
  while (dp[i][j] > 0) {
    if (dp[i][j] == dp[i - 1][j - 1] + 1 && dp[i - 1][j] == dp[i - 1][j - 1] &&
        dp[i][j - 1] == dp[i - 1][j - 1]) {
      ans[dp[i][j]] = s[i - 1];
      i--;
      j--;
      continue;
    }

    if (dp[i - 1][j] == dp[i][j]) {
      i--;
    } else {
      j--;
    }
  }

  for (int i = 1; i <= dp[n][m]; i++) {
    cout << ans[i];
  }
  cout << endl;

  return 0;
}
