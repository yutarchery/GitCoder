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
ll m, a[int(2e5 + 5)], loop_sum = 0;
bool loop = true;

map<ll, bool> visited;
map<ll, ll> cnt, dp;

ll solve(ll num) {
  if (visited[num]) {
    return dp[num];
  }

  visited[num] = true;
  if (cnt[num] == 0) {
    return 0;
  }
  ll sum = num * cnt[num] + solve((num + 1) % m);
  return dp[num] = sum;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  for (int i = 0; i < m; i++) {
    if (cnt[i] == 0) {
      loop = false;
      break;
    }
  }
  if (loop) {
    for (ll i = 0; i < m; i++) {
      loop_sum += i * cnt[i];
    }
    for (ll i = 0; i < m; i++) {
      visited[i] = true;
      dp[i] = loop_sum;
    }
  }

  ll res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(solve(a[i]), res);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += a[i];
  }
  cout << ans - res << endl;

  return 0;
}