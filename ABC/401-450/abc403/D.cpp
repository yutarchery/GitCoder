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

int n, d, a[int(2e5 + 5)];
int cnt[int(4e6 + 5)];

int dp[int(1e6 + 5)][2];

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  int ans = 0;
  if (d == 0) {
    for (int i = 0; i <= int(1e6); i++) {
      if (cnt[i] >= 2) {
        ans += cnt[i] - 1;
      }
    }
  }

  for (int i = 0; i < d; i++) {
    dp[0][0] = cnt[i];
    dp[0][1] = 0;

    int max_j = 0;
    for (int j = 1; i + j * d <= int(1e6); j++) {
      dp[j][0] = min(dp[j - 1][0], dp[j - 1][1]) + cnt[i + j * d];

      if (cnt[i + j * d] > 0) {
        dp[j][1] = dp[j - 1][0];
      } else {
        dp[j][1] = min(dp[j - 1][0], dp[j - 1][1]);
      }

      max_j = j;
    }

    ans += min(dp[max_j][0], dp[max_j][1]);
  }
  cout << ans << endl;

  return 0;
}
