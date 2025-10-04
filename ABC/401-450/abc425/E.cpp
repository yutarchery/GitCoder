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

int t;
ll m, n, c[5005];

ll dp[5005][5005];
bool visited[5005][5005];

ll calc_dp(ll n, ll k) {
  if (visited[n][k]) {
    return dp[n][k];
  }

  visited[n][k] = true;
  if (n < k) {
    return dp[n][k] = 0;
  }

  if (k == 0) {
    return dp[n][k] = 1;
  }

  ll res = (calc_dp(n - 1, k - 1) + calc_dp(n - 1, k)) % m;
  return dp[n][k] = res;
}

ll solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  ll ans = 1, sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += c[i];
    ans = ans * calc_dp(sum, c[i]) % m;
  }

  return ans;
}

int main() {
  cin >> t >> m;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
