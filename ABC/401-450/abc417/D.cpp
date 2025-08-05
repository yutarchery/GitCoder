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

int n, q;
ll p[int(1e4 + 5)], a[int(1e4 + 5)], b[int(1e4 + 5)], x[int(5e5 + 5)];

ll dp[int(1e4 + 5)][505], sum_b[int(1e4 + 5)];
bool visited[int(1e4 + 5)][505];

ll solve(int idx, ll val) {
  if (idx == n) {
    return val;
  }

  if (val > 500) {
    if (val - (sum_b[n] - sum_b[idx]) > 500) {
      return val - (sum_b[n] - sum_b[idx]);
    }
    int ng = idx, ok = n;
    while (ok - ng > 1) {
      int mid = (ok + ng) / 2;
      if (val - (sum_b[mid] - sum_b[idx]) > 500) {
        ng = mid;
      } else {
        ok = mid;
      }
    }

    return solve(ok, max(0ll, val - (sum_b[ok] - sum_b[idx])));
  }

  if (visited[idx][val]) {
    return dp[idx][val];
  }

  visited[idx][val] = true;
  if (val <= p[idx + 1]) {
    return dp[idx][val] = solve(idx + 1, val + a[idx + 1]);
  } else {
    return dp[idx][val] = solve(idx + 1, max(0ll, val - b[idx + 1]));
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> a[i] >> b[i];
    sum_b[i] = sum_b[i - 1] + b[i];
  }
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
  }

  for (int i = 1; i <= q; i++) {
    cout << solve(0, x[i]) << endl;
  }

  return 0;
}
