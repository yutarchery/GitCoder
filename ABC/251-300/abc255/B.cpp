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

int n, k, a[1005];
ll x[1005], y[1005];

bool visited[1005];

bool solve(ll num) {
  fill(visited, visited + n + 1, false);
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      if ((x[a[i]] - x[j]) * (x[a[i]] - x[j]) +
              (y[a[i]] - y[j]) * (y[a[i]] - y[j]) <=
          num) {
        visited[j] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  ll l = 0, r = ll(1e16);
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (solve(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }

  cout << fixed << setprecision(32) << sqrt(r) << endl;

  return 0;
}
