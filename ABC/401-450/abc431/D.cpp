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
ll w[505], h[505], b[505];

ll sum_w = 0, sum_b = 0;

bool visited[int(13e4 + 5)], next_visited[int(13e4 + 5)];
ll dp[int(13e4 + 5)], next_dp[int(13e4 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> h[i] >> b[i];
    sum_w += w[i];
    sum_b += b[i];
  }

  visited[0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j + w[i] <= sum_w / 2; j++) {
      if (visited[j] && h[i] - b[i] > 0) {
        next_visited[j + w[i]] = true;
        next_dp[j + w[i]] = max(dp[j] + h[i] - b[i], next_dp[j + w[i]]);
      }
    }

    for (int j = 0; j <= sum_w / 2; j++) {
      if (next_visited[j]) {
        visited[j] = true;
        next_visited[j] = false;

        dp[j] = max(dp[j], next_dp[j]);
        next_dp[j] = 0;
      }
    }
  }

  ll ans = sum_b;
  for (int j = 0; j <= sum_w / 2; j++) {
    ans = max(ans, sum_b + dp[j]);
  }
  cout << ans << endl;

  return 0;
}
