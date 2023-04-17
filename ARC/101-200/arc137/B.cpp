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

int n, a[int(3e5 + 5)], dp[int(3e5 + 5)][2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cnt0 = 0, cnt1 = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      if (a[i] == j) {
        dp[i][j] = dp[i - 1][j] + 1;
      } else {
        dp[i][j] = max(0, dp[i - 1][j] - 1);
      }
    }

    cnt0 = max(cnt0, dp[i][0]);
    cnt1 = max(cnt1, dp[i][1]);
  }

  cout << cnt0 + cnt1 + 1 << endl;

  return 0;
}