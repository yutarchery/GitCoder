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

string n;

int now, cnt;
ll dp[15][10][15];

int main() {
  cin >> n;
  for (int j = 0; j < n[0] - '0'; j++) {
    if (j == 1) {
      dp[0][j][1] = 1;
    } else {
      dp[0][j][0] = 1;
    }
  }

  now = n[0] - '0';
  if (now == 1) {
    cnt = 1;
  }

  for (int i = 1; i < n.length(); i++) {
    for (int j = 0; j < 10; j++) {
      for (int jj = 0; jj < 10; jj++) {
        for (int k = 0; k <= i; k++) {
          if (jj == 1) {
            dp[i][jj][k + 1] += dp[i - 1][j][k];
          } else {
            dp[i][jj][k] += dp[i - 1][j][k];
          }
        }
      }
    }

    now = n[i] - '0';
    for (int jj = 0; jj < now; jj++) {
      if (jj == 1) {
        dp[i][jj][cnt + 1]++;
      } else {
        dp[i][jj][cnt]++;
      }
    }

    if (now == 1) {
      cnt++;
    }
  }

  ll ans = cnt;
  for (int j = 0; j < 10; j++) {
    for (int k = 1; k <= n.length(); k++) {
      ans += dp[n.length() - 1][j][k] * k;
    }
  }

  cout << ans << endl;

  return 0;
}
