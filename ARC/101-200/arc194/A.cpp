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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll a[int(2e5 + 5)];

ll dp[int(2e5 + 5)];
priority_queue<ll> odds, evens;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  evens.push(0);
  for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + a[i];

    if (i % 2 == 0 && !odds.empty()) {
      dp[i] = max(dp[i], odds.top() + a[i]);
    }
    if (i % 2 == 1 && !evens.empty()) {
      dp[i] = max(dp[i], evens.top() + a[i]);
    }

    if (i % 2 == 0) {
      evens.push(dp[i]);
    } else {
      odds.push(dp[i]);
    }
  }

  ll ans = -1e18;
  for (int i = 0; i <= n; i++) {
    if ((n - i) % 2 == 0) {
      ans = max(ans, dp[i]);
    }
  }
  cout << ans << '\n';

  return 0;
}
