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

string t, s[105][15];
int n, a[105];

int dp[105][105];

int main() {
  cin >> t;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    for (int j = 1; j <= a[i]; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= t.length(); j++) {
      dp[i][j] = int(1e9);
    }
  }

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= t.length(); j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);

      for (int k = 1; k <= a[i]; k++) {
        if (j + s[i][k].length() > t.length()) {
          continue;
        }

        bool flag = true;
        for (int l = 0; l < s[i][k].length(); l++) {
          if (s[i][k][l] != t[j + l]) {
            flag = false;
            break;
          }
        }

        if (flag) {
          dp[i][j + s[i][k].length()] =
              min(dp[i][j + s[i][k].length()], dp[i - 1][j] + 1);
        }
      }
    }
  }

  if (dp[n][t.length()] == int(1e9)) {
    cout << -1 << endl;
  } else {
    cout << dp[n][t.length()] << endl;
  }

  return 0;
}
