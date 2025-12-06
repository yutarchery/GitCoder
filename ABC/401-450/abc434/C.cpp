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
ll h, t[int(1e5 + 5)], l[int(1e5 + 5)], u[int(1e5 + 5)];

bool solve() {
  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> t[i] >> l[i] >> u[i];
  }

  ll now_t = 0, now_l = h, now_u = h;
  for (int i = 1; i <= n; i++) {
    now_l = max(1ll, now_l - (t[i] - t[i - 1]));
    now_u = now_u + (t[i] - t[i - 1]);

    if (now_u < l[i]) {
      return false;
    }
    if (u[i] < now_l) {
      return false;
    }

    now_l = max(now_l, l[i]);
    now_u = min(now_u, u[i]);
  }

  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve() ? Yes() : No();
  }

  return 0;
}
