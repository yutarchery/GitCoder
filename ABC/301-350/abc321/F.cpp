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

int q, k, x;
char c;

ll dp[5005];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> q >> k;
  dp[0] = 1;

  while (q--) {
    cin >> c >> x;
    if (c == '+') {
      for (int j = k; j >= x; j--) {
        dp[j] += dp[j - x];
        dp[j] %= MOD2;
      }
    } else {
      for (int j = x; j <= k; j++) {
        dp[j] -= dp[j - x];
        dp[j] %= MOD2;
        if (dp[j] < 0) {
          dp[j] += MOD2;
        }
      }
    }

    cout << dp[k] << '\n';
  }

  return 0;
}
